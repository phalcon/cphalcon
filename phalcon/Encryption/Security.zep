
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Encryption;

use Phalcon\Di\DiInterface;
use Phalcon\Di\AbstractInjectionAware;
use Phalcon\Http\RequestInterface;
use Phalcon\Encryption\Security\Random;
use Phalcon\Encryption\Security\Exception;
use Phalcon\Session\ManagerInterface as SessionInterface;

/**
 * This component provides a set of functions to improve the security in Phalcon
 * applications
 *
 *```php
 * $login    = $this->request->getPost("login");
 * $password = $this->request->getPost("password");
 *
 * $user = Users::findFirstByLogin($login);
 *
 * if ($user) {
 *     if ($this->security->checkHash($password, $user->password)) {
 *         // The password is valid
 *     }
 * }
 *```
 */
class Security extends AbstractInjectionAware
{
    const CRYPT_ARGON2I    = 10;
    const CRYPT_ARGON2ID   = 11;
    const CRYPT_BCRYPT     = 0;
    const CRYPT_DEFAULT    = 0;
    const CRYPT_BLOWFISH   = 4;
    const CRYPT_BLOWFISH_A = 5;
    const CRYPT_BLOWFISH_X = 6;
    const CRYPT_BLOWFISH_Y = 7;
    const CRYPT_EXT_DES    = 2;
    const CRYPT_MD5        = 3;
    const CRYPT_SHA256     = 8;
    const CRYPT_SHA512     = 9;
    const CRYPT_STD_DES    = 1;

    /**
     * @var int
     */
    protected defaultHash = self::CRYPT_DEFAULT;

    /**
     * @var int
     */
    protected numberBytes = 16;

    /**
     * @var Random
     */
    protected random;

    /**
     * @var string|null
     */
    protected requestToken = null;

    /**
     * @var string|null
     */
    protected token = null;

    /**
     * @var string|null
     */
    protected tokenKey = null;

    /**
     * @var string
     */
    protected tokenKeySessionId = "$PHALCON/CSRF/KEY$";

    /**
     * @var string
     */
    protected tokenValueSessionId = "$PHALCON/CSRF$";

    /**
     * @var int
     */
    protected workFactor = 10 { get };

    /**
     * @var SessionInterface|null
     */
    private localSession = null;

    /**
     * @var RequestInterface|null
     */
    private localRequest = null;

    /**
     * Security constructor.
     *
     * @param SessionInterface|null $session
     * @param RequestInterface|null $request
     */
    public function __construct(
        <SessionInterface> session = null,
        <RequestInterface> request = null
    ) {
        let this->random       = new Random(),
            this->localRequest = request,
            this->localSession = session;
    }

    /**
     * Checks a plain text password and its hash version to check if the
     * password matches
     *
     * @param string $password
     * @param string $passwordHash
     * @param int    $maxPassLength
     *
     * @return bool
     */
    public function checkHash(
        string password,
        string passwordHash,
        int maxPassLength = 0
    ) -> bool {
        if maxPassLength > 0 && strlen(password) > maxPassLength {
            return false;
        }

        return password_verify(password, passwordHash);
    }

    /**
     * Check if the CSRF token sent in the request is the same that the current
     * in session
     *
     * @param string|null $tokenKey
     * @param mixed|null  $tokenValue
     * @param bool        $destroyIfValid
     *
     * @return bool
     */
    public function checkToken(
        string tokenKey = null,
        var tokenValue = null,
        bool destroyIfValid = true
    ) -> bool {
        var equals, knownToken, userToken;

        let tokenKey = this->processTokenKey(tokenKey);

        /**
         * If tokenKey does not exist in session return false
         */
        if !tokenKey {
            return false;
        }

        /**
         * The value is the same?
         */
        let userToken  = this->processUserToken(tokenKey, tokenValue),
            knownToken = this->getRequestToken();
        if (null === knownToken || null === userToken) {
            return false;
        }

        let equals = hash_equals(knownToken, userToken);

        /**
         * Remove the key and value of the CSRF token in session
         */
        if equals && destroyIfValid {
            this->destroyToken();
        }

        return equals;
    }

    /**
     * Computes a HMAC
     *
     * @param string $data
     * @param string $key
     * @param string $algo
     * @param bool   $raw
     *
     * @return string
     * @throws Exception
     */
    public function computeHmac(
        string data,
        string key,
        string algo,
        bool raw = false
    ) -> string {
        var hmac;

        let hmac = hash_hmac(algo, data, key, raw);

        if unlikely !hmac {
            throw new Exception(
                sprintf(
                    "Unknown hashing algorithm: %s",
                    algo
                )
            );
        }

        return hmac;
    }

    /**
     * Removes the value of the CSRF token and key from session
     */
    public function destroyToken() -> <Security>
    {
        var session;

        let session = this->getLocalService("session", "localSession");

        if likely session {
            session->remove(this->tokenKeySessionId);
            session->remove(this->tokenValueSessionId);
        }

        let this->token        = null,
            this->tokenKey     = null,
            this->requestToken = null;

        return this;
    }

    /**
     * Returns the default hash
     *
     * @return int
     */
    public function getDefaultHash() -> int
    {
        return this->defaultHash;
    }

    /**
     * Returns information regarding a hash
     *
     * @param string $hash
     *
     * @return array
     */
    public function getHashInformation(string hash) -> array
    {
        return password_get_info(hash);
    }

    /**
     * Returns a secure random number generator instance
     */
    public function getRandom() -> <Random>
    {
        return this->random;
    }

    /**
     * Returns a number of bytes to be generated by the openssl pseudo random
     * generator
     */
    public function getRandomBytes() -> int
    {
        return this->numberBytes;
    }

    /**
     * Returns the value of the CSRF token for the current request.
     */
    public function getRequestToken() -> string | null
    {
        if empty this->requestToken {
            return this->getSessionToken();
        }

        return this->requestToken;
    }

    /**
     * Returns the value of the CSRF token in session
     *
     * @return string|null
     */
    public function getSessionToken() -> string | null
    {
        var session;

        let session = this->getLocalService("session", "localSession");

        if likely session {
            return session->get(this->tokenValueSessionId);
        }

        return null;
    }

    /**
     * Generate a >22-length pseudo random string to be used as salt for
     * passwords
     *
     * @param int $numberBytes
     *
     * @return string
     * @throws Exception
     */
    public function getSaltBytes(int numberBytes = 0) -> string
    {
        var safeBytes;

        if !numberBytes {
            let numberBytes = this->numberBytes;
        }

        loop {
            let safeBytes = this->random->base64Safe(numberBytes);

            if safeBytes && strlen(safeBytes) >= numberBytes {
                break;
            }
        }

        return safeBytes;
    }

    /**
     * Generates a pseudo random token value to be used as input's value in a
     * CSRF check
     *
     * @return string
     * @throws Exception
     */
    public function getToken() -> string | null
    {
        var session;

        if (null === this->token) {
            let this->requestToken = this->getSessionToken(),
                this->token        = this->random->base64Safe(this->numberBytes);

            /** @var SessionInterface|null $session */
            let session = this->getLocalService("session", "localSession");
            if (null !== session) {
                session->set(
                    this->tokenValueSessionId,
                    this->token
                );
            }
        }

        return this->token;
    }

    /**
     * Generates a pseudo random token key to be used as input's name in a CSRF
     * check
     *
     * @return string|null
     * @throws Exception
     */
    public function getTokenKey() -> string | null
    {
        var session;

        if (null === this->tokenKey) {
            /** @var SessionInterface|null $session */
            let session = this->getLocalService("session", "localSession");
            if (null !== session) {
                let this->tokenKey = this->random->base64Safe(this->numberBytes);
                session->set(
                    this->tokenKeySessionId,
                    this->tokenKey
                );
            }
        }

        return this->tokenKey;
    }

    /**
     * Creates a password hash using bcrypt with a pseudo random salt
     *
     * @param string $password
     * @param array  $options
     *
     * @return string
     */
    public function hash(string password, array options = []) -> string
    {
        var algorithm, arguments, cost, formatted, prefix, salt;
        bool legacy;
        int bytes;

        /**
         * The `legacy` variable distinguishes between `password_hash` and
         * non `password_hash` hashing.
         */
        let cost      = this->processCost(options),
            formatted = sprintf("%02s", cost),
            prefix    = "",
            bytes     = 22,
            legacy    = true;

        switch (this->defaultHash) {
            case self::CRYPT_MD5:
                /*
                 * MD5 hashing with a twelve character salt
                 * SHA-256/SHA-512 hash with a sixteen character salt.
                 */
                let prefix = "$1$",
                    bytes  = 12;
                break;
            case self::CRYPT_SHA256:
                let prefix = "$5$",
                    bytes  = 16;
                break;
            case self::CRYPT_SHA512:
                let prefix = "$6$",
                    bytes  = 16;
                break;
            /*
             * Blowfish hashing with a salt as follows: "$2a$", "$2x$" or
             * "$2y$", a two digit cost parameter, "$", and 22 characters
             * from the alphabet "./0-9A-Za-z". Using characters outside
             * this range in the salt will cause `crypt()` to return a
             * zero-length string. The two digit cost parameter is the
             * base-2 logarithm of the iteration count for the underlying
             * Blowfish-based hashing algorithm and must be in range 04-31,
             * values outside this range will cause crypt() to fail.
             */
            case self::CRYPT_BLOWFISH_A:
                let prefix = sprintf("$2a$%s$", formatted);
                break;
            case self::CRYPT_BLOWFISH_X:
                let prefix = sprintf("$2x$%s$", formatted);
                break;
            default:
                let legacy = false;
                break;
        }

        if unlikely legacy {
            let salt = prefix . this->getSaltBytes(bytes) . "$";

            return crypt(password, salt);
        }

        /**
         * This is using password_hash
         *
         * We will not provide a "salt" but let PHP calculate it.
         */
        let options = [
            "cost" : cost
        ];

        let algorithm = this->processAlgorithm(),
            arguments = this->processArgonOptions(options);

        return password_hash(password, algorithm, arguments);
    }

    /**
     * Checks if a password hash is a valid bcrypt's hash
     *
     * @param string $passwordHash
     *
     * @return bool
     */
    public function isLegacyHash(string passwordHash) -> bool
    {
        return starts_with(passwordHash, "$2a$");
    }

    /**
     * Sets the default hash
     *
     * @param int $defaultHash
     *
     * @return Security
     */
    public function setDefaultHash(int defaultHash) -> <Security>
    {
        let this->defaultHash = defaultHash;

        return this;
    }

    /**
     * Sets a number of bytes to be generated by the openssl pseudo random
     * generator
     *
     * @param int $randomBytes
     *
     * @return Security
     */
    public function setRandomBytes(int! randomBytes) -> <Security>
    {
        let this->numberBytes = randomBytes;

        return this;
    }

    /**
     * Sets the work factor
     *
     * @param int $workFactor
     *
     * @return Security
     */
    public function setWorkFactor(int workFactor) -> <Security>
    {
        let this->workFactor = workFactor;

        return this;
    }

    /**
     * @param string $name
     * @param string $property
     *
     * @return RequestInterface|SessionInterface|null
     */
    protected function getLocalService(string name, string property)
    {
        if (
            null === this->{property} &&
            null !== this->container &&
            true === this->container->has(name)
        ) {
            let this->{property} = this->container->getShared(name);
        }

        return this->{property};
    }

    /**
     * Checks the algorithm for `password_hash`. If it is argon based, it
     * returns the relevant constant
     *
     * @return string
     */
    private function processAlgorithm() -> string
    {
        var algorithm;

        let algorithm = PASSWORD_BCRYPT;

        if (this->defaultHash === self::CRYPT_ARGON2I) {
            let algorithm = PASSWORD_ARGON2I;
        } elseif (this->defaultHash === self::CRYPT_ARGON2ID) {
            let algorithm = PASSWORD_ARGON2ID;
        }

        return algorithm;
    }

    /**
     * We check if the algorithm is Argon based. If yes, options are set for
     * `password_hash` such as `memory_cost`, `time_cost` and `threads`
     *
     * @param array $options
     *
     * @return array
     */
    private function processArgonOptions(array options) -> array
    {
        var value;

        if (
            this->defaultHash === self::CRYPT_ARGON2I ||
            this->defaultHash === self::CRYPT_ARGON2ID
        ) {
            if !fetch value, options["memory_cost"] {
                let value = PASSWORD_ARGON2_DEFAULT_MEMORY_COST;
            }
            let options["memory_cost"] = value;

            if !fetch value, options["time_cost"] {
                let value = PASSWORD_ARGON2_DEFAULT_TIME_COST;
            }
            let options["time_cost"] = value;

            if !fetch value, options["threads"] {
                let value = PASSWORD_ARGON2_DEFAULT_THREADS;
            }
            let options["threads"] = value;
        }

        return options;
    }

    /**
     * Checks the options array for `cost`. If not defined it is set to 10.
     * It also checks the cost if it is between 4 and 31
     *
     * @param array $options
     *
     * @return int
     */
    private function processCost(array options = []) -> int
    {
        var cost;

        if !fetch cost, options["cost"] {
            let cost = 10;
        }

        if cost < 4 {
            let cost = 4;
        }

        if cost > 31 {
            let cost = 31;
        }

        return cost;
    }

    /**
     * @param string|null $tokenKey
     *
     * @return string|null
     */
    private function processTokenKey(string tokenKey = null) -> string | null
    {
        var key, session;

        let key     = tokenKey,
            session = this->getLocalService("session", "localSession");
        if (null !== session && true === empty(key)) {
            let key = session->get(this->tokenKeySessionId);
        }

        return key;
    }

    /**
     * @param string      $tokenKey
     * @param string|null $tokenValue
     *
     * @return string|null
     */
    private function processUserToken(
        string tokenKey,
        string tokenValue = null
    ) -> string | null {
        var request, userToken;

        let userToken = tokenValue;
        if !tokenValue {
            /** @var RequestInterface|null $request */
            let request = this->getLocalService("request", "localRequest");

            /**
             * We always check if the value is correct in post
             */
            if (null !== request) {
                /** @var string|null $userToken */
                let userToken = request->getPost(tokenKey, "string");
            }
        }

        return userToken;
    }
}
