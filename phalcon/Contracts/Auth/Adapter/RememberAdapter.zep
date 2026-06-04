
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

namespace Phalcon\Contracts\Auth\Adapter;

use Phalcon\Contracts\Auth\AuthUser;
use Phalcon\Contracts\Auth\RememberToken;

/**
 * Capability extension implemented by adapters that support remember-me.
 */
interface RememberAdapter extends Adapter
{
    /**
     * Create and persist a new remember token for the user.
     */
    public function createRememberToken(<AuthUser> user) -> <RememberToken>;

    /**
     * Retrieve a user by the remember-me cookie payload.
     */
    public function retrieveByToken(
        var id,
        string token,
        string userAgent = null
    ) -> <AuthUser> | null;
}
