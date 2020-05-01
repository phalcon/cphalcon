#!/usr/bin/env bash
#
# This file is part of the Phalcon Framework.
#
# (c) Phalcon Team <team@phalcon.io>
#
# For the full copyright and license information, please view the
# LICENSE.txt file that was distributed with this source code.

: "${ZEPHIR_PARSER_VERSION:=master}"
: "${ZEPHIR_VERSION:=master}"
: "${DEFAULT_COMPOSER_FLAGS:=}"

# Install zephir_parser
git clone -b "$ZEPHIR_PARSER_VERSION" --depth 1 -q https://github.com/phalcon/php-zephir-parser
pushd php-zephir-parser 1>/dev/null || exit 1

# Select proper paths of PHP tools
if command -v phpenv >/dev/null 2>&1; then
  inidir="$(phpenv prefix)/etc/conf.d"
  phpize="$(phpenv which phpize)"
  phpconfig="$(phpenv which php-config)"
else
  inidir="$(php -i | grep 'Scan this dir' | grep -oE '/.*')"
  phpize="$(command -v phpize >/dev/null 2>&1)"
  phpconfig="$(command -v php-config >/dev/null 2>&1)"
fi

$phpize

./configure \
  --silent \
  --with-php-config="$phpconfig" \
  --enable-zephir-parser \
  CFLAGS="-O2 -g"

make --silent -j"$(getconf _NPROCESSORS_ONLN)"

# GitHub Actions requires sudo
if [ "$GITHUB_ACTIONS" == "true" ]; then
  sudo make --silent install || exit 1
  echo 'extension="zephir_parser.so"' | sudo tee "$inidir/zephir_parser.ini"
else
  make --silent install || exit 1
  echo 'extension="zephir_parser.so"' > "$inidir/zephir_parser.ini"
fi

popd 1>/dev/null || exit 1

# Install zephir
mkdir -p "$HOME/bin"
if [[ ! $ZEPHIR_VERSION =~ ^(master|development)$ ]]; then
  wget \
    --no-clobber \
    -O "$HOME/bin/zephir" \
    "https://github.com/phalcon/zephir/releases/download/$ZEPHIR_VERSION/zephir.phar"
  chmod +x "$HOME/bin/zephir"
  exit 0
fi

git clone -b "$ZEPHIR_VERSION" --depth 1 -q https://github.com/phalcon/zephir
pushd zephir 1>/dev/null || exit 1

eval "composer install $DEFAULT_COMPOSER_FLAGS"
ln -s "$(pwd)/zephir" "$HOME/bin/zephir"

popd 1>/dev/null || exit 1
