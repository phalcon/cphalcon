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

install_extension imagick
enable_extension memcache
enable_extension memcached
install_extension igbinary
install_extension yaml
install_extension mongo

printf "\n" | pecl install apcu-4.0.11 &> /dev/null

echo "apc.enable_cli=On" >> ~/.phpenv/versions/$(phpenv version-name)/etc/php.ini
