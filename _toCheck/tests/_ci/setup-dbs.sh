#!/usr/bin/env bash
#
# This file is part of the Phalcon.
#
# (c) Phalcon Team <team@phalconphp.com>
#
# For the full copyright and license information, please view the LICENSE.txt
# file that was distributed with this source code.

PROJECT_ROOT=$(readlink -enq "$(dirname $0)/../../")

echo -e "Create MySQL database..."
mysql -u root -e "CREATE DATABASE IF NOT EXISTS phalcon_test charset=utf8mb4 collate=utf8mb4_unicode_ci;"
cat "${PROJECT_ROOT}/tests/_data/schemas/mysql/phalcon_test.sql" | mysql -u root phalcon_test
echo -e "Done\n"

echo -e "Create PostgreSQL database..."
psql -c 'create database phalcon_test;' -U postgres
psql -U postgres phalcon_test -q -f "${PROJECT_ROOT}/tests/_data/schemas/postgresql/phalcon_test.sql"
echo -e "Done\n"

echo -e "Create SQLite database..."
sqlite3 /tmp/phalcon_test.sqlite < "${PROJECT_ROOT}/tests/_data/schemas/sqlite/phalcon_test.sql"
echo -e "Done\n"

echo -e "Create translations SQLite database..."
sqlite3 /tmp/translations.sqlite < "${PROJECT_ROOT}/tests/_data/schemas/sqlite/translations.sql"
echo -e "Done\n"

wait
