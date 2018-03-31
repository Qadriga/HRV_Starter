import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.2



ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    menuBar: MenuBar{
        Menu{
            title: qsTr("File")
            Action{
                text: qsTr("Select COM Port")
                onTriggered: {
                    portsel.open();
                }

            }
            Action{
                text: qsTr("Load")
                onTriggered: {
                    filechooser.open()
                }

            }
            MenuSeparator{

            }
            Action{
                text: qsTr("Quit")
                onTriggered: {
                    Qt.quit();// Close Application
                }
            }
        }
    }
    CoreWindow{
        id: win_core
    }

    FileDialog{
        id: filechooser
        title: qsTr("Choose File")
        selectExisting: true
        selectMultiple: false
        nameFilters: ["CVS files (*.cvs)","All files (*)"]
        folder: shortcuts.home
        onAccepted: {
            if(fileUrl === null){
                win_core.setFilepath(filechooser.fileUrls[0]);
            }
            else{
                win_core.setFilepath(filechooser.fileUrl);
            }


        }

    }

    ComportChooser{
        id: portsel
        onAccepted: {
            console.log("Hello");
        }
    }




}
