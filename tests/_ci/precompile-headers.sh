#!/usr/bin/env bash
#
# This file is part of the Phalcon.
#
# (c) Phalcon Team <team@phalconphp.com>
#
# For the full copyright and license information, please view the LICENSE.txt
# file that was distributed with this source code.

if [ -z "${CC}" ]; then
	echo "The CC variable is unset or set to the empty string. Skip"
	exit 0
fi

echo "Creating precompiled headers..."
if [ "${CC:0:5}" = "clang" ]; then
	_ext="pch"
	_option="-emit-pch"
	_arg="-cc1"
else
	_ext="ghc"
	_option=
	_arg=
fi

# If a `*.gch' (or a `*.pch') file is not found then the normal header files
# will be used. For more see: http://en.wikipedia.org/wiki/Precompiled_header
for file in `find ./ext/kernel -name "*.h"`; do
	printf "\t>>> ${file}\n\t<<< ${file}.ghc\n"
	${CC} ${_arg} "${file}" -I. -I./ext $(php-config --includes) ${_option} -o "${file}.${_ext}"
done
