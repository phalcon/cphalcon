
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
use Phalcon\Cache\Exception\Exception;
use Phalcon\Factory\AbstractFactory;
use Phalcon\Storage\SerializerFactory;

/**
 * Factory to create Cache adapters
 */
class AdapterFactory extends AbstractFactory
{
    /**
     * @var SerializerFactory
     */
    private serializerFactory;

    /**
     * AdapterFactory constructor.
     */
    public function __construct(<SerializerFactory> factory = null, array! services = [])
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
     *             'host' => 'localhost',
     *             'port' => 11211,
     *             'weight' => 1,
     *         ]
     *     ],
     *     'host' => '127.0.0.1',
     *     'port' => 6379,
     *     'index' => 0,
     *     'persistent' => false,
     *     'auth' => '',
     *     'socket' => '',
     *     'defaultSerializer' => 'Php',
     *     'lifetime' => 3600,
     *     'serializer' => null,
     *     'prefix' => 'phalcon',
     *     'storageDir' => ''
     * ]
     */
    public function newInstance(string! name, array! options = []) -> <AdapterInterface>
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
     * Returns the available adapters
     */
    protected function getAdapters() -> array
    {
        return [
            "apcu"         : "Phalcon\\Cache\\Adapter\\Apcu",
            "libmemcached" : "Phalcon\\Cache\\Adapter\\Libmemcached",
            "memory"       : "Phalcon\\Cache\\Adapter\\Memory",
            "redis"        : "Phalcon\\Cache\\Adapter\\Redis",
            "stream"       : "Phalcon\\Cache\\Adapter\\Stream"
        ];
    }
}
