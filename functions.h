#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <string.h>
#include <process.h>

// Define the smartphone structure
struct smartphone {
    int id;
    char brand[20];
    char model[20];
    float screen_size;
    int memory;
    float camera_resolution;
    int price_no_plan;
    int price_one_year;
    int price_two_year;
    int stock;
};

// Function prototypes
void populateInventory();
void displayBrand();
void buyItem();
void returnItem();
void displayInventory();
void exitSystem();
void displayMenu();

#endif  // FUNCTIONS_H
