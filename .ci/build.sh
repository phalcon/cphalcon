#!/usr/bin/env bash
#
# This file is part of the Phalcon Framework.
#
# (c) Phalcon Team <team@phalcon.io>
#
# For the full copyright and license information, please view the
# LICENSE.txt file that was distributed with this source code.

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
	# will be used. For more see: https://en.wikipedia.org/wiki/Precompiled_header
  while IFS= read -r -d '' file
  do
    # shellcheck disable=SC2046
    ${CC} ${_arg} "${file}" -I. -I./ext $(php-config --includes) ${_option} -o "${file}.${_ext}"
  done <   <(find ./ext/kernel -name '*.h' -print0)
fi

cd ext || exit 1

phpize

if [[ -n ${REPORT_COVERAGE+x} ]] && [[ "$REPORT_COVERAGE" = "1" ]]; then
  CFLAGS=${CFLAGS//-O[0-9s]/}
  CXXFLAGS=${CXXFLAGS//-O[0-9s]/}
  LDFLAGS=${LDFLAGS//--coverage/}

  LDFLAGS="${LDFLAGS} --coverage"
  CFLAGS="${CFLAGS} -O0 -ggdb -fprofile-arcs -ftest-coverage"
  CXXFLAGS="${CXXFLAGS} -O0 -ggdb -fprofile-arcs -ftest-coverage"
fi

./configure \
  --silent \
  --with-php-config="$(phpenv which php-config)" \
  --enable-phalcon \
  CFLAGS="${CFLAGS}" \
  LDFLAGS="${LDFLAGS}"

make -j"$(getconf _NPROCESSORS_ONLN)" >/dev/null 2> ./compile-errors.log
make install

phpenv config-add ../.ci/phalcon.ini || exit 1

cd .. || exit 1
