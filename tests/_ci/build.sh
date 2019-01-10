#!/usr/bin/env bash
#
# This file is part of the Phalcon Framework.
#
# (c) Phalcon Team <team@phalconphp.com>
#
# For the full copyright and license information, please view the LICENSE.txt
# file that was distributed with this source code.
#

PROJECT_ROOT=$(readlink -enq "$(dirname $0)/../../")
LCOV_REPORT=${PROJECT_ROOT}/tests/_output/lcov.info

shopt -s nullglob

zephir clean 2>&1
zephir fullclean 2>&1
zephir generate 2>&1

if [[ -z ${CC+x} ]]; then
	echo -e "The CC variable is unset or set to the empty string.\nSkip precompiling headers.\n"
else
	echo "Creating precompiled headers..."
	if [[ "${CC:0:5}" = "clang" ]]; then
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
		${CC} ${_arg} "${file}" -I. -I./ext $(php-config --includes) ${_option} -o "${file}.${_ext}"
	done
fi

cd ext

phpize

if [[ ! -z ${REPORT_COVERAGE+x} ]] && [[ "$REPORT_COVERAGE" = "1" ]]; then
	# The ltmain.sh which bundled with PHP it's from libtool 1.5.26.
	# However, the version of libtool that claims to no longer remove
	# ".gcno" profiler information is libtool 2.2.6. The fix is probably
	# in later libtool versions as well.
	if [[ "$(uname -s 2>/dev/null)" = "Darwin" ]]; then
		# macOS
		LIBTOOLIZE_BIN=$(command -v glibtoolize 2>/dev/null)
	else
		# Linux, Gentoo, etc
		LIBTOOLIZE_BIN=$(command -v libtoolize 2>/dev/null)
	fi

	aclocal && ${LIBTOOLIZE_BIN} --copy --force && autoheader && autoconf

	CFLAGS=`echo "${CFLAGS}" | sed -e 's/-O[0-9s]*//g'`
	CXXFLAGS=`echo "${CXXFLAGS}" | sed -e 's/-O[0-9s]*//g'`
	LDFLAGS=`echo "${LDFLAGS}" | sed -e 's/--coverage//g'`

	LDFLAGS="${LDFLAGS} --coverage"
	CFLAGS="${CFLAGS} -O0 -ggdb -fprofile-arcs -ftest-coverage"
	CXXFLAGS="${CXXFLAGS} -O0 -ggdb -fprofile-arcs -ftest-coverage"
fi

./configure --silent --with-php-config=$(phpenv which php-config) --enable-phalcon CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

make -j"$(getconf _NPROCESSORS_ONLN)" > /dev/null 2> ${PROJECT_ROOT}/compile-errors.log
make install

phpenv config-add ${PROJECT_ROOT}/tests/_ci/phalcon.ini

cd ..

if [[ ! -z ${REPORT_COVERAGE+x} ]] && [[ "$REPORT_COVERAGE" = "1" ]]; then
	if [[ $(command -v lcov 2>/dev/null) = "" ]]; then
		echo -e "lcov does not exist.\nSkip capturing coverage data.\n"
	else
		# Reset all execution counts to zero
		lcov \
			--quiet \
			--directory ext \
			--base-directory=${PROJECT_ROOT} \
			--zerocounters 2>&1 >/dev/null

		# Capture coverage data
		lcov \
			--quiet \
			--directory ext \
			--base-directory=${PROJECT_ROOT} \
			--capture \
			--compat-libtool \
			--initial \
			--output-file ${LCOV_REPORT} 2>&1 >/dev/null
	fi
fi
