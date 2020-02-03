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

use DatabaseTester;
use PDO;
use Phalcon\Annotations\Adapter\Memory as AnnotationsMemory;
use Phalcon\Cache\Adapter\Libmemcached as StorageLibmemcached;
use Phalcon\Cache\Adapter\Stream as StorageStream;
use Phalcon\Cli\Console;
use Phalcon\Cli\Console as CliConsole;
use Phalcon\Crypt;
use Phalcon\Db\Adapter\AdapterInterface;
use Phalcon\Db\Adapter\PdoFactory;
use Phalcon\Di;
use Phalcon\Di\DiInterface;
use Phalcon\Di\FactoryDefault;
use Phalcon\Di\FactoryDefault\Cli as CliFactoryDefault;
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
use Phalcon\Session\Adapter\Stream as SessionStream;
use Phalcon\Session\Manager;
use Phalcon\Session\Manager as SessionManager;
use Phalcon\Storage\AdapterFactory as StorageAdapterFactory;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Url;

use function getOptionsLibmemcached;
use function getOptionsMysql;
use function getOptionsPostgresql;
use function getOptionsRedis;
use function getOptionsSessionStream;
use function getOptionsSqlite;

/**
 * Trait DiTrait
 *
 * @property null|DiInterface $container
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

    /**
     * @return CliConsole
     */
    protected function newCliConsole(): CliConsole
    {
        return new CliConsole();
    }

    /**
     * @return CliFactoryDefault
     */
    protected function newCliFactoryDefault(): CliFactoryDefault
    {
        return new CliFactoryDefault();
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
     * @param DatabaseTester $I
     *
     * @return AdapterInterface
     */
    protected function newDbService(DatabaseTester $I): AdapterInterface
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

        return (new PdoFactory())->newInstance($service, $options);
    }

    /**
     * @param string $service
     *
     * @return mixed|null
     */
    protected function newService(string $service)
    {
        switch ($service) {
            case 'annotations':
                return new AnnotationsMemory();
            case 'console':
                return new Console();
            case 'crypt':
                return new Crypt();
            case 'eventsManager':
                return new EventsManager();
            case 'escaper':
                return new Escaper();
            case 'filter':
                return (new Filter\FilterFactory())->newInstance();
            case 'metadataMemory':
                return new MetadataMemory();
            case 'modelsManager':
                return new ModelsManager();
            case 'request':
                return new Request();
            case 'response':
                return new Response();
            case 'sessionStream':
                return new SessionStream(getOptionsSessionStream());
            case 'sessionLibmemcached':
                return new SessionLibmemcached(
                    new StorageAdapterFactory(
                        new SerializerFactory()
                    ),
                    getOptionsLibmemcached()
                );
            case 'sessionNoop':
                return new SessionNoop();
            case 'sessionRedis':
                return new SessionRedis(
                    new StorageAdapterFactory(
                        new SerializerFactory()
                    ),
                    getOptionsRedis()
                );
            case 'url':
                return new Url();
            case 'view':
                return new View();
            case 'viewSimple':
                return new Simple();
            default:
                return null;
        }
    }

    /**
     * Reset the DI
     */
    protected function resetDi()
    {
        Di::reset();
    }

    /**
     * @param DatabaseTester $I
     */
    protected function setDatabase(DatabaseTester $I)
    {
        $db = $this->newDbService($I);

        $this->container->setShared('db', $db);
    }

    /**
     * @param string $service
     */
    protected function setDiService(string $service)
    {
        $class = $this->newService($service);
        switch ($service) {
            case 'console':
            case 'annotations':
            case 'filter':
            case 'modelsManager':
            case 'modelsMetadata':
            case 'escaper':
            case 'eventsManager':
            case 'request':
            case 'response':
                $this->container->set($service, $class);
                break;
            case 'crypt':
                $this->container->set(
                    'crypt',
                    function () use ($class) {
                        $class->setKey('cryptkeycryptkey');

                        return $class;
                    }
                );
                break;

            case 'sessionStream':
            case 'sessionLibmemcached':
            case 'sessionNoop':
            case 'sessionRedis':
                $this->container->set(
                    'session',
                    function () use ($class) {
                        return (new Manager())->setAdapter($class);
                    }
                );
                break;

            case 'url':
                $this->container->set(
                    $service,
                    function () use ($class) {
                        $class->setBaseUri('/');

                        return $class;
                    }
                );
                break;
            case 'view':
            case 'viewSimple':
                $this->container->set(
                    $service,
                    function () use ($class) {
                        $class->setViewsDir(dataDir('fixtures/views/'));

                        return $class;
                    }
                );
                break;

            default:
                break;
        }
    }

    /**
     * @return FactoryDefault
     */
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
//    protected function getAndSetModelsCacheStream(): StorageStream
//    {
//        $serializer = new SerializerFactory();
//
//        $cache = new StorageStream(
//            $serializer,
//            getOptionsModelCacheStream()
//        );
//
//        $this->container->set('modelsCache', $cache);
//
//        return $cache;
//    }
//
//    protected function getAndSetViewCacheStream(): StorageStream
//    {
//        $serializer = new SerializerFactory();
//
//        $cache = new StorageStream(
//            $serializer,
//            getOptionsModelCacheStream()
//        );
//
//        $this->container->set('viewCache', $cache);
//
//        return $cache;
//    }
//
//    protected function getAndSetModelsCacheLibmemcached(): StorageLibmemcached
//    {
//        $serializer = new SerializerFactory();
//
//        $cache = new StorageLibmemcached(
//            $serializer,
//            getOptionsLibmemcached()
//        );
//
//        $this->container->set('modelsCache', $cache);
//
//        return $cache;
//    }
//
//    /**
//     * Set up db service (mysql)
//     */
//    protected function setDiMysql()
//    {
//        $this->container->setShared(
//            'db',
//            $this->newDiMysql()
//        );
//    }
//
//    /**
//     * Setup a new Session Manager (Libmemcached)
//     */
//    protected function setDiSessionLibmemcached()
//    {
//        $this->container->set(
//            'session',
//            function () {
//                $manager = new SessionManager();
//
//                $manager->setAdapter(
//                    new SessionLibmemcached(
//                        getOptionsLibmemcached()
//                    )
//                );
//
//                return $manager;
//            }
//        );
//    }
//
//    /**
//     * Setup a new Session Manager (Noop)
//     */
//    protected function setDiSessionNoop()
//    {
//        $this->container->set(
//            'session',
//            function () {
//                $manager = new SessionManager();
//
//                $manager->setAdapter(
//                    new SessionNoop()
//                );
//
//                return $manager;
//            }
//        );
//    }
//
//    /**
//     * Setup a new Session Manager (Redis)
//     */
//    protected function setDiSessionRedis()
//    {
//        $this->container->set(
//            'session',
//            function () {
//                $manager = new SessionManager();
//
//                $manager->setAdapter(
//                    new SessionRedis(
//                        getOptionsRedis()
//                    )
//                );
//
//                return $manager;
//            }
//        );
//    }
//
//    /**
//     * Setup a new Postgresql connection
//     */
//    protected function setupPostgres()
//    {
//        $this->setNewFactoryDefault();
//        $this->setDiPostgresql();
//
//        $this->connection = $this->getService('db');
//    }
//
//    /**
//     * Set up db service (Postgresql)
//     */
//    protected function setDiPostgresql()
//    {
//        $this->container->set(
//            'db',
//            $this->newDiPostgresql()
//        );
//    }
}
