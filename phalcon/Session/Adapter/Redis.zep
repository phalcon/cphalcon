
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
 * Phalcon\Session\Adapter\Redis
 */
 class Redis extends AbstractAdapter
{
    /**
     * Constructor
     *
     * @param AdapterFactory $factory
     * @param array          $options = [
     *                                'prefix'      => 'sess-reds-',
     *                                'stripPrefix' => false,
     *                                'host'        => '127.0.0.1',
     *                                'port'        => 6379,
     *                                'index'       => 0,
     *                                'persistent'  => false,
     *                                'auth'        => '',
     *                                'socket'      => '',
     * ]
     */
    public function __construct(<AdapterFactory> factory, array! options = [])
    {
        /**
         * Session ids are externally generated and never carry the storage
         * prefix; disable prefix stripping so an id that happens to start
         * with the prefix text cannot collide with another session
         */
        let options["prefix"]      = this->getArrVal(options, "prefix", "sess-reds-"),
            options["stripPrefix"] = this->getArrVal(options, "stripPrefix", false),
            this->adapter          = factory->newInstance("redis", options);
    }
}
