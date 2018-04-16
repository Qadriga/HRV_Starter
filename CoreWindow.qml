import QtQuick 2.9
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3

import de.hrv.types 1.0

Item {
    anchors.fill: parent
    function setFilepath(filepath) {
        ct_racelist.createListFromFile(filepath)
    }

    ColumnLayout {
        anchors.fill: parent
        spacing: 2
        ListView {
            id: lv_sendqueue
            width: parent.width
            height: parent.height * 0.3
            anchors.margins: 5
            model: ct_racelist.list

            Layout.alignment: Qt.AlignHCenter

            Layout.preferredWidth: parent.width * 0.9

            delegate: //RaceDelegate{ }
                      RowLayout {

                //width: parent.width
                TextField {
                    width: parent * 0.1
                    text: modelData.index
                }
                TextField {
                    width: parent * 0.1
                    text: modelData.abteilung
                }
                TextField {
                    text: modelData.rennNumber
                }
                Repeater {
                    model: modelData.lanes
                    delegate: Row {
                        TextField{
                            width: 20
                            text: modelData.lane_Lable
                        }

                        TextField {
                            width: 20
                            text: modelData.time_delay
                        }

                    }
                    onItemAdded: {

                    }
                }

            }
            spacing: 1
        }
        Button {
            id: btn_send
            Layout.alignment: Qt.AlignRight
            text: qsTr("Send")
            onClicked: {
                console.log(test.url)
                console.log(ct_racelist.rowCount())
            }
        }
    }
    RaceList {
        id: ct_racelist
    }

    ListModel {
        id: lm_send
    }
    ListModel {
        id: lm_finshed
    }

    /*Component {

        id: delgateItem

        Row {
            property int listIndex: 0

            TextField {
                width: parent * 0.1
                text: model.modelData.index
            }
            TextField {
                width: parent * 0.1
                text: model.modelData.abteilung
            }
            TextField {
                text: model.modelData.rennNumber
            }

        }
        Loader {
            id: subItemLoader
            property variant subItemModel: lanes
        }
    }
    Component{
        id: subItemDelegate
        Row{
            property alias model: subItemRepeater.model
            Repeater{
                id: subItemRepeater
                delegate: Row{
                    Text{
                        text: lane_Lable
                    }
                }
            }
        }
    }*/
}
