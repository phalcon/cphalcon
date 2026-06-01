
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

namespace Phalcon\Auth\Guard;

use Phalcon\Contracts\Auth\Adapter\Adapter;
use Phalcon\Contracts\Auth\AuthUser;
use Phalcon\Contracts\Auth\Guard\Guard;
use Phalcon\Contracts\Auth\Guard\GuardConfig;
use Phalcon\Events\AbstractEventsAware;

/**
 * @phpstan-import-type AuthCredentials from Adapter
 *
 * @template TConfig of GuardConfig
 */
abstract class AbstractGuard extends AbstractEventsAware implements Guard
{
    /**
     * @var Adapter
     */
    protected adapter;
    /**
     * @var GuardConfig
     */
    protected config;
    /**
     * @var AuthUser | null
     */
    protected lastUserAttempted = null;
    /**
     * @var AuthUser | null
     */
    protected user = null;

    /**
     * @phpstan-param TConfig $config
     */
    public function __construct(<Adapter> adapter, <GuardConfig> config)
    {
        let this->adapter = adapter;
        let this->config  = config;
    }

    /**
     * Returns the guard configuration object.
     *
     * @phpstan-return TConfig
     */
    public function getConfig() -> <GuardConfig>
    {
        return this->config;
    }

    public function check() -> bool
    {
        return this->user() !== null;
    }

    public function getAdapter() -> <Adapter>
    {
        return this->adapter;
    }

    public function getLastUserAttempted() -> <AuthUser> | null
    {
        return this->lastUserAttempted;
    }

    public function guest() -> bool
    {
        return !this->check();
    }

    public function hasUser() -> bool
    {
        return this->user !== null;
    }

    public function id() -> int | string | null
    {
        var current;

        let current = this->user();

        if (current === null) {
            return null;
        }

        return current->getAuthIdentifier();
    }

    public function setAdapter(<Adapter> adapter) -> <static>
    {
        let this->adapter = adapter;

        return this;
    }

    public function setUser(<AuthUser> user) -> <static>
    {
        let this->user = user;

        return this;
    }

    /**
     * @phpstan-param AuthCredentials $credentials
     *
     * @phpstan-assert-if-true !null $user
     */
    protected function hasValidCredentials(<AuthUser> user = null, array credentials) -> bool
    {
        if (user === null) {
            return false;
        }

        return this->adapter->validateCredentials(user, credentials);
    }
}
