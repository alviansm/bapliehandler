import QtQuick
import QtQuick.Controls
import QtQuick.Dialogs

import "../Interface"

MenuBar {
    id: menuBarRoot

    FileDialogOpenBaplie {
        id: fileDialogBaplie
    }

    Menu {
        title: qsTr("&File")
        leftPadding: 32
        Action {
            text: qsTr("&New...")
        }
        Action {
            text: qsTr("&Open BAPLIE...")
            shortcut: "O"
            onTriggered: {
                fileDialogBaplie.open()
            }
        }
        Action {
            text: qsTr("&Close Project...")
        }
        Action {
            text: qsTr("&Save")
        }
        Action {
            text: qsTr("Save &As...")
        }
        MenuSeparator {}
        Action {
            text: qsTr("E&xport...")
        }
        Action {
            text: qsTr("E&xport as SQL...")
        }
        MenuSeparator {}
        Action {
            text: qsTr("&Preferences...")
        }
        MenuSeparator {}
        Action {
            text: qsTr("&Quit")
            onTriggered: Qt.quit()
        }
    }
    Menu {
        title: qsTr("&Edit")
        leftPadding: 32
        Action {
            text: qsTr("View &Raw Baplie")
        }
        MenuSeparator {}
        Action {
            text: qsTr("Cu&t")
        }
        Action {
            text: qsTr("&Copy")
        }
        Action {
            text: qsTr("&Paste")
        }
    }
    Menu {
        title: qsTr("&Report")
        leftPadding: 32
        Action {
            text: qsTr("Document Level")
        }
        Action {
            text: qsTr("Container &List")
        }
    }

    Menu {
        title: qsTr("&Window")
        leftPadding: 32
        Action {
            text: qsTr("Mi&nimize")
        }
        Action {
            text: qsTr("Ma&ximize")
        }
        Action {
            text: qsTr("&Full Screen")
        }
    }
    Menu {
        title: qsTr("&Help")
        leftPadding: 32
        Action {
            text: qsTr("&Manual")
        }
        Action {
            text: qsTr("&About")
        }
    }
}
