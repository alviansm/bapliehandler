cmake_minimum_required(VERSION 3.16)

project(BaplieVw VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(app_icon_resource_windows "${CMAKE_CURRENT_SOURCE_DIR}/baplievw.rc")

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

qt_add_executable(appBaplieVw
    main.cpp
    ${app_icon_resource_windows}
)

qt_add_qml_module(appBaplieVw
    URI BaplieVw
    VERSION 1.0
    QML_FILES Main.qml
    SOURCES ApplicationWindow.h ApplicationWindow.cpp
    RESOURCES
    RESOURCES
    RESOURCES
    RESOURCES BaplieVwQRC.qrc
    RESOURCES
    QML_FILES Interface/FooterStatusBar.qml Interface/HeaderMenuBar.qml
QML_FILES Interface/TextAreaProjectDescription.qml
QML_FILES Interface/TableContentSummary.qml
SOURCES TableModelSummary.h TableModelSummary.cpp
QML_FILES Interface/FileDialogOpenBaplie.qml
SOURCES TableBaplieContent.h TableBaplieContent.cpp
QML_FILES Interface/TableContentBaplie.qml
SOURCES HandleBaplie.h HandleBaplie.cpp
QML_FILES Interface/TextAreaRawBaplie.qml
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appBaplieVw PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appBaplieVw
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appBaplieVw
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appBaplieVw
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
