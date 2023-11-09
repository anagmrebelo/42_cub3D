# 42_cub3D
![ezgif com-video-to-gif-5](https://github.com/anagmrebelo/42_cub3D/assets/66007323/03f1d3b5-39dd-4ffb-94a4-5a39fe2eb260)

This is the README file for the cub3d project, completed as part of the curriculum at 42 coding school. The objective of this project is to create a simple raycasting game engine that renders a 3D maze using the principles of raycasting.

## Description
cub3d is a project that introduces students to the concepts of raycasting and graphics rendering. The project involves creating a simple 3D game engine that displays a maze-like environment. The engine uses raycasting to simulate a 3D perspective in a 2D grid, similar to the techniques used in early first-person shooter games.

## Features
- Raycasting-based graphics engine
- Textured walls and sprites rendering
- Basic maze exploration
- Support for multiple textures and sprite images
- Basic collision detection
- Minimalistic user interface

## Instalation
```
git clone https://github.com/anagmrebelo/42_cub3D
cd 42_cub3D
make
```

## Usage
```
./cub3D maps/map.cub
```

## Controls
W: Move forward

A: Move left

S: Move backward

D: Move right

Left Arrow: Rotate camera left

Right Arrow: Rotate camera right

Esc: Exit the game

## Map Format
The map is defined in a .cub configuration file. Here's a basic example of the map format:

```
NO srcs/imgs/wall_text/a.xpm
SO srcs/imgs/wall_text/b.xpm
EA srcs/imgs/wall_text/c.xpm
WE srcs/imgs/wall_text/d.xpm
F 30,240,200
C 40,12,240
111111
100001
101101
100001
111111
```
For detailed specifications, please refer to the project subject or documentation.

## Screenshots
<img width="961" alt="Screenshot 2023-08-27 at 18 50 51" src="https://github.com/anagmrebelo/42_cub3D/assets/66007323/e0411965-f6b9-4948-b712-78439ab1cfb1">

## Contributors
Ana Rebêlo (@anagmrebelo)

Micaela Rollo (@micarollo)

