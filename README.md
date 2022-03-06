
# ft_printf

In this project we have to replicate the famous `printf` function of the [`stdio`](https://pubs.opengroup.org/onlinepubs/007908775/xsh/stdio.h.html) lib.

## How to browse this repository

- [`include`](./include/) - It's the `.h` file of the `ft_printf` project;

- [`libft`](./libft/) - It's my static lib functions. [Read more about it](https://github.com/lamorim42/libft);

- [`obj`](./obj/) - The folder for object files;

- [`src`](./src/) - The sorce code of this project.

## How to use `ft_printf`

This project was made without bonus, so you can use with the flags:

| Place holder | Value
| :----------: | :----
| %c | a single character
| %s | a string (end up `'\0'`)
| %p | the address of a variable
| %d or %i | a integer
| %u | unsigned integer
| %x | a number in hexadecimal (base 16) lowercase format
| %X | a number in hexadecimal (base 16) uppercase format
| %% | a percent sign

### How to put it in your project

1 - Clone this repository into your directory project

2 - In the `ft_printf/` directory compile the `ft_printf` with `make`

3 - compile your project with the flags:
```
-L ./ft_printf/ -lftprintf -I ./ft_printf/include
```

### Usage

```c
#include "ft_printf.h"

int	main(void)
{
	char str[6] = "World";

	ft_printf("Hello, %s!\n", str);
	return (0);
}
```