#!/usr/bin/env bash
#
# This file is part of the Phalcon.
#
# (c) Phalcon Team <team@phalconphp.com>
#
# For the full copyright and license information, please view
# the LICENSE.txt file that was distributed with this source code.

# -e	Exit immediately if a command exits with a non-zero status.
# -u	Treat unset variables as an error when substituting.
# -o	This setting prevents errors in a pipeline from being masked.
set -euo pipefail

# Ensure that this is being run inside a CI container
if [ "${CI}" != "true" ];
then
	(>&2 echo "This script is designed to run inside a CI container only.")
	(>&2 echo "Aborting.")
	exit 1
fi

if [ -z ${ZEPHIR_VERSION+x} ];
then
	(>&2 echo "The $ZEPHIR_VERSION is absent or empty.")
	(>&2 echo "Aborting.")
	exit 1
fi

if [ -z ${ZEPHIR_PARSER_VERSION+x} ];
then
	(>&2 echo "The ZEPHIR_PARSER_VERSION is absent or empty.")
	(>&2 echo "Aborting.")
	exit 1
fi

src=https://github.com/phalcon/php-zephir-parser.git

(>&1 echo "Cloning source: ${src}")
git clone --depth=1 -q "${src}" -b "${ZEPHIR_PARSER_VERSION}" 1>/dev/null

cd php-zephir-parser

$(phpenv which phpize)
./configure --with-php-config="$(phpenv which php-config)" --enable-zephir_parser 1>/dev/null
make --silent -j"$(getconf _NPROCESSORS_ONLN)" 1>/dev/null
make --silent install 1>/dev/null

echo "extension=zephir_parser.so" >> "$(phpenv prefix)/etc/conf.d/zephir_parser.ini"
$(phpenv which php) --ri 'Zephir Parser'

composer global require "phalcon/zephir:$ZEPHIR_VERSION" --no-interaction --no-ansi --no-progress --no-suggest
cd "$HOME/.composer/vendor/phalcon/zephir"
./install-nosudo

zephir version
