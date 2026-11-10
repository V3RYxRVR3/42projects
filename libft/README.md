*This project has been created as part of the 42 curriculum by sofdomin.*

# Libft

## Description

**Libft** is the first project of the 42 curriculum. The goal is to build, from scratch, our own C library containing a set of general-purpose functions that reimplement part of the standard C library (`libc`), plus additional utility functions for string manipulation, memory handling, file descriptor output and linked lists.

This library will be reused in all the following 42 projects, so it is designed to be reliable, norm-compliant and free of memory leaks. The project is also an opportunity to understand how the standard functions work internally, how memory is managed in C, and how to build and distribute a static library with `make` and `ar`.

### Library overview

The library is compiled into a static archive, `libft.a`, and is split into three parts.

#### Part 1 — Libc functions

Reimplementations of standard functions, with the same prototypes and behavior as the originals (except the `ft_` prefix).

| Character checks | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint` |
| Character conversion | `ft_toupper`, `ft_tolower` |
| String functions | `ft_strlen`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strlcpy`, `ft_strlcat`, `ft_strdup` |
| Memory functions | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc` |
| Conversion | `ft_atoi` |

#### Part 2 — Additional functions

Functions that are not in `libc`, or that are part of it in a different form.

| `ft_substr` | Allocates and returns a substring of a string. |
| `ft_strjoin` | Allocates and returns the concatenation of two strings. |
| `ft_strtrim` | Trims the given set of characters from the start and end of a string. |
| `ft_split` | Splits a string into an array of strings using a delimiter character. |
| `ft_itoa` | Converts an integer to a string. |
| `ft_strmapi` | Applies a function to each character (with its index), creating a new string. |
| `ft_striteri` | Applies a function to each character (with its index) in place. |
| `ft_putchar_fd` | Writes a character to a file descriptor. |
| `ft_putstr_fd` | Writes a string to a file descriptor. |
| `ft_putendl_fd` | Writes a string followed by a newline to a file descriptor. |
| `ft_putnbr_fd` | Writes an integer to a file descriptor. |

#### Bonus part — Linked lists

Functions to manipulate linked lists using the following structure:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

| `ft_lstnew` | Creates a new node. |
| `ft_lstadd_front` | Adds a node at the beginning of the list. |
| `ft_lstsize` | Counts the nodes of the list. |
| `ft_lstlast` | Returns the last node of the list. |
| `ft_lstadd_back` | Adds a node at the end of the list. |
| `ft_lstdelone` | Frees the content of a node and the node itself. |
| `ft_lstclear` | Deletes and frees a node and all the following ones. |
| `ft_lstiter` | Applies a function to the content of each node. |
| `ft_lstmap` | Creates a new list by applying a function to each node's content. |

## Instructions

### Requirements

- A C compiler (`cc`/`gcc`/`clang`)
- `make`
- `ar`

### Compilation

At the root of the repository:

```bash
make          # compiles the mandatory part and creates libft.a
make bonus    # also compiles the linked list functions (bonus)
make clean    # removes the object files
make fclean   # removes the object files and libft.a
make re       # fclean + make
```

The code is compiled with the flags `-Wall -Wextra -Werror`.

### Usage

Include the header in your source files:

```c
#include "libft.h"
```

Then compile your program and link it with the library:

```bash
cc -Wall -Wextra -Werror main.c -L. -lft -o my_program
```

or, equivalently:

```bash
cc -Wall -Wextra -Werror main.c libft.a -o my_program
```

### Example

```c
#include "libft.h"

int	main(void)
{
	char	**words;
	int		i;

	words = ft_split("hello 42 world", ' ');
	i = 0;
	while (words[i])
	{
		ft_putendl_fd(words[i], 1);
		free(words[i]);
		i++;
	}
	free(words);
	return (0);
}
```

## Resources

### References

- [`man` pages](https://man7.org/linux/man-pages/) — `string(3)`, `memory(3)`, `ctype.h(0p)`, `malloc(3)`, `ar(1)`
- [GNU Make Manual](https://www.gnu.org/software/make/manual/make.html)
- [Static libraries with `ar`](https://tldp.org/HOWTO/Program-Library-HOWTO/static-libraries.html)
- [42 Norm](https://github.com/42School/norminette)

### Use of AI

AI was used as a support tool, not to write the project code. Specifically:

- **README:** generating the structure and the first draft of this file.
- **Understanding concepts:** clarifying doubts about the behavior of standard functions (e.g. `memmove` with overlapping memory, `strlcat` return value) and about `Makefile` rules.
- **Testing ideas:** suggesting edge cases to test the functions.

All the library code was written, tested and understood by the author.