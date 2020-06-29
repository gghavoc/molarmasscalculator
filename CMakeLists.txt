cmake_minimum_required(VERSION 3.15)
project(MolarMassCalculator)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}")
message(STATUS "PROJECT SOURCE DIRECTORY: ${PROJECT_SOURCE_DIR}")

# BUILD CONFIGURATION
set(BUILD_CONFIG_WIN32 "msw") # to store config variable for windows
set(BUILD_CONFIG_UNIX "BUILD CONFIG: ") # to store config variable for linux
set(USE_UNIVERSAL "FALSE")
set(USE_UNICODE "TRUE")
set(USE_DEBUG "FALSE")
set(USE_STATIC "TRUE")

set(wxWidgets_EXCLUDE_COMMON_LIBRARIES "FALSE")

# IF WINDOWS
if (WIN32)
    file(TO_CMAKE_PATH "$ENV{MinGW32_Root}" MinGW32_Root) # make the path unix
    file(TO_CMAKE_PATH "$ENV{wxDIR}" wxDIR) # make the path unix
    set(wxWidgets_ROOT_DIR "${wxDIR}")
    set(wxWidgets_LIB_DIR "${wxDIR}/lib/gcc_lib")
    set(CMAKE_C_COMPILER "${MinGW32_Root}/bin/gcc.exe")
    set(CMAKE_CXX_COMPILER "${MinGW32_Root}/bin/g++.exe")
    set(CMAKE_GENERATOR "MinGW Makefiles")
    set(CMAKE_GENERATOR_PLATFORM "x86")
    message(STATUS "PLATFORM: WIN32")
elseif(MSVC)
    set(wxWidgets_ROOT_DIR "${wxDIR}" )
    set(wxWidgets_LIB_DIR "${wxDIR}/lib/vc_lib")
endif()

# FOR UNIX OPERATING SYSTEMS
if (UNIX AND NOT APPLE)
    set(LINUX "TRUE")
endif()

if (LINUX)
    set(wxWidgets_ROOT_DIR "$ENV{wxuml}")
    set(wxWidgets_LIB_DIR "$ENV{wxuml}/lib")
    set(PLATFORM "LINUX")
elseif (APPLE)
    set(PLATFORM "APPLE")
elseif (UNIX AND NOT APPLE AND NOT LINUX)
    set(PLATFORM "UNIX")
endif()

message(STATUS "PLATFORM: ${PLATFORM}")
message(STATUS "SYSTEM: ${CMAKE_SYSTEM}")
message(STATUS "SYSTEM NAME: ${CMAKE_SYSTEM_NAME}")

message(STATUS "WXWIDGETS ROOT DIRECTORY: ${wxWidgets_ROOT_DIR}")
message(STATUS "WXWIDGETS LIB DIRECTORY: ${wxWidgets_LIB_DIR}")

if(WIN32 OR MSVC)
    if(USE_UNIVERSAL)
        string(APPEND BUILD_CONFIG_WIN32 "univ")
    endif()

    if(USE_UNICODE)
        string(APPEND BUILD_CONFIG_WIN32 "u")
    endif()

    if(USE_DEBUG)
        string(APPEND BUILD_CONFIG_WIN32 "d")
    endif()

    if(NOT USE_STATIC)
        string(APPEND BUILD_CONFIG_WIN32 "dll")
    endif()

    message(STATUS "WINDOWS BUILD CONFIG: ${BUILD_CONFIG_WIN32}")
    set(wxWidgets_CONFIGURATION "${BUILD_CONFIG_WIN32}")
endif()

if (UNIX)
    if(USE_UNIVERSAL)
        set(wxWidgets_USE_UNIVERSAL "TRUE")
        string(APPEND BUILD_CONFIG_UNIX "UNIVERSAL ")
    endif()

    if(USE_UNICODE)
        set(wxWidgets_USE_UNICODE "TRUE")
        string(APPEND BUILD_CONFIG_UNIX "UNICODE ")
    else()
        string(APPEND BUILD_CONFIG_UNIX "ASCII ")
    endif()

    if(USE_DEBUG)
        set(wxWidgets_USE_DEBUG "TRUE")
        string(APPEND BUILD_CONFIG_UNIX "DEBUG ")
    else()
        string(APPEND BUILD_CONFIG_UNIX "RELEASE ")
    endif()

    if(USE_STATIC)
        set(wxWidgets_USE_STATIC "TRUE")
        string(APPEND BUILD_CONFIG_UNIX "STATIC ")
    else()
        string(APPEND BUILD_CONFIG_UNIX "SHARED ")
    endif()

endif()

find_package(wxWidgets COMPONENTS core base REQUIRED)
include("${wxWidgets_USE_FILE}")

message(STATUS "wxWidgets USE FILE: ${wxWidgets_USE_FILE}")

set(SRC_FILES
        main.cpp
        sources/MainApp.cpp
        sources/MainApp.h
        sources/MainFrame.cpp
        sources/MainFrame.h
        sources/PaintWindow.cpp
        sources/PaintWindow.h
        sources/CompoundTextArea.cpp
        sources/CompoundTextArea.h
        sources/Element.h
        sources/Element.cpp
        sources/MolarMass.h
        sources/MolarMass.cpp
        sources/EventHandler.cpp
        sources/EventHandler.h
        sources/ElementResultsList.cpp
        sources/ElementResultsList.h
        sources/TotalTextOutput.cpp
        sources/TotalTextOutput.h
        sources/ElementBox.cpp
        sources/ElementBox.h
        sources/ElementResultsListEntry.cpp
        sources/ElementResultsListEntry.h
    )

add_executable(MolarMassCalculator "${SRC_FILES}")

if (WIN32)
    target_link_libraries(MolarMassCalculator "${wxWidgets_LIBRARIES}" "${MinGW32_Root}/lib/libuxtheme.a" "${MinGW32_Root}/lib/liboleacc.a")
elseif (LINUX)
    target_link_libraries(MolarMassCalculator "${wxWidgets_LIBRARIES}")
endif()

# POST COMMANDS FOR SHARED LIBRARIES
if (NOT USE_STATIC)
    # TODO Make post build commands to copy dynamic libraries to output folder
endif()