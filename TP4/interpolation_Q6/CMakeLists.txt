cmake_minimum_required(VERSION 3.0)

project(interpolation_Q6 C)

add_library(MyLibrary biblio.h biblio.c)

add_executable(output code.c)

# the m option is to add a static library to make 
target_link_libraries(output PRIVATE MyLibrary m)
