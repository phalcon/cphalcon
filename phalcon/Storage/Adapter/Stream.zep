
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
        var dirIterator, iterator, file, mask, result;

        let result      = true,
            mask        =  Str::folderFromFile(this->prefix),
            dirIterator = new \RecursiveDirectoryIterator(this->cacheDir),
            iterator    = new \RecursiveIteratorIterator(
                dirIterator,
                \RecursiveIteratorIterator::CHILD_FIRST
            );

        for file in iterator {
            if file->isDir && Str::startsWith(file->getPathname(), this->cacheDir . this->prefix) {
                if !unlink(file->getPathname()) {
                    let result = false;
                }
            }
        }

        return result;
    }

    /**
     * Decrements a stored number
     */
    public function decrement(string! key, int value = 1) -> int | bool
    {
        var prefixedKey;

        let prefixedKey = this->getPrefixedKey(key);

        return value;
    }

    /**
     * Reads data from the adapter
     */
    public function delete(string! key) -> bool
    {
        var exists;

        let key    = this->getKey(key) . key,
            exists = file_exists(this->cacheDir . key);

        if !exists {
            return false;
        }

        return unlink(this->cacheDir . key);
    }

    /**
     * Reads data from the adapter
     */
    public function get(string! key, var defaultValue = null) -> var
    {
        var content, payload;

        let key     = this->getKey(key) . key,
            payload = file_get_contents(this->cacheDir . key);

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
        return [];
    }

    /**
     * Checks if an element exists in the cache and is not expired
     */
    public function has(string! key) -> bool
    {
        var exists, payload;

        let key    = this->getKey(key) . key,
            exists = file_exists(this->cacheDir . key);

        if !exists {
            return false;
        }

        let payload = file_get_contents(this->cacheDir . key),
            payload = json_decode(payload);

        return !this->isExpired(payload);
    }

    /**
     * Increments a stored number
     */
    public function increment(string! key, int value = 1) -> int | bool
    {
        var prefixedKey;

        let prefixedKey = this->getPrefixedKey(key);

        return apcu_inc(prefixedKey, value);
    }

    /**
     * Stores data in the adapter
     */
    public function set(string! key, var value, var ttl = null) -> bool
    {
        var folder;
        array payload;

        let payload = [
                "created" : time(),
                "ttl"     : this->getTtl(ttl),
                "content" : this->getSerializedData(value)
            ],
            payload = json_encode(payload),
            folder  = this->getKey(key),
            key     = folder . key;

        if !is_dir(this->cacheDir . folder) {
            mkdir(this->cacheDir . folder, 0777, true);
        }

        return false !== file_put_contents(this->cacheDir . key, payload);
    }

    /**
     * Returns the calculated folder with the key
     */
    private function getKey(string! key) -> string
    {
         return Str::folderFromFile(this->prefix . key);
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
}
