cmake_minimum_required (VERSION 2.6)
project (Roundup)
add_executable(Roundup main.c roundup.c roundup.h)
install (TARGETS Roundup DESTINATION bin)
