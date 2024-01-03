cmake_minimum_required(VERSION 3.26)

# set the project name
project(libtess2 VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(tess2
./Source/priorityq.c
./Source/tess.h
./Source/tess.c
./Source/geom.h
./Source/dict.c
./Source/dict.h
./Source/geom.c
./Source/mesh.h
./Source/priorityq.h
./Source/sweep.c
./Source/bucketalloc.c
./Source/mesh.c
./Source/sweep.h
./Source/bucketalloc.h
 )

install(TARGETS tess2 DESTINATION lib)

install(FILES
  ./Include/tesselator.h
  ./Include/tesselator_cpp.h
  DESTINATION include)

target_include_directories(tess2
  PUBLIC
  Include
  )

target_link_libraries(tess2
    PUBLIC
    )

