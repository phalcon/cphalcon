
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
