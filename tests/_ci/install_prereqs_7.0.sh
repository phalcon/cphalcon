#!/usr/bin/env bash

source install_common.sh

install_igbinary() {
	git clone https://github.com/igbinary/igbinary7.git /tmp/igbinary
	cd /tmp/igbinary

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
