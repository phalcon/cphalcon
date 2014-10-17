<?php

namespace PhalconTest;

use \Phalcon\DI\FactoryDefault as PhDI;
use \Phalcon\Config as PhConfig;
use \Phalcon\Mvc\Url as PhUrl;
use \Phalcon\Mvc\Router as PhRouter;
use \Phalcon\Mvc\Dispatcher as PhDispatcher;
use \Phalcon\Db\Adapter\Pdo\Mysql as PhMysql;
use \Phalcon\Loader as PhLoader;
use \Phalcon\Mvc\Application as PhApplication;

$di  = new PhDI();

/**
 * Config file
 */
$configFile  = require(ROOT_PATH . '/_support/_config/global.php');
$di->set(
    'config',
    function () use ($configFile) {
        return new PhConfig($configFile);
    },
    true
);

/**
 * Autoloader
 */
$di->set(
    'loader',
    function () use ($di) {

        $config = $di['config'];
        $loader = new PhLoader();

        $loader->registerDirs(
            [$config->app_path->dirs]
        );

        // Register the Library namespace as well as the common module
        // since it needs to always be available
        $loader->registerNamespaces(
            ['PhalconTest\Models' => $config->app_path->models]
        );

        $loader->register();
    }
);

/**
 * The URL component is used to generate all kind of urls in the
 * application
 */
$di->set(
    'url',
    function () use ($di) {

        $config = $di['config'];

        $url = new PhUrl();
        $url->setBaseUri($config->app_baseUri);

        return $url;
    },
    true
);

/**
 * Router
 */
$di->set(
    'router',
    function () {

        $router = new PhRouter(false);
        return $router;
    },
    true
);

/**
 * Dispatcher
 */
$di->set(
    'dispatcher',
    function () use ($di) {
        $dispatcher = new PhDispatcher();
        return $dispatcher;
    }
);

/**
 * Db
 */
$di->set(
    'db',
    function () use ($di) {

        $config = $di['config'];

        $params = [
            "host"     => $config->app_db_test->host,
            "username" => $config->app_db_test->username,
            "password" => $config->app_db_test->password,
            "dbname"   => $config->app_db_test->dbname,
            "charset"  => $config->app_db_test->charset,
        ];

        $adapter = $config->app_db_test->adapter;
        $conn = new $adapter();

        // Set everything to UTF8
        $conn->execute('SET NAMES UTF8', []);

        return $conn;
    }
);

$application = new PhApplication();
$application->setDI($di);

PhDI::setDefault($di);

return $application;
