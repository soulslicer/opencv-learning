cmake_minimum_required(VERSION 2.8)
project( FirstProgram )
add_executable( FirstProgram FirstProgram.cpp )
target_link_libraries( FirstProgram  )
find_package( OpenCV REQUIRED )
target_link_libraries( FirstProgram ${OpenCV_LIBS} )
