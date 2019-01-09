#!/usr/bin/env bash
#
# This file is part of the Phalcon Framework.
#
# (c) Phalcon Team <team@phalconphp.com>
#
# For the full copyright and license information, please view the
# LICENSE.txt file that was distributed with this source code.

PROJECT_ROOT=$(cd "$(dirname $0)/../"; pwd -P)

export NO_INTERACTION=1
export REPORT_EXIT_STATUS=1
export TEST_PHP_EXECUTABLE=$(phpenv which php)

phpenv config-rm xdebug.ini || true
php ${PROJECT_ROOT}/ext/run-tests.php \
	-d "extension=$(php-config --extension-dir)/psr.so" \
	-d "extension=${PROJECT_ROOT}/ext/modules/phalcon.so" \
	--offline \
	--show-diff \
	--set-timeout 120 \
	-n \
	-g "FAIL,XFAIL,SKIP,BORK,WARN,LEAK" \
	${PROJECT_ROOT}/tests/syntax
