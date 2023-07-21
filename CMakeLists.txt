cmake_minimum_required(VERSION 3.27)
set(PROJECT_NAME AIs_with_Grenade_Launchers_Fight)
project(${PROJECT_NAME} VERSION 1.0.0 LANGUAGES CXX)

file(GLOB source_files
	"main.cpp"
)

set(SOURCES ${source_files})

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED COMPONENTS network audio graphics window system)

add_executable(${PROJECT_NAME} ${SOURCES})
add_subdirectory(lib/sfml)

target_include_directories(${PROJECT_NAME}
    PUBLIC lib/sfml/include
)

target_link_directories(${PROJECT_NAME}
    PUBLIC lib/sfml
)
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)
target_include_directories(${PROJECT_NAME} PRIVATE "include" "lib")
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics)

if (WIN32)
   target_link_libraries(${PROJECT_NAME} pthread)
endif (WIN32)