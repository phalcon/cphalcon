
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Http\JWT;

use Phalcon\Http\JWT\Exceptions\ValidatorException;
use Phalcon\Http\JWT\Token\Enum;
use Phalcon\Http\JWT\Token\Token;

/**
 * Class Validator
 *
 * @property int   $timeShift
 * @property Token $token
 */
class Validator
{
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
        let this->token     = token,
            this->timeShift = timeShift;
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
     * @param string $audience
     *
     * @return Validator
     * @throws ValidatorException
     */
    public function validateAudience(string! audience) -> <Validator>
    {
        if (!in_array(audience, this->token->getClaims()->get(Enum::AUDIENCE, []))) {
            throw new ValidatorException(
                "Validation: audience not allowed"
            );
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
        if (
            this->token->getClaims()->has(Enum::EXPIRATION_TIME) &&
            this->getTimestamp(timestamp) >= (int) this->token->getClaims()->get(Enum::EXPIRATION_TIME)
        ) {
            throw new ValidatorException(
                "Validation: the token has expired"
            );
        }

        return this;
    }

    /**
     * @param string $id
     *
     * @return Validator
     * @throws ValidatorException
     */
    public function validateId(string! id) -> <Validator>
    {
        if (id !== (string) this->token->getClaims()->get(Enum::ID)) {
            throw new ValidatorException(
                "Validation: incorrect Id"
            );
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
        if (this->getTimestamp(timestamp) <= (int) this->token->getClaims()->get(Enum::ISSUED_AT)) {
            throw new ValidatorException(
                "Validation: the token cannot be used yet (future)"
            );
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
        if (issuer !== (string) this->token->getClaims()->get(Enum::ISSUER)) {
            throw new ValidatorException(
                "Validation: incorrect issuer"
            );
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
        if (this->getTimestamp(timestamp) <= (int) this->token->getClaims()->get(Enum::NOT_BEFORE)) {
            throw new ValidatorException(
                "Validation: the token cannot be used yet (not before)"
            );
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
