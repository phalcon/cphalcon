
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

use Phalcon\Http\Message\AbstractMessage;
use Psr\Http\Message\RequestInterface;
use Psr\Http\Message\StreamInterface;
use Psr\Http\Message\UriInterface;

/**
 * Abstract class to offer common message methods for PSR-7
 *
 * In the future this can move into a trait and the properties/methods can become
 * private
 */
class AbstractRequest extends AbstractMessage implements RequestInterface
{
	/**
	 * @var string
	 */
	protected method = "GET" { get };

	/**
	 * The request-target, if it has been provided or calculated.
	 *
	 * @var null|string
	 */
	protected requestTarget;
	
	/**
	 * Retrieves the URI instance.
	 *
	 * This method MUST return a UriInterface instance.
	 *
	 * @link http://tools.ietf.org/html/rfc3986#section-4.3
	 *
	 * @var <UriInterface>
	 */
	protected uri { get };

	/**
	 * Retrieves the message"s request target.
	 *
	 * Retrieves the message"s request-target either as it will appear (for
	 * clients), as it appeared at request (for servers), or as it was
	 * specified for the instance (see withRequestTarget()).
	 *
	 * In most cases, this will be the origin-form of the composed URI,
	 * unless a value was provided to the concrete implementation (see
	 * withRequestTarget() below).
	 *
	 * If no URI is available, and no request-target has been specifically
	 * provided, this method MUST return the string "/".
	 */
	public function getRequestTarget() -> string
	{

	}

	/**
	 * Return an instance with the provided HTTP method.
	 *
	 * While HTTP method names are typically all uppercase characters, HTTP
	 * method names are case-sensitive and thus implementations SHOULD NOT
	 * modify the given string.
	 *
	 * This method MUST be implemented in such a way as to retain the
	 * immutability of the message, and MUST return an instance that has the
	 * changed request method.
	 *
	 * @param string $method Case-insensitive method.
	 * @throws Exception\InvalidArgumentException for invalid HTTP methods.
	 */
	public function withMethod(var method) -> <RequestInterface>
	{
		var newInstance;

		let newInstance = this;

		newInstance->setMethod(method);

		return newInstance;
	}

	/**
	 * Create a new instance with a specific request-target.
	 *
	 * If the request needs a non-origin-form request-target — e.g., for
	 * specifying an absolute-form, authority-form, or asterisk-form —
	 * this method may be used to create an instance with the specified
	 * request-target, verbatim.
	 *
	 * This method MUST be implemented in such a way as to retain the
	 * immutability of the message, and MUST return a new instance that has the
	 * changed request target.
	 *
	 * @link http://tools.ietf.org/html/rfc7230#section-2.7 (for the various
	 *     request-target forms allowed in request messages)
	 * @param string $requestTarget
	 * @throws Exception\InvalidArgumentException if the request target is invalid.
	 */
	public function withRequestTarget(var requestTarget) -> <RequestInterface>
	{

	}

	/**
	 * Returns an instance with the provided URI.
	 *
	 * This method MUST update the Host header of the returned request by
	 * default if the URI contains a host component. If the URI does not
	 * contain a host component, any pre-existing Host header MUST be carried
	 * over to the returned request.
	 *
	 * You can opt-in to preserving the original state of the Host header by
	 * setting `$preserveHost` to `true`. When `$preserveHost` is set to
	 * `true`, this method interacts with the Host header in the following ways:
	 *
	 * - If the Host header is missing or empty, and the new URI contains
	 *   a host component, this method MUST update the Host header in the returned
	 *   request.
	 * - If the Host header is missing or empty, and the new URI does not contain a
	 *   host component, this method MUST NOT update the Host header in the returned
	 *   request.
	 * - If a Host header is present and non-empty, this method MUST NOT update
	 *   the Host header in the returned request.
	 *
	 * This method MUST be implemented in such a way as to retain the
	 * immutability of the message, and MUST return an instance that has the
	 * new UriInterface instance.
	 *
	 * @see http://tools.ietf.org/html/rfc3986#section-4.3
	 */
	public function withUri(<UriInterface> uri, var preserveHost = false) -> <RequestInterface>
	{

	}

	/**
	 * Sets the method, performing some validation on it
	 */
	private function setMethod(var method) -> void
	{
		array available;

		if typeof method !== "string" {
			throw new \InvalidArgumentException(
				"The method passed must be a string"
			);
		}

		let available = [
			"OPTIONS" : 1,
			"GET"     : 1,
			"HEAD"    : 1,
			"POST"    : 1,
			"PUT"     : 1,
			"DELETE"  : 1,
			"TRACE"   : 1,
			"CONNECT" : 1
		];

		if true !== isset(available[method]) {
			throw new \InvalidArgumentException("Unsupported HTTP method");
		}

		let this->method = method;
	}
}
