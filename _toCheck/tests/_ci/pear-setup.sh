#!/usr/bin/env bash
#
# This file is part of the Phalcon.
#
# (c) Phalcon Team <team@phalconphp.com>
#
# For the full copyright and license information, please view the LICENSE.txt
# file that was distributed with this source code.

# trace ERR through pipes
set -o pipefail

# trace ERR through 'time command' and other functions
set -o errtrace

# set -u : exit the script if you try to use an uninitialised variable
set -o nounset

# set -e : exit the script if any statement returns a non-true return value
set -o errexit

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
pear config-set www_dir "$(phpenv root)/versions/$(phpenv version-name)/share/pear/www"
pear config-set sig_keydir "$(phpenv root)/versions/$(phpenv version-name)/etc/pearkeys"

# Does not work on PHP 5.x
if [ "$(echo `$(phpenv which php-config) --version` | cut -d '.' -f 1)" != "5" ]; then
	pear config-set man_dir "$(phpenv root)/versions/$(phpenv version-name)/php/man"
fi

pear config-set php_ini "$(phpenv root)/versions/$(phpenv version-name)/etc/php.ini"

pecl channel-update pecl.php.net || true
