# cube3D

This project is an implementation of a simple raycasting engine. The program renders a 3D maze, allowing the user to navigate it through keyboard input.

## Features

- **Wall Textures**: Displays different textures based on the wall's direction (North, South, East, West).
- **Floor and Ceiling Colors**: Supports customizable floor and ceiling colors.
- **Navigation**:
    - Arrow keys allow the player to look left and right.
    - W, A, S, D keys move the player's point of view through the maze.
- **Map Parsing**: Takes a `.cub` file as input, parses it, and renders the scene accordingly.
- **Texture Mapping**: Supports different textures for walls in .xml format.

## Map File Format

The program expects a scene description file with a `.cub` extension. The file format follows specific rules:

1. **Wall Characters**:
    - `0` for an empty space.
    - `1` for a wall.
    - `N`, `S`, `E`, `W` for the player's starting position and orientation.
2. **File Structure**:
    - The map is composed of rows of characters where the player is represented by **N**, **S**, **E**, or **W**.
    - Each element (textures, floor, ceiling) can be separated by one or more empty lines.
    - The map must be surrounded by walls; otherwise, the program will return an error.
3. **Example**:

```bash
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture 

F 220,100,0 
C 225,30,0

111111
100101
101001
1100N1
111111
```

## Controls

- **W**: Move forward
- **A**: Move left
- **S**: Move backward
- **D**: Move right
- **Arrow Left**: Look left
- **Arrow Right**: Look right
- **ESC**: Exit the program

## Installation and running

```bash
git clone https://github.com/stanislavmg/cube3d
cd cube3d
make
./cube3D maps/map.cub
```
