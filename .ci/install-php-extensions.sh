#!/usr/bin/env bash
#
# This file is part of the Phalcon Framework.
#
# (c) Phalcon Team <team@phalconphp.com>
#
# For the full copyright and license information, please view the
# LICENSE.txt file that was distributed with this source code.

# -e  Exit immediately if a command exits with a non-zero status.
# -u  Treat unset variables as an error when substituting.
set -eu

PHP_INI="$(phpenv root)/versions/$(phpenv version-name)/etc/php.ini"
PHP_CONF_D="$(phpenv root)/versions/$(phpenv version-name)/etc/conf.d"

(>&1 echo 'Install apcu extension ...')
printf "\\n" | pecl install --force apcu_bc 1> /dev/null
# See https://pear.php.net/bugs/bug.php?id=21007
awk '/extension.*apcu?\.so"?/{$0=""}1' "${PHP_INI}" > php.ini.patch && mv php.ini.patch "${PHP_INI}"
cat <<EOT >> "$PHP_CONF_D/apcu.ini"
[apc]
extension      = "apcu.so"
extension      = "apc.so"

apc.enabled    = 1
apc.enable_cli = 1
EOT

(>&1 echo 'Install xdebug extension ...')
phpenv config-rm xdebug.ini >/dev/null 2>&1 || true
if [[ "$($(phpenv which php-config) --vernum)" -lt "70300" ]]
then
  printf "\\n" | pecl install --force xdebug 1> /dev/null
  awk '/zend_extension.*xdebug.so"?/{$0=""}1' "${PHP_INI}" > php.ini.patch && mv php.ini.patch "${PHP_INI}"
  echo 'zend_extension="xdebug.so"' > "$PHP_CONF_D/xdebug.ini"
fi

(>&1 echo 'Install memcached extension ...')
printf "\\n" | pecl install --force memcached 1> /dev/null

(>&1 echo 'Install msgpack extension ...')
printf "\\n" | pecl install --force msgpack 1> /dev/null

(>&1 echo 'Install igbinary extension ...')
printf "\\n" | pecl install --force igbinary 1> /dev/null

(>&1 echo 'Install imagick extension ...')
printf "\\n" | pecl install --force imagick 1> /dev/null

(>&1 echo 'Install psr extension ...')
printf "\\n" | pecl install --force psr 1> /dev/null

(>&1 echo 'Install yaml extension ...')
printf "\\n" | pecl install --force yaml 1> /dev/null

(>&1 echo 'Install mongodb extension ...')
printf "\\n" | pecl install --force mongodb 1> /dev/null

sodium_ext=$($(phpenv which php-config) --extension-dir)/sodium.so
if [[ "$(php --ri sodium 1> /dev/null)" = "" ]] && [[ ! -f "${sodium_ext}" ]]
then
  # for some reason Ubuntu 18.04 on Travis CI doesn't install libsodium-dev
  # via "addons -> apt -> packages"
  if [ "${CI}" = "true" ] && [ "$(dpkg -s libsodium-dev 1>/dev/null)" != "" ]
  then
    (>&1 echo "Install libsodium-dev...")
    sudo apt-get install \
      --no-install-recommends \
      --quiet \
      --assume-yes \
      libsodium-dev 1> /dev/null
  fi

  (>&1 echo 'Install libsodium extension ...')
  printf "\\n" | pecl install --force libsodium 1> /dev/null
fi

if [[ "$(php --ri sodium 1> /dev/null)" = "" ]] && [[ -f "${sodium_ext}" ]]
then
	echo 'extension="sodium.so"' > "$PHP_CONF_D/sodium.ini"
fi

redis_ext=$($(phpenv which php-config) --extension-dir)/redis.so
if [[ "$(php --ri redis 1> /dev/null)" = "" ]] && [[ ! -f "${redis_ext}" ]]
then
  (>&1 echo 'Install redis extension ...')
  printf "\\n" | pecl install --force redis 1> /dev/null
fi

if [[ "$(php --ri redis 1> /dev/null)" = "" ]] && [[ -f "${redis_ext}" ]]
then
	echo 'extension="redis.so"' > "$PHP_CONF_D/redis.ini"
fi
