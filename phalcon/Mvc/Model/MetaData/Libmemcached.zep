
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model\MetaData;

use Phalcon\Mvc\Model\Exception;
use Phalcon\Mvc\Model\MetaData;
use Phalcon\Cache\AdapterFactory;

/**
 * Phalcon\Mvc\Model\MetaData\Libmemcached
 *
 * Stores model meta-data in the Memcache.
 *
 * By default meta-data is stored for 48 hours (172800 seconds)
 */
class Libmemcached extends MetaData
{
    protected metaData = [];

    /**
     * Phalcon\Mvc\Model\MetaData\Libmemcached constructor
     *
     * @param array options
     */
    public function __construct(<AdapterFactory> factory, array! options = []) -> void
    {
        let options["prefix"]   = "ph-mm-memc-",
            options["lifetime"] = 172800,
            this->adapter       = factory->newInstance("libmemcached", options);
    }

    /**
     * Flush Memcache data and resets internal meta-data in order to regenerate it
     */
    public function reset() -> void
    {
        this->adapter->clear();

        parent::reset();
    }
}
