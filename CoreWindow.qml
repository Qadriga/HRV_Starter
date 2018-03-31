import QtQuick 2.9
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3

import de.hrv.types 1.0
Item {
    anchors.fill: parent
    function setFilepath(filepath){
        ct_racelist.createListFromFile(filepath);
    }

    ColumnLayout{
        anchors.fill: parent
        spacing: 2
        Rectangle{
            Layout.alignment: Qt.AlignCenter
            Layout.fillWidth: true
            Layout.minimumHeight: 20
            border.color: "navy"
            border.width: 1
            ListView{
                id: lv_sendqueue
                anchors.margins: 5
                model: lm_send
                //delegate: renndelegate

            }
        }
        Rennen{
            id: test
        }

        Button{
            id: btn_send
            Layout.alignment: Qt.AlignRight
            onClicked: {
                console.log(test.url)
                console.log(ct_racelist.rowCount())
            }
        }
        Rectangle{
            Layout.alignment: Qt.AlignCenter
            Layout.fillWidth: true
            Layout.minimumHeight: 20
            border.color: "navy"
            border.width: 1
            TableView{
                anchors.margins: 5
                id: lv_donequeue
                model: lm_finshed
                //delegate: renndelegate

            }
        }
    }
    RaceList{
        id: ct_racelist
        onRowsInserted: {
            console.log("PARTY")
        }
    }

    ListModel{
        id:lm_send


    }
    ListModel{
        id: lm_finshed

    }


}
