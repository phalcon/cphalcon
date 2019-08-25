#!/usr/bin/env bash
#
# This file is part of the Phalcon Framework.
#
# (c) Phalcon Team <team@phalcon.io>
#
# For the full copyright and license information, please view the
# LICENSE.txt file that was distributed with this source code.

# Export tests environment variables
# shellcheck disable=SC1091
source ./tests/_ci/environment

# shellcheck disable=SC2046
export $(cut -d= -f1 tests/_ci/environment)

# Export build environment variables
PHP_MAJOR="$(php -r 'echo phpversion();' | cut -d '.' -f 1)"
PHP_MINOR="$(php -r 'echo phpversion();' | cut -d '.' -f 2)"
PHP_VERNUM="$(php-config --vernum)"
PHP_PEAR_PHP_BIN=$(phpenv which php)

export PHP_MAJOR PHP_MINOR PHP_VERNUM PHP_PEAR_PHP_BIN
