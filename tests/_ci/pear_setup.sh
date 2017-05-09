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

# trace ERR through pipes
set -o pipefail

# trace ERR through 'time command' and other functions
set -o errtrace

# set -u : exit the script if you try to use an uninitialised variable
set -o nounset

# set -e : exit the script if any statement returns a non-true return value
set -o errexit

# Ensure that this is being run inside a CI
if [ ! -n "$CI" ] || [ "${CI}" != "true" ]; then
    echo "This script is designed to run inside a CI container only. Exiting"
    exit 1
fi

mkdir -p "$HOME/pear"

mkdir -p "$(phpenv root)/versions/$(phpenv version-name)/etc/conf.d"
mkdir -p "$(phpenv root)/versions/$(phpenv version-name)/share/pear/docs"
mkdir -p "$(phpenv root)/versions/$(phpenv version-name)/share/pear/cfg"
mkdir -p "$(phpenv root)/versions/$(phpenv version-name)/share/pear/data"
mkdir -p "$(phpenv root)/versions/$(phpenv version-name)/share/pear/tests"
mkdir -p "$(phpenv root)/versions/$(phpenv version-name)/share/pear/www"
mkdir -p "$(phpenv root)/versions/$(phpenv version-name)/php/man"
mkdir -p "$(phpenv root)/versions/$(phpenv version-name)/etc/pearkeys"

mkdir -p $HOME/bin

# Travis CI ugly hack
ln -s $(phpenv which php) $HOME/bin/php
ln -s $(phpenv which phpize) $HOME/bin/phpize

pear config-set auto_discover 1
pear config-set preferred_state devel

pear config-set php_bin $(phpenv which php)

pear config-set download_dir "$HOME/pear"
pear config-set php_dir "$(phpenv root)/versions/$(phpenv version-name)/share/pear"
pear config-set ext_dir `$(phpenv which php-config) --extension-dir`
pear config-set bin_dir "$(phpenv root)/versions/$(phpenv version-name)/bin"
pear config-set doc_dir "$(phpenv root)/versions/$(phpenv version-name)/share/pear/docs"
pear config-set cfg_dir "$(phpenv root)/versions/$(phpenv version-name)/share/pear/cfg"
pear config-set data_dir "$(phpenv root)/versions/$(phpenv version-name)/share/pear/data"
pear config-set test_dir "$(phpenv root)/versions/$(phpenv version-name)/share/pear/tests"
pear config-set www_dir "$(phpenv root)/versions/$(phpenv version-name)/share/pearr/www"
pear config-set sig_keydir "$(phpenv root)/versions/$(phpenv version-name)/etc/pearkeys"

# Does not work on PHP 5.x
if [ "$(echo `$(phpenv which php-config) --version` | cut -d '.' -f 1)" != "5" ]; then
	pear config-set man_dir "$(phpenv root)/versions/$(phpenv version-name)/php/man"
fi

pear config-set php_ini "$(phpenv root)/versions/$(phpenv version-name)/etc/php.ini"

echo "opcache.enable_cli=1" >> "$(phpenv root)/versions/$(phpenv version-name)/etc/php.ini"
echo 'apc.enabled=1' >> "$(phpenv root)/versions/$(phpenv version-name)/etc/php.ini"
echo 'apc.enable_cli=1' >> "$(phpenv root)/versions/$(phpenv version-name)/etc/php.ini"

pecl channel-update pecl.php.net || true
