cmake_minimum_required (VERSION 2.6)
project (Lab11 CXX)

include_directories(src include)

add_executable(Lab11 main.cpp)

set(LIBSRC include/Vector2D.h src/Vector2D.cpp)
add_library(lab11 ${LIBSRC})

target_link_libraries(Lab11 lab11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-DLIB_TEST -Wall -g")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
set(CMAKE_CXX_FLAGS_RELEASE "-DNDEBUG -O2")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

install(TARGETS Lab11 DESTINATION bin)

add_custom_target(info # ALL # target zoo is always built
    COMMAND echo "Build commands:"
    COMMAND cat compile_commands.json 
    COMMAND echo ""
    COMMAND echo ""
    COMMAND echo "Debug info:"
    COMMAND readelf --debug-dump=decodedline Lab11
    DEPENDS Lab11
)

add_custom_target(create_zip COMMAND
    ${CMAKE_COMMAND} -E tar "cfv" "lab11.zip" --format=zip
       "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp"
       "${CMAKE_CURRENT_SOURCE_DIR}/include" 
       "${CMAKE_CURRENT_SOURCE_DIR}/src" 
       "${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt") 