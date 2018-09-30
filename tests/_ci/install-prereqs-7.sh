#!/usr/bin/env bash
#
# This file is part of the Phalcon.
#
# (c) Phalcon Team <team@phalconphp.com>
#
# For the full copyright and license information, please view the LICENSE
# file that was distributed with this source code.

# Ensure that this is being run inside a CI container
if [ "${CI}" != "true" ]; then
	echo "This script is designed to run inside a CI container only. Stop."
	exit 1
fi

PHP_MAJOR="$(`phpenv which php` -r 'echo phpversion();' | cut -d '.' -f 1)"
PHP_MINOR="$(`phpenv which php` -r 'echo phpversion();' | cut -d '.' -f 2)"

printf "\n" | pecl install --force apcu_bc &> /dev/null
printf "\n" | pecl install --force igbinary &> /dev/null
printf "\n" | pecl install --force imagick &> /dev/null

# See https://pear.php.net/bugs/bug.php?id=21007
sed -i '1s/^/extension="apcu.so"\n/' "$(phpenv root)/versions/$(phpenv version-name)/etc/php.ini"

if [ "${PHP_MAJOR}.${PHP_MINOR}" != "7.3" ] && [ "${PHP_MAJOR}.${PHP_MINOR}" != "7.4" ]; then
	printf "\n" | pecl install --force yaml-2.0.0 &> /dev/null
	echo 'extension="memcached.so"' >> "$(phpenv root)/versions/$(phpenv version-name)/etc/php.ini"
fi
