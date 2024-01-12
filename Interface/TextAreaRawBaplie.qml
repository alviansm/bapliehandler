import QtQuick
import QtQuick.Controls 2.15

ScrollView {
    height: parent.height

    Rectangle {
        anchors.fill: flickable
    }

    Flickable {
        id: flickable
        width: parent.width
        height: parent.height
        contentWidth: width
        contentHeight: textArea.implicitHeight

        TextArea {
            id: textArea
            readOnly: true
            width: parent.width
            text: handleBaplie.baplieContent // macro from /HandleBaplie.cpp
            wrapMode: Text.WordWrap
        }

        ScrollBar.vertical: ScrollBar {}
    }
}
