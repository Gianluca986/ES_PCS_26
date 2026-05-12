cmake_minimum_required(VERSION 3.20)
project(esercitazione8)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

# Creo il target per l'eseguibile principale del mio progetto software
set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
set(SRC_graph unidirected_edge.hpp   unidirected_graph.hpp   test_unidirected_graph.cpp  )
add_executable(test_unidirected_graph ${SRC_graph})
