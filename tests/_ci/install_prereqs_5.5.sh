#!/usr/bin/env bash
#
#  Phalcon Framework
#
#  Copyright (c) 2011-2017 Phalcon Team (https://www.phalconphp.com)
#
#  This source file is subject to the New BSD License that is bundled
#  with this package in the file docs/LICENSE.txt.
#
#  If you did not receive a copy of the license and are unable to
#  obtain it through the world-wide-web, please send an email
#  to license@phalconphp.com so we can send you a copy immediately.

CURRENT_DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
TRAVIS_BUILD_DIR="${TRAVIS_BUILD_DIR:-$(dirname $(dirname $CURRENT_DIR))}"

source ${TRAVIS_BUILD_DIR}/tests/_ci/install_common.sh

install_extension imagick
enable_extension memcache
enable_extension memcached
install_extension yaml
install_extension mongo

printf "\n" | pecl install apcu-4.0.11 &> /dev/null

echo "apc.enable_cli=On" >> ~/.phpenv/versions/$(phpenv version-name)/etc/php.ini

install_igbinary
