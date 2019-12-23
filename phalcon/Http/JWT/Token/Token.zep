
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
 * Class Token
 *
 * @property Item      $claims
 * @property Item      $jose
 * @property Signature $signature
 *
 * @link https://tools.ietf.org/html/rfc7519
 */
class Token
{
    /**
     * @var Item
     */
    private claims;

    /**
     * @var Item
     */
    private jose;

    /**
     * @var Signature
     */
    private signature;

    /**
     * Token constructor.
     *
     * @param Item      $jose
     * @param Item      $claims
     * @param Signature $signature
     */
    public function __construct(
        <Item> jose,
        <Item> claims,
        <Signature> signature
    ) {
        let this->jose      = jose,
            this->claims    = claims,
            this->signature = signature;
    }

    /**
     * @return Item
     */
    public function getClaims() -> <Item>
    {
        return this->claims;
    }

    /**
     * @return Item
     */
    public function getHeaders() -> <Item>
    {
        return this->jose;
    }

    /**
     * @return string
     */
    public function getPayload() -> string
    {
        return this->jose->getEncoded() . "." . this->claims->getEncoded();
    }

    /**
     * @return string
     */
    public function getSignature() -> string
    {
        return this->signature->getEncoded();
    }

    /**
     * @return string
     */
    public function getToken() -> string
    {
        return this->getPayload() . "." . this->getSignature();
    }
}
