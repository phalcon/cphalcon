
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model\MetaData;

use Phalcon\Helper\Arr;
use Phalcon\Mvc\Model\Exception;
use Phalcon\Mvc\Model\MetaData\AbstractMetaData;
use Phalcon\Cache\AdapterFactory;

/**
 * Stores model meta-data in the Memcache.
 *
 * By default meta-data is stored for 48 hours (172800 seconds)
 */
class Libmemcached extends AbstractMetaData
{
    /**
     * Phalcon\Mvc\Model\MetaData\Libmemcached constructor
     */
    public function __construct(<AdapterFactory> factory, array! options = []) -> void
    {
        let options["persistentId"] = Arr::get(options, "persistentId", "ph-mm-mcid-"),
            options["prefix"]       = Arr::get(options, "prefix", "ph-mm-memc-"),
            options["lifetime"]     = Arr::get(options, "lifetime", 172800),
            this->adapter           = factory->newInstance("libmemcached", options);
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
