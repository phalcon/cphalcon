
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Contracts\Encryption\Security;

interface CsrfProtection
{
    public function getToken() -> string | null;

    public function getTokenKey() -> string | null;

    public function checkToken(
        string tokenKey = null,
        var tokenValue = null,
        bool destroyIfValid = true
    ) -> bool;

    public function destroyToken() -> <Security>;

    public function getRequestToken() -> string | null;

    public function getSessionToken() -> string | null;
}
