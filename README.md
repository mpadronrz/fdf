# 🗺️ FdF — 3D Wireframe Viewer

![C](https://img.shields.io/badge/Language-C-blue) ![42 Project](https://img.shields.io/badge/42%20Project-FdF-orange) ![MiniLibX](https://img.shields.io/badge/MiniLibX-graphics-lightgrey) ![Grade](https://img.shields.io/badge/Grade-125%2F100-brightgreen)

**FdF** is a 42 School project that renders a 3D wireframe representation of a landscape from a map file (`.fdf`).
It was completed and peer-graded at **42Barcelona**, receiving a grade of **125/100**.

The project uses **MiniLibX** for graphics and handles **3D projection, translation, rotation, zooming, and color effects**.

---
## 📑 Table of Contents
- [About the Project](#about-the-project)
- [Features](#features)
- [Compilation](#compilation)
- [Execution](#execution)
- [Controls](#controls)
- [.fdf File Format](#fdf-file-format)
- [How It Works](#how-it-works)

---

### 🏫 About the Project

**FdF** is part of the **42 curriculum**, introducing 3D graphics and coordinate manipulation in C.
It reinforces key programming and mathematical concepts:

* Trigonometry and linear algebra for 3D projections
* Event-driven programming
* Clean and modular code design
* Graphics rendering algorithms

> Peer-graded at **42Barcelona** with a final grade of **125/100**.

---

### 🚀 Features

* Render 3D wireframes from `.fdf` map files
* Isometric and parallel projections
* Smooth translation, rotation, zoom, and Z-axis scaling
* Color filters for red, green, and blue channels
* Tilt/plane inclination effect for dynamic 3D visualization

---

### ⚙️ Compilation

All required libraries (**MiniLibX** and **Libft**) are included in the repository.

To compile, simply run:

```bash
make
```

Compilation flags used (Linux / WSL):

```bash
-lXext -lX11 -lm -lbsd -lz
```

> You may need to install these system libraries for MiniLibX to work on Linux/WSL.

To clean or rebuild:

```bash
make clean
make fclean
make re
```

---

### 🕹️ Execution

```bash
./fdf test_maps/42.fdf
```

You can use your own `.fdf` map or one from the provided `test_maps/` folder.

> The default window size is **1920x1080**. You can change it by editing the `WIDTH` and `HEIGHT` macros in `fdf.h`.

---

### 🎮 Controls

| Key             | Action                                                                                    |
| --------------- | ----------------------------------------------------------------------------------------- |
| `ESC`           | ❌ Close window / exit program                                                             |
| `←` / `→`       | ↔ Translate map along Y-axis                                                              |
| `↑` / `↓`       | ↕ Translate map along X-axis                                                              |
| `Z` / `X`       | ⬆️⬇️ Translate map along Z-axis (height)                                                  |
| `A` / `D`       | 🔄 Rotate around Z-axis                                                                   |
| `W` / `S`       | 🌀 Tilt / incline XY plane (creates dynamic 3D effect)                                    |
| `N` / `M`       | ↕ Adjust Z-axis scale (stretch/compress height)                                           |
| `+` / `-`       | 🔍 Zoom in / out                                                                          |
| `I`             | 🖼 Switch to isometric projection                                                         |
| `P`             | 🖼 Switch to parallel projection                                                          |
| `R` / `G` / `B` | 🎨 Adjust color intensity of Red / Green / Blue |

**Notes:**

* Key mappings are optimized for **Spanish keyboards**; they may vary on other layouts.

---

### 🗂️ `.fdf` File Format

* Only **rectangular maps** are accepted (same number of elements per line).
* Each number represents the altitude (Z-value) of a point.
* Optional colors can be added immediately after the number (no spaces):

```
<number>,0xRRGGBB
```

* Example line:

```
0 1 2 3,0xFF0000 4 5,0x00FF00
```

This represents a row of points, some with custom colors in hexadecimal.

---

### 🧠 How it works

* Reads the `.fdf` file and stores points with altitudes and optional colors.
* Uses **linear algebra and trigonometry** to calculate 3D positions and projection coordinates.
* Draws lines between points using **Bresenham’s line algorithm**.
* Handles real-time transformations (translation, rotation, zoom, tilt) and color adjustments.
