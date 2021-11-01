
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Storage\Adapter;

use DateInterval;
use FilesystemIterator;
use Iterator;
use Phalcon\Storage\Exception;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Storage\Traits\StorageErrorHandlerTrait;
use Phalcon\Support\Exception as SupportException;
use Phalcon\Traits\Helper\Str\DirFromFileTrait;
use Phalcon\Traits\Helper\Str\DirSeparatorTrait;
use Phalcon\Traits\Php\FileTrait;
use RecursiveDirectoryIterator;
use RecursiveIteratorIterator;

/**
 * Stream adapter
 *
 * @property string $storageDir
 * @property array  $options
 */
class Stream extends AbstractAdapter
{
    /**
     * @var string
     */
    protected prefix = "ph-strm";

    /**
     * @var string
     */
    protected storageDir = "";

    /**
     * Stream constructor.
     *
     * @param SerializerFactory $factory
     * @param array             $options = [
     *     'storageDir'        => '',
     *     'defaultSerializer' => 'php',
     *     'lifetime'          => 3600,
     *     'prefix'            => ''
     * ]
     *
     * @throws Exception
     */
    public function __construct(<SerializerFactory> factory, array! options = [])
    {
        var storageDir;

        let storageDir = this->getArrVal(options, "storageDir", "");
        if empty storageDir {
            throw new Exception("The 'storageDir' must be specified in the options");
        }

        /**
         * Lets set some defaults and options here
         */
        let this->storageDir = this->getDirSeparator(storageDir);

        parent::__construct(factory, options);

        this->initSerializer();
    }

    /**
     * Flushes/clears the cache
     */
    public function clear() -> bool
    {
        var directory, iterator, file;
        bool result;

        let result    = true,
            directory = this->getDirSeparator(this->storageDir),
            iterator  = this->getIterator(directory);

        for file in iterator {
            if file->isFile() && !unlink(file->getPathName()) {
                let result = false;
            }
        }

        return result;
    }

    /**
     * Decrements a stored number
     *
     * @param string $key
     * @param int    $value
     *
     * @return bool|int
     */
    public function decrement(string! key, int value = 1) -> int | bool
    {
        var data;

        if !this->has(key) {
            return false;
        }

        let data = this->get(key),
            data = (int) data - value;

        return this->set(key, data);
    }

    /**
     * Reads data from the adapter
     *
     * @param string $key
     *
     * @return bool
     */
    public function delete(string! key) -> bool
    {
        var filepath;

        if !this->has(key) {
            return false;
        }

        let filepath = this->getFilepath(key);

        return unlink(filepath);
    }

    /**
     * Reads data from the adapter
     *
     * @param string     $key
     * @param mixed|null $defaultValue
     *
     * @return mixed|null
     */
    public function get(string! key, var defaultValue = null) -> var
    {
        var content, filepath, payload;

        let filepath = this->getFilepath(key);

        if (true !== file_exists(filepath)) {
            return defaultValue;
        }

        let payload = this->getPayload(filepath);

        if (empty(payload) || this->isExpired(payload)) {
            return defaultValue;
        }

        let content = this->getArrVal(payload, "content");

        return this->getUnserializedData(content, defaultValue);
    }

    /**
     * Stores data in the adapter
     *
     * @param string $prefix
     *
     * @return array
     */
    public function getKeys(string! prefix = "") -> array
    {
        var directory, file, iterator;
        array files;

        let files     = [],
            directory = this->getDir();

        if !file_exists(directory) {
            return [];
        }

        let iterator  = this->getIterator(directory);

        for file in iterator {
            if file->isFile() {
                let files[] = this->prefix . file->getFilename();
            }
        }

        return this->getFilteredKeys(files, prefix);
    }

    /**
     * Checks if an element exists in the cache and is not expired
     *
     * @param string $key
     *
     * @return bool
     */
    public function has(string! key) -> bool
    {
        var payload, filepath;

        let filepath = this->getFilepath(key);

        if !file_exists(filepath) {
            return false;
        }

        let payload = this->getPayload(filepath);

        if unlikely empty payload {
            return false;
        }

        return !this->isExpired(payload);
    }

    /**
     * Increments a stored number
     *
     * @param string $key
     * @param int    $value
     *
     * @return bool|int
     */
    public function increment(string! key, int value = 1) -> int | bool
    {
        var data;

        if !this->has(key) {
            return false;
        }

        let data = this->get(key),
            data = (int) data + value;

        return this->set(key, data);
    }

    /**
     * Stores data in the adapter
     *
     * @param string                 $key
     * @param mixed                  $value
     * @param \DateInterval|int|null $ttl
     *
     * @return bool
     */
    public function set(string! key, var value, var ttl = null) -> bool
    {
        array payload;

        if (typeof ttl === "integer" && ttl < 1) {
            return this->delete(key);
        }

        let payload   = [
            "created" : time(),
            "ttl"     : this->getTtl(ttl),
            "content" : this->getSerializedData(value)
        ];

        return this->storePayload(payload, key);
    }

    /**
     * Stores data in the adapter forever. The key needs to manually deleted
     * from the adapter.
     *
     * @param string $key
     * @param mixed  $value
     *
     * @return bool
     */
    public function setForever(string! key, var value) -> bool
    {
        array payload;

        let payload   = [
            "created" : time(),
            "ttl"     : "forever",
            "content" : this->getSerializedData(value)
        ];

        return this->storePayload(payload, key);
    }

    /**
     * Returns the folder based on the storageDir and the prefix
     *
     * @param string $key
     *
     * @return string
     */
    private function getDir(string! key = "") -> string
    {
        var dirFromFile, dirPrefix;

        let dirPrefix   = this->getDirSeparator(this->storageDir . this->prefix),
            dirFromFile = this->getDirFromFile(
                str_replace(this->prefix, "", key)
            );

        return this->getDirSeparator(dirPrefix . dirFromFile);
    }

    /**
     * Returns the full path to the file
     *
     * @param string $key
     *
     * @return string
     */
    private function getFilepath(string! key) -> string
    {
        return this->getDir(key) . str_replace(this->prefix, "", key);
    }

    /**
     * Returns an iterator for the directory contents
     *
     * @param string $dir
     *
     * @return Iterator
     */
    private function getIterator(string! dir) -> <Iterator>
    {
        return new RecursiveIteratorIterator(
            new RecursiveDirectoryIterator(
                dir,
                FilesystemIterator::SKIP_DOTS
            ),
            RecursiveIteratorIterator::CHILD_FIRST
        );
    }

    /**
     * Gets the file contents and returns an array or an error if something
     * went wrong
     *
     * @param string $filepath
     *
     * @return array
     */
    private function getPayload(string filepath) -> array
    {
        var payload, pointer, version;

        let payload = false,
            pointer = fopen(filepath, 'r');

        /**
         * Cannot open file
         */
        if (false === pointer) {
            return [];
        }

        if (flock(pointer, LOCK_SH)) {
            let payload = file_get_contents(filepath);
        }

        fclose(pointer);

        /**
         * No results
         */
        if false === payload {
            return [];
        }

        let version = phpversion();
        globals_set("warning.enable", false);

        if version_compare(version, "8.0", ">=") {
            set_error_handler(
                function (number, message, file, line) {
                    globals_set("warning.enable", true);
                },
                E_NOTICE
            );
        } else {
            set_error_handler(
                function (number, message, file, line, context) {
                    globals_set("warning.enable", true);
                },
                E_NOTICE
            );
        }

        let payload = unserialize(payload);

        restore_error_handler();

        if unlikely (globals_get("warning.enable") || typeof payload !== "array") {
            return [];
        }

        return payload;
    }

    /**
     * Returns if the cache has expired for this item or not
     *
     * @param array $payload
     *
     * @return bool
     */
    private function isExpired(array! payload) -> bool
    {
        var created, ttl;

        let created = this->getArrVal(payload, "created", time()),
            ttl     = this->getArrVal(payload, "ttl", 3600);

        if ("forever" === ttl) {
            return false;
        }

        return (created + ttl) < time();
    }


    /**
     * Stores an array payload on the file system
     *
     * @param array  $payload
     * @param string $key
     *
     * @return bool
     */
    private function storePayload(array payload, string key) -> bool
    {
        var directory, payload;

        let payload   = serialize(payload),
            directory = this->getDir(key);

        if !is_dir(directory) {
            mkdir(directory, 0777, true);
        }

        return false !== file_put_contents(directory . key, payload, LOCK_EX);
    }

    /**
     * @todo Remove this when we get traits
     */
    private function getDirFromFile(string! file) -> string
    {
        var name, start;

        let name  = pathinfo(file, PATHINFO_FILENAME),
            start = substr(name, 0, -2);

         if !empty start {
            let start = str_replace(".", "-", start);
        }

        if !start {
            let start = substr(name, 0, 1);
        }

        return implode("/", str_split(start, 2)) . "/";
    }

    /**
     * @todo Remove this when we get traits
     */
    private function getDirSeparator(string! directory) -> string
    {
        return rtrim(directory, DIRECTORY_SEPARATOR) . DIRECTORY_SEPARATOR;
    }
}
