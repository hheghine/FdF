# FdF

**FdF** is a simple 3D height-map renderer project. It enables the rendering of models, where the color of each point is determined by its relative height within the map. The project includes features like model rotation, camera control for zoom and translation, as well as support for color gradients.

![Screenshot from 2023-09-16 05-32-03](https://github.com/hheghine/FdF/assets/119530584/c6394ce5-9848-40a7-9e35-50a68dffe7ba)



## Features

### Current Features

- Simple file format definition using an array of space-separated integers.
- transitions `keys: ↑/↓/←/→`
- zoom `keys: +/-/W/S`
- 3D rotations `keys: A/D`
- Utilization of pretty color gradients, color change `key: C`.

### Compatibility

- MacOs
- Linux

## Compiling and Running

1. Compile the executable by running `make`. The resulting executable will be generated.
2. Run the program using `./fdf [map]`, where `[map]` should be replaced with the path to the map file you wish to visualize.
3. A set of sample maps can be found in the `maps` directory. Notably, `maps/42.fdf` is a popular choice for testing.

## Conclusion

**FdF** is a straightforward 3D height-map renderer that allows users to visualize and interact with models. It offers rotation, camera control, color gradients, and various planned features to enhance the experience further. By compiling and running the program, you can explore the provided sample maps and create your own height-map visualizations.

![Screenshot from 2023-09-16 05-45-08](https://github.com/hheghine/FdF/assets/119530584/b139951b-70fc-4487-9683-94fdacb403ae)

![Screenshot from 2023-09-16 05-36-36](https://github.com/hheghine/FdF/assets/119530584/e3abf443-22b4-4908-b10a-da46309aacf5)

![Screenshot from 2023-09-16 05-49-15](https://github.com/hheghine/FdF/assets/119530584/ce0a7c85-d1a4-453a-8c76-d9c307e07e56)


