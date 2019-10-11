
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

/**
 * Phalcon\Session\Adapter\Redis
 */
 class Redis extends AbstractAdapter
{
    /**
     * Constructor
     *
     * @param array options = [
     *     'prefix' => 'sess-reds-',
     *     'host' => '127.0.0.1',
     *     'port' => 6379,
     *     'index' => 0,
     *     'persistent' => false,
     *     'auth' => '',
     *     'socket' => ''
     * ]
     */
    public function __construct(<AdapterFactory> factory, array! options = [])
    {
        let options["prefix"] = "sess-reds-",
            this->adapter     = factory->newInstance("redis", options);
    }
}
