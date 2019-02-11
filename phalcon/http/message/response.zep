
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
use Psr\Http\Message\ResponseInterface;
use Psr\Http\Message\StreamInterface;
use Phalcon\Utility;

/**
 * Representation of an outgoing, server-side response.
 *
 * Per the HTTP specification, this interface includes properties for
 * each of the following:
 *
 * - Protocol version
 * - Status code and reason phrase
 * - Headers
 * - Message body
 *
 * Responses are considered immutable; all methods that might change state MUST
 * be implemented such that they retain the internal state of the current
 * message and return an instance that contains the changed state.
 */
class Response implements ResponseInterface
{
	/**
	 * @var <StreamInterface>
	 */
	private body;

	/**
	 * @var int
	 */
	private code = 0;

	/**
	 * @var array
	 */
	private headers = [];

	/**
	 * @var string
	 */
	private protocol = "1.1";

	/**
	 * @var string
	 */
	private reason = "";

	/**
	 * Constructor
	 */
	public function __construct(var body = "php://memory", int code = 200, array headers = [])
	{
		this->processCode(code);
	}

	/**
	 * Gets the body of the message.
	 *
	 * @return StreamInterface Returns the body as a stream.
	 */
	public function getBody() -> <StreamInterface>
	{
		return this->body;
	}

	/**
	 * Retrieves a message header value by the given case-insensitive name.
	 *
	 * This method returns an array of all the header values of the given
	 * case-insensitive header name.
	 *
	 * If the header does not appear in the message, this method MUST return an
	 * empty array.
	 *
	 * @param string $name Case-insensitive header field name.
	 * @return string[] An array of string values as provided for the given
	 *    header. If the header does not appear in the message, this method MUST
	 *    return an empty array.
	 */
	public function getHeader(var name) -> string
	{

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
	 *
	 * @param string $name Case-insensitive header field name.
	 * @return string A string of values as provided for the given header
	 *    concatenated together using a comma. If the header does not appear in
	 *    the message, this method MUST return an empty string.
	 */
	public function getHeaderLine(var name) -> string
	{

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
	 *
	 * @return string[][] Returns an associative array of the message's headers.
	 *     Each key MUST be a header name, and each value MUST be an array of
	 *     strings for that header.
	 */
	public function getHeaders() -> array
	{
		return this->headers;
	}

	/**
	 * Retrieves the HTTP protocol version as a string.
	 *
	 * The string MUST contain only the HTTP version number (e.g., "1.1", "1.0").
	 *
	 * @return string HTTP protocol version.
	 */
	public function getProtocolVersion() -> string
	{
		return this->protocol;
	}

	/**
	 * Gets the response reason phrase associated with the status code.
	 *
	 * Because a reason phrase is not a required element in a response
	 * status line, the reason phrase value MAY be empty. Implementations MAY
	 * choose to return the default RFC 7231 recommended reason phrase (or those
	 * listed in the IANA HTTP Status Code Registry) for the response's
	 * status code.
	 *
	 * @see http://tools.ietf.org/html/rfc7231#section-6
	 * @see http://www.iana.org/assignments/http-status-codes/http-status-codes.xhtml
	 * @return string Reason phrase; must return an empty string if none present.
	 */
	public function getReasonPhrase() -> string
	{
		return this->reason;
	}

	/**
	 * Gets the response status code.
	 *
	 * The status code is a 3-digit integer result code of the server's attempt
	 * to understand and satisfy the request.
	 *
	 * @return int Status code.
	 */
	public function getStatusCode() -> int
	{
		return this->code;
	}

	/**
	 * Checks if a header exists by the given case-insensitive name.
	 *
	 * @param string $name Case-insensitive header field name.
	 * @return bool Returns true if any header names match the given header
	 *     name using a case-insensitive string comparison. Returns false if
	 *     no matching header name is found in the message.
	 */
	public function hasHeader(var name) -> bool
	{

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
	 *
	 * @param string $name Case-insensitive header field name to add.
	 * @param string|string[] $value Header value(s).
	 * @return static
	 * @throws \InvalidArgumentException for invalid header names.
	 * @throws \InvalidArgumentException for invalid header values.
	 */
	public function withAddedHeader(var name, var value) -> <ResponseInterface>
	{

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
	public function withBody(<StreamInterface> body) -> <ResponseInterface>
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
	 *
	 * @param string $name Case-insensitive header field name.
	 * @param string|string[] $value Header value(s).
	 * @return static
	 * @throws \InvalidArgumentException for invalid header names or values.
	 */
	public function withHeader(var name, var value) -> <ResponseInterface>
	{

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
	 *
	 * @param string $version HTTP protocol version
	 * @return static
	 */
	public function withProtocolVersion(var version) -> <ResponseInterface>
	{
    	var newInstance;

		if (version === this->protocol) {
            return this;
        }

		/**
		 * Immutable - need to send a new object back
		 */
        let newInstance           = clone this;
        let newInstance->protocol = version;

        return newInstance;

	}

	/**
	 * Return an instance with the specified status code and, optionally, reason phrase.
	 *
	 * If no reason phrase is specified, implementations MAY choose to default
	 * to the RFC 7231 or IANA recommended reason phrase for the response's
	 * status code.
	 *
	 * This method MUST be implemented in such a way as to retain the
	 * immutability of the message, and MUST return an instance that has the
	 * updated status and reason phrase.
	 *
	 * @see http://tools.ietf.org/html/rfc7231#section-6
	 * @see http://www.iana.org/assignments/http-status-codes/http-status-codes.xhtml
	 * @param int $code The 3-digit integer result code to set.
	 * @param string $reasonPhrase The reason phrase to use with the
	 *     provided status code; if none is provided, implementations MAY
	 *     use the defaults as suggested in the HTTP specification.
	 * @return static
	 * @throws \InvalidArgumentException For invalid status code arguments.
	 */
	public function withStatus(var code, var reasonPhrase = "") -> <ResponseInterface>
	{
    	var newInstance;

		if (code === this->code) {
            return this;
        }

		/**
		 * Immutable - need to send a new object back
		 */
        let newInstance = clone this;

		newInstance->processCode(code, reasonPhrase);

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
	 *
	 * @param string $name Case-insensitive header field name to remove.
	 * @return static
	 */
	public function withoutHeader(var name) -> <ResponseInterface>
	{

	}

	/**
	 * Returns the list of status codes available
	 */
	private function getPhrases() -> array
	{
		return [
			100 : "Continue",                                         // Information - RFC 7231, 6.2.1
			101 : "Switching Protocols",                              // Information - RFC 7231, 6.2.2
			102 : "Processing",                                       // Information - RFC 2518, 10.1
			103 : "Early Hints",
			200 : "OK",                                               // Success - RFC 7231, 6.3.1
			201 : "Created",                                          // Success - RFC 7231, 6.3.2
			202 : "Accepted",                                         // Success - RFC 7231, 6.3.3
			203 : "Non-Authoritative Information",                    // Success - RFC 7231, 6.3.4
			204 : "No Content",                                       // Success - RFC 7231, 6.3.5
			205 : "Reset Content",                                    // Success - RFC 7231, 6.3.6
			206 : "Partial Content",                                  // Success - RFC 7233, 4.1
			207 : "Multi-status",                                     // Success - RFC 4918, 11.1
			208 : "Already Reported",                                 // Success - RFC 5842, 7.1
			218 : "This is fine",                                     // Unofficial - Apache Web Server
			419 : "Page Expired",                                     // Unofficial - Laravel Framework
			226 : "IM Used",                                          // Success - RFC 3229, 10.4.1
			300 : "Multiple Choices",                                 // Redirection - RFC 7231, 6.4.1
			301 : "Moved Permanently",                                // Redirection - RFC 7231, 6.4.2
			302 : "Found",                                            // Redirection - RFC 7231, 6.4.3
			303 : "See Other",                                        // Redirection - RFC 7231, 6.4.4
			304 : "Not Modified",                                     // Redirection - RFC 7232, 4.1
			305 : "Use Proxy",                                        // Redirection - RFC 7231, 6.4.5
			306 : "Switch Proxy",                                     // Redirection - RFC 7231, 6.4.6 (Deprecated)
			307 : "Temporary Redirect",                               // Redirection - RFC 7231, 6.4.7
			308 : "Permanent Redirect",                               // Redirection - RFC 7538, 3
			400 : "Bad Request",                                      // Client Error - RFC 7231, 6.5.1
			401 : "Unauthorized",                                     // Client Error - RFC 7235, 3.1
			402 : "Payment Required",                                 // Client Error - RFC 7231, 6.5.2
			403 : "Forbidden",                                        // Client Error - RFC 7231, 6.5.3
			404 : "Not Found",                                        // Client Error - RFC 7231, 6.5.4
			405 : "Method Not Allowed",                               // Client Error - RFC 7231, 6.5.5
			406 : "Not Acceptable",                                   // Client Error - RFC 7231, 6.5.6
			407 : "Proxy Authentication Required",                    // Client Error - RFC 7235, 3.2
			408 : "Request Time-out",                                 // Client Error - RFC 7231, 6.5.7
			409 : "Conflict",                                         // Client Error - RFC 7231, 6.5.8
			410 : "Gone",                                             // Client Error - RFC 7231, 6.5.9
			411 : "Length Required",                                  // Client Error - RFC 7231, 6.5.10
			412 : "Precondition Failed",                              // Client Error - RFC 7232, 4.2
			413 : "Request Entity Too Large",                         // Client Error - RFC 7231, 6.5.11
			414 : "Request-URI Too Large",                            // Client Error - RFC 7231, 6.5.12
			415 : "Unsupported Media Type",                           // Client Error - RFC 7231, 6.5.13
			416 : "Requested range not satisfiable",                  // Client Error - RFC 7233, 4.4
			417 : "Expectation Failed",                               // Client Error - RFC 7231, 6.5.14
			418 : "I'm a teapot",                                     // Client Error - RFC 7168, 2.3.3
			420 : "Method Failure",                                   // Unofficial - Spring Framework
			420 : "Enhance Your Calm",                                // Unofficial - Twitter
			421 : "Misdirected Request",
			422 : "Unprocessable Entity",                             // Client Error - RFC 4918, 11.2
			423 : "Locked",                                           // Client Error - RFC 4918, 11.3
			424 : "Failed Dependency",                                // Client Error - RFC 4918, 11.4
			425 : "Unordered Collection",
			426 : "Upgrade Required",                                 // Client Error - RFC 7231, 6.5.15
			428 : "Precondition Required",                            // Client Error - RFC 6585, 3
			429 : "Too Many Requests",                                // Client Error - RFC 6585, 4
			431 : "Request Header Fields Too Large",                  // Client Error - RFC 6585, 5
			440 : "Login Time-out",                                   // Unofficial - IIS
			444 : "No Response",                                      // Unofficial - nginx
			449 : "Retry With",                                       // Unofficial - IIS
			451 : "Redirect",                                         // Unofficial - IIS
			494 : "Request header too large",                         // Unofficial - nginx
			495 : "SSL Certificate Error",                            // Unofficial - nginx
			496 : "SSL Certificate Required",                         // Unofficial - nginx
			497 : "HTTP Request Sent to HTTPS Port",                  // Unofficial - nginx
			499 : "Client Closed Request",                            // Unofficial - nginx
			450 : "Blocked by Windows Parental Controls (Microsoft)", // Unofficial - nginx
			451 : "Unavailable For Legal Reasons",                    // Client Error - RFC 7725, 3
			498 : "Invalid Token (Esri)",                             // Unofficial - ESRI
			499 : "Client Closed Request",
			500 : "Internal Server Error",                            // Server Error - RFC 7231, 6.6.1
			501 : "Not Implemented",                                  // Server Error - RFC 7231, 6.6.2
			502 : "Bad Gateway",                                      // Server Error - RFC 7231, 6.6.3
			503 : "Service Unavailable",                              // Server Error - RFC 7231, 6.6.4
			504 : "Gateway Time-out",                                 // Server Error - RFC 7231, 6.6.5
			505 : "HTTP Version not supported",                       // Server Error - RFC 7231, 6.6.6
			506 : "Variant Also Negotiates",                          // Server Error - RFC 2295, 8.1
			507 : "Insufficient Storage",                             // Server Error - RFC 4918, 11.5
			508 : "Loop Detected",                                    // Server Error - RFC 5842, 7.2
            509 : "Bandwidth Limit Exceeded",                         // Unofficial - Apache/cPanel
			510 : "Not Extended",                                     // Server Error - RFC 2774, 7
			511 : "Network Authentication Required",                  // Server Error - RFC 6585, 6
			520 : "Unknown Error",                                    // Unofficial - Cloudflare
			521 : "Web Server Is Down",                               // Unofficial - Cloudflare
			522 : "Connection Timed Out",                             // Unofficial - Cloudflare
			523 : "Origin Is Unreachable",                            // Unofficial - Cloudflare
			524 : "A Timeout Occurred",                               // Unofficial - Cloudflare
			525 : "SSL Handshake Failed",                             // Unofficial - Cloudflare
			526 : "Invalid SSL Certificate",                          // Unofficial - Cloudflare
			527 : "Railgun Error",                                    // Unofficial - Cloudflare
			530 : "Origin DNS Error",                                 // Unofficial - Cloudflare
			598 : "Network read timeout error",                       // Unofficial
			599 : "Network Connect Timeout Error"                     // Server Error - RFC 6585, 6
		];
	}

	/**
	 * Set a valid status code and phrase
	 */
	private function processCode(var code, var phrase = "") -> void
	{
		var keys, max, min, phrases;

		let phrases = this->getPhrases(),
			keys    = array_keys(phrases),
			min     = min(keys),
			max     = max(keys);

		if (true !== is_numeric(code) ||
			true === is_float(code)   ||
			code < min                ||
			code > max
		) {
			throw new \InvalidArgumentException(
				"Invalid status code '" . code . "', (allowed values " . min . "-" . max . ")"
			);
		}

		if true !== is_string(phrase) {
			throw new \InvalidArgumentException("Invalid response reason");
		}

		if ("" === phrase && true === isset(phrases[code])) {
			let phrase = phrases[code];
		}

		let this->code   = code,
			this->reason = phrase;
	}

	private function processStream(var body = "php://memody", string mode) -> <StreamInterface>
	{
		if body instanceof StreamInterface {
			return body;
		}

		if (typeof body !== "string" && true !== is_resource(body)) {
			throw new \InvalidArgumentException("Invalid stream passed as a parameter");
		}

		return new Stream(body, mode);
	}
}
