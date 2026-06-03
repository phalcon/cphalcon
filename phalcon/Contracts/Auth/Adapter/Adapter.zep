
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
use Phalcon\Contracts\Encryption\Security\Security;

/**
 * Authentication adapter contract.
 *
 * Adapters look users up by credentials or by identifier and verify the
 * password against the stored hash. The credential payload is intentionally
 * unsealed: any user-row field may be used as the lookup key, plus an
 * optional `password` entry that is ignored during the row match and
 * consumed only by validateCredentials().
 *
 * @phpstan-type AuthCredentials array<string, mixed>
 */
interface Adapter
{
    /**
     * Build an adapter from a flat options map. Used by ManagerFactory to
     * wire adapters from the application config; each implementation is
     * free to interpret the option keys it cares about.
     *
     * @param array<string, mixed> $options
     */
    public static function fromOptions(<Security> hasher, array options) -> <static>;

    /**
     * Find a user matching the given credentials (e.g. ['email' => 'a@b']).
     * The 'password' key, if present, is ignored during the lookup.
     * Returns null if no user matches.
     *
     * @phpstan-param AuthCredentials $credentials
     */
    public function retrieveByCredentials(array credentials) -> <AuthUser> | null;

    /**
     * Find a user by their unique identifier.
     */
    public function retrieveById(var id) -> <AuthUser> | null;

    /**
     * Validate the provided credentials against the given user.
     * Implementations typically verify the password hash held under the
     * 'password' key.
     *
     * @phpstan-param AuthCredentials $credentials
     */
    public function validateCredentials(<AuthUser> user, array credentials) -> bool;
}
