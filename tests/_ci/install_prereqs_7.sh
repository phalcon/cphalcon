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

printf "\n" | pecl install --force apcu_bc &> /dev/null
printf "\n" | pecl install --force igbinary &> /dev/null
printf "\n" | pecl install --force imagick &> /dev/null
printf "\n" | pecl install --force yaml-2.0.0 &> /dev/null

# See https://pear.php.net/bugs/bug.php?id=21007
sed -i '1s/^/extension="apcu.so"\n/' "$(phpenv root)/versions/$(phpenv version-name)/etc/php.ini"
echo 'extension="memcached.so"' >> "$(phpenv root)/versions/$(phpenv version-name)/etc/php.ini"
