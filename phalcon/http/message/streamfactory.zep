
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Http\Message;

use Phalcon\Http\Message\Stream;
use Psr\Http\Message\StreamInterface;
use Psr\Http\Message\StreamFactoryInterface;
use Psr\Http\Message\UriInterface;

class StreamFactory implements StreamFactoryInterface
{
    /**
     * Create a new stream from a string.
     *
     * The stream SHOULD be created with a temporary resource.
     *
     * @param string $content String content with which to populate the stream.
     */
    public function createStream(string content = "") -> <StreamInterface>
    {
		var tempResource;

		let tempResource = fopen("php://temp", "r+");

		fwrite(tempResource, content);
		rewind(tempResource);

		return this->createStreamFromResource(tempResource);
    }

    /**
     * Create a stream from an existing file.
     *
     * The file MUST be opened using the given mode, which may be any mode
     * supported by the `fopen` function.
     *
     * The `$filename` MAY be any string supported by `fopen()`.
     *
     * @param string $filename The filename or stream URI to use as basis of stream.
     * @param string $mode The mode with which to open the underlying filename/stream.
     *
     * @throws \RuntimeException If the file cannot be opened.
     * @throws \InvalidArgumentException If the mode is invalid.
     */
    public function createStreamFromFile(string filename, string mode = "r") -> <StreamInterface>
    {
		return new Stream(filename, mode);
    }

    /**
     * Create a new stream from an existing resource.
     *
     * The stream MUST be readable and may be writable.
     *
     * @param resource $resource The PHP resource to use as the basis for the stream.
     */
    public function createStreamFromResource(var phpResource) -> <StreamInterface>
    {
    	if (true !== is_resource(phpResource) || "stream" !== get_resource_type(phpResource)) {
            throw new \InvalidArgumentException(
                "StreamFactory:createStreamFromResource() - invalid stream provbided"
            );
        }

        return new Stream(phpResource);
    }
}
