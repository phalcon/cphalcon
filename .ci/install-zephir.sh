#!/usr/bin/env bash
#
# This file is part of the Phalcon Framework.
#
# (c) Phalcon Team <team@phalcon.io>
#
# For the full copyright and license information, please view the
# LICENSE.txt file that was distributed with this source code.

# TODO: Move Zephir installation to composer.json

: "${ZEPHIR_VERSION:=master}"
: "${DEFAULT_COMPOSER_FLAGS:=}"

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

# Executes the command in a subshell.
# It inherits everything from the calling script but does not
# transmit any change back.
(eval "composer install $DEFAULT_COMPOSER_FLAGS")

ln -s "$(pwd)/zephir" "$HOME/bin/zephir"

popd 1>/dev/null || exit 1
