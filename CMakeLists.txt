cmake_minimum_required(VERSION 3.16)
project(PixelBird LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

file (GLOB SOURCES
    src/*.h
    src/*.cpp
)

add_executable(PixelBird ${SOURCES})
target_link_libraries(PixelBird PRIVATE sfml-graphics)
target_compile_features(PixelBird PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET PixelBird
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:PixelBird>
        VERBATIM)
endif()

set (source "${CMAKE_SOURCE_DIR}/src/assets")
set (destination "${CMAKE_CURRENT_BINARY_DIR}/assets")
add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E create_symlink ${source} ${destination} 
    DEPENDS ${destination}
    COMMENT "symbolic link resources folder from ${source} => ${destination}"
)

install(TARGETS PixelBird)
