#!/usr/bin/env bash
#
# This file is part of the Phalcon.
#
# (c) Phalcon Team <team@phalconphp.com>
#
# For the full copyright and license information, please view the LICENSE.txt
# file that was distributed with this source code.

DEFAULT_COMPOSER_FLAGS="--no-interaction --no-ansi --no-progress --no-suggest"
PROJECT_ROOT=$(readlink -enq "$(dirname $0)/../../")

cd ${PROJECT_ROOT}
composer install ${DEFAULT_COMPOSER_FLAGS}

PHP_MAJOR="$(`phpenv which php` -r 'echo phpversion();' | cut -d '.' -f 1)"

#if [ "${PHP_MAJOR}" = "7" ]; then
#	composer remove -n --no-ansi --no-progress --dev doctrine/instantiator
#	composer remove -n --no-ansi --no-progress --dev phpdocumentor/reflection-docblock
#	composer remove -n --no-ansi --no-progress --dev phpunit/phpunit
#	composer require ${DEFAULT_COMPOSER_FLAGS} "phpunit/phpunit:^6.4"
#fi
