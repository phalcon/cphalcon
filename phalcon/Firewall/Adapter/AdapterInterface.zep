
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Firewall\Adapter;

use Phalcon\Mvc\DispatcherInterface;
use Phalcon\Cache\Adapter\AdapterInterface as CacheAdapterInterface;

/**
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
    public function setAlwaysResolvingRole(bool alwaysResolvingRole) -> void;

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
