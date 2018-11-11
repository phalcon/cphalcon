#!/usr/bin/env bash
#
# This file is part of the Phalcon.
#
# (c) Phalcon Team <team@phalconphp.com>
#
# For the full copyright and license information, please view the LICENSE.txt
# file that was distributed with this source code.

# Exit the script if any statement returns a non-true return value
set -e

ZEPHIR_PARSER_VERSION=${ZEPHIR_PARSER_VERSION:-development}

pushd /tmp

git clone --depth=1 -v https://github.com/phalcon/php-zephir-parser.git -b ${ZEPHIR_PARSER_VERSION}
cd php-zephir-parser
phpize
./configure
make
make install

popd

echo "extension=zephir_parser.so" >> $(phpenv root)/versions/$(phpenv version-name)/etc/conf.d/zephir-parser.ini

php --ri 'Zephir Parser'
