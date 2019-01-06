#!/usr/bin/env bash
#
# This file is part of the Phalcon Framework.
#
# (c) Phalcon Team <team@phalconphp.com>
#
# For the full copyright and license information, please view the LICENSE.txt
# file that was distributed with this source code.
#

set -e +o pipefail

PROJECT_ROOT=$(readlink -enq "$(dirname $0)/../../")
LCOV_REPORT=${PROJECT_ROOT}/tests/_output/lcov.info

if [[ -z ${REPORT_COVERAGE+x} ]] || [[ "$REPORT_COVERAGE" != "1" ]]; then
	echo -e "\nUploading coverage data is not enabled.\nSkip uploading reports to Codecov.\n"
	exit 0
fi

if [[ $(command -v lcov 2>/dev/null) = "" ]]; then
	echo -e "lcov does not exist.\nSkip capturing coverage data."
else
	# Capture coverage data
	lcov \
		--quiet \
		--no-checksum \
		--directory ext \
		--base-directory=${PROJECT_ROOT} \
		--capture \
		--compat-libtool \
		--output-file ${LCOV_REPORT}

	# Remove files matching non-project patterns
	lcov \
		--quiet \
		--remove ${LCOV_REPORT} "/usr*" \
		--remove ${LCOV_REPORT} "${PROJECT_ROOT}/kernel/*" \
		--remove ${LCOV_REPORT} "${PROJECT_ROOT}/ext/kernel/*" \
		--remove ${LCOV_REPORT} "${HOME}/.phpenv/*" \
		--compat-libtool \
		--output-file ${LCOV_REPORT}
fi

curl -sSl https://codecov.io/bash -o codecov.sh
chmod +x codecov.sh

if [[ -f "${LCOV_REPORT}" ]]; then
	echo -e "Uploading coverage report: ${LCOV_REPORT}...\n"
	./codecov.sh -f "${LCOV_REPORT}"
fi
