//
//  main.cpp
//  Formula1
//
//  Created by Oluwatobi John Oluwafemi on 22/12/2023.
//

#include <iostream>
#include <vector>


// Constants
const double dt = 0.01; // Time step
const double dx = 0.1; // Spatial step
const int nx = 50;
const int ny = 50;

// Function to initialize the grid
void initialize(std::vector<std::vector<double>>& grid) {
    // Set initial conditions (e.g., start with a uniform velocity field)
    for (int i = 0; i < nx; ++i) {
        for (int j = 0; j < ny; ++j) {
            grid[i][j] = 1.0;
        }
    }
}

// Function to perform a time step using a simple advection equation
void timeStep(std::vector<std::vector<double>>& grid) {
    std::vector<std::vector<double>> newGrid(nx, std::vector<double>(ny, 0.0));

    for (int i = 1; i < nx - 1; ++i) {
        for (int j = 1; j < ny - 1; ++j) {
            // Simple advection equation
            newGrid[i][j] = grid[i][j] - (dt / dx) * (grid[i][j] - grid[i - 1][j]);
        }
    }

    // Update the grid
    grid = newGrid;
}


// Function to print grid
void printGrid(const std::vector<std::vector<double>>& grid) {
    for (int i = 0; i < nx; ++i) {
        for (int j = 0; j < ny; ++j) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    // Create and initialize the grid
    std::vector<std::vector<double>> velocityGrid(nx, std::vector<double>(ny, 0.0));
    initialize(velocityGrid);
    
    // Perform a few time steps
    for (int step = 0; step < 10; ++step) {
        timeStep(velocityGrid);
    }
    // Print the final grid
    printGrid(velocityGrid);
    return 0;
}
