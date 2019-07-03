#!/usr/bin/env bash
#
# This file is part of the Phalcon Framework.
#
# (c) Phalcon Team <team@phalconphp.com>
#
# For the full copyright and license information, please view the
# LICENSE.txt file that was distributed with this source code.

: ${ZEPHIR_PARSER_VERSION:=master}
: ${ZEPHIR_VERSION:=master}

# Install zephir_parser
git clone -b "${ZEPHIR_PARSER_VERSION}" --depth 1 -q https://github.com/phalcon/php-zephir-parser
cd php-zephir-parser
$(phpenv which phpize)
./configure --silent --with-php-config=$(phpenv which php-config) --enable-zephir_parser
make --silent -j"$(getconf _NPROCESSORS_ONLN)"
make --silent install
echo 'extension="zephir_parser.so"' > "$(phpenv root)/versions/$(phpenv version-name)/etc/conf.d/zephir_parser.ini"

# Install zephir
if [[ ! $ZEPHIR_VERSION =~ ^(master|development)$ ]]; then
	wget \
		--no-clobber \
		-O $HOME/bin/zephir \
		https://github.com/phalcon/zephir/releases/download/${ZEPHIR_VERSION}/zephir.phar
	chmod +x $HOME/bin/zephir
else
	git clone -b "${ZEPHIR_VERSION}" --depth 1 -q https://github.com/phalcon/zephir
	cd zephir
	composer install $DEFAULT_COMPOSER_FLAGS
	ln -s $(pwd)/zephir $HOME/bin/zephir
fi

# Local variables:
# tab-width: 4
# c-basic-offset: 4
# End:
# vim600: noet sw=4 ts=4
# vim<600: noet sw=4 ts=4
