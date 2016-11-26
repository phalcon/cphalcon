#!/usr/bin/env bash

CFLAGS="-O2 -g3 -fno-strict-aliasing -std=gnu90";

pecl channel-update pecl.php.net

enable_extension() {
    if [ -z $(php -m | grep "${1}") ] && [ -f "${TRAVIS_BUILD_DIR}/tests/_ci/${1}.ini" ]; then
        phpenv config-add "${TRAVIS_BUILD_DIR}/tests/_ci/${1}.ini"
    fi
}

install_extension() {
    INSTALLED=$(pecl list "${1}" | grep 'not installed')
    echo -e $(pecl list "${1}")

    if [ -z "${INSTALLED}" ]; then
        printf "\n" | pecl upgrade "${1}"
    else
        printf "\n" | pecl install "${1}"
    fi

    enable_extension "${1}"
}
