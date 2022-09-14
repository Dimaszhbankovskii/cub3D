#!/bin/bash

OUTFILE="tester.log"
EXE_FILE="./cub3D"
EXE="./../cub3D"

ERROR_AMOUNT_ARGS="Error: amount args in input"
ERROR_FILE_EXTENSION="Error: file extension '.cub'"
ERROR_OPEN_FILE="Error: open file"

print_header(){
	echo "" >> $OUTFILE
	echo "------------------------------------------------------------" >> $OUTFILE
	echo "-------------------------  TEST $1  -------------------------" >> $OUTFILE
	echo "------------------------------------------------------------" >> $OUTFILE
}

execute_test(){
	echo "Test: $EXE_FILE ==> $2" >> $OUTFILE
	echo "$ >> $EXE_FILE $1" >> $OUTFILE
	echo -n "Out: " >> $OUTFILE
	$EXE $1 2>> $OUTFILE
}

echo -n "" > $OUTFILE
echo "----------------------  ERROR TESTS  -----------------------" >> $OUTFILE

print_header "1"
execute_test "" "$ERROR_AMOUNT_ARGS"

print_header "2"
execute_test "map.failcub" "$ERROR_FILE_EXTENSION"
print_header "3"
execute_test "map.cubbbb" "$ERROR_FILE_EXTENSION"
print_header "4"
execute_test "map.c" "$ERROR_FILE_EXTENSION"
print_header "5"
execute_test "map" "$ERROR_FILE_EXTENSION"
print_header "6"
execute_test "map.txt" "$ERROR_FILE_EXTENSION"

print_header "7"
execute_test "maps/map_without_access.cub" "$ERROR_OPEN_FILE"

