
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

namespace Phalcon\Session;

/**
 * Phalcon\Session\Adapter
 *
 * Base class for Phalcon\Session adapters
 */
abstract class Adapter
{

	protected _uniqueId;

	protected _started = false;

	protected _options;

	/**
	 * Phalcon\Session\Adapter constructor
	 *
	 * @param array options
	 */
	public function __construct(options=null)
	{
		if typeof options == "array" {
			this->setOptions(options);
		}
	}

	/**
	 * Starts the session (if headers are already sent the session will not be started)
	 *
	 * @return boolean
	 */
	public function start()
	{
		if headers_sent() {
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
	public function setOptions(options)
	{
		var uniqueId;

		if typeof options != "array" {
			throw new Phalcon\Session\Exception("Options must be an Array");
		}

		if fetch uniqueId, options["uniqueId"] {
			let this->_uniqueId = uniqueId;
		}

		let this->_options = options;
	}

	/**
	 * Get internal options
	 *
	 * @return array
	 */
	public function getOptions()
	{
		return this->_options;
	}

	/**
	 * Gets a session variable from an application context
	 *
	 * @param string index
	 * @param mixed defaultValue
	 * @return mixed
	 */
	public function get(index, defaultValue=null)
	{
		var value;
		if fetch value, _SESSION[this->_uniqueId . index] {
			if !is_empty(value) {
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
	 *
	 * @param string index
	 * @param string value
	 */
	public function set(index, value)
	{
		let _SESSION[this->_uniqueId . index] = value;
	}

	/**
	 * Check whether a session variable is set in an application context
	 *
	 *<code>
	 *	var_dump(session->has('auth'));
	 *</code>
	 *
	 * @param string index
	 * @return boolean
	 */
	public function has(index)
	{
		if isset _SESSION[this->_uniqueId . index] {
			return true;
		}
		return false;
	}

	/**
	 * Removes a session variable from an application context
	 *
	 *<code>
	 *	session->remove('auth');
	 *</code>
	 *
	 * @param string index
	 */
	public function remove(index)
	{
		unset _SESSION[this->_uniqueId . index];
	}

	/**
	 * Returns active session id
	 *
	 *<code>
	 *	echo session->getId();
	 *</code>
	 *
	 * @return string
	 */
	public function getId()
	{
		return session_id();
	}

	/**
	 * Check whether the session has been started
	 *
	 *<code>
	 *	var_dump(session->isStarted());
	 *</code>
	 *
	 * @return boolean
	 */
	public function isStarted()
	{
		return this->_started;
	}

	/**
	 * Destroys the active session
	 *
	 *<code>
	 *	var_dump(session->destroy());
	 *</code>
	 *
	 * @return boolean
	 */
	public function destroy()
	{
		var destroyed;
		let destroyed = session_destroy(),
			this->_started = false;
		return destroyed;
	}

}
