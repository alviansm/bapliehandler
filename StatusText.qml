import QtQuick

Text {
    id: labelProjectName
    property alias text: "Shipping Project:"
    font.pointSize: 9
    color: "#000"
    anchors.verticalCenter: parent.verticalCenter
    anchors.left: globalLoadingBar.right
    anchors.leftMargin: 9
}
