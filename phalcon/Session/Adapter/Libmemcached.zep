
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
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
     * Libmemcached constructor.
     *
     * @param AdapterFactory $factory
     * @param array          $options = [
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
     *     'prefix' => 'sess-memc-',
     *     'stripPrefix' => false
     * ]
     */
    public function __construct(<AdapterFactory> factory, array! options = [])
    {
        /**
         * Session ids are externally generated and never carry the storage
         * prefix; disable prefix stripping so an id that happens to start
         * with the prefix text cannot collide with another session
         */
        let options["prefix"]      = this->getArrVal(options, "prefix", "sess-memc-"),
            options["stripPrefix"] = this->getArrVal(options, "stripPrefix", false),
            this->adapter          = factory->newInstance("libmemcached", options);
    }
}
