
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Encryption\Security\JWT\Token;

/**
 * Constants for Tokens. It offers constants for Headers as well as Claims
 *
 * @link https://tools.ietf.org/html/rfc7519
 */
class Enum
{
    /**
     * Headers
     *
     * @var string
     */
    const TYPE         = "typ";
    /**
     * @var string
     */
    const ALGO         = "alg";
    /**
     * @var string
     */
    const CONTENT_TYPE = "cty";

    /**
     * Claims
     *
     * @var string
     */
    const AUDIENCE        = "aud";
    /**
     * @var string
     */
    const EXPIRATION_TIME = "exp";
    /**
     * @var string
     */
    const ID              = "jti";
    /**
     * @var string
     */
    const ISSUED_AT       = "iat";
    /**
     * @var string
     */
    const ISSUER          = "iss";
    /**
     * @var string
     */
    const NOT_BEFORE      = "nbf";
    /**
     * @var string
     */
    const SUBJECT         = "sub";
}
