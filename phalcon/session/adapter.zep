
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
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Session;

/**
 * Phalcon\Session\Adapter
 *
 * Base class for Phalcon\Session adapters
 */
abstract class Adapter
{

	const SESSION_ACTIVE = 2;

	const SESSION_NONE = 1;

	const SESSION_DISABLED = 0;

	protected _uniqueId;

	protected _started = false;

	protected _options;

	/**
	 * Phalcon\Session\Adapter constructor
	 *
	 * @param array options
	 */
	public function __construct(options = null)
	{
		if typeof options == "array" {
			this->setOptions(options);
		}
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
	 * Gets a session variable from an application context
	 *
	 * @param string index
	 * @param mixed defaultValue
	 * @param boolean remove
	 * @return mixed
	 */
	public function get(string index, defaultValue = null, boolean remove = false)
	{
		var value, key;

		let key = this->_uniqueId . index;
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
	 *	session->set('auth', 'yes');
	 *</code>
	 *
	 * @param string index
	 * @param string value
	 */
	public function set(string index, value)
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
	public function has(string index) -> boolean
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
	public function remove(string index)
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
	public function setId(string id)
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
		return this->_started;
	}

	/**
	 * Destroys the active session
	 *
	 *<code>
	 *	var_dump($session->destroy());
	 *</code>
	 */
	public function destroy() -> boolean
	{
		let this->_started = false;
		return session_destroy();
	}

	/**
	 * Returns the status of the current session. For PHP 5.3 this function will always return SESSION_NONE
	 *
	 *<code>
	 *	var_dump($session->status());
	 *
	 *  // PHP 5.4 and above will give meaningful messages, 5.3 gets SESSION_NONE always
	 *  if ($session->status() !== $session::SESSION_ACTIVE) {
	 *      $session->start();
	 *  }
	 *</code>
	 */
	public function status() -> int
	{
		var status;

		if !is_php_version("5.3") {
			let status = session_status();

			switch status {
				case PHP_SESSION_DISABLED:
					return self::SESSION_DISABLED;

				case PHP_SESSION_ACTIVE:
					return self::SESSION_ACTIVE;
			}
		}

		return self::SESSION_NONE;
	}

	/**
	 * Alias: Gets a session variable from an application context
	 *
	 * @param string index
	 * @return mixed
	 */
	public function __get(string index)
	{
		return this->get(index);
	}

	/**
	 * Alias: Sets a session variable in an application context
	 *
	 * @param string index
	 * @param string value
	 */
	public function __set(string index, value)
	{
		return this->set(index, value);
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
	public function __unset(string index)
	{
		return this->remove(index);
	}
}
