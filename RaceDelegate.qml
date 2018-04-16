import QtQuick 2.0
import QtQuick.Controls 1.4

Item {
    Component {

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
    }
}
