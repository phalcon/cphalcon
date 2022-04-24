
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

use Phalcon\Http\Message\Exception\InvalidArgumentException;
use Psr\Http\Message\UriInterface;

/**
 * Request methods
 */
abstract class AbstractRequest extends AbstractMessage implements RequestMethodInterface
{
    /**
     * Retrieves the HTTP method of the request.
     *
     * @var string
     */
    protected method = self::METHOD_GET { get };

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
     * @see http://tools.ietf.org/html/rfc3986#section-4.3
     *
     * @var UriInterface
     */
    protected uri { get };

    /**
     * Retrieves the message's request target.
     *
     * Retrieves the message's request-target either as it will appear (for
     * clients), as it appeared at request (for servers), or as it was
     * specified for the instance (see withRequestTarget()).
     *
     * In most cases, this will be the origin-form of the composed URI, unless a
     * value was provided to the concrete implementation (see
     * withRequestTarget() below).
     *
     * @return string
     */
    public function getRequestTarget() -> string
    {
        var requestTarget;

        let requestTarget = this->requestTarget;

        if unlikely null === requestTarget {
            let requestTarget = this->uri->getPath();

            if unlikely !empty(this->uri->getQuery()) {
                let requestTarget .= "?" . this->uri->getQuery();
            }

            if unlikely empty(requestTarget) {
                let requestTarget = "/";
            }
        }

        return requestTarget;
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
     * @param string $method
     *
     * @return static
     * @throws InvalidArgumentException for invalid HTTP methods.
     */
    public function withMethod(var method) -> var
    {
        this->processMethod(method);

        return this->cloneInstance(method, "method");
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
     * immutability of the message, and MUST return an instance that has the
     * changed request target.
     *
     * @see http://tools.ietf.org/html/rfc7230#section-5.3 (for the various
     *     request-target forms allowed in request messages)
     *
     * @param mixed $requestTarget
     *
     * @return static
     */
    public function withRequestTarget(var requestTarget) -> var
    {
        if unlikely preg_match("/\s/", requestTarget) {
            throw new InvalidArgumentException(
                "Invalid request target: cannot contain whitespace"
            );
        }

        return this->cloneInstance(requestTarget, "requestTarget");
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
     * `true`, this method interacts with the Host header in the following
     * ways:
     *
     * - If the Host header is missing or empty, and the new URI contains
     *   a host component, this method MUST update the Host header in the
     *   returned request.
     * - If the Host header is missing or empty, and the new URI does not
     * contain a host component, this method MUST NOT update the Host header in
     * the returned request.
     * - If a Host header is present and non-empty, this method MUST NOT update
     *   the Host header in the returned request.
     *
     * This method MUST be implemented in such a way as to retain the
     * immutability of the message, and MUST return an instance that has the
     * new UriInterface instance.
     *
     * @see http://tools.ietf.org/html/rfc3986#section-4.3
     *
     * @param UriInterface $uri
     * @param bool         $preserveHost
     *
     * @return static
     */
    public function withUri(<UriInterface> uri, var preserveHost = false) -> var
    {
        var headers, newInstance;

        let preserveHost     = (bool) preserveHost,
            headers          = clone this->headers,
            newInstance      = this->cloneInstance(uri, "uri");

        if unlikely !preserveHost {
            let headers = this->checkHeaderHost(headers);

            let newInstance->headers = headers;
        }

        return newInstance;
    }

    /**
     * Check the method
     *
     * @param string $method
     *
     * @return string
     */
    final protected function processMethod(method = "") -> string
    {
        var methods;

        let methods = [
            self::METHOD_CONNECT : 1,
            self::METHOD_DELETE  : 1,
            self::METHOD_GET     : 1,
            self::METHOD_HEAD    : 1,
            self::METHOD_OPTIONS : 1,
            self::METHOD_PATCH   : 1,
            self::METHOD_POST    : 1,
            self::METHOD_PURGE   : 1,
            self::METHOD_PUT     : 1,
            self::METHOD_TRACE   : 1
        ];

        if unlikely !(!empty(method) &&
            typeof method === "string"  &&
            isset methods[method]) {
            throw new InvalidArgumentException(
                "Invalid or unsupported method " . method
            );
        }

        return method;
    }

    /**
     * Sets a valid Uri
     *
     * @param UriInterface|string|null $uri
     *
     * @return UriInterface
     */
    final protected function processUri(var uri) -> <UriInterface>
    {
        if unlikely (typeof uri === "object" && uri instanceof UriInterface) {
            return uri;
        }

        if likely typeof uri === "string" {
            return new Uri(uri);
        }

        if null === uri {
            return new Uri();
        }

        throw new InvalidArgumentException(
            "Invalid uri passed as a parameter"
        );
    }
}
