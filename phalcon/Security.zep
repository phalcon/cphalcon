
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon;

use Phalcon\DiInterface;
use Phalcon\Security\Random;
use Phalcon\Security\Exception;
use Phalcon\Di\InjectionAwareInterface;
use Phalcon\Session\ManagerInterface as SessionInterface;

/**
 * Phalcon\Security
 *
 * This component provides a set of functions to improve the security in Phalcon
 * applications
 *
 *<code>
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
 *</code>
 */
class Security implements InjectionAwareInterface
{
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

    protected container;
    protected defaultHash;
    protected numberBytes = 16;
    protected random;
    protected requestToken;
    protected token;
    protected tokenKey;
    protected tokenKeySessionId = "$PHALCON/CSRF/KEY$";
    protected tokenValueSessionId = "$PHALCON/CSRF$";
    protected workFactor = 8 { set, get };

    /**
     * Phalcon\Security constructor
     */
    public function __construct() -> void
    {
        let this->random = new Random();
    }

    /**
     * Checks a plain text password and its hash version to check if the
     * password matches
     */
    public function checkHash(string password, string passwordHash, int maxPassLength = 0) -> bool
    {
        char ch;
        string cryptedHash;
        int i, sum, cryptedLength, passwordLength;

        if maxPassLength > 0 && strlen(password) > maxPassLength {
            return false;
        }

        let cryptedHash = (string) crypt(password, passwordHash);

        let cryptedLength = strlen(cryptedHash),
            passwordLength = strlen(passwordHash);

        let cryptedHash .= passwordHash;

        let sum = cryptedLength - passwordLength;

        for i, ch in passwordHash {
            let sum = sum | (cryptedHash[i] ^ ch);
        }

        return 0 === sum;
    }

    /**
     * Check if the CSRF token sent in the request is the same that the current
     * in session
     */
    public function checkToken(var tokenKey = null, var tokenValue = null, bool destroyIfValid = true) -> bool
    {
        var container, session, request, equals, userToken, knownToken;

        let container = <DiInterface> this->container;

        if typeof container != "object" {
            throw new Exception(
                Exception::containerServiceNotFound("the 'session' service")
            );
        }

        let session = <SessionInterface> container->getShared("session");

        if !tokenKey {
            let tokenKey = session->get(
                this->tokenKeySessionId
            );
        }

        /**
         * If tokenKey does not exist in session return false
         */
        if !tokenKey {
            return false;
        }

        if !tokenValue {
            let request = container->getShared("request");

            /**
             * We always check if the value is correct in post
             */
            let userToken = request->getPost(tokenKey, "string");
        } else {
            let userToken = tokenValue;
        }

        /**
         * The value is the same?
         */
        let knownToken = this->getRequestToken();

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
     */
    public function computeHmac(string data, string key, string algo, bool raw = false) -> string
    {
        var hmac;

        let hmac = hash_hmac(algo, data, key, raw);

        if !hmac {
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
        var container, session;

        let container = <DiInterface> this->container;

        if typeof container != "object" {
            throw new Exception(
                Exception::containerServiceNotFound("the 'session' service")
            );
        }

        let session = <SessionInterface> container->getShared("session");

        session->remove(this->tokenKeySessionId);
        session->remove(this->tokenValueSessionId);

        let this->token = null;
        let this->tokenKey = null;
        let this->requestToken = null;

        return this;
    }

    /**
      * Returns the default hash
      */
    public function getDefaultHash() -> int | null
    {
        return this->defaultHash;
    }

    /**
     * Returns the internal dependency injector
     */
    public function getDI() -> <DiInterface>
    {
        return this->container;
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
    public function getRandomBytes() -> string
    {
        return this->numberBytes;
    }

    /**
     * Returns the value of the CSRF token for the current request.
     */
    public function getRequestToken() -> string
    {
        if empty this->requestToken {
            return this->getSessionToken();
        }

        return this->requestToken;
    }

    /**
     * Returns the value of the CSRF token in session
     */
    public function getSessionToken() -> string
    {
        var container, session;

        let container = <DiInterface> this->container;

        if typeof container != "object" {
            throw new Exception(
                Exception::containerServiceNotFound("the 'session' service")
            );
        }

        let session = <SessionInterface> container->getShared("session");

        return session->get(this->tokenValueSessionId);
    }

    /**
     * Generate a >22-length pseudo random string to be used as salt for
     * passwords
     */
    public function getSaltBytes(int numberBytes = 0) -> string
    {
        var safeBytes;

        if !numberBytes {
            let numberBytes = (int) this->numberBytes;
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
     */
    public function getToken() -> string
    {
        var container, session;

        if null === this->token {
            let this->requestToken = this->getSessionToken();
            let this->token = this->random->base64Safe(this->numberBytes);

            let container = <DiInterface> this->container;

            if typeof container != "object" {
                throw new Exception(
                    Exception::containerServiceNotFound("the 'session' service")
                );
            }

            let session = <SessionInterface> container->getShared("session");

            session->set(
                this->tokenValueSessionId,
                this->token
            );
        }

        return this->token;
    }

    /**
     * Generates a pseudo random token key to be used as input's name in a CSRF
     * check
     */
    public function getTokenKey() -> string
    {
        var container, session;

        if null === this->tokenKey {
            let container = <DiInterface> this->container;

            if typeof container != "object" {
                throw new Exception(
                    Exception::containerServiceNotFound("the 'session' service")
                );
            }

            let this->tokenKey = this->random->base64Safe(this->numberBytes);

            let session = <SessionInterface> container->getShared("session");

            session->set(
                this->tokenKeySessionId,
                this->tokenKey
            );
        }

        return this->tokenKey;
    }

    /**
     * Creates a password hash using bcrypt with a pseudo random salt
     */
    public function hash(string password, int workFactor = 0) -> string
    {
        int hash;
        string variant;
        var saltBytes;

        if !workFactor {
            let workFactor = (int) this->workFactor;
        }

        let hash = (int) this->defaultHash;

        switch hash {

            case self::CRYPT_BLOWFISH_A:
                let variant = "a";
                break;

            case self::CRYPT_BLOWFISH_X:
                let variant = "x";
                break;

            case self::CRYPT_BLOWFISH_Y:
                let variant = "y";
                break;

            case self::CRYPT_MD5:
                let variant = "1";
                break;

            case self::CRYPT_SHA256:
                let variant = "5";
                break;

            case self::CRYPT_SHA512:
                let variant = "6";
                break;

            case self::CRYPT_DEFAULT:
            default:
                let variant = "y";
                break;
        }

        switch hash {

            case self::CRYPT_STD_DES:
            case self::CRYPT_EXT_DES:

                /*
                 * Standard DES-based hash with a two character salt from the
                 * alphabet "./0-9A-Za-z".
                 */

                if (hash == self::CRYPT_EXT_DES) {
                    let saltBytes = "_" . this->getSaltBytes(8);
                } else {
                    let saltBytes = this->getSaltBytes(2);
                }

                if typeof saltBytes != "string" {
                    throw new Exception(
                        "Unable to get random bytes for the salt"
                    );
                }

                return crypt(password, saltBytes);

            case self::CRYPT_MD5:
            case self::CRYPT_SHA256:
            case self::CRYPT_SHA512:

                /*
                 * MD5 hashing with a twelve character salt
                 * SHA-256/SHA-512 hash with a sixteen character salt.
                 */

                let saltBytes = this->getSaltBytes(hash == self::CRYPT_MD5 ? 12 : 16);

                if typeof saltBytes != "string" {
                    throw new Exception(
                        "Unable to get random bytes for the salt"
                    );
                }

                return crypt(
                    password, "$" . variant . "$"  . saltBytes . "$"
                );

            case self::CRYPT_DEFAULT:
            case self::CRYPT_BLOWFISH:
            case self::CRYPT_BLOWFISH_X:
            case self::CRYPT_BLOWFISH_Y:
            default:

                /*
                 * Blowfish hashing with a salt as follows: "$2a$", "$2x$" or
                 * "$2y$", a two digit cost parameter, "$", and 22 characters
                 * from the alphabet "./0-9A-Za-z". Using characters outside of
                 * this range in the salt will cause `crypt()` to return a
                 * zero-length string. The two digit cost parameter is the
                 * base-2 logarithm of the iteration count for the underlying
                 * Blowfish-based hashing algorithm and must be in range 04-31,
                 * values outside this range will cause crypt() to fail.
                 */

                let saltBytes = this->getSaltBytes(22);

                if typeof saltBytes != "string" {
                    throw new Exception(
                        "Unable to get random bytes for the salt"
                    );
                }

                if workFactor < 4 {
                    let workFactor = 4;
                } elseif workFactor > 31 {
                    let workFactor = 31;
                }

                return crypt(
                    password,
                    "$2" . variant . "$" . sprintf("%02s", workFactor) . "$" . saltBytes . "$"
                );
        }

        return "";
    }

    /**
     * Checks if a password hash is a valid bcrypt's hash
     */
    public function isLegacyHash(string passwordHash) -> bool
    {
        return starts_with(passwordHash, "$2a$");
    }

    /**
      * Sets the default hash
      */
    public function setDefaultHash(int defaultHash) -> <Security>
    {
        let this->defaultHash = defaultHash;

        return this;
    }

    /**
     * Sets the dependency injector
     */
    public function setDI(<DiInterface> container) -> void
    {
        let this->container = container;
    }

    /**
     * Sets a number of bytes to be generated by the openssl pseudo random
     * generator
     */
    public function setRandomBytes(long! randomBytes) -> <Security>
    {
        let this->numberBytes = randomBytes;

        return this;
    }
}
