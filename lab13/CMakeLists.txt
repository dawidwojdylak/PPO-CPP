cmake_minimum_required (VERSION 2.6)
project (Lab13 CXX)

include_directories(src include)

add_executable(Lab13 main.cpp)

set(LIBSRC include/MyString.h src/MyString.cpp)
add_library(lab13 ${LIBSRC})

target_link_libraries(Lab13 lab13)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-DLIB_TEST -Wall -g")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
set(CMAKE_CXX_FLAGS_RELEASE "-DNDEBUG -O2")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

install(TARGETS Lab13 DESTINATION bin)

add_custom_target(info # ALL # target zoo is always built
    COMMAND echo "Build commands:"
    COMMAND cat compile_commands.json 
    COMMAND echo ""
    COMMAND echo ""
    COMMAND echo "Debug info:"
    COMMAND readelf --debug-dump=decodedline Lab13
    DEPENDS Lab13
)

add_custom_target(create_zip COMMAND
    ${CMAKE_COMMAND} -E tar "cfv" "lab13.zip" --format=zip
       "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp"
       "${CMAKE_CURRENT_SOURCE_DIR}/include" 
       "${CMAKE_CURRENT_SOURCE_DIR}/src" 
       "${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt") 