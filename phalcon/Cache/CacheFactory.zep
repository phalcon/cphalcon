
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Cache;

use Phalcon\Cache\Adapter\AdapterInterface;
use Phalcon\Cache\AdapterFactory;
use Phalcon\Cache\Cache;
use Phalcon\Cache\CacheInterface;
use Phalcon\Cache\Exception\Exception;
use Phalcon\Config\Config;
use Phalcon\Factory\AbstractFactory;
use Phalcon\Helper\Arr;

/**
 * Phalcon\CacheFactory
 *
 * Creates a new Cache class
 */
class CacheFactory
{
    /**
     * @var <AdapterFactory>
     */
    protected adapterFactory;

    /**
     * Constructor
     */
    public function __construct(<AdapterFactory> factory)
    {
        let this->adapterFactory = factory;
    }

    /**
     * Factory to create an instace from a Config object
     */
    public function load(var config) -> var
    {
        var name, options;

        if typeof config == "object" && config instanceof Config {
            let config = config->toArray();
        }

        if unlikely typeof config !== "array" {
            throw new Exception(
                "Config must be array or Phalcon\\Config object"
            );
        }

        if unlikely !isset config["adapter"] {
            throw new Exception(
                "You must provide 'adapter' option in factory config parameter."
            );
        }

        let name    = config["adapter"],
            options = Arr::get(config, "options", []);

        return this->newInstance(name, options);
    }

    /**
     * Constructor.
     *
     * @param AdapterInterface  adapter The cache adapter
     */
    public function newInstance(string! name, array! options = []) -> <CacheInterface>
    {
        var adapter;

        let adapter = this->adapterFactory->newInstance(name, options);

        return new Cache(adapter);
    }
}
