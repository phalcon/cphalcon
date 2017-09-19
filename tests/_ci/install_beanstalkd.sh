#!/usr/bin/env bash
#
#  Phalcon Framework
#
#  Copyright (c) 2011-2017 Phalcon Team (https://www.phalconphp.com)
#
#  This source file is subject to the New BSD License that is bundled
#  with this package in the file LICENSE.txt.
#
#  If you did not receive a copy of the license and are unable to
#  obtain it through the world-wide-web, please send an email
#  to license@phalconphp.com so we can send you a copy immediately.

set -eufo pipefail

CURRENT_DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
TRAVIS_BUILD_DIR="${TRAVIS_BUILD_DIR:-$(dirname $(dirname $CURRENT_DIR))}"

src_url="https://github.com/kr/beanstalkd/archive/v${BEANSTALKD_VERSION}.tar.gz"
BEANSTALKD_DIR=$HOME/beanstalk

# Use Travis cache
if [ ! -f ${BEANSTALKD_DIR}/Makefile ]; then
	curl -sSL "$src_url" | tar xz
	cp -a "./beanstalkd-${BEANSTALKD_VERSION}/." ${BEANSTALKD_DIR}
fi

cd ${BEANSTALKD_DIR}
make --silent -j"$(getconf _NPROCESSORS_ONLN)" &> /dev/null
mv beanstalkd "$HOME/bin"
