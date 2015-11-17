#!/bin/bash
make all

fileImput=$1

if [ -z "$1" ]
then
    echo "No argument supplied";
    exit;
fi

echo "Sin -O3";
original=$(./original.out $fileImput original.txt);
echo "Orignal: "$original;

mejorado=$(./mejorado.out $fileImput mejorado.txt);
echo "Mejorado: "$mejorado;

rm original.txt mejorado.txt

echo "Con -O3";

original=$(./originalO3.out $fileImput original.txt);
echo "Orignal: "$original;

mejorado=$(./mejoradoO3.out $fileImput mejorado.txt);
echo "Mejorado: "$mejorado;

rm original.txt mejorado.txt

make clean
