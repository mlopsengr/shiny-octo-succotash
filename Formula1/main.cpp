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

