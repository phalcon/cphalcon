#!/usr/bin/env bash
#
# This file is part of the Phalcon.
#
# (c) Phalcon Team <team@phalconphp.com>
#
# For the full copyright and license information, please view
# the LICENSE.txt file that was distributed with this source code.

# rbenv: phpenv: command not found
if [ "$(command -v phpenv 2>/dev/null)" != "" ]
then
  TEST_PHP_EXECUTABLE="$(phpenv which php)"
else
  TEST_PHP_EXECUTABLE="$(command -v php 2>/dev/null)"
fi

NO_INTERACTION=1
REPORT_EXIT_STATUS=1
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
  -d "extension=$(php-config --extension-dir)/psr.so" \
  -d "extension=${TRAVIS_BUILD_DIR}/ext/modules/phalcon.so" \
  --offline \
  --show-diff \
  --set-timeout 120 \
  -n \
  -g "FAIL,XFAIL,SKIP,BORK,WARN,LEAK" \
  ./tests/syntax
