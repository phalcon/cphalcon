
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Firewall;

use Phalcon\Mvc\DispatcherInterface;
use Phalcon\Cache\Adapter\AdapterInterface as CacheAdapterInterface;

/**
 * Phalcon\Mvc\Dispatcher\Firewall\AdapterInterface
 *
 * Interface for Phalcon\Mvc\Dispatcher\Firewall adapters
 */
interface AdapterInterface
{
	/**
	 * Returns the default ACL access level
	 */
	public function getDefaultAccess() -> int;

	/**
	 * Gets role callback to fetch role name
	 */
	public function getRoleCallback();

	/**
	 * Gets always resolving role option
	 */
	public function isAlwaysResolvingRole() -> bool;

	/**
	 * Sets always resolving role option
	 */
	public function setAlwaysResolvingRole(bool alwaysResolvingRole) -> bool

	/**
	 * Sets cache backend
	 */
	public function setCache(<CacheAdapterInterface> cache) -> <AdapterInterface>;

	/**
	 * Sets the default access level (Phalcon\Acl::ALLOW or Phalcon\Acl::DENY)
	 */
	public function setDefaultAccess(int defaultAccess) -> <AdapterInterface>;

	/**
	 * Sets role callback to fetch role name
	 */
	public function setRoleCallback(var callback) -> <AdapterInterface>;
}
