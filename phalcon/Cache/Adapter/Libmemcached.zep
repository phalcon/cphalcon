
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Cache\Adapter;

use Phalcon\Cache\Adapter\AdapterInterface as CacheAdapterInterface;
use Phalcon\Storage\Adapter\Libmemcached as StorageLibmemcached;

/**
 * Libmemcached adapter
 */
class Libmemcached extends StorageLibmemcached implements CacheAdapterInterface
{
}
