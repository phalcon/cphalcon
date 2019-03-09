
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by Zend Diactoros
 * @link    https://github.com/zendframework/zend-diactoros
 * @license https://github.com/zendframework/zend-diactoros/blob/master/LICENSE.md
 */

namespace Phalcon\Http\Message;

use Phalcon\Helper\Arr;
use Phalcon\Http\Message\Exception;
use Psr\Http\Message\StreamInterface;

/**
 * Describes a data stream.
 *
 * Typically, an instance will wrap a PHP stream; this interface provides
 * a wrapper around the most common operations, including serialization of
 * the entire stream to a string.
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
	 * @var bool
	 */
	protected warning = false;

	/**
	 * Constructor
	 */
	public function __construct(var stream, var mode = "rb") -> void
	{
		this->setStream(stream, mode);
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
			if true === this->isReadable() {
				if true === this->isSeekable() {
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

		if null !== this->handle {
			let handle = this->detach();
			fclose(handle);
		}
    }

    /**
     * Separates any underlying resources from the stream.
     *
     * After the stream has been detached, the stream is in an unusable state.
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
		if this->handle {
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

		if false === data {
			throw new Exception("Could not read from the file/stream");
		}

		return data;

    }

    /**
     * Get stream metadata as an associative array or retrieve a specific key.
     *
     * The keys returned are identical to the keys returned from PHP's
     * stream_get_meta_data() function.
     */
    public function getMetadata(var key = null) -> null | var
    {
    	var metadata;

		if null === this->handle {
			return null;
		}

		let metadata = stream_get_meta_data(this->handle);

		if null === key {
			return metadata;
		}

		return Arr::get(metadata, key, []);
    }

    /**
     * Get the size of the stream if known.
     */
    public function getSize() -> null | int
    {
		var stats;

		if null !== this->handle {
			let stats = fstat(this->handle);
			if false !== stats {
				return Arr::get(stats, "size", null);
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

		let mode = this->getMetadata("mode");

		return (false !== strpos(mode, "r") || false !== strpos(mode, "+"));
    }

    /**
     * Returns whether or not the stream is seekable.
     */
    public function isSeekable() -> bool
    {
    	return boolval(this->getMetadata("seekable"));
    }

    /**
     * Returns whether or not the stream is writable.
     */
    public function isWritable() -> bool
    {
		var mode;

		let mode = this->getMetadata("mode");

		return (
			false !== strpos(mode, "x") ||
			false !== strpos(mode, "w") ||
			false !== strpos(mode, "c") ||
			false !== strpos(mode, "a") ||
			false !== strpos(mode, "+")
		);
    }

    /**
     * Read data from the stream.
     */
    public function read(var length)-> string
    {
		var data;

		this->checkHandle();
		this->checkReadable();

		let data = fread(this->handle, length);

		if false === data {
			throw new Exception("Could not read from the file/stream");
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
     */
    public function seek(var offset, var whence = 0) -> void
    {
    	var seeker;

		this->checkHandle();
		this->checkSeekable();

		let seeker = fseek(this->handle, offset, whence);

		if 0 !== seeker {
			throw new Exception("Cound not seek on the file pointer");
		}
    }

	/**
	 * Sets the stream - existing instance
	 */
	public function setStream(var stream, var mode = "r") -> void
	{
		var handle;

		let handle = stream;

		if typeof stream === "string" {
			set_error_handler(
				function (error) {
					let this->warning = true;
				}
			);
			let handle = fopen(stream, mode);
			restore_error_handler();
		}

		if true === this->warning || typeof handle !== "resource" || "stream" !== get_resource_type(handle) {
			throw new Exception(
				"The stream provided is not valid (string/resource) or could not be opened."
			);
		}

		let this->handle = handle,
			this->stream = stream;
	}

    /**
     * Returns the current position of the file read/write pointer
     */
    public function tell() -> int
    {
    	var position;

		this->checkHandle();
		let position = ftell(this->handle);

		if typeof position !== "int" {
			throw new Exception("Could not retrieve the pointer position");
		}

		return position;
    }

    /**
     * Write data to the stream.
     */
    public function write(var data) -> int
    {
		var bytes;

		this->checkHandle();
		this->checkWritable();

		let bytes = fwrite(this->handle, data);

		if false === bytes {
			throw new Exception("Could not write to the file/stream");
		}

		return bytes;
    }

	/**
	 * Checks if a handle is available and throws an exception otherwise
	 */
    private function checkHandle() -> void
    {
    	if null === this->handle {
    		throw new Exception("A valid resource is required.");
    	}
    }

	/**
	 * Checks if a handle is readable and throws an exception otherwise
	 */
    private function checkReadable() -> void
    {
    	if true !== this->isReadable() {
    		throw new Exception("The resource is not readable.");
    	}
    }

	/**
	 * Checks if a handle is seekable and throws an exception otherwise
	 */
    private function checkSeekable() -> void
    {
    	if true !== this->isSeekable() {
    		throw new Exception("The resource is not seekable.");
    	}
    }

	/**
	 * Checks if a handle is writeable and throws an exception otherwise
	 */
    private function checkWritable() -> void
    {
    	if true !== this->isWritable() {
    		throw new Exception("The resource is not writable.");
    	}
    }
}
