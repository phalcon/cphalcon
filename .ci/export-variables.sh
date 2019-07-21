#!/usr/bin/env bash
#
# This file is part of the Phalcon Framework.
#
# (c) Phalcon Team <team@phalconphp.com>
#
# For the full copyright and license information, please view the
# LICENSE.txt file that was distributed with this source code.

# Export tests environment variables
source tests/_ci/environment
export $(cut -d= -f1 tests/_ci/environment)

# Export build environment variables
export PHP_MAJOR="$(php -r 'echo phpversion();' | cut -d '.' -f 1)"
export PHP_MINOR="$(php -r 'echo phpversion();' | cut -d '.' -f 2)"
export PHP_VERNUM="$(php-config --vernum)"
export PHP_PEAR_PHP_BIN=$(phpenv which php)
