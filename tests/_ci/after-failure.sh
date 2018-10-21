#!/usr/bin/env bash
#
# This file is part of the Phalcon.
#
# (c) Phalcon Team <team@phalconphp.com>
#
# For the full copyright and license information, please view the LICENSE
# file that was distributed with this source code.

shopt -s nullglob

export LC_ALL=C

ls -al `$(phpenv which php-config) --extension-dir`
$(phpenv which php) -v
$(phpenv which php) -m
$(phpenv which php) --ri phalcon

PROJECT_ROOT=$(readlink -enq "$(dirname $0)/../../")

for i in `find ${PROJECT_ROOT}/tests -name "*.out" 2>/dev/null`; do
	echo "-- START ${i}"; cat ${i}; echo "-- END";
done

for i in `find ${PROJECT_ROOT}/tests -name "*.mem" 2>/dev/null`; do
	echo "-- START ${i}"; cat ${i}; echo "-- END";
done

for i in core core*; do
	if [ -f "$i" -a "$(file "$i" | grep -o 'core file')" ]; then
		gdb -q $(phpenv which php) "$i" <<EOF
set pagination 0
backtrace full
info registers
x/16i \$pc
thread apply all backtrace
quit
EOF
	fi
done
