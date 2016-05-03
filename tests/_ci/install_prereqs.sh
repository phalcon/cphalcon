#!/usr/bin/env bash

DIR=$(readlink -enq $(dirname $0))
CFLAGS="-O2 -g3 -fno-strict-aliasing -std=gnu90";

pecl channel-update pecl.php.net

enable_extension() {

    if [ -z "$1" ]; then
        return 1;
    fi

    if [ -z $(php -m | grep $1) ]; then
        phpenv config-add "$DIR/$1.ini"
    fi

    return 0;
}

install_extension() {

    if [ "$2" ]; then
        pecl config-set preferred_state beta;
    fi

    declare INSTALLED=$(pecl list $1 | grep 'not installed')

    if [ -z "$1" ]; then
        return 1;
    fi

    if [ -z "${INSTALLED}" ]; then
        printf "\n" | pecl upgrade $1 &> /dev/null
    else
        printf "\n" | pecl install $1 &> /dev/null
    fi

   enable_extension $1

   return 0;
}

install_extension imagick
enable_extension memcached

if [ ${TRAVIS_PHP_VERSION} != "7.0" ]; then
    install_extension igbinary
    install_extension yaml
    install_extension mongo
    enable_extension memcache
fi

if [ ${TRAVIS_PHP_VERSION} == "5.4" ]; then
    ( printf "\n" | pecl upgrade apc &> /dev/null; enable_extension apc ) &
elif [ ${TRAVIS_PHP_VERSION} == "7.0" ]; then
    ( mkdir -p /tmp/apcu && cd /tmp/apcu && git clone https://github.com/krakjoe/apcu /tmp/apcu && phpize && ./configure && make -j 4 && sudo make install && phpenv config-add "$DIR/apcu.ini" ) &
else
    ( pecl install apcu &> /dev/null && phpenv config-add "$DIR/apcu.ini" ) &
fi

wait
