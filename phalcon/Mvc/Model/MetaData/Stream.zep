
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model\MetaData;

use Phalcon\Contracts\Mvc\MvcTypes;
use Phalcon\Mvc\Model\MetaData;
use Phalcon\Mvc\Model\MetaData\Exceptions\MetaDataDirectoryNotWritable;
use Phalcon\Support\Settings;
use Phalcon\Traits\Php\FileTrait;

/**
 * Phalcon\Mvc\Model\MetaData\Stream
 *
 * Stores model meta-data in PHP files.
 *
 *```php
 * $metaData = new \Phalcon\Mvc\Model\MetaData\Files(
 *     [
 *         "metaDataDir" => "app/cache/metadata/",
 *     ]
 * );
 *```
 *
 * @phpstan-import-type mvc_metadata_index from MvcTypes
 */
class Stream extends MetaData
{
    use FileTrait;

    protected string metaDataDir = "./";

    /**
     * Phalcon\Mvc\Model\MetaData\Files constructor
     *
     * @param array<string, mixed> $options
     */
    public function __construct(array options = [])
    {
        var metaDataDir;

        if fetch metaDataDir, options["metaDataDir"] {
            let this->metaDataDir = metaDataDir;
        }
    }

    /**
     * Reads meta-data from files
     *
     * @phpstan-return mvc_metadata_index|null
     */
    public function read(var key) -> array | null
    {
        var data, path;

        if null === key {
            return null;
        }

        let path = this->getFilePath(key);

        if !this->phpFileExists(path) {
            return null;
        }

        /**
         * A file that is not valid is a cache miss
         */
        try {
            let data = this->requireFile(path);
        } catch \ParseError {
            return null;
        }

        if typeof data != "array" {
            return null;
        }

        return data;
    }

    /**
     * Writes the meta-data to files
     *
     * @phpstan-param mvc_metadata_index $data
     */
    public function write(var key, array data) -> void
    {
        var option, path, tmpPath;

        let option = Settings::get("orm.exception_on_failed_metadata_save");

        try {
            let path    = this->getFilePath(key),
                tmpPath = path . ".tmp." . (string) getmypid();

            /**
             * Write to a temporary file, then move it into place with one
             * rename(). Other processes then never read a partial file.
             */
            if false === this->phpFilePutContents(tmpPath, "<?php return " . var_export(data, true) . "; ") {
                this->throwWriteException(option);
            } elseif !rename(tmpPath, path) {
                this->phpUnlink(tmpPath);
                this->throwWriteException(option);
            }
        } catch \Exception {
            this->throwWriteException(option);
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

        return this->metaDataDir . name . ".php";
    }

    /**
     * Returns the value of a PHP file. The require is in a separate method,
     * because the caller must be able to catch a ParseError.
     */
    private function requireFile(string path) -> var
    {
        return require path;
    }

    /**
     * Throws an exception when the metadata cannot be written
     */
    private function throwWriteException(var option) -> void
    {
        if option {
            throw new MetaDataDirectoryNotWritable();
        } else {
            trigger_error(
                "Meta-Data directory cannot be written"
            );
        }
    }
}
