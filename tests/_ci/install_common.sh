#!/usr/bin/env bash

if [ -z $TRAVIS_BUILD_DIR ]; then
	TRAVIS_BUILD_DIR=$(readlink -enq $(dirname $0))
fi

CFLAGS="-O2 -g3 -fno-strict-aliasing -std=gnu90";

pecl channel-update pecl.php.net

enable_extension() {
    if [ -z $(php -m | grep "${1}") ]; then
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

    enable_extension $1
}
