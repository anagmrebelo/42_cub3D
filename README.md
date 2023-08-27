# 42_cub3D
This is the README file for the cub3d project, completed as part of the curriculum at 42 coding school. The objective of this project is to create a simple raycasting game engine that renders a 3D maze using the principles of raycasting.

## Description
cub3d is a project that introduces students to the concepts of raycasting and graphics rendering. The project involves creating a simple 3D game engine that displays a maze-like environment. The engine uses raycasting to simulate a 3D perspective in a 2D grid, similar to the techniques used in early first-person shooter games.

## Features
Raycasting-based graphics engine
Textured walls and sprites rendering
Basic maze exploration
Adjustable screen resolution and window size
Support for multiple textures and sprite images
Basic collision detection
Minimalistic user interface
Installation
Clone the repository:

## Instalation
git clone https://github.com/your-username/cub3d.git
cd 42_cub3D
make

## Usage
./cub3D path/to/map.cub

## Controls
W: Move forward
A: Move left
S: Move backward
D: Move right
Left Arrow: Rotate camera left
Right Arrow: Rotate camera right
Esc: Exit the game
Map Format
The map is defined in a .cub configuration file. Here's a basic example of the map format:

R 1920 1080
NO textures/north_texture_path.png
SO textures/south_texture_path.png
WE textures/west_texture_path.png
EA textures/east_texture_path.png
S sprite_path.png
F 220,100,0
C 50,50,50
111111
100001
101101
100001
111111
For detailed specifications, please refer to the project subject or documentation.

Screenshots
Insert some screenshots of your project in action.

Resources
Insert any resources, tutorials, or references you used to complete the project.

Contributors
Ana Rebêlo (@anagmrebelo)
Micaela Rollo ()


License
This project is licensed under the MIT License.
