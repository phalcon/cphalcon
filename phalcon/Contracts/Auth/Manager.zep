
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

namespace Phalcon\Contracts\Auth;

use Phalcon\Auth\Exception;
use Phalcon\Contracts\Auth\Access\Access;
use Phalcon\Contracts\Auth\Adapter\Adapter;
use Phalcon\Contracts\Auth\Guard\Guard;

/**
 * @phpstan-import-type AuthCredentials from Adapter
 */
interface Manager
{
    /**
     * Activates the named access gate for the current request and returns the
     * manager for fluent only()/except() configuration.
     *
     * Enforcement is opt-in and fail-open: when no access has been activated
     * (getAccess() returns null) every dispatch is allowed. An activated gate
     * stays active for subsequent dispatches in the same request (forwards,
     * nested handlers) until it is replaced. Under classic FPM this is scoped
     * to a single request; long-running runtimes must reset it per request.
     */
    public function access(string accessName) -> <self>;

    /**
     * @phpstan-param array<string, class-string<Access>> $accessList
     */
    public function addAccessList(array accessList) -> <self>;

    public function addGuard(string nameGuard, <Guard> guard, bool isDefault = false) -> <self>;

    /**
     * @phpstan-param AuthCredentials $credentials
     *
     * @throws Exception
     */
    public function attempt(array credentials = [], bool remember = false) -> bool;

    /**
     * Whether the default guard reports the current request as authenticated.
     */
    public function check() -> bool;

    /**
     * Restricts the active access gate to skip the listed action names.
     */
    public function except(string ...actions) -> <self>;

    /**
     * Returns the active access gate, or null when none has been activated -
     * in which case listener enforcement is a no-op (see access()).
     */
    public function getAccess() -> <Access> | null;

    /**
     * @phpstan-return array<string, class-string<Access>>
     */
    public function getAccessList() -> array;

    public function getDefaultGuard() -> <Guard> | null;

    /**
     * @return array<string, Guard>
     */
    public function getGuards() -> array;

    /**
     * Returns the named guard, or the default guard when $name is null.
     */
    public function guard(string name = null) -> <Guard>;

    /**
     * Returns the authenticated user's identifier from the default guard,
     * or null when no authenticated user is present.
     */
    public function id() -> int | string | null;

    /**
     * Logs the current user out via the default guard.
     *
     * @throws Exception
     */
    public function logout() -> void;

    /**
     * Restricts the active access gate to apply only to the listed action names.
     */
    public function only(string ...actions) -> <self>;

    public function setAccess(<Access> access) -> <self>;

    public function setDefaultGuard(<Guard> guard) -> <self>;

    /**
     * Returns the resolved user from the default guard, or null.
     */
    public function user() -> <AuthUser> | null;

    /**
     * Validates the given credentials against the default guard without
     * logging in.
     *
     * @phpstan-param AuthCredentials $credentials
     */
    public function validate(array credentials = []) -> bool;
}
