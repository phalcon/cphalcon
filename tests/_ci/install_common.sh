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

CFLAGS="-O2 -g3 -fno-strict-aliasing -std=gnu90";

pecl channel-update pecl.php.net || true

enable_extension() {
    if [ -z $(php -m | grep "${1}") ] && [ -f "${TRAVIS_BUILD_DIR}/tests/_ci/${1}.ini" ]; then
        phpenv config-add "${TRAVIS_BUILD_DIR}/tests/_ci/${1}.ini"
    fi
}

install_extension() {
    INSTALLED=$(pecl list "${1}" | grep 'not installed')

    if [ -z "${INSTALLED}" ]; then
        printf "\n" | pecl upgrade "${1}" &> /dev/null
    else
        printf "\n" | pecl install "${1}" &> /dev/null
    fi

    enable_extension "${1}"
}

install_igbinary() {
	git clone -q https://github.com/igbinary/igbinary.git -b release-2.0.0 /tmp/igbinary
	cd /tmp/igbinary

	phpize &> /dev/null
	./configure CFLAGS="-O2 -g" --silent --enable-igbinary &> /dev/null

	make --silent -j4 &> /dev/null
	make --silent install

	if [ -z $(php -m | grep igbinary) ]; then
        phpenv config-add "${TRAVIS_BUILD_DIR}/tests/_ci/igbinary.ini"
    fi
}
