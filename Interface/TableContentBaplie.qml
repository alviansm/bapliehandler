import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import TableBaplieContent 0.1

ColumnLayout {
    spacing: 0.4
    layoutDirection: Qt.LeftToRight

    TableView {
        anchors.fill: parent
        columnSpacing: 1
        rowSpacing: 1
        clip: true

        model: TableBaplieContent {}

        delegate: Rectangle {
            implicitWidth: (parent.parent.width - 32) / 15
            implicitHeight: 20
            color: (heading == true) ? "#f3f4f6" : "#ffffff"
            clip: true
            Text {
                text: tabledata
                font.pointSize: 9
                anchors.centerIn: parent
                font.bold: (heading == true) ? true : false
            }

            TableView.editDelegate: TextField {
                anchors.fill: parent
                text: tabledata
                horizontalAlignment: TextInput.AlignHCenter
                verticalAlignment: TextInput.AlignVCenter
                Component.onCompleted: selectAll()

                TableView.onCommit: {
                    display = text
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
}
