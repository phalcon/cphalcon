#!/bin/sh

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

php ./unit-tests/ci/phpunit.php --debug -c unit-tests/phpunit.xml
STATUS=$?
if [ $STATUS != 0 ]; then
	shopt -s nullglob
	export LC_ALL=C
	for i in core core.*; do
		if [ -f "$i" -a "$(file "$i" | grep -o 'core file')" ]; then
			gdb -q $(file "$i" | grep -Eo "'.*'\$") "$i" <<EOF
set pagination 0
backtrace full
info registers
x/16i \$pc
thread apply all backtrace
quit
EOF
		fi
	done
fi

exit $STATUS
