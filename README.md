# Fractals

A simple fractal visualizer made with SFML, GLSL and ImGui

## Setup

This version was tested with the Mingw32 C++ compiler , SFML 2.6.1, ImGui 1.90.2 and ImGui-sfml 2.6

### Prerequisites

1. Install `mingw32` and don't forget to a add it to the PATH variable

2. Download the [SFML library](https://www.sfml-dev.org/download.php), make sure to select the `MinGW (DW2) - 32-bit` version

3. Clone the [ImGui](https://github.com/ocornut/imgui) and [ImGui-SFML](https://github.com/SFML/imgui-sfml) repositories

### Installation

1. Clone this repository and get inside it
2. Create the `lib`, and `imgui` folders into the `Fractals` folder
3. Extract the previously downloaded files
4. ~Copy the sfml dll to lib~ 
5. Copy the `include` and `bin` from `SFML-2.6.1` into the `Fractals` folder
6. Copy all the `.cpp` and `.h` files from `imgui-master` except `imgui_demo.cpp` into the `imgui` folder
7. Same for `imgui-sfml-2.6.x` 
8. Edit the `imconfig.h` file in the imgui folder by adding the line `#include "imconfig-SFML.h"` after the `#pragma once` line
9. And then get into your favorite commandline tool, move into the `Fractals` folder and type `mingw32-make`
10. Enjoy

## Some images