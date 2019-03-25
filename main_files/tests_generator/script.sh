./a.out $1 $2 | awk '{ if (NR % 4 == 1) print $0 > "original_printf"; if (NR % 4 == 2) print $0 > "custom_printf"; if (NR % 4 == 3) print $0 > "input_string"}'
diff custom_printf original_printf | awk '{split ($1,a,""); if (a[1] != ">" && a[1] != "<" && a[1] != "-") {print "\n"; split ($1,a,"c"); system("cat input_string | sed -n " a[1] "p")} else print $0}'
