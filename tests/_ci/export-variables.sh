#!/usr/bin/env bash
#
# This file is part of the Phalcon.
#
# (c) Phalcon Team <team@phalconphp.com>
#
# For the full copyright and license information, please view
# the LICENSE.txt file that was distributed with this source code.

# Export tests environment variables
# shellcheck disable=SC1091
source ./tests/_ci/environment

# shellcheck disable=SC2046
export $(cut -d= -f1 tests/_ci/environment)

PHP_MAJOR="$(php -r 'echo phpversion();' | cut -d '.' -f 1)"
PHP_MINOR="$(php -r 'echo phpversion();' | cut -d '.' -f 2)"
PHP_PEAR_PHP_BIN="$(phpenv which php)"

export PHP_MAJOR PHP_MINOR PHP_PEAR_PHP_BIN

if [ "$PHP_MAJOR" == "5" ]; then
  export BACKEND="ZendEngine2"
fi

unset _php
