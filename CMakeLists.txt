cmake_minimum_required(VERSION 3.10)
project(GeneticAlgorithm)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



add_executable(genetic_algorithm
    src/main.cpp
    src/TAlgorithm.cpp
    src/TCandidate.cpp
    src/TParam.cpp
    src/TPopulation.cpp
)
