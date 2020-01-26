#!/usr/bin/env bash
#
# This file is part of the Phalcon Framework.
#
# (c) Phalcon Team <team@phalcon.io>
#
# For the full copyright and license information, please view the
# LICENSE.txt file that was distributed with this source code.

(>&1 echo "Create MySQL database...")
mysql -u root -e "CREATE DATABASE IF NOT EXISTS phalcon_test charset=utf8mb4 collate=utf8mb4_unicode_ci;"
#mysql -u root phalcon_test < ./tests/_data/assets/db/schemas/mysql_schema.sql
(>&1 echo "Done.")

(>&1 echo "Create PostgreSQL database...")
psql -c 'create database phalcon_test;' -U postgres
#psql -U postgres phalcon_test -q -f ./tests/_data/assets/db/schemas/postgresql_schema.sql
(>&1 echo "Done.")

#(>&1 echo "Create SQLite database...")
#sqlite3 ./tests/_output/phalcon_test.sqlite < ./tests/_data/assets/db/schemas/sqlite_schema.sql
#(>&1 echo "Done.")

#(>&1 echo "Create translations SQLite database...")
#sqlite3 ./tests/_output/translations.sqlite < ./tests/_data/assets/db/schemas/sqlite_translations_schema.sql
#(>&1 echo "Done.")

wait
