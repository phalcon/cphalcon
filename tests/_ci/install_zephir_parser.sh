#!/usr/bin/env bash

# Ensure that this is being run inside a CI container
if [ "${CI}" != "true" ]; then
    echo "This script is designed to run inside a CI container only. Exiting"
    exit 1
fi

ZEPHIR_PARSER_VERSION=${ZEPHIR_PARSER_VERSION:-development}
PHP_MAJOR=`$(phpenv which php-config) --version | cut -d '.' -f 1,2`

LOCAL_SRC_DIR=${HOME}/.cache/zephir-parser/src
LOCAL_LIB_DIR=${HOME}/.local/lib
LOCAL_LIBRARY=${LOCAL_LIB_DIR}/zephir-parser-${ZEPHIR_PARSER_VERSION}-${PHP_MAJOR}.so

EXTENSION_DIR=`$(phpenv which php-config) --extension-dir`

if [ ! -f ${LOCAL_LIBRARY} ]; then
    mkdir -p ${LOCAL_SRC_DIR}
    mkdir -p ${LOCAL_LIB_DIR}

    rm -rf ${LOCAL_SRC_DIR}/*
    git clone --depth=1 -v https://github.com/phalcon/php-zephir-parser.git -b ${ZEPHIR_PARSER_VERSION} ${LOCAL_SRC_DIR}

    bash ${LOCAL_SRC_DIR}/install

    if [ ! -f "${EXTENSION_DIR}/zephir_parser.so" ]; then
        echo "Unable to locate installed zephir_parser.so"
        exit 1
    fi

    cp "${EXTENSION_DIR}/zephir_parser.so" ${LOCAL_LIBRARY}
fi

echo "[Zephir Parser]" > ${HOME}/.phpenv/versions/$(phpenv version-name)/etc/conf.d/zephir-parser.ini
echo "extension=${LOCAL_LIBRARY}" >> ${HOME}/.phpenv/versions/$(phpenv version-name)/etc/conf.d/zephir-parser.ini

php --ri 'Zephir Parser'
