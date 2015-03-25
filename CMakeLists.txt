cmake_minimum_required(VERSION 2.8)
project(genesis C CXX)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

set(LIBGENESIS_VERSION_MAJOR 0)
set(LIBGENESIS_VERSION_MINOR 0)
set(LIBGENESIS_VERSION_PATCH 0)
set(LIBGENESIS_VERSION "${LIBGENESIS_VERSION_MAJOR}.${LIBGENESIS_VERSION_MINOR}.${LIBGENESIS_VERSION_PATCH}")
message("Configuring genesis version ${LIBGENESIS_VERSION}")

set(LIBGENESIS_SOURCES
    "${CMAKE_SOURCE_DIR}/src/genesis.cpp"
    "${CMAKE_SOURCE_DIR}/src/error.cpp"
    "${CMAKE_SOURCE_DIR}/src/channel_layout.cpp"
    "${CMAKE_SOURCE_DIR}/src/audio_hardware.cpp"
    "${CMAKE_SOURCE_DIR}/src/audio_file.cpp"
    "${CMAKE_SOURCE_DIR}/src/util.cpp"
    "${CMAKE_SOURCE_DIR}/src/sample_format.cpp"
    "${CMAKE_SOURCE_DIR}/src/byte_buffer.cpp"
    "${CMAKE_SOURCE_DIR}/src/midi_hardware.cpp"
    )
set(CONFIGURE_OUT_FILE "${CMAKE_BINARY_DIR}/config.h")
set(LIBGENESIS_HEADERS
    "${CMAKE_SOURCE_DIR}/src/genesis.h"
    "${CMAKE_SOURCE_DIR}/src/channel_layout.h"
    "${CMAKE_SOURCE_DIR}/src/sample_format.h"
    "${CMAKE_SOURCE_DIR}/src/error.h"
    ${CONFIGURE_OUT_FILE}
    )

set(GENESIS_SOURCES
    "${CMAKE_SOURCE_DIR}/src/main.cpp"
    "${CMAKE_SOURCE_DIR}/src/util.cpp"
    "${CMAKE_SOURCE_DIR}/src/byte_buffer.cpp"
    "${CMAKE_SOURCE_DIR}/src/os.cpp"
    "${CMAKE_SOURCE_DIR}/src/path.cpp"
    "${CMAKE_SOURCE_DIR}/src/string.cpp"
    "${CMAKE_SOURCE_DIR}/src/shader_program.cpp"
    "${CMAKE_SOURCE_DIR}/src/gui.cpp"
    "${CMAKE_SOURCE_DIR}/src/label.cpp"
    "${CMAKE_SOURCE_DIR}/src/debug.cpp"
    "${CMAKE_SOURCE_DIR}/src/text_widget.cpp"
    "${CMAKE_SOURCE_DIR}/src/font_size.cpp"
    "${CMAKE_SOURCE_DIR}/src/find_file_widget.cpp"
    "${CMAKE_SOURCE_DIR}/src/resource_bundle.cpp"
    "${CMAKE_SOURCE_DIR}/src/png_image.cpp"
    "${CMAKE_SOURCE_DIR}/src/spritesheet.cpp"
    "${CMAKE_SOURCE_DIR}/src/genesis_editor.cpp"
    "${CMAKE_SOURCE_DIR}/src/audio_edit_widget.cpp"
    "${CMAKE_SOURCE_DIR}/src/texture.cpp"
    "${CMAKE_SOURCE_DIR}/src/shader_program_manager.cpp"
    "${CMAKE_SOURCE_DIR}/src/alpha_texture.cpp"
    "${CMAKE_SOURCE_DIR}/src/static_geometry.cpp"
    "${CMAKE_SOURCE_DIR}/src/vertex_array.cpp"
    "${CMAKE_SOURCE_DIR}/src/gui_window.cpp"
    "${CMAKE_SOURCE_DIR}/src/select_widget.cpp"
    )

set(UNICODE_HPP "${CMAKE_BINARY_DIR}/unicode.hpp")
set(GENESIS_HEADERS
    ${UNICODE_HPP}
    )

set(GENERATE_UNICODE_DATA_SOURCES
    "${CMAKE_SOURCE_DIR}/src/generate_unicode_data.cpp"
    "${CMAKE_SOURCE_DIR}/src/util.cpp"
    "${CMAKE_SOURCE_DIR}/src/byte_buffer.cpp"
    )

set(TEST_SOURCES
    "${CMAKE_SOURCE_DIR}/src/test.cpp"
    "${CMAKE_SOURCE_DIR}/src/util.cpp"
    "${CMAKE_SOURCE_DIR}/src/byte_buffer.cpp"
    "${CMAKE_SOURCE_DIR}/src/string.cpp"
    )
set(TEST_HEADERS ${GENESIS_HEADERS})

find_package(Threads)
if(Threads_FOUND)
    set(STATUS_THREADS "OK")
else(Threads_FOUND)
    set(STATUS_THREADS "not found")
endif(Threads_FOUND)


find_package(LibAV)
if(AVCODEC_FOUND)
    set(STATUS_LIBAVCODEC "OK")
else()
    set(STATUS_LIBAVCODEC "not found")
endif()
if(AVFORMAT_FOUND)
    set(STATUS_LIBAVFORMAT "OK")
else()
    set(STATUS_LIBAVFORMAT "not found")
endif()
if(AVUTIL_FOUND)
    set(STATUS_LIBAVUTIL "OK")
else()
    set(STATUS_LIBAVUTIL "not found")
endif()

find_package(FreeType)
if(FREETYPE_FOUND)
    set(STATUS_FREETYPE "OK")
else()
    set(STATUS_FREETYPE "not found")
endif()

find_package(PNG)
if(PNG_FOUND)
    set(STATUS_PNG "OK")
else()
    set(STATUS_PNG "not found")
endif()

find_package(rucksack)
if(RUCKSACK_FOUND)
    set(STATUS_RUCKSACK "OK")
else()
    set(STATUS_RUCKSACK "not found")
endif()

find_package(PulseAudio)
if(PULSEAUDIO_FOUND)
    set(STATUS_PULSEAUDIO "OK")
else()
    set(STATUS_PULSEAUDIO "not found")
endif()

find_package(GLFW)
if(GLFW_FOUND)
    set(STATUS_GLFW "OK")
else()
    set(STATUS_GLFW "not found")
endif()

find_package(epoxy)
if(EPOXY_FOUND)
    set(STATUS_EPOXY "OK")
else()
    set(STATUS_EPOXY "not found")
endif()

find_package(ALSA)
if(ALSA_FOUND)
    set(STATUS_ALSA "OK")
else()
    set(STATUS_ALSA "not found")
endif()

# GFTO, -lstdc++ !!
set(CMAKE_CXX_IMPLICIT_LINK_LIBRARIES "")
set(CMAKE_CXX_IMPLICIT_LINK_DIRECTORIES "")

set(LIB_CFLAGS "-std=c++11 -nodefaultlibs -fno-exceptions -fno-rtti -Werror -Wall -g -fdiagnostics-color=auto")
set(EXAMPLE_CFLAGS "-std=c99 -pedantic -Werror -Wall -g -fdiagnostics-color=auto")
set(EXAMPLE_INCLUDES "${CMAKE_SOURCE_DIR}/src")

configure_file (
    "${CMAKE_SOURCE_DIR}/src/config.h.in"
    ${CONFIGURE_OUT_FILE}
    )

add_library(libgenesis_shared SHARED ${LIBGENESIS_SOURCES} ${LIBGENESIS_HEADERS})
set_target_properties(libgenesis_shared PROPERTIES
    OUTPUT_NAME genesis
    SOVERSION ${LIBGENESIS_VERSION_MAJOR}
    VERSION ${LIBGENESIS_VERSION}
    COMPILE_FLAGS ${LIB_CFLAGS}
    LINKER_LANGUAGE C
    )
include_directories(
    ${CMAKE_SOURCE_DIR}
    ${PULSEAUDIO_INCLUDE_DIR}
    ${CMAKE_BINARY_DIR}
    ${ALSA_INCLUDE_DIRS}
    )
target_link_libraries(libgenesis_shared LINK_PRIVATE
    ${LIBAV_LIBRARIES}
    ${PULSEAUDIO_LIBRARY}
    ${ALSA_LIBRARIES}
    m
    )
target_link_libraries(libgenesis_shared LINK_PUBLIC ${CMAKE_THREAD_LIBS_INIT})
include_directories(${LIBAV_INCLUDE_DIRS})
install(TARGETS libgenesis_shared DESTINATION lib)


add_library(libgenesis_static STATIC ${LIBGENESIS_SOURCES})
set_target_properties(libgenesis_static PROPERTIES
    OUTPUT_NAME genesis
    COMPILE_FLAGS ${LIB_CFLAGS}
    LINKER_LANGUAGE C
    )
install(TARGETS libgenesis_static DESTINATION lib)

install(FILES
    ${LIBGENESIS_HEADERS}
    ${CONFIGURE_OUT_FILE}
    DESTINATION "include/genesis")

# Example Programs

add_executable(list_devices example/list_devices.c)
set_target_properties(list_devices PROPERTIES
    LINKER_LANGUAGE C
    COMPILE_FLAGS ${EXAMPLE_CFLAGS})
include_directories(${EXAMPLE_INCLUDES})
target_link_libraries(list_devices libgenesis_shared)
add_dependencies(list_devices libgenesis_shared)

add_executable(normalize_audio example/normalize_audio.c)
set_target_properties(normalize_audio PROPERTIES
    LINKER_LANGUAGE C
    COMPILE_FLAGS ${EXAMPLE_CFLAGS})
include_directories(${EXAMPLE_INCLUDES})
target_link_libraries(normalize_audio libgenesis_shared m)
add_dependencies(normalize_audio libgenesis_shared)

add_executable(list_supported_formats example/list_supported_formats.c)
set_target_properties(list_supported_formats PROPERTIES
    LINKER_LANGUAGE C
    COMPILE_FLAGS ${EXAMPLE_CFLAGS})
include_directories(${EXAMPLE_INCLUDES})
target_link_libraries(list_supported_formats libgenesis_shared)
add_dependencies(list_supported_formats libgenesis_shared)

add_executable(synth example/synth.c)
set_target_properties(synth PROPERTIES
    LINKER_LANGUAGE C
    COMPILE_FLAGS ${EXAMPLE_CFLAGS})
include_directories(${EXAMPLE_INCLUDES})
target_link_libraries(synth libgenesis_shared)
add_dependencies(synth libgenesis_shared)


add_executable(generate_unicode_data ${GENERATE_UNICODE_DATA_SOURCES})
set_target_properties(generate_unicode_data PROPERTIES
    LINKER_LANGUAGE C
    COMPILE_FLAGS ${LIB_CFLAGS})

set(UNICODE_DATA_TXT "/usr/share/unicode/UnicodeData.txt")
add_custom_command(
    OUTPUT ${UNICODE_HPP}
    COMMAND generate_unicode_data ARGS ${UNICODE_DATA_TXT} ${UNICODE_HPP}
    DEPENDS ${UNICODE_DATA_TXT}
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    )

set(ASSETS_JSON_FILE "${CMAKE_SOURCE_DIR}/assets.json")
set(RESOURCES_FILE "${CMAKE_BINARY_DIR}/resources.bundle")
add_custom_target(rucksack_bundle ALL
    ${RUCKSACK_BINARY} bundle ${ASSETS_JSON_FILE} ${RESOURCES_FILE}
    DEPENDS ${ASSETS_JSON_FILE}
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    )

add_executable(genesis ${GENESIS_SOURCES} ${GENESIS_HEADERS})
set_target_properties(genesis PROPERTIES
    LINKER_LANGUAGE CXX
    COMPILE_FLAGS ${LIB_CFLAGS})
include_directories(
    ${FREETYPE_INCLUDE_DIR}
    ${PNG_INCLUDE_DIR}
    ${RUCKSACK_INCLUDE_DIR}
    ${GLFW_INCLUDE_DIR}
    ${EPOXY_INCLUDE_DIR}
    )
target_link_libraries(genesis libgenesis_shared
    ${FREETYPE_LIBRARY}
    ${PNG_LIBRARY}
    ${RUCKSACK_LIBRARY}
    ${GLFW_LIBRARY}
    ${EPOXY_LIBRARY}
    )
add_dependencies(genesis libgenesis_shared ${UNICODE_HPP})
install(TARGETS genesis DESTINATION bin)


enable_testing()
add_executable(unit_tests ${TEST_SOURCES} ${TEST_HEADERS})
set_target_properties(unit_tests PROPERTIES
    LINKER_LANGUAGE CXX
    COMPILE_FLAGS ${LIB_CFLAGS})
add_test(UnitTests unit_tests)

message("\n"
    "Installation Summary\n"
    "--------------------\n"
    "* Install Directory            : ${CMAKE_INSTALL_PREFIX}\n"
    )

message(
    "System Dependencies\n"
    "-------------------\n"
    "* threads                      : ${STATUS_THREADS}\n"
    "* libavformat                  : ${STATUS_LIBAVFORMAT}\n"
    "* libavcodec                   : ${STATUS_LIBAVCODEC}\n"
    "* libavutil                    : ${STATUS_LIBAVUTIL}\n"
    "* freetype                     : ${STATUS_FREETYPE}\n"
    "* libpng                       : ${STATUS_PNG}\n"
    "* rucksack                     : ${STATUS_RUCKSACK}\n"
    "* pulseaudio                   : ${STATUS_PULSEAUDIO}\n"
    "* GLFW                         : ${STATUS_GLFW}\n"
    "* libepoxy                     : ${STATUS_EPOXY}\n"
    "* ALSA                         : ${STATUS_ALSA}\n"
    )