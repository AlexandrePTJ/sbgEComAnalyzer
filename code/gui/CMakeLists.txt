project(sbgEComAnalyzerGui)

find_package(Qt6 COMPONENTS Quick Positioning Location)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE
        src/main.cpp
)

qt_add_qml_module(${PROJECT_NAME}
        URI sbg
        QML_FILES "qml/main.qml"
)

target_compile_definitions(${PROJECT_NAME} PRIVATE $<$<CONFIG:Debug>:QT_QML_DEBUG>)

target_link_libraries(${PROJECT_NAME} PUBLIC
        Qt::Location
        Qt::Positioning
        Qt::Quick)
