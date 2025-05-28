project(sbgEComAnalyzerTests)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE
        src/data/sessionInfoTests.cpp
        src/ecom/fileParserTests.cpp
        src/ecom/libraryInfoTests.cpp
)

target_compile_definitions(${PROJECT_NAME} PRIVATE SBG_TEST_DATA_DIR="${CMAKE_SOURCE_DIR}/data")

target_link_libraries(${PROJECT_NAME} PRIVATE sbgEComAnalyzerCore Catch2::Catch2WithMain)

list(APPEND CMAKE_MODULE_PATH ${Catch2_SOURCE_DIR}/extras)
include(Catch)
catch_discover_tests(${PROJECT_NAME})