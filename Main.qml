import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts

import "./Interface"

Window {
    width: 640
    height: 480
    minimumWidth: 640
    minimumHeight: 480
    visible: true
    visibility: "Maximized"
    title: qsTr("BaplieVw")

    // Menu Bar
    HeaderMenuBar {
        id: headerMenuBar
        width: parent.width
        z: 1
    }

    // Project Area Text Status
    TextAreaProjectDescription {
        id: textAreaProjectDescription
        z: 1
        anchors.top: headerMenuBar.bottom
        anchors.topMargin: 6
        anchors.left: headerMenuBar.left
        anchors.leftMargin: 6
        height: 90
        width: parent.width / 1.3
    }

    TextAreaRawBaplie {
        id: textAreaRawBaplie
        z: 1
        anchors.top: headerMenuBar.bottom
        anchors.topMargin: 6
        anchors.left: textAreaProjectDescription.right
        anchors.leftMargin: 6
        width: parent.width / 5
        height: textAreaProjectDescription.height
                + tableContentSummary.height // textAreaProjectDescription.height + tableContentSummary.height
    }

    // Table Summary
    TableContentSummary {
        id: tableContentSummary
        anchors.top: textAreaProjectDescription.bottom
        anchors.topMargin: 6
        anchors.left: headerMenuBar.left
        anchors.leftMargin: 6
        width: parent.width / 1.3
        height: parent.height / 6
    }

    // Main Table for BAPLIE content
    TableContentBaplie {
        id: tableContentBaplie
        anchors.top: tableContentSummary.bottom
        anchors.topMargin: 6
        anchors.left: headerMenuBar.left
        anchors.leftMargin: 6
        width: parent.width - 12
        height: parent.height / 1.6
    }

    // Background Color
    Rectangle {
        id: rectBg
        z: -1
        width: parent.width
        height: parent.height
        color: "#e2e8f0"
    }

    // Status Bar (Footer)
    FooterStatusBar {
        id: footerStatusBar
        z: 1
        width: parent.width
        height: 24
        color: "#cbd5e1"
        anchors.bottom: parent.bottom
    }
}
