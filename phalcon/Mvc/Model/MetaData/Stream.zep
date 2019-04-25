
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
use Phalcon\Storage\Adapter\Stream as StorageStream;

/**
 * Phalcon\Mvc\Model\MetaData\Stream
 *
 * Stores model meta-data in PHP files.
 *
 *<code>
 * $metaData = new \Phalcon\Mvc\Model\MetaData\Stream(
 *     [
 *         "metaDataDir" => "app/cache/metadata/",
 *     ]
 * );
 *</code>
 */
class Stream extends MetaData
{
    protected metaData = [];

    /**
     * Phalcon\Mvc\Model\MetaData\Files constructor
     *
     * @param array options
     */
    public function __construct(options = null) -> void
    {
        let options["prefix"]     = "ph-mm-strm-",
            options["defaultTtl"] = 172800,
            options["cacheDir"]   = Arr::get(options, "metaDataDir", "./"),
            this->adapter         = new StorageStream(options);
    }
}
