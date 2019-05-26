
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

/**
 * Phalcon\Mvc\Model\MetaData\Stream
 *
 * Stores model meta-data in PHP files.
 *
 *<code>
 * $metaData = new \Phalcon\Mvc\Model\MetaData\Files(
 *     [
 *         "metaDataDir" => "app/cache/metadata/",
 *     ]
 * );
 *</code>
 */
class Stream extends MetaData
{
    protected metaDataDir = "./";

    /**
     * Phalcon\Mvc\Model\MetaData\Files constructor
     *
     * @param array options
     */
    public function __construct(options = null) -> void
    {
        var metaDataDir;

        if fetch metaDataDir, options["metaDataDir"] {
            let this->metaDataDir = metaDataDir;
        }
    }

    /**
     * Reads meta-data from files
     */
    public function read(string! key) -> array | null
    {
        var path;

        let path = this->metaDataDir . prepare_virtual_path(key, "_") . ".php";

        if !file_exists(path) {
            return null;
        }

        return require path;
    }

    /**
     * Writes the meta-data to files
     */
    public function write(string! key, array data) -> void
    {
        var path;

        let path = this->metaDataDir . prepare_virtual_path(key, "_") . ".php";

        if file_put_contents(path, "<?php return " . var_export(data, true) . "; ") === false {
            throw new Exception("Meta-Data directory cannot be written");
        }
    }
}
