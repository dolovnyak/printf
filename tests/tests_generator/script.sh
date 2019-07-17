rm test
gcc tests.c libftprintf.a -o test
./test $1 $2 | awk '{ if (NR % 4 == 1) print $0 > "original_printf.txt"; if (NR % 4 == 2) print $0 > "custom_printf.txt"; if (NR % 4 == 3) print $0 > "input_string.txt"}'
diff custom_printf.txt original_printf.txt | awk '{split ($1,a,""); if (a[1] != ">" && a[1] != "<" && a[1] != "-") {print "\n"; split ($1,a,"c"); system("cat input_string.txt | sed -n " a[1] "p")} else print $0}'
rm test input_string.txt original_printf.txt custom_printf.txt
