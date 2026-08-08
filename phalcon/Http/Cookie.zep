
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Http;

use Phalcon\Di\AbstractInjectionAware;
use Phalcon\Di\DiInterface;
use Phalcon\Encryption\Crypt\CryptInterface;
use Phalcon\Filter\FilterInterface;
use Phalcon\Http\Cookie\CookieInterface;
use Phalcon\Http\Cookie\Exception as CookieException;
use Phalcon\Http\Cookie\Exceptions\CookieKeyTooShort;
use Phalcon\Http\Cookie\Exceptions\CryptInterfaceRequired;
use Phalcon\Http\Cookie\Exceptions\CryptServiceUnavailable;
use Phalcon\Http\Cookie\Exceptions\FilterServiceUnavailable;
use Phalcon\Http\Response\Exception;
use Phalcon\Http\Traits\EncryptionAwareTrait;
use Phalcon\Session\ManagerInterface as SessionManagerInterface;
use Phalcon\Traits\Support\Helper\Arr\GetTrait;
use Stringable;

/**
 * Provide OO wrappers to manage a HTTP cookie.
 */
class Cookie extends AbstractInjectionAware implements CookieInterface, Stringable
{
    use EncryptionAwareTrait;
    use GetTrait;

    protected string domain = "";
    protected int expire = 0;
    protected ?<FilterInterface> filter = null;
    protected bool httpOnly = false;
    protected string name;
    protected array options = [];
    protected string path = "/";
    protected bool isRead = false;
    protected bool isRestored = false;
    protected bool secure = true;
    /**
     * The cookie's sign key.
     */
    protected ?string signKey = null;
    /**
     * @var mixed
     */
    protected value = null;

    /**
     * Phalcon\Http\Cookie constructor.
     */
    public function __construct(
         string name,
        var value = null,
        int expire = 0,
        string path = "/",
        bool secure = false,
        string domain = "",
        bool httpOnly = false,
        array options = []
    ) {
        let this->name     = name,
            this->expire   = expire,
            this->path     = path,
            this->secure   = secure,
            this->domain   = domain,
            this->httpOnly = httpOnly,
            this->options  = options;

        if value !== null {
            this->setValue(value);
        }
    }

    /**
     * Magic __toString method converts the cookie's value to string
     */
    public function __toString() -> string
    {
        return (string) this->getValue();
    }

    /**
     * Deletes the cookie by setting an expiration time in the past
     */
    public function delete() -> void
    {
        var options, session;

        let session = this->getStartedSession();

        if session !== null {
            session->remove(this->getSessionKey());
        }

        let this->value = null,
            options     = this->getCookieOptions(time() - 691200);

        setcookie(this->name, "", options);
    }

    /**
     * Returns the domain that the cookie is available to
     */
    public function getDomain() -> string
    {
        this->checkRestored();

        return this->domain;
    }

    /**
     * Returns the current expiration time
     */
    public function getExpiration() -> int
    {
        this->checkRestored();

        return this->expire;
    }

    /**
     * Returns if the cookie is accessible only through the HTTP protocol
     */
    public function getHttpOnly() -> bool
    {
        this->checkRestored();

        return this->httpOnly;
    }

    /**
     * Returns the current cookie's name
     */
    public function getName() -> string
    {
        return this->name;
    }

    /**
     * Returns the current cookie's options
     */
    public function getOptions() -> array
    {
        return this->options;
    }

    /**
     * Returns the current cookie's path
     */
    public function getPath() -> string
    {
        this->checkRestored();

        return this->path;
    }

    /**
     * Returns whether the cookie must only be sent when the connection is
     * secure (HTTPS)
     */
    public function getSecure() -> bool
    {
        this->checkRestored();

        return this->secure;
    }

    /**
     * Returns the cookie's value.
     *
     * @todo filters needs to be array/string
     */
    public function getValue(var filters = null, var defaultValue = null) -> var
    {
        var container, value, crypt, decryptedValue, filter, signKey, name;

        this->checkRestored();

        let container = null,
            name = this->name;

        if this->isRead === false {
            if !fetch value, _COOKIE[name] {
                return defaultValue;
            }

            if this->useEncryption {
                let container = <DiInterface> this->container;

                if container === null {
                    throw new CryptServiceUnavailable();
                }

                let crypt = <CryptInterface> container->getShared("crypt");

                if unlikely typeof crypt != "object" {
                    throw new CryptInterfaceRequired();
                }

                /**
                 * Verify the cookie's value if the sign key was set
                 */
                let signKey = this->signKey;

                if typeof signKey === "string" {
                    /**
                     * Decrypt the value also decoding it with base64
                     */
                    let decryptedValue = crypt->decryptBase64(
                        value,
                        signKey
                    );
                } else {
                    /**
                     * Decrypt the value also decoding it with base64
                     */
                    let decryptedValue = crypt->decryptBase64(value);
                }
            } else {
                let decryptedValue = value;
            }

            /**
             * Update the decrypted value
             */
            let this->value = decryptedValue;

            if filters !== null {
                let filter = this->filter;

                if typeof filter != "object" {
                    if container === null {
                        let container = <DiInterface> this->container;

                        if container === null {
                            throw new FilterServiceUnavailable();
                        }
                    }

                    let filter = <FilterInterface> container->getShared("filter"),
                        this->filter = filter;
                }

                return filter->sanitize(decryptedValue, filters);
            }

            /**
             * Return the value without filtering
             */
            return decryptedValue;
        }

        return this->value;
    }

    /**
     * Reads the cookie-related info from the SESSION to restore the cookie as
     * it was set.
     *
     * This method is automatically called internally so normally you don't
     * need to call it.
     */
    public function restore() -> <CookieInterface>
    {
        var definition, domain, expire, httpOnly, options, path,
            secure, session;

        if !this->isRestored {
            let session = this->getStartedSession();

            if session !== null {
                let definition = session->get(this->getSessionKey());

                if fetch expire, definition["expire"] {
                    let this->expire = expire;
                }

                if fetch domain, definition["domain"] {
                    let this->domain = domain;
                }

                if fetch path, definition["path"] {
                    let this->path = path;
                }

                if fetch secure, definition["secure"] {
                    let this->secure = secure;
                }

                if fetch httpOnly, definition["httpOnly"] {
                    let this->httpOnly = httpOnly;
                }

                if fetch options, definition["options"] {
                    let this->options = options;
                }
            }

            let this->isRestored = true;
        }

        return this;
    }

    /**
     * Sends the cookie to the HTTP client.
     *
     * Stores the cookie definition in session.
     */
    public function send() -> <CookieInterface>
    {
        var container, crypt, definition, encryptValue, expire, domain, httpOnly,
            name, options, path, secure, session, signKey, value;

        let name     = this->name,
            value    = this->value,
            expire   = this->expire,
            domain   = this->domain,
            path     = this->path,
            secure   = this->secure,
            httpOnly = this->httpOnly,
            options  = this->options;

        let container = this->container;

        let definition              = [],
            definition["expire"]   = expire,
            definition["path"]     = path,
            definition["domain"]   = domain,
            definition["secure"]   = secure,
            definition["httpOnly"] = httpOnly,
            definition["options"]  = options;

        /**
         * Remove all the empty elements
         */
        let definition = array_filter(definition);

        /**
         * The definition is stored in session
         */
        if !empty(definition) {
            let session = this->getStartedSession();

            if session !== null {
                session->set(this->getSessionKey(), definition);
            }
        }

        if this->useEncryption && !empty value {
            if container === null {
                throw new FilterServiceUnavailable();
            }

            let crypt = <CryptInterface> container->getShared("crypt");

            if unlikely typeof crypt !== "object" {
                throw new CryptInterfaceRequired();
            }

            /**
             * Encrypt the value also coding it with base64.
             * Sign the cookie's value if the sign key was set
             */
            let signKey = this->signKey;

            if typeof signKey === "string" {
                let encryptValue = crypt->encryptBase64(
                    (string) value,
                    signKey
                );
            } else {
                let encryptValue = crypt->encryptBase64(
                    (string) value
                );
            }
        } else {
            let encryptValue = value;
        }

        /**
         * Sets the cookie using the standard 'setcookie' function
         */
        let options = this->getCookieOptions(this->expire);

        setcookie(name, encryptValue, options);

        return this;
    }

    /**
     * Sets the domain that the cookie is available to
     */
    public function setDomain( string domain) -> <CookieInterface>
    {
        this->checkRestored();

        let this->domain = domain;

        return this;
    }

    /**
     * Sets the cookie's expiration time
     */
    public function setExpiration(int expire) -> <CookieInterface>
    {
        this->checkRestored();

        let this->expire = expire;

        return this;
    }

    /**
     * Sets if the cookie is accessible only through the HTTP protocol
     */
    public function setHttpOnly(bool httpOnly) -> <CookieInterface>
    {
        this->checkRestored();

        let this->httpOnly = httpOnly;

        return this;
    }

    /**
     * Sets the cookie's options
     */
    public function setOptions( array options) -> <CookieInterface>
    {
        let this->options = options;

        return this;
    }

    /**
     * Sets the cookie's path
     */
    public function setPath( string path) -> <CookieInterface>
    {
        this->checkRestored();

        let this->path = path;

        return this;
    }

    /**
     * Sets if the cookie must only be sent when the connection is secure
     * (HTTPS)
     */
    public function setSecure(bool secure) -> <CookieInterface>
    {
        this->checkRestored();

        let this->secure = secure;

        return this;
    }

    /**
     * Sets the cookie's sign key.
     *
     * The `$signKey' MUST be at least 32 characters long
     * and generated using a cryptographically secure pseudo random generator.
     *
     * Use NULL to disable cookie signing.
     *
     * @see \Phalcon\Encryption\Security\Random
     */
    public function setSignKey(string signKey = null) -> <CookieInterface>
    {
        if signKey !== null {
            this->assertSignKeyIsLongEnough(signKey);
        }

        let this->signKey = signKey;

        return this;
    }

    /**
     * Sets the cookie's value
     */
    public function setValue(value) -> <CookieInterface>
    {
        let this->value = value,
            this->isRead = true;

        return this;
    }

    /**
     * Sets if the cookie must be encrypted/decrypted automatically
     */
    public function useEncryption(bool useEncryption) -> <CookieInterface>
    {
        let this->useEncryption = useEncryption;

        return this;
    }

    /**
     * Assert the cookie's key is enough long.
     *
     * @throws \Phalcon\Http\Cookie\Exception
     */
    protected function assertSignKeyIsLongEnough( string signKey) -> void
    {
        var length;

        let length = mb_strlen(signKey);

        if unlikely length < 32 {
            throw new CookieKeyTooShort(length);
        }
    }

    /**
     * Check if the cookie is restored and restore it if not
     */
    private function checkRestored() -> void
    {
        if (true !== this->isRestored) {
            this->restore();
        }
    }

    private function getCookieOptions(int expiresDefault) -> array
    {
        array options;
        
        let options             = this->options;
        let options["expires"]  = this->getArrVal(options, "expires", expiresDefault);
        let options["domain"]   = this->getArrVal(options, "domain", this->domain);
        let options["path"]     = this->getArrVal(options, "path", this->path);
        let options["secure"]   = this->getArrVal(options, "secure", this->secure);
        let options["httponly"] = this->getArrVal(options, "httponly", this->httpOnly);

        return options;
    }

    /**
     * The session key under which this cookie's definition is stored
     */
    private function getSessionKey() -> string
    {
        return "_PHCOOKIE_" . this->name;
    }

    /**
     * Returns the session manager from the container when the service is
     * available and the session has been started; `null` otherwise
     */
    private function getStartedSession() -> <SessionManagerInterface> | null
    {
        var container, session;

        let container = this->container;

        if typeof container != "object" || !container->has("session") {
            return null;
        }

        let session = <SessionManagerInterface> container->getShared("session");

        if !session->exists() {
            return null;
        }

        return session;
    }
}
