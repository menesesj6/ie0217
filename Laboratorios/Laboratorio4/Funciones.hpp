#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <string>

using namespace std;
using namespace std::chrono;

// Prototipos de funciones
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
void generateRandomArray(int arr[], int n);
void measuringSortingTime(void (*sortingAlgorithm)(int[], int), int arr[], int n, string algorithmName);
void measuringQuickSortTime(void (*sortingAlgorithm)(int[], int, int), int arr[], int low, int high, string algorithmName);

#endif