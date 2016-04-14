#!/usr/bin/env bash

DIR=$(readlink -enq $(dirname $0))
CFLAGS="-g0 -O0 -std=gnu90";

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

install_extension igbinary
install_extension imagick
install_extension yaml
install_extension mongo
enable_extension memcache
enable_extension memcached

if [ ${TRAVIS_PHP_VERSION} = "5.4" ]; then
    echo "Install APC"
    ( CFLAGS="-O2 -g3 -fno-strict-aliasing" pecl upgrade apc < /dev/null; phpenv config-add "$DIR/apc.ini" ) &
elif [ ${TRAVIS_PHP_VERSION} = "7" ]; then
    echo "Install APCu"
    ( pecl config-set preferred_state beta; pecl install -a apcu < /dev/null && phpenv config-add "$DIR/apcu.ini" ) &
else
    echo "Install APCu"
    ( pecl install -a apcu-4.0.10 < /dev/null; phpenv config-add "$DIR/apc.ini" ) &
fi

wait
