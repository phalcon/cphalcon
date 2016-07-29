#!/usr/bin/env bash

set -eufo pipefail

BEANSTALKD_VERSION="1.10"
BEANSTALKD_SRC="https://github.com/kr/beanstalkd/archive/v${BEANSTALKD_VERSION}.tar.gz"

if [ -z "${TEST_BT_HOST}" ]; then TEST_BT_HOST="127.0.0.1"; fi
if [ -z "${TEST_BT_PORT}" ]; then TEST_BT_PORT="11300"; fi

mkdir -p "${HOME}/bin"

curl -L "${BEANSTALKD_SRC}" | tar xz
pushd "beanstalkd-${BEANSTALKD_VERSION}"
    make --silent -j4 &> /dev/null
    mv beanstalkd "$HOME/bin"
popd
rm -rf "beanstalkd-${BEANSTALKD_VERSION}"

${HOME}/bin/beanstalkd -l ${TEST_BT_HOST} -p ${TEST_BT_PORT} &
beanstalkd -v
sleep 5
