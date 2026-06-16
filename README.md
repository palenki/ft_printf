# ft_printf - @42sp

<p align="center">
  <img src="https://img.shields.io/badge/Status-In%20Progress-orange.svg" alt="Status" />
  <img src="https://img.shields.io/badge/Language-C-blue.svg" alt="Language" />
</p>

## 📝 About the Project
The goal of this project is to recode the `printf` function from the C standard library (`stdio.h`). 

---

## 🎯 Specifiers to be Implemented

The function will handle the following format modifiers:

| Specifier | Description |
| :---: | :--- |
| `%c` | Prints a single character. |
| `%s` | Prints a string (character sequence). |
| `%p` | Prints a pointer address in hexadecimal format. |
| `%d` | Prints a signed decimal (base 10) number. |
| `%i` | Prints a signed integer (base 10) number. |
| `%u` | Prints an unsigned decimal number. |
| `%x` | Prints a hexadecimal (base 16) number in lowercase. |
| `%X` | Prints a hexadecimal (base 16) number in uppercase. |
| `%%` | Prints a literal percent sign. |

---

## 📁 Repository Structure (Planned)

```text
ft_printf/
├── includes/          # Header files (.h)
│   └── ft_printf.h
├── srcs/              # Source code files (.c)
│   ├── ft_printf.c
│   ├── ft_putchars.c
│   ├── ft_putnbrs.c
│   └── ft_puthex.c
└── Makefile           # Compilation script
