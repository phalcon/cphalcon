#!/usr/bin/env bash
#
# This file is part of the Phalcon.
#
# (c) Phalcon Team <team@phalconphp.com>
#
# For the full copyright and license information, please view the LICENSE.txt
# file that was distributed with this source code.

php ext/run-tests.php \
	--offline \
	--show-diff \
	--set-timeout 120 \
	-n \
	-g "FAIL,XFAIL,SKIP,BORK,WARN,LEAK" \
	-p $(phpenv which php) \
	tests/syntax
