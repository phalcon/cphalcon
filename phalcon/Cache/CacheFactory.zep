
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Cache;

use Phalcon\Cache\AdapterFactory;
use Phalcon\Cache\Adapter\AdapterInterface;
use Phalcon\Cache\Cache;
use Phalcon\Cache\CacheInterface;

/**
 * Phalcon\CacheFactory
 *
 * Creates a new Cache class
 */
class CacheFactory
{
    /**
     * <AdapterFactory>
     */
    protected adapterFactory;

    /**
     * Constructor
     */
    public function __construct(<AdapterFactory> $factory)
    {
        let this->adapterFactory = factory;
    }

    /**
     * Returns a new instance
     */
    public function newInstance(string! name, array! options = []) -> <CacheInterface>
    {
        var adapter = this->adapterFactory->newInstance(name, options);

        return new Cache(adapter);
    }
}
