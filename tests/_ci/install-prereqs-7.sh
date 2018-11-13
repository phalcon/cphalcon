#!/usr/bin/env bash
#
# This file is part of the Phalcon.
#
# (c) Phalcon Team <team@phalconphp.com>
#
# For the full copyright and license information, please view the LICENSE.txt
# file that was distributed with this source code.

PROJECT_ROOT=$(readlink -enq "$(dirname $0)/../../")

source ${PROJECT_ROOT}/tests/_ci/ci-tools.sh

printf "\n" | pecl install --force apcu_bc &> /dev/null
printf "\n" | pecl install --force igbinary &> /dev/null
printf "\n" | pecl install --force imagick &> /dev/null
printf "\n" | pecl install --force psr &> /dev/null
printf "\n" | pecl install --force yaml-2.0.3 &> /dev/null

# See https://pear.php.net/bugs/bug.php?id=21007
sed -i '1s/^/extension="apcu.so"\n/' "$(phpenv root)/versions/$(phpenv version-name)/etc/php.ini"

install_ext_from_src "zephir_parser" "https://github.com/phalcon/php-zephir-parser" ""

if [ "$(`phpenv which php-config` --vernum)" -ge 70300 ]; then
	install_ext_from_src "memcached" "https://github.com/php-memcached-dev/php-memcached" "--disable-memcached-sasl"
else
	echo 'extension="memcached.so"' > "$(phpenv root)/versions/$(phpenv version-name)/etc/conf.d/memcached.ini"
fi
