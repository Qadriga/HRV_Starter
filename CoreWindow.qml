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

        RowLayout {
        }
        Rectangle {
            width: parent.width
            height: parent.height * 0.4
            border.width: 2
            border.color: "darkgreen"
            ListView {
                id: lv_sendqueue
                anchors.fill: parent
                anchors.margins: 5
                cacheBuffer: 50
                header: Rectangle {
                    width: parent.width
                    RowLayout {
                        width: parent.width
                        Text {
                            width: parent * 0.1
                            text: qsTr("Index")
                        }
                        Text {
                            width: parent * 0.1
                            text: qsTr("Abteilung")
                        }
                        Text {
                            width: parent * 0.1
                            text: qsTr("RennNummer")
                        }
                        Text {
                            text: qsTr("Bahnen")
                        }
                    }
                }

                model: ct_racelist.list
                delegate: //RaceDelegate{ }
                          Rectangle {
                    anchors.left: parent.left
                    anchors.right: parent.right
                    border.width: 1
                    border.color: "lightsteelblue"
                    RowLayout {

                        anchors.fill: parent
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
                                TextField {
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
                }
                spacing: 30
                onCountChanged: {
                    console.log(count)
                }
            }
        }
        RowLayout {
            width: parent.width
            layoutDirection: Qt.RightToLeft
            Rectangle {
                id: rc_sendtext
                implicitWidth: 100
                width: tv_sendtext.width
                height: 20
                Text {

                    id: tv_sendtext
                }
                onColorChanged: {
                    if (color !== "yellow" || color !== "transparent") {
                        timer_reset.start()
                        console.log("Timer Start")
                    }
                }
            }
            Timer {
                id: timer_reset
                repeat: false
                interval: 5000
                onTriggered: {

                    tv_sendtext.text = ""
                    rc_sendtext.color = "transparent"
                }
            }

            Button {
                id: btn_send

                text: qsTr("Send")
                onClicked: {
                    rc_sendtext.color = "yellow"
                    tv_sendtext.text = "Sending"
                    if (ct_racelist.sendToDevice()) {
                        console.log("Sended")
                        rc_sendtext.color = "green"
                        tv_sendtext.text = "Gesendet"
                    } else {
                        console.log("FAILED")
                        tv_sendtext.text = "Fehlgeschlagen"
                        rc_sendtext.color = "red"
                    }
                }
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
