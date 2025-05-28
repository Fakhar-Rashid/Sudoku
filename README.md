# 🧩 Sudoku Game (C++ Console Application)

[![C++](https://img.shields.io/badge/C%2B%2B-17-blue)](https://en.cppreference.com/w/cpp/17)
[![Build](https://img.shields.io/badge/build-passing-brightgreen)]()
[![Platform](https://img.shields.io/badge/platform-Windows%20%7C%20Linux-lightgrey)]()

A fully-functional **Sudoku game** built from scratch in **modern C++**. This is a single-file console app that allows users to:

- Play randomly generated Sudoku puzzles
- Save and resume up to **3 different games**
- Experience a clean and responsive console UI

---

## 🖼️ Preview

### Home Page
![Home Page](https://github.com/user-attachments/assets/4c4b1ac3-d223-404e-b6ee-1c82c7b2d81e)

### Sudoku Gameplay
![Gameplay](https://github.com/user-attachments/assets/095cdc3e-7a77-4308-bf9f-698545260aca)

---

## 🚀 Features

- 🔄 **Auto-Generated Puzzles** – Unique, solvable Sudoku boards every time you start a new game.
- 💾 **Game Saving** – Store up to 3 games with the ability to resume later.
- ⌨️ **Console-Based Input** – Lightweight and fast, with intuitive controls.
- 🧠 **Solver Logic** – Ensures each puzzle is valid using backtracking.

---

## 📦 How to Run

### 🧭 Option 1: Quick Start via VS Code

> 💡 Recommended for most users

1. Clone this repository:
    ```bash
    git clone https://github.com/Fakhar-Rashid/Sudoku.git
    cd Sudoku
    ```

2. Open the folder in **Visual Studio Code**.
3. Run `game.cpp` using the Run button or `Ctrl + Alt + N` (if you have **Code Runner** installed).

---

### 🧭 Option 2: Manual Setup (New Project)

> If you're starting fresh

1. Open VS Code
2. Create a new empty C++ project
3. Copy the contents of `game.cpp` from this repo
4. Paste into your new project and run it

---

## 🛠️ Built With

- **Language:** C++17
- **Compiler:** g++, MSVC, or any modern C++ compiler
- **IDE:** VS Code (recommended)
- **Techniques:** OOP, File I/O, Random Generation, Backtracking

---

## 🗂️ File Structure

```bash
/FINANL_SUDOKU/
├── game.cpp         # Main game file
├── .vscode/         # Optional VS Code tasks/debug configs
├── .gitignore
└── README.md
