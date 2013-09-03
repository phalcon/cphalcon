
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
 * Phalcon\Session\AdapterInterface
 *
 * Interface for Phalcon\Session adapters
 */
interface AdapterInterface
{

	/**
	 * Phalcon\Session construtor
	 *
	 * @param array options
	 */
	public function __construct(options=null);

	/**
	 * Starts session, optionally using an adapter
	 *
	 * @param array options
	 */
	public function start();

	/**
	 * Sets session options
	 *
	 * @param array options
	 */
	public function setOptions(options);

	/**
	 * Get internal options
	 *
	 * @return array
	 */
	public function getOptions();

	/**
	 * Gets a session variable from an application context
	 *
	 * @param string index
	 * @param mixed defaultValue
	 * @return mixed
	 */
	public function get(index, defaultValue=null);

	/**
	 * Sets a session variable in an application context
	 *
	 * @param string index
	 * @param string value
	 */
	public function set(index, value);

	/**
	 * Check whether a session variable is set in an application context
	 *
	 * @param string index
	 * @return boolean
	 */
	public function has(index);

	/**
	 * Removes a session variable from an application context
	 *
	 * @param string index
	 */
	public function remove(index);

	/**
	 * Returns active session id
	 *
	 * @return string
	 */
	public function getId();

	/**
	 * Check whether the session has been started
	 *
	 * @return boolean
	 */
	public function isStarted();

	/**
	 * Destroys the active session
	 *
	 * @return boolean
	 */
	public function destroy();

}