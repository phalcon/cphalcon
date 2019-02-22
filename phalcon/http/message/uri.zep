
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

use Phalcon\Helper\Arr;
use Psr\Http\Message\UriInterface;

class Uri implements UriInterface
{
	/**
	 * @var string
	 */
	private authority = "";

    /**
     * Retrieve the fragment component of the URI.
     *
     * @var string
     */
    private fragment = "" { get };

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
     * @var string
     */
    private host = "" { get };

    /**
     * Retrieve the path component of the URI.
     *
     * @var string
     */
    private path = "" { get };

    /**
     * Retrieve the port component of the URI.
     *
     * If a port is present, and it is non-standard for the current scheme,
     * this method MUST return it as an integer. If the port is the standard port
     * used with the current scheme, this method SHOULD return null.
     *
     * If no port is present, and no scheme is present, this method MUST return
     * a null value.
     *
     * If no port is present, but a scheme is present, this method MAY return
     * the standard port for that scheme, but SHOULD return null.
     *
     * @var null | int
     */
    private port = null { get };

    /**
     * Retrieve the query string of the URI.
     *
     * @var string
     */
    private query = "" { get };

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
     * @var string
     */
    private scheme = "https" { get };

	/**
	 * @var string
	 */
	private pass = "";

	/**
	 * @var string
	 */
	private user = "";

	/**
	 * Constructor - parses the URI
	 */
    public function __construct(string uri = "")
    {
    	var fragment, host, scheme, pass, path, port, query, urlParts, user;

		if ("" !== uri) {
			let urlParts = parse_url(uri);

			/**
			 * Assign the parsed uri to the properties
			 */
			let scheme   = Arr::get(urlParts, "scheme", ""),
				host     = Arr::get(urlParts, "host", ""),
				port     = Arr::get(urlParts, "port", null),
				user     = Arr::get(urlParts, "user", ""),
				pass     = Arr::get(urlParts, "pass", ""),
				path     = Arr::get(urlParts, "path", ""),
				query    = Arr::get(urlParts, "query", ""),
				fragment = Arr::get(urlParts, "fragment", "");

			let this->scheme   = this->filterScheme(scheme),
				this->host     = strtolower(host),
				this->port     = this->filterPort(port),
				this->user     = rawurlencode(user),
				this->pass     = rawurlencode(pass),
				this->path     = this->filterPath(path),
				this->query    = this->filterQuery(query),
				this->fragment = this->filterFragment(fragment);
	    }
    }

    /**
     * Return the string representation as a URI reference.
     *
     * Depending on which components of the URI are present, the resulting
     * string is either a full URI or relative reference according to RFC 3986,
     * Section 4.1. The method concatenates the various components of the URI,
     * using the appropriate delimiters
     */
    public function __toString() -> string
    {
    	var authority, fragment, part, path, query, scheme, uri;

		let authority = this->getAuthority(),
			fragment  = this->fragment,
			path      = this->path,
			query     = this->query,
			scheme    = this->scheme,
			part      = substr(path, 0, 1),
			uri       = "";

		/**
		 * If a scheme is present, it MUST be suffixed by ":".
		 */
        if "" !== scheme {
        	let uri .= scheme . ":";
        }

		/**
		 * If an authority is present, it MUST be prefixed by "//".
		 */
        if "" !== authority {
            let uri .= "//" . authority;
        }

		/**
		 * The path can be concatenated without delimiters. But there are two
		 * cases where the path has to be adjusted to make the URI reference
		 * valid as PHP does not allow to throw an exception in __toString():
		 *   - If the path is rootless and an authority is present, the path MUST
		 *     be prefixed by "/".
		 *   - If the path is starting with more than one "/" and no authority is
		 *     present, the starting slashes MUST be reduced to one.
		 */
        if "" !== path {
        	if "//" === substr(path, 0, 2) && "" === authority {
        		let path = ltrim(path, "/");
        	} elseif (!starts_with(path, "/") && "" !== authority) {
				let path = "/" . path;
			}

            let uri .= path;
        }

		/**
		 * If a query is present, it MUST be prefixed by "?".
		 */
        if "" !== query {
            let uri .= "?" . query;
        }

		/**
		 * If a fragment is present, it MUST be prefixed by "#".
		 */
        if "" !== fragment {
            let uri .= "#" . fragment;
        }

        return uri;
    }

    /**
     * Retrieve the authority component of the URI.
     */
    public function getAuthority() -> string
    {
    	var authority, userInfo;

    	/**
		 * If no authority information is present, this method MUST return an empty
		 * string.
		 */
    	if "" === this->host {
    		return "";
    	}

    	let authority = this->host,
    		userInfo  = this->getUserInfo();

		/**
		 * The authority syntax of the URI is:
		 *
		 * [user-info@]host[:port]
		 */
    	if "" !== userInfo {
    		let authority = userInfo . "@" . authority;
    	}

		/**
		 * If the port component is not set or is the standard port for the
		 * current scheme, it SHOULD NOT be included.
		 */
    	if null !== this->port {
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
    	if !empty(this->pass) {
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
     */
    public function withFragment(var fragment) -> <Uri>
    {
    	return this->processWith(fragment, "fragment", __METHOD__);
    }

    /**
     * Return an instance with the specified host.
     *
     * This method MUST retain the state of the current instance, and return
     * an instance that contains the specified host.
     *
     * An empty host value is equivalent to removing the host.
     *
     * @throws \InvalidArgumentException for invalid hostnames.
     */
    public function withHost(var host) -> <Uri>
    {
    	return this->processWith(host, "host", __METHOD__);
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
     * then it must begin with a slash ("/"). HTTP paths not starting with a slash
     * are assumed to be relative to some base path known to the application or
     * consumer.
     *
     * Users can provide both encoded and decoded path characters.
     * Implementations ensure the correct encoding as outlined in getPath().
     *
     * @throws \InvalidArgumentException for invalid paths.
     */
    public function withPath(var path) -> <Uri>
    {
    	this->checkStringParameter(path, "path", __METHOD__);

    	if false !== strpos(path, "?") {
    		throw new \InvalidArgumentException(
    			__METHOD__ . "- path cannot contain a query string"
    		);
    	}

    	if false !== strpos(path, "#") {
    		throw new \InvalidArgumentException(
    			__METHOD__ . " - path cannot contain a query fragment"
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
     * @throws \InvalidArgumentException for invalid ports.
     */
    public function withPort(var port) -> <Uri>
    {
    	var type;

    	if null !== port {
			if (!is_numeric(port) || is_float(port)) {
				if is_object(port) {
					let type = get_class(port);
				} else {
					let type = gettype(port);
				}

				if typeof port !== "string" {
					throw new \InvalidArgumentException(
						__METHOD__ . " expects an integer, integer string or null argument instead of " . type
					);
				}
            }

            let port = this->filterPort(port);
        }

        if (null !== port && (port < 1 || port > 65535)) {
            throw new \InvalidArgumentException(__METHOD__ . " expects valid port (1-65535)");
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
     * @throws \InvalidArgumentException for invalid query strings.
     */
    public function withQuery(var query) -> <Uri>
    {
    	this->checkStringParameter(query, "query", __METHOD__);

		if false !== strpos(query, "#") {
			throw new \InvalidArgumentException(
				__METHOD__ . " - query cannot contain a query fragment"
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
     * @throws \InvalidArgumentException for invalid schemes.
     * @throws \InvalidArgumentException for unsupported schemes.
     */
    public function withScheme(var scheme) -> <Uri>
    {
    	this->checkStringParameter(scheme, "scheme", __METHOD__);

		let scheme = this->filterScheme(scheme);

    	return this->processWith(scheme, "scheme", __METHOD__);
    }

    /**
     * Return an instance with the specified user information.
     */
    public function withUserInfo(var user, var password = null) -> <Uri>
    {
    	var newInstance;

		this->checkStringParameter(user, "user", __METHOD__);
		if null !== password {
			this->checkStringParameter(user, "pass", __METHOD__);
		}

		let user = rawurlencode(user);
		if null !== password {
			let password = rawurlencode(password);
		}


		if (user === this->user && password === this->pass) {
            return this;
        }

		/**
		 * Immutable - need to send a new object back
		 */
        let newInstance       = clone this;
        let newInstance->user = user;
        let newInstance->pass = password;

        return newInstance;
    }

	/**
	 * Checks the element passed if it is a string
	 */
	private function checkStringParameter(var element, string property, string method) -> void
	{
    	var type;

		if is_object(element) {
			let type = get_class(element);
		} else {
			let type = gettype(element);
		}

		if typeof element !== "string" {
			throw new \InvalidArgumentException(
				method . "() requires a string argument instead of " . type
			);
		}
	}

	/**
	 * Returns a new instance having set the parameter
	 */
	private function cloneInstance(var element, string property) -> <Uri>
	{
    	var newInstance;

		if (element === this->{property}) {
            return this;
        }

		/**
		 * Immutable - need to send a new object back
		 */
        let newInstance             = clone this;
        let newInstance->{property} = element;

        return newInstance;
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
     */
	private function filterFragment(string fragment) -> string
	{
		if ("" !== fragment && starts_with(fragment, "#")) {
			let fragment = "%23" . substr(fragment, 1);
		}

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
     * @return string The URI path.
     */
	private function filterPath(string path) -> string
	{
		var element, index, parts;

        if "" === path || !starts_with(path, "/") {
            // Relative or empty path
            return path;
        }

		let parts  = explode("/", path);

		for index, element in parts {
			let parts[index] = rawurlencode(element);
		}

		let path = implode("/", parts);

        return "/" . ltrim(path, "/");
	}

	/**
	 * Checks the port. If it is a standard one (80,443) then it returns null
 	 */
	private function filterPort(var port) -> null | int
	{
		array ports;

		let ports = [
			80  : 1,
			443 : 1
		];

		if null !== port {
			let port = intval(port);
			if true === isset(ports[port]) {
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
     * @return string The URI query string.
     */
	private function filterQuery(string query) -> string
    {
    	var key, parts, split, value;

        if "" === query {
            return "";
        }

        if starts_with(query, "?") {
            let query = substr(query, 1);
        }

        let parts = explode("&", query);

        for key, value in parts {
			let split = explode("=", value);
			if true !== isset(split[1]) {
				let split[] = null;
			}

			if null === split[1] {
 				let parts[key] = rawurlencode(split[0]);
				continue;
			} else {
				let parts[key] = rawurlencode(split[0]) . "=" . rawurlencode(split[1]);
			}
		}

		return implode("&", parts);
    }


	/**
	 * Filters the passed scheme - only allowed schemes
	 */
	private function filterScheme(string scheme) -> string
	{
		var filtered;
		array schemes;

		let filtered = strtolower(scheme),
			filtered = preg_replace("#:(//)?$#", "", filtered),
			schemes  = [
			"http"  : 1,
			"https" : 1
		];

        if "" === filtered {
            return "";
        }

        if true !== isset(schemes[filtered]) {
            throw new \InvalidArgumentException(
            	"Unsupported scheme [" . filtered . "]. " .
            	"Scheme must be one of [" . implode(", ", schemes). "]"
			);
        }

        return scheme;
	}

	/**
	 * UTF-8 aware parse_url
	 *
	 * @link http://php.net/manual/en/function.parse-url.php#114817
	 */
	private function parseUrl(string url) -> array
	{
		var encoded, key, urlParts, value;

		let encoded = preg_replace_callback(
			"%[^:/@?&=#]+%usD",
            function (matches)
            {
                return urlencode(matches[0]);
            },
            url
        );

        let urlParts = parse_url(encoded);

		if (false === urlParts) {
			throw new \InvalidArgumentException("The source URI string appears to be malformed");
		}

		for key, value in urlParts {
			let urlParts[key] = urldecode(value);
		}

        return urlParts;
	}

	/**
	 * Checks the element passed; assigns it to the property and returns a
	 * clone of the object back
	 */
	private function processWith(var element, string property, string method) -> <Uri>
	{
		this->checkStringParameter(element, property, method);

		return this->cloneInstance(element, property);
	}
}
