
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Encryption\Security\JWT\Token;

use Phalcon\Contracts\Encryption\EncryptionTypes;
use Phalcon\Encryption\Security\JWT\Signer\SignerInterface;
use Phalcon\Encryption\Security\JWT\Validator;

/**
 * Token Class.
 *
 * A container for Token related data. It stores the claims, headers, signature
 * and payload. It also calculates and returns the token string.
 *
 * @property Item      $claims
 * @property Item      $headers
 * @property Signature $signature
 *
 * @link https://tools.ietf.org/html/rfc7519
 *
 * @phpstan-import-type encryption_jwt_errors from EncryptionTypes
 */
class Token
{
    private <Item> claims;

    private <Item> headers;

    private <Signature> signature;

    /**
     * Token constructor.
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
     * Return the registered claims
     */
    public function getClaims() -> <Item>
    {
        return this->claims;
    }

    /**
     * Return the registered headers
     */
    public function getHeaders() -> <Item>
    {
        return this->headers;
    }

    /**
     * Return the payload
     */
    public function getPayload() -> string
    {
        return this->headers->getEncoded() . "." . this->claims->getEncoded();
    }

    /**
     * Return the signature
     */
    public function getSignature() -> <Signature>
    {
        return this->signature;
    }

    /**
     * Return the token
     */
    public function getToken() -> string
    {
        return this->getPayload() . "." . this->signature->getEncoded();
    }

    /**
     * Validate the token against the claims registered in the validator.
     *
     * Only claims that have a value in the validator are checked. A claim left
     * as null expresses no expectation and is skipped.
     *
     * Security note: this method checks the claims only. It does not verify
     * the signature. A token accepted by validate() alone is unauthenticated.
     * Always also call verify() (or Validator::validateSignature()) and treat
     * an empty error array as valid only after the signature check passes.
     * A signature-aware default is planned for a future major version.
     *
     * @phpstan-return encryption_jwt_errors
     */
    public function validate(<Validator> validator) -> array
    {
        var claimValue, method;
        array methods;

        let methods = [
            "validateAudience"   : validator->get(Enum::AUDIENCE),
            "validateExpiration" : validator->get(Enum::EXPIRATION_TIME),
            "validateId"         : validator->get(Enum::ID),
            "validateIssuedAt"   : validator->get(Enum::ISSUED_AT),
            "validateIssuer"     : validator->get(Enum::ISSUER),
            "validateNotBefore"  : validator->get(Enum::NOT_BEFORE),
            "validateSubject"    : validator->get(Enum::SUBJECT)
        ];

        for method, claimValue in methods {
            if (null !== claimValue) {
                validator->{method}(claimValue);
            }
        }

        return validator->getErrors();
    }

    /**
     * Verify the signature
     */
    public function verify(<SignerInterface> signer, string key) -> bool
    {
        if (signer->getAlgHeader() !== this->getHeaders()->get(Enum::ALGO)) {
            return false;
        }

        return signer->verify(
            this->signature->getHash(),
            this->getPayload(),
            key
        );
    }
}
