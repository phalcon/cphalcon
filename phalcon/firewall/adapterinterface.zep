
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2016 Phalcon Team (http://www.phalconphp.com)       |
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
 |          Wojciech Ślawski <jurigag@gmail.com>                          |
 +------------------------------------------------------------------------+
 */


namespace Phalcon\Firewall;

use Phalcon\Mvc\DispatcherInterface;

/**
 * Phalcon\Mvc\Dispatcher\Firewall\AdapterInterface
 *
 * Interface for Phalcon\Mvc\Dispatcher\Firewall adapters
 */
interface AdapterInterface
{
	/**
	 * Sets the default access level (Phalcon\Acl::ALLOW or Phalcon\Acl::DENY)
	 */
	public function setDefaultAccess(int defaultAccess);

	/**
	 * Returns the default ACL access level
	 */
	public function getDefaultAccess() -> int;

	/**
	 * Sets role callback to fetch role name
	 */
	public function setRoleCallback(var callback);

	/**
	 * Gets role callback to fetch role name
	 */
	public function getRoleCallback();

	/**
	 * Gets dispatcher
	 */
	public function getDispatcher() -> <DispatcherInterface>;

	/**
	* Saves access in cache and internal cache
	*/
	protected function saveAccessInCache(string! key, boolean access) -> void;

	/**
	 * Gets access from cache
	 */
	protected function getAccessFromCache(string! key, array originalValues = null) -> boolean|null;

	/**
	 * Gets access from internal cache
	 */
	protected function getAccessFromInternalCache(string! key) -> boolean|null;

	/**
	 * Gets bound models key map
	 */
	protected function getBoundModelsKeyMap() -> array;

	/**
	 * Sets bound models key map
	 */
	protected function setBoundModelsKeyMap(array! boundModelsKeyMap) -> this;
}
