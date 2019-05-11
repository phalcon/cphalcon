<?php

return [
    'paths'         => [
        'migrations' => getenv('PHINX_CONFIG_DIR') . 'tests/_data/assets/db/migrations',
        'seeds'      => getenv('PHINX_CONFIG_DIR') . 'tests/_data/assets/db/seeds',
    ],
    'environments'  => [
        'default_migration_table' => 'phinxlog',
        'default_database'        => 'mysql',
        'mysql'                   => [
            'adapter' => 'mysql',
            'host'    => getenv('DATA_MYSQL_HOST'),
            'name'    => 'gonano',
            'user'    => getenv('DATA_MYSQL_USER'),
            'pass'    => getenv('DATA_MYSQL_PASS'),
            'port'    => 3306,
            'charset' => 'utf8',
        ],
        'postgres'                => [
            'adapter' => 'pgsql',
            'host'    => getenv('DATA_POSTGRES_HOST'),
            'name'    => 'gonano',
            'user'    => getenv('DATA_POSTGRES_USER'),
            'pass'    => getenv('DATA_POSTGRES_PASS'),
//            'port'    => 3306,
            'charset' => 'utf8',
        ],
        'sqlite'                  => [
            'adapter' => 'sqlite',
            'name'    => getenv('PHINX_CONFIG_DIR') . 'tests/_data/assets/db/phalcon',
            'suffix'  => '.db',
        ],
    ],
    'version_order' => 'creation',
];
