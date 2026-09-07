# Conway's Game of Life

An academic C++ console implementation of Conway's Game of Life on a randomly initialized 20×20 grid.

[![C++](https://img.shields.io/badge/language-C%2B%2B-00599C?style=flat-square)](#technology-stack)
[![Console Application](https://img.shields.io/badge/type-console%20application-444444?style=flat-square)](#overview)
[![Academic Project](https://img.shields.io/badge/category-academic%20project-6A5ACD?style=flat-square)](#academic-context)
[![Windows](https://img.shields.io/badge/platform-Windows-0078D6?style=flat-square)](#running-the-program)
[![Year | 2021](https://img.shields.io/badge/year-2021-555555?style=flat-square)](#academic-context)

> [!NOTE]
> This repository contains an academic project originally developed during earlier programming studies. It is preserved as a record of the technical knowledge, design decisions and development experience acquired at the time.

## Academic context

The source file identifies the work as a “Compito di Natale 2021-2022” and names the author and class, providing dated evidence that the project was developed as a school exercise. The original development period represented in the repository is **2021**.

## Overview

The program models Conway's Game of Life as a 20×20 boolean grid. It creates a random initial population, renders the grid and generation counters in a Windows console, then repeatedly computes generations using the standard neighbor-count rules for live and dead cells.

The simulation is observation-only: after the initial setup, the program does not request gameplay input. It stops when the population reaches zero, the generation counter reaches 300, or the implementation detects an unchanged generation.

## Features

- Randomly initializes live cells on a 20×20 grid.
- Applies Conway-style birth, survival and death rules based on adjacent cells.
- Displays the grid, generation number and live-cell count in a formatted console view.
- Uses console colors, cursor positioning and a pause-based menu to present the simulation.
- Terminates on the implemented empty-population, unchanged-generation or generation-300 conditions.

## Technology stack

- **Language:** C++
- **Console API:** Windows Console API via `windows.h`
- **Build project:** Code::Blocks project using the GCC compiler configuration
- **Runtime dependencies:** C++ standard input/output, Windows console functions, POSIX-style `unistd.h` declarations and time-based random seeding

## Project structure

```text
.
├── main.cpp                         # Application source and entry point
├── esercizio_natale.cbp             # Code::Blocks project configuration
├── Relazione_programma_natale_Ulivi.pdf
│                                     # Project report
├── bin/Debug/esercizio_natale.exe   # Checked-in Windows debug executable
└── obj/Debug/main.o                 # Checked-in debug object file
```

## Prerequisites

- A Windows environment with a C++ compiler that provides the headers and APIs used by the program, including `windows.h`.
- Code::Blocks can open `esercizio_natale.cbp`; the project configuration selects GCC and defines Debug and Release targets.

The repository does not include a package manifest, dependency lockfile, automated test suite or CI workflow.

## Building

Open `esercizio_natale.cbp` in Code::Blocks and select one of the configured targets:

- **Debug:** outputs `bin/Debug/esercizio_natale`
- **Release:** outputs `bin/Release/esercizio_natale`

The project configuration enables `-Wall` and `-fexceptions`; the Release target additionally enables `-O2` and strips symbols with `-s`.

## Running the program

After building on Windows, run the generated executable from a console. The checked-in Debug artifact is also located at `bin/Debug/esercizio_natale.exe`.

The program first displays the title, an empty grid and an informational menu. It then generates the initial population and advances generations automatically until one of the implemented stopping conditions is reached.

## Limitations

- The implementation is Windows-specific because it uses the Windows Console API, Windows console handles and `system("CLS")`/`system("PAUSE")`.
- The source is a historical educational exercise rather than a production-ready application.
- No automated tests or reproducible command-line build script are provided in the repository.

## License

No license file or explicit license declaration is included in the repository. Licensing therefore requires human review.
