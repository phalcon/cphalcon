
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

/**
 * Phalcon\Session\Adapter
 *
 * Base class for Phalcon\Session adapter
 *
 *<code>
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
abstract class Adapter
{

	protected _uniqueId;

	protected _started = false;

	protected _options;

	/**
	 * Phalcon\Session\Adapter constructor
	 */
	public function __construct(options = null)
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
			session_start();
			let this->_started = true;
			return true;
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
	public function setCookieParams(int! lifetime, string! path, string! domain, bool! secure = false, bool! httpOnly = false) -> void
	{
		session_set_cookie_params(lifetime, path, domain, secure, httpOnly);
	}

	/**
	 * Sets session's options
	 *
	 *<code>
	 *	session->setOptions(array(
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
	public function getOption(string! key, var defaultValue = null) -> var
	{
		var value;

		if fetch value, this->_options[key] {
			return value;
		} else {
			return defaultValue;
		}
	}

	/**
	 * Gets a session variable from an application context
	 */
	public function get(string! index, var defaultValue = null, boolean remove = false) -> var
	{
		var value, key;

		let key = this->_uniqueId . index;
		if fetch value, _SESSION[key] {
			if !empty value {
				if remove {
					unset _SESSION[key];
				}
				return value;
			}
		}
		return defaultValue;
	}

	/**
	 * Sets a session variable in an application context
	 *
	 *<code>
	 *	session->set('auth', 'yes');
	 *</code>
	 */
	public function set(string! index, var value) -> void
	{
		let _SESSION[this->_uniqueId . index] = value;
	}

	/**
	 * Check whether a session variable is set in an application context
	 *
	 *<code>
	 *	var_dump($session->has('auth'));
	 *</code>
	 */
	public function has(string! index) -> boolean
	{
		return isset _SESSION[this->_uniqueId . index];
	}

	/**
	 * Removes a session variable from an application context
	 *
	 *<code>
	 *	$session->remove('auth');
	 *</code>
	 */
	public function remove(string! index) -> void
	{
		unset _SESSION[this->_uniqueId . index];
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
	public function setId(string! id) -> void
	{
		session_id(id);
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
	 * Sets the current session name
	 * @see http://php.net/manual/en/function.session-name.php
	 */
	public function setName(string! name) -> void
	{
		session_name(name);
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
		return this->_started;
	}

	/**
	 * Destroys the active session
	 *
	 *<code>
	 *	var_dump(session->destroy());
	 *</code>
	 */
	public function destroy() -> boolean
	{
		let this->_started = false;
		return session_destroy();
	}

	/**
	 * Re-initialize session array with original values
	 * @see http://php.net/manual/en/function.session-reset.php
	 */
	public function reset() -> boolean
	{
		return session_reset();
	}

	/**
	 * Write session data and end session
	 * @see http://php.net/manual/en/function.session-write-close.php
	 */
	public function commit() -> void
	{
		session_write_close();
	}

	/**
	 * Discard session array changes and finish session
	 * @see http://php.net/manual/en/function.session-abort.php
	 */
	public function abort() -> boolean
	{
		return session_abort();
	}

	/**
	 * Update the current session id with a newly generated one.
	 * Returns NEW session ID on success or FALSE on failure.
	 * @see http://php.net/manual/en/function.session-regenerate-id.php
	 */
	public function regenerateId(bool! deleteSession = false) -> string|boolean
	{
		if session_regenerate_id(deleteSession) {
			return this->getId();
		} else {
			return false;
		}
	}

	/**
	 * Alias: Gets a session variable from an application context
	 */
	public function __get(string! index) -> var
	{
		return this->get(index);
	}

	/**
	 * Alias: Sets a session variable in an application context
	 */
	public function __set(string! index, var value) -> void
	{
		this->set(index, value);
	}

	/**
	 * Alias: Check whether a session variable is set in an application context
	 */
	public function __isset(string! index) -> boolean
	{
		return this->has(index);
	}

	/**
	 * Alias: Removes a session variable from an application context
	 */
	public function __unset(string! index) -> void
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
}
