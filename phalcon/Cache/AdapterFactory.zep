
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Cache;

use Phalcon\Cache\Adapter\AdapterInterface;
use Phalcon\Cache\Adapter\Apcu;
use Phalcon\Cache\Adapter\Libmemcached;
use Phalcon\Cache\Adapter\Memory;
use Phalcon\Cache\Adapter\Redis;
use Phalcon\Cache\Adapter\RedisCluster;
use Phalcon\Cache\Adapter\Stream;
use Phalcon\Cache\Adapter\Weak;
use Phalcon\Cache\Exception\Exception;
use Phalcon\Contracts\Storage\StorageTypes;
use Phalcon\Factory\AbstractFactory;
use Phalcon\Storage\SerializerFactory;

/**
 * Factory to create Cache adapters
 *
 * @phpstan-import-type storage_adapter_options from StorageTypes
 */
class AdapterFactory extends AbstractFactory
{
    protected <SerializerFactory> serializerFactory;

    /**
     * AdapterFactory constructor.
     *
     * @param array<string, string> $services
     */
    public function __construct(<SerializerFactory> serializerFactory,  array services = [])
    {
        let this->serializerFactory = serializerFactory;

        this->init(services);
    }

    /**
     * Create a new instance of the adapter
     *
     * @param array  $options = [
     *     'servers' => [
     *         [
     *             'host'   => 'localhost',
     *             'port'   => 11211,
     *             'weight' => 1,
     *         ]
     *     ],
     *     'host'              => '127.0.0.1',
     *     'port'              => 6379,
     *     'index'             => 0,
     *     'persistent'        => false,
     *     'auth'              => '',
     *     'socket'            => '',
     *     'defaultSerializer' => 'Php',
     *     'lifetime'          => 3600,
     *     'serializer'        => null,
     *     'prefix'            => 'phalcon',
     *     'storageDir'        => ''
     * ]
     *
     * @phpstan-param storage_adapter_options $options
     *
     * @return AdapterInterface
     * @throws Exception
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
     * @return class-string<\Exception>
     */
    protected function getExceptionClass() -> string
    {
        return Exception::class;
    }

    /**
     * Returns the available adapters
     *
     * @return array<string, string>
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
