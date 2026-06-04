
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

/**
 * Implemented by authenticatable models that support remember-me tokens.
 * This is intentionally separate from AuthUser so that adapters which do
 * not support remember-me are not forced to implement it.
 */
interface AuthRemember
{
    /**
     * Persists a new remember token for the user.
     *
     * @param string      $token
     * @param string|null $userAgent
     *
     * @return RememberToken
     */
    public function createRememberToken(
        string token,
        string userAgent = null
    ) -> <RememberToken>;

    /**
     * Returns the remember token entry matching the given token value,
     * or null if not found.
     *
     * @param string $token
     *
     * @return RememberToken|null
     */
    public function getRememberToken(string token) -> <RememberToken> | null;
}
