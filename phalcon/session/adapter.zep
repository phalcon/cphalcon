/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Session;

/**
 * Phalcon\Session\Adapter
 *
 * Base class for Phalcon\Session adapters
 */
abstract class Adapter implements AdapterInterface
{
	const SESSION_ACTIVE = 2;

	const SESSION_DISABLED = 0;

	const SESSION_NONE = 1;

	protected _options;

	protected _started = false;

	protected _uniqueId;

	/**
	 * Phalcon\Session\Adapter constructor
	 */
	public function __construct(array options = [])
	{
		this->setOptions(options);
	}

	public function __destruct()
	{
		if this->_started {
			session_write_close();
			let this->_started = false;
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
	 * Alias: Check whether a session variable is set in an application context
	 */
	public function __isset(string index) -> bool
	{
		return this->has(index);
	}

	/**
	 * Alias: Sets a session variable in an application context
	 */
	public function __set(string index, var value)
	{
		return this->set(index, value);
	}

	/**
	 * Alias: Removes a session variable from an application context
	 *
	 * <code>
	 * unset($session->auth);
	 * </code>
	 */
	public function __unset(string index)
	{
		this->remove(index);
	}

	/**
	 * Destroys the active session
	 *
	 *<code>
	 * var_dump(
	 *     $session->destroy()
	 * );
	 *
	 * var_dump(
	 *     $session->destroy('some-id')
	 * );
	 *</code>
	 */
	public function destroy(string sessionId = null) -> bool
	 {
		this->removeSessionData();

		let this->_started = false;
		return session_destroy();
	}

	/**
	 * Gets a session variable from an application context
	 *
	 * <code>
	 * $session->get("auth", "yes");
	 * </code>
	 */
	public function get(string index, var defaultValue = null, bool remove = false) -> var
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
	 * Returns active session id
	 *
	 *<code>
	 * echo $session->getId();
	 *</code>
	 */
	public function getId() -> string
	{
		return session_id();
	}

	/**
	 * Get session name
	 */
	public function getName() -> string
	{
	    return session_name();
	}

	/**
	 * Get internal options
	 */
	public function getOptions() -> array
	{
		return this->_options;
	}

	/**
	 * Check whether a session variable is set in an application context
	 *
	 *<code>
	 * var_dump(
	 *     $session->has("auth")
	 * );
	 *</code>
	 */
	public function has(string index) -> bool
	{
		var uniqueId;

		let uniqueId = this->_uniqueId;
		if !empty uniqueId {
			return isset _SESSION[uniqueId . "#" . index];
		}

		return isset _SESSION[index];
	}

	/**
	 * Check whether the session has been started
	 *
	 *<code>
	 * var_dump(
	 *     $session->isStarted()
	 * );
	 *</code>
	 */
	public function isStarted() -> bool
	{
		return this->_started;
	}

	/**
	 * {@inheritdoc}
	 */
	public function regenerateId(bool deleteOldSession = true) -> <AdapterInterface>
	{
		session_regenerate_id(deleteOldSession);
		return this;
	}

	/**
	 * Removes a session variable from an application context
	 *
	 * <code>
	 * $session->remove("auth");
	 * </code>
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
	 * Sets a session variable in an application context
	 *
	 *<code>
	 * $session->set("auth", "yes");
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
	 * Set the current session id
	 *
	 *<code>
	 * $session->setId($id);
	 *</code>
	 */
	public function setId(string id)
	{
		session_id(id);
	}

	/**
	 * Set session name
	 */
	public function setName(string name)
	{
	    session_name(name);
	}

	/**
	 * Sets session's options
	 *
	 *<code>
	 * $session->setOptions(
	 *     [
	 *         "uniqueId" => "my-private-app",
	 *     ]
	 * );
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
	 * Starts the session (if headers are already sent the session will not be started)
	 */
	public function start() -> bool
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
	 * Returns the status of the current session.
	 *
	 *<code>
	 * var_dump(
	 *     $session->status()
	 * );
	 *
	 * if ($session->status() !== $session::SESSION_ACTIVE) {
	 *     $session->start();
	 * }
	 *</code>
	 */
	public function status() -> int
	{
		var status;

		let status = session_status();

		switch status {
			case PHP_SESSION_DISABLED:
				return self::SESSION_DISABLED;

			case PHP_SESSION_ACTIVE:
				return self::SESSION_ACTIVE;
		}

		return self::SESSION_NONE;
	}

	/**
	 * Helper method to remove session data
	 */
	protected function removeSessionData() -> void
	{
		var uniqueId, key;

		let uniqueId = this->_uniqueId;

		if empty _SESSION {
			return;
		}

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
}
