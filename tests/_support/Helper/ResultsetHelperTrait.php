<?php

namespace Helper;

use Phalcon\Di;
use Phalcon\Mvc\Model\Manager;
use Phalcon\Cache\Backend\File;
use Phalcon\Cache\Frontend\Data;
use Phalcon\Db\Adapter\Pdo\Mysql;
use Phalcon\Cache\Backend\Memcache;
use Phalcon\Cache\BackendInterface;
use Phalcon\Mvc\Model\Metadata\Memory;
use Phalcon\Cache\Backend\Libmemcached;

/**
 * \Helper\ResultsetHelperTrait
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @author    Wojciech Ślawski <jurigag@gmail.com>
 * @package   Phalcon\Test\Unit\Mvc
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
trait ResultsetHelperTrait
{
    protected function setUpEnvironment()
    {
        Di::reset();

        $di = new Di();

        $di->set('modelsManager', Manager::class);
        $di->set('modelsMetadata', Memory::class);

        $di->set('db', function () {
            return new Mysql([
                'host'     => env('TEST_DB_MYSQL_HOST', '127.0.0.1'),
                'username' => env('TEST_DB_MYSQL_USER', 'root'),
                'password' => env('TEST_DB_MYSQL_PASSWD', ''),
                'dbname'   => env('TEST_DB_MYSQL_NAME', 'phalcon_test'),
                'port'     => env('TEST_DB_MYSQL_PORT', 3306),
                'charset'  => env('TEST_DB_MYSQL_CHARSET', 'utf8'),
            ]);
        });

        Di::setDefault($di);
    }

    protected function setUpModelsCache(BackendInterface $driver)
    {
        $di = Di::getDefault();

        $di->set('modelsCache', $driver);
    }

    protected function getFileCache()
    {
        $di = Di::getDefault();
        $cache = new File(new Data(['lifetime' => 3600]), ['cacheDir' => PATH_CACHE]);

        $di->set('modelsCache', $cache);

        return $cache;
    }

    protected function getMemcacheCache()
    {
        if (!extension_loaded('memcache')) {
            throw new \PHPUnit_Framework_SkippedTestError(
                'Warning: memcache extension is not loaded'
            );
        }

        $config = [
            'host' => env('TEST_MC_HOST', '127.0.0.1'),
            'port' => env('TEST_MC_PORT', 11211),
        ];

        $cache = new Memcache(new Data(['lifetime' => 3600]), $config);

        $di = Di::getDefault();
        $di->set('modelsCache', $cache);

        return $cache;
    }

    protected function getLibmemcachedCache()
    {
        if (!extension_loaded('memcached')) {
            throw new \PHPUnit_Framework_SkippedTestError(
                'Warning: memcached extension is not loaded'
            );
        }

        $config = [
            'servers' => [
                [
                    'host'   => env('TEST_MC_HOST', '127.0.0.1'),
                    'port'   => env('TEST_MC_PORT', 11211),
                    'weight' => env('TEST_MC_WEIGHT', 1),
                ]
            ],
        ];

        $cache = new Libmemcached(new Data(['lifetime' => 3600]), $config);

        $di = Di::getDefault();
        $di->set('modelsCache', $cache);

        return $cache;
    }
}
