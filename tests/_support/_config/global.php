<?php

$base = [
    'app_baseUri'     => '/',
    'app_timezone'    => 'UTC',
    'app_db_test'     => [
        'adapter'     => 'Mysql',
        'host'        => 'localhost',
        'username'    => 'root',
        'password'    => '1234',
        'name'        => 'phalcon_test',
        'charset'     => 'utf-8',
    ],
];

$path = [
    'app_path' => [
        'dirs'   => ROOT_PATH . '/_support/',
        'models' => ROOT_PATH . '/_support/_models/',
    ]
];

return array_merge(
    $base,
    $path
);
