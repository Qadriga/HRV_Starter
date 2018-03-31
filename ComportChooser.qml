import QtQuick 2.3
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.3
Dialog{
    id: dialog
    height: 400
    width: 400
    title: qsTr("Choose USB Port")
    contentItem: ColumnLayout{
        ComboBox {

        }
        Button{
            id: btn_select
            text: "Select"
            onClicked: {
                dialog.close();

            }

        }
    }
    Component.onCompleted: {
        btn_select.clicked.connect(accepted);
    }

}
