cmake_minimum_required(VERSION 3.21.3)

project(twoe)

set(sashka2_src Source.cpp Autotest.cpp CVector.cpp)
set(sashka2_hdr CVector.h Autotest.h)

add_executable(${PROJECT_NAME} ${sashka2_src} ${sashka2_hdr})