
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

namespace Phalcon\Auth\Adapter;

use Phalcon\Contracts\Auth\Adapter\Adapter;
use Phalcon\Contracts\Auth\Adapter\AdapterConfig;
use Phalcon\Contracts\Auth\AuthUser;
use Phalcon\Contracts\Encryption\Security\Security;

/**
 * @phpstan-import-type AuthCredentials from Adapter
 *
 * @template TConfig of AdapterConfig
 */
abstract class AbstractAdapter implements Adapter
{
    /**
     * Dummy bcrypt hash used to equalize timing on the user-not-found path so
     * a failed lookup costs the same as a real password check (prevents
     * login-timing user enumeration).
     *
     * @var string
     */
    const DUMMY_HASH = "$2y$10$YMmGMSXz.5U3bjjJ2qx45uElzUrlaBiS8L70VaVnmsKYFJVcam8gW";

    /**
     * @var AdapterConfig
     */
    protected config;

    /**
     * @var Security
     */
    protected hasher;

    /**
     * @phpstan-param TConfig $config
     */
    public function __construct(<Security> hasher, <AdapterConfig> config)
    {
        let this->hasher = hasher;
        let this->config = config;
    }

    /**
     * Returns the adapter configuration object.
     *
     * @phpstan-return TConfig
     */
    public function getConfig() -> <AdapterConfig>
    {
        return this->config;
    }

    /**
     * Returns the model class name, if configured.
     */
    public function getModel() -> string | null
    {
        return this->config->getModel();
    }

    /**
     * Validates the supplied plaintext password against the user's stored hash.
     * Concrete adapters share this implementation; if your data source needs
     * a different verification strategy, override it.
     *
     * @phpstan-param AuthCredentials $credentials
     */
    public function validateCredentials(<AuthUser> user, array credentials) -> bool
    {
        var password;

        if !fetch password, credentials["password"] {
            return false;
        }

        return this->hasher->checkHash(password, user->getAuthPassword());
    }

    /**
     * Runs a throwaway password verification against a fixed dummy hash so the
     * user-not-found path performs the same hash work as a found path. Call it
     * when a credential lookup misses to keep response time constant.
     */
    protected function burnHash() -> void
    {
        this->hasher->checkHash("phalcon-auth-timing", self::DUMMY_HASH);
    }
}
