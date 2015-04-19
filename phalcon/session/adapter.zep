
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
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
 |          Stanislav Kiryukhin <korsar.zn@gmail.com>                     |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Session;

use Phalcon\Session\Exception;

/**
 * Phalcon\Session\Adapter
 *
 * Base class for Phalcon\Session adapter
 *
 * <code>
 * $session = new \Phalcon\Session\Adapter\SomeAdapter(array(
 *    'uniqueId' => 'my-private-app',
 *    'name' => 'session-name',
 *    'cookie_lifetime' => 'session-cookie-lifetime',
 *    'cookie_path' => 'session-cookie-path',
 *    'cookie_domain' => 'session-cookie-domain',
 *    'cookie_secure' => 'session-cookie-secure',
 *    'cookie_httponly' => 'session-cookie-httponly'
 * ));
 *
 * $session->start();
 *
 * $session->set('var', 'some-value');
 *
 * echo $session->get('var');
 *</code>
 */
abstract class Adapter implements AdapterInterface
{
	/**
	* if sessions are enabled, and one exists.
	* @see PHP_SESSION_ACTIVE
	*/
	const SESSION_ACTIVE = 2;

	/**
	 * if sessions are enabled, but none exists.
	 * @see PHP_SESSION_NONE
	 */
	const SESSION_NONE = 1;

	/**
	 * if sessions are disabled.
	 * @see PHP_SESSION_DISABLED
	 */
	const SESSION_DISABLED = 0;

	protected _uniqueId;

	protected _started = false;

	protected _options;

	/**
	 * Phalcon\Session\Adapter constructor
	 */
	public function __construct(var options = null)
	{
		if typeof options == "array" {
			this->setOptions(options);
		}

		/**
		* Configure Session (cookie parameters, etc...)
		*/
		this->configure();
	}

	/**
	 * Starts the session (if headers are already sent the session will not be started)
	 */
	public function start() -> boolean
	{
		if !headers_sent() {
			if !this->_started && this->status() !== self::SESSION_ACTIVE {
				session_start();
				let this->_started = true;
				return true;
			}
		}
		return false;
	}

	/**
	 * Gets the session cookie parameters
	 * @see http://php.net/manual/en/function.session-get-cookie-params.php
	 */
	public function getCookieParams() -> array
	{
		return session_get_cookie_params();
	}

	/**
	 * Sets the session cookie parameters
	 * @see http://php.net/manual/en/function.session-set-cookie-params.php
	 */
	public function setCookieParams(int! lifetime, string path, string domain, bool secure = false, bool httpOnly = false) -> void
	{
		session_set_cookie_params(lifetime, path, domain, secure, httpOnly);
	}

	/**
	 * Sets session's options
	 *
	 *<code>
	 *	$session->setOptions(array(
	 *		'uniqueId' => 'my-private-app'
	 *	));
	 *</code>
	 */
	public function setOptions(array! options)
	{
		var uniqueId;

		if fetch uniqueId, options["uniqueId"] {
			let this->_uniqueId = uniqueId;
		}

		let this->_options = options;
	}

	/**
	 * Get internal options
	 */
	public function getOptions() -> array
	{
		return this->_options;
	}

	/**
	 * Returns an option in the session's options
	 * Returns defaultValue if the option hasn't set
	 */
	public function getOption(string key, var defaultValue = null) -> var
	{
		var value;

		if fetch value, this->_options[key] {
			return value;
		} else {
			return defaultValue;
		}
	}

	/**
	 * Sets the current session name and return the old session name
	 * @see http://php.net/manual/en/function.session-name.php
	 */
	public function setName(string name) -> string
	{
		return session_name(name);
	}

	/**
	 * Gets the current session name
	 * @see http://php.net/manual/en/function.session-name.php
	 */
	public function getName() -> string
	{
		return session_name();
	}

	/**
	 * {@inheritdoc}
	 */
	public function regenerateId(bool deleteOldSession = false) -> string | boolean
	{
		if session_regenerate_id(deleteOldSession) {
			return this->getId();
		} else {
			return false;
		}
	}

	/**
	 * Gets a session variable from an application context
	 *
	 *<code>
	 *	$session->get('auth', 'yes');
	 *</code>
	 */
	public function get(string index, var defaultValue = null, boolean remove = false) -> var
	{
		var value, key, uniqueId;

		let uniqueId = this->_uniqueId;
		if !empty uniqueId {
			let key = uniqueId . "#" . index;
		} else {
			let key = index;
		}

		if fetch value, _SESSION[key] {
			if remove {
				unset _SESSION[key];
			}
			return value;
		}

		return defaultValue;
	}

	/**
	 * Sets a session variable in an application context
	 *
	 *<code>
	 *	$session->set('auth', 'yes');
	 *</code>
	 */
	public function set(string index, var value)
	{
		var uniqueId;

		let uniqueId = this->_uniqueId;
		if !empty uniqueId {
			let _SESSION[uniqueId . "#" . index] = value;
			return;
		}

		let _SESSION[index] = value;
	}

	/**
	 * Check whether a session variable is set in an application context
	 *
	 *<code>
	 *	var_dump($session->has('auth'));
	 *</code>
	 */
	public function has(string index) -> boolean
	{
		var uniqueId;

		let uniqueId = this->_uniqueId;
		if !empty uniqueId {
			return isset _SESSION[uniqueId . "#" . index];
		}

		return isset _SESSION[index];
	}

	/**
	 * Removes a session variable from an application context
	 *
	 *<code>
	 *	$session->remove('auth');
	 *</code>
	 */
	public function remove(string index) -> void
	{
		var uniqueId;

		let uniqueId = this->_uniqueId;
		if !empty uniqueId {
			unset _SESSION[uniqueId . "#" . index];
			return;
		}

		unset _SESSION[index];
	}

	/**
	 * Returns active session id
	 *
	 *<code>
	 *	echo $session->getId();
	 *</code>
	 */
	public function getId() -> string
	{
		return session_id();
	}

	/**
	 * Set the current session id
	 *
	 *<code>
	 *	$session->setId($id);
	 *</code>
	 */
	public function setId(string id) -> void
	{
		session_id(id);
	}

	/**
	 * Check whether the session has been started
	 *
	 *<code>
	 *	var_dump($session->isStarted());
	 *</code>
	 */
	public function isStarted() -> boolean
	{
		let this->_started = this->status() == self::SESSION_ACTIVE;
		return this->_started;
	}

	/**
	 * Destroys the active session
	 *
	 *<code>
	 *	var_dump($session->destroy());
	 *	var_dump($session->destroy(true));
	 *</code>
	 */
	public function destroy(boolean removeData = false) -> boolean
	{
		var uniqueId, key;

		if !this->isStarted() {
			throw new Exception("Trying to destroy uninitialized session...");
		}

		if removeData {
			let uniqueId = this->_uniqueId;
			if !empty uniqueId {
				for key, _ in _SESSION {
					if starts_with(key, uniqueId . "#") {
						unset _SESSION[key];
					}
				}
			} else {
				let _SESSION = [];
			}
		}

		let this->_started = false;
		return session_destroy();
	}

	/**
	 * {@inheritdoc}
	 */
	public function abort() -> void
	{
		let this->_started = false;

		if function_exists("session_abort") {
			session_abort();
		} else {
			this->legacySessionAbort();
		}
	}

	/**
	 * {@inheritdoc}
	 */
	public function reset() -> void
	{
		if !this->isStarted() {
			throw new Exception("Trying to reset uninitialized session...");
		}

		if function_exists("session_reset") {
			session_reset();
		} else {
			this->legacySessionReset();
		}
	}

	/**
	 * {@inheritdoc}
	 */
	public function commit() -> void
	{
		let this->_started = false;
		session_write_close();
	}

	/**
	 * {@inheritdoc}
	 */
	public function clear() -> void
	{
		if !this->isStarted() {
			throw new Exception("Trying to clear uninitialized session...");
		}

		session_unset();
	}

	/**
	 * {@inheritdoc}
	 */
	public function encode() -> string
	{
		return session_encode();
	}

	/**
	 * {@inheritdoc}
	 */
	public function decode(string data) -> boolean
	{
		return session_decode(data);
	}

	/**
	 * Returns the current session status (const: SESSION_DISABLED, SESSION_NONE, SESSION_ACTIVE)
	 * @see http://php.net/manual/en/function.session-status.php
	 *
	 *<code>
	 *	var_dump($session->status());
	 *
	 *  if ($session->status() !== $session::SESSION_ACTIVE) {
	 *      $session->start();
	 *  }
	 *</code>
	 */
	public function status() -> int
	{
		if function_exists("session_status") {
			return session_status();
		} else {
			return this->legacySessionStatus();
		}
	}

	/**
	 * Alias: Gets a session variable from an application context
	 */
	public function __get(string index) -> var
	{
		return this->get(index);
	}

	/**
	 * Alias: Sets a session variable in an application context
	 */
	public function __set(string index, var value)
	{
		this->set(index, value);
	}

	/**
	 * Alias: Check whether a session variable is set in an application context
	 */
	public function __isset(string index) -> boolean
	{
		return this->has(index);
	}

	/**
	 * Alias: Removes a session variable from an application context
	 */
	public function __unset(string index) -> void
	{
		this->remove(index);
	}

	/**
	 * Configure session adapter
	 */
	protected function configure() -> void
	{
		var params, name;

		let params = this->getCookieParams();
		let name = this->getOption("name");

		if name {
			this->setName(name);
		}

		this->setCookieParams(
			this->getOption("cookie_lifetime", 	params["lifetime"]),
			this->getOption("cookie_path", 		params["path"]),
			this->getOption("cookie_domain", 	params["domain"]),
			this->getOption("cookie_secure", 	params["secure"]),
			this->getOption("cookie_httponly", 	params["httponly"])
		);
	}

	/**
	 * Implementation of the function session_reset() for PHP < v5.6
	 * Please do not call manually, use this Phalcon\Session\AdapterInterface::reset() for it
	 */
	protected function legacySessionReset() -> void
	{
		if method_exists(this, "read") {
			this->clear();
			this->decode(this->{"read"}(this->getId()));
			return;
		}

		throw new Exception("Please implement method read() for your adapter session.");
	}

	/**
	 * Implementation of the function session_abort() for PHP < v5.6
	 * Please do not call manually, use this Phalcon\Session\AdapterInterface::abort() for it
	 */
	protected function legacySessionAbort() -> void
	{
		this->reset();
		this->commit();
	}

	/**
	 * Implementation of the function session_status() for PHP < v5.4
	 * Please do not call manually, use this Phalcon\Session\AdapterInterface::status() for it
	 */
	protected function legacySessionStatus() -> int
	{
		if this->_started || session_decode(null) {
			return self::SESSION_ACTIVE;
		} elseif ini_get("session.serialize_handler") === null {
			return self::SESSION_DISABLED;
		} else {
			return self::SESSION_NONE;
		}
	}
}
