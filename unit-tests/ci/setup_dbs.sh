#! /bin/sh

DIR=$(readlink -enq $(dirname $0))

(mysql -uroot -e 'create database phalcon_test charset=utf8 collate=utf8_unicode_ci;' && mysql -uroot phalcon_test < "$DIR/../schemas/mysql/phalcon_test.sql") &
(psql -c 'create database phalcon_test;' -U postgres && psql -U postgres phalcon_test -q -f "$DIR/../schemas/postgresql/phalcon_test.sql") &
sqlite3 /tmp/phalcon_test.sqlite < "$DIR/../schemas/sqlite/phalcon_test.sql"
wait
