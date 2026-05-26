*This project has been created as part of the 42 curriculum by ssoto-su, mlermo-j.*

# cub3D

## Description
**cub3D** is a 42 school project that challenges us to create a realistic 3D maze explorer using the raycasting technique, inspired by the classic game *Wolfenstein 3D*. The primary goal of this project is to explore the mathematics behind raycasting, 2D to 3D perspective projection, window management, and event handling in C. The graphical engine is built using the **MLX42** library.

## Instructions

### Compilation
To compile the project and build the executable, simply run the following command in the root of the repository:
```bash
make
```
This will compile the source code along with its dependencies (like `libft` and `MLX42`) and generate the `cub3d` executable. 

### Execution
To launch the game, you must provide a valid map file (with a `.cub` extension) as a parameter.
```bash
./cub3d assets/maps/test.cub
```

### Controls
- **W, A, S, D**: Move Forward, Left, Backward, and Right.
- **Left / Right Arrow Keys**: Rotate the camera view.
- **ESC**: Quit the game gracefully.

## Map Format
The map file is a text file that describes the layout of the maze. It consists of a grid of characters, where:
- `1` represents a wall.
- `0` represents an empty space.
- `N`, `S`, `E`, `W` represent the player's starting position and orientation (North, South, East, West).

The textures for walls are provided with the next format:
```
NO ./assets/textures/north.png
SO ./assets/textures/south.png
WE ./assets/textures/west.png
EA ./assets/textures/east.png
```

The colors for the floor and ceiling are defined as follows:
```
F 220,100,0
C 225,30,0
```
If colors surpass 255, the program will start from 0 again. So `F 220,100,300` will be the same as `F 220,100,44`.

And then the map layout has to be defined with the next requirements:
- The map must be surrounded by walls (1s). SO it doesn't have to be a perfect rectangle, but it must be closed.
- There must be exactly one player starting position (N, S, E, or W).
With the next format:
```
111111
1N0001
100001
100001
111111
```

## Raycasting Technique

The core of **cub3D** relies on the Raycasting algorithm to render a 3D perspective from a 2D map. The technique computes the scene column by column across the screen, mimicking how light rays hit surfaces. Our implementation relies on the following steps for each vertical strip of the screen:

1. **Ray Initialization (`init_ray`)**: 
   For every vertical column of pixels ($x$) on the screen, a camera plane is set up. We calculate the ray direction:
   $$camera\_x = \frac{2x}{S\_WIDTH} - 1$$
   $$rayDirX = dirX + planeX \times camera\_x$$
   $$rayDirY = dirY + planeY \times camera\_x$$
   We also calculate the distance the ray has to travel to cross one x or y grid cell ($\Delta dist$):
   $$\Delta distX = \left| \frac{1}{rayDirX} \right|, \quad \Delta distY = \left| \frac{1}{rayDirY} \right|$$
   
2. **Step Setup (`calculate_step`)**: 
   Depending on the ray's direction, we determine if it will step positively or negatively along the grid. The initial distance from the player to the first grid boundary ($sideDist$) is calculated. For example, on the X axis:

   If $rayDirX < 0$: 
   $$sideDistX = (posX - mapX) \times \Delta distX$$

   If $rayDirX \ge 0$: $$sideDistX = (mapX + 1.0 - posX) \times \Delta distX$$

3. **Digital Differential Analysis (`perform_dda`)**: 
   We use the DDA algorithm to step through the map grid. It compares $sideDistX$ and $sideDistY$, advancing the ray in the direction of the smaller distance, and updating it by adding $\Delta dist$. The loop continues until the ray intersects a cell designated as a wall (`1`).

4. **Distance and Projection (`calculate_wall_height`)**: 
   Once a hit is detected, the perpendicular distance to the wall is calculated to prevent the "fisheye" effect. 
   
   If the ray hit a vertical wall segment (x-side):
   $$perpWallDist = sideDistX - \Delta distX$$

   Conversely, for a horizontal wall (y-side):
   $$perpWallDist = sideDistY - \Delta distY$$
   
   This distance directly determines the height of the wall strip to be drawn on the screen:
   $$lineHeight = \frac{S\_HEIGHT}{perpWallDist}$$

## Resources

-	[From Flat to Fantastic: How cub3D’s Ray Casting Engine Transforms 2D into 3D](https://medium.com/@elmehdielgarouaz/from-flat-to-fantastic-how-cub3ds-ray-casting-engine-transforms-2d-into-3d-647ff2f7fd4f)

-	[Ray-Casting [C]](https://ismailassil.medium.com/ray-casting-c-8bfae2c2fc13)
