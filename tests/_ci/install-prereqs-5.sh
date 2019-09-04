#!/usr/bin/env bash
#
# This file is part of the Phalcon.
#
# (c) Phalcon Team <team@phalconphp.com>
#
# For the full copyright and license information, please view
# the LICENSE.txt file that was distributed with this source code.

printf "\\n" | pecl install --force apcu-4.0.11 1> /dev/null
cat <<EOT >> "$(phpenv prefix)/etc/php.ini"
apc.enabled    = 1
apc.enable_cli = 1
EOT

printf "\\n" | pecl install --force igbinary-2.0.8  1> /dev/null
printf "\\n" | pecl install --force imagick 1> /dev/null
printf "\\n" | pecl install --force yaml-1.3.1 1> /dev/null
printf "\\n" | pecl install --force memcache-2.2.7 1> /dev/null
printf "\\n" | pecl install --force psr-0.6.0 1> /dev/null

echo 'extension="mongo.so"' >> "$(phpenv prefix)/etc/php.ini"

if [ -f "$(php-config --extension-dir)/memcached.so" ]
then
  echo 'extension="memcached.so"' >> "$(phpenv prefix)/etc/php.ini"
else
  printf "\n" | pecl install --force memcached-2.2.0 1> /dev/null
fi

if [[ "$(php --ri redis 1> /dev/null)" = "" ]] && [[ ! -f "$(phpenv prefix)/etc/conf.d/redis.so" ]]
then
  (>&1 echo 'Install redis extension ...')
  printf "\\n" | pecl install --force redis 1> /dev/null
fi

if [[ "$(php --ri redis 1> /dev/null)" = "" ]] && [[ -f "$(php-config --extension-dir)/redis.so" ]]
then
	echo 'extension="redis.so"' > "$(phpenv prefix)/etc/conf.d/redis.ini"
fi
