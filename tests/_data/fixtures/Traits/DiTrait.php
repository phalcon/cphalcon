<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Traits;

use Phalcon\Annotations\Adapter\Memory as AnnotationsMemory;
use Phalcon\Cache\Backend\File;
use Phalcon\Cache\Backend\Libmemcached;
use Phalcon\Cache\Frontend\Data;
use Phalcon\Cli\Console as CliConsole;
use Phalcon\Crypt;
use Phalcon\Db\Adapter\Pdo\Mysql;
use Phalcon\Db\Adapter\Pdo\Postgresql;
use Phalcon\Db\Adapter\Pdo\Sqlite;
use Phalcon\Di;
use Phalcon\Di\FactoryDefault;
use Phalcon\Di\FactoryDefault\Cli as CliFactoryDefault;
use Phalcon\DiInterface;
use Phalcon\Escaper;
use Phalcon\Events\Manager as EventsManager;
use Phalcon\Filter;
use Phalcon\Http\Request;
use Phalcon\Http\Response;
use Phalcon\Mvc\Models\Manager as ModelsManager;
use Phalcon\Mvc\Models\Metadata\Memory as MetadataMemory;
use Phalcon\Mvc\Url;
use Phalcon\Mvc\View;
use Phalcon\Mvc\View\Simple;
use Phalcon\Session\Manager as SessionManager;
use Phalcon\Session\Adapter\Files as SessionFiles;
use function cacheFolder;
use function dataFolder;

/**
 * Trait DiTrait
 *
 * @package Phalcon\Test\Fixtures\Traits
 */
trait DiTrait
{
    /**
     * @var null|DiInterface
     */
    protected $container = null;

    protected function getDi()
    {
        return $this->container;
    }

    protected function getAndSetModelsCacheFile()
    {
        $cache = new File(
            new Data(
                [
                    'lifetime' => 3600,
                ]
            ),
            [
                'cacheDir' => cacheFolder(),
            ]
        );
        $this->container->set('modelsCache', $cache);

        return $cache;
    }

    protected function getAndSetModelsCacheFileLibmemcached()
    {
        $config = [
            'servers' => [
                [
                    'host'   => env('DATA_MEMCACHED_HOST'),
                    'port'   => env('DATA_MEMCACHED_PORT'),
                    'weight' => env('DATA_MEMCACHED_WEIGHT'),
                ],
            ],
        ];

        $cache = new Libmemcached(new Data(['lifetime' => 3600]), $config);
        $this->container->set('modelsCache', $cache);

        return $cache;
    }

    protected function newDi()
    {
        Di::reset();
        $this->container = new Di();
        Di::setDefault($this->container);
    }

    protected function setNewFactoryDefault()
    {
        Di::reset();
        $this->container = $this->newFactoryDefault();
        Di::setDefault($this->container);
    }

    protected function newFactoryDefault()
    {
        return new FactoryDefault();
    }

    protected function setNewCliFactoryDefault()
    {
        Di::reset();
        $this->container = $this->newCliFactoryDefault();
        Di::setDefault($this->container);
    }

    protected function newCliFactoryDefault()
    {
        return new CliFactoryDefault();
    }

    protected function newCliConsole()
    {
        return new CliConsole();
    }

    protected function newEventsManager()
    {
        return new EventsManager();
    }

    protected function newModelsManager()
    {
        return new ModelsManager();
    }

    protected function resetDi()
    {
        Di::reset();
    }

    protected function setCliConsole()
    {
        return $this->container->get('console');
    }

    protected function setDiAnnotations()
    {
        $this->container->set('annotations', new AnnotationsMemory());
    }

    protected function setDiCrypt()
    {
        $this->container->set(
            'crypt',
            function () {
                $crypt = new Crypt();
                $crypt->setKey('cryptkeycryptkey');

                return $crypt;
            }
        );
    }

    protected function setDiEscaper()
    {
        $this->container->set('escaper', Escaper::class);
    }

    protected function setDiEventsManager()
    {
        $this->container->set('eventsManager', EventsManager::class);
    }

    protected function setDiFilter()
    {
        $this->container->set('filter', Filter::class);
    }

    protected function setDiModelsManager()
    {
        $this->container->setShared('modelsManager', ModelsManager::class);
    }

    protected function setDiModelsMetadata()
    {
        $this->container->setShared('modelsMetadata', MetadataMemory::class);
    }

    /**
     * Set up db service (mysql)
     */
    protected function setDiMysql()
    {
        $this->container->setShared('db', $this->newDiMysql());
    }

    /**
     * Set up db service (mysql)
     */
    protected function newDiMysql()
    {
        $options = [
            'host'     => env('DATA_MYSQL_HOST'),
            'username' => env('DATA_MYSQL_USER'),
            'password' => env('DATA_MYSQL_PASS'),
            'dbname'   => env('DATA_MYSQL_NAME'),
            'charset'  => env('DATA_MYSQL_CHARSET'),
        ];

        return new Mysql($options);
    }

    /**
     * Set up db service (Postgresql)
     */
    protected function setDiPostgresql()
    {
        $this->container->set('db', $this->newDiPostgresql());
    }

    /**
     * Set up db service (Postgresql)
     */
    protected function newDiPostgresql()
    {
        $options = [
            'host'     => env('DATA_POSTGRES_HOST'),
            'username' => env('DATA_POSTGRES_USER'),
            'password' => env('DATA_POSTGRES_PASS'),
            'dbname'   => env('DATA_POSTGRES_NAME'),
            'schema'   => env('DATA_POSTGRES_SCHEMA'),
        ];

        return new Postgresql($options);
    }

    protected function setDiResponse()
    {
        $this->container->set('response', Response::class);
    }

    protected function setDiRequest()
    {
        $this->container->set('request', Request::class);
    }

    protected function setDiSession()
    {
        $this->container->set(
            'session',
            function () {
                $manager = new SessionManager();
                $manager->setHandler(new SessionFiles());

                return $manager;
            }
        );
    }

    /**
     * Set up db service (Sqlite)
     */
    protected function setDiSqlite()
    {
        $this->container->set('db', $this->newDiSqlite());
    }

    /**
     * Set up db service (Sqlite)
     */
    protected function newDiSqlite()
    {
        $options = [
            'dbname' => env('DATA_SQLITE_NAME'),
        ];

        return new Sqlite($options);
    }

    protected function setDiUrl()
    {
        $this->container->set(
            'url',
            function () {
                $url = new Url();
                $url->setBaseUri('/');

                return $url;
            }
        );
    }

    protected function setDiView()
    {
        $this->container->set(
            'view',
            function () {
                $view = new View();
                $view->setViewsDir(dataFolder('fixtures/views'));

                return $view;
            }
        );
    }

    protected function setDiViewSimple()
    {
        $this->container->set(
            'viewSimple',
            function () {
                $view = new Simple();
                $view->setViewsDir(dataFolder('fixtures/views/'));

                return $view;
            }
        );
    }

    protected function setupPostgres()
    {
        $this->setNewFactoryDefault();
        $this->setDiPostgresql();

        $this->connection = $this->getService('db');
    }

    protected function getService(string $name)
    {
        return $this->container->get($name);
    }
}
