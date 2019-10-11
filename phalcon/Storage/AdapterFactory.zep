
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Storage;

use Phalcon\Factory\AbstractFactory;
use Phalcon\Storage\Adapter\AdapterInterface;

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
     */
    public function newInstance(string! name, array! options = []) -> <AdapterInterface>
    {
        var definition;

        this->checkService(name);

        let definition = this->mapper[name];

        return create_instance_params(
            definition,
            [
                this->serializerFactory,
                options
            ]
        );
    }

    protected function getAdapters() -> array
    {
        return [
            "apcu"         : "Phalcon\\Storage\\Adapter\\Apcu",
            "libmemcached" : "Phalcon\\Storage\\Adapter\\Libmemcached",
            "memory"       : "Phalcon\\Storage\\Adapter\\Memory",
            "redis"        : "Phalcon\\Storage\\Adapter\\Redis",
            "stream"       : "Phalcon\\Storage\\Adapter\\Stream"
        ];
    }
}
