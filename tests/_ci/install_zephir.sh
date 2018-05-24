#!/usr/bin/env bash
#
#  Phalcon Framework
#
#  Copyright (c) 2011-present Phalcon Team (https://www.phalconphp.com)
#
#  This source file is subject to the New BSD License that is bundled
#  with this package in the file LICENSE.txt.
#
#  If you did not receive a copy of the license and are unable to
#  obtain it through the world-wide-web, please send an email
#  to license@phalconphp.com so we can send you a copy immediately.

CURRENT_DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
TRAVIS_BUILD_DIR="${TRAVIS_BUILD_DIR:-$(dirname $(dirname $CURRENT_DIR))}"
ZEPHIRDIR=${TRAVIS_BUILD_DIR}/vendor/phalcon/zephir

if [ ! -d "${ZEPHIRDIR}" ]; then
  echo -e "The ${ZEPHIRDIR} directory does not exists. First run 'composer install --dev'"
  exit 1;
fi

cd ${ZEPHIRDIR}

sed "s#%ZEPHIRDIR%#$ZEPHIRDIR#g" bin/zephir > bin/zephir-cmd
chmod 755 bin/zephir-cmd

mkdir -p ${HOME}/bin

cp ./bin/zephir-cmd ${HOME}/bin/zephir
rm ./bin/zephir-cmd

cd ${TRAVIS_BUILD_DIR}


zephir version
