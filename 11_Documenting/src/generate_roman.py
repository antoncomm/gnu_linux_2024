#!/usr/bin/env python3

## @package generate_table
# Generate table of roman numbers from 0 to 100

import roman

print("const char* roman_table[101] = {", end='')
for num in range(101):
    print('"', end='')
    print(roman.toRoman(num), end='')
    print('"', end='')
    if num != 100:
         print(", ", end='')
 
print("};")
