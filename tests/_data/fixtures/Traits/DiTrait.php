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
use Phalcon\Url;
use Phalcon\Mvc\View;
use Phalcon\Mvc\View\Simple;
use Phalcon\Session\Adapter\Files as SessionFiles;
use Phalcon\Session\Adapter\Libmemcached as SessionLibmemcached;
use Phalcon\Session\Adapter\Noop as SessionNoop;
use Phalcon\Session\Adapter\Redis as SessionRedis;
use Phalcon\Session\Manager as SessionManager;
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

    /**
     * @return DiInterface|null
     */
    protected function getDi()
    {
        return $this->container;
    }

    /**
     * @return File
     */
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

    /**
     * @return Libmemcached
     */
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

    /**
     * Set up a new DI
     */
    protected function newDi()
    {
        Di::reset();
        $this->container = new Di();
        Di::setDefault($this->container);
    }

    /**
     * Set up a new Cli\FactoryDefault
     */
    protected function setNewCliFactoryDefault()
    {
        Di::reset();
        $this->container = $this->newCliFactoryDefault();
        Di::setDefault($this->container);
    }

    /**
     * @return CliFactoryDefault
     */
    protected function newCliFactoryDefault()
    {
        return new CliFactoryDefault();
    }

    /**
     * @return CliConsole
     */
    protected function newCliConsole()
    {
        return new CliConsole();
    }

    /**
     * @return EventsManager
     */
    protected function newEventsManager()
    {
        return new EventsManager();
    }

    /**
     * @return Escaper
     */
    protected function newEscaper()
    {
        return new Escaper();
    }

    /**
     * @return ModelsManager
     */
    protected function newModelsManager()
    {
        return new ModelsManager();
    }

    /**
     * Reset the DI
     */
    protected function resetDi()
    {
        Di::reset();
    }

    /**
     * @return mixed
     */
    protected function setCliConsole()
    {
        return $this->container->get('console');
    }

    /**
     * Setup new Annotations\Memory
     */
    protected function setDiAnnotations()
    {
        $this->container->set('annotations', new AnnotationsMemory());
    }

    /**
     * Setup a new Crypt
     */
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

    /**
     * Setup a new Escaper
     */
    protected function setDiEscaper()
    {
        $this->container->set('escaper', Escaper::class);
    }

    /**
     * Setup a new Events Manager
     */
    protected function setDiEventsManager()
    {
        $this->container->set('eventsManager', EventsManager::class);
    }

    /**
     * Setup a new Filter
     */
    protected function setDiFilter()
    {
        $this->container->set(
            'filter',
            function () {
                $filter = new Filter\FilterLocatorFactory();

                return $filter->newInstance();
            }
        );
    }

    /**
     * Setup a new Models Manager
     */
    protected function setDiModelsManager()
    {
        $this->container->setShared('modelsManager', ModelsManager::class);
    }

    /**
     * Setup a new Models Metadata
     */
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
     * Setup a new Response
     */
    protected function setDiResponse()
    {
        $this->container->set('response', Response::class);
    }

    /**
     * Setup a new Request
     */
    protected function setDiRequest()
    {
        $this->container->set('request', Request::class);
    }

    /**
     * Setup a new Session Manager (Files)
     */
    protected function setDiSessionFiles()
    {
        $this->container->set(
            'session',
            function () {
                $manager = new SessionManager();
                $manager->setHandler(
                    new SessionFiles(
                        [
                            'save_path' => cacheFolder(),
                        ]
                    )
                );

                return $manager;
            }
        );
    }

    /**
     * Setup a new Session Manager (Libmemcached)
     */
    protected function setDiSessionLibmemcached()
    {
        $this->container->set(
            'session',
            function () {
                $manager = new SessionManager();
                $manager->setHandler(
                    new SessionLibmemcached(
                        [
                            'servers' => [
                                [
                                    'host'   => env('DATA_MEMCACHED_HOST'),
                                    'port'   => env('DATA_MEMCACHED_PORT'),
                                    'weight' => env('DATA_MEMCACHED_WEIGHT'),
                                ],
                            ],
                        ]
                    )
                );

                return $manager;
            }
        );
    }

    /**
     * Setup a new Session Manager (Noop)
     */
    protected function setDiSessionNoop()
    {
        $this->container->set(
            'session',
            function () {
                $manager = new SessionManager();
                $manager->setHandler(new SessionNoop());

                return $manager;
            }
        );
    }

    /**
     * Setup a new Session Manager (Redis)
     */
    protected function setDiSessionRedis()
    {
        $this->container->set(
            'session',
            function () {
                $manager = new SessionManager();
                $manager->setHandler(new SessionRedis());

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

    /**
     * Setup a new Url
     */
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

    /**
     * Setup a new View
     */
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

    /**
     * Setup a new View]Simple
     */
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

    /**
     * Setup a new Postgresql connection
     */
    protected function setupPostgres()
    {
        $this->setNewFactoryDefault();
        $this->setDiPostgresql();

        $this->connection = $this->getService('db');
    }

    /**
     * Set up a new FactoryDefault
     */
    protected function setNewFactoryDefault()
    {
        Di::reset();
        $this->container = $this->newFactoryDefault();
        Di::setDefault($this->container);
    }

    /**
     * @return FactoryDefault
     */
    protected function newFactoryDefault()
    {
        return new FactoryDefault();
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

    /**
     * Return a service from the container
     *
     * @param string $name
     *
     * @return mixed
     */
    protected function getService(string $name)
    {
        return $this->container->get($name);
    }
}
