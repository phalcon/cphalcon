
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Annotations\Adapter;

use Phalcon\Annotations\Exception;
use Phalcon\Annotations\Exceptions\AnnotationsDirectoryNotWritable;
use Phalcon\Annotations\Exceptions\CannotReadAnnotationData;
use Phalcon\Annotations\Reflection;
use Phalcon\Contracts\Annotations\AnnotationsTypes;
use Phalcon\Traits\Php\FileTrait;
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
 *
 * @phpstan-import-type annotations_options from AnnotationsTypes
 */
class Stream extends AbstractAdapter
{
    use FileTrait;

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
     *
     * @phpstan-param annotations_options $options
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
        var path;

        /**
         * Paths must be normalized before be used as keys
         */
        let path = this->getFilePath(key);

        if !this->phpFileExists(path) {
            return false;
        }

        let contents = this->phpFileGetContents(path);

        if unlikely empty contents {
            return false;
        }

        globals_set("warning.enable", false);
        set_error_handler(
            function (number, message, file, line) {
                globals_set("warning.enable", true);
            },
            E_WARNING
        );

        /**
         * Restrict object instantiation to the annotation classes this cache
         * ever stores, so a planted cache file cannot trigger PHP object
         * injection through arbitrary classes (CWE-502).
         */
        let contents = unserialize(
            contents,
            [
                "allowed_classes": [
                    "Phalcon\\Annotations\\Reflection",
                    "Phalcon\\Annotations\\Collection",
                    "Phalcon\\Annotations\\Annotation"
                ]
            ]
        );

        restore_error_handler();

        if unlikely globals_get("warning.enable") {
            throw new CannotReadAnnotationData();
        }

        return contents;
    }

    /**
     * Writes parsed annotations to files
     */
    public function write(string key, <Reflection> data) -> void
    {
        var code;
        var path;

        /**
         * Paths must be normalized before be used as keys
         */
        let path = this->getFilePath(key),
            code = serialize(data);

        if unlikely this->phpFilePutContents(path, code) === false {
            throw new AnnotationsDirectoryNotWritable();
        }
    }

    /**
     * Builds the cache file path. Namespace separators become "_", so a
     * name that itself contains "_" gets a hash suffix; otherwise "A\\B"
     * and "A_B" would share one file.
     */
    private function getFilePath(string key) -> string
    {
        var name;

        let name = prepare_virtual_path(key, "_");

        if memstr(key, "_") {
            let name = name . "_" . sha1(key);
        }

        return this->annotationsDir . name . ".php";
    }
}
