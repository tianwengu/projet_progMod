# Projet ProgMod — Population Simulation (C++)

A modular C++ project simulating populations of animals evolving on a grid.  
Developed as part of a course on **programmation modulaire**.

## Project Overview
The simulation models a simple ecosystem:
- **Animals** (`animal.*`) with attributes/behaviors
- **Populations** (`population.*`) grouping animals
- **Grid** (`grille.*`) representing the environment
- **Game system** (`jeu.*`, `systeme.hpp`) handling interactions and evolution
- **Ensemble/system modules** for higher-level management

## Features
- Object-oriented design with C++ classes
- Simulation of populations on a discrete grid
- Modular decomposition (each component in its own module)
- Unit testing with Doctest

## Build & Run
```sh
make
./progmod
```
