#!/usr/bin/env bash

source ${TRAVIS_BUILD_DIR}/tests/_ci/install_common.sh

(mysql -uroot -e 'create database phalcon_test charset=utf8mb4 collate=utf8mb4_unicode_ci;' && mysql -uroot phalcon_test < "${TRAVIS_BUILD_DIR}/tests/_data/schemas/mysql/mysql.dump.sql") &
(psql -c 'create database phalcon_test;' -U postgres && psql -U postgres phalcon_test -q -f "${TRAVIS_BUILD_DIR}/tests/_data/schemas/postgresql/phalcon_test.sql") &
sqlite3 /tmp/phalcon_test.sqlite < "${TRAVIS_BUILD_DIR}/tests/_data/schemas/sqlite/phalcon_test.sql"

wait
