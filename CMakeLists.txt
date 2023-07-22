cmake_minimum_required(VERSION 3.26) # the one I have installed

project(Project)

# find SFML
set(SFML_DIR "${CMAKE_SOURCE_DIR}/ext/SFML-2.5.1/lib/cmake/SFML")
set(SFML_STATIC_LIBRARIES true)
find_package(SFML COMPONENTS window graphics system audio network)

# TODO: multiple target support probably will not be good here, when to use add vs target?

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(.) # for headers and ipp
link_libraries( # Link all SFML libraries, because SFML isn't very big anyway
	sfml-graphics
	sfml-window
	sfml-audio
	sfml-network
	sfml-system
)

# compiler flags
if(MSVC)
	# TODO: more compiler flags, debug vs release builds?
	add_compile_options(/W4 /WX) # warning level 4, treat warnings as errors
	if(CMAKE_BUILD_TYPE STREQUAL "Release")
		add_compile_options(/fp:fast /GL /Gr) # unsafe but faster hopefully
	endif()
else()
	message("No compiler flags set, I only have compiled on MSVC!")
endif()

# for IntelliSense to use
set(CMAKE_EXPORT_COMPILE_COMMANDS true)

# add executables
add_executable(app)
target_compile_features(app PUBLIC cxx_std_20)

add_subdirectory(src)