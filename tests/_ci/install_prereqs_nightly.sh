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
source ${TRAVIS_BUILD_DIR}/tests/_ci/install_php_7.sh

install_extension imagick
enable_extension memcached
install_apcu
install_apcu_bc

phpenv config-add "${TRAVIS_BUILD_DIR}/tests/_ci/apc_bc.ini"

printf "\n" | pecl install yaml-2.0.0 &> /dev/null

install_igbinary
