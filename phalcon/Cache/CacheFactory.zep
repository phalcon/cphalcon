
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
     * Constructor.
     *
     * @param AdapterInterface  adapter The cache adapter
     */
    public function newInstance(<AdapterInterface> adapter) -> <CacheInterface>
    {
        return new Cache(adapter);
    }
}
