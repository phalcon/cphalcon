
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Http;

/**
 * Phalcon\Http\Cookie
 *
 * Provide OO wrappers to manage a HTTP cookie
 */
class Cookie implements Phalcon\Di\InjectionAwareInterface
{

	protected _readed = false;

	protected _restored = false;

	protected _useEncryption = false;

	protected _dependencyInjector;

	protected _filter;

	protected _name;

	protected _value;

	protected _expire;

	protected _path = "/";

	protected _domain;

	protected _secure;

	protected _httpOnly = true;

	/**
	 * Phalcon\Http\Cookie constructor
	 *
	 * @param string name
	 * @param mixed value
	 * @param int expire
	 * @param string path
	 * @param boolean secure
	 * @param string domain
	 * @param boolean httpOnly
	 */
	public function __construct(string! name, value=null, expire=0, path="/", secure=null, domain=null, httpOnly=null)
	{

		let this->_name = name;

		if value !== null {
			let this->_value = value;
		}

		let this->_expire = expire;

		if path !== null {
			let this->_path = path;
		}

		if secure !== null {
			let this->_secure = secure;
		}

		if domain !== null {
			let this->_domain = domain;
		}

		if httpOnly !== null {
			let this->_httpOnly = httpOnly;
		}
	}

	/**
	 * Sets the dependency injector
	 *
	 * @param Phalcon\DiInterface dependencyInjector
	 */
	public function setDI(<Phalcon\DiInterface> dependencyInjector)
	{
		let this->_dependencyInjector = dependencyInjector;
	}

	/**
	 * Returns the internal dependency injector
	 *
	 * @return Phalcon\DiInterface
	 */
	public function getDI() -> <Phalcon\DiInterface>
	{
		return this->_dependencyInjector;
	}

	/**
	 * Sets the cookie's value
	 *
	 * @param string value
	 * @return Phalcon\Http\Cookie
	 */
	public function setValue(value) -> <Phalcon\Http\Cookie>
	{
		let this->_value = value,
			this->_readed = true;
		return this;
	}

	/**
	 * Returns the cookie's value
	 *
	 * @param string|array filters
	 * @param string defaultValue
	 * @return mixed
	 */
	public function getValue(filters=null, defaultValue=null)
	{
		var dependencyInjector, value, crypt, decryptedValue, filter;

		if !this->_restored {
			this->restore();
		}

		let dependencyInjector = null;

		if this->_readed === false {

			if fetch value, _COOKIE[this->_name] {

				if this->_useEncryption {

					let dependencyInjector = this->_dependencyInjector;
					if typeof dependencyInjector != "object" {
						throw new Phalcon\Http\Response\Exception("A dependency injection object is required to access the 'filter' service");
					}

					let crypt = dependencyInjector->getShared("crypt");

					/**
					 * Decrypt the value also decoding it with base64
					 */
					let decryptedValue = crypt->decryptBase64(value);

				} else {
					let decryptedValue = value;
				}

				/**
				 * Update the decrypted value
				 */
				let this->_value = decryptedValue;

				if filters !== null {
					let filter = this->_filter;
					if typeof filter != "object" {

						if dependencyInjector === null {
							let dependencyInjector = this->_dependencyInjector;
							if typeof dependencyInjector != "object" {
								throw new Phalcon\Http\Response\Exception("A dependency injection object is required to access the 'filter' service");
							}
						}

						let filter = dependencyInjector->getShared("filter"),
							this->_filter = filter;
					}

					return filter->sanitize(decryptedValue, filters);
				}

				/**
				 * Return the value without filtering
				 */
				return decryptedValue;
			}
			return defaultValue;
		}

		return this->_value;
	}

	/**
	 * Sends the cookie to the HTTP client
	 * Stores the cookie definition in session
	 *
	 * @return Phalcon\Http\Cookie
	 */
	public function send() -> <Phalcon\Http\Cookie>
	{
		var name, value, expire, domain, path, secure, httpOnly,
			dependencyInjector, definition, session, crypt, encryptValue;

		let name = this->_name,
			value = this->_value,
			expire = this->_expire,
			domain = this->_domain,
			path = this->_path,
			secure = this->_secure,
			httpOnly = this->_httpOnly;

		let dependencyInjector = this->_dependencyInjector;

		if typeof dependencyInjector != "object" {
			throw new Phalcon\Http\Response\Exception("A dependency injection object is required to access the 'session' service");
		}

		let definition = [];

		if expire != 0 {
			let definition["expire"] = expire;
		}

		if !empty path {
			let definition["path"] = path;
		}

		if !empty domain {
			let definition["domain"] = domain;
		}

		if !empty secure {
			let definition["secure"] = secure;
		}

		if !empty httpOnly {
			let definition["httpOnly"] = httpOnly;
		}

		/**
		 * The definition is stored in session
		 */
		if count(definition) {
			let session = <Phalcon\Session\AdapterInterface> dependencyInjector->getShared("session");
			session->set("_PHCOOKIE_" . name, definition);
		}

		if this->_useEncryption {

			if !empty value {

				if typeof dependencyInjector != "object" {
					throw new Phalcon\Http\Response\Exception("A dependency injection object is required to access the 'filter' service");
				}

				let crypt = <Phalcon\CryptInterface> dependencyInjector->getShared("crypt");

				/**
				 * Encrypt the value also coding it with base64
				 */
				let encryptValue = crypt->encryptBase64(value);
			} else {
				let encryptValue = value;
			}

		} else {
			let encryptValue = value;
		}

		/**
		 * Sets the cookie using the standard 'setcookie' function
		 */
		setcookie(name, encryptValue, expire, path, domain, secure, httpOnly);

		return this;
	}

	/**
	 * Reads the cookie-related info from the SESSION to restore the cookie as it was set
	 * This method is automatically called internally so normally you don't need to call it
	 *
	 * @return Phalcon\Http\Cookie
	 */
	public function restore() -> <Phalcon\Http\Cookie>
	{
		var dependencyInjector, expire, domain, path, secure,
			httpOnly, session, definition;

		if !this->_restored {

			let dependencyInjector = this->_dependencyInjector;
			if typeof dependencyInjector == "object" {

				let session = dependencyInjector->getShared("session");

				let definition = session->get("_PHCOOKIE_" . this->_name);
				if typeof definition == "array" {

					if fetch expire, definition["expire"] {
						let this->_expire = expire;
					}

					if fetch domain, definition["domain"] {
						let this->_domain = domain;
					}

					if fetch path, definition["path"] {
						let this->_path = path;
					}

					if fetch secure, definition["secure"] {
						let this->_secure = secure;
					}

					if fetch httpOnly, definition["httpOnly"] {
						let this->_httpOnly = httpOnly;
					}

				}
			}

			let this->_restored = true;
		}

		return this;
	}

	/**
	 * Deletes the cookie by setting an expire time in the past
	 *
	 */
	public function delete()
	{
		var name, value, expire, domain, path, secure, httpOnly,
			dependencyInjector, definition, session;

		let name     = this->_name,
			domain   = this->_domain,
			path     = this->_path,
			secure   = this->_secure,
			httpOnly = this->_httpOnly;

		let dependencyInjector = <Phalcon\DiInterface> this->_dependencyInjector;
		if typeof dependencyInjector != "object" {
			let session = <Phalcon\Session\AdapterInterface> dependencyInjector->getShared("session");
			session->remove("_PHCOOKIE_" . name);
		}

		let this->_value = null;
		setcookie(name, null, time() - 691200, path, domain, secure, httpOnly);
	}

	/**
	 * Sets if the cookie must be encrypted/decrypted automatically
	 *
	 * @param boolean useEncryption
	 * @return Phalcon\Http\Cookie
	 */
	public function useEncryption(boolean useEncryption) -> <Phalcon\Http\Cookie>
	{
		let this->_useEncryption = useEncryption;
		return this;
	}

	/**
	 * Check if the cookie is using implicit encryption
	 *
	 * @return boolean
	 */
	public function isUsingEncryption() -> boolean
	{
		return this->_useEncryption;
	}

	/**
	 * Sets the cookie's expiration time
	 *
	 * @param int expire
	 * @return Phalcon\Http\Cookie
	 */
	public function setExpiration(int expire) -> <Phalcon\Http\Cookie>
	{
		if !this->_restored {
			this->restore();
		}
		let this->_expire = expire;
		return this;
	}

	/**
	 * Returns the current expiration time
	 *
	 * @return string
	 */
	public function getExpiration() -> string
	{
		if !this->_restored {
			this->restore();
		}
		return this->_expire;
	}

	/**
	 * Sets the cookie's expiration time
	 *
	 * @param string path
	 * @return Phalcon\Http\Cookie
	 */
	public function setPath(string! path)
	{
		if !this->_restored {
			this->restore();
		}
		let this->_path = path;
		return this;
	}

	/**
	 * Returns the current cookie's path
	 *
	 * @return string
	 */
	public function getPath() -> string
	{
		if !this->_restored {
			this->restore();
		}
		return this->_path;
	}

	/**
	 * Sets the domain that the cookie is available to
	 *
	 * @param string domain
	 * @return Phalcon\Http\Cookie
	 */
	public function setDomain(string! domain) -> <Phalcon\Http\Cookie>
	{
		if !this->_restored {
			this->restore();
		}
		let this->_domain = domain;
		return this;
	}

	/**
	 * Returns the domain that the cookie is available to
	 *
	 * @return string
	 */
	public function getDomain() -> string
	{
		if !this->_restored {
			this->restore();
		}
		return this->_domain;
	}

	/**
	 * Sets if the cookie must only be sent when the connection is secure (HTTPS)
	 *
	 * @param boolean secure
	 * @return Phalcon\Http\Cookie
	 */
	public function setSecure(boolean secure) -> <Phalcon\Http\Cookie>
	{
		if !this->_restored {
			this->restore();
		}
		let this->_secure = secure;
		return this;
	}

	/**
	 * Returns whether the cookie must only be sent when the connection is secure (HTTPS)
	 *
	 * @return boolean
	 */
	public function getSecure()
	{
		if !this->_restored {
			this->restore();
		}
		return this->_secure;
	}

	/**
	 * Sets if the cookie is accessible only through the HTTP protocol
	 *
	 * @param boolean httpOnly
	 * @return Phalcon\Http\Cookie
	 */
	public function setHttpOnly(boolean httpOnly) -> <Phalcon\Http\Cookie>
	{
		if !this->_restored {
			this->restore();
		}
		let this->_httpOnly = httpOnly;
		return this;
	}

	/**
	 * Returns if the cookie is accessible only through the HTTP protocol
	 *
	 * @return boolean
	 */
	public function getHttpOnly() -> boolean
	{
		if !this->_restored {
			this->restore();
		}
		return this->_httpOnly;
	}

	/**
	 * Magic __toString method converts the cookie's value to string
	 *
	 * @return mixed
	 */
	public function __toString()
	{

	}

}
