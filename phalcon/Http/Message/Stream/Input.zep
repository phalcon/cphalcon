
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

namespace Phalcon\Http\Message\Stream;

use Phalcon\Http\Message\Stream;

/**
 * Describes a data stream from "php://input"
 *
 * Typically, an instance will wrap a PHP stream; this interface provides
 * a wrapper around the most common operations, including serialization of
 * the entire stream to a string.
 */
class Input extends Stream
{
    /**
     * @var string
     */
    private data = "";

    /**
     * @var bool
     */
    private eof = false;

    /**
     * Input constructor.
     */
    public function __construct()
    {
        parent::__construct("php://input", "rb");
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
        if unlikely this->eof {
            return this->data;
        }

        this->getContents();

        return this->data;
    }

    /**
     * Returns the remaining contents in a string
     *
     * @param int $length
     *
     * @throws \RuntimeException If unable to read or if error occurs while reading.
     * @return string
     */
    public function getContents(int length = -1) -> string
    {
        var data;

        if unlikely this->eof {
            return this->data;
        }

        let data       = stream_get_contents(this->handle, length),
            this->data = data;

        if unlikely (-1 === length || this->eof()) {
            let this->eof = true;
        }

        return this->data;
    }

    /**
     * Returns whether or not the stream is writeable.
     */
    public function isWritable() -> bool
    {
        return false;
    }

    /**
     * Read data from the stream.
     *
     * @param int $length
     *
     * @return string
     */
    public function read(var length)-> string
    {
        var data;

        let data = parent::read(length);

        if unlikely true !== this->eof {
            let this->data = data;
        }

        if unlikely this->eof() {
            let this->eof = true;
        }

        return data;
    }
}
