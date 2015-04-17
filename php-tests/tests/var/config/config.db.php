<?php

if (!file_exists(__DIR__ . '/config.db.local.php')) {
    $configMysql = array(
        'host'     => 'localhost',
        'username' => 'root',
        'password' => 'root',
        'dbname'   => 'phalcon_test'
    );

    $configPostgresql = array(
        'host'     => '127.0.0.1',
        'username' => 'postgres',
        'password' => '',
        'dbname'   => 'phalcon_test',
        'schema'   => 'public'
    );

    $configSqlite = array(
        'dbname' => '/tmp/phalcon_test.sqlite',
    );
}
else {
    require __DIR__ . '/config.db.local.php';
}
