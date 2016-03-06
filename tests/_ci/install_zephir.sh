#!/usr/bin/env bash

cd vendor/phalcon/zephir

ZEPHIRDIR="$( cd "$( dirname . )" && pwd )"
sed "s#%ZEPHIRDIR%#$ZEPHIRDIR#g" bin/zephir > bin/zephir-cmd
chmod 755 bin/zephir-cmd

if [ ! -d ~/bin ]; then
	mkdir ~/bin
fi

cp bin/zephir-cmd ~/bin/zephir
rm bin/zephir-cmd
