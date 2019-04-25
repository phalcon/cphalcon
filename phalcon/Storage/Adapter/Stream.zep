
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Storage\Adapter;

use Phalcon\Helper\Arr;
use Phalcon\Helper\Str;
use Phalcon\Storage\Adapter\AbstractAdapter;
use Phalcon\Storage\Exception;
use Phalcon\Storage\Serializer\SerializerInterface;

/**
 * Phalcon\Storage\Adapter\Stream
 *
 * Stream adapter
 */
class Stream extends AbstractAdapter
{
    /**
    * @var string
    */
    protected cacheDir = "";

    /**
     * @var array
     */
    protected options = [];

    /**
     * Constructor
     */
    public function __construct(array! options = [])
    {
        var cacheDir;
        string className;

        let cacheDir = Arr::get(options, "cacheDir", "");
        if empty cacheDir {
            throw new Exception("The 'cacheDir' must be specified in the options");
        }

        /**
         * Lets set some defaults and options here
         */
        let this->cacheDir = rtrim(cacheDir, DIRECTORY_SEPARATOR) . DIRECTORY_SEPARATOR,
            this->prefix   = "phstrm-",
            this->options  = options;

        parent::__construct(options);

        let className = "Phalcon\\Storage\\Serializer\\" . this->defaultSerializer;
        let this->serializer = new {className}();
    }

    /**
     * Flushes/clears the cache
     */
    public function clear() -> bool
    {
        var directory, iterator, file, result;

        let result      = true,
            directory = rtrim(this->cacheDir . this->prefix, DIRECTORY_SEPARATOR),
            iterator  = this->rglob(directory . "/*");

        for file in iterator {
            if !is_dir(file) && !unlink(file) {
                let result = false;
            }
        }

        return result;
    }

    /**
     * Decrements a stored number
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
     */
    public function delete(string! key) -> bool
    {
        var directory;

        if !this->has(key) {
            return false;
        }

        let directory = this->getDir(key);

        return unlink(directory . key);
    }

    /**
     * Reads data from the adapter
     */
    public function get(string! key, var defaultValue = null) -> var
    {
        var content, directory, payload;

        let directory = this->getDir(key),
            payload   = file_get_contents(directory . key);

        if typeof payload !== "string" {
            return defaultValue;
        }

        let payload = json_decode(payload, true);

        if json_last_error() !== JSON_ERROR_NONE {
            return defaultValue;
        }

        if this->isExpired(payload) {
            return defaultValue;
        }

        let content = Arr::get(payload, "content", null);

        return this->getUnserializedData(content, defaultValue);
    }

    /**
     * Returns the already connected adapter or connects to the Memcached
     * server(s)
     */
    public function getAdapter() -> var
    {
        return this->adapter;
    }

    /**
     * Stores data in the adapter
     */
    public function getKeys() -> array
    {
        var directory, iterator, file, split, results;

        let results   = [],
            directory = rtrim(this->cacheDir . this->prefix, DIRECTORY_SEPARATOR),
            iterator  = this->rglob(directory . "/*");

        for file in iterator {
            if !is_dir(file) {
                let split     = explode("/", file),
                    results[] = this->prefix . Arr::last(split);
            }
        }

        return results;
    }

    /**
     * Checks if an element exists in the cache and is not expired
     */
    public function has(string! key) -> bool
    {
        var directory, exists, payload;

        let directory = this->getDir(key),
            exists    = file_exists(directory . key);

        if !exists {
            return false;
        }

        let payload = file_get_contents(directory . key),
            payload = json_decode(payload);

        return !this->isExpired(payload);
    }

    /**
     * Increments a stored number
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
     */
    public function set(string! key, var value, var ttl = null) -> bool
    {
        var directory;
        array payload;

        let payload   = [
                "created" : time(),
                "ttl"     : this->getTtl(ttl),
                "content" : this->getSerializedData(value)
            ],
            payload   = json_encode(payload),
            directory = this->getDir(key);

        if !is_dir(directory) {
            mkdir(directory, 0777, true);
        }

        return false !== file_put_contents(directory . key, payload);
    }

    /**
     * Returns the folder based on the cacheDir and the prefix
     */
    private function getDir(string! key = "") -> string
    {
        var directory, fileDirectory;

        let directory     = rtrim(this->cacheDir . this->prefix, DIRECTORY_SEPARATOR),
            fileDirectory = rtrim(Str::folderFromFile(key), DIRECTORY_SEPARATOR);

        return directory . DIRECTORY_SEPARATOR . fileDirectory . DIRECTORY_SEPARATOR;
    }

    /**
     * Returns if the cache has expired for this item or not
     */
    private function isExpired(array! payload) -> bool
    {
        var created, ttl;

        let created = Arr::get(payload, "created", time()),
            ttl     = Arr::get(payload, "ttl", 3600);

        return (created + ttl) < time();
    }

    private function rglob(string! pattern) -> array
    {
        var dir, dirName, files, flags, recurse;

        let dirName = dirname(pattern) . "/*",
            files   = glob(pattern),
            flags   = GLOB_ONLYDIR | GLOB_NOSORT;

        for dir in glob(dirName, flags) {
            let dir     = dir . "/" . basename(pattern),
                recurse = this->rglob(dir),
                files   = array_merge(files, recurse);
        }

        return files;
    }
}
