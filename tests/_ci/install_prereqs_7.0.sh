#!/usr/bin/env bash

source ${TRAVIS_BUILD_DIR}/tests/_ci/install_common.sh
source ${TRAVIS_BUILD_DIR}/tests/_ci/install_php_7.sh

install_extension imagick
enable_extension memcached

install_apcu
install_apcu_bc
phpenv config-add "${TRAVIS_BUILD_DIR}/tests/_ci/apc_bc.ini"

printf "\n" | pecl install yaml-2.0.0 &> /dev/null

install_igbinary
