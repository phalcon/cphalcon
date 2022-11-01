
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Encryption\Security\JWT;

use Phalcon\Encryption\Security\JWT\Exceptions\ValidatorException;
use Phalcon\Encryption\Security\JWT\Signer\SignerInterface;
use Phalcon\Encryption\Security\JWT\Token\Enum;
use Phalcon\Encryption\Security\JWT\Token\Token;

/**
 * Class Validator
 */
class Validator
{
    /**
     * @var array
     */
    private claims = [];

    /**
     * @var array
     */
    private errors = [];

    /**
     * @var int
     */
    private timeShift = 0;

    /**
     * @var Token
     */
    private token;

    /**
     * Validator constructor.
     *
     * @param Token $token
     * @param int   $timeShift
     */
    public function __construct(<Token> token, int timeShift = 0)
    {
        var now;

        let now             = time(),
            this->token     = token,
            this->timeShift = timeShift,
            this->claims    = [
                Enum::AUDIENCE        : null,
                Enum::EXPIRATION_TIME : now,
                Enum::ID              : null,
                Enum::ISSUED_AT       : now,
                Enum::ISSUER          : null,
                Enum::NOT_BEFORE      : now,
                Enum::SUBJECT         : null
            ];
    }

    public function getErrors() -> array
    {
        return this->errors;
    }

    public function get(string claim) -> mixed | null
    {
        if isset this->claims[claim] {
            return this->claims[claim];
        }

        return null;
    }

    public function set(string claim, var value) -> <Validator>
    {
        let this->claims[claim] = value;

        return this;
    }

    /**
     * @param Token $token
     *
     * @return Validator
     */
    public function setToken(<Token> token) -> <Validator>
    {
        let this->token = token;

        return this;
    }

    /**
     * @param string|array $audience
     *
     * @return Validator
     * @throws ValidatorException
     */
    public function validateAudience(var audience) -> <Validator>
    {
        var item, tokenAudience;

        if (typeof audience !== "string" && typeof audience !== "array") {
            throw new ValidatorException(
                "Audience must be a string or an array"
            );
        }

        if (typeof audience === "string") {
            let audience = [audience];
        }

        let tokenAudience = this->token->getClaims()->get(Enum::AUDIENCE, []);

        for item in audience {
            if (true !== in_array(item, tokenAudience)) {
                let this->errors[] = "Validation: audience not allowed";
            }
        }

        return this;
    }

    /**
     * @param int $timestamp
     *
     * @return Validator
     * @throws ValidatorException
     */
    public function validateExpiration(int timestamp) -> <Validator>
    {
        var tokenExpirationTime;

        let tokenExpirationTime = (int) this->token->getClaims()->get(Enum::EXPIRATION_TIME);

        if (
            this->token->getClaims()->has(Enum::EXPIRATION_TIME) &&
            this->getTimestamp(timestamp) > $tokenExpirationTime
        ) {
            let this->errors[] = "Validation: the token has expired";
        }

        return this;
    }

    /**
     * @param string $id
     *
     * @return Validator
     * @throws ValidatorException
     */
    public function validateId(string id) -> <Validator>
    {
        var tokenId;

        let tokenId = (string) this->token->getClaims()->get(Enum::ID);

        if ($id !== tokenId) {
            let this->errors[] = "Validation: incorrect Id";
        }

        return this;
    }

    /**
     * @param int $timestamp
     *
     * @return Validator
     * @throws ValidatorException
     */
    public function validateIssuedAt(int timestamp) -> <Validator>
    {
        var tokenIssuedAt;

        let tokenIssuedAt = (int) this->token->getClaims()->get(Enum::ISSUED_AT);

        if (this->getTimestamp($timestamp) <= tokenIssuedAt) {
            let this->errors[] = "Validation: the token cannot be used yet (future)";
        }

        return this;
    }

    /**
     * @param string $issuer
     *
     * @return Validator
     * @throws ValidatorException
     */
    public function validateIssuer(string! issuer) -> <Validator>
    {
        var tokenIssuer;

        let tokenIssuer = (string) this->token->getClaims()->get(Enum::ISSUER);

        if (issuer !== tokenIssuer) {
            let this->errors[] = "Validation: incorrect issuer";
        }

        return this;
    }

    /**
     * @param int $timestamp
     *
     * @return Validator
     * @throws ValidatorException
     */
    public function validateNotBefore(int timestamp) -> <Validator>
    {
        var tokenNotBefore;

        let tokenNotBefore = (int) this->token->getClaims()->get(Enum::NOT_BEFORE);

        if (this->getTimestamp($timestamp) <= tokenNotBefore) {
            let this->errors[] = "Validation: the token cannot be used yet (not before)";
        }

        return this;
    }

    /**
     * @param SignerInterface $signer
     * @param string          $passphrase
     *
     * @return Validator
     * @throws ValidatorException
     */
    public function validateSignature(
        <SignerInterface> signer,
        string passphrase
    ) -> <Validator> {
        if (
            true !== signer->verify(
                this->token->getSignature()->getHash(),
                this->token->getPayload(),
                passphrase
            )
        ) {
            let this->errors[] = "Validation: the signature does not match";
        }

        return this;
    }

    /**
     * @param int $timestamp
     *
     * @return int
     */
    private function getTimestamp(int timestamp) -> int
    {
        return timestamp + this->timeShift;
    }
}
