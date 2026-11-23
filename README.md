
# C Text Decryption Algorithm

A C programming project that implements a custom text decryption algorithm to recover encoded names using a 5×5 alphabet matrix, coordinate transformations, and character manipulation.

## Description

This program decrypts a predefined list of encoded names through a combination of operations:

1. **Custom Alphabet Matrix:** Uses a 5×5 matrix containing a rearranged alphabet.
2. **Word Reversal:** Reverses the characters of each word.
3. **Coordinate Transformation:** Applies row and column movements to locate the decrypted characters in the matrix.
4. **Cyclic Movement:** Uses modular arithmetic to keep matrix coordinates within valid boundaries.
5. **Case Preservation:** Maintains the original uppercase and lowercase formatting.
6. **Space Handling:** Changes the transformation sequence when encountering spaces.

## Technologies Used

- C Programming Language
- Standard Input/Output (`stdio.h`)
- Character Handling (`ctype.h`)
- String Manipulation (`string.h`)
- Arrays and Matrices
- Pointers and Functions
- Loops and Conditional Statements
- Modular Arithmetic

## Algorithm Overview

The decryption process follows these steps:

1. Read each encoded name from the predefined array.
2. Divide the text into individual words.
3. Reverse each word.
4. Locate each character in the custom 5×5 alphabet matrix.
5. Apply the inverse row and column transformations.
6. Preserve the original character case.
7. Print the decrypted names.

## Key Programming Concepts

| Concept | Application |
|---|---|
| 2D Arrays | Representing the custom alphabet matrix |
| 1D Arrays | Storing row and column movements |
| Strings | Managing encoded names |
| Pointers | Modifying strings through functions |
| Functions | Organizing the decryption logic |
| While Loops | Processing words and characters |
| For Loops | Searching the alphabet matrix |
| Modulus (`%`) | Wrapping matrix coordinates |
| Character Functions | Handling uppercase and lowercase letters |

## How to Compile and Run

### 1. Compile

```bash
gcc main.c -o decrypt
```

### 2. Run

**Windows:**
```bash
decrypt.exe
```

**Linux / macOS:**
```bash
./decrypt
```

## Project Structure

```text
C-Text-Decryption/
│
├── main.c
└── README.md
```

## Author

**Achraf Djelid**

---

*This project demonstrates practical applications of arrays, strings, matrix operations, modular arithmetic, and character manipulation in C.*
