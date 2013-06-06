#!/bin/bash

#  Phalcon Framework
#
#  Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)
#
#  This source file is subject to the New BSD License that is bundled
#  with this package in the file docs/LICENSE.txt.
#
#  If you did not receive a copy of the license and are unable to
#  obtain it through the world-wide-web, please send an email
#  to license@phalconphp.com so we can send you a copy immediately.
#
#  Authors: Andres Gutierrez <andres@phalconphp.com>
#            Eduar Carvajal <eduar@phalconphp.com>

find_core_dump() {
	find /home/travis -name "core"
}

ulimit -c unlimited
PHP_VERSION=`php -r "echo PHP_VERSION;"`
PHP_BIN="/home/travis/.phpenv/versions/$PHP_VERSION/bin/php"
echo $PHP_BIN

$PHP_BIN ./unit-tests/ci/phpunit.php --debug -c unit-tests/phpunit.xml
STATUS=$?
if [ $STATUS != 0 ]; then
	if [ -f /tmp/core ]; then
		sudo apt-get install gdb
		gdb -q -batch -x ./unit-tests/ci/gdb-commands -e $PHP_BIN -c /tmp/core
	else
		find_core_dump
		echo "No core dump was found"
	fi

	exit $STATUS
fi

$PHP_BIN ./php-tests/ci/phpunit.php --debug -c php-tests/tests/phpunit.xml
STATUS=$?
if [ $STATUS != 0 ]; then
	if [ -f /tmp/core ]; then
		sudo apt-get install gdb
		gdb -q -batch -x ./unit-tests/ci/gdb-commands -e $PHP_BIN -c /tmp/core
	else
		find_core_dump
		echo "No core dump was found"
	fi
fi

exit $STATUS
