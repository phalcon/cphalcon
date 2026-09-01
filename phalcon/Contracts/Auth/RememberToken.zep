
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
 * A persisted remember-me token row.
 */
interface RememberToken
{
    /**
     * Deletes the token from storage.
     *
     * @return bool
     */
    public function delete() -> bool;

    /**
     * Returns the token value stored for this remember entry.
     *
     * @return string
     */
    public function getToken() -> string;

    /**
     * Returns the user agent associated with this token, if any.
     *
     * @return string|null
     */
    public function getUserAgent() -> string | null;
}
