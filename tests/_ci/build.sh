#!/usr/bin/env bash
#
# This file is part of the Phalcon.
#
# (c) Phalcon Team <team@phalconphp.com>
#
# For the full copyright and license information, please view
# the LICENSE.txt file that was distributed with this source code.

shopt -s nullglob

zephir clean 2>&1 || exit 1
zephir fullclean 2>&1 || exit 1
zephir generate 2>&1 || exit 1

if [[ -z ${CC+x} ]]
then
  (>&1 echo "The CC variable is unset or set to the empty string.")
  (>&1 echo "Skip precompiling headers.")
else
  (>&1 echo "Creating precompiled headers...")
  if [[ "${CC:0:5}" = "clang" ]]
  then
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
  while IFS= read -r -d '' file
  do
    # shellcheck disable=SC2046
    ${CC} ${_arg} "${file}" -I. -I./ext $(php-config --includes) ${_option} -o "${file}.${_ext}"
  done <   <(find ./ext/kernel -name '*.h' -print0)
fi

cd ext || exit 1

$(phpenv which phpize)

./configure \
  --silent \
  --with-php-config="$(phpenv which php-config)" \
  --enable-phalcon \
  CFLAGS="-g -O0 -Wall -std=gnu90"

make -j"$(getconf _NPROCESSORS_ONLN)" >"$TRAVIS_BUILD_DIR/compile.log" 2> "$TRAVIS_BUILD_DIR/compile-errors.log"
make install

phpenv config-add "$TRAVIS_BUILD_DIR/tests/_ci/phalcon.ini"
