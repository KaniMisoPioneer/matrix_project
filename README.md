# Matrix Library

C library for matrix operations with support for basic linear algebra functions.

## Build Instructions

### Compiling the Library
```bash
make all
```
Generates static library `build/matrix.a`.

### Execute Main Program
```bash
make main
```
Compiles and executes demonstration program from `main.c`.

### Run Test Suite
```bash
make test
```
Executes unit tests using CUnit framework.

### Memory Validation
```bash
make valgrind
```
Runs test suite with Valgrind memory analysis.

---

## Development Environment

### Core Dependencies
- **Compiler**: GCC 11+ (C11 standard support)
- **Mathematics**: Standard math library (`-lm`)

### Optional Tooling
| Tool          | Purpose                          |
|---------------|----------------------------------|
| CUnit         | Unit testing framework           |
| Valgrind      | Memory leak detection            |
| Doxygen       | Documentation generation         |
| cppcheck      | Static code analysis             |
| clang-format  | Code style validation            |

---

## Makefile Reference

| Target        | Description                                  |
|---------------|---------------------------------------------|
| `all`         | Build static library (default)              |
| `main`        | Compile and execute demonstration program   |
| `test`        | Run comprehensive unit tests                |
| `valgrind`    | Validate memory usage with test suite       |
| `cppcheck`    | Perform static code analysis                |
| `docs`        | Generate API documentation                  |
| `clean`       | Remove all build artifacts                 |

---

## API Documentation

### Matrix Structure
```c
typedef struct {
    size_t rows;     // Number of rows
    size_t cols;     // Number of columns
    MATRIX_TYPE** data;  // 2D array of elements
} Matrix;
```
Configure data type via `config.h`.

---

### Core Matrix Operations

| Function              | Description                                  |
|-----------------------|----------------------------------------------|
| `create_matrix`       | Allocate matrix with specified dimensions    |
| `free_matrix`         | Release matrix resources                     |
| `copy_matrix`         | Create deep copy of matrix                   |
| `isCorrectMatrix`     | Validate matrix integrity                    |
| `isSizeEqual`         | Compare dimensions of two matrices          |

### Algebraic Operations

| Function              | Description                                  |
|-----------------------|----------------------------------------------|
| `sum_matrices`        | Element-wise addition                       |
| `sub_matrices`        | Element-wise subtraction                    |
| `multiply_matrices`   | Matrix multiplication                       |
| `transpose_matrix`    | Create transposed matrix                    |
| `determinant`         | Calculate matrix determinant                |
| `getMinorMatrix`      | Compute minor matrix                        |

---

### I/O Operations

| Function              | Description                                  |
|-----------------------|----------------------------------------------|
| `load_matrix_from_file` | Initialize matrix from text file           |
| `save_matrix_to_file`  | Persist matrix to disk                     |
| `print_matrix`         | Console output with default formatting     |

### Custom Formatting

| Function              | Description                                  |
|-----------------------|----------------------------------------------|
| `export_matrix`       | Write matrix with custom renderer           |
| `rounded_print`       | Integer-rounded element display            |
| `default_print`       | Standard floating-point format             |

---

Full implementation details available in corresponding header files.