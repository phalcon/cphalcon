#!/usr/bin/env bash
#
# This file is part of the Phalcon.
#
# (c) Phalcon Team <team@phalconphp.com>
#
# For the full copyright and license information, please view
# the LICENSE.txt file that was distributed with this source code.

printf "\\n" | pecl install --force apcu_bc 1> /dev/null
# See https://pear.php.net/bugs/bug.php?id=21007
awk '/extension.*apcu?\.so"?/{$0=""}1' "$(phpenv prefix)/etc/php.ini" > php.ini.patch
mv php.ini.patch "$(phpenv prefix)/etc/php.ini"

cat <<EOT >> "$(phpenv prefix)/etc/conf.d/apcu.ini"
[apc]
extension      = "apcu.so"
extension      = "apc.so"

apc.enabled    = 1
apc.enable_cli = 1
EOT

printf "\\n" | pecl install --force igbinary 1> /dev/null
printf "\\n" | pecl install --force imagick 1> /dev/null
printf "\\n" | pecl install --force psr 1> /dev/null
printf "\\n" | pecl install --force yaml 1> /dev/null

if [[ "$(php-config --vernum)" -ge 70300 ]] || [[ -f "$(php-config --extension-dir)/memcached.so" ]]
then
  git clone \
    --depth=1 \
    https://github.com/php-memcached-dev/php-memcached memcached

  cd memcached || exit 1

  $(phpenv which phpize)
  ./configure --with-php-config="$(phpenv which php-config)" --enable-memcached 1>/dev/null
  make --silent -j"$(getconf _NPROCESSORS_ONLN)" 1>/dev/null
  make --silent install 1>/dev/null
fi

echo "extension=memcached.so" >> "$(phpenv prefix)/etc/conf.d/memcached.ini"

if [[ "$(php --ri redis 1> /dev/null)" = "" ]] && [[ ! -f "$(php-config --extension-dir)/redis.so" ]]
then
  (>&1 echo 'Install redis extension ...')
  printf "\\n" | pecl install --force redis 1> /dev/null
fi

if [[ "$(php --ri redis 1> /dev/null)" = "" ]] && [[ -f "$(php-config --extension-dir)/redis.so" ]]
then
	echo 'extension="redis.so"' > "$(phpenv prefix)/etc/conf.d/redis.ini"
fi
