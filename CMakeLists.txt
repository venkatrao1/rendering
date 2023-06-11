cmake_minimum_required(VERSION 3.26)

project(Project)

add_executable(app src/main.cpp)

set(SFML_STATIC_LIBRARIES true)

set(SFML_DIR "${CMAKE_SOURCE_DIR}/ext/SFML-2.5.1/lib/cmake/SFML")
message("${SFML_DIR}")
find_package(SFML COMPONENTS window graphics system)


target_include_directories(app PRIVATE "${CMAKE_SOURCE_DIR}/ext/SFML-2.5.1/include")
target_compile_features(app PUBLIC cxx_std_17)
target_compile_definitions(app PRIVATE SFML_STATIC)
target_link_libraries(app PRIVATE sfml-graphics)