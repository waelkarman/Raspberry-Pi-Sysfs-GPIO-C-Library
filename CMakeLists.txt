cmake_minimum_required(VERSION 3.15)

project(sysfsgpio)

add_library(sysfsgpio SHARED sysfsgpio.cpp sysfsgpio.h)

install(TARGETS sysfsgpio DESTINATION lib)
