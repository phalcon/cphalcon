#!/usr/bin/env bash
#
# This file is part of the Phalcon.
#
# (c) Phalcon Team <team@phalconphp.com>
#
# For the full copyright and license information, please view the LICENSE
# file that was distributed with this source code.

# Ensure that this is being run inside a CI container
if [ "${CI}" != "true" ]; then
	echo "This script is designed to run inside a CI container only. Stop."
	exit 1
fi

CURRENT_DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
TRAVIS_BUILD_DIR="${TRAVIS_BUILD_DIR:-$(dirname $(dirname $CURRENT_DIR))}"

echo -e "Create MySQL database..."
mysql -u root -e "CREATE DATABASE IF NOT EXISTS phalcon_test charset=utf8mb4 collate=utf8mb4_unicode_ci;"
cat "${TRAVIS_BUILD_DIR}/tests/_data/schemas/mysql/phalcon_test.sql" | mysql -u root phalcon_test
echo -e "Done\n"

echo -e "Create PostgreSQL database..."
psql -c 'create database phalcon_test;' -U postgres
psql -U postgres phalcon_test -q -f "${TRAVIS_BUILD_DIR}/tests/_data/schemas/postgresql/phalcon_test.sql"
echo -e "Done\n"

echo -e "Create SQLite database..."
sqlite3 /tmp/phalcon_test.sqlite < "${TRAVIS_BUILD_DIR}/tests/_data/schemas/sqlite/phalcon_test.sql"
echo -e "Done\n"

echo -e "Create translations SQLite database..."
sqlite3 /tmp/translations.sqlite < "${TRAVIS_BUILD_DIR}/tests/_data/schemas/sqlite/translations.sql"
echo -e "Done\n"

wait
