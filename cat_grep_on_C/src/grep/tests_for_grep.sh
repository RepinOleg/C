#!bin/bash

SUCCESS=0
FAIL=0
FILE_NAME="test.txt"
DIFF_RES=""
declare -a extra=(
    "hello"
    "onE"
    "TEST"
    "World"
    "Hello"
    "h[az]"
    "f[ao]" 
    "\dschool"
)

echo "PART 2"
for var in -e -i -v -c -l -n
do
    TEST="$var for $FILE_NAME"
    echo "$TEST"
    ./s21_grep $TEST > s21_grep.txt
    grep $TEST > grep.txt
    DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
    if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
        then
            echo $TEST >> success.log
            (( SUCCESS++ ))
        else
            echo $TEST >> fail.log
            (( FAIL++ ))
    fi
    rm s21_grep.txt grep.txt
done

for var in "${extra[@]}"
do 
    TEST1="-e $var $FILE_NAME"
    echo "$TEST1"
    ./s21_grep $TEST1 > s21_grep.txt
    grep $TEST1 > grep.txt
    DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
    if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
        then
            echo $TEST1 >> success.log
            (( SUCCESS++ ))
        else
            echo $TEST1 >> fail.log
            (( FAIL++ ))
    fi
    rm s21_grep.txt grep.txt
done



echo "PART 3"
for var in -o -h -s
do
    TEST2="$var for $FILE_NAME"
    echo "$TEST2"
    ./s21_grep $TEST2 > s21_grep.txt
    grep $TEST2 > grep.txt
    DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
    if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
        then
            echo $TEST2 >> success.log
            (( SUCCESS++ ))
        else
            echo $TEST2 >> fail.log
            (( FAIL++ ))
    fi
    rm s21_grep.txt grep.txt
done

TEST3="-f pattern.txt $FILE_NAME"
echo "$TEST3"
./s21_grep $TEST3 > s21_grep.txt
grep $TEST3 > grep.txt
DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
    then
        echo $TEST3 >> success.log
            (( SUCCESS++ ))
        else
            echo $TEST3 >> fail.log
            (( FAIL++ ))
    fi
    rm s21_grep.txt grep.txt

for var in -e -i -v -c -l -n -h -s -o
do
    for var1 in -e -i -v -c -l -n -h -s -o
    do
        if [ $var != $var1 ]
        then
            for i in "${extra[@]}"
            do
                TEST4="$var $var1 $i $FILE_NAME"
                echo "$TEST4"
                ./s21_grep $TEST4 > s21_grep.txt
                grep $TEST4 > grep.txt
                DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
                if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
                    then
                        echo $TEST4 >> success.log
                        echo "success"
                            (( SUCCESS++ ))
                        else
                            echo $TEST4 >> fail.log
                            echo "fail"
                            (( FAIL++ ))
                fi
                rm s21_grep.txt grep.txt
            done
        fi
    done
done


echo "SUCCESS $SUCCESS"
echo "FAIL $FAIL"

