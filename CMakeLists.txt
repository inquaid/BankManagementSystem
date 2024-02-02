cmake_minimum_required(VERSION 3.27)
project(BankManagementSystem C)

set(CMAKE_C_STANDARD 23)

add_executable(BankManagementSystem main.c
        MyFunctions.h
        sha256.h)
