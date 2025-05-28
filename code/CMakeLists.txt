add_subdirectory(core)
add_subdirectory(cli)

if (BUILD_TESTING)
    add_subdirectory(tests)
endif ()

if (BUILD_GUI)
    add_subdirectory(gui)
endif ()
