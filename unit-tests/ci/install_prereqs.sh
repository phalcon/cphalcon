#!/usr/bin/env bash

DIR=$(readlink -enq $(dirname $0))
PHP_VER=$(php -r 'echo substr(PHP_VERSION, 0, 3);');
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

case ${PHP_VER} in
    "5.4")
        install_extension apc
        ;;
    "*")
        install_extension apcu beta
        ;;
esac

phpenv config-rm xdebug.ini

wait
