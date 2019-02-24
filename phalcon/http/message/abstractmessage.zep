
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

use Psr\Http\Message\MessageInterface;
use Psr\Http\Message\StreamInterface;

/**
 * Abstract class to offer common message methods for PSR-7
 *
 * In the future this can move into a trait and the properties/methods can become
 * private
 */
class AbstractMessage implements MessageInterface
{
	/**
	 * Gets the body of the message.
	 *
	 * @var <StreamInterface>
	 */
	protected body { get };

	/**
	 * @var array
	 */
	protected headers = [];

	/**
	 * Retrieves the HTTP protocol version as a string.
	 *
	 * The string MUST contain only the HTTP version number (e.g., "1.1", "1.0").
	 *
	 * @var string
	 */
	protected protocolVersion = "1.1" { get };

	/**
	 * Retrieves a message header value by the given case-insensitive name.
	 *
	 * This method returns an array of all the header values of the given
	 * case-insensitive header name.
	 *
	 * If the header does not appear in the message, this method MUST return an
	 * empty array.
	 */
	public function getHeader(var name) -> array
	{
		var header, key;

		let key = strtolower(name);

		if fetch header, this->headers[key] {
			return header["value"];
		}

		return [];
	}

	/**
	 * Retrieves a comma-separated string of the values for a single header.
	 *
	 * This method returns all of the header values of the given
	 * case-insensitive header name as a string concatenated together using
	 * a comma.
	 *
	 * NOTE: Not all header values may be appropriately represented using
	 * comma concatenation. For such headers, use getHeader() instead
	 * and supply your own delimiter when concatenating.
	 *
	 * If the header does not appear in the message, this method MUST return
	 * an empty string.
	 */
	public function getHeaderLine(var name) -> string
	{
		var header;

		let header = this->getHeader(name);

		if true !== empty(header) {
			return implode(",", header);
		}

		return "";
	}

	/**
	 * Retrieves all message header values.
	 *
	 * The keys represent the header name as it will be sent over the wire, and
	 * each value is an array of strings associated with the header.
	 *
	 *     // Represent the headers as a string
	 *     foreach ($message->getHeaders() as $name => $values) {
	 *         echo $name . ': ' . implode(', ', $values);
	 *     }
	 *
	 *     // Emit headers iteratively:
	 *     foreach ($message->getHeaders() as $name => $values) {
	 *         foreach ($values as $value) {
	 *             header(sprintf('%s: %s', $name, $value), false);
	 *         }
	 *     }
	 *
	 * While header names are not case-sensitive, getHeaders() will preserve the
	 * exact case in which headers were originally specified.
	 */
	public function getHeaders() -> array
	{
		var element;
		array headers;

		let headers = [];

		for element in this->headers {
			let headers[element["name"]] = element["value"];
		}

		return headers;
	}

	/**
	 * Checks if a header exists by the given case-insensitive name.
	 */
	public function hasHeader(var name) -> bool
	{
		return isset(this->headers[strtolower(name)]);
	}

	/**
	 * Return an instance with the specified header appended with the given value.
	 *
	 * Existing values for the specified header will be maintained. The new
	 * value(s) will be appended to the existing list. If the header did not
	 * exist previously, it will be added.
	 *
	 * This method MUST be implemented in such a way as to retain the
	 * immutability of the message, and MUST return an instance that has the
	 * new header and/or value.
	 */
	public function withAddedHeader(var name, var value) -> <MessageInterface>
	{
		var key, headers, newInstance, values;

		if true !== this->hasHeader(name) {
			return this->withHeader(name, value);
		}

		let key         = strtolower(name),
			newInstance = clone this,
			headers     = newInstance->headers;

		let values = headers[key]["value"],
			values = array_merge(values, value);

		let headers[key]["value"] = values;

		let newInstance->headers = headers;

		return newInstance;
	}

	/**
	 * Return an instance with the specified message body.
	 *
	 * The body MUST be a StreamInterface object.
	 *
	 * This method MUST be implemented in such a way as to retain the
	 * immutability of the message, and MUST return a new instance that has the
	 * new body stream.
	 */
	public function withBody(<StreamInterface> body) -> <MessageInterface>
	{
    	var newInstance;

		if (body === this->body) {
            return this;
        }

		/**
		 * Immutable - need to send a new object back
		 */
        let newInstance       = clone this;
        let newInstance->body = body;

        return newInstance;
	}

	/**
	 * Return an instance with the provided value replacing the specified header.
	 *
	 * While header names are case-insensitive, the casing of the header will
	 * be preserved by this function, and returned from getHeaders().
	 *
	 * This method MUST be implemented in such a way as to retain the
	 * immutability of the message, and MUST return an instance that has the
	 * new and/or updated header and value.
	 */
	public function withHeader(var name, var value) -> <MessageInterface>
	{
		var key, newInstance;

		let key = strtolower(name);

		let newInstance               = clone this;
		let newInstance->headers[key] = value;

		return newInstance;
	}

	/**
	 * Return an instance with the specified HTTP protocol version.
	 *
	 * The version string MUST contain only the HTTP version number (e.g.,
	 * "1.1", "1.0").
	 *
	 * This method MUST be implemented in such a way as to retain the
	 * immutability of the message, and MUST return an instance that has the
	 * new protocol version.
	 */
	public function withProtocolVersion(var version) -> <MessageInterface>
	{
    	var newInstance;

		this->processProtocol(version);

		if (version === this->protocolVersion) {
            return this;
        }

		/**
		 * Immutable - need to send a new object back
		 */
        let newInstance                  = clone this;
        let newInstance->protocolVersion = version;

        return newInstance;

	}

	/**
	 * Return an instance without the specified header.
	 *
	 * Header resolution MUST be done without case-sensitivity.
	 *
	 * This method MUST be implemented in such a way as to retain the
	 * immutability of the message, and MUST return an instance that removes
	 * the named header.
	 */
	public function withoutHeader(var name) -> <MessageInterface>
	{
		var key, newInstance;

		let key         = strtolower(name),
			newInstance = clone this;

		unset(newInstance->headers[key]);

		return newInstance;
	}

	/**
	 * Checks if the value of a header is valid. As per RFC 7230, ASCII characters,
	 * spaces and horizontal tabs are allowed. Need to also check for visible
	 * characters
	 */
	private function isValidHeaderValue(var value) -> bool
	{
		let value = (string) value;

        if (preg_match("#(?:(?:(?<!\r)\n)|(?:\r(?!\n))|(?:\r\n(?![ \t])))#", value) ||
        	preg_match("/[^\x09\x0a\x0d\x20-\x7E\x80-\xFE]/", value)) {
            return false;
        }

        return true;
	}

	/**
	 * Sets the headers
	 */
	protected function processHeaders(array headers) -> void
	{
		var key, name, value;
		array headerData;

		let headerData = [];
		for name, value in headers {
			let key = strtolower(name);

			let headerData[key] = [
				"name"  : name,
				"value" : value
			];
		}

		let this->headers = headerData;
	}

	/**
	 * Checks the protocol
	 */
	protected function processProtocol(var protocol = "") -> void
	{
    	array protocols;

    	let protocols = [
    		"1.0" : 1,
    		"1.1" : 1,
    		"2.0" : 1,
    		"3.0" : 1
    	];

    	if (true === empty(protocol) || typeof protocol !== "string") {
    		throw new \InvalidArgumentException("Invalid protocol value");
    	}

    	if true !== isset(protocols[protocol]) {
			throw new \InvalidArgumentException("Unsupported protocol " . protocol);
		}
	}

	/**
	 * Set a valid stream
	 */
	protected function processStream(var body = "php://memory", string mode) -> <StreamInterface>
	{
		if body instanceof StreamInterface {
			return body;
		}

		if (typeof body !== "string" && (true !== is_resource(body))) {
			throw new \InvalidArgumentException("Invalid stream passed as a parameter");
		}

		return new Stream(body, mode);
	}
}
