
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Security\JWT\Token;

/**
 * Class Token
 *
 * @property Item      $claims
 * @property Item      $headers
 * @property Signature $signature
 *
 * @link https://tools.ietf.org/html/rfc7519
 */
class Token
{
    /**
     * @var Item
     */
    private claims { get };

    /**
     * @var Item
     */
    private headers { get };

    /**
     * @var Signature
     */
    private signature { get };

    /**
     * Token constructor.
     *
     * @param Item      $headers
     * @param Item      $claims
     * @param Signature $signature
     */
    public function __construct(
        <Item> headers,
        <Item> claims,
        <Signature> signature
    ) {
        let this->headers   = headers,
            this->claims    = claims,
            this->signature = signature;
    }

    /**
     * @return string
     */
    public function getPayload() -> string
    {
        return this->headers->getEncoded() . "." . this->claims->getEncoded();
    }

    /**
     * @return string
     */
    public function getToken() -> string
    {
        return this->getPayload() . "." . this->getSignature()->getEncoded();
    }
}
