<?php

declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Traits;

use IntegrationTester;
use PDO;
use Phalcon\Db\Adapter\PdoFactory;
use function dataDir;
use function getOptionsLibmemcached;
use function getOptionsModelCacheStream;
use function getOptionsMysql;
use function getOptionsPostgresql;
use function getOptionsRedis;
use function getOptionsSqlite;
use Phalcon\Annotations\Adapter\Memory as AnnotationsMemory;
use Phalcon\Cache\Adapter\Libmemcached as StorageLibmemcached;
use Phalcon\Cache\Adapter\Stream as StorageStream;
use Phalcon\Cli\Console as CliConsole;
use Phalcon\Crypt;
use Phalcon\Db\Adapter\Pdo\Mysql;
use Phalcon\Db\Adapter\Pdo\Postgresql;
use Phalcon\Db\Adapter\Pdo\Sqlite;
use Phalcon\Di;
use Phalcon\Di\FactoryDefault;
use Phalcon\Di\FactoryDefault\Cli as CliFactoryDefault;
use Phalcon\Di\DiInterface;
use Phalcon\Escaper;
use Phalcon\Events\Manager as EventsManager;
use Phalcon\Filter;
use Phalcon\Http\Request;
use Phalcon\Http\Response;
use Phalcon\Mvc\Model\Manager as ModelsManager;
use Phalcon\Mvc\Model\Metadata\Memory as MetadataMemory;
use Phalcon\Mvc\View;
use Phalcon\Mvc\View\Simple;
use Phalcon\Session\Adapter\Libmemcached as SessionLibmemcached;
use Phalcon\Session\Adapter\Noop as SessionNoop;
use Phalcon\Session\Adapter\Redis as SessionRedis;
use Phalcon\Session\Adapter\Stream as SessionFiles;
use Phalcon\Session\Manager as SessionManager;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Url;

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

    protected function newCliConsole(): CliConsole
    {
        return new CliConsole();
    }

    protected function newCliFactoryDefault(): CliFactoryDefault
    {
        return new CliFactoryDefault();
    }

    protected function setDatabase(IntegrationTester $I)
    {
        /** @var PDO $connection */
        $connection = $I->getConnection();
        $driver     = $connection->getAttribute(PDO::ATTR_DRIVER_NAME);
        $service    = $driver;
        switch ($driver) {
            case 'mysql':
                $options = getOptionsMysql();
                break;
            case 'pgsql':
                $options = getOptionsPostgresql();
                $service = 'postgresql';
                break;
            case 'sqlite':
                $options = getOptionsSqlite();
                break;
            case 'sqlsrv':
            default:
                $options = [];
        }

        $db = (new PdoFactory())->newInstance($service, $options);
        $this->container->setShared('db', $db);
    }

    protected function newFactoryDefault(): FactoryDefault
    {
        return new FactoryDefault();
    }

    /**
     * Set up a new Cli\FactoryDefault
     */
    protected function setNewCliFactoryDefault()
    {
        FactoryDefault::reset();//Di::reset();
        $this->container = $this->newCliFactoryDefault();
        FactoryDefault::setDefault($this->container);
        //Di::setDefault($this->container);
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

//------------------------------------------------------------------------------
    protected function getAndSetModelsCacheStream(): StorageStream
    {
        $serializer = new SerializerFactory();

        $cache = new StorageStream(
            $serializer,
            getOptionsModelCacheStream()
        );

        $this->container->set('modelsCache', $cache);

        return $cache;
    }

    protected function getAndSetViewCacheStream(): StorageStream
    {
        $serializer = new SerializerFactory();

        $cache = new StorageStream(
            $serializer,
            getOptionsModelCacheStream()
        );

        $this->container->set('viewCache', $cache);

        return $cache;
    }

    protected function getAndSetModelsCacheLibmemcached(): StorageLibmemcached
    {
        $serializer = new SerializerFactory();

        $cache = new StorageLibmemcached(
            $serializer,
            getOptionsLibmemcached()
        );

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

    protected function newEventsManager(): EventsManager
    {
        return new EventsManager();
    }

    protected function newEscaper(): Escaper
    {
        return new Escaper();
    }

    protected function newModelsManager(): ModelsManager
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

    protected function setCliConsole()
    {
        return $this->container->get('console');
    }

    /**
     * Setup new Annotations\Memory
     */
    protected function setDiAnnotations()
    {
        $this->container->set(
            'annotations',
            new AnnotationsMemory()
        );
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
                $filter = new Filter\FilterFactory();

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
        $this->container->setShared(
            'db',
            $this->newDiMysql()
        );
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

                $manager->setAdapter(
                    new SessionFiles(
                        getOptionsSessionStream()
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

                $manager->setAdapter(
                    new SessionLibmemcached(
                        getOptionsLibmemcached()
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

                $manager->setAdapter(
                    new SessionNoop()
                );

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

                $manager->setAdapter(
                    new SessionRedis(
                        getOptionsRedis()
                    )
                );

                return $manager;
            }
        );
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

                $view->setViewsDir(
                    dataDir('fixtures/views')
                );

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

                $view->setViewsDir(
                    dataDir('fixtures/views/')
                );

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
     * Set up db service (Postgresql)
     */
    protected function setDiPostgresql()
    {
        $this->container->set(
            'db',
            $this->newDiPostgresql()
        );
    }

    /**
     * Return a service from the container
     */
    protected function getService(string $name)
    {
        return $this->container->get($name);
    }
}
