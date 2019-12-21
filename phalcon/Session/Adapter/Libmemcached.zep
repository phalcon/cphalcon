
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
 * Phalcon\Session\Adapter\Libmemcached
 */
class Libmemcached extends AbstractAdapter
{
    /**
     * Constructor
     *
     * @param array options = [
     *     'servers' => [
     *         [
     *             'host' => 'localhost',
     *             'port' => 11211,
     *             'weight' => 1,
     *
     *         ]
     *     ],
     *     'defaultSerializer' => 'Php',
     *     'lifetime' => 3600,
     *     'serializer' => null,
     *     'prefix' => 'sess-memc-'
     * ]
     */
    public function __construct(<AdapterFactory> factory, array! options = [])
    {
        let options["prefix"] = "sess-memc-",
            this->adapter     = factory->newInstance("libmemcached", options);
    }
}
