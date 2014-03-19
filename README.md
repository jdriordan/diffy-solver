diffy-solver
=====

All this program does is solve a differential equation over a 1-D `C` array, and then animate the results using `matplotlib` via `python`. Included (via comments) are first and second order central finite difference methods, and some initial conditions. It has a simple wave equation with constant boundary conditions hardcoded.

Usage
-----
Twiddle with the C program as appropriate and compile with:

    gcc -Wall -O2 -std=c99 -lm reaction.c

and run with simply `$ ./main.sh`.
