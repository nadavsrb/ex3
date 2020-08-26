
cmake_minimum_required(VERSION 3.0.0)
project(ex2 VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(-Wall -Wextra -pedantic -Werror -Wnon-virtual-dtor -Wshadow)

# Add the libmatrix file to the include path - so that
#   we can include it as without explicitly specifying 
#   the files directory.
include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/lib)
include_directories(${CMAKE_SOURCE_DIR}/src)
# Link directories - tells the linker to look for .so files
#   in these directories. We want libmatrix.so which is under 
#   the matrix directory. Note that a full path is required.
link_directories(${CMAKE_SOURCE_DIR}/src)
link_directories(${CMAKE_SOURCE_DIR}/lib)
link_directories(${CMAKE_SOURCE_DIR})


file(GLOB My_Source_Files src/*.cpp)
add_executable(ex2.out main.cpp ${My_Source_Files})
set_target_properties(ex2.out PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../src/bin)
target_link_libraries(ex2.out matrix)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)



