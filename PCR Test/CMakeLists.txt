cmake_minimum_required(VERSION 3.21)
project(PCR_Test)

set(CMAKE_CXX_STANDARD 14)

add_executable(PCR_Test main.cpp Queue.h Assistance.cpp Assistance.h LinkList.h Node.h PCRTest.cpp PCRTest.h Person.cpp Person.h)
