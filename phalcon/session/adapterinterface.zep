
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
 * Phalcon\Session\AdapterInterface
 *
 * Interface for Phalcon\Session adapters
 */
interface AdapterInterface
{

	/**
	 * Starts session, optionally using an adapter
	 */
	public function start(boolean force = false) -> boolean;
	
	/**
	 * Gets the session cookie parameters
	 * @see http://php.net/manual/en/function.session-get-cookie-params.php
	 */
	public function getCookieParams() -> array;

	/**
	 * Sets the session cookie parameters
	 * @see http://php.net/manual/en/function.session-set-cookie-params.php
	 */
	public function setCookieParams(int! lifetime, string! path, string! domain, bool! secure = false, bool! httpOnly = false) -> void;

	/**
	 * Sets session options
	 */
	public function setOptions(array! options) -> void;

	/**
	 * Get internal options
	 */
	public function getOptions() -> array;

	/**
	 * Returns an option in the session's options
	 * Returns defaultValue if the option hasn't set
	 */
	public function getOption(string! key, var defaultValue = null) -> var;

	/**
	 * Gets a session variable from an application context
	 */
	public function get(string! index, var defaultValue = null) -> var;

	/**
	 * Sets a session variable in an application context
	 */
	public function set(string! index, var value) -> void;

	/**
	 * Check whether a session variable is set in an application context
	 */
	public function has(string! index) -> boolean;

	/**
	 * Removes a session variable from an application context
	 */
	public function remove(string! index) -> void;

	/**
	 * Returns active session id
	 */
	public function getId() -> string;

	/**
	 * Set the current session id
	 *
	 *<code>
	 *	$session->setId($id);
	 *</code>
	 */
	public function setId(string! id) -> void;

	/**
	 * Gets the current session name
	 * @see http://php.net/manual/en/function.session-name.php
	 */
	public function getName() -> string;

	/**
	 * Sets the current session name and return the old session name
	 * @see http://php.net/manual/en/function.session-name.php
	 */
	public function setName(string! name) -> string;

	/**
	 * Check whether the session has been started
	 */
	public function isStarted() -> boolean;

	/**
	 * Destroys the active session
	 */
	public function destroy() -> boolean;

	/**
	 * Re-initialize session array with original values
	 * @see http://php.net/manual/en/function.session-reset.php
	 */
	public function reset() -> boolean;

	/**
	 * Write session data and end session
	 * @see http://php.net/manual/en/function.session-write-close.php
	 */
	public function commit() -> void;

	/**
	 * Discard session array changes and finish session
	 * @see http://php.net/manual/en/function.session-abort.php
	 */
	public function abort() -> boolean;

	/**
	 * Update the current session id with a newly generated one.
	 * Returns NEW session ID on success or FALSE on failure.
	 * @see http://php.net/manual/en/function.session-regenerate-id.php
	 */
	public function regenerateId(bool! deleteSession = false) -> string|boolean;

	/**
	 * Returns the current session status (const: SESSION_DISABLED, SESSION_NONE, SESSION_ACTIVE)
	 * @see http://php.net/manual/en/function.session-status.php
	 */
	public function status() -> int;
	
	/**
	 * Clear all session variables
	 * @see http://php.net/manual/en/function.session-unset.php
	 */
	public function clear() -> void;

	/**
	 * Encodes the current session data as a session encoded string
	 * @see http://php.net/manual/en/function.session-encode.php
	 */
	public function encode() -> string;

	/**
	 * Decodes session data from a session encoded string
	 * @see http://php.net/manual/en/function.session-encode.php
	 */
	public function decode(string data) -> boolean;
}
