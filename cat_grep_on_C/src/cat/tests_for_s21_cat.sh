#!bin/bash

SUCCESS=0
FAIL=0
FILE_NAME="test.txt"
DIFF_RES=""

for var in -b -e -n -s -t -v #-E -T --number-nonblank --number --squeeze-blank
do
    TEST="$var $FILE_NAME"
    echo "$TEST"
    ./s21_cat $TEST > s21_cat.txt
    cat $TEST > cat.txt
    DIFF_RES="$(diff -s s21_cat.txt cat.txt)"
    if [ "$DIFF_RES" == "Files s21_cat.txt and cat.txt are identical" ]
        then
            echo "$TEST" >> success.log
            (( SUCCESS++ ))
        else
            echo "$TEST" >> fail.log
            (( FAIL++ ))
    fi
    rm s21_cat.txt cat.txt
done

FILE_NAME=test1.txt
for var in -b -e -n -s -t -v #-E -T --number-nonblank --number --squeeze-blank
do
    TEST1="$var $FILE_NAME"
    echo "$TEST1"
    ./s21_cat $TEST1 > s21_cat.txt
    cat $TEST1 > cat.txt
    DIFF_RES="$(diff -s s21_cat.txt cat.txt)"
    if [ "$DIFF_RES" == "Files s21_cat.txt and cat.txt are identical" ]
        then
            echo "$TEST1" >> success.log
            (( SUCCESS++ ))
        else
            echo "$TEST1" >> fail.log
            (( FAIL++ ))
    fi
    rm s21_cat.txt cat.txt
done

echo "SUCCESS $SUCCESS"
echo "FAIL $FAIL"
