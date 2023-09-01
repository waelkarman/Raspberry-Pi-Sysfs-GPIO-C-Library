cmake_minimum_required(VERSION 3.15)

project(sfGPIO)

add_library(sfGPIO GPIO.cpp GPIO.h)

install(TARGETS sfGPIO DESTINATION lib)