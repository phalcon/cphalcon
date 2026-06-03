
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

/**
 * Implemented by guards backed by persistent state (sessions/cookies).
 *
 * @phpstan-import-type AuthCredentials from Adapter
 */
interface GuardStateful
{
    /**
     * Attempts to authenticate the user with the given credentials and, on
     * success, persists the resulting state on the guard.
     *
     * @phpstan-param AuthCredentials $credentials
     */
    public function attempt(array credentials = [], bool remember = false) -> bool;

    public function login(<AuthUser> user, bool remember = false) -> void;

    /**
     * Logs in the user identified by $id. Returns the resolved user on
     * success or false when no user matches the id.
     */
    public function loginById(var id, bool remember = false) -> false | <AuthUser>;

    public function logout() -> void;

    public function viaRemember() -> bool;
}
