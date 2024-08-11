cmake_minimum_required(VERSION 3.8)
include(${cpp_lib_build_scripts_path}/cmake-module/setup.cmake)
include(target_import_boost)
include(target_import_qt)
include(target_import_base)
include(target_import_cli11)

set(ProjectName point24)
project(${ProjectName})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 17)

add_executable(${ProjectName})
target_import_src(${ProjectName})
target_import_base(${ProjectName} PUBLIC)
target_import_cli11(${ProjectName} PUBLIC)

set(CMAKE_INSTALL_PREFIX ${cpp_lib_build_scripts_path}/${platform}/.libs/${ProjectName}/)