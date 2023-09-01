cmake_minimum_required(VERSION 3.15)

project(sysfsGPIO)

add_library(sysfsGPIO GPIO.cpp GPIO.h)

install(TARGETS sysfsGPIO DESTINATION lib)