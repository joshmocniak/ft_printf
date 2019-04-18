# ft_printf

Recreated *some* functionality of the C standard Library function printf.\
Produces output according to a format string.  Writes output to stdout, the standard output stream.

<pre>
ft_printf(&ltformat string&gt, &ltarg1&gt, &ltarg2&gt, ..., &ltargn&gt);
</pre>

The format string is composed of zero or more directives: ordinary characters (not %), which are copied unchanged to the 
output stream; and conversion specifications, each of which results in fetching zero or more subsequent arguments.  Each 
conversion specification is introduced by the % character.  The arguments must correspond properly (after type promotion) 
with the conversion specifier.  After the %, the following appear in sequence:

* Zero or more of the following flags:

	| Flags | |
	| :-| :- |
	| '#' |  The value should be converted to an 'alternate form'.  For c, d, i, p, s, and u conversions, this option has no effect.  For o conversions, the precision of the number is increased to force the first character of the output string to a zero.  For x and X conversions, a non-zero result has the string '0x' (or '0X' for X conversions) prepended to it.  For f conversions, the result will always contain a decimal point, even if no digits follow it (normally, a decimal point appears in the results of those conversions only if a digit follows). |
	| '0' (zero) | Zero padding.  For all conversions, the converted value is padded on the left with zeros rather than blanks.  If a precision is given with a numeric conversion (d, i, o, u, x, and X), the 0 flag is ignored. |
	| '-' | A negative field width flag; the converted value is to be left adjusted on the field boundary.  The converted value is padded on the right with blanks, rather than on the left with blanks or zeros.  A - overrides a 0 if both are given. |
	| ' ' (space) | A blank should be left before a positive number produced by a signed conversion (d, f, or i). |
	| '+' | A sign must always be placed before a number produced by a signed conversion.  A + overrides a space if both are used. |

* An optional decimal digit string specifying a minimum field width.  If the converted value has fewer characters than the 
field width, it will be padded with spaces on the left (or right, if the left-adjustment flag has been given) to fill out 
the field width.

* An optional precision, in the form of a period . followed by an optional digit string.  If the digit string is omitted, 
the precision is taken as zero.  This gives the minimum number of digits to appear for d, i, o, u, x, and X conversions, 
the number of digits to appear after the decimal-point for f conversions, or the maximum number of characters to be printed 
from a string for s conversions.

* An optional length modifier, that specifies the size of the argument.  

	The following length modifiers are valid for the d, i, o, u, x, or X conversion:

	| Modifier | d, i | o, u, x, X |
	| :- | :- | :- |
	| hh | signed char | unsigned char |
	| h | short | unsigned short |
	| l (ell) | long | unsigned long |
	| ll (ell ell) | long long | unsigned long long |

	The following length modifiers are valid for the f conversion:

	| Modifier | f |
	| :- | :- |
	| l (ell) | double (ignored, same behavior as without it) |
	| L | long double |

The conversion specifiers and their meanings are:

| Conversion Specifiers | |
| :- | :- |
| diouxX | The int (or appropriate variant) argument is converted to signed decimal (d and i), unsigned octal (o), unsigned decimal (u), or unsigned hexadecimal (x and X) notation.  The letters ''abcdef'' are used for x conversions; the letters ''ABCDEF'' are used for X conversions.  The precision, if any, gives the minimum number of digits that must appear; if the converted value requires fewer digits, it is padded on the left with zeros. |
| f | The double argument is rounded and converted to decimal notation in the style [-]ddd.ddd, where the number of digits after the decimal-point character is equal to the precision specification.  If the precision is missing, it is taken as 6; if the precision is explicitly zero, no decimal-point character appears.  If a decimal point appears, at least one digit appears before it. |
| c | The int argument is converted to an unsigned char, and the resulting character is written. |
| s | The char * argument is expected to be a pointer to an array of character type (pointer to a string).  Characters from the array are written up to (but not including) a terminating NUL character; if a precision is specified, no more than the number specified are written.  If a precision is given, no null character need be present; if the precision is not specified, or is greater than the size of the array, the array must contain a terminating NUL character. |
| p | The void * pointer argument is printed in hexadecimal (as if by '%#x' or '%#lx'). |
| % | A '%' is written.  No argument is converted.  The complete conversion specification is '%%'. |

In no case does a non-existent or small field width cause truncation of a numeric field; if the result
of a conversion is wider than the field width, the field is expanded to contain the conversion result.

RETURN VALUES\
Returns the number of characters printed (not including the trailing '\0' used to end
output to strings).  Returns a negative value if an error occurs.


Examples
-----

test.c
```C
#include "ft_printf.h"

int	main(void)
{
	int		*ptr;
	int		val;

	ptr = &val;
	ft_printf("%-25s%15d\n", "signed decimal:", -1234);
	ft_printf("%-25s%15u\n", "unsigned decimal:", -1234);
	ft_printf("%-25s%#15o\n", "unsigned octal:", -1234);
	ft_printf("%-25s%#15x\n", "unsigned hex:", -1234);
	ft_printf("%-25s%15f\n", "double:", -1234.1234);
	ft_printf("%-25s%15c\n", "unsigned char:", 'j');
	ft_printf("%-25s%15s\n", "string:", "hello world");
	ft_printf("%-25s%15p\n", "pointer:", (void *)ptr);
	return (0);
}
```

Output:
<pre>
signed decimal:                    -1234
unsigned decimal:             4294966062
unsigned octal:             037777775456
unsigned hex:                 0xfffffb2e
double:                     -1234.123400
unsigned char:                         j
string:                      hello world
pointer:                  0x7ffeea57b95c
</pre>
