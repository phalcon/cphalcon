#!/usr/bin/env bash
#
#  Phalcon Framework
#
#  Copyright (c) 2011-2017 Phalcon Team (https://www.phalconphp.com)
#
#  This source file is subject to the New BSD License that is bundled
#  with this package in the file LICENSE.txt.
#
#  If you did not receive a copy of the license and are unable to
#  obtain it through the world-wide-web, please send an email
#  to license@phalconphp.com so we can send you a copy immediately.

printf "\n" | pecl install --force apcu-4.0.11 &> /dev/null
printf "\n" | pecl install --force igbinary &> /dev/null
printf "\n" | pecl install --force imagick &> /dev/null
printf "\n" | pecl install --force yaml &> /dev/null

echo 'extension="mongo.so"' >> "$(phpenv root)/versions/$(phpenv version-name)/etc/php.ini"
echo 'extension="memcache.so"' >> "$(phpenv root)/versions/$(phpenv version-name)/etc/php.ini"
echo 'extension="memcached.so"' >> "$(phpenv root)/versions/$(phpenv version-name)/etc/php.ini"
