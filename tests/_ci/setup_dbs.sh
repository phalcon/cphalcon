#!/usr/bin/env bash

DIR=$(readlink -enq $(dirname $0))

(mysql -uroot -e 'create database phalcon_test charset=utf8mb4 collate=utf8mb4_unicode_ci;' && mysql -uroot phalcon_test < "$DIR/../_data/schemas/mysql/mysql.dump.sql") &
(psql -c 'create database phalcon_test;' -U postgres && psql -U postgres phalcon_test -q -f "$DIR/../_data/schemas/postgresql/phalcon_test.sql") &
sqlite3 /tmp/phalcon_test.sqlite < "$DIR/../_data/schemas/sqlite/phalcon_test.sql"

wait
