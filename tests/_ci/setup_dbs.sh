#!/usr/bin/env bash
#
#  Phalcon Framework
#
#  Copyright (c) 2011-2017 Phalcon Team (https://www.phalconphp.com)
#
#  This source file is subject to the New BSD License that is bundled
#  with this package in the file docs/LICENSE.txt.
#
#  If you did not receive a copy of the license and are unable to
#  obtain it through the world-wide-web, please send an email
#  to license@phalconphp.com so we can send you a copy immediately.

CURRENT_DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
TRAVIS_BUILD_DIR="${TRAVIS_BUILD_DIR:-$(dirname $(dirname $CURRENT_DIR))}"

source ${TRAVIS_BUILD_DIR}/tests/_ci/install_common.sh

(mysql -uroot -e 'create database phalcon_test charset=utf8mb4 collate=utf8mb4_unicode_ci;' && mysql -uroot phalcon_test < "${TRAVIS_BUILD_DIR}/tests/_data/schemas/mysql/mysql.dump.sql") &
(psql -c 'create database phalcon_test;' -U postgres && psql -U postgres phalcon_test -q -f "${TRAVIS_BUILD_DIR}/tests/_data/schemas/postgresql/phalcon_test.sql") &
sqlite3 /tmp/phalcon_test.sqlite < "${TRAVIS_BUILD_DIR}/tests/_data/schemas/sqlite/phalcon_test.sql"

wait
