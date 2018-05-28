#!/usr/bin/env bash
#
#  Phalcon Framework
#
#  Copyright (c) 2011-present Phalcon Team (https://www.phalconphp.com)
#
#  This source file is subject to the New BSD License that is bundled
#  with this package in the file LICENSE.txt.
#
#  If you did not receive a copy of the license and are unable to
#  obtain it through the world-wide-web, please send an email
#  to license@phalconphp.com so we can send you a copy immediately.

shopt -s nullglob
export LC_ALL=C

for i in /tmp/core_*.*; do
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

$(phpenv which php) -m
$(phpenv which php) -i
