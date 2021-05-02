
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

namespace Phalcon\Http\Message;

use Phalcon\Helper\Arr;
use Phalcon\Helper\Str;
use Phalcon\Http\Message\Exception\InvalidArgumentException;
use Psr\Http\Message\UriInterface;

/**
 * PSR-7 Uri
 */
final class Uri extends AbstractCommon implements UriInterface
{
    /**
     * Returns the fragment of the URL
     *
     * @return string
     */
    protected fragment = "" { get };

    /**
     * Retrieve the host component of the URI.
     *
     * If no host is present, this method MUST return an empty string.
     *
     * The value returned MUST be normalized to lowercase, per RFC 3986
     * Section 3.2.2.
     *
     * @see http://tools.ietf.org/html/rfc3986#section-3.2.2
     *
     * @return string
     */
    protected host = "" { get };

    /**
     * @var string
     */
    protected pass = "";

    /**
     * Returns the path of the URL
     *
     * @return string
     */
    protected path = "" { get };

    /**
     * Retrieve the port component of the URI.
     *
     * If a port is present, and it is non-standard for the current scheme,
     * this method MUST return it as an integer. If the port is the standard
     * port used with the current scheme, this method SHOULD return null.
     *
     * If no port is present, and no scheme is present, this method MUST return
     * a null value.
     *
     * If no port is present, but a scheme is present, this method MAY return
     * the standard port for that scheme, but SHOULD return null.
     *
     * @return int|null
     */
    protected port = null { get };

    /**
     * Returns the query of the URL
     *
     * @return string
     */
    protected query = "" { get };

    /**
     * Retrieve the scheme component of the URI.
     *
     * If no scheme is present, this method MUST return an empty string.
     *
     * The value returned MUST be normalized to lowercase, per RFC 3986
     * Section 3.1.
     *
     * The trailing ":" character is not part of the scheme and MUST NOT be
     * added.
     *
     * @see https://tools.ietf.org/html/rfc3986#section-3.1
     *
     * @return string
     */
    protected scheme = "https" { get };

    /**
     * @var string
     */
    protected user = "";

    /**
     * Uri constructor.
     *
     * @param string $uri
     */
    public function __construct(string! uri = "")
    {
        var urlParts;

        if unlikely "" !== uri {
            let urlParts = parse_url(uri);

            if unlikely false === urlParts {
                let urlParts = [];
            }

            let this->fragment = this->filterFragment(Arr::get(urlParts, "fragment", "")),
                this->host     = strtolower(Arr::get(urlParts, "host", "")),
                this->pass     = rawurlencode(Arr::get(urlParts, "pass", "")),
                this->path     = this->filterPath(Arr::get(urlParts, "path", "")),
                this->port     = this->filterPort(Arr::get(urlParts, "port", null)),
                this->query    = this->filterQuery(Arr::get(urlParts, "query", "")),
                this->scheme   = this->filterScheme(Arr::get(urlParts, "scheme", "")),
                this->user     = rawurlencode(Arr::get(urlParts, "user", ""));
        }
    }

    /**
     * Return the string representation as a URI reference.
     *
     * Depending on which components of the URI are present, the resulting
     * string is either a full URI or relative reference according to RFC 3986,
     * Section 4.1. The method concatenates the various components of the URI,
     * using the appropriate delimiters
     *
     * @return string
     */
    public function __toString() -> string
    {
        var authority, path, uri;

        let authority = this->getAuthority(),
            path      = this->path;

        /**
         * The path can be concatenated without delimiters. But there are two
         * cases where the path has to be adjusted to make the URI reference
         * valid as PHP does not allow to throw an exception in __toString():
         *   - If the path is rootless and an authority is present, the path
         *     MUST be prefixed by "/".
         *   - If the path is starting with more than one "/" and no authority
         *     is present, the starting slashes MUST be reduced to one.
         */
        if unlikely ("" !== path && true !== starts_with(path, "/") && "" !== authority) {
            let path = "/" . path;
        }

        let uri = this->checkValue(this->scheme, "", ":")
                . this->checkValue(authority, "//")
                . path
                . this->checkValue(this->query, "?")
                . this->checkValue(this->fragment, "#");

        return uri;
    }

    /**
     * Retrieve the authority component of the URI.
     *
     * @return string
     */
    public function getAuthority() -> string
    {
        var authority, userInfo;

        /**
         * If no authority information is present, this method MUST return an
         * empty string.
         */
        if unlikely "" === this->host {
            return "";
        }

        let authority = this->host,
            userInfo  = this->getUserInfo();

        /**
         * The authority syntax of the URI is:
         *
         * [user-info@]host[:port]
         */
        if unlikely "" !== userInfo {
            let authority = userInfo . "@" . authority;
        }

        /**
         * If the port component is not set or is the standard port for the
         * current scheme, it SHOULD NOT be included.
         */
        if unlikely null !== this->port {
            let authority .= ":" . this->port;
        }

        return authority;
    }

    /**
     * Retrieve the user information component of the URI.
     *
     * If no user information is present, this method MUST return an empty
     * string.
     *
     * If a user is present in the URI, this will return that value;
     * additionally, if the password is also present, it will be appended to the
     * user value, with a colon (":") separating the values.
     *
     * The trailing "@" character is not part of the user information and MUST
     * NOT be added.
     *
     * @return string The URI user information, in "username[:password]" format.
     */
    public function getUserInfo() -> string
    {
        if unlikely true !== empty(this->pass) {
            return this->user . ":" . this->pass;
        }

        return this->user;
    }

    /**
     * Return an instance with the specified URI fragment.
     *
     * This method MUST retain the state of the current instance, and return
     * an instance that contains the specified URI fragment.
     *
     * Users can provide both encoded and decoded fragment characters.
     * Implementations ensure the correct encoding as outlined in getFragment().
     *
     * An empty fragment value is equivalent to removing the fragment.
     *
     * @param string $fragment
     *
     * @return Uri
     */
    public function withFragment(var fragment) -> <Uri>
    {
        this->checkStringParameter(fragment);

        let fragment = this->filterFragment(fragment);

        return this->cloneInstance(fragment, "fragment");
    }

    /**
     * Return an instance with the specified path.
     *
     * This method MUST retain the state of the current instance, and return
     * an instance that contains the specified path.
     *
     * The path can either be empty or absolute (starting with a slash) or
     * rootless (not starting with a slash). Implementations MUST support all
     * three syntaxes.
     *
     * If an HTTP path is intended to be host-relative rather than path-relative
     * then it must begin with a slash ("/"). HTTP paths not starting with a
     * slash are assumed to be relative to some base path known to the
     * application or consumer.
     *
     * Users can provide both encoded and decoded path characters.
     * Implementations ensure the correct encoding as outlined in getPath().
     *
     * @param string $path
     *
     * @return Uri
     * @throws InvalidArgumentException for invalid paths.
     */
    public function withPath(var path) -> <Uri>
    {
        this->checkStringParameter(path);

        if unlikely (false !== strpos(path, "?") || false !== strpos(path, "#")) {
            throw new InvalidArgumentException(
                "Path cannot contain a query string or fragment"
            );
        }

        let path = this->filterPath(path);

        return this->cloneInstance(path, "path");
    }

    /**
     * Return an instance with the specified port.
     *
     * This method MUST retain the state of the current instance, and return
     * an instance that contains the specified port.
     *
     * Implementations MUST raise an exception for ports outside the
     * established TCP and UDP port ranges.
     *
     * A null value provided for the port is equivalent to removing the port
     * information.
     *
     * @param int|null $port
     *
     * @return Uri
     * @throws InvalidArgumentException for invalid ports.
     */
    public function withPort(var port) -> <Uri>
    {
        if unlikely null !== port {
            let port = this->filterPort(port);

            if unlikely (null !== port && (port < 1 || port > 65535)) {
                throw new InvalidArgumentException(
                    "Method expects valid port (1-65535)"
                );
            }
        }

        return this->cloneInstance(port, "port");
    }

    /**
     * Return an instance with the specified query string.
     *
     * This method MUST retain the state of the current instance, and return
     * an instance that contains the specified query string.
     *
     * Users can provide both encoded and decoded query characters.
     * Implementations ensure the correct encoding as outlined in getQuery().
     *
     * An empty query string value is equivalent to removing the query string.
     *
     * @param string $query
     *
     * @return Uri
     * @throws InvalidArgumentException for invalid query strings.
     */
    public function withQuery(var query) -> <Uri>
    {
        this->checkStringParameter(query);

        if unlikely false !== strpos(query, "#") {
            throw new InvalidArgumentException(
                "Query cannot contain a query fragment"
            );
        }

        let query = this->filterQuery(query);

        return this->cloneInstance(query, "query");
    }

    /**
     * Return an instance with the specified scheme.
     *
     * This method MUST retain the state of the current instance, and return
     * an instance that contains the specified scheme.
     *
     * Implementations MUST support the schemes "http" and "https" case
     * insensitively, and MAY accommodate other schemes if required.
     *
     * An empty scheme is equivalent to removing the scheme.
     *
     * @param string $scheme
     *
     * @return Uri
     * @throws InvalidArgumentException for invalid schemes.
     * @throws InvalidArgumentException for unsupported schemes.
     */
    public function withScheme(scheme) -> <Uri>
    {
        this->checkStringParameter(scheme);

        let scheme = this->filterScheme(scheme);

        return this->processWith(scheme, "scheme");
    }

    /**
     * Return an instance with the specified user information.
     *
     * @param string      $user
     * @param string|null $password
     *
     * @return Uri
     */
    public function withUserInfo(var user, var password = null) -> <Uri>
    {
        var newInstance;

        this->checkStringParameter(user);

        if unlikely null !== password {
            this->checkStringParameter(user);
        }

        let user = rawurlencode(user);

        if unlikely null !== password {
            let password = rawurlencode(password);
        }

        /**
         * Immutable - need to send a new object back
         */
        let newInstance       = this->cloneInstance(user, "user"),
            newInstance->pass = password;

        return newInstance;
    }

    /**
     * Return an instance with the specified host.
     *
     * This method MUST retain the state of the current instance, and return
     * an instance that contains the specified host.
     *
     * An empty host value is equivalent to removing the host.
     *
     * @param string $host
     *
     * @return Uri
     * @throws InvalidArgumentException for invalid hostnames.
     *
     */
    public function withHost(host) -> <Uri>
    {
        return this->processWith(host, "host");
    }

    /**
     * If the value passed is empty it returns it prefixed and suffixed with
     * the passed parameters
     *
     * @param string $value
     * @param string $prefix
     * @param string $suffix
     *
     * @return string
     */
    private function checkValue(
        string! value,
        string! prefix = "",
        string! suffix = ""
    ) -> string
    {
        if unlikely "" !== value {
            let value = prefix . value . suffix;
        }

        return value;
    }

    /**
     * If no fragment is present, this method MUST return an empty string.
     *
     * The leading "#" character is not part of the fragment and MUST NOT be
     * added.
     *
     * The value returned MUST be percent-encoded, but MUST NOT double-encode
     * any characters. To determine what characters to encode, please refer to
     * RFC 3986, Sections 2 and 3.5.
     *
     * @see https://tools.ietf.org/html/rfc3986#section-2
     * @see https://tools.ietf.org/html/rfc3986#section-3.5
     *
     * @param string $fragment
     *
     * @return string
     */
    private function filterFragment(string! fragment) -> string
    {
        return rawurlencode(fragment);
    }

    /**
     *
     * The path can either be empty or absolute (starting with a slash) or
     * rootless (not starting with a slash). Implementations MUST support all
     * three syntaxes.
     *
     * Normally, the empty path "" and absolute path "/" are considered equal as
     * defined in RFC 7230 Section 2.7.3. But this method MUST NOT automatically
     * do this normalization because in contexts with a trimmed base path, e.g.
     * the front controller, this difference becomes significant. It's the task
     * of the user to handle both "" and "/".
     *
     * The value returned MUST be percent-encoded, but MUST NOT double-encode
     * any characters. To determine what characters to encode, please refer to
     * RFC 3986, Sections 2 and 3.3.
     *
     * As an example, if the value should include a slash ("/") not intended as
     * delimiter between path segments, that value MUST be passed in encoded
     * form (e.g., "%2F") to the instance.
     *
     * @see https://tools.ietf.org/html/rfc3986#section-2
     * @see https://tools.ietf.org/html/rfc3986#section-3.3
     *
     * @param string $path
     *
     * @return string The URI path.
     */
    private function filterPath(string! path) -> string
    {
        var element, key, parts;

        if unlikely ("" === path || true !== starts_with(path, "/")) {
            return path;
        }

        let parts = explode("/", path);
        for key, element in parts {
            let parts[key] = rawurlencode(element);
        }

        let path = implode("/", parts);

        return "/" . ltrim(path, "/");
    }

    /**
     * Checks the port. If it is a standard one (80,443) then it returns null
     *
     * @param int|null $port
     *
     * @return int|null
     */
    private function filterPort(var port) -> int | null
    {
        array ports;

        let ports = [
            80  : 1,
            443 : 1
        ];

        if unlikely null !== port {
            let port = (int) port;
            if unlikely isset ports[port] {
                let port = null;
            }
        }

        return port;
    }

    /**
     * If no query string is present, this method MUST return an empty string.
     *
     * The leading "?" character is not part of the query and MUST NOT be
     * added.
     *
     * The value returned MUST be percent-encoded, but MUST NOT double-encode
     * any characters. To determine what characters to encode, please refer to
     * RFC 3986, Sections 2 and 3.4.
     *
     * As an example, if a value in a key/value pair of the query string should
     * include an ampersand ("&") not intended as a delimiter between values,
     * that value MUST be passed in encoded form (e.g., "%26") to the instance.
     *
     * @see https://tools.ietf.org/html/rfc3986#section-2
     * @see https://tools.ietf.org/html/rfc3986#section-3.4
     *
     * @param string $query
     *
     * @return string The URI query string.
     */
    private function filterQuery(string query) -> string
    {
        var index, part, parts, split;

        if unlikely "" === query {
            return "";
        }

        let query = ltrim(query, "?"),
            parts = explode("&", query);

        for index, part in parts {
            let split = this->splitQueryValue(part);
            if unlikely null === split[1] {
                let parts[index] = rawurlencode(split[0]);
                continue;
            }

            let parts[index] = rawurlencode(split[0]) . "=" . rawurlencode(split[1]);
        }

        return implode("&", parts);
    }

    /**
     * Filters the passed scheme - only allowed schemes
     *
     * @param string $scheme
     *
     * @return string
     */
    private function filterScheme(string! scheme) -> string
    {
        var filtered;
        array schemes;

        let filtered = preg_replace("#:(//)?$#", "", mb_strtolower(scheme)),
            schemes  = [
                "http"  : 1,
                "https" : 1
            ];

        if unlikely "" === filtered {
            return "";
        }

        if unlikely !isset schemes[filtered] {
            throw new InvalidArgumentException(
                "Unsupported scheme [" . filtered . "]. " .
                "Scheme must be one of [" .
                implode(", ", array_keys(schemes)) . "]"
            );
        }

        return scheme;
    }

    /**
     * @param string $element
     *
     * @return array
     */
    private function splitQueryValue(string element) -> array
    {
        var data;

        let data = explode("=", element, 2);
        if unlikely !isset data[1] {
            let data[] = null;
        }

        return data;
    }
}
