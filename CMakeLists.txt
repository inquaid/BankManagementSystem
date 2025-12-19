cmake_minimum_required(VERSION 3.27)
project(BankManagementSystem C)

set(CMAKE_C_STANDARD 23)

# Add executable with just your .c files (headers are auto-included by compiler)
add_executable(BankManagementSystem
        main.c
        # Add other .c files if they exist (not just .h headers)
)

# Find and link ncurses
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
target_link_libraries(BankManagementSystem ${CURSES_LIBRARIES})
