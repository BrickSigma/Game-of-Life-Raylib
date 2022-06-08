# Conway's Game of Life
 This is a remake of Conway's Game of Life in C using the RayLib framework.  

 This project was based off of NeuralNine's tutorial which was written using python and pygame. The main functions and processes are simialr to the python version, and you can find the original tutorial [here](https://www.youtube.com/watch?v=cRWg2SWuXtM). 

 ## How to Build and Run
 Clone or download the repository and open the directory in command prompt. Run the command `make` to build the executable and run it. 

 ## Additional Information
 - I have made a custom functions for managing 2D arrays within [array.c](src/array.c) and [array.h](headers/array.h),
 - It has built in functions for creating 2D `int` arrays and freeing their memory once used,
 - Other functions mimic those of the [NumPy](https://github.com/numpy/numpy) library such as `sumArray`, `fillArray`, and `copyArray`.
 - Finally a custom `Range` struct has been made for looping through regions of 2D arrays.

 ## Notes
 - This project was simply for learning the basics of C and RayLib.  
 - The executable has been tested only on Windows 10, but it should compile on other operating systems.