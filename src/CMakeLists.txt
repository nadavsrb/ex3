
cmake_minimum_required(VERSION 3.0.0)
project(ex2 VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(-Wall -Wextra -pedantic -Werror -Wnon-virtual-dtor -Wshadow)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Add the libmatrix file to the include path - so that
#   we can include it as without explicitly specifying 
#   the files directory.
include_directories(${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/files ${CMAKE_SOURCE_DIR}/bmp
${CMAKE_SOURCE_DIR}/hash ${CMAKE_SOURCE_DIR}/matrix ${CMAKE_SOURCE_DIR}/cache_manager 
${CMAKE_SOURCE_DIR}/cache_manager/operations ${CMAKE_SOURCE_DIR}/cache_manager/time)
# Link directories - tells the linker to look for .so files
#   in these directories. We want libmatrix.so which is under 
#   the matrix directory. Note that a full path is required.
link__directories(${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/files ${CMAKE_SOURCE_DIR}/bmp
${CMAKE_SOURCE_DIR}/hash ${CMAKE_SOURCE_DIR}/matrix ${CMAKE_SOURCE_DIR}/cache_manager 
${CMAKE_SOURCE_DIR}/cache_manager/operations ${CMAKE_SOURCE_DIR}/cache_manager/time)


add_executable(ex3.out main.cpp cache_manager/operations/MatrixֹMultOperation.cpp cache_manager/time/CurrentTime.cpp 
cache_manager/MatrixMultOperation.cpp cache_manager/operations/MatrixAddOperation.cpp 
cache_manager/operations/ImageRotateOperation.cpp cache_manager/operations/ImageConvertOperation.cpp 
cache_manager/operations/HashCrc32Operation.cpp cache_manager/CacheManager.cpp  cache_manager/StringFunctions.cpp 
matrix/ErrorCodeException.cpp matrix/MatrixClass.cpp hash/crc32.cpp hash/crc32FileReader.cpp 
files/file_reading.cpp)
target_link_libraries(ex3.out matrix)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)





# add the .cpp files of the project
add_executable(ex3.out
                bmp/bmp.cpp
                bmp/bmp_tester.cpp
                cache/Cache.cpp
                cache/cache_manager.cpp
                hash/crc32.cpp
                exceptions/exceptions.cpp
                main.cpp
                matrix/matrix.cpp
                matrix/mat_parser.cpp
                paths/Paths.cpp
                )

# add the library
target_link_libraries(ex3.out matrix)

# add the folders of the .h files (to be able to include them)
target_include_directories(ex3.out PUBLIC
                            ${CMAKE_SOURCE_DIR}/bmp
                            ${CMAKE_SOURCE_DIR}/cache
                            ${CMAKE_SOURCE_DIR}/exceptions
                            ${CMAKE_SOURCE_DIR}/hash
                            ${CMAKE_SOURCE_DIR}/matrix
                            ${CMAKE_SOURCE_DIR}/paths
                            )

# make the cache directory
file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/cache)

# include the src directory
target_link_directories(ex3.out PUBLIC ${PROJECT_SOURCE_DIR})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)