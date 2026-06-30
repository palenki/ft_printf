*This project has been created as part of the 42 curriculum by pauhenr2.*

# ft_printf

## Description

**ft_printf** is a reimplementation of the C Standard Library `printf` function. The goal of this project is to understand how formatted output works internally while gaining practical experience with variadic functions, parsing, modular programming, and formatted string processing.

The mandatory part reproduces the behavior of `printf` for the required conversion specifiers, while the bonus extends the implementation with support for formatting flags.

This project was developed in C following the constraints of the 42 curriculum, with particular attention to modularity, code readability, and maintainability.

---

## Features

### Mandatory

The following conversion specifiers are supported:

* `%c` — character
* `%s` — string
* `%p` — pointer address
* `%d` — signed decimal integer
* `%i` — signed integer
* `%u` — unsigned decimal integer
* `%x` — hexadecimal (lowercase)
* `%X` — hexadecimal (uppercase)
* `%%` — percent sign

### Bonus

The bonus implementation supports the following formatting flags:

* `-` (left alignment)
* `0` (zero padding)
* Precision (only for %s)

---

## Project Structure

```
.
├── includes/
│   ├── ft_printf.h
│   └── ft_printf_bonus.h
├── srcs/
│   ├── ft_printf.c
│   ├── ft_printf_text.c
│   └── ft_printf_numbers.c
├── srcs_bonus/
│   ├── ft_printf_bonus.c
│   ├── ft_printf_text_bonus.c
│   ├── ft_printf_numbers_bonus.c
│   ├── ft_printf_length_bonus.c
│   └── ft_printf_handles_bonus.c
├── Makefile
└── README.md
```

The project contains two independent implementations:

* **Mandatory**, compiled with `make`
* **Bonus**, compiled with `make bonus`

This separation allows both versions to evolve independently while preserving a fully functional mandatory implementation.

---

## Algorithm & Data Structures

The implementation processes the format string sequentially, printing ordinary characters directly and handling format specifiers whenever a `%` character is encountered.

The overall workflow is:

1. Read the format string one character at a time.
2. Print regular characters immediately.
3. When `%` is found, parse the conversion specification.
4. (Bonus) Parse formatting flags, width, and precision.
5. Store formatting information inside a dedicated `t_format` structure.
6. Dispatch the conversion to the appropriate handler function.
7. Print the formatted output while keeping track of the total number of printed characters.

### Design Choices

The project is organized into multiple source files according to their responsibilities:

* Parsing
* Text conversions
* Numeric conversions
* Conversion handlers
* Utility functions

For the bonus implementation, all formatting information is stored inside a `t_format` structure. This approach centralizes the parsing logic, reduces the number of function parameters, and keeps conversion handlers focused only on formatting and printing their respective data types.

This modular design makes the implementation easier to debug, extend, and maintain.

---

## Instructions

### Compile the mandatory version

```bash
make
```

This generates:

```
libftprintf.a
```

### Compile the bonus version

```bash
make bonus
```

This rebuilds the library using the bonus implementation.

### Clean object files

```bash
make clean
```

### Remove all generated files

```bash
make fclean
```

### Rebuild the project

```bash
make re
```

---

## Example

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s!\n", "42");
    ft_printf("Value: %08d\n", 42);
    return (0);
}
```

---

## Resources

Official documentation:

* C Standard Library
* `man 3 printf`
* `man stdarg`
* https://man7.org/linux/man-pages/man3/printf.3.html
* https://en.cppreference.com/w/c/io/fprintf
* https://pubs.opengroup.org/onlinepubs/9699919799/

These references were used to understand the expected behavior of conversion specifiers, formatting flags, variadic functions, and edge cases.

---

## AI Usage

Artificial Intelligence was used as a learning assistant throughout the development of this project.

Its usage included:

* clarifying the expected behavior of specific conversion specifiers and formatting flags;
* explaining edge cases and undefined behavior of the original `printf`;
* discussing implementation strategies and design decisions;
* reviewing the project organization and Makefile;
* providing feedback on code readability and modularization.

All algorithms, implementation decisions, debugging, testing, and final code were written, validated, and integrated by me.

