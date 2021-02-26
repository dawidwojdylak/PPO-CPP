cmake_minimum_required(VERSION 2.6)

project(lab06)

include_directories(include src)

add_executable(lab06 main.cpp src/lab06.cpp)

set(CMAKE_CXX_FLAGS "-Wall -g")

add_custom_target(MAKE_ZIP)
#add_custom_target(STAGE_FILES)

add_custom_command( 
#  TARGET STAGE_FILES 
  TARGET MAKE_ZIP
  COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/assets/video ${CMAKE_CURRENT_BINARY_DIR}/video
  COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/assets/data ${CMAKE_CURRENT_BINARY_DIR}/data
  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/assets/strings_en.csv ${CMAKE_CURRENT_BINARY_DIR}/
  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/assets/strings_rules_en.csv ${CMAKE_CURRENT_BINARY_DIR}/
  COMMAND ${CMAKE_COMMAND} -E tar "cfv" "data.zip" --format=zip  --files-from=${CMAKE_SOURCE_DIR}/assets/to_zip.txt
  COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_CURRENT_BINARY_DIR}/data
  COMMAND ${CMAKE_COMMAND} -E rename  ${CMAKE_CURRENT_BINARY_DIR}/data.zip ${CMAKE_CURRENT_BINARY_DIR}/data
)

add_custom_target(create_zip COMMAND
    ${CMAKE_COMMAND} -E tar "cfv" "lab06.zip" --format=zip
       "${CMAKE_CURRENT_SOURCE_DIR}/testfile.txt"
       "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp"
       "${CMAKE_CURRENT_SOURCE_DIR}/testdir"
       "${CMAKE_CURRENT_SOURCE_DIR}/testdir"
       "${CMAKE_CURRENT_SOURCE_DIR}/testdir")