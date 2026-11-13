import QtQuick
import QtCore
import QtQuick.Layouts
import QtQuick.Controls
import QtQuick.Dialogs
import QtGraphs

import BaterieSimulation

ApplicationWindow {
    id: window
    width: 1280
    height: 960
    visible: true
    title: qsTr("Baterie Simulation")


    RowLayout {
        anchors.fill: parent

        ColumnLayout {

            ListView {
                id: filesListView

                Layout.fillHeight: true

                model: Data.files

                delegate: Text {
                    required property url modelData
                    text: modelData.toString()
                }
            }

            Button {
                id: selectFileButton
                text: "Dateien auswählen"

                onClicked: fileDialog.open()

                FileDialog {
                    id: fileDialog

                    fileMode: FileDialog.OpenFiles
                    options: FileDialog.ReadOnly
                    currentFolder: StandardPaths.standardLocations(StandardPaths.DocumentsLocation)[0]

                    nameFilters: ["CSV Dateien (*.csv)"]

                    onAccepted: {
                        Data.readFiles(selectedFiles)
                        console.log(selectedFiles)
                    }
                }
            }
        }

        GraphsView {
            id: graph

            Layout.fillHeight: true
            Layout.fillWidth: true

            axisX: DateTimeAxis {
                id: axisX
                labelFormat: "dd.MM HH:mm"
            }
            axisY: ValueAxis {
                id: axisY
                min: 0
                max: 5000
            }

            LineSeries {
                id: netzbezugSeries
                axisX: axisX
                axisY: axisY

                color: "red"
            }

            LineSeries {
                id: einspeisungSeries
                axisX: axisX
                axisY: axisY

                color: "green"
            }


            function refreshSeries() {
                netzbezugSeries.clear();

                const points = Data.datapoints;
                for (let i = 0; i < points.length; i++) {
                    const netzbezug = points[i].netzbezug
                    const einspeisung = points[i].einspeisung
                    netzbezugSeries.append(points[i].dateTime, netzbezug);
                    einspeisungSeries.append(points[i].dateTime, einspeisung);

                    axisY.max = Math.max(netzbezug + 100, einspeisung + 100, axisY.max)
                }

                if (points.length > 0) {
                    axisX.min = points[0].dateTime;
                    axisX.max = points[points.length - 1].dateTime;
                }
            }

            Component.onCompleted: refreshSeries()

            Connections {
                target: Data
                function onDatapointsChanged() {
                    graph.refreshSeries();
                }
            }

            MouseArea {
                anchors.fill: parent
                property real lastX: 0
                onPressed: (mouse) => lastX = mouse.x
                onPositionChanged: (mouse) => {
                    const dx = mouse.x - lastX;
                    const minMs = axisX.min.getTime();
                    const maxMs = axisX.max.getTime();
                    const range = maxMs - minMs;
                    const shift = -dx / width * range;
                    axisX.min = new Date(minMs + shift);
                    axisX.max = new Date(maxMs + shift);
                    lastX = mouse.x;
                }
                onWheel: (wheel) => {
                    const zoomFactor = wheel.angleDelta.y > 0 ? 0.9 : 1.1;
                    const minMs = axisX.min.getTime();
                    const maxMs = axisX.max.getTime();
                    const center = minMs + (maxMs - minMs) / 2;
                    const range = (maxMs - minMs) * zoomFactor / 2;
                    axisX.min = new Date(center - range);
                    axisX.max = new Date(center + range);
                }
            }
        }
    }
}


