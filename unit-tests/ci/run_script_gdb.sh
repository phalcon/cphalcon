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

# Note: Use this script to run phalcon under GDB this shows a backtrace on TRAVIS

ulimit -c unlimited
PHP_VERSION=`php -r "echo PHP_VERSION;"`
PHP_BIN="/home/travis/.phpenv/versions/$PHP_VERSION/bin/php"
echo $PHP_BIN

sudo apt-get install gdb

gdb -q -batch -x ./unit-tests/ci/gdb-commands-run -e $PHP_BIN
STATUS=$?
if [ $STATUS != 0 ]; then
	exit $STATUS
fi

exit $STATUS
