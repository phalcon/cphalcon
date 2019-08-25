
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Storage\Adapter;

use FilesystemIterator;
use Iterator;
use Phalcon\Helper\Arr;
use Phalcon\Helper\Str;
use Phalcon\Storage\Adapter\AbstractAdapter;
use Phalcon\Storage\Exception;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Storage\Serializer\SerializerInterface;
use RecursiveDirectoryIterator;
use RecursiveIteratorIterator;

/**
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
     * Stream constructor.
     *
     * @param array $options
     *
     * @throws Exception
     */
    public function __construct(<SerializerFactory> factory = null, array! options = [])
    {
        var cacheDir;

        let cacheDir = Arr::get(options, "cacheDir", "");
        if empty cacheDir {
            throw new Exception("The 'cacheDir' must be specified in the options");
        }

        /**
         * Lets set some defaults and options here
         */
        let this->cacheDir = Str::dirSeparator(cacheDir),
            this->prefix   = "phstrm-",
            this->options  = options;

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
            directory = Str::dirSeparator(this->cacheDir),
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
     * @throws \Exception
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
     * @param string $key
     * @param null   $defaultValue
     *
     * @return mixed|null
     */
    public function get(string! key, var defaultValue = null) -> var
    {
        var content, payload, filepath;

        let filepath = this->getFilepath(key);

        if !file_exists(filepath) {
            return defaultValue;
        }

        let payload   = file_get_contents(filepath),
            payload = json_decode(payload, true);

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
            directory = Str::dirSeparator(this->cacheDir),
            iterator  = this->getIterator(directory);

        for file in iterator {
            if file->isFile() {
                let split     = explode("/", file->getPathName()),
                    results[] = this->prefix . Arr::last(split);
            }
        }

        return results;
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

        let payload = file_get_contents(filepath),
            payload = json_decode(payload);

        return !this->isExpired(payload);
    }

    /**
     * Increments a stored number
     *
     * @param string $key
     * @param int    $value
     *
     * @return bool|int
     * @throws \Exception
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
     * @param string $key
     * @param mixed  $value
     * @param null   $ttl
     *
     * @return bool
     * @throws \Exception
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
     *
     * @param string $key
     *
     * @return string
     */
    private function getDir(string! key = "") -> string
    {
        var dirPrefix, dirFromFile;

        let dirPrefix   = this->cacheDir . this->prefix,
            dirFromFile = Str::dirFromFile(
                str_replace(this->prefix, "", key, 1)
            );

        return Str::dirSeparator(dirPrefix) . dirFromFile;
    }

    /**
     * Returns the full path to the file
     */
    private function getFilepath(string! key) -> string
    {
        return this->getDir(key) . str_replace(this->prefix, "", key, 1);
    }

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
     * Returns if the cache has expired for this item or not
     *
     * @param array $payload
     *
     * @return bool
     */
    private function isExpired(array! payload) -> bool
    {
        var created, ttl;

        let created = Arr::get(payload, "created", time()),
            ttl     = Arr::get(payload, "ttl", 3600);

        return (created + ttl) < time();
    }
}
