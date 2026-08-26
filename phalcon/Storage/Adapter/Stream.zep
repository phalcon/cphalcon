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
use Phalcon\Contracts\Storage\StorageTypes;
use Phalcon\Storage\Exceptions\InvalidConfiguration;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Traits\Php\FileTrait;
use Phalcon\Traits\Support\Helper\Str\DirFromFileTrait;
use Phalcon\Traits\Support\Helper\Str\DirSeparatorTrait;
use RecursiveDirectoryIterator;
use RecursiveIteratorIterator;
use SplFileInfo;

/**
 * Stream adapter
 *
 * Capabilities:
 * - Counters: read-modify-write (doHas()/doGet()/doSet()); not atomic and racy
 *   across concurrent processes.
 * - getKeys(): recursive directory traversal; cost grows with the entry count.
 * - Serializers: Phalcon-side only.
 *
 * @phpstan-import-type storage_keys from StorageTypes
 * @phpstan-import-type storage_stream_options from StorageTypes
 * @phpstan-import-type storage_stream_payload from StorageTypes
 */
class Stream extends AbstractAdapter
{
    use DirFromFileTrait;
    use DirSeparatorTrait;
    use FileTrait;

    protected string prefix = "ph-strm";
    protected string storageDir = "";

    /**
     * Stream constructor.
     *
     * @phpstan-param storage_stream_options $options
     *
     * @throws InvalidConfiguration
     */
    public function __construct(
        <SerializerFactory> factory,
        array options = []
    ) {
        var storageDir;

        /** @var string $storageDir */
        let storageDir = this->getArrVal(options, "storageDir", "");
        if empty storageDir {
            throw new InvalidConfiguration(
                "The 'storageDir' must be specified in the options"
            );
        }

        /**
         * Lets set some defaults and options here
         */
        let this->storageDir = this->toDirSeparator(storageDir);

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
            directory = this->getDir();

        if unlikely true !== this->phpFileExists(directory) {
            return result;
        }

        let iterator = this->getIterator(directory);

        /** @var SplFileInfo $file */
        for file in iterator {
            if unlikely true === file->isFile() && true !== this->phpUnlink(file->getPathName()) {
                let result = false;
            }
        }

        return result;
    }

    /**
     * Stores data in the adapter
     *
     * @phpstan-return storage_keys
     */
    public function getKeys(string prefix = "") -> array
    {
        var directory, file, iterator;
        array files;

        let files     = [],
            directory = this->getDir();

        if unlikely true !== this->phpFileExists(directory) {
            return [];
        }

        let iterator  = this->getIterator(directory);

        /** @var SplFileInfo $file */
        for file in iterator {
            if true === file->isFile() {
                let files[] = this->prefix . file->getFilename();
            }
        }

        return this->getFilteredKeys(files, prefix);
    }

    /**
     * Stores data in the adapter forever. The key needs to manually deleted
     * from the adapter.
     */
    public function setForever(string key, var data) -> bool
    {
        array payload;

        let payload   = [
            "created" : time(),
            "ttl"     : "forever",
            "content" : this->getSerializedData(data)
        ];

        return this->storePayload(payload, key);
    }

    /**
     * Decrements a stored number
     */
    protected function doDecrement(string key, int value = 1) -> false | int
    {
        var data, result;

        if unlikely true !== this->doHas(key) {
            return false;
        }

        /** @var float|int|string $data */
        let data = this->doGet(key),
            data = (int) data - value;

        let result = this->doSet(key, data);
        if likely result !== false {
            let result = data;
        }

        return result;
    }

    /**
     * Deletes data from the adapter
     */
    protected function doDelete(string key) -> bool
    {
        var filepath;

        if true !== this->doHas(key) {
            return false;
        }

        let filepath = this->getFilepath(key);

        return this->phpUnlink(filepath);
    }

    /**
     * Reads data from the adapter
     */
    protected function doGet( string key, var defaultValue = null) -> var
    {
        var content, filepath, payload;

        let filepath = this->getFilepath(key);

        if (true !== this->phpFileExists(filepath)) {
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
     * Checks if an element exists in the cache and is not expired
     */
    protected function doHas( string key) -> bool
    {
        var payload, filepath;

        let filepath = this->getFilepath(key);

        if unlikely true !== this->phpFileExists(filepath) {
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
     */
    protected function doIncrement( string key, int value = 1) -> false | int
    {
        var data, result;

        if unlikely true !== this->doHas(key) {
            return false;
        }

        /** @var float|int|string $data */
        let data = this->doGet(key),
            data = (int) data + value;

        let result = this->doSet(key, data);
        if likely result !== false {
            let result = data;
        }

        return result;
    }

    /**
     * Stores data in the adapter. If the TTL is `null` (default) or not defined
     * then the default TTL will be used, as set in this adapter. If the TTL
     * is `0` or a negative number, a `delete()` will be issued, since this
     * item has expired. If you need to set this key forever, you should use
     * the `setForever()` method.
     */
    protected function doSet( string key, var value, var ttl = null) -> bool
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
     * Returns the folder based on the storageDir and the prefix
     */
    private function getDir( string key = "") -> string
    {
        var dirFromFile, dirPrefix;

        let dirPrefix   = this->toDirSeparator(this->storageDir . this->prefix),
            dirFromFile = this->toDirFromFile(this->getKeyWithoutPrefix(key), true);

        return this->toDirSeparator(dirPrefix . dirFromFile);
    }

    /**
     * Returns the full path to the file
     */
    private function getFilepath(string key) -> string
    {
        var name, plain;

        /**
         * Remove path separators from the key so a crafted key cannot climb
         * out of the storage directory (CWE-22). str_replace is used rather
         * than prepare_virtual_path because the latter also lower-cases the
         * key, which would no longer match the stored file name.
         */
        let plain = this->getKeyWithoutPrefix(key),
            name  = str_replace(["/", "\\", ":"], "_", plain);

        /**
         * A key with a path separator gets a hash suffix, so it cannot share
         * a file with a key that spells the "_" replacement itself.
         */
        if memstr(plain, "/") || memstr(plain, "\\") || memstr(plain, ":") {
            let name = name . "_" . sha1(plain);
        }

        return this->getDir(key) . name;
    }

    /**
     * Returns an iterator for the directory contents
     */
    private function getIterator( string dir) -> <Iterator>
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
     * @phpstan-return storage_stream_payload
     */
    private function getPayload(string filepath) -> array
    {
        var payload, pointer;

        let payload = false,
            pointer = this->phpFopen(filepath, "r");

        /**
         * Cannot open file
         */
        if unlikely false === pointer {
            return [];
        }

        if likely true === flock(pointer, LOCK_SH) {
            let payload = this->phpFileGetContents(filepath);
        }

        this->phpFclose(pointer);

        /**
         * No results
         */
        if unlikely false === payload {
            return [];
        }

        globals_set("warning.enable", false);
        set_error_handler(
            function (number, message, file, line) {
                globals_set("warning.enable", true);
            },
            E_NOTICE
        );

        /**
         * The payload is only ever a metadata array (the stored value is a
         * nested serialized string). Refuse to build any object so a crafted
         * cache file cannot fire magic methods on read (CWE-502).
         *
         * @var storage_stream_payload|false $payload
         */
        let payload = unserialize(payload, ["allowed_classes" : false]);

        restore_error_handler();

        if unlikely (globals_get("warning.enable") || typeof payload !== "array") {
            return [];
        }

        return payload;
    }

    /**
     * Returns if the cache has expired for this item or not
     *
     * @phpstan-param storage_stream_payload $payload
     */
    private function isExpired( array payload) -> bool
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
     * @phpstan-param storage_stream_payload $payload
     */
    private function storePayload(array payload, string key) -> bool
    {
        var directory, localPayload;

        let localPayload   = serialize(payload),
            directory = this->getDir(key);

        if !is_dir(directory) {
            mkdir(directory, 0777, true);
        }

        return false !== this->phpFilePutContents(
            this->getFilepath(key),
            localPayload,
            LOCK_EX
        );
    }
}
