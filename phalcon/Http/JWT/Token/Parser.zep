
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Http\JWT\Token;

use InvalidArgumentException;
use Phalcon\Helper\Arr;
use Phalcon\Helper\Base64;
use Phalcon\Helper\Json;

/**
 * Class Parser
 */
class Parser
{
    /**
     * Parse a token and return it
     *
     * @param string $token
     *
     * @return Token
     */
    public function parse(string! token) -> <Token>
    {
        var claims, encodedClaims, encodedHeaders, encodedSignature,
            headers, results, signature;

        let results          = this->parseToken(token),
            encodedHeaders   = results[0],
            encodedClaims    = results[1],
            encodedSignature = results[2],
            headers          = this->decodeHeaders(encodedHeaders),
            claims           = this->decodeClaims(encodedClaims),
            signature        = this->decodeSignature(headers, encodedSignature);

        return new Token(headers, claims, signature);
    }

    /**
     * Decode the claims
     *
     * @param string $claims
     *
     * @return Item
     */
    private function decodeClaims(string claims) -> <Item>
    {
        var decoded;

        let decoded = Json::decode(Base64::decodeUrl(claims), true);

        if typeof decoded !== "array" {
            throw new InvalidArgumentException(
                "Invalid Claims (not an array)"
            );
        }

        /**
         * Just in case
         */
        if isset decoded[Enum::AUDIENCE] && typeof decoded[Enum::AUDIENCE] !== "array" {
            let decoded[Enum::AUDIENCE] = [decoded[Enum::AUDIENCE]];
        }

        return new Item(decoded, claims);
    }

    /**
     * Decodes the headers
     *
     * @param string $headers
     *
     * @return Item
     */
    private function decodeHeaders(string headers) -> <Item>
    {
        var decoded;

        let decoded = Json::decode(Base64::decodeUrl(headers), true);

        if typeof decoded !== "array" {
            throw new InvalidArgumentException(
                "Invalid Header (not an array)"
            );
        }

        if !isset decoded[Enum::TYPE] {
            throw new InvalidArgumentException(
                "Invalid Header (missing 'typ' element)"
            );
        }

        return new Item(decoded, headers);
    }

    /**
     * Decodes the signature
     *
     * @param Item   $headers
     * @param string $signature
     *
     * @return Signature
     */
    private function decodeSignature(<Item> headers, string signature) -> <Signature>
    {
        var algo, decoded;

        let algo = headers->get(Enum::ALGO, "none");

        if "none" === algo {
            let decoded   = "",
                signature = "";
        } else {
            let decoded = Base64::decodeUrl(signature);
        }

        return new Signature(decoded, signature);
    }

    /**
     * Splits the token to its three parts;
     *
     * @param string $token
     *
     * @return array
     */
    private function parseToken(string! token) -> array
    {
        var parts;

        let parts = explode(".", token);

        if count(parts) !== 3 {
            throw new InvalidArgumentException(
                "Invalid JWT string (dots misalignment)"
            );
        }

        return parts;
    }
}
