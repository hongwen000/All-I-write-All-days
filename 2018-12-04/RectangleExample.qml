import QtQuick 2.11
Rectangle {
    id: root
    width: 120; height: 240
    color: "#4A4A4A"
    Image {
        id: triangle
        x: (parent.width - width) / 2; y:40
        source: '1.png'
    }
    Text {
        y: triangle.y + triangle.height + 20
        width: root.width
        color: 'white'
        horizontalAlignment: Text.AlignHCenter
        text: 'Triangle'
    }
}
