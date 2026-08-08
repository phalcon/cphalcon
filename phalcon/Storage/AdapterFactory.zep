
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Storage;

use Exception as BaseException;
use Phalcon\Factory\AbstractFactory;
use Phalcon\Storage\Adapter\AdapterInterface;
use Phalcon\Storage\Adapter\Apcu;
use Phalcon\Storage\Adapter\Libmemcached;
use Phalcon\Storage\Adapter\Memory;
use Phalcon\Storage\Adapter\Redis;
use Phalcon\Storage\Adapter\RedisCluster;
use Phalcon\Storage\Adapter\Stream;
use Phalcon\Storage\Adapter\Weak;
use Throwable;

class AdapterFactory extends AbstractFactory
{
    private <SerializerFactory> serializerFactory;

    /**
     * AdapterFactory constructor.
     */
    public function __construct(<SerializerFactory> factory,  array services = [])
    {
        let this->serializerFactory = factory;

        this->init(services);
    }

    /**
     * Create a new instance of the adapter
     *
     * @param array options = [
     *     'servers' => [
     *         [
     *             'host' => '127.0.0.1',
     *             'port' => 11211,
     *             'weight' => 1
     *         ]
     *     ],
     *     'defaultSerializer' => 'Php',
     *     'lifetime' => 3600,
     *     'serializer' => null,
     *     'prefix' => '',
     *     'host' => '127.0.0.1',
     *     'port' => 6379,
     *     'index' => 0,
     *     'persistent' => false,
     *     'auth' => '',
     *     'socket' => '',
     *     'storageDir' => '',
     * ]
     *
     * @return AdapterInterface
     * @throws BaseException
     */
    public function newInstance( string name,  array options = []) -> <AdapterInterface>
    {
        var definition;

        let definition = this->getService(name);

        return create_instance_params(
            definition,
            [
                this->serializerFactory,
                options
            ]
        );
    }

    /**
     * @return class-string<Throwable>
     */
    protected function getExceptionClass() -> string
    {
        return Exception::class;
    }

    /**
     * Returns the available adapters
     *
     * @return string[]
     */
    protected function getServices() -> array
    {
        return [
            "apcu"         : Apcu::class,
            "libmemcached" : Libmemcached::class,
            "memory"       : Memory::class,
            "redis"        : Redis::class,
            "rediscluster" : RedisCluster::class,
            "stream"       : Stream::class,
            "weak"         : Weak::class
        ];
    }
}
