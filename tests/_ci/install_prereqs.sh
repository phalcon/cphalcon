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

install_extension imagick
enable_extension memcached

case ${PHP_VER} in
    "7.0")
        # Beta version of yaml extension works on 7.0
        install_extension yaml beta
        # todo: compile igbinary for 7.0
        ;;
    "*")
        install_extension yaml
        # no memcache or mongo on 7.0
        enable_extension memcache
        install_extension mongo
        # igbinary needs to be compiled for 7.0
        install_extension igbinary
        ;;
esac
 
case ${PHP_VER} in
    "5.4")
        install_extension apc
        ;;
    "*")
        install_extension apcu beta
        ;;
esac

wait
