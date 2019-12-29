
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
use RuntimeException;

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
     * @param array options = [
     *     'annotationsDir' => 'phalconDir'
     * ]
     *
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
        var contents;
        string path;

        /**
         * Paths must be normalized before be used as keys
         */
        let path = this->annotationsDir . prepare_virtual_path(key, "_") . ".php";

        if !file_exists(path) {
            return false;
        }

        let contents = file_get_contents(path);

        if unlikely empty contents {
            return false;
        }

        globals_set("warning.enable", false);

        set_error_handler(
            function (number, message, file, line, context) {
                globals_set("warning.enable", true);
            },
            E_WARNING
        );

        let contents = unserialize(contents);

        restore_error_handler();

        if unlikely globals_get("warning.enable") {
            throw new RuntimeException(
                "Cannot read annotation data"
            );
        }

        return contents;
    }

    /**
     * Writes parsed annotations to files
     */
    public function write(string! key, <Reflection> data) -> void
    {
        var code;
        string path;

        /**
         * Paths must be normalized before be used as keys
         */
        let path = this->annotationsDir . prepare_virtual_path(key, "_") . ".php",
            code = serialize(data);

        if unlikely file_put_contents(path, code) === false {
              throw new Exception("Annotations directory cannot be written");
        }
    }
}
