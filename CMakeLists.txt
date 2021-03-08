cmake_minimum_required(VERSION 2.8)

project( Aves )

#Bring the headers, such as Student.h into the project
include_directories(include)

# Add src files:
file(GLOB SOURCES "src/*.cpp")

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

#add_executable( Aves Aves.cpp )
add_executable(Aves ${SOURCES})
target_link_libraries( Aves ${OpenCV_LIBS} ${DEPENDENCIES})
