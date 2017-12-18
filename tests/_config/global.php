<?php

return [
    'application' => [
        'baseUri'   => '/',
        'staticUri' => '/',
        'timezone'  => 'UTC',
        'viewsDir'  => PATH_DATA . 'views/',
        'modelsDir' => PATH_DATA . 'models/',
        'modulesDir' => PATH_DATA . 'modules/',
        'resultsetsDir'  => PATH_DATA . 'resultsets/',
        'collectionsDir' => PATH_DATA . 'collections/',
        'controllersDir' => PATH_DATA . 'controllers/',
        'tasksDir' => PATH_DATA . 'tasks/',
        'microDir' => PATH_DATA . 'micro/',
        'aclDir' => PATH_DATA . 'acl/'
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
