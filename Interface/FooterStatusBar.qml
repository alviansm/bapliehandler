import QtQuick
import QtQuick.Controls

Rectangle {
    ProgressBar {
        id: globalLoadingBar
        z: 2
        width: 72
        height: 16
        value: handleBaplie.loadingStatus
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: 9
    }

    Text {
        id: labelProjectName
        text: "Shipping Project:"
        font.pointSize: 9
        color: "#000"
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: globalLoadingBar.right
        anchors.leftMargin: 9
    }

    Text {
        id: valueProjectName
        text: "-"
        font.pointSize: 9
        color: "#000"
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: labelProjectName.right
        anchors.leftMargin: 6
    }

    Text {
        id: labelRecords
        text: "Records:"
        font.pointSize: 9
        color: "#000"
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: valueProjectName.right
        anchors.leftMargin: 6
    }

    Text {
        id: valueRecords
        text: "-"
        font.pointSize: 9
        color: "#000"
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: labelRecords.right
        anchors.leftMargin: 6
    }

    Text {
        id: labelWeight
        text: "Weight:"
        font.pointSize: 9
        color: "#000"
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: valueRecords.right
        anchors.leftMargin: 6
    }

    Text {
        id: valueWeight
        text: "-"
        font.pointSize: 9
        color: "#000"
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: labelWeight.right
        anchors.leftMargin: 6
    }

    Text {
        id: labelTeus
        text: "TEUs:"
        font.pointSize: 9
        color: "#000"
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: valueWeight.right
        anchors.leftMargin: 6
    }

    Text {
        id: valueTeus
        text: "-"
        font.pointSize: 9
        color: "#000"
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: labelTeus.right
        anchors.leftMargin: 6
    }

    Text {
        id: labelProjectPath
        text: "Path:"
        font.pointSize: 9
        color: "#000"
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: valueProjectPath.left
        anchors.leftMargin: 6
    }

    Text {
        id: valueProjectPath
        text: handleBaplie.baplieURI
        font.pointSize: 9
        color: "#000"
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: labelPorts.left
        anchors.rightMargin: 6
        anchors.leftMargin: 6
    }

    Text {
        id: labelPorts
        text: "Ports:"
        font.pointSize: 9
        color: "#000"
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: valuePorts.left
        anchors.leftMargin: 6
    }

    Text {
        id: valuePorts
        text: "-"
        font.pointSize: 9
        color: "#000"
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right
        anchors.rightMargin: 6
        anchors.leftMargin: 6
    }
}
