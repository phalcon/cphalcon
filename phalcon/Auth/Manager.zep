
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

use Phalcon\Auth\Access\AccessLocator;
use Phalcon\Contracts\Auth\Access\Access;
use Phalcon\Contracts\Auth\Adapter\Adapter;
use Phalcon\Contracts\Auth\AuthUser;
use Phalcon\Contracts\Auth\Guard\Guard;
use Phalcon\Contracts\Auth\Guard\GuardStateful;
use Phalcon\Contracts\Auth\Manager as ManagerContract;

/**
 * Composes guards (authentication) and access gates (authorization)
 * behind a single facade. Guard-specific behavior is reached through
 * Manager::guard(); callers narrow with instanceof against the
 * relevant capability interface (GuardStateful, BasicAuth, etc.).
 *
 * @phpstan-import-type AuthCredentials from Adapter
 */
class Manager implements ManagerContract
{
    /**
     * @var AccessLocator
     */
    protected accessFactory;
    /**
     * @var Access | null
     */
    protected activeAccess = null;
    /**
     * @var Guard | null
     */
    protected defaultGuard = null;

    /**
     * @var array<string, Guard>
     */
    protected guards = [];

    public function __construct(<AccessLocator> accessFactory)
    {
        let this->accessFactory = accessFactory;
    }

    /**
     * @throws Exception
     */
    public function access(string accessName) -> <self>
    {
        var className;

        if (!this->accessFactory->has(accessName)) {
            throw new Exception(
                sprintf("Access '%s' is not registered", accessName)
            );
        }

        let className          = this->accessFactory->getClass(accessName);
        let this->activeAccess = new {className}(this);

        return this;
    }

    /**
     * @param array<string, class-string<Access>> $accessList
     */
    public function addAccessList(array accessList) -> <self>
    {
        var className, name;

        for name, className in accessList {
            this->accessFactory->register(name, className);
        }

        return this;
    }

    public function addGuard(
        string nameGuard,
        <Guard> guard,
        bool isDefault = false
    ) -> <self> {
        let this->guards[nameGuard] = guard;

        if (isDefault) {
            let this->defaultGuard = guard;
        }

        return this;
    }

    /**
     * @phpstan-param AuthCredentials $credentials
     *
     * @throws Exception
     */
    public function attempt(array credentials = [], bool remember = false) -> bool
    {
        var guard;

        let guard = this->guard();

        if (!guard instanceof GuardStateful) {
            throw new Exception("Default guard does not implement GuardStateful");
        }

        return guard->attempt(credentials, remember);
    }

    public function check() -> bool
    {
        return this->guard()->check();
    }

    /**
     * @throws Exception
     */
    public function except(string ...actions) -> <self>
    {
        if (this->activeAccess === null) {
            throw new Exception("No active access — call access() first");
        }

        this->activeAccess->setExceptActions(array_values(actions));

        return this;
    }

    public function getAccess() -> <Access> | null
    {
        return this->activeAccess;
    }

    /**
     * @return array<string, class-string<Access>>
     */
    public function getAccessList() -> array
    {
        return this->accessFactory->getAll();
    }

    public function getDefaultGuard() -> <Guard> | null
    {
        return this->defaultGuard;
    }

    /**
     * @return array<string, Guard>
     */
    public function getGuards() -> array
    {
        return this->guards;
    }

    /**
     * @throws Exception
     */
    public function guard(string name = null) -> <Guard>
    {
        if (name === null) {
            if (this->defaultGuard === null) {
                throw new Exception("No default guard registered");
            }

            return this->defaultGuard;
        }

        if (!isset(this->guards[name])) {
            throw new Exception(
                sprintf("Auth guard '%s' is not defined", name)
            );
        }

        return this->guards[name];
    }

    public function id() -> int | string | null
    {
        return this->guard()->id();
    }

    public function logout() -> void
    {
        var guard;

        let guard = this->guard();

        if (!guard instanceof GuardStateful) {
            throw new Exception("Default guard does not implement GuardStateful");
        }

        guard->logout();
    }

    /**
     * @throws Exception
     */
    public function only(string ...actions) -> <self>
    {
        if (this->activeAccess === null) {
            throw new Exception("No active access — call access() first");
        }

        this->activeAccess->setOnlyActions(array_values(actions));

        return this;
    }

    public function setAccess(<Access> access) -> <self>
    {
        let this->activeAccess = access;

        return this;
    }

    public function setDefaultGuard(<Guard> guard) -> <self>
    {
        let this->defaultGuard = guard;

        return this;
    }

    public function user() -> <AuthUser> | null
    {
        return this->guard()->user();
    }

    /**
     * @phpstan-param AuthCredentials $credentials
     */
    public function validate(array credentials = []) -> bool
    {
        return this->guard()->validate(credentials);
    }
}
