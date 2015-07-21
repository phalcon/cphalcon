#!/bin/bash

cd vendor/phalcon/zephir
cd parser
rm -f *.o *.lo

#Compile lemon
if [ ! -f lemon ]; then
	gcc -w lemon.c -o lemon
fi

TEST=`re2c -v`
if [ $? != 2 ]; then
	echo "error: re2c is not installed"
	exit 2
fi

re2c -o scanner.c scanner.re && ./lemon -s parser.lemon && cat base.c >> parser.c
if [ ! -f parser.c ]; then
	echo "error: re2c is not installed"
	exit 2
fi

sed s/"\#line"/"\/\/"/g scanner.c > xx && mv -f xx scanner.c
sed s/"#line"/"\/\/"/g parser.c > xx && mv -f xx parser.c
gcc -Wl,-rpath $TRAVIS_BUILD_DIR/build/lib \
	-I/usr/local/include \
	-L/usr/local/lib \
	-L/opt/local/lib \
	-I$TRAVIS_BUILD_DIR/build/include \
	-L$TRAVIS_BUILD_DIR/build/lib \
	-g3 -O0 -w parser.c scanner.c -ljson-c -o ../bin/zephir-parser

cd ..

ZEPHIRDIR="$( cd "$( dirname . )" && pwd )"
sed "s#%ZEPHIRDIR%#$ZEPHIRDIR#g" bin/zephir > bin/zephir-cmd
chmod 755 bin/zephir-cmd

if [ ! -d ~/bin ]; then
	mkdir ~/bin
fi

cp bin/zephir-cmd ~/bin/zephir
rm bin/zephir-cmd
