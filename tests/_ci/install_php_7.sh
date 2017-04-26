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

install_apcu() {
	git clone --depth=1 -v https://github.com/krakjoe/apcu /tmp/apcu
	cd /tmp/apcu

	phpize &> /dev/null
	./configure --silent &> /dev/null

	make --silent -j"$(getconf _NPROCESSORS_ONLN)" &> /dev/null
	make --silent install
}

install_apcu_bc() {
	git clone -q https://github.com/krakjoe/apcu-bc /tmp/apcu-bc
	cd /tmp/apcu-bc

	phpize &> /dev/null
	./configure --silent &> /dev/null

	make --silent -j"$(getconf _NPROCESSORS_ONLN)" &> /dev/null
	make --silent install
}
