project(sbgEComAnalyzerCore)

add_library(${PROJECT_NAME} STATIC)
set_property(TARGET ${PROJECT_NAME} PROPERTY POSITION_INDEPENDENT_CODE ON)

target_sources(${PROJECT_NAME} PRIVATE
        src/data/sessionInfo.cpp
        src/data/sessionInfo.h
        src/ecom/fileParser.cpp
        src/ecom/fileParser.h
        src/ecom/fileParser_p.h
        src/ecom/libraryInfo.cpp
        src/ecom/libraryInfo.h
)

target_include_directories(${PROJECT_NAME}
        PUBLIC ${CMAKE_CURRENT_LIST_DIR}/src)

target_link_libraries(${PROJECT_NAME}
        PRIVATE nlohmann_json::nlohmann_json fmt::fmt sbgECom
)
