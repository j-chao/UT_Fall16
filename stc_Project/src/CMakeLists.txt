cmake_minimum_required (VERSION 2.6)

set(CMAKE_C_COMPILER "/opt/apps/intel/16.0.1.150/compilers_and_libraries_2016.1.150/linux/bin/intel64/icc")
set(CMAKE_CXX_COMPILER "/opt/apps/intel/16.0.1.150/compilers_and_libraries_2016.1.150/linux/bin/intel64/icpc")

project (Needleman_Wunsch)
add_executable(Needleman_Wunsch main.c needleman_wunsch.c needleman_wunsch.h)
install (TARGETS Needleman_Wunsch DESTINATION bin)
