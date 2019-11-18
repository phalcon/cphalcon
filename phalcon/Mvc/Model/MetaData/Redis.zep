
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model\MetaData;

use Phalcon\Helper\Arr;
use Phalcon\Mvc\Model\MetaData;
use Phalcon\Cache\AdapterFactory;

/**
 * Phalcon\Mvc\Model\MetaData\Redis
 *
 * Stores model meta-data in the Redis.
 *
 * By default meta-data is stored for 48 hours (172800 seconds)
 *
 *```php
 * use Phalcon\Mvc\Model\MetaData\Redis;
 *
 * $metaData = new Redis(
 *     [
 *         "host"       => "127.0.0.1",
 *         "port"       => 6379,
 *         "persistent" => 0,
 *         "lifetime"   => 172800,
 *         "index"      => 2,
 *     ]
 * );
 *```
 */
class Redis extends MetaData
{
    /**
     * Phalcon\Mvc\Model\MetaData\Redis constructor
     *
     * @param array options
     */
    public function __construct(<AdapterFactory> factory, array! options = [])
    {
        let options["prefix"]   = Arr::get(options, "prefix", "ph-mm-reds-"),
            options["lifetime"] = Arr::get(options, "lifetime", 172800),
            this->adapter       = factory->newInstance("redis", options);
    }

    /**
     * Flush Redis data and resets internal meta-data in order to regenerate it
     */
    public function reset() -> void
    {
        this->adapter->clear();

        parent::reset();
    }
}
