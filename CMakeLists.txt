cmake_minimum_required(VERSION 3.15)
project(MolarMassCalculator)

set(CMAKE_CXX_STANDARD 20)

set(wxWidgets_ROOT_DIR </usr/local/include/wx-3.1>)
set(wxWidgets_CONFIGURATION mswu)
find_package(wxWidgets COMPONENTS core base  REQUIRED)
include(${wxWidgets_USE_FILE})

set(MolarMassCalculator
        main.cpp
        sources/MainApp.cpp
        sources/MainApp.h
        sources/MainFrame.cpp
        sources/MainFrame.h
        sources/PaintWindow.cpp
        sources/PaintWindow.h
        sources/CompoundTextArea.cpp
        sources/CompoundTextArea.h
        sources/ElementListBox.cpp
        sources/ElementListBox.h
        sources/Element.h
        sources/Element.cpp
        sources/MolarMass.h
        sources/MolarMass.cpp
        sources/EventHandler.cpp sources/EventHandler.h)
add_executable(MolarMassCalculator ${MolarMassCalculator})

target_link_libraries(MolarMassCalculator ${wxWidgets_LIBRARIES})