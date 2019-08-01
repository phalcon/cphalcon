#!/usr/bin/env bash
#
# This file is part of the Phalcon Framework.
#
# (c) Phalcon Team <team@phalconphp.com>
#
# For the full copyright and license information, please view the
# LICENSE.txt file that was distributed with this source code.

PHP_INI="$(phpenv root)/versions/$(phpenv version-name)/etc/php.ini"

# Install latest APC(u)
printf "\\n" | pecl install --force apcu_bc 1> /dev/null
# See https://pear.php.net/bugs/bug.php?id=21007
awk '/extension.*apcu?\.so"?/{$0=""}1' "${PHP_INI}" > php.ini.patch && mv php.ini.patch "${PHP_INI}"
cat <<EOT >> "$(phpenv root)/versions/$(phpenv version-name)/etc/conf.d/apcu.ini"
[apc]
extension      = "apcu.so"
extension      = "apc.so"

apc.enabled    = 1
apc.enable_cli = 1
EOT

# Install latest xdebug
phpenv config-rm xdebug.ini >/dev/null 2>&1 || true
if [[ "$PHP_VERNUM" -lt "70300" ]]
then
  printf "\\n" | pecl install --force xdebug 1> /dev/null
  awk '/zend_extension.*xdebug.so"?/{$0=""}1' "${PHP_INI}" > php.ini.patch && mv php.ini.patch "${PHP_INI}"
  echo 'zend_extension="xdebug.so"' > "$(phpenv root)/versions/$(phpenv version-name)/etc/conf.d/xdebug.ini"
fi

# Install latest memcached, msgpack, igbinary, imagick, psr, libsodium and yaml
printf "\\n" | pecl install --force memcached 1> /dev/null
printf "\\n" | pecl install --force msgpack 1> /dev/null
printf "\\n" | pecl install --force igbinary 1> /dev/null
printf "\\n" | pecl install --force imagick 1> /dev/null
printf "\\n" | pecl install --force psr 1> /dev/null
printf "\\n" | pecl install --force yaml 1> /dev/null
printf "\\n" | pecl install --force mongodb 1> /dev/null
printf "\\n" | pecl install --force libosodium 1> /dev/null

# Install redis
redis_ext=$($(phpenv which php-config) --extension-dir)/redis.so
if [[ ! -f "${redis_ext}" ]]
then
  printf "\\n" | pecl install --force redis 1> /dev/null
fi

if [[ "$(php --ri redis 1> /dev/null)" = "" ]] && [[ -f "${redis_ext}" ]]
then
	echo 'extension="redis.so"' > "$(phpenv root)/versions/$(phpenv version-name)/etc/conf.d/redis.ini"
fi
