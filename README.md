# printf
## MacOS - [![Build Status](https://www.travis-ci.com/dolovnyak/printf.svg?branch=master)](https://www.travis-ci.com/dolovnyak/printf)
###
Copies most of the original printf behavior.
---------
Build and run on `MacOS`
---------
```
//your main.c file:

#include "ft_printf.h"

int main()
{
  ft_printf("%d LIKE A BOSS %d\n", 1337, 1337);
}

//end of your main.c file


make -C ${PATH_TO_LIB_FOLDER}
gcc ${PATH_TO_LIB_FOLDER}/libftprintf.a -I ${PATH_TO_LIB_FOLDER}/includes main.c
./a.out
```
Flags:
---------
- `#`
- `SPACE`
- `0`
- `-`
- `+`
###
### Has WIDTH implementation
###
### Has PRICISION implementation
###
Modifiers:
--------
- `hh`
- `h`	
- `l`	
- `ll`	
- `j`	
- `z`	
- `L`
###
Types:
--------
- char - `%c`
- string - `%s`
- pointer - `%p`
- int - `%d`, `%i`
- int in octal system - `%o`
- unsigned int - `%u`
- int in hexadecimal system, upper/lower case -  `%x`, `%X`.
- double - `%f`, `%F`
- additional type print int in binary - `%b`
###
Remarks:
---------
- On all types except fractional numbers ft_printf wotk or faster or slower within 10 percent.
- Fractional numbers implemented with long arithmetics.
- There are custom tests for a lot of strange and undefind behavior.
- There are generated tests for types diouxXf, that randomize flags, precision, width, modifier and type for both original and ft_printf and compares output.
