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

loadIni();
loadAutoloader($root);
loadFolders();
loadDefined();

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
    ]
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

$application = new Application();

$application->setDI($container);

FactoryDefault::setDefault($container);

return $application;
