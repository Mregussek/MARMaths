#
# Mateusz Rzeczyca
# Copyright (C) 2020 Mateusz Rzeczyca <info@mateuszrzeczyca.pl>
#

cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(MARMaths)

file(GLOB_RECURSE SOURCE_FILES 
	${CMAKE_SOURCE_DIR}/src/*.c
	${CMAKE_SOURCE_DIR}/src/*.cpp)
	
file(GLOB_RECURSE HEADER_FILES 
	${CMAKE_SOURCE_DIR}/src/*.h
	${CMAKE_SOURCE_DIR}/src/*.hpp)
	
set(MAIN_FILE ${CMAKE_SOURCE_DIR}/MARMaths.h)
	
add_library(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES} ${MAIN_FILE})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)