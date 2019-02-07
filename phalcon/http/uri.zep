
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Http;

use Psr\Http\Message\UriInterface;
use Phalcon\Utility;

class Uri implements UriInterface
{
	/**
	 * @var string
	 */
	protected authority = "";

	/**
	 * @var string
	 */
	protected fragment = "";

	/**
	 * @var string
	 */
	protected host = "";

	/**
	 * @var string
	 */
	protected path = "";

	/**
	 * @var int
	 */
	protected port;

	/**
	 * @var string
	 */
	protected query = "";

	/**
	 * @var string
	 */
	protected scheme = "https";

	/**
	 * @var string
	 */
	protected pass = "";

	/**
	 * @var string
	 */
	protected user = "";

	/**
	 * Constructor - parses the URI
	 */
    public function __construct(string uri = "")
    {
    	var urlParts;

        let urlParts = parse_url(uri);

        if (false === urlParts) {
            throw new \InvalidArgumentException("The source URI string appears to be malformed");
        }

		/**
		 * Assign the parsed uri to the properties
		 */
		let this->scheme   = Utility::arrayGetDefault("scheme", urlParts, ""),
            this->host     = Utility::arrayGetDefault("host", urlParts, ""),
            this->port     = Utility::arrayGetDefault("port", urlParts, null),
            this->user     = Utility::arrayGetDefault("user", urlParts, ""),
            this->pass     = Utility::arrayGetDefault("pass", urlParts, ""),
            this->path     = Utility::arrayGetDefault("path", urlParts, ""),
            this->query    = Utility::arrayGetDefault("query", urlParts, ""),
            this->fragment = Utility::arrayGetDefault("fragment", urlParts, "");
    }

    /**
     * Return the string representation as a URI reference.
     */
    public function __toString() -> string
    {
    }

    /**
     * Retrieve the authority component of the URI.
     */
    public function getAuthority() -> string
    {
    	var authority, userInfo;

    	/**
    	 * Early exit if we have no host
		 */
    	if "" === this->host {
    		return "";
    	}

    	let authority = this->host,
    		userInfo  = this->getUserInfo();

    	if "" !== userInfo {
    		let authority = userInfo . "@" . authority;
    	}

    	if null !== this->port {
    		let authority .= ":" . this->port;
    	}

    	return authority;
    }

    /**
     * Retrieve the fragment component of the URI.
     */
    public function getFragment() -> string
    {
    	return this->fragment;
    }

    /**
     * Retrieve the host component of the URI.
     */
    public function getHost() -> string
    {
    	return this->host;
    }

    /**
     * Retrieve the path component of the URI.
     */
    public function getPath() -> string
    {
		return this->path;
    }

    /**
     * Retrieve the port component of the URI.
     */
    public function getPort() -> null | int
    {
		return this->port;
    }

    /**
     * Retrieve the query string of the URI.
     */
    public function getQuery() -> string
    {
    	return this->query;
    }

    /**
     * Retrieve the scheme component of the URI.
     */
    public function getScheme() -> string
    {
    	return this->scheme;
    }

    /**
     * Retrieve the user information component of the URI.
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
     */
    public function withFragment(var fragment) -> <UriInterface>
    {
    	return this->processWith(fragment, "fragment", __METHOD__);
    }

    /**
     * Return an instance with the specified host.
     */
    public function withHost(var host) -> <UriInterface>
    {
    	return this->processWith(host, "host", __METHOD__);
    }

    /**
     * Return an instance with the specified path.
     */
    public function withPath(var path) -> <UriInterface>
    {
    	return this->processWith(path, "path", __METHOD__);
    }

    /**
     * Return an instance with the specified port.
     */
    public function withPort(var port) -> <UriInterface>
    {
    	return this->processWith(port, "port", __METHOD__);
    }

    /**
     * Return an instance with the specified query string.
     */
    public function withQuery(var query) -> <UriInterface>
    {
    	return this->processWith(query, "query", __METHOD__);
    }

    /**
     * Return an instance with the specified scheme.
     */
    public function withScheme(var scheme) -> <UriInterface>
    {
    	return this->processWith(scheme, "scheme", __METHOD__);
    }

    /**
     * Return an instance with the specified user information.
     */
    public function withUserInfo(var user, var password = null) -> <UriInterface>
    {

    }

	/**
	 * Checks the element passed; assigns it to the property and returns a
	 * clone of the object back
	 */
	private function processWith(var element, string property, string method) -> <UriInterface>
	{
    	var newInstance, type;

		if is_object(element) {
			let type = get_class(element);
		} else {
			let type = gettype(element);
		}

		if typeof element !== "string" {
			throw new \InvalidArgumentException(
				method . " requires a string argument instead of " . type
			);
		}

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
}
