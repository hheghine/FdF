# FdF

**FdF** is a simple 3D height-map renderer project. It enables the rendering of models, where the color of each point is determined by its relative height within the map. The project includes features like model rotation, camera control for zoom and translation, as well as support for color gradients.

![photo_2023-08-29_03-30-19](https://github.com/cosmo-octopus/FdF/assets/119530584/13685ab7-55e8-4409-b59a-47859c1752b0)

## Features

### Current Features

- Simple file format definition using an array of space-separated integers.
- 3D rotations achievable with the mouse.
- Camera controls, including zoom and translation.
- Utilization of pretty color gradients.
- Double-buffering for smooth rendering.
- Line clipping for improved visual quality.

## Compiling and Running

1. Compile the executable by running `make`. The resulting executable will be generated.
2. Run the program using `./fdf [map]`, where `[map]` should be replaced with the path to the map file you wish to visualize.
3. A set of sample maps can be found in the `test_maps` directory. Notably, `test_maps/42.fdf` is a popular choice for testing.

## Conclusion

**FdF** is a straightforward 3D height-map renderer that allows users to visualize and interact with models. It offers rotation, camera control, color gradients, and various planned features to enhance the experience further. By compiling and running the program, you can explore the provided sample maps and create your own height-map visualizations.
