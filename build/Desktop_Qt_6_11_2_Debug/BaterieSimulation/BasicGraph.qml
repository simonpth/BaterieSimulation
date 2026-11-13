import QtQuick
import QtCore
import QtQuick.Layouts
import QtQuick.Controls
import QtQuick.Dialogs
import QtGraphs

import BaterieSimulation

Item {
    id: root

    Button {
        text: "Neu zentrieren"

        anchors.topMargin: 24
        anchors.rightMargin: 4
        anchors.right: parent.right
        anchors.top: parent.top

        z: 5

        onClicked: {
            axisX.zoom = 1
            axisX.pan = 0
            axisY.zoom = 1
            axisY.pan = 0
        }
    }

    ColumnLayout {
        anchors.topMargin: 24
        anchors.leftMargin: 92
        anchors.top: parent.top
        anchors.left: parent.left
        z: 5
        Text {
            text: "Einspeisung in W"
            color: "green"
        }

        Text {
            text: "Netzbezug in W"
            color: "red"
        }
    }

    MouseArea {
        anchors.fill: parent
        acceptedButtons: Qt.RightButton
        cursorShape: pressed ? Qt.ClosedHandCursor : Qt.ArrowCursor

        property real lastX: 0
        property real lastY: 0

        onPressed: (mouse) => {
            lastX = mouse.x
            lastY = mouse.y
        }

        onPositionChanged: (mouse) => {
            if (pressed) {
                const dx = mouse.x - lastX
                const dy = mouse.y - lastY

                axisX.pan -= dx  * (axisX.visualMax - axisX.visualMin) / width
                axisY.pan += dy  * (axisY.visualMax - axisY.visualMin) / height

                lastX = mouse.x
                lastY = mouse.y
            }
        }
    }

    GraphsView {
        id: graph
        anchors.fill: parent

        panStyle: GraphsView.PanStyle.None
        zoomStyle: GraphsView.ZoomStyle.Center
        zoomAreaEnabled: true

        Layout.fillHeight: true
        Layout.fillWidth: true

        axisX: DateTimeAxis {
            id: axisX
            labelFormat: "dd.MM.yyyy HH:mm"
        }
        axisY: ValueAxis {
            id: axisY
            min: 0
            max: 5000

            onVisualMinChanged: if(visualMin < 0) pan -= visualMin
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
            einspeisungSeries.clear();

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

            axisX.pan = 0
            axisX.zoom = 1
            axisY.pan = 0
            axisY.zoom = 1
        }

        Component.onCompleted: refreshSeries()

        Connections {
            target: Data
            function onDatapointsChanged() {
                graph.refreshSeries();
            }
        }
    }
}