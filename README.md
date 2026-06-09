# 2D Graphics Editor in C

## Project Overview

This project is a menu-driven 2D Graphics Editor developed in C using a 2D character array as the drawing canvas. The canvas is initially filled with the underscore (`_`) character, and graphical objects are drawn using the asterisk (`*`) character.

The application allows users to add, delete, modify, and display graphical objects such as lines, rectangles, triangles, and circles.

---

## Features

- Menu-driven interface
- 2D character array canvas
- Draw Line
- Draw Rectangle
- Draw Triangle
- Draw Circle
- Add objects to canvas
- Delete objects from canvas
- Modify existing objects
- Display the current drawing
- Object management using structures

---

## Technologies Used

- C Programming Language
- GCC Compiler
- Standard Libraries:
  - stdio.h
  - stdlib.h
  - math.h

---

## Data Structure

```c
typedef struct
{
    int id;
    int type;

    int x1, y1;
    int x2, y2;

    int width, height;
    int radius;

} Object;
```

---

## Canvas Representation

```c
#define ROWS 30
#define COLS 60

char canvas[ROWS][COLS];
```

The canvas is initialized with `_` and graphical objects are drawn using `*`.

---

## Menu Options

```text
1. Draw Line
2. Draw Rectangle
3. Draw Triangle
4. Draw Circle
5. Delete Object
6. Modify Object
7. Display Canvas
8. Show Object List
9. Exit
```

---

## Compilation

Compile the program using:

```bash
gcc graphics_editor.c -o graphics_editor -lm
```

Run the program:

```bash
./graphics_editor
```

---

## Sample Output

```text
========== 2D GRAPHICS EDITOR ==========
1. Draw Line
2. Draw Rectangle
3. Draw Triangle
4. Draw Circle
5. Delete Object
6. Modify Object
7. Display Canvas
8. Show Object List
9. Exit

Enter Choice: 2

Enter x y: 10 5
Enter width height: 8 4

Rectangle Added. ID = 1
```

---

## Project Workflow

1. Initialize the canvas with `_`.
2. Select a drawing option from the menu.
3. Enter object parameters.
4. Store object information in an array of structures.
5. Draw the object on the canvas.
6. Display, modify, or delete objects using their IDs.
7. Redraw the canvas whenever changes occur.

---

## Learning Outcomes

- Understanding 2D Arrays
- Structures in C
- Function-based Programming
- Menu-driven Application Design
- Graphics Representation Using Characters
- Object Management Techniques

---

## Future Enhancements

- ncurses-based graphical interface
- Colored drawing support
- Save and load drawings from files
- Undo/Redo functionality
- Support for diagonal lines
- Improved circle and triangle algorithms

---

## Author

**Name:** Your Name

**USN:** Your USN

**Course:** C Programming / Data Structures

**Academic Year:** 2025-26
