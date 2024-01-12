import QtQuick
import QtQuick.Dialogs
import QtCore

FileDialog {
    id: fileDialogBaplie
    title: "Please choose a BAPLIE file (.EDI)"
    nameFilters: ["BAPLIE files (*.EDI)"]
    visible: false
    onAccepted: {
        handleBaplie.baplieURI = selectedFile
        handleBaplie.readBaplie(handleBaplie.baplieURI)
        handleBaplie.loadingStatus = 1.00
    }
}
