
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Http\JWT\Token;

/**
 * Class Enum
 *
 * @link https://tools.ietf.org/html/rfc7519
 */
class Enum
{
    /**
     * Headers
     */
    const TYPE         = "typ";
    const ALGO         = "alg";
    const CONTENT_TYPE = "cty";

    /**
     * Claims
     */
    const AUDIENCE        = "aud";
    const EXPIRATION_TIME = "exp";
    const ID              = "jti";
    const ISSUED_AT       = "iat";
    const ISSUER          = "iss";
    const NOT_BEFORE      = "nbf";
    const SUBJECT         = "sub";
}
