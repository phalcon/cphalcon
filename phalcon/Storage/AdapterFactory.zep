
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
    public function __construct(<SerializerFactory> factory, array! services = [])
    {
        var helpers, name, service;
        
        let this->serializerFactory = factory;

        let helpers = [
            "apcu"         : function (factory, options = []) {
                return new \Phalcon\Storage\Adapter\Apcu(factory, options);
            },
            "libmemcached" : function (factory, options = []) {
                return new \Phalcon\Storage\Adapter\Libmemcached(factory, options);
            },
            "memory"       : function (factory, options = []) {
                return new \Phalcon\Storage\Adapter\Memory(factory, options);
            },
            "redis"        : function (factory, options = []) {
                return new \Phalcon\Storage\Adapter\Redis(factory, options);
            },
            "stream"       : function (factory, options = []) {
                return new \Phalcon\Storage\Adapter\Stream(factory, options);
            }
        ];

        let helpers = array_merge(helpers, services);

        for name, service in helpers {
            let this->mapper[name] = service;
            unset(this->services[name]);
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
                this->services[name] = {definition}(this->serializerFactory, options);
        }

        return this->services[name];
    }
}
