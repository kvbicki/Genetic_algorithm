Genetic Algorithm Implementation
Overview
This project implements a genetic algorithm framework designed to solve optimization problems. The algorithm evolves populations of candidate solutions over generations, applying selection, crossover, and mutation operations to find optimal or near-optimal solutions.

Features
Flexible Candidate Types: Supports different problem formulations through polymorphic candidate classes

Configurable Parameters: Adjustable population size, stopping conditions, and genetic operations

Multiple Stopping Criteria:

Maximum generation count

Minimum improvement threshold

Genetic Operations:

Roulette wheel selection

Single-point crossover

Bit-flip mutation

Problem Types:

Two-variable optimization (TCandidate_Zad1)

Different two-variable optimization (TCandidate_Zad2)

Three-variable optimization (TCandidate_Zad3)

How to Use
Compile the program:

text
g++ main.cpp TAlgorithm.cpp TCandidate.cpp TParam.cpp TPopulation.cpp -o genetic_algorithm
Run the program:

text
./genetic_algorithm
Choose a problem type when prompted:

1 for TCandidate_Zad1 (2x1x2)

2 for TCandidate_Zad2 (x1*x2 + x2)

3 for TCandidate_Zad3 (x1 + x2 + x3)

Configuration
The algorithm parameters can be adjusted in main.cpp:

candidates_count: Number of candidates in each population

max_population_count: Maximum number of generations

min_improvment_proc: Minimum improvement percentage threshold

pop_check: Number of previous generations to consider for improvement

Implementation Details
Key Classes
TCandidate: Abstract base class for candidate solutions

TCandidate_Zad1/Zad2/Zad3: Concrete problem implementations

TParam: Represents a single parameter with value range

TPopulation: Manages a collection of candidates

TAlgorithm: Controls the evolutionary process

Genetic Operations
Selection: Roulette wheel selection based on fitness

Crossover: Single-point crossover with 25% chance

Mutation: Bit-flip mutation with 5% chance per bit

Example Output
The program will display:

Population number and best value for each generation

Final best candidate information

Best value found

License
This project is open-source. Feel free to use and modify it for your needs.

Future Improvements
Add more problem types

Implement additional selection methods (tournament, rank-based)

Add configuration file support

Implement parallel processing for fitness evaluation
