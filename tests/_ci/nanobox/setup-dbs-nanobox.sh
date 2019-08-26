#!/usr/bin/env bash
#
# This file is part of the Phalcon Framework.
#
# (c) Phalcon Team <team@phalcon.io>
#
# For the full copyright and license information, please view the LICENSE.txt
# file that was distributed with this source code.
#

PROJECT_ROOT=$(readlink -enq "$(dirname $0)/../../")

echo -e "Populate MySQL database..."
cat "${PROJECT_ROOT}/_data/assets/db/schemas/mysql_schema.sql" | \
	mysql --user="${DATA_MYSQL_USER}" --host="${DATA_MYSQL_HOST}" --password="${DATA_MYSQL_PASS}" gonano
echo -e "Done\n"

echo -e "Create PostgreSQL database..."
PGPASSWORD="${DATA_POSTGRES_PASS}" \
psql --username="${DATA_POSTGRES_USER}" --host="${DATA_POSTGRES_HOST}"  gonano \
	-q -f "${PROJECT_ROOT}/_data/assets/db/schemas/postgresql_schema_nanobox.sql"
echo -e "Done\n"

echo -e "Create SQLite database..."
sqlite3 "${PROJECT_ROOT}/_output/phalcon_test.sqlite" < \
	"${PROJECT_ROOT}/_data/assets/db/schemas/sqlite_schema.sql"
echo -e "Done\n"

echo -e "Create translations SQLite database..."
sqlite3 "${PROJECT_ROOT}/_output/translations.sqlite" < \
	"${PROJECT_ROOT}/_data/assets/db/schemas/sqlite_translations_schema.sql"
echo -e "Done\n"

wait
