
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Session\Adapter;

use Phalcon\Storage\AdapterFactory;
use Phalcon\Session\Adapter\AbstractAdapter;

/**
 * Phalcon\Session\Adapter\Libmemcached
 */
class Libmemcached extends AbstractAdapter
{
    /**
     * Constructor
     */
    public function __construct(<AdapterFactory> factory, array! options = [])
    {
        let options["prefix"] = "sess-memc-",
            this->adapter     = factory->newInstance("libmemcached", options);
    }
}
