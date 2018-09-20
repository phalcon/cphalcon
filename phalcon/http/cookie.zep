
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

namespace Phalcon\Http;

use Phalcon\DiInterface;
use Phalcon\CryptInterface;
use Phalcon\Di\InjectionAwareInterface;
use Phalcon\Http\Response\Exception;
use Phalcon\Http\Cookie\Exception as CookieException;
use Phalcon\Crypt\Mismatch;
use Phalcon\Session\AdapterInterface as SessionInterface;

/**
 * Phalcon\Http\Cookie
 *
 * Provide OO wrappers to manage a HTTP cookie.
 */
class Cookie implements CookieInterface, InjectionAwareInterface
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
	 * The cookie's sign key.
	 * @var string|null
     */
	protected signKey = null;

	/**
	 * Phalcon\Http\Cookie constructor.
	 */
	public function __construct(
		string! name,
		var value = null,
		int expire = 0,
		string path = "/",
		boolean secure = null,
		string domain = null,
		boolean httpOnly = null
	) {
		let this->_name = name;

		if value !== null {
			this->setValue(value);
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
	 * Sets the cookie's sign key.
	 *
	 * The `$signKey' MUST be at least 32 characters long
	 * and generated using a cryptographically secure pseudo random generator.
	 *
	 * Use NULL to disable cookie signing.
	 *
	 * @see \Phalcon\Security\Random
	 * @throws \Phalcon\Http\Cookie\Exception
	 */
	public function setSignKey(string signKey = null) -> <CookieInterface>
	{
		if signKey !== null {
			this->assertSignKeyIsLongEnough(signKey);
		}

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
	 * Sets the cookie's value
	 *
	 * @param string value
	 * @return \Phalcon\Http\Cookie
	 */
	public function setValue(value) -> <CookieInterface>
	{
		let this->_value = value,
			this->_readed = true;
		return this;
	}

	/**
	 * Returns the cookie's value.
	 */
	public function getValue(var filters = null, var defaultValue = null) -> var
	{
		var dependencyInjector, value, crypt, decryptedValue, filter, signKey, name;

		if !this->_restored {
			this->restore();
		}

		let dependencyInjector = null,
			name = this->_name;

		if this->_readed === false {

			if fetch value, _COOKIE[name] {

				if this->_useEncryption {

					let dependencyInjector = <DiInterface> this->_dependencyInjector;
					if typeof dependencyInjector != "object" {
						throw new Exception(
							"A dependency injection object is required to access the 'filter' and 'crypt' service"
						);
					}

					let crypt = <CryptInterface> dependencyInjector->getShared("crypt");
					if typeof crypt != "object" {
						throw new Exception(
							"A dependency which implements CryptInterface is required to use encryption"
						);
					}

					/**
					 * Verify the cookie's value if the sign key was set
					 */
					let signKey = this->signKey;
					if typeof signKey === "string" {
						/**
						 * Decrypt the value also decoding it with base64
						 */
						let decryptedValue = crypt->decryptBase64(value, signKey);
					} else {
						/**
						 * Decrypt the value also decoding it with base64
						 */
						let decryptedValue = crypt->decryptBase64(value);
					}
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
							let dependencyInjector = <DiInterface> this->_dependencyInjector;
							if typeof dependencyInjector != "object" {
								throw new Exception(
									"A dependency injection object is required to access the 'filter' service"
								);
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
	 * Sends the cookie to the HTTP client.
	 *
	 * Stores the cookie definition in session.
	 */
	public function send() -> <CookieInterface>
	{
		var name, value, expire, domain, path, secure, httpOnly,
			dependencyInjector, definition, session, crypt, encryptValue, signKey;

		let name = this->_name,
			value = this->_value,
			expire = this->_expire,
			domain = this->_domain,
			path = this->_path,
			secure = this->_secure,
			httpOnly = this->_httpOnly;

		let dependencyInjector = this->_dependencyInjector;

		if typeof dependencyInjector != "object" {
			throw new Exception("A dependency injection object is required to access the 'session' service");
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
			let session = <SessionInterface> dependencyInjector->getShared("session");
			if session->isStarted() {
				session->set("_PHCOOKIE_" . name, definition);
			}
		}

		if this->_useEncryption {

			if !empty value {

				if typeof dependencyInjector != "object" {
					throw new Exception(
						"A dependency injection object is required to access the 'filter' service"
					);
				}

				let crypt = <CryptInterface> dependencyInjector->getShared("crypt");
				if typeof crypt != "object" {
					throw new Exception(
						"A dependency which implements CryptInterface is required to use encryption"
					);
				}

				/**
				 * Encrypt the value also coding it with base64.
				 * Sign the cookie's value if the sign key was set
				 */
				let signKey = this->signKey;
				if typeof signKey === "string" {
					let encryptValue = crypt->encryptBase64((string) value, signKey);
				} else {
					let encryptValue = crypt->encryptBase64((string) value);
				}
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
	 * Reads the cookie-related info from the SESSION to restore the cookie as it was set.
	 *
	 * This method is automatically called internally so normally you don't need to call it.
	 */
	public function restore() -> <CookieInterface>
	{
		var dependencyInjector, expire, domain, path, secure,
			httpOnly, session, definition;

		if !this->_restored {

			let dependencyInjector = this->_dependencyInjector;
			if typeof dependencyInjector == "object" {

				let session = dependencyInjector->getShared("session");

				if session->isStarted() {
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
			}

			let this->_restored = true;
		}

		return this;
	}

	/**
	 * Deletes the cookie by setting an expire time in the past
	 */
	public function delete()
	{
		var name, domain, path, secure, httpOnly, dependencyInjector, session;

		let name     = this->_name,
			domain   = this->_domain,
			path     = this->_path,
			secure   = this->_secure,
			httpOnly = this->_httpOnly;

		let dependencyInjector = <DiInterface> this->_dependencyInjector;
		if typeof dependencyInjector == "object" {
			let session = <SessionInterface> dependencyInjector->getShared("session");
			if session->isStarted() {
				session->remove("_PHCOOKIE_" . name);
			}
		}

		let this->_value = null;
		setcookie(name, null, time() - 691200, path, domain, secure, httpOnly);
	}

	/**
	 * Sets if the cookie must be encrypted/decrypted automatically
	 */
	public function useEncryption(boolean useEncryption) -> <CookieInterface>
	{
		let this->_useEncryption = useEncryption;
		return this;
	}

	/**
	 * Check if the cookie is using implicit encryption
	 */
	public function isUsingEncryption() -> boolean
	{
		return this->_useEncryption;
	}

	/**
	 * Sets the cookie's expiration time
	 */
	public function setExpiration(int expire) -> <CookieInterface>
	{
		if !this->_restored {
			this->restore();
		}
		let this->_expire = expire;
		return this;
	}

	/**
	 * Returns the current expiration time
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
	 */
	public function setPath(string! path) -> <CookieInterface>
	{
		if !this->_restored {
			this->restore();
		}
		let this->_path = path;
		return this;
	}

	/**
	 * Returns the current cookie's name
	 */
	public function getName() -> string
	{
		return this->_name;
	}

	/**
	 * Returns the current cookie's path
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
	 */
	public function setDomain(string! domain) -> <CookieInterface>
	{
		if !this->_restored {
			this->restore();
		}
		let this->_domain = domain;
		return this;
	}

	/**
	 * Returns the domain that the cookie is available to
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
	 */
	public function setSecure(boolean secure) -> <CookieInterface>
	{
		if !this->_restored {
			this->restore();
		}
		let this->_secure = secure;
		return this;
	}

	/**
	 * Returns whether the cookie must only be sent when the connection is secure (HTTPS)
	 */
	public function getSecure() -> boolean
	{
		if !this->_restored {
			this->restore();
		}
		return this->_secure;
	}

	/**
	 * Sets if the cookie is accessible only through the HTTP protocol
	 */
	public function setHttpOnly(boolean httpOnly) -> <CookieInterface>
	{
		if !this->_restored {
			this->restore();
		}
		let this->_httpOnly = httpOnly;
		return this;
	}

	/**
	 * Returns if the cookie is accessible only through the HTTP protocol
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
	 */
	public function __toString() -> string
	{
		return (string) this->getValue();
	}

	/**
	 * Assert the cookie's key is enough long.
	 *
	 * @throws \Phalcon\Http\Cookie\Exception
	 */
	protected function assertSignKeyIsLongEnough(string! signKey) -> void
	{
		var length;

		let length = mb_strlen(signKey);
		if length < 32 {
			throw new CookieException(
				sprintf(
					"The cookie's key should be at least 32 characters long. Current length is %d.",
					length
				)
			);
		}
	}
}
