
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Auth\Access;

use Phalcon\Acl\Adapter\AdapterInterface;
use Phalcon\Acl\RoleAwareInterface;
use Phalcon\Auth\Exception;
use Phalcon\Contracts\Auth\Access\Access;
use Phalcon\Contracts\Auth\AuthUser;
use Phalcon\Contracts\Auth\Guard\Guard;

/**
 * ACL-backed access gate. Checks the authenticated user's role against a
 * Phalcon\Acl adapter: the ACL component is taken from the 'handler' context
 * key (prefixed with 'module' and the module separator when present) and the
 * ACL access is the action name. The 'params' context key is passed through
 * to the ACL adapter for callable rules.
 *
 * Filter semantics differ from the binary gates: except = bypass the gate
 * for the listed actions; only = the gate applies to the listed actions
 * exclusively (everything else is allowed).
 *
 * Role resolution: no user resolves to the configured guest role; a user
 * implementing Phalcon\Acl\RoleAwareInterface supplies its role name; any
 * other user is rejected with an exception.
 *
 * @phpstan-import-type AccessContext from Access
 */
class Acl extends AbstractAccess
{
    /**
     * @var AdapterInterface
     */
    protected acl;

    /**
     * @var string
     */
    protected guestRole = "guest";

    /**
     * @var string
     */
    protected moduleSeparator = ":";

    /**
     * @phpstan-param array{guestRole?: string, moduleSeparator?: string} $options
     */
    public function __construct(<AdapterInterface> acl, array options = [])
    {
        var value;

        let this->acl = acl;

        if (fetch value, options["guestRole"]) {
            let this->guestRole = (string) value;
        }

        if (fetch value, options["moduleSeparator"]) {
            let this->moduleSeparator = (string) value;
        }
    }

    /**
     * @phpstan-param AccessContext $context
     *
     * @throws Exception
     */
    public function isAllowed(<Guard> guard, string actionName, array context = []) -> bool
    {
        var component, handler, module, params;

        if (in_array(actionName, this->exceptActions, true)) {
            return true;
        }

        if (!empty(this->onlyActions) && !in_array(actionName, this->onlyActions, true)) {
            return true;
        }

        fetch handler, context["handler"];
        if (typeof handler !== "string" || handler === "") {
            throw new Exception(
                "The Acl access gate requires the 'handler' context key to determine the ACL component"
            );
        }

        let component = handler;

        fetch module, context["module"];
        if (typeof module === "string" && module !== "") {
            let component = module . this->moduleSeparator . handler;
        }

        let params = null;

        fetch params, context["params"];
        if (typeof params !== "array") {
            let params = null;
        }

        return this->acl->isAllowed(
            this->resolveRole(guard),
            component,
            actionName,
            params
        );
    }

    /**
     * Unused: this gate overrides isAllowed() in full. Fail closed to
     * satisfy the abstract.
     */
    protected function allowedIf(<Guard> guard) -> bool
    {
        return false;
    }

    /**
     * @throws Exception
     */
    protected function resolveRole(<Guard> guard) -> string
    {
        var user;

        let user = guard->user();

        if (user === null) {
            return this->guestRole;
        }

        if (user instanceof RoleAwareInterface) {
            return user->getRoleName();
        }

        throw new Exception(
            "The authenticated user must implement Phalcon\\Acl\\RoleAwareInterface to be used with the Acl access gate"
        );
    }
}
