#!/usr/bin/env bash

DIR=$(readlink -enq $(dirname $0))
CFLAGS="-O2 -g3 -fno-strict-aliasing -std=gnu90";

pecl channel-update pecl.php.net

enable_extension() {
    if [ -z $(php -m | grep $1) ]; then
        phpenv config-add "$DIR/$1.ini"
    fi
}

install_extension() {
    INSTALLED=$(pecl list $1 | grep 'not installed')

    if [ -z "${INSTALLED}" ]; then
        printf "\n" | pecl upgrade $1 &> /dev/null
    else
        printf "\n" | pecl install $1 &> /dev/null
    fi

    enable_extension $1
}

install_igbinary() {
	git clone https://github.com/igbinary/igbinary7.git /tmp/igbinary
	cd /tmp/igbinary;

	$PHPIZE_BIN &> /dev/null
	./configure CFLAGS="-O2 -g" --silent --enable-phalcon &> /dev/null

	make --silent -j4 &> /dev/null
	make --silent install

	if [ -z $(php -m | grep igbinary) ]; then
        phpenv config-add "$DIR/igbinary.ini"
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

install_extension imagick
enable_extension memcached

install_apcu
install_apcu_bc
phpenv config-add "$DIR/apc_bc.ini"

printf "\n" | pecl install yaml-2.0.0 &> /dev/null

install_igbinary
