<?php

$configMysql = array(
    'host'     => 'localhost',
    'username' => 'phalcon_user',
    'password' => '1234',
    'dbname'   => 'phalcon_test',
);

$configPostgresql = array(
    'host'     => '127.0.0.1',
    'username' => 'phalcon_user',
    'password' => '1234',
    'dbname'   => 'phalcon_test',
    'schema'   => 'public',
);

$configSqlite = array(
    'dbname' => '/tmp/phalcon_test.sqlite',
);
