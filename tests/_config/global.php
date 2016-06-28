<?php

return [
    'application' => [
        'baseUri'   => '/',
        'staticUri' => '/',
        'timezone'  => 'UTC',
        'modelsDir' => PATH_DATA . 'models/',
        'collectionsDir' => PATH_DATA . 'collections/',
        'controllersDir' => PATH_DATA . 'controllers/',
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
