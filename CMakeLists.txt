cmake_minimum_required(VERSION 3.27)
set(PROJECT_NAME AI_with_jetpack_and_grenade_launcher)
project(${PROJECT_NAME})

file(GLOB source_files
    "main.cpp"
)

set(SOURCES ${source_files})

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(
    SFML 2 REQUIRED COMPONENTS
    network
    audio
    graphics
    window
    system
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE "include" "lib")
target_include_directories(${PROJECT_NAME} PUBLIC ${xtensor_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics)

add_subdirectory(lib/xsimd)
add_subdirectory(lib/xtl)
add_subdirectory(lib/xtensor)

target_include_directories(${PROJECT_NAME}
  PUBLIC lib/xsimd/include
  PUBLIC lib/xtl/include
  PUBLIC lib/xtensor/include
)

target_link_directories(${PROJECT_NAME}
  PUBLIC lib/xsimd
  PUBLIC lib/xtl
  PUBLIC lib/xtensor
)

if (WIN32)
   target_link_libraries(${PROJECT_NAME} pthread)
endif (WIN32)