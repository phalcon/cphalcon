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

install_igbinary_php7() {
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

install_extension imagick
enable_extension memcached

if [ ${TRAVIS_PHP_VERSION} != "7.0" ]; then
    install_extension igbinary
    install_extension yaml
    install_extension mongo
    echo "extension=memcache.so" >> ~/.phpenv/versions/$(phpenv version-name)/etc/php.ini
fi

if [ ${TRAVIS_PHP_VERSION} == "5.4" ]; then
    ( printf "\n" | pecl upgrade apc &> /dev/null; enable_extension apc ) &
elif [ ${TRAVIS_PHP_VERSION} == "7.0" ]; then
	# See https://pear.php.net/bugs/bug.php?id=21007
	printf "\n" | pecl install apcu
	printf "\n" | pecl install apcu_bc-beta
	echo "apc.enable_cli=On" >> ~/.phpenv/versions/$(phpenv version-name)/etc/php.ini
	printf "\n" | pecl install yaml-2.0.0RC8
	install_igbinary_php7
else
    ( pecl install apcu-4.0.11 &> /dev/null && echo "apc.enable_cli=On" >> ~/.phpenv/versions/$(phpenv version-name)/etc/php.ini ) &
fi

wait
