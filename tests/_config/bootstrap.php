<?php

use Phalcon\Config;
use Phalcon\Di\FactoryDefault;
use Phalcon\Loader;
use Phalcon\Mvc\Application;
use Phalcon\Mvc\Dispatcher;
use Phalcon\Mvc\Router;
use Phalcon\Mvc\Url;
use Phalcon\Mvc\View;

$container = new FactoryDefault();

/**
 * Config
 */

$configFile = [
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


$config = new Config($configFile);
$container->setShared('config', $config);

/**
 * View
 */
$container->setShared(
    'view',
    function () use ($configFile) {
        $view = new View();
        $view->setViewsDir($configFile['application']['viewsDir']);

        return $view;
    }
);

/**
 * Autoloader
 */
$loader = new Loader();

// Register the Library namespace as well as the common module
// since it needs to always be available
$namespaces = [
    'Phalcon\Test\Models'                       => $configFile['application']['modelsDir'],
    'Phalcon\Test\Resultsets'                   => $configFile['application']['resultsetsDir'],
    'Phalcon\Test\Objectsets'                   => $configFile['application']['objectsetsDir'],
    'Phalcon\Test\Collections'                  => $configFile['application']['collectionsDir'],
    'Phalcon\Test\Modules\Frontend\Controllers' => $configFile['application']['modulesDir'] . 'frontend/controllers/',
    'Phalcon\Test\Modules\Backend\Controllers'  => $configFile['application']['modulesDir'] . 'backend/controllers/',
    'Phalcon\Test\Acl'                          => $configFile['application']['aclDir'],
    'Phalcon\Test\Debug'                        => $configFile['application']['debugDir'],
];

$loader->registerNamespaces($namespaces);

$loader->registerDirs(
    [
        $configFile['application']['controllersDir'],
        $configFile['application']['tasksDir'],
        $configFile['application']['microDir'],
    ]
);

$loader->register();

$container->setShared('loader', $loader);

/**
 * The URL component is used to generate all kind of urls in the
 * application
 */
$container->setShared(
    'url',
    function () use ($configFile) {
        $url = new Url();

        $url->setStaticBaseUri($configFile['application']['staticUri']);
        $url->setBaseUri($configFile['application']['baseUri']);

        return $url;
    }
);

/**
 * Router
 */
$container->setShared(
    'router',
    function () {
        return new Router(false);
    }
);

/**
 * Dispatcher
 */
$container->set('dispatcher', Dispatcher::class);

/**
 * Initialize the Database connection
 */
$container->set(
    'db',
    function () use ($configFile) {
        $config  = $configFile['database'];
        $adapter = '\Phalcon\Db\Adapter\Pdo\\' . $config['adapter'];

        unset($config['adapter']);

        /** @var \Phalcon\Db\AdapterInterface $connection */
        $connection = new $adapter($config);
        $connection->execute('SET NAMES UTF8', []);

        return $connection;
    }
);

$application = new Application();
$application->setDI($container);

FactoryDefault::setDefault($container);

return $application;
