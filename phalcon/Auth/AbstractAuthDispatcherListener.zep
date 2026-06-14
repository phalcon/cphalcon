
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by sinbadxiii/cphalcon-auth
 * @link    https://github.com/sinbadxiii/cphalcon-auth
 */

namespace Phalcon\Auth;

use Phalcon\Auth\Exceptions\AccessDenied;
use Phalcon\Contracts\Auth\Access\Access;
use Phalcon\Contracts\Auth\Manager;

/**
 * Shared enforcement algorithm for the Cli, Mvc and Micro auth listeners.
 * The subclass provides the action name and context from its event source,
 * the action-kind label used in the access-denied exception, and (Mvc only)
 * a forward handler for Access::redirectTo().
 *
 * Enforcement is fail-open: when the manager has no active access
 * (Manager::getAccess() === null) every dispatch is allowed. A policy
 * activated via Manager::access() persists across forwards and nested
 * dispatches in the same request until it is replaced.
 *
 * @phpstan-import-type AccessContext from Access
 */
abstract class AbstractAuthDispatcherListener
{
    /**
     * @var Manager
     */
    protected manager;

    public function __construct(<Manager> manager)
    {
        let this->manager = manager;
    }

    /**
     * Returns the kind label used by AccessDenied (e.g. 'task', 'action',
     * 'route').
     */
    abstract protected function getActionType() -> string;

    /**
     * Runs the access check for the given action name. Returns true when
     * the dispatch should proceed, false when a forward was issued, and
     * throws when access is denied without a redirect target.
     *
     * The guard is fetched only when an access is active, so the no-op
     * path works without a default guard.
     *
     * @phpstan-param AccessContext $context
     * @phpstan-param callable|null $forwardHandler
     *
     * @throws Exception
     */
    protected function enforce(
        string actionName,
        array context = [],
        var forwardHandler = null
    ) -> bool {
        var access, target;

        let access = this->manager->getAccess();
        if (access === null) {
            return true;
        }

        if (access->isAllowed(this->manager->guard(), actionName, context)) {
            return true;
        }

        if (forwardHandler !== null) {
            let target = access->redirectTo();
            if (target !== null) {
                {forwardHandler}(target);

                return false;
            }
        }

        throw new AccessDenied(this->getActionType(), actionName);
    }
}
