
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Storage;

use Phalcon\Storage\Adapter\AbstractAdapter;
use Phalcon\Storage\SerializerFactory;

class AdapterFactory
{
    /**
     * @var array
     */
    private mapper   = [];

    /**
     * @var array
     */
    private services = [];

    /**
     * @var <SerializerFactory>
     */
    private serializerFactory;

    /**
     * AdapterFactory constructor.
     */
    public function __construct(<SerializerFactory> factory = null, array! services = [])
    {
        var adapters, name, service;
        
        let this->serializerFactory = factory;

        let adapters = [
            "apcu"         : "\\Phalcon\\Storage\\Adapter\\Apcu",
            "libmemcached" : "\\Phalcon\\Storage\\Adapter\\Libmemcached",
            "memory"       : "\\Phalcon\\Storage\\Adapter\\Memory",
            "redis"        : "\\Phalcon\\Storage\\Adapter\\Redis",
            "stream"       : "\\Phalcon\\Storage\\Adapter\\Stream"
        ];

        let adapters = array_merge(adapters, services);

        for name, service in adapters {
            let this->mapper[name] = service;
            unset this->services[name];
        }
    }

    /**
     * Create a new instance of the adapter
     */
    public function newInstance(string! name, array! options = []) -> <AbstractAdapter>
    {
        var definition;

        if !isset this->mapper[name] {
            throw new Exception("Service " . name . " is not registered");
        }

        if !isset this->services[name] {
            let definition           = this->mapper[name],
                this->services[name] = new {definition}(this->serializerFactory, options);
        }

        return this->services[name];
    }
}
