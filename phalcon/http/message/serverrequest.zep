
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

use Phalcon\Collection;
use Phalcon\Http\Message\Stream\Input;
use Phalcon\Http\Message\Uri;
use Psr\Http\Message\MessageInterface;
use Psr\Http\Message\RequestInterface;
use Psr\Http\Message\ServerRequestInterface;
use Psr\Http\Message\StreamInterface;
use Psr\Http\Message\UploadedFileInterface;
use Psr\Http\Message\UriInterface;

/**
 * Representation of an incoming, server-side HTTP request.
 *
 * Per the HTTP specification, this interface includes properties for
 * each of the following:
 *
 * - Protocol version
 * - HTTP method
 * - URI
 * - Headers
 * - Message body
 *
 * Additionally, it encapsulates all data as it has arrived at the
 * application from the CGI and/or PHP environment, including:
 *
 * - The values represented in _SERVER.
 * - Any cookies provided (generally via _COOKIE)
 * - Query string arguments (generally via _GET, or as parsed via parse_str())
 * - Upload files, if any (as represented by _FILES)
 * - Deserialized body parameters (generally from _POST)
 *
 * _SERVER values MUST be treated as immutable, as they represent application
 * state at the time of request; as such, no methods are provided to allow
 * modification of those values. The other values provide such methods, as they
 * can be restored from _SERVER or the request body, and may need treatment
 * during the application (e.g., body parameters may be deserialized based on
 * content type).
 *
 * Additionally, this interface recognizes the utility of introspecting a
 * request to derive and match additional parameters (e.g., via URI path
 * matching, decrypting cookie values, deserializing non-form-encoded body
 * content, matching authorization headers to users, etc). These parameters
 * are stored in an "attributes" property.
 *
 * Requests are considered immutable; all methods that might change state MUST
 * be implemented such that they retain the internal state of the current
 * message and return an instance that contains the changed state.
 */
class ServerRequest implements ServerRequestInterface
{
	/**
	 * @var <Collection>
	 */
	private attributes;

	/**
	 * Gets the body of the message.
	 *
	 * @var <StreamInterface>
	 */
	private body { get };

	/**
	 * Retrieve cookies.
	 *
	 * Retrieves cookies sent by the client to the server.
	 *
	 * The data MUST be compatible with the structure of the $_COOKIE
	 * superglobal.
	 *
	 * @var array
	 */
	private cookieParams = [] { get };

    /**
	 * @var <Collection>
     */
	private headers;

	/**
	 * Retrieves the HTTP method of the request.
	 *
	 * @var string
	 */
	private method = "GET" { get };

	/**
	 * Retrieve any parameters provided in the request body.
	 *
	 * If the request Content-Type is either application/x-www-form-urlencoded
	 * or multipart/form-data, and the request method is POST, this method MUST
	 * return the contents of $_POST.
	 *
	 * Otherwise, this method may return any results of deserializing
	 * the request body content; as parsing returns structured content, the
	 * potential types MUST be arrays or objects only. A null value indicates
	 * the absence of body content.
	 *
	 * @var mixed
	 */
	private parsedBody { get };

    /**
     * Retrieves the HTTP protocol version as a string.
     *
     * The string MUST contain only the HTTP version number (e.g., "1.1", "1.0").
     *
     * @return string HTTP protocol version.
     *
     * @var string
     */
    private protocolVersion = "1.1" { get };

	/**
	 * Retrieve query string arguments.
	 *
	 * Retrieves the deserialized query string arguments, if any.
	 *
	 * Note: the query params might not be in sync with the URI or server
	 * params. If you need to ensure you are only getting the original
	 * values, you may need to parse the query string from `getUri()->getQuery()`
	 * or from the `QUERY_STRING` server param.
	 *
	 * @var array
	 */
	private queryParams = [] { get };

	/**
	 * The request-target, if it has been provided or calculated.
	 *
	 * @var null|string
	 */
	private requestTarget;

	/**
	 * Retrieve server parameters.
	 *
	 * Retrieves data related to the incoming request environment,
	 * typically derived from PHP's $_SERVER superglobal. The data IS NOT
	 * REQUIRED to originate from $_SERVER.
	 *
	 * @var array
	 */
	private serverParams = [] { get };

	/**
	 * Retrieve normalized file upload data.
	 *
	 * This method returns upload metadata in a normalized tree, with each leaf
	 * an instance of Psr\Http\Message\UploadedFileInterface.
	 *
	 * These values MAY be prepared from $_FILES or the message body during
	 * instantiation, or MAY be injected via withUploadedFiles().
	 *
	 * @var array
	 */
	private uploadedFiles = [] { get };

	/**
	 * Retrieves the URI instance.
	 *
	 * This method MUST return a UriInterface instance.
	 *
	 * @see http://tools.ietf.org/html/rfc3986#section-4.3
	 *
	 * @var <UriInterface>
	 */
	private uri { get };

	/**
	 * Constructor
	 */
	public function __construct(
		string method = "GET",
		var uri = null,
		array serverParams = [],
		var body = "php://input",
		var headers = [],
		array cookies = [],
		array queryParams = [],
		array uploadFiles = [],
		var parsedBody = null,
		string protocol = "1.1"
	) {

		if "php://input" === body {
			let body = new Input();
		}

		this->checkUploadedFiles(uploadFiles);

		let this->protocolVersion = this->processProtocol(protocol),
			this->method          = this->processMethod(method),
			this->headers         = this->processHeaders(headers),
			this->uri             = this->processUri(uri),
			this->body            = this->processBody(body, "w+b"),
			this->uploadedFiles   = uploadFiles,
			this->parsedBody      = parsedBody,
			this->serverParams    = serverParams,
			this->cookieParams    = cookies,
			this->queryParams     = queryParams,
			this->attributes      = new Collection()
		;
	}

	/**
	 * Retrieve a single derived request attribute.
	 *
	 * Retrieves a single derived request attribute as described in
	 * getAttributes(). If the attribute has not been previously set, returns
	 * the default value as provided.
	 *
	 * This method obviates the need for a hasAttribute() method, as it allows
	 * specifying a default value to return if the attribute is not found.
	 */
	public function getAttribute(var name, var defaultValue = null) -> var
	{
		return this->attributes->get(name, defaultValue);
	}

	/**
	 * Retrieve attributes derived from the request.
	 *
	 * The request "attributes" may be used to allow injection of any
	 * parameters derived from the request: e.g., the results of path
	 * match operations; the results of decrypting cookies; the results of
	 * deserializing non-form-encoded message bodies; etc. Attributes
	 * will be application and request specific, and CAN be mutable.
	 */
	public function getAttributes() -> array
	{
		return this->attributes->toArray();
	}

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
		let name = (string) name;

		return this->headers->get(name, []);
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

    	if count(header) > 0 {
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
		return this->headers->toArray();
	}

	/**
	 * Retrieves the message's request target.
	 *
	 * Retrieves the message's request-target either as it will appear (for
	 * clients), as it appeared at request (for servers), or as it was
	 * specified for the instance (see withRequestTarget()).
	 *
	 * In most cases, this will be the origin-form of the composed URI,
	 * unless a value was provided to the concrete implementation (see
	 * withRequestTarget() below).
	 */
	public function getRequestTarget() -> string
	{
		var requestTarget;

		let requestTarget = this->requestTarget;

		if null === requestTarget {
			let requestTarget = this->uri->getPath();
			if true === this->uri->getQuery() {
				let requestTarget .= this->uri->getQuery();
			}

			if empty(requestTarget) {
				let requestTarget = "/";
			}
		}

		return requestTarget;
	}

    /**
     * Checks if a header exists by the given case-insensitive name.
     */
    public function hasHeader(var name) -> bool
    {
		return this->headers->has(name);
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
    public function withAddedHeader(var name, var value) -> <ServerRequest>
    {
		var existing, headers;

		this->checkHeaderName(name);

		let headers  = clone this->headers,
			existing = headers->get(name, []),
			value    = this->getHeaderValue(value),
			value    = array_merge(existing, value);

		headers->set(name, value);

		return this->cloneInstance(headers, "headers");
    }

	/**
	 * Return an instance with the specified derived request attribute.
	 *
	 * This method allows setting a single derived request attribute as
	 * described in getAttributes().
	 *
	 * This method MUST be implemented in such a way as to retain the
	 * immutability of the message, and MUST return an instance that has the
	 * updated attribute.
	 */
	public function withAttribute(var name, var value) -> <ServerRequest>
	{
		var attributes;

		let attributes = clone this->attributes;

		attributes->set(name, value);

		return this->cloneInstance(attributes, "attributes");
	}

    /**
     * Return an instance with the specified message body.
     *
     * The body MUST be a StreamInterface object.
     *
     * This method MUST be implemented in such a way as to retain the
     * immutability of the message, and MUST return a new instance that has the
     * new body stream.
     *
     * @throws \InvalidArgumentException When the body is not valid.
     */
    public function withBody(<StreamInterface> body) -> <ServerRequest>
    {
    	var newBody;

    	let newBody = this->processBody(body, "w+b");

		return this->cloneInstance(newBody, "body");
    }

	/**
	 * Return an instance with the specified cookies.
	 *
	 * The data IS NOT REQUIRED to come from the $_COOKIE superglobal, but MUST
	 * be compatible with the structure of $_COOKIE. Typically, this data will
	 * be injected at instantiation.
	 *
	 * This method MUST NOT update the related Cookie header of the request
	 * instance, nor related values in the server params.
	 *
	 * This method MUST be implemented in such a way as to retain the
	 * immutability of the message, and MUST return an instance that has the
	 * updated cookie values.
	 */
	public function withCookieParams(array cookies) -> <ServerRequest>
	{
		return this->cloneInstance(cookies, "cookieParams");
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
     * @throws \InvalidArgumentException for invalid header names or values.
     */
    public function withHeader(var name, var value) -> <ServerRequest>
    {
		var headers;

		this->checkHeaderName(name);

		let headers = clone this->headers,
			value   = this->getHeaderValue(value);

		headers->set(name, value);

		return this->cloneInstance(headers, "headers");
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
	 * @throws \InvalidArgumentException for invalid HTTP methods.
	 */
	public function withMethod(var method) -> <ServerRequest>
	{
		this->processMethod(method);

		return this->cloneInstance(method, "method");
	}

	/**
	 * Return an instance with the specified body parameters.
	 *
	 * These MAY be injected during instantiation.
	 *
	 * If the request Content-Type is either application/x-www-form-urlencoded
	 * or multipart/form-data, and the request method is POST, use this method
	 * ONLY to inject the contents of $_POST.
	 *
	 * The data IS NOT REQUIRED to come from $_POST, but MUST be the results of
	 * deserializing the request body content. Deserialization/parsing returns
	 * structured data, and, as such, this method ONLY accepts arrays or objects,
	 * or a null value if nothing was available to parse.
	 *
	 * As an example, if content negotiation determines that the request data
	 * is a JSON payload, this method could be used to create a request
	 * instance with the deserialized parameters.
	 *
	 * This method MUST be implemented in such a way as to retain the
	 * immutability of the message, and MUST return an instance that has the
	 * updated body parameters.
	 *
	 * @throws \InvalidArgumentException if an unsupported argument type is
	 *     provided.
	 */
	public function withParsedBody(var data) -> <ServerRequest>
	{
		return this->cloneInstance(data, "parsedBody");
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
    public function withProtocolVersion(var version) -> <ServerRequest>
    {
		this->processProtocol(version);

		return this->cloneInstance(version, "protocolVersion");
    }

	/**
	 * Return an instance with the specified query string arguments.
	 *
	 * These values SHOULD remain immutable over the course of the incoming
	 * request. They MAY be injected during instantiation, such as from PHP's
	 * $_GET superglobal, or MAY be derived from some other value such as the
	 * URI. In cases where the arguments are parsed from the URI, the data
	 * MUST be compatible with what PHP's parse_str() would return for
	 * purposes of how duplicate query parameters are handled, and how nested
	 * sets are handled.
	 *
	 * Setting query string arguments MUST NOT change the URI stored by the
	 * request, nor the values in the server params.
	 *
	 * This method MUST be implemented in such a way as to retain the
	 * immutability of the message, and MUST return an instance that has the
	 * updated query string arguments.
	 */
	public function withQueryParams(array query) -> <ServerRequest>
	{
		return this->cloneInstance(query, "queryParams");
	}

	/**
	 * Return an instance with the specific request-target.
	 *
	 * If the request needs a non-origin-form request-target — e.g., for
	 * specifying an absolute-form, authority-form, or asterisk-form —
	 * this method may be used to create an instance with the specified
	 * request-target, verbatim.
	 *
	 * This method MUST be implemented in such a way as to retain the
	 * immutability of the message, and MUST return an instance that has t
	 * changed request target.
	 *
	 * @see http://tools.ietf.org/html/rfc7230#section-5.3 (for the various
	 *     request-target forms allowed in request messages)
	 */
	public function withRequestTarget(var requestTarget) -> <ServerRequest>
	{
		if preg_match("/\s/", requestTarget) {
			throw new \InvalidArgumentException(
				"Invalid request target: cannot contain whitespace"
			);
		}

		return this->cloneInstance(requestTarget, "requestTarget");
	}

	/**
	 * Create a new instance with the specified uploaded files.
	 *
	 * This method MUST be implemented in such a way as to retain the
	 * immutability of the message, and MUST return an instance that has the
	 * updated body parameters.
	 *
	 * @throws \InvalidArgumentException if an invalid structure is provided.
	 */
	public function withUploadedFiles(array uploadedFiles) -> <ServerRequest>
	{
		this->checkUploadedFiles(uploadedFiles);

		return this->cloneInstance(uploadedFiles, "uploadedFiles");
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
	public function withUri(<UriInterface> uri, var preserveHost = false) -> <ServerRequest>
	{
		var headers, host, newInstance;

		let preserveHost     = (bool) preserveHost,
			headers          = clone this->headers,
			newInstance      = clone this,
			newInstance->uri = uri;

		if !(true === preserveHost &&
			true === headers->has("Host") &&
			"" !== uri->getHost()) {

			let host = this->getUriHost(uri);

			headers->set("Host", [host]);

			let newInstance->headers = headers;
		}

		return newInstance;
	}

	/**
	 * Return an instance that removes the specified derived request attribute.
	 *
	 * This method allows removing a single derived request attribute as
	 * described in getAttributes().
	 *
	 * This method MUST be implemented in such a way as to retain the
	 * immutability of the message, and MUST return an instance that removes
	 * the attribute.
	 */
	public function withoutAttribute(var name) -> <ServerRequest>
	{
		var attributes;

		let attributes = clone this->attributes;

		attributes->remove(name);

		return this->cloneInstance(attributes, "attributes");
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
    public function withoutHeader(var name) -> <ServerRequest>
    {
		var headers;

		let headers = clone this->headers;

		headers->remove(name);

		return this->cloneInstance(headers, "headers");
	}

	/**
	 * Check the name of the header. Throw exception if not valid
	 *
	 * @see http://tools.ietf.org/html/rfc7230#section-3.2
	 */
	private function checkHeaderName(var name) -> void
	{
		if typeof name !== "string" || !preg_match("/^[a-zA-Z0-9\'`#$%&*+.^_|~!-]+$/", name) {
			throw new \InvalidArgumentException("Invalid header name " . name);
		}
	}

	/**
	 * Validates a header value
	 *
	 * Most HTTP header field values are defined using common syntax
	 * components (token, quoted-string, and comment) separated by
	 * whitespace or specific delimiting characters.  Delimiters are chosen
	 * from the set of US-ASCII visual characters not allowed in a token
	 * (DQUOTE and "(),/:;<=>?@[\]{}").
	 *
	 *     token          = 1*tchar
	 *
	 *     tchar          = "!" / "#" / "$" / "%" / "&" / "'" / "*"
	 *                    / "+" / "-" / "." / "^" / "_" / "`" / "|" / "~"
	 *                    / DIGIT / ALPHA
	 *                    ; any VCHAR, except delimiters
	 *
	 * A string of text is parsed as a single value if it is quoted using
	 * double-quote marks.
	 *
	 *     quoted-string  = DQUOTE *( qdtext / quoted-pair ) DQUOTE
	 *     qdtext         = HTAB / SP /%x21 / %x23-5B / %x5D-7E / obs-text
	 *     obs-text       = %x80-FF
	 *
	 * Comments can be included in some HTTP header fields by surrounding
	 * the comment text with parentheses.  Comments are only allowed in
	 * fields containing "comment" as part of their field value definition.
	 *
	 *     comment        = "(" *( ctext / quoted-pair / comment ) ")"
	 *     ctext          = HTAB / SP / %x21-27 / %x2A-5B / %x5D-7E / obs-text
	 *
	 * The backslash octet ("\") can be used as a single-octet quoting
	 * mechanism within quoted-string and comment constructs.  Recipients
	 * that process the value of a quoted-string MUST handle a quoted-pair
	 * as if it were replaced by the octet following the backslash.
	 *
	 *     quoted-pair    = "\" ( HTAB / SP / VCHAR / obs-text )
	 *
	 * A sender SHOULD NOT generate a quoted-pair in a quoted-string except
	 * where necessary to quote DQUOTE and backslash octets occurring within
	 * that string.  A sender SHOULD NOT generate a quoted-pair in a comment
	 * except where necessary to quote parentheses ["(" and ")"] and
	 * backslash octets occurring within that comment.
	 *
	 * @see https://tools.ietf.org/html/rfc7230#section-3.2.6
	 */
	private function checkHeaderValue(var value) -> void
	{
		if typeof value !== "string" && typeof value !== "int" && typeof value !== "float" {
			throw new \InvalidArgumentException("Invalid header value");
		}

		let value = (string) value;

		if preg_match("#(?:(?:(?<!\r)\n)|(?:\r(?!\n))|(?:\r\n(?![ \t])))#", value) ||
			preg_match("/[^\x09\x0a\x0d\x20-\x7E\x80-\xFE]/", value) {
			throw new \InvalidArgumentException("Invalid header value");
		}
	}

	/**
	 * Checks the uploaded files
	 */
	private function checkUploadedFiles(array files) -> void
	{
    	var file;

    	for file in files {
    		if typeof file === "array" {
    			this->checkUploadedFiles(file);
    		} else {
    			if !(typeof file === "object" && file instanceof UploadedFileInterface) {
    				throw new \InvalidArgumentException("Invalid uploaded file");
    			}
    		}

    	}
	}

	/**
	 * Returns a new instance having set the parameter
	 */
	private function cloneInstance(var element, string property) -> <ServerRequest>
	{
    	var newInstance;

        let newInstance = clone this;
		if element !== this->{property} {
            let newInstance->{property} = element;
        }

        return newInstance;
	}

	/**
	 * Returns the header values checked for validity
	 */
   private function getHeaderValue(var values) -> array
	{
		var value;
		array valueData;

		if typeof values !== "array" {
			let values = [values];
		}

		if empty(values) {
			throw new \InvalidArgumentException(
				"Invalid header value: must be a string or array of strings; cannot be an empty array"
			);
		}

		let valueData = [];
		for value in values {
			this->checkHeaderValue(value);
			let valueData[] = (string) value;
		}

		return valueData;
	}

	/**
	 * Return the host and if applicable the port
	 */
	private function getUriHost(<UriInterface> uri) -> string
	{
		var host;

		let host = uri->getHost();
		if null !== uri->getPort() {
			let host .= ":" . uri->getPort();
		}

		return host;
	}

	/**
	 * Set a valid stream
	 */
	private function processBody(var body = "php://memory", string mode = "r+b") -> <StreamInterface>
	{
		if body instanceof StreamInterface {
			return body;
		}

		if typeof body !== "string" && typeof body !== "resource" {
			throw new \InvalidArgumentException("Invalid stream passed as a parameter");
		}

		return new Stream(body, mode);
	}

	/**
	 * Sets the headers
	 */
	private function processHeaders(var headers) -> <Collection>
	{
		var collection, host, name, value;

		if typeof headers === "array" {
			let collection = new Collection();
			for name, value in headers {

				this->checkHeaderName(name);

				let name  = (string) name,
					value = this->getHeaderValue(value);

				collection->set(name, value);
			}

			if true === collection->has("host") && "" !== this->uri->getHost() {
				let host = this->getUriHost(this->uri);

				collection->set("Host", [host]);
			}
		} else {
			if headers instanceof Collection {
				let collection = headers;
			} else {
				throw new \InvalidArgumentException(
					"Headers need to be either an array or instance of Phalcon\Collection"
				);
			}
		}

		return collection;
	}

	/**
	 * Check the method
	 */
	private function processMethod(var method = "") ->  string
	{
		array methods;

		let methods = [
			"GET"     : 1,
			"CONNECT" : 1,
			"DELETE"  : 1,
			"HEAD"    : 1,
			"OPTIONS" : 1,
			"PATCH"   : 1,
			"POST"    : 1,
			"PUT"     : 1,
			"TRACE"   : 1
		];

		if !(!empty(method) && typeof method === "string" && isset methods[method]) {
			throw new \InvalidArgumentException("Invalid or unsupported method " . method);
		}

		return method;
	}

	/**
	 * Checks the protocol
	 */
	private function processProtocol(var protocol = "") -> string
	{
		array protocols;

		let protocols = [
			"1.0" : 1,
			"1.1" : 1,
			"2.0" : 1,
			"3.0" : 1
		];

		if (empty(protocol)) || typeof protocol !== "string" {
			throw new \InvalidArgumentException("Invalid protocol value");
		}

		if !isset protocols[protocol] {
			throw new \InvalidArgumentException("Unsupported protocol " . protocol);
		}

		return protocol;
	}

	/**
	 * Sets a valid Uri
	 */
	private function processUri(var uri) -> <UriInterface>
	{
		var localUri;

		if uri instanceof UriInterface {
			let localUri = uri;
		} elseif typeof uri === "string" || null === uri {
			let localUri = new Uri(uri);
		} else {
			throw new \InvalidArgumentException("Invalid uri passed as a parameter");
		}

		return localUri;
	}
}
