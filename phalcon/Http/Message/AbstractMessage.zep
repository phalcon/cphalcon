
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by Zend Diactoros
 * @link    https://github.com/zendframework/zend-diactoros
 * @license https://github.com/zendframework/zend-diactoros/blob/master/LICENSE.md
 */

namespace Phalcon\Http\Message;

use Phalcon\Support\Collection;
use Phalcon\Support\Collection\CollectionInterface;
use Phalcon\Http\Message\Exception\InvalidArgumentException;
use Psr\Http\Message\StreamInterface;
use Psr\Http\Message\UriInterface;

/**
 * Message methods
 */
abstract class AbstractMessage extends AbstractCommon
{
    /**
     * Gets the body of the message.
     *
     * @var StreamInterface
     */
    protected body { get };

    /**
     * @var Collection|CollectionInterface
     */
    protected headers;

    /**
     * Retrieves the HTTP protocol version as a string.
     *
     * The string MUST contain only the HTTP version number (e.g., '1.1',
     * '1.0').
     *
     * @return string HTTP protocol version.
     *
     * @var string
     */
    protected protocolVersion = "1.1" { get };

    /**
     * Retrieves the URI instance.
     *
     * This method MUST return a UriInterface instance.
     *
     * @see http://tools.ietf.org/html/rfc3986#section-4.3
     *
     * @var UriInterface
     */
    protected uri { get };

    /**
     * Retrieves a message header value by the given case-insensitive name.
     *
     * This method returns an array of all the header values of the given
     * case-insensitive header name.
     *
     * If the header does not appear in the message, this method MUST return an
     * empty array.
     *
     * @param string $name
     *
     * @return array
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
     *
     * @param string $name
     *
     * @return string
     */
    public function getHeaderLine(var name) -> string
    {
        var header;

        let header = this->getHeader(name);

        return implode(',', header);
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
     * @return array
     */
    public function getHeaders() -> array
    {
        return this->headers->toArray();
    }

    /**
     * Checks if a header exists by the given case-insensitive name.
     *
     * @param string $name
     *
     * @return bool
     */
    public function hasHeader(name) -> bool
    {
        return this->headers->has(name);
    }

    /**
     * Return an instance with the specified header appended with the given
     * value.
     *
     * Existing values for the specified header will be maintained. The new
     * value(s) will be appended to the existing list. If the header did not
     * exist previously, it will be added.
     *
     * This method MUST be implemented in such a way as to retain the
     * immutability of the message, and MUST return an instance that has the
     * new header and/or value.
     *
     * @param string          $name
     * @param string|string[] $value
     *
     * @return static
     */
    public function withAddedHeader(var name, var value) -> var
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
     * Return an instance with the specified message body.
     *
     * The body MUST be a StreamInterface object.
     *
     * This method MUST be implemented in such a way as to retain the
     * immutability of the message, and MUST return a new instance that has the
     * new body stream.
     *
     * @param StreamInterface $body
     *
     * @return static
     * @throws InvalidArgumentException When the body is not valid.
     *
     */
    public function withBody(<StreamInterface> body) -> var
    {
        var newBody;

        let newBody = this->processBody(body, "w+b");

        return this->cloneInstance(newBody, "body");
    }

    /**
     * Return an instance with the provided value replacing the specified
     * header.
     *
     * While header names are case-insensitive, the casing of the header will
     * be preserved by this function, and returned from getHeaders().
     *
     * This method MUST be implemented in such a way as to retain the
     * immutability of the message, and MUST return an instance that has the
     * new and/or updated header and value.
     *
     * @param string          $name
     * @param string|string[] $value
     *
     * @return static
     * @throws InvalidArgumentException for invalid header names or values.
     *
     */
    public function withHeader(var name, var value) -> var
    {
        var headers;

        this->checkHeaderName(name);

        let headers = clone this->headers,
            value   = this->getHeaderValue(value);

        headers->set(name, value);

        return this->cloneInstance(headers, "headers");
    }

    /**
     * Return an instance with the specified HTTP protocol version.
     *
     * The version string MUST contain only the HTTP version number (e.g.,
     * '1.1', '1.0').
     *
     * This method MUST be implemented in such a way as to retain the
     * immutability of the message, and MUST return an instance that has the
     * new protocol version.
     *
     * @param string $version
     *
     * @return static
     */
    public function withProtocolVersion(var version) -> var
    {
        this->processProtocol(version);

        return this->cloneInstance(version, "protocolVersion");
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
     * @param string $name
     *
     * @return static
     */
    public function withoutHeader(var name) -> var
    {
        var headers;

        let headers = clone this->headers;

        headers->remove(name);

        return this->cloneInstance(headers, "headers");
    }

    /**
     * Ensure Host is the first header.
     *
     * @see: http://tools.ietf.org/html/rfc7230#section-5.4
     *
     * @param CollectionInterface $collection
     *
     * @return CollectionInterface
     */
    final protected function checkHeaderHost(<CollectionInterface> collection) -> <CollectionInterface>
    {
        var data, host, hostArray;
        array header;

        if unlikely (collection->has("host") &&
            !empty(this->uri) &&
            "" !== this->uri->getHost()) {

            let host      = this->getUriHost(this->uri),
                hostArray = host;
            if unlikely typeof host !== "array" {
                let hostArray = [host];
            }

            collection->remove("host");

            let data           = collection->toArray(),
                header         = [],
                header["Host"] = hostArray,
                header         = header + (array) data;

            collection->clear();
            collection->init(header);
        }

        return collection;
    }

    /**
     * Check the name of the header. Throw exception if not valid
     *
     * @see http://tools.ietf.org/html/rfc7230#section-3.2
     */
    final protected function checkHeaderName(var name) -> void
    {
        if unlikely (typeof name !== "string"  ||
            !preg_match("/^[a-zA-Z0-9'`#$%&*+.^_|~!-]+$/", name)) {
            throw new InvalidArgumentException(
                "Invalid header name " . name
            );
        }
    }

    /**
     * Validates a header value
     *
     * Most HTTP header field values are defined using common syntax
     * components (token, quoted-string, and comment) separated by
     * whitespace or specific delimiting characters.  Delimiters are chosen
     * from the set of US-ASCII visual characters not allowed in a token
     * (DQUOTE and '(),/:;<=>?@[\]{}').
     *
     *     token          = 1*tchar
     *
     *     tchar          = '!' / '#' / '$' / '%' / '&' / ''' / '*'
     *                    / '+' / '-' / '.' / '^' / '_' / '`' / '|' / '~'
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
     * fields containing 'comment' as part of their field value definition.
     *
     *     comment        = '(' *( ctext / quoted-pair / comment ) ')'
     *     ctext          = HTAB / SP / %x21-27 / %x2A-5B / %x5D-7E / obs-text
     *
     * The backslash octet ('\') can be used as a single-octet quoting
     * mechanism within quoted-string and comment constructs.  Recipients
     * that process the value of a quoted-string MUST handle a quoted-pair
     * as if it were replaced by the octet following the backslash.
     *
     *     quoted-pair    = '\' ( HTAB / SP / VCHAR / obs-text )
     *
     * A sender SHOULD NOT generate a quoted-pair in a quoted-string except
     * where necessary to quote DQUOTE and backslash octets occurring within
     * that string.  A sender SHOULD NOT generate a quoted-pair in a comment
     * except where necessary to quote parentheses ['(' and ')'] and
     * backslash octets occurring within that comment.
     *
     * @see https://tools.ietf.org/html/rfc7230#section-3.2.6
     */
    final protected function checkHeaderValue(var value) -> void
    {
        if unlikely (typeof value !== "string" && true !== is_numeric(value)) {
            throw new InvalidArgumentException("Invalid header value");
        }

        let value = (string) value;

        if unlikely (preg_match("#(?:(?:(?<!\r)\n)|(?:\r(?!\n))|(?:\r\n(?![ \t])))#", value) ||
            preg_match("/[^\x09\x0a\x0d\x20-\x7E\x80-\xFE]/", value)) {
            throw new InvalidArgumentException("Invalid header value");
        }
    }

    /**
     * Returns the header values checked for validity
     */
    final protected function getHeaderValue(var values) -> array
    {
        var value, valueArray, valueData;

        let valueArray = values;
        if unlikely typeof values !== "array" {
            let valueArray = [values];
        }

        if unlikely empty(valueArray) {
            throw new InvalidArgumentException(
                "Invalid header value: must be a string or " .
                "array of strings; cannot be an empty array"
            );
        }

        let valueData = [];
        for value in valueArray {
            this->checkHeaderValue(value);

            let valueData[] = (string) value;
        }

        return valueData;
    }

    /**
     * Return the host and if applicable the port
     *
     * @param UriInterface $uri
     *
     * @return string
     */
    final protected function getUriHost(<UriInterface> uri) -> string
    {
        var host;

        let host = uri->getHost();

        if unlikely null !== uri->getPort() {
            let host .= ":" . uri->getPort();
        }

        return host;
    }

    /**
     * Populates the header collection
     *
     * @param array $headers
     *
     * @return CollectionInterface
     */
    final protected function populateHeaderCollection(array headers) -> <CollectionInterface>
    {
        var collection, name, value;

        let collection = new Collection();
        for name, value in headers {
            this->checkHeaderName(name);

            let name  = (string) name,
                value = this->getHeaderValue(value);

            collection->set(name, value);
        }

        return collection;
    }

    /**
     * Set a valid stream
     *
     * @param StreamInterface|resource|string $body
     * @param string                          $mode
     *
     * @return StreamInterface
     */
    final protected function processBody(var body = "php://memory", string! mode = "r+b") -> <StreamInterface>
    {
        if unlikely (typeof body === "object" && body instanceof StreamInterface) {
            return body;
        }

        if unlikely (typeof body !== "string" && typeof body !== "resource") {
            throw new InvalidArgumentException(
                "Invalid stream passed as a parameter"
            );
        }

        return new Stream(body, mode);
    }

    /**
     * Sets the headers
     */
    final protected function processHeaders(var headers) -> <CollectionInterface>
    {
        var collection;

        if likely typeof headers === "array" {
            let collection = this->populateHeaderCollection(headers);
            let collection = this->checkHeaderHost(collection);
        } else {
            if unlikely !(typeof headers === "object" && headers instanceof CollectionInterface) {
                throw new InvalidArgumentException(
                    "Headers needs to be either an array or instance of Phalcon\\Support\\Collection"
                );
            }

            let collection = headers;
        }

        return collection;
    }

    /**
     * Checks the protocol
     *
     * @param string $protocol
     *
     * @return string
     */
    final protected function processProtocol(var protocol = "") -> string
    {
        var protocols;

        let protocols = [
            "1.0" : 1,
            "1.1" : 1,
            "2.0" : 1,
            "3.0" : 1
        ];

        if unlikely (empty(protocol) || typeof protocol !== "string") {
            throw new InvalidArgumentException("Invalid protocol value");
        }

        if unlikely !isset protocols[protocol] {
            throw new InvalidArgumentException(
                "Unsupported protocol " . protocol
            );
        }

        return protocol;
    }
}
