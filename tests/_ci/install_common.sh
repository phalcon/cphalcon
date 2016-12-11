#!/usr/bin/env bash

CFLAGS="-O2 -g3 -fno-strict-aliasing -std=gnu90";

pecl channel-update pecl.php.net

enable_extension() {
    if [ -z $(php -m | grep "${1}") ] && [ -f "${TRAVIS_BUILD_DIR}/tests/_ci/${1}.ini" ]; then
        phpenv config-add "${TRAVIS_BUILD_DIR}/tests/_ci/${1}.ini"
    fi
}

install_extension() {
    INSTALLED=$(pecl list "${1}" | grep 'not installed')

    if [ -z "${INSTALLED}" ]; then
        printf "\n" | pecl upgrade "${1}" &> /dev/null
    else
        printf "\n" | pecl install "${1}" &> /dev/null
    fi

    enable_extension "${1}"
}

install_igbinary() {
	git clone -q https://github.com/igbinary/igbinary.git -b release-2.0.0 /tmp/igbinary
	cd /tmp/igbinary

	phpize &> /dev/null
	./configure CFLAGS="-O2 -g" --silent --enable-igbinary &> /dev/null

	make --silent -j4 &> /dev/null
	make --silent install

	if [ -z $(php -m | grep igbinary) ]; then
        phpenv config-add "${TRAVIS_BUILD_DIR}/tests/_ci/igbinary.ini"
    fi
}
