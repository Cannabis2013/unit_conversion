cmake_minimum_required(VERSION 3.16)

project(converter LANGUAGES C)

add_executable(converter converter.c
    menu_ui.c
    menu_ui.h
    distance.h
    distance.c
    distance_ui.h
    distance_ui.c)

include(GNUInstallDirs)
install(TARGETS converter
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
