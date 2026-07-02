# Sudokuish (C-UDOKU)

A terminal-based Sudoku implementation in C, built as an early school project. The board size and symbol set are configurable, and the game enforces standard Sudoku row/column/box constraints.

## Features

- Configurable board size, empty-cell character, and symbol type, loaded from `options.txt`
- Random initial board fill respecting Sudoku constraints (row, column, and grid/box checks)
- Text-based board rendering with coordinate headers (e.g. `4b`) for selecting a tile
- Win detection (board fully filled)

## Status

This was written early on while learning C, and it shows: `loadGameMain()` and `saveGameMain()` are unimplemented stubs, the settings menu has a formatting bug, and there's no persistence of game state between sessions beyond `options.txt`. It's kept here as-is rather than polished up after the fact.

## Project structure

- `main.c` - entry point, launches the main menu
- `menu.c` / `menu.h` - menu screens (main menu, credits, settings)
- `sudoku.c` / `sudoku.h` - game state (`config` struct), board allocation, constraint checks, rendering
- `options.txt` - board configuration read at startup (size, empty-cell character, symbol type)
- `CMakeLists.txt` - CMake build definition

## Requirements

- A C99 compiler (e.g. GCC or Clang)
- CMake 3.17+

## Building

```bash
mkdir build && cd build
cmake ..
cmake --build .
```

This produces the `Sudokuish` executable.

## Author

Bruno Freitas ([@viribusegovis](https://github.com/viribusegovis)).
