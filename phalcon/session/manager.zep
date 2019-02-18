
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Session;

use InvalidArgumentException;
use RuntimeException;
use SessionHandlerInterface;
use Phalcon\DiInterface;
use Phalcon\DI\InjectionAwareInterface;
use Phalcon\Helper\Arr;
use Phalcon\Session\ManagerInterface;

/**
 * Phalcon\Session\Manager
 *
 * Session manager class
 */
class Manager implements ManagerInterface, InjectionAwareInterface
{
    /**
     * @var <DiInterface>
     */
    private container;

	/**
	 * @var <SessionHandlerInterface>|null
	 */
	private handler = null;

	/**
	 * @var string
	 */
	private name = "";

	/**
	 * @var array
	 */
	private options = [];

	/**
	 * @var string
	 */
	private uniqueId = "";

	/**
	 * Manager constructor.
	 *
	 * @param array options
	 */
	public function __construct(array options = [])
	{
		this->setOptions(options);
	}


	/**
	 * Alias: Gets a session variable from an application context
	 */
	public function __get(string key) -> var
	{
		return this->get(key);
	}

	/**
	 * Alias: Check whether a session variable is set in an application context
	 */
	public function __isset(string key) -> bool
	{
		return this->has(key);
	}

	/**
	 * Alias: Sets a session variable in an application context
	 */
	public function __set(string key, value) -> void
	{
		this->set(key, value);
	}

	/**
	 * Alias: Removes a session variable from an application context
	 */
	public function __unset(string key)
	{
		this->remove(key);
	}

	/**
	 * Destroy/end a session
	 */
	public function destroy() -> void
	{
		if (true === this->exists()) {
			session_destroy();
			let _SESSION = [];
		}
	}

	/**
	 * Check whether the session has been started
	 */
	public function exists() -> bool
	{
		if (session_status() === self::SESSION_ACTIVE) {
			return true;
		}

		return false;
	}

	/**
	 * Gets a session variable from an application context
	 */
	public function get(string key, var defaultValue = null, bool remove = false) -> var
	{
	    var uniqueKey, value = null;

		if (false === this->exists()) {
			// To use $_SESSION variable we need to start session first
			return value;
		}

		let uniqueKey = this->getUniqueKey(key),
			value     = Arr::get(_SESSION, uniqueKey, defaultValue);

		if (remove === true) {
			unset(_SESSION[uniqueKey]);
		}

		return value;
	}

	/**
	 * Returns the DependencyInjector container
	 */
	public function getDI() -> <DiInterface>
	{
		return this->container;
	}

	/**
	 * Returns the stored session handler
	 */
	public function getHandler() -> <SessionHandlerInterface>
	{
		return this->handler;
	}

	/**
	 * Returns the session id
	 */
	public function getId() -> string
	{
		return session_id();
	}

	/**
	 * Returns the name of the session
	 */
	public function getName() -> string
	{
		if ("" !== this->name) {
			let this->name = session_name();
		}

		return this->name;
	}

	/**
	 * Check whether a session variable is set in an application context
	 */
	public function has(string key) -> bool
	{
		var uniqueKey;

		if (false === this->exists()) {
			// To use $_SESSION variable we need to start session first
			return false;
		}

		let uniqueKey = this->getUniqueKey(key);

		return isset(_SESSION[uniqueKey]);
	}

	/**
	 * Get internal options
	 */
	public function getOptions() -> array
	{
		return this->options;
	}

	/**
	 * Regenerates the session id using the handler.
	 */
	public function regenerateId(deleteOldSession = true) -> <ManagerInterface>
	{
	    var delete;

	    let delete = (bool) deleteOldSession;

		if (true === this->exists()) {
			session_regenerate_id(delete);
		}

		return this;
	}

	/**
	 * Registers a handler with the session
	 */
	public function registerHandler(<SessionHandlerInterface> handler) -> bool
	{
		return session_set_save_handler(handler);
	}

	/**
	 * Removes a session variable from an application context
	 */
	public function remove(string key)
	{
		if (false === this->exists()) {
			// To use $_SESSION variable we need to start session first
			return;
		}

		var uniqueKey;

		let uniqueKey = this->getUniqueKey(key);

		unset(_SESSION[uniqueKey]);
	}

	/**
	 * Sets a session variable in an application context
	 */
	public function set(string key, value) -> void
	{
		var uniqueKey;

		if (false === this->exists()) {
			// To use $_SESSION variable we need to start session first
			return;
		}

		 let uniqueKey          = this->getUniqueKey(key),
		    _SESSION[uniqueKey] = value;
	}

	/**
	 * Sets the DependencyInjector container
	 */
	public function setDI(<DiInterface> container)
	{
		let this->container = container;
	}

    /**
	 * Set the handler for the session
	 */
	public function setHandler(<SessionHandlerInterface> handler) -> <ManagerInterface>
	{
		let this->handler = handler;

		return this;
	}

	/**
	 * Set session Id
	 */
	public function setId(string id) -> <ManagerInterface>
	{
		if (true === this->exists()) {
			throw new RuntimeException(
				"The session has already been started. " .
				"To change the id, use regenerateId()"
			);
		}

		session_id(id);

		return this;
	}

	/**
	 * Set the session name. Throw exception if the session has started
	 * and do not allow poop names
	 *
	 * @param  string name
	 *
	 * @throws InvalidArgumentException
	 *
	 * @return Manager
	 */
	public function setName(string name) -> <ManagerInterface>
	{
		if (this->exists()) {
			throw new InvalidArgumentException(
				"Cannot set session name after a session has started"
			);
		}

		if !preg_match("/^[\p{L}\p{N}_-]+$/u", name) {
			throw new InvalidArgumentException(
				"The name contains non alphanum characters"
			);
		}

		let this->name = name;
		session_name(name);

		return this;
	}

	/**
	 * Sets session's options
	 *
	 * @param array options
	 */
	public function setOptions(array options) -> void
	{
		let this->uniqueId = Arr::get(options, "uniqueId", ""),
		    this->options  = options;
	}

	/**
	 * Starts the session (if headers are already sent the session will not be
	 * started)
	 */
	public function start() -> bool
	{
		/**
		 * Check if the session exists
		 */
		if (true === this->exists()) {
			return true;
		}

		/**
		 * Cannot start this - headers already sent
		 */
		if (true === headers_sent()) {
			return false;
		}

		/**
		 * Register the handler
		 */
		if (this->handler instanceof SessionHandlerInterface) {
			this->registerHandler(this->handler);
		} else {
		    throw new Exception("The session handler is not valid");
		}

		/**
		 * Start the session
		 */
		session_start();

		return true;
	}

	/**
	 * Returns the status of the current session.
	 *
	 * @return int
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
	 * Returns the key prefixed
	 */
	private function getUniqueKey(string key) -> string
	{
		return this->uniqueId . "#" . key;
	}
}
