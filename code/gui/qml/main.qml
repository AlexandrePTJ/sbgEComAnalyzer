// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: 2025 SBG Systems and Contributors

import QtQuick
import QtQuick.Controls
import QtPositioning
import QtLocation

ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: qsTr("GeoJSON Viewer: ") + view.map.center

    MapView {
        id: view
        anchors.fill: parent
        map.plugin: Plugin { name: "osm" }
        map.zoomLevel: 12
        map.center: QtPositioning.coordinate(48.9103652, 2.1673702)
    }
}
