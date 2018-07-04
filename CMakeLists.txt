cmake_minimum_required(VERSION 3.8)
project(codeforces)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -O2")

file(GLOB sources "src/*/*.cpp")
foreach(src ${sources})
  get_filename_component(full_dir ${src} DIRECTORY)
  get_filename_component(contest_id ${full_dir} NAME)
  get_filename_component(prob_id ${src} NAME_WE)
  add_executable(${contest_id}${prob_id} ${src})
endforeach()
