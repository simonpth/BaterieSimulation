cmake_minimum_required(VERSION 3.16)

project(BaterieSimulation VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick Graphs Widgets)

qt_standard_project_setup(REQUIRES 6.10)

# Content of downloaded design from Figma to Qt or similar
if (EXISTS "${CMAKE_CURRENT_LIST_DIR}/importedcontent/CMakeLists.txt")
    add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/importedcontent)
endif()

qt_add_executable(appBaterieSimulation
    main.cpp
)

file(GLOB CSV_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/CSV/*.csv")

foreach(csv_file ${CSV_FILES})
    get_filename_component(csv_name ${csv_file} NAME)
    set_source_files_properties(${csv_file} PROPERTIES
        QT_RESOURCE_ALIAS "CSV/${csv_name}"
    )
endforeach()


qt_add_qml_module(appBaterieSimulation
    URI BaterieSimulation
    QML_FILES
        Main.qml
    SOURCES
        data.h data.cpp

    RESOURCES
        ${CSV_FILES}
        QML_FILES BasicGraph.qml
        QML_FILES SimulatedBatteryGraph.qml
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appBaterieSimulation PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appBaterieSimulation
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appBaterieSimulation
    PRIVATE Qt6::Quick Qt6::Graphs Qt6::Widgets
)

install(TARGETS appBaterieSimulation
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
