cmake_minimum_required(VERSION 3.16)
project(Problem CXX)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

find_package(Z3
  REQUIRED
  CONFIG
)

include_directories(
  ${CMAKE_SOURCE_DIR}/src
  ${Z3_CXX_INCLUDE_DIRS}
)

file(GLOB libdum_SRC
"${CMAKE_SOURCE_DIR}/src/*.cpp"
)

# set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

message(STATUS "Z3_FOUND: ${Z3_FOUND}")
message(STATUS "Found Z3 ${Z3_VERSION_STRING}")
message(STATUS "Z3_DIR: ${Z3_DIR}")

add_library(DUM_static STATIC ${libdum_SRC})

set_target_properties(DUM_static 
    PROPERTIES 
    CXX_STANDARD 17
    CXX_EXTENSIONS OFF
    CXX_STANDARD_REQUIRED ON
)

add_executable(main src/main.cpp)

set_target_properties(main 
    PROPERTIES 
    CXX_STANDARD 17
    CXX_EXTENSIONS OFF
    CXX_STANDARD_REQUIRED ON
)

add_dependencies(main DUM_static ${Z3_LIBRARIES})
target_link_libraries(main DUM_static ${Z3_LIBRARIES})
