
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
 |          Jere Jones <jere.jones@gmail.com>                             |
 +------------------------------------------------------------------------+
 */

namespace Phalcon;

use Phalcon\Session\AdapterInterface;

/**
 * Phalcon\Session
 *
 * Session client-server persistent state data management. This component
 * allows you to separate your session data between application or modules.
 * With this, it's possible to use the same index to refer a variable
 * but it can be in different applications.
 *
 *<code>
 * $session = new \Phalcon\Session\(array(
 *    'adapter' => 'files',
 *    'uniqueId' => 'my-private-app'
 * ));
 *
 * $session->start();
 *
 * $session->set('var', 'some-value');
 *
 * echo $session->get('var');
 *</code>
 */
class Session
{
	protected _started = false;

	protected _regenerated = false;

	/**
	 * Adapter instance
	 */
	protected _adapter;

	/**
	 * Phalcon\Session constructor
	 *
	 * @param array options
	 */
	public function __construct(options = null)
	{
		var adapter;

		let adapter = "\\Phalcon\\Session\\Adapter\\Files";

		if typeof options == "array" && isset options["adapter"] {
			/**
			 * Adapter class can override the default files
			 */
			fetch adapter, options["adapter"];
		}

		/**
		 * Create the instance
		 */
		if typeof adapter == "string" {
			if strpos(adapter, "\\") !== 0 {
				let adapter = "\\Phalcon\\Session\\Adapter\\" . adapter;
			}
			let this->_adapter = new {adapter}(options);
		} elseif typeof adapter == "object" && adapter instanceof AdapterInterface {
			let this->_adapter = adapter;
		}
	}

	/**
	 * Starts the session (if headers are already sent the session will not be started)
	 *
	 * @return boolean
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
	 * Sets session's options
	 *
	 *<code>
	 *	session->setOptions(array(
	 *		'uniqueId' => 'my-private-app'
	 *	));
	 *</code>
	 *
	 * @param array options
	 */
	public function setOptions(array! options)
	{
		return this->_adapter->setOptions(options);
	}

	/**
	 * Get internal options
	 *
	 * @return array
	 */
	public function getOptions()
	{
		return this->_adapter->getOptions();
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
		return this->_adapter->get(index, defaultValue, remove);
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
		return this->_adapter->set(index, value);
	}

	/**
	 * Check whether a session variable is set in an application context
	 *
	 *<code>
	 *	var_dump($session->has('auth'));
	 *</code>
	 *
	 * @param string index
	 */
	public function has(string index) -> boolean
	{
		return this->_adapter->has(index);
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
		return this->_adapter->remove(index);
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
		return this->_adapter->getId();
	}

	/**
	 * Set the current session id
	 *
	 *<code>
	 *	$session->setId($id);
	 *</code>
	 *
	 * @param string id
	 */
	public function setId(string id)
	{
		return this->_adapter->setId(id);
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
		this->_adapter->destroy();
		return session_destroy();
	}

	/**
	 * Sets the adapter instance
	 */
	public function setAdapter(<AdapterInterface> adapter)
	{
		let this->_adapter = adapter;
	}

	/**
	 * Returns internal adapter instance
	 */
	public function getAdapter() -> <AdapterInterface>
	{
		return this->_adapter;
	}

	/**
	 * Regenerate the session id
	 *
	 * @return boolean
	 */
	public function regenerateId() -> boolean
	{
		if (this->_started) {
			session_regenerate_id(true);
			let this->_regenerated = true;
			return true;
		}
		return false;
	}

	/**
	 * Check whether the session id has been regenerate
	 *
	 *<code>
	 *	var_dump($session->isRegenerated());
	 *</code>
	 */
	public function isRegenerated() -> boolean
	{
		return this->_regenerated;
	}

	/**
	 * Alias: Gets a session variable from an application context
	 *
	 * @param string index
	 * @return mixed
	 */
	public function __get(string index)
	{
		return this->_adapter->get(index);
	}

	/**
	 * Alias: Sets a session variable in an application context
	 *
	 * @param string index
	 * @param string value
	 */
	public function __set(string index, value)
	{
		return this->_adapter->set(index, value);
	}

	/**
	 * Alias: Check whether a session variable is set in an application context
	 *
	 * @param string index
	 */
	public function __isset(string index) -> boolean
	{
		return this->_adapter->has(index);
	}

	/**
	 * Alias: Removes a session variable from an application context
	 */
	public function __unset(string index)
	{
		return this->_adapter->remove(index);
	}
}
