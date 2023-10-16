cmake_minimum_required(VERSION 3.26)
project(PhoneInventoryPro C)

set(CMAKE_C_STANDARD 23)

add_executable(PhoneInventoryPro main.c
        functions.h
        functions.c)

# Copy inventory.txt to the build directory
add_custom_command(
        TARGET PhoneInventoryPro POST_BUILD  # Updated target name
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/inventory.txt
        ${CMAKE_CURRENT_BINARY_DIR}/inventory.txt
)