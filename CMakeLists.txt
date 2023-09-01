cmake_minimum_required(VERSION 3.15)

project(sysfsgpio)

add_library(sysfsgpio GPIO.cpp GPIO.h)

install(TARGETS sysfsgpio DESTINATION lib)