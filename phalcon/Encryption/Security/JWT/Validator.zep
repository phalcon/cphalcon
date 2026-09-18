
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Encryption\Security\JWT;

use DateTimeImmutable;
use Phalcon\Contracts\Encryption\EncryptionTypes;
use Phalcon\Encryption\Security\JWT\Exceptions\InvalidAudienceType;
use Phalcon\Encryption\Security\JWT\Exceptions\ValidatorException;
use Phalcon\Encryption\Security\JWT\Signer\SignerInterface;
use Phalcon\Encryption\Security\JWT\Token\Enum;
use Phalcon\Encryption\Security\JWT\Token\Token;
use Phalcon\Time\Clock\ClockInterface;

/**
 * Class Validator
 *
 * @phpstan-import-type encryption_jwt_audience from EncryptionTypes
 * @phpstan-import-type encryption_jwt_errors from EncryptionTypes
 * @phpstan-import-type encryption_jwt_validator_claims from EncryptionTypes
 */
class Validator
{
    /**
     * @phpstan-var encryption_jwt_validator_claims
     */
    private array claims = [];

    /**
     * @phpstan-var encryption_jwt_errors
     */
    private array errors = [];

    private int timeShift = 0;

    private <Token> token;

    /**
     * Validator constructor.
     *
     * @param int                 $timeShift Legacy clock-skew offset in seconds
     *                                       added to validated timestamps.
     *                                       Prefer injecting a ClockInterface
     *                                       for testable time; retained for BC.
     * @param ClockInterface|null $clock     Clock used to read "now" at
     *                                       construction. Defaults to the
     *                                       system wall clock (time()).
     */
    public function __construct(
        <Token> token,
        int timeShift = 0,
        <ClockInterface> clock = null
    ) {
        var now;

        let now = time();
        if (null !== clock) {
            let now = clock->now()->getTimestamp();
        }

        let this->token     = token,
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

    /**
     * Return the value of a claim
     */
    public function get(string claim) -> mixed | null
    {
        if isset this->claims[claim] {
            return this->claims[claim];
        }

        return null;
    }

    /**
     * Return an array with validation errors (if any)
     *
     * @phpstan-return encryption_jwt_errors
     */
    public function getErrors() -> array
    {
        return this->errors;
    }

    /**
     * Set the value of a claim, for comparison with the token values
     */
    public function set(string claim, var value) -> <static>
    {
        let this->claims[claim] = value;

        return this;
    }

    /**
     * Set the token to be validated
     */
    public function setToken(<Token> token) -> <static>
    {
        let this->token = token;

        return this;
    }

    /**
     * Validate the audience
     *
     * @throws ValidatorException
     */
    public function validateAudience(var audience) -> <static>
    {
        var item, tokenAudience;

        if (typeof audience !== "string" && typeof audience !== "array") {
            throw new InvalidAudienceType();
        }

        if (typeof audience === "string") {
            let audience = [audience];
        }

        let tokenAudience = this->token->getClaims()->get(Enum::AUDIENCE, []);

        for item in audience {
            if (true !== in_array(item, tokenAudience, true)) {
                let this->errors[] = "Validation: audience not allowed";
            }
        }

        return this;
    }

    /**
     * Validate a claim
     */
    public function validateClaim(string name, var value) -> <static>
    {
        var claimValue;

        let claimValue = this->token->getClaims()->get(name);

        if value !== claimValue {
            let this->errors[] = "Validation: incorrect " . name;
        }

        return this;
    }

    /**
     * Validate the expiration time of the token
     */
    public function validateExpiration(int timestamp) -> <static>
    {
        var tokenExpirationTime;

        let tokenExpirationTime = (int) this->token->getClaims()->get(Enum::EXPIRATION_TIME);

        if (
            this->token->getClaims()->has(Enum::EXPIRATION_TIME) &&
            this->getTimestamp(timestamp) > tokenExpirationTime
        ) {
            let this->errors[] = "Validation: the token has expired";
        }

        return this;
    }

    /**
     * Validate the id of the token
     *
     * A null id expresses no expectation and is skipped.
     */
    public function validateId(string id = null) -> <static>
    {
        var tokenId;

        if (null === id) {
            return this;
        }

        let tokenId = (string) this->token->getClaims()->get(Enum::ID);

        if (id !== tokenId) {
            let this->errors[] = "Validation: incorrect Id";
        }

        return this;
    }

    /**
     * Validate the issued at (iat) of the token
     *
     * A token issued at exactly $timestamp is valid. Only a token issued after
     * it, i.e. in the future, is rejected.
     */
    public function validateIssuedAt(int timestamp) -> <static>
    {
        var tokenIssuedAt;

        let tokenIssuedAt = (int) this->token->getClaims()->get(Enum::ISSUED_AT);

        if (this->getTimestamp(timestamp) < tokenIssuedAt) {
            let this->errors[] = "Validation: the token cannot be used yet (future)";
        }

        return this;
    }

    /**
     * Validate the issuer of the token
     *
     * A null issuer expresses no expectation and is skipped.
     */
    public function validateIssuer(string issuer = null) -> <static>
    {
        var tokenIssuer;

        if (null === issuer) {
            return this;
        }

        let tokenIssuer = (string) this->token->getClaims()->get(Enum::ISSUER);

        if (issuer !== tokenIssuer) {
            let this->errors[] = "Validation: incorrect issuer";
        }

        return this;
    }

    /**
     * Validate the notbefore (nbf) of the token
     *
     * A token is valid at exactly $timestamp. Only a timestamp before the
     * "nbf" claim is rejected.
     */
    public function validateNotBefore(int timestamp) -> <static>
    {
        var tokenNotBefore;

        let tokenNotBefore = (int) this->token->getClaims()->get(Enum::NOT_BEFORE);

        if (this->getTimestamp(timestamp) < tokenNotBefore) {
            let this->errors[] = "Validation: the token cannot be used yet (not before)";
        }

        return this;
    }

    /**
     * Validate the signature of the token
     */
    public function validateSignature(
        <SignerInterface> signer,
        string passphrase
    ) -> <static> {
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
     * Validate the subject of the token
     *
     * A null subject expresses no expectation and is skipped.
     */
    public function validateSubject(string subject = null) -> <static>
    {
        var tokenSubject;

        if (null === subject) {
            return this;
        }

        let tokenSubject = (string) this->token->getClaims()->get(Enum::SUBJECT);

        if (subject !== tokenSubject) {
            let this->errors[] = "Validation: incorrect subject";
        }

        return this;
    }

    private function getTimestamp(int timestamp) -> int
    {
        return timestamp + this->timeShift;
    }
}
