
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

namespace Phalcon\Contracts\Auth\Guard;

use Phalcon\Contracts\Auth\Adapter\Adapter;
use Phalcon\Contracts\Auth\AuthUser;
use Phalcon\Contracts\Container\Service\Collection;

/**
 * @phpstan-import-type AuthCredentials from Adapter
 */
interface Guard
{
    /**
     * Build a guard from an adapter, the application container, and a flat
     * options map. Used by ManagerFactory to wire guards from the
     * application config; each implementation resolves the framework
     * services it needs from the container.
     *
     * @param array<string, mixed> $options
     */
    public static function fromOptions(
        <Adapter> adapter,
        <Collection> container,
        array options
    ) -> <static>;

    /**
     * Whether the current request is authenticated.
     */
    public function check() -> bool;

    /**
     * Returns the last user the guard tried to authenticate during this
     * request, regardless of success.
     */
    public function getLastUserAttempted() -> <AuthUser> | null;

    /**
     * Whether the current request is unauthenticated.
     */
    public function guest() -> bool;

    /**
     * Whether the guard currently holds a resolved user.
     */
    public function hasUser() -> bool;

    /**
     * Returns the authenticated user's identifier, or null when no
     * authenticated user is present.
     */
    public function id() -> int | string | null;

    /**
     * Sets the current user explicitly. Returns $this for fluent chaining.
     */
    public function setUser(<AuthUser> user) -> <static>;

    /**
     * Returns the resolved user for the current request, or null.
     */
    public function user() -> <AuthUser> | null;

    /**
     * Validates the given credentials without logging in.
     *
     * @phpstan-param AuthCredentials $credentials
     */
    public function validate(array credentials = []) -> bool;
}
