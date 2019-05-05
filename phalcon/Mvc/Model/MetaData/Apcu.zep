
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model\MetaData;

use Phalcon\Mvc\Model\MetaData;
use Phalcon\Mvc\Model\Exception;
use Phalcon\Storage\Adapter\Apcu as StorageApcu;

/**
 * Phalcon\Mvc\Model\MetaData\Apcu
 *
 * Stores model meta-data in the APCu cache. Data will erased if the web server is restarted
 *
 * By default meta-data is stored for 48 hours (172800 seconds)
 *
 * You can query the meta-data by printing apcu_fetch('$PMM$') or apcu_fetch('$PMM$my-app-id')
 *
 *<code>
 * $metaData = new \Phalcon\Mvc\Model\MetaData\Apcu(
 *     [
 *         "prefix"   => "my-app-id",
 *         "lifetime" => 86400,
 *     ]
 * );
 *</code>
 */
class Apcu extends MetaData
{
    protected metaData = [];

    /**
     * Phalcon\Mvc\Model\MetaData\Apcu constructor
     *
     * @param array options
     */
    public function __construct(options = null) -> void
    {
        let options["prefix"]   = "ph-mm-apcu-",
            options["lifetime"] = 172800,
            this->adapter       = new StorageApcu(options);
    }
}
