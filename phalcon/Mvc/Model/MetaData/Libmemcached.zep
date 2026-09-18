
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model\MetaData;

use Phalcon\Cache\AdapterFactory;
use Phalcon\Contracts\Mvc\MvcTypes;
use Phalcon\Contracts\Storage\StorageTypes;
use Phalcon\Mvc\Model\MetaData;

/**
 * Stores model meta-data in the Memcache.
 *
 * By default meta-data is stored for 48 hours (172800 seconds)
 *
 * @phpstan-import-type storage_adapter_options from StorageTypes
 */
class Libmemcached extends MetaData
{
    /**
     * Phalcon\Mvc\Model\MetaData\Libmemcached constructor
     *
     * @param array<string, mixed> $options
     */
    public function __construct(<AdapterFactory> factory,  array options = [])
    {
        let options["persistentId"] = this->getArrVal(options, "persistentId", "ph-mm-mcid-"),
            options["prefix"]       = this->getArrVal(options, "prefix", "ph-mm-memc-"),
            options["lifetime"]     = this->getArrVal(options, "lifetime", 172800),
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
