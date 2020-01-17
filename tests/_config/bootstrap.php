<?php

use Codeception\Lib\Connector\Phalcon\MemorySession as CodeceptionMemorySession;
use Phalcon\Config;
use Phalcon\Di\FactoryDefault;
use Phalcon\Loader;
use Phalcon\Mvc\Application;
use Phalcon\Mvc\Dispatcher;
use Phalcon\Mvc\Router;
use Phalcon\Mvc\View;
use Phalcon\Test\Fixtures\MemorySession as PhalconMemorySession;
use Phalcon\Url;

$container = new FactoryDefault();

/**
 * Load environment
 */
$root = dirname(dirname(__DIR__)) . DIRECTORY_SEPARATOR;

loadEnvironment($root);

/**
 * Config
 */
$configFile = [
    'application' => [
        'baseUri'        => '/',
        'staticUri'      => '/',
        'timezone'       => 'UTC',
        'controllersDir' => $root . 'tests/_data/fixtures/controllers/',
        'modelsDir'      => $root . 'tests/_data/fixtures/models/',
        'modulesDir'     => $root . 'tests/_data/fixtures/modules/',
        'viewsDir'       => $root . 'tests/_data/fixtures/views/',
        'resultsetsDir'  => $root . 'tests/_data/fixtures/resultsets/',
        'tasksDir'       => $root . 'tests/_data/fixtures/tasks/',
        //        'microDir'       => $root . 'tests/_data/micro/',
        //        'objectsetsDir'  => $root . 'tests/_data/objectsets/',
        //        'debugDir'       => $root . 'tests/_data/debug/',
        //        'collectionsDir' => $root . 'tests/_data/collections/',
        //        'aclDir'         => $root . 'tests/_data/acl/',
    ],
    'database'    => [
        'adapter'  => 'Mysql',
        'host'     => env('DATA_MYSQL_HOST'),
        'username' => env('DATA_MYSQL_USER'),
        'password' => env('DATA_MYSQL_PASS'),
        'dbname'   => env('DATA_MYSQL_NAME'),
        'port'     => env('DATA_MYSQL_PORT'),
        'charset'  => env('DATA_MYSQL_CHARSET'),
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

        $view->setViewsDir(
            $configFile['application']['viewsDir']
        );

        return $view;
    }
);

///**
// * Autoloader
// */
//$loader = new Loader();
//
//// Register the Library namespace as well as the common module
//// since it needs to always be available
//$namespaces = [
//    'Phalcon\Test\Controllers'                  => $configFile['application']['controllersDir'],
//    'Phalcon\Test\Models'                       => $configFile['application']['modelsDir'],
//    'Phalcon\Test\Resultsets'                   => $configFile['application']['resultsetsDir'],
//    'Phalcon\Test\Modules\Frontend\Controllers' => $configFile['application']['modulesDir'] . 'frontend/controllers/',
//    'Phalcon\Test\Modules\Backend\Controllers'  => $configFile['application']['modulesDir'] . 'backend/controllers/',
//    'Phalcon\Test\Tasks'                        => $configFile['application']['tasksDir'],
//    //    'Phalcon\Test\Acl'                          => $configFile['application']['aclDir'],
//    //    'Phalcon\Test\Collections'                  => $configFile['application']['collectionsDir'],
//    //    'Phalcon\Test\Debug'                        => $configFile['application']['debugDir'],
//    //    'Phalcon\Test\Objectsets'                   => $configFile['application']['objectsetsDir'],
//];
//
//$loader->registerNamespaces($namespaces);
//
//$loader->registerDirs(
//    [
//        $configFile['application']['tasksDir'],
//        $configFile['application']['controllersDir'],
//        //        $configFile['application']['microDir'],
//    ]
//);
//
//$loader->register();
//
//$container->setShared('loader', $loader);

/**
 * The URL component is used to generate all kind of urls in the
 * application
 */
$container->setShared(
    'url',
    function () use ($configFile) {
        $url = new Url();

        $url->setStaticBaseUri(
            $configFile['application']['staticUri']
        );

        $url->setBaseUri(
            $configFile['application']['baseUri']
        );

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
 * Session
 */
$container->set(
    CodeceptionMemorySession::class,
    PhalconMemorySession::class
);

$application = new Application();

$application->setDI($container);

FactoryDefault::setDefault($container);

return $application;
