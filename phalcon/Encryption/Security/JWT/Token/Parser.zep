
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Encryption\Security\JWT\Token;

use InvalidArgumentException;
use Phalcon\Encryption\Security\JWT\Exceptions\InvalidClaims;
use Phalcon\Encryption\Security\JWT\Exceptions\InvalidHeader;
use Phalcon\Encryption\Security\JWT\Exceptions\MalformedJwtString;
use Phalcon\Encryption\Security\JWT\Exceptions\MissingJwtTypHeader;
use Phalcon\Support\Helper\Json\Decode;

/**
 * Token Parser class.
 *
 * It parses a token by validating if it is formed properly and splits it into
 * three parts. The headers are decoded, then the claims and finally the
 * signature. It returns a token object populated with the decoded information.
 */
class Parser
{
    /**
     * @var Decode
     */
    private decode;

    public function __construct(<Decode> decode = null)
    {
        var service;

        let service = decode;
        if (null === service) {
            let service = new Decode();
        }

        let this->decode = service;
    }

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
            encodedSignature = (string) results[2],
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

        let decoded = this->decode->__invoke(this->decodeUrl(claims), true);

        if typeof decoded !== "array" {
            throw new InvalidClaims();
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

        let decoded = this->decode->__invoke(this->decodeUrl(headers), true);

        if typeof decoded !== "array" {
            throw new InvalidHeader();
        }

        if !isset decoded[Enum::TYPE] {
            throw new MissingJwtTypHeader();
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
    private function decodeSignature(<Item> headers, string! signature) -> <Signature>
    {
        var algo, decoded, encodedSignature;

        let decoded          = "",
            encodedSignature = "",
            algo             = headers->get(Enum::ALGO, "none");

        if "none" !== algo {
            let decoded          = (string) this->decodeUrl(signature),
                encodedSignature = signature;
        }

        return new Signature(decoded, encodedSignature);
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
            throw new MalformedJwtString();
        }

        return parts;
    }

    /**
     * @todo This will be removed when traits are introduced
     */
    private function decodeUrl(string! input) -> string
    {
        var data, remainder;

        let remainder = strlen(input) % 4;
        if remainder {
            let input .= str_repeat("=", 4 - remainder);
        }

        let data = base64_decode(strtr(input, "-_", "+/"));
        if (false === data) {
            let data = "";
        }

        return data;
    }
}
