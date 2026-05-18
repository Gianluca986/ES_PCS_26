cmake_minimum_required(VERSION 3.20)
project(esercitazione9)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

# Creo il target per l'eseguibile principale del mio progetto software
set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
set(SRC_visit graph_visits.hpp   containers.hpp   main.cpp  )
add_executable(main ${SRC_visit})