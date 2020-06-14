<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Fixtures\Traits;

use DatabaseTester;
use PDO;
use Phalcon\Annotations\Adapter\Memory as AnnotationsMemory;
use Phalcon\Cache\Adapter\Libmemcached as StorageLibmemcached;
use Phalcon\Cache\Adapter\Stream as StorageStream;
use Phalcon\Cli\Console;
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
use Phalcon\Storage\AdapterFactory as StorageAdapterFactory;
use Phalcon\Storage\Exception;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Url;

use function getOptionsLibmemcached;
use function getOptionsModelCacheStream;
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
     * @param string $driver
     *
     * @return AdapterInterface
     */
    protected function newDbConnection(string $driver): AdapterInterface
    {
        switch ($driver) {
            case 'mysql':
                $options = getOptionsMysql();
                break;
            case 'pgsql':
                $options = getOptionsPostgresql();
                $driver = 'postgresql';
                break;
            case 'sqlite':
                $options = getOptionsSqlite();
                break;
            case 'sqlsrv':
            default:
                $options = [];
        }

        $options['options'][PDO::ATTR_TIMEOUT] = 0;

        return (new PdoFactory())->newInstance($driver, $options);
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

        return $this->newDbConnection($driver);
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
     * @param string     $service
     * @param mixed|null $options
     *
     * @return mixed|null
     * @throws Exception
     */
    protected function newService(string $service, $options = null)
    {
        switch ($service) {
            case 'annotations':
                return new AnnotationsMemory();
            case 'cliFactoryDefault':
                return new CliFactoryDefault();
            case 'console':
                return new Console($options);
            case 'crypt':
                return new Crypt();
            case 'eventsManager':
                return new EventsManager();
            case 'escaper':
                return new Escaper();
            case 'factoryDefault':
                return new FactoryDefault();
            case 'filter':
                return (new Filter\FilterFactory())->newInstance();
            case 'metadataMemory':
                return new MetadataMemory();
            case 'modelsCacheLibmemcached':
                return new StorageLibmemcached(
                    new SerializerFactory(),
                    getOptionsLibmemcached()
                );
            case 'modelsCacheStream':
                return new StorageStream(
                    new SerializerFactory(),
                    getOptionsModelCacheStream()
                );
            case 'modelsManager':
                return new ModelsManager();
            case 'phpSerializer':
                return (new SerializerFactory())->newInstance('php');
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
     *
     * @throws Exception
     */
    protected function setDiService(string $service)
    {
        $class = $this->newService($service);
        switch ($service) {
            case 'annotations':
            case 'console':
            case 'escaper':
            case 'eventsManager':
            case 'filter':
            case 'modelsManager':
            case 'modelsMetadata':
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

            case 'modelsCacheLibmemcached':
            case 'modelsCacheStream':
                $this->container->set('modelsCache', $class);
                break;

            case 'phpSerializer':
                $this->container->set('serializer', $class);
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
     * Set up a new Cli\FactoryDefault
     *
     * @throws Exception
     */
    protected function setNewCliFactoryDefault()
    {
        FactoryDefault::reset();
        $this->container = $this->newService('cliFactoryDefault');
        FactoryDefault::setDefault($this->container);
    }

    /**
     * Set up a new FactoryDefault
     *
     * @throws Exception
     */
    protected function setNewFactoryDefault()
    {
        Di::reset();
        $this->container = $this->newService('factoryDefault');
        Di::setDefault($this->container);
    }
}
