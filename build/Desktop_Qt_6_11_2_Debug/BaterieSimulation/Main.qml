import QtQuick
import QtCore
import QtQuick.Layouts
import QtQuick.Controls.Universal
import QtQuick.Dialogs
import QtGraphs

import BaterieSimulation

ApplicationWindow {
    id: window
    width: 1280
    height: 960
    visible: true
    title: qsTr("Baterie Simulation")

    GridLayout {
        id: mainLayout
        anchors.fill: parent

        rows: 2
        columns: 2

        ListView {
            id: filesListView

            Layout.fillHeight: true
            Layout.minimumWidth: 200

            model: Data.files

            contentWidth: 300
            flickableDirection: Flickable.HorizontalFlick

            delegate: Text {
                required property string modelData
                text: modelData
            }

            footerPositioning: ListView.OverlayFooter
            footer: ColumnLayout {
                anchors.left: parent.left
                width: 200
                Button {
                    id: loadDefaultData
                    text: "FSV Daten laden"

                    Layout.alignment: Layout.Center

                    onClicked: {
                        Data.loadFSVData()
                    }
                }

                Button {
                    id: selectFileButton
                    text: "Datei auswählen"

                    Layout.alignment: Layout.Center

                    onClicked: {
                        Data.selectFile()
                    }
                }
            }
        }

        BasicGraph {
            id: basicGraph
            Layout.fillHeight: true
            Layout.fillWidth: true

            Layout.minimumHeight: 100
        }

        ColumnLayout {
            id: batteryLayout

            Layout.alignment: Layout.Center

            Label {
                text: "Batterie"

                Layout.alignment: Layout.Center
            }

            RowLayout {
                Layout.alignment: Layout.Center
                SpinBox {
                    id: batterySizeSpinBox
                    value: 8
                }

                Label {
                    text: "kWh"
                }
            }

            Button {
                text: "Berechnen"
                Layout.alignment: Layout.Center

                onClicked: {
                    Data.calculate(batterySizeSpinBox.value * 1000)
                    savingsLabel.text = Math.round(Data.savings / 1000) + " kWh durch " + Data.batterySize / 1000 + " kWh Akku gespart";
                    moneyLabel.text = Math.round(Data.savings / 1000 * ctSpinBox.value / 100) + "€ gespart"
                }
            }

            Label {
                id: savingsLabel

                wrapMode: Text.Wrap
                Layout.alignment: Layout.Center
                Layout.maximumWidth: 150
            }

            RowLayout {
                Layout.alignment: Layout.Center
                SpinBox {
                    id: ctSpinBox
                    value: 28
                }

                Label {
                    text: "ct/kWh"
                }
            }

            Label {
                id: moneyLabel
                Layout.alignment: Layout.Center
                Layout.maximumWidth: 150
            }
        }

        SimulatedBatteryGraph {
            id: simulatedBatteryGraph

            Layout.fillHeight: true
            Layout.fillWidth: true
        }
    }
}


