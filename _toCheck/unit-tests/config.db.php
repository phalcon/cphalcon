<?php

if (!file_exists(__DIR__ . '/config.db.local.php')) {

    $configMysql = [
        'host'     => 'localhost',
        'username' => 'root',
        'password' => '',
        'dbname'   => 'phalcon_test',
    ];

    $configPostgresql = [
        'host'     => '127.0.0.1',
        'username' => 'postgres',
        'password' => '',
        'dbname'   => 'phalcon_test',
        'schema'   => 'public',
    ];

    $configSqlite = [
        'dbname' => '/tmp/phalcon_test.sqlite',
    ];
} else {
    require __DIR__ . '/config.db.local.php';
}
