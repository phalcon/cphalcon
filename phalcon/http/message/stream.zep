
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

use Psr\Http\Message\StreamInterface;
use Phalcon\Utility;

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
	 * @var resource
	 */
	protected handle = null;

	/**
	 * @var resource | string
	 */
	protected stream;

	/**
	 * @var array
	 */
	protected metadata = [];

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

    }

    /**
     * Closes the stream and any underlying resources.
     */
    public function close() -> void
    {
    	var handle;

		if this->handle {
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

    }

    /**
     * Get stream metadata as an associative array or retrieve a specific key.
     *
     * The keys returned are identical to the keys returned from PHP's
     * stream_get_meta_data() function.
     */
    public function getMetadata(var key = null) -> var
    {

    }

    /**
     * Get the size of the stream if known.
     */
    public function getSize() -> null | int
    {
		var stats;

		if this->handle {
			let stats = fstat(this->handle);
			if false !== stats {
				return Utility::arrayGetDefault("size", stats, null);
			}
		}

		return null;
    }

    /**
     * Returns whether or not the stream is readable.
     */
    public function isReadable() -> bool
    {

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

    }

    /**
     * Read data from the stream.
     */
    public function read(var length)-> string
    {

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

    }

    /**
     * Returns the current position of the file read/write pointer
     */
    public function tell() -> int
    {

    }

    /**
     * Write data to the stream.
     */
    public function write(var data) -> int
    {

    }
}
