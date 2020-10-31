#!/usr/bin/env bash
#
# This file is part of the Phalcon Framework.
#
# (c) Phalcon Team <team@phalcon.io>
#
# For the full copyright and license information, please view the
# LICENSE.txt file that was distributed with this source code.

# Example of call:
#   tests/run-syntax-tests.sh

set -e

NO_INTERACTION=1
REPORT_EXIT_STATUS=1
TEST_PHP_EXECUTABLE="$(phpenv which php)"
TEST_PHP_ARGS="--show-diff"

export NO_INTERACTION REPORT_EXIT_STATUS TEST_PHP_EXECUTABLE TEST_PHP_ARGS

phpenv config-rm xdebug.ini >/dev/null 2>&1 || true

php ./ext/run-tests.php \
  -d "error_reporting=32767" \
  -d "display_errors=1" \
  -d "display_startup_errors=1" \
  -d "log_errors=0" \
  -d "report_memleaks=1" \
  -d "report_zend_debug=0" \
  -d "zend.assertions=1" \
  -d "extension=psr.so" \
  -d "extension=$(pwd)/ext/modules/phalcon.so" \
  -d extension_dir="$($(phpenv which php-config) --extension-dir)" \
  -p "$TEST_PHP_EXECUTABLE" \
  --show-diff \
  --set-timeout 120 \
  -n \
  ./tests/syntax
