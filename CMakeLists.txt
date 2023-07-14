cmake_minimum_required(VERSION 3.8)

Project(Sound_Sheet)

include(FetchContent)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(SFML_VERSION "2.6.0")
set(FETCHCONTENT_QUIET FALSE)

FetchContent_Declare(
        sfml
        GIT_REPOSITORY "https://github.com/SFML/SFML.git"
        GIT_TAG        "${SFML_VERSION}"
        GIT_PROGRESS TRUE
)

FetchContent_GetProperties(sfml)
if(NOT sfml_POPULATED)
    FetchContent_Populate(sfml)
    add_subdirectory(${sfml_SOURCE_DIR} ${sfml_BINARY_DIR})
endif()

find_package(SFML ${SFML_VERSION} COMPONENTS system window graphics audio)

include_directories(src)

add_executable(${PROJECT_NAME}
    main.cpp
    src/metronome.cpp
    )

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system sfml-audio)




