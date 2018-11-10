
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2018 Phalcon Team (https://phalconphp.com)          |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Http\Response;

use Phalcon\DiInterface;
use Phalcon\Http\CookieInterface;
use Phalcon\Http\Response\CookiesInterface;
use Phalcon\Di\InjectionAwareInterface;
use Phalcon\Http\Cookie\Exception;

/**
 * Phalcon\Http\Response\Cookies
 *
 * This class is a bag to manage the cookies.
 *
 * A cookies bag is automatically registered as part of the 'response' service in the DI.
 * By default, cookies are automatically encrypted before being sent to the client and are
 * decrypted when retrieved from the user. To set sign key used to generate a message
 * authentication code use `Phalcon\Http\Response\Cookies::setSignKey`.
 *
 * <code>
 * use Phalcon\Di;
 * use Phalcon\Crypt;
 * use Phalcon\Http\Response\Cookies;
 *
 * $di = new Di();
 *
 * $di->set(
 *     'crypt',
 *     function () {
 *         $crypt = new Crypt();
 *
 *         // The `$key' should have been previously generated in a cryptographically safe way.
 *         $key = "T4\xb1\x8d\xa9\x98\x05\\\x8c\xbe\x1d\x07&[\x99\x18\xa4~Lc1\xbeW\xb3";
 *         $crypt->setKey($key);
 *
 *         return $crypt;
 *     }
 * );
 *
 *
 * $di->set(
 *     'cookies',
 *     function () {
 *         $cookies = new Cookies();
 *
 *         // The `$key' MUST be at least 32 characters long and generated using a
 *         // cryptographically secure pseudo random generator.
 *         $key = "#1dj8$=dp?.ak//j1V$~%*0XaK\xb1\x8d\xa9\x98\x054t7w!z%C*F-Jk\x98\x05\\\x5c";
 *         $cookies->setSignKey($key);
 *
 *         return $cookies;
 *     }
 * );
 * </code>
 */
class Cookies implements CookiesInterface, InjectionAwareInterface
{
	protected _dependencyInjector;

	protected _registered = false;

	protected _useEncryption = true;

	protected _cookies;

	/**
	 * The cookie's sign key.
	 * @var string|null
     */
	protected signKey = null;

	/**
	 * Phalcon\Http\Response\Cookies constructor
	 */
	public function __construct(bool useEncryption = true, string signKey = null)
	{
		let this->_useEncryption = useEncryption;
		let this->_cookies = [];

		this->setSignKey(signKey);
	}

	/**
	 * Sets the cookie's sign key.
	 *
	 * The `$signKey' MUST be at least 32 characters long
	 * and generated using a cryptographically secure pseudo random generator.
	 *
	 * Use NULL to disable cookie signing.
	 *
	 * @see \Phalcon\Security\Random
	 */
	public function setSignKey(string signKey = null) -> <CookieInterface>
	{
		let this->signKey = signKey;

		return this;
	}

	/**
	 * Sets the dependency injector
	 */
	public function setDI(<DiInterface> dependencyInjector)
	{
		let this->_dependencyInjector = dependencyInjector;
	}

	/**
	 * Returns the internal dependency injector
	 */
	public function getDI() -> <DiInterface>
	{
		return this->_dependencyInjector;
	}

	/**
	 * Set if cookies in the bag must be automatically encrypted/decrypted
	 */
	public function useEncryption(boolean useEncryption) -> <CookiesInterface>
	{
		let this->_useEncryption = useEncryption;
		return this;
	}

	/**
	 * Returns if the bag is automatically encrypting/decrypting cookies
	 */
	public function isUsingEncryption() -> boolean
	{
		return this->_useEncryption;
	}

	/**
	 * Sets a cookie to be sent at the end of the request.
	 *
	 * This method overrides any cookie set before with the same name.
	 *
	 * <code>
	 * use Phalcon\Http\Response\Cookies;
	 *
	 * $now = new DateTimeImmutable();
	 * $tomorrow = $now->modify('tomorrow');
	 *
	 * $cookies = new Cookies();
	 * $cookies->set(
	 *     'remember-me',
	 *     json_encode(['user_id' => 1]),
	 *     (int) $tomorrow->format('U'),
	 * );
	 * </code>
	 */
	public function set(
		string! name,
		value = null,
		int expire = 0,
		string path = "/",
		boolean secure = null,
		string! domain = null,
		boolean httpOnly = null
	) -> <CookiesInterface> {
		var cookie, encryption, dependencyInjector, response;

		let encryption = this->_useEncryption;

		/**
		 * Check if the cookie needs to be updated or
		 */
		if !fetch cookie, this->_cookies[name] {
			let cookie =
				<CookieInterface> this->_dependencyInjector->get(
					"Phalcon\\Http\\Cookie",
					[name, value, expire, path, secure, domain, httpOnly]
				);

			/**
			 * Pass the DI to created cookies
			 */
			cookie->setDi(this->_dependencyInjector);

			/**
			 * Enable encryption in the cookie
			 */
			if encryption {
				cookie->useEncryption(encryption);
				cookie->setSignKey(this->signKey);
			}

			let this->_cookies[name] = cookie;

		} else {
			/**
			 * Override any settings in the cookie
			 */
			cookie->setValue(value);
			cookie->setExpiration(expire);
			cookie->setPath(path);
			cookie->setSecure(secure);
			cookie->setDomain(domain);
			cookie->setHttpOnly(httpOnly);
			cookie->setSignKey(this->signKey);
		}

		/**
		 * Register the cookies bag in the response
		 */
		if this->_registered === false {

			let dependencyInjector = this->_dependencyInjector;
			if typeof dependencyInjector != "object" {
				throw new Exception("A dependency injection object is required to access the 'response' service");
			}

			let response = dependencyInjector->getShared("response");

			/**
			 * Pass the cookies bag to the response so it can send the headers at the of the request
			 */
			response->setCookies(this);

			let this->_registered = true;
		}

		return this;
	}

	/**
	 * Gets a cookie from the bag
	 */
	public function get(string! name) -> <\Phalcon\Http\Response\CookiesInterface>
	{
		var dependencyInjector, encryption, cookie;

		/**
		 * Gets cookie from the cookies service. They will be sent with response.
		 */
		if fetch cookie, this->_cookies[name] {
			return cookie;
		}

		/**
		 * Create the cookie if the it does not exist.
		 * It's value come from $_COOKIE with request, so it shouldn't be saved
		 * to _cookies property, otherwise it will always be resent after get.
		 */
		let cookie = <CookieInterface> this->_dependencyInjector->get("Phalcon\\Http\\Cookie", [name]),
			dependencyInjector = this->_dependencyInjector;

		if typeof dependencyInjector == "object" {

			/**
			 * Pass the DI to created cookies
			 */
			cookie->setDi(dependencyInjector);

			let encryption = this->_useEncryption;

			/**
			 * Enable encryption in the cookie
			 */
			if encryption {
				cookie->useEncryption(encryption);
				cookie->setSignKey(this->signKey);
			}
		}

		return cookie;
	}

	/**
	 * Check if a cookie is defined in the bag or exists in the _COOKIE superglobal
	 */
	public function has(string! name) -> boolean
	{
		/**
		 * Check the internal bag
		 */
		if isset this->_cookies[name] {
			return true;
		}

		/**
		 * Check the superglobal
		 */
		if isset _COOKIE[name] {
			return true;
		}

		return false;
	}

	/**
	 * Deletes a cookie by its name
	 * This method does not removes cookies from the _COOKIE superglobal
	 */
	public function delete(string! name) -> boolean
	{
		var cookie;

		/**
		 * Check the internal bag
		 */
		if fetch cookie, this->_cookies[name] {
			cookie->delete();
			return true;
		}

		return false;
	}

	/**
	 * Sends the cookies to the client
	 * Cookies aren't sent if headers are sent in the current request
	 */
	public function send() -> boolean
	{
		var cookie;

		if !headers_sent() {
			for cookie in this->_cookies {
				cookie->send();
			}

			return true;
		}

		return false;
	}

	/**
	 * Reset set cookies
	 */
	public function reset() -> <CookiesInterface>
	{
		let this->_cookies = [];
		return this;
	}
}
