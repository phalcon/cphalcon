
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

use Phalcon\Contracts\Auth\AuthUser;

interface BasicAuth
{
    /**
     * Authenticate against HTTP Basic credentials. Returns true on success.
     *
     * @param array<string, mixed> $extraConditions credentials merged on top of
     *                                              the basic-auth pair
     */
    public function basic(string field = "email", array extraConditions = []) -> bool;

    /**
     * Like basic() but does not persist; returns the resolved user on success
     * or false on failure.
     *
     * @param array<string, mixed> $extraConditions
     */
    public function onceBasic(string field = "email", array extraConditions = []) -> false | <AuthUser>;
}
