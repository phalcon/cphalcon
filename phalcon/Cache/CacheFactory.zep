
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
use Phalcon\Cache;
use Psr\SimpleCache\CacheInterface;
use Phalcon\Cache\Exception\Exception;
use Phalcon\Config\ConfigInterface;
use Phalcon\Helper\Arr;

/**
 * Creates a new Cache class
 */
class CacheFactory
{
    /**
     * @var AdapterFactory
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
     * Factory to create an instance from a Config object
     *
     * @param array|\Phalcon\Config\Config config = [
     *     'adapter' => 'apcu',
     *     'options' => [
     *         'servers' => [
     *             [
     *                 'host' => 'localhost',
     *                 'port' => 11211,
     *                 'weight' => 1,
     *
     *             ]
     *         ],
     *         'host' => '127.0.0.1',
     *         'port' => 6379,
     *         'index' => 0,
     *         'persistent' => false,
     *         'auth' => '',
     *         'socket' => '',
     *         'defaultSerializer' => 'Php',
     *         'lifetime' => 3600,
     *         'serializer' => null,
     *         'prefix' => 'phalcon',
     *         'storageDir' => ''
     *     ]
     * ]
     */
    public function load(var config) -> var
    {
        var name, options;

        if typeof config == "object" && config instanceof ConfigInterface {
            let config = config->toArray();
        }

        if unlikely typeof config !== "array" {
            throw new Exception(
                "Config must be array or Phalcon\\Config\\Config object"
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
     * Constructs a new Cache instance.
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
    public function newInstance(string! name, array! options = []) -> <CacheInterface>
    {
        var adapter;

        let adapter = this->adapterFactory->newInstance(name, options);

        return new Cache(adapter);
    }
}
