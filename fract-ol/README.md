*This project has been created as part of the 42 curriculum by mcarapie.*

# Fract-ol

## Description

Fract-ol is a small fractal exploration program written in C with the MiniLibX
graphics library. It renders mathematical fractals in a window and lets the user
zoom into the image with the mouse wheel.

The mandatory part of the project supports:

- Mandelbrot set rendering
- Julia set rendering
- Different Julia sets through command-line parameters
- Color gradients based on iteration depth
- Clean window handling with ESC and the window close button

## Instructions

Compile the project:

```sh
make
```

Run the Mandelbrot set:

```sh
./fractol mandelbrot
```

Run a Julia set by passing the real and imaginary values for the constant:

```sh
./fractol julia <real> <imag>
```

Useful Julia examples:

```sh
./fractol julia -0.79 0.15
./fractol julia -0.8 0.156
./fractol julia 0.285 0.01
./fractol julia 0.355 0.355
./fractol julia -0.70176 -0.3842
./fractol julia -0.4 0.6
```

Controls:

- Mouse wheel up: zoom in
- Mouse wheel down: zoom out
- ESC: close the program
- Window close button: close the program

Clean object files:

```sh
make clean
```

Remove object files and the executable:

```sh
make fclean
```

Rebuild the project:

```sh
make re
```

Build with debug flags:

```sh
make debug
```

## Resources

- [Fract-ol Canva notes](https://www.canva.com/design/DAGT6G8aJHY/fqork5u1hxZONk8a4WQtdQ/view)
- [Fract-ol video reference](https://www.youtube.com/watch?v=ANLW1zYbLcs)
- [Understanding `mlx_init` in MiniLibX](https://medium.com/@ahmadbilla07/understanding-mlx-init-in-minilibx-beginner-friendly-7272b7ac9181)
- [Understanding Julia and Mandelbrot Sets](https://www.karlsims.com/julia.html)

AI was used to review the project against the subject requirements, identify
README compliance issues, suggest manual test cases, and check small code risks
such as event callback signatures and cleanup behavior.
