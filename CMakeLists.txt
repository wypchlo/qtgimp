set(CMAKE_CXX_FLAGS "")
set(CMAKE_C_FLAGS "")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

cmake_minimum_required(VERSION 3.19)
project(qtgimp LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(qtgimp
    WIN32 MACOSX_BUNDLE
    main.cpp
    src/ui/main_window.cpp
    src/ui/main_window.h
    src/ui/menu_bar.h
    src/ui/menu_bar.cpp
    src/ui/canvas.cpp
    src/ui/canvas.h
    src/utils/image_handler.cpp
    src/utils/image_handler.h
    src/utils/bezier.cpp
    src/utils/bezier.h
)

target_link_libraries(qtgimp
    PRIVATE
        Qt::Core
        Qt::Widgets
)

include(GNUInstallDirs)

install(TARGETS qtgimp
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET qtgimp
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)

target_include_directories(qtgimp PRIVATE
    ${PROJECT_SOURCE_DIR}/src
)

install(SCRIPT ${deploy_script})
