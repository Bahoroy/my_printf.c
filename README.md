# Welcome to My Printf
***

## Task
No problem. Unfortunately for you, this project will bring you back in the 1970s, before the existence of this book, and you will have to write your own function to greet the world

## Description
The my_printf() function produce output according to a format as described below. The my_printf() functions write output to stdout, the standard output stream; This function writes the output under the control of a format string that specifies how subsequent arguments (or arguments accessed via the variable-length argument facilities of stdarg(3)) are converted for output. The format string is composed of zero or more directives: ordinary characters (not PERCENT), which are copied unchanged to the output stream; and conversion specifications, each of which results in fetching zero or more subsequent arguments. Each conversion specification is introduced by the PERCENT character. The arguments must correspond properly (after type promotion) with the conversion specifier. After the PERCENT, the following appear in sequence: doux The int (or appropriate variant) argument is converted to signed decimal (d). unsigned octal (o), unsigned decimal (u), unsigned hexadecimal (x). c The int argument is converted to an unsigned char, and the resulting character is written. s The char * argument is expected to be a pointer to an array of character type (pointer to a string). Characters from the array are written up to (but not including) a terminating NUL character. p The void * pointer argument is printed in hexadecimal

## Installation
No install. Each conversion specification is introduced by the PERCENT character. The arguments must correspond properly (after type promotion) with the conversion specifier. After the PERCENT, the following appear in sequence.

## Usage
make
gcc -g -Wall -Wextra -Werror -o my_printf my_printf.c

./my_project argument1 argument2
```

### The Core Team


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px'></span>
#   m y _ p r i n t f . c  
 