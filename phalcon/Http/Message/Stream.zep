
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by Zend Diactoros
 * @link    https://github.com/zendframework/zend-diactoros
 * @license https://github.com/zendframework/zend-diactoros/blob/master/LICENSE.md
 */

namespace Phalcon\Http\Message;

use Exception;
use PsrExt\Http\Message\StreamInterface;
use RuntimeException;

/**
 * PSR-7 Stream
 */
class Stream implements StreamInterface
{
    /**
     * @var resource | null
     */
    protected handle = null;

    /**
     * @var resource | string
     */
    protected stream;

    /**
     * Stream constructor.
     *
     * @param mixed  $stream
     * @param string $mode
     */
    public function __construct(var stream, string! mode = "rb")
    {
        this->setStream(stream, mode);
    }

    /**
     * Closes the stream when the destructed.
     */
    public function __destruct()
    {
        this->close();
    }

    /**
     * Reads all data from the stream into a string, from the beginning to end.
     *
     * This method MUST attempt to seek to the beginning of the stream before
     * reading data and read the stream until the end is reached.
     *
     * Warning: This could attempt to load a large amount of data into memory.
     *
     * This method MUST NOT raise an exception in order to conform with PHP's
     * string casting operations.
     *
     * @see http://php.net/manual/en/language.oop5.magic.php#object.tostring
     */
    public function __toString() -> string
    {
        try {
            if likely this->isReadable() {
                if likely this->isSeekable() {
                    this->rewind();
                }

                return this->getContents();
            }
        }

        return "";
    }

    /**
     * Closes the stream and any underlying resources.
     */
    public function close() -> void
    {
        var handle;

        if likely null !== this->handle {
            let handle = this->detach();

            fclose(handle);
        }
    }

    /**
     * Separates any underlying resources from the stream.
     *
     * After the stream has been detached, the stream is in an unusable state.
     *
     * @return resource | null
     */
    public function detach() -> resource | null
    {
        var handle;

        let handle       = this->handle,
            this->handle = null;

        return handle;
    }

    /**
     * Returns true if the stream is at the end of the stream.
     */
    public function eof() -> bool
    {
        if likely this->handle {
            return feof(this->handle);
        }

        return true;
    }

    /**
     * Returns the remaining contents in a string
     */
    public function getContents() -> string
    {
        var data;

        this->checkHandle();
        this->checkReadable();

        let data = stream_get_contents(this->handle);

        if unlikely false === data {
            throw new RuntimeException("Could not read from the file/stream");
        }

        return data;
    }

    /**
     * Get stream metadata as an associative array or retrieve a specific key.
     *
     * The keys returned are identical to the keys returned from PHP's
     * stream_get_meta_data() function.
     *
     * @param mixed|null $key
     *
     * @return array|mixed|null
     */
    public function getMetadata(var key = null)
    {
        var metadata;

        if unlikely null === this->handle {
            return null;
        }

        let metadata = stream_get_meta_data(this->handle);

        if unlikely null === key {
            return metadata;
        }

        return this->getArrVal(metadata, key, []);
    }

    /**
     * Get the size of the stream if known.
     */
    public function getSize() -> null | int
    {
        var stats;

        if likely null !== this->handle {
            let stats = fstat(this->handle);

            if likely false !== stats {
                return this->getArrVal(stats, "size", null);
            }
        }

        return null;
    }

    /**
     * Returns whether or not the stream is readable.
     */
    public function isReadable() -> bool
    {
        var mode;

        let mode = (string) this->getMetadata("mode");

        return false !== strpbrk(mode, "r+");
    }

    /**
     * Returns whether or not the stream is seekable.
     */
    public function isSeekable() -> bool
    {
        return (bool) this->getMetadata("seekable");
    }

    /**
     * Returns whether or not the stream is writable.
     */
    public function isWritable() -> bool
    {
        var mode;

        let mode = (string) this->getMetadata("mode");

        return false !== strpbrk(mode, "xwca+");
    }

    /**
     * Read data from the stream.
     *
     * @param int $length
     *
     * @return string
     */
    public function read(var length) -> string
    {
        var data;

        this->checkHandle();
        this->checkReadable();

        let data = fread(this->handle, length);

        if unlikely false === data {
            throw new RuntimeException("Could not read from the file/stream");
        }

        return data;
    }

    /**
     * Seek to the beginning of the stream.
     *
     * If the stream is not seekable, this method will raise an exception;
     * otherwise, it will perform a seek(0).
     */
    public function rewind() -> void
    {
        this->seek(0);
    }

    /**
     * Seek to a position in the stream.
     *
     * @param int $offset
     * @param int $whence
     */
    public function seek(var offset, var whence = 0) -> void
    {
        var seeker;

        this->checkHandle();
        this->checkSeekable();

        let seeker = fseek(this->handle, offset, whence);

        if unlikely 0 !== seeker {
            throw new RuntimeException("Could not seek on the file pointer");
        }
    }

    /**
     * Sets the stream - existing instance
     *
     * @param mixed  $stream
     * @param string $mode
     */
    public function setStream(var stream, string! mode = "rb") -> void
    {
        var handle, version;

        let handle = stream;
        let version = phpversion();

        globals_set("warning.enable", false);

        if likely typeof stream === "string" {
            if version_compare(version, "8.0", ">=") {
                set_error_handler(
                    function (number, message, file, line) {
                        globals_set("warning.enable", true);
                    },
                    E_WARNING
                );
            } else {
                set_error_handler(
                    function (number, message, file, line, context) {
                        globals_set("warning.enable", true);
                    },
                    E_WARNING
                );
            }

            let handle = fopen(stream, mode);

            restore_error_handler();
        }

        if unlikely (
            globals_get("warning.enable") ||
            typeof handle !== "resource" ||
            "stream" !== get_resource_type(handle)
        ) {
            throw new RuntimeException(
                "The stream provided is not valid (string/resource) or could not be opened."
            );
        }

        let this->handle = handle,
            this->stream = stream;
    }

    /**
     * Returns the current position of the file read/write pointer
     *
     * @return int
     */
    public function tell() -> int
    {
        var position;

        this->checkHandle();

        let position = ftell(this->handle);

        if unlikely typeof position !== "int" {
            throw new Exception("Could not retrieve the pointer position");
        }

        return position;
    }

    /**
     * Write data to the stream.
     *
     * @param string $data
     *
     * @return int
     */
    public function write(var data) -> int
    {
        var bytes;

        this->checkHandle();
        this->checkWritable();

        let bytes = fwrite(this->handle, data);

        if unlikely false === bytes {
            throw new RuntimeException("Could not write to the file/stream");
        }

        return bytes;
    }

   /**
     * Checks if a handle is available and throws an exception otherwise
     */
    private function checkHandle() -> void
    {
        if unlikely null === this->handle {
            throw new RuntimeException("A valid resource is required.");
        }
    }

    /**
     * Checks if a handle is readable and throws an exception otherwise
     */
    private function checkReadable() -> void
    {
        if unlikely true !== this->isReadable() {
            throw new RuntimeException("The resource is not readable.");
        }
    }

    /**
     * Checks if a handle is seekable and throws an exception otherwise
     */
    private function checkSeekable() -> void
    {
        if unlikely true !== this->isSeekable() {
            throw new RuntimeException("The resource is not seekable.");
        }
    }

    /**
     * Checks if a handle is writeable and throws an exception otherwise
     */
    private function checkWritable() -> void
    {
        if unlikely true !== this->isWritable() {
            throw new RuntimeException("The resource is not writable.");
        }
    }

    /**
     * @todo Remove this when we get traits
     */
    private function getArrVal(
        array! collection,
        var index,
        var defaultValue = null
    ) -> var {
        var value;

        if unlikely !fetch value, collection[index] {
            return defaultValue;
        }

        return value;
    }
}
