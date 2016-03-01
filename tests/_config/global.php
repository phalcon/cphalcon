<?php

return [
    'application' => [
        'baseUri'   => '/',
        'staticUri' => '/',
        'timezone'  => 'UTC',
        'modelsDir' => TESTS_PATH . '_data/models/',
    ],
    'database' => [
        'adapter'  => 'Mysql',
        'host'     => TEST_DB_MYSQL_HOST,
        'username' => TEST_DB_MYSQL_USER,
        'password' => TEST_DB_MYSQL_PASSWD,
        'dbname'   => TEST_DB_MYSQL_NAME,
        'port'     => TEST_DB_MYSQL_PORT,
        'charset'  => TEST_DB_MYSQL_CHARSET,
    ],
];
