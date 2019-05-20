
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Storage;

use Phalcon\Factory\AbstractFactory;
use Phalcon\Storage\Adapter\AbstractAdapter;
use Phalcon\Storage\SerializerFactory;

class AdapterFactory extends AbstractFactory
{
    /**
     * @var <SerializerFactory>
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
    public function newInstance(string! name, array! options = []) -> <AbstractAdapter>
    {
        let options = [
                this->serializerFactory,
                options
            ];

        this->checkService(name, options);

        return this->services[name];
    }

    protected function getAdapters() -> array
    {
        return [
            "apcu"         : "\\Phalcon\\Storage\\Adapter\\Apcu",
            "libmemcached" : "\\Phalcon\\Storage\\Adapter\\Libmemcached",
            "memory"       : "\\Phalcon\\Storage\\Adapter\\Memory",
            "redis"        : "\\Phalcon\\Storage\\Adapter\\Redis",
            "stream"       : "\\Phalcon\\Storage\\Adapter\\Stream"
        ];
    }
}
