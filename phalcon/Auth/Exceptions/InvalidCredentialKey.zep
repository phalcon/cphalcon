/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Auth\Exceptions;

use Phalcon\Auth\Exception;

/**
 * A credential key is not a plain identifier and cannot be used as a query
 * column
 */
class InvalidCredentialKey extends Exception
{
    public function __construct(string key)
    {
        parent::__construct(
            "Credential key '" . key . "' is not a valid identifier"
        );
    }
}
