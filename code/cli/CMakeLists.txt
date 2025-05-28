project(sbgEComAnalyzerCli)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
        PRIVATE src/main.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE sbgEComAnalyzerCore CLI11::CLI11 fmt::fmt spdlog::spdlog sbgECom)
