
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Annotations\Adapter;

use Phalcon\Annotations\Reflection;
use Phalcon\Annotations\Exception;

/**
 * Stores the parsed annotations in files. This adapter is suitable for production
 *
 *```php
 * use Phalcon\Annotations\Adapter\Stream;
 *
 * $annotations = new Stream(
 *     [
 *         "annotationsDir" => "app/cache/annotations/",
 *     ]
 * );
 *```
 */
class Stream extends AbstractAdapter
{
    /**
     * @var string
     */
    protected annotationsDir = "./";

    /**
     * Phalcon\Annotations\Adapter\Stream constructor
     */
    public function __construct(array options = [])
    {
        var annotationsDir;

        if fetch annotationsDir, options["annotationsDir"] {
            let this->annotationsDir = annotationsDir;
        }
    }

    /**
     * Reads parsed annotations from files
     */
    public function read(string key) -> <Reflection> | bool | int
    {
        string path;

        /**
         * Paths must be normalized before be used as keys
         */
        let path = this->annotationsDir . prepare_virtual_path(key, "_") . ".php";

        if !file_exists(path) {
            return false;
        }

        return require path;
    }

    /**
     * Writes parsed annotations to files
     */
    public function write(string! key, <Reflection> data) -> void
    {
        string path, code;

        /**
         * Paths must be normalized before be used as keys
         */
        let path = this->annotationsDir . prepare_virtual_path(key, "_") . ".php";

        let code = "<?php return " . var_export(data, true) . "; ";

        if unlikely file_put_contents(path, code) === false {
              throw new Exception("Annotations directory cannot be written");
        }
    }
}
