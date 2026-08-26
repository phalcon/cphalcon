
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by sinbadxiii/cphalcon-auth
 * @link    https://github.com/sinbadxiii/cphalcon-auth
 */

namespace Phalcon\Auth\Guard\Config;

use Phalcon\Auth\Exception;
use Phalcon\Auth\Exceptions\ConfigRequiresNonEmptyValue;
use Phalcon\Auth\Exceptions\SessionNamesMustDiffer;

/**
 * Configuration for the Session guard. Holds the names under which the
 * session key and remember-me cookie are stored. Defaults to 'auth' and
 * 'remember'; multi-guard apps can pass a $suffix ('web', 'admin', ...)
 * to derive 'auth_web' / 'remember_web' style names, or override either
 * full name explicitly.
 */
class SessionGuardConfig extends AbstractGuardConfig
{
    /**
     * Default remember-me cookie lifetime, in seconds (365 days).
     *
     * @var int
     */
    const DEFAULT_REMEMBER_TTL = 31536000;

    private string name;
    private string rememberName;
    private bool rememberSecure;
    private int rememberTtl;

    /**
     * @throws Exception
     */
    public function __construct(
        string suffix = null,
        string name = null,
        string rememberName = null,
        int rememberTtl = null,
        bool rememberSecure = true
    ) {
        this->validateNonEmpty("suffix", suffix);
        this->validateNonEmpty("name", name);
        this->validateNonEmpty("rememberName", rememberName);

        let this->name         = null !== name ? name : this->derive("auth", suffix);
        let this->rememberName = null !== rememberName ? rememberName : this->derive("remember", suffix);
        let this->rememberTtl  = null !== rememberTtl ? rememberTtl : self::DEFAULT_REMEMBER_TTL;
        let this->rememberSecure = rememberSecure;

        if (this->name === this->rememberName) {
            throw new SessionNamesMustDiffer();
        }
    }

    public function getName() -> string
    {
        return this->name;
    }

    public function getRememberName() -> string
    {
        return this->rememberName;
    }

    /**
     * Whether the remember-me cookie carries the Secure flag. Defaults to
     * true: the cookie is a bearer credential. Set it to false only for a
     * deployment that serves plain HTTP on purpose.
     */
    public function getRememberSecure() -> bool
    {
        return this->rememberSecure;
    }

    public function getRememberTtl() -> int
    {
        return this->rememberTtl;
    }

    private function derive(string prefix, string suffix = null) -> string
    {
        return suffix === null ? prefix : (prefix . "_" . suffix);
    }

    /**
     * @throws Exception
     */
    private function validateNonEmpty(string param, string value = null) -> void
    {
        ConfigRequiresNonEmptyValue::assert(value, "Session guard", param);
    }
}
