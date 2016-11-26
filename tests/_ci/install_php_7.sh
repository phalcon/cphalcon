#!/usr/bin/env bash

if [ -z $TRAVIS_BUILD_DIR ]; then
	TRAVIS_BUILD_DIR=$(readlink -enq $(dirname $0))
fi

install_igbinary() {
	git clone https://github.com/igbinary/igbinary7.git /tmp/igbinary
	cd /tmp/igbinary

	$PHPIZE_BIN &> /dev/null
	./configure CFLAGS="-O2 -g" --silent --enable-phalcon &> /dev/null

	make --silent -j4 &> /dev/null
	make --silent install

	if [ -z $(php -m | grep igbinary) ]; then
        phpenv config-add "${TRAVIS_BUILD_DIR}/tests/_ci/igbinary.ini"
    fi
}

install_apcu() {
	# See https://github.com/krakjoe/apcu/issues/203
	git clone -q https://github.com/krakjoe/apcu -b v5.1.7 /tmp/apcu
	cd /tmp/apcu

	$PHPIZE_BIN &> /dev/null
	./configure &> /dev/null

	make --silent -j4 &> /dev/null
	make --silent install
}

install_apcu_bc() {
	git clone -q https://github.com/krakjoe/apcu-bc /tmp/apcu-bc
	cd /tmp/apcu-bc

	$PHPIZE_BIN &> /dev/null
	./configure &> /dev/null

	make --silent -j4 &> /dev/null
	make --silent install
}
