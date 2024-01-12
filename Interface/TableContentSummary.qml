import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import QtQuick.Dialogs
import TableModelSummary 0.1

ColumnLayout {
    spacing: 0.4
    layoutDirection: Qt.LeftToRight

    TableView {
        anchors.fill: parent
        columnSpacing: 1
        rowSpacing: 1
        clip: true

        model: TableModelSummary {}

        delegate: Rectangle {
            required property bool editing

            id: rectangleDelegateCell
            implicitWidth: 75
            implicitHeight: 20
            color: (heading == true) ? "#f3f4f6" : "#ffffff"
            Text {
                id: textField
                text: tabledata
                font.pointSize: 9
                anchors.centerIn: parent
                font.bold: (heading == true) ? true : false
                visible: !editing
            }

            TableView.editDelegate: TextField {
                x: textField.x
                y: textField.y
                width: textField.width
                height: textField.height
                text: tabledata
                TableView.onCommit: {
                    let index = TableView.view.index(column, row)
                    TableView.view.model.setData(index, text, Qt.DisplayRole)
                    if (row == 0) {
                        messageDialogInfoEdit.open()
                    } else {
                        console.log("Success changing column ", row,
                                    " row ", column)
                    }
                }
            }
        }

        ScrollBar.vertical: ScrollBar {
            id: tableVerticalBar
            policy: ScrollBar.AlwaysOn
        }

        ScrollBar.horizontal: ScrollBar {
            id: tableHorizontalBar
            policy: ScrollBar.AlwaysOn
        }
    }

    MessageDialog {
        id: messageDialogInfoEdit
        buttons: MessageDialog.Ok
        text: "Can't change headers."
    }
}
