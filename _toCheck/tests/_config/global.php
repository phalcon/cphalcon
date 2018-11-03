<?php

return [
    'application' => [
        'baseUri'        => '/',
        'staticUri'      => '/',
        'timezone'       => 'UTC',
        'debugDir'       => __DIR__ . '/../_data/debug/',
        'viewsDir'       => __DIR__ . '/../_data/views/',
        'modelsDir'      => __DIR__ . '/../_data/models/',
        'modulesDir'     => __DIR__ . '/../_data/modules/',
        'resultsetsDir'  => __DIR__ . '/../_data/resultsets/',
        'objectsetsDir'  => __DIR__ . '/../_data/objectsets/',
        'collectionsDir' => __DIR__ . '/../_data/collections/',
        'controllersDir' => __DIR__ . '/../_data/controllers/',
        'tasksDir'       => __DIR__ . '/../_data/tasks/',
        'microDir'       => __DIR__ . '/../_data/micro/',
        'aclDir'         => __DIR__ . '/../_data/acl/'
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
