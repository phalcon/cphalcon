
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Http\Response;

use Phalcon\Di\DiInterface;
use Phalcon\Di\AbstractInjectionAware;
use Phalcon\Http\Cookie\Exception;
use Phalcon\Http\Cookie\CookieInterface;

/**
 * Phalcon\Http\Response\Cookies
 *
 * This class is a bag to manage the cookies.
 *
 * A cookies bag is automatically registered as part of the 'response' service
 * in the DI. By default, cookies are automatically encrypted before being sent
 * to the client and are decrypted when retrieved from the user. To set sign key
 * used to generate a message authentication code use
 * `Phalcon\Http\Response\Cookies::setSignKey()`.
 *
 * ```php
 * use Phalcon\Di;
 * use Phalcon\Crypt;
 * use Phalcon\Http\Response\Cookies;
 *
 * $di = new Di();
 *
 * $di->set(
 *     'crypt',
 *     function () {
 *         $crypt = new Crypt();
 *
 *         // The `$key' should have been previously generated in a cryptographically safe way.
 *         $key = "T4\xb1\x8d\xa9\x98\x05\\\x8c\xbe\x1d\x07&[\x99\x18\xa4~Lc1\xbeW\xb3";
 *
 *         $crypt->setKey($key);
 *
 *         return $crypt;
 *     }
 * );
 *
 * $di->set(
 *     'cookies',
 *     function () {
 *         $cookies = new Cookies();
 *
 *         // The `$key' MUST be at least 32 characters long and generated using a
 *         // cryptographically secure pseudo random generator.
 *         $key = "#1dj8$=dp?.ak//j1V$~%*0XaK\xb1\x8d\xa9\x98\x054t7w!z%C*F-Jk\x98\x05\\\x5c";
 *
 *         $cookies->setSignKey($key);
 *
 *         return $cookies;
 *     }
 * );
 * ```
 */
class Cookies extends AbstractInjectionAware implements CookiesInterface
{
    protected cookies = [];

    protected registered = false;

    /**
     * The cookie's sign key.
     * @var string|null
     */
    protected signKey = null;

    protected useEncryption = true;

    /**
     * Phalcon\Http\Response\Cookies constructor
     */
    public function __construct(bool useEncryption = true, string signKey = null)
    {
        let this->useEncryption = useEncryption;

        this->setSignKey(signKey);
    }

    /**
     * Deletes a cookie by its name
     * This method does not removes cookies from the _COOKIE superglobal
     */
    public function delete(string! name) -> bool
    {
        var cookie;

        /**
         * Check the internal bag
         */
        if !fetch cookie, this->cookies[name] {
            return false;
        }

        cookie->delete();

        return true;
    }

    /**
     * Gets a cookie from the bag
     */
    public function get(string! name) -> <CookieInterface>
    {
        var container, encryption, cookie;

        /**
         * Gets cookie from the cookies service. They will be sent with response.
         */
        if fetch cookie, this->cookies[name] {
            return cookie;
        }

        /**
         * Create the cookie if the it does not exist.
         * It's value come from $_COOKIE with request, so it shouldn't be saved
         * to _cookies property, otherwise it will always be resent after get.
         */
        let cookie = <CookieInterface> this->container->get("Phalcon\\Http\\Cookie", [name]),
            container = this->container;

        if typeof container == "object" {
            /**
             * Pass the DI to created cookies
             */
            cookie->setDi(container);

            let encryption = this->useEncryption;

            /**
             * Enable encryption in the cookie
             */
            if encryption {
                cookie->useEncryption(encryption);
                cookie->setSignKey(this->signKey);
            }
        }

        return cookie;
    }

    /**
     * Gets all cookies from the bag
     */
    public function getCookies() -> array
    {
        return this->cookies;
    }

    /**
     * Check if a cookie is defined in the bag or exists in the _COOKIE
     * superglobal
     */
    public function has(string! name) -> bool
    {
        return isset this->cookies[name] || isset _COOKIE[name];
    }

    /**
     * Returns if the bag is automatically encrypting/decrypting cookies
     */
    public function isUsingEncryption() -> bool
    {
        return this->useEncryption;
    }

    /**
     * Reset set cookies
     */
    public function reset() -> <CookiesInterface>
    {
        let this->cookies = [];

        return this;
    }

    /**
     * Sends the cookies to the client
     * Cookies aren't sent if headers are sent in the current request
     */
    public function send() -> bool
    {
        var cookie;

        if headers_sent() {
            return false;
        }

        for cookie in this->cookies {
            cookie->send();
        }

        return true;
    }

    /**
     * Sets a cookie to be sent at the end of the request.
     *
     * This method overrides any cookie set before with the same name.
     *
     * ```php
     * use Phalcon\Http\Response\Cookies;
     *
     * $now = new DateTimeImmutable();
     * $tomorrow = $now->modify('tomorrow');
     *
     * $cookies = new Cookies();
     * $cookies->set(
     *     'remember-me',
     *     json_encode(['user_id' => 1]),
     *     (int) $tomorrow->format('U'),
     * );
     * ```
     */
    public function set(
        string! name,
        value = null,
        int expire = 0,
        string path = "/",
        bool secure = null,
        string! domain = null,
        bool httpOnly = null
    ) -> <CookiesInterface> {
        var cookie, encryption, container, response;

        let encryption = this->useEncryption;

        /**
         * Check if the cookie needs to be updated or
         */
        if !fetch cookie, this->cookies[name] {
            let cookie =
                <CookieInterface> this->container->get(
                    "Phalcon\\Http\\Cookie",
                    [name, value, expire, path, secure, domain, httpOnly]
                );

            /**
             * Pass the DI to created cookies
             */
            cookie->setDi(this->container);

            /**
             * Enable encryption in the cookie
             */
            if encryption {
                cookie->useEncryption(encryption);

                cookie->setSignKey(this->signKey);
            }

            let this->cookies[name] = cookie;
        } else {
            /**
             * Override any settings in the cookie
             */
            cookie->setValue(value);
            cookie->setExpiration(expire);
            cookie->setPath(path);
            cookie->setSecure(secure);
            cookie->setDomain(domain);
            cookie->setHttpOnly(httpOnly);
            cookie->setSignKey(this->signKey);
        }

        /**
         * Register the cookies bag in the response
         */
        if this->registered === false {
            let container = this->container;

            if unlikely typeof container != "object" {
                throw new Exception(
                    Exception::containerServiceNotFound(
                        "the 'response' service"
                    )
                );
            }

            let response = container->getShared("response");

            /**
             * Pass the cookies bag to the response so it can send the headers
             * at the of the request
             */
            response->setCookies(this);

            let this->registered = true;
        }

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
     * @see \Phalcon\Security\Random
     */
    public function setSignKey(string signKey = null) -> <CookieInterface>
    {
        let this->signKey = signKey;

        return this;
    }

    /**
     * Set if cookies in the bag must be automatically encrypted/decrypted
     */
    public function useEncryption(bool useEncryption) -> <CookiesInterface>
    {
        let this->useEncryption = useEncryption;

        return this;
    }
}
