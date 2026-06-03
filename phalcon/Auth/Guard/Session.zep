
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

use Phalcon\Auth\Exception;
use Phalcon\Auth\Exceptions\DoesNotImplement;
use Phalcon\Auth\Guard\Config\SessionGuardConfig;
use Phalcon\Auth\Internal\Options;
use Phalcon\Contracts\Auth\Adapter\Adapter;
use Phalcon\Contracts\Auth\Adapter\RememberAdapter;
use Phalcon\Contracts\Auth\AuthRemember;
use Phalcon\Contracts\Auth\AuthUser;
use Phalcon\Contracts\Auth\Guard\BasicAuth;
use Phalcon\Contracts\Auth\Guard\GuardStateful;
use Phalcon\Contracts\Auth\RememberToken;
use Phalcon\Contracts\Container\Service\Collection;
use Phalcon\Http\RequestInterface;
use Phalcon\Http\Response\CookiesInterface;
use Phalcon\Session\ManagerInterface as SessionManagerInterface;
use Phalcon\Support\Helper\Json\Encode;

/**
 * @phpstan-import-type AuthCredentials from Adapter
 *
 * @extends AbstractGuard<SessionGuardConfig>
 */
class Session extends AbstractGuard implements GuardStateful, BasicAuth
{
    /**
     * @var CookiesInterface
     */
    protected cookies;
    /**
     * @var RequestInterface
     */
    protected request;
    /**
     * @var SessionManagerInterface
     */
    protected session;
    /**
     * @var bool
     */
    protected viaRemember = false;

    public function __construct(
        <Adapter> adapter,
        <RequestInterface> request,
        <CookiesInterface> cookies,
        <SessionManagerInterface> session,
        <SessionGuardConfig> config = null
    ) {
        let this->request = request;
        let this->cookies = cookies;
        let this->session = session;

        if (config === null) {
            let config = new SessionGuardConfig();
        }

        parent::__construct(adapter, config);
    }

    public static function fromOptions(
        <Adapter> adapter,
        <Collection> container,
        array options
    ) -> <static> {
        var config;

        let config = new SessionGuardConfig(
            Options::stringOrNull(options, "suffix"),
            Options::stringOrNull(options, "name"),
            Options::stringOrNull(options, "rememberName")
        );

        return new static(
            adapter,
            Options::resolveService(container, "Phalcon\\Http\\RequestInterface", "Session guard"),
            Options::resolveService(container, "Phalcon\\Http\\Response\\CookiesInterface", "Session guard"),
            Options::resolveService(container, "Phalcon\\Session\\ManagerInterface", "Session guard"),
            config
        );
    }

    /**
     * @phpstan-param AuthCredentials $credentials
     *
     * @throws Exception
     */
    public function attempt(array credentials = [], bool remember = false) -> bool
    {
        var resolved;

        let resolved                = this->adapter->retrieveByCredentials(credentials);
        let this->lastUserAttempted = resolved;

        if (this->hasValidCredentials(resolved, credentials)) {
            this->login(resolved, remember);

            return true;
        }

        return false;
    }

    /**
     * @param array<string, mixed> $extraConditions
     *
     * @throws Exception
     */
    public function basic(string field = "email", array extraConditions = []) -> bool
    {
        if (this->check()) {
            return true;
        }

        return this->attemptBasic(field, extraConditions);
    }

    public function getName() -> string
    {
        return this->config->getName();
    }

    public function getRememberName() -> string
    {
        return this->config->getRememberName();
    }

    /**
     * @throws Exception
     */
    public function login(<AuthUser> user, bool remember = false) -> void
    {
        this->fireManagerEvent("auth:beforeLogin");

        this->session->set(this->getName(), user->getAuthIdentifier());

        if (remember) {
            if (!(this->adapter instanceof RememberAdapter)) {
                throw new DoesNotImplement("Adapter", "RememberAdapter");
            }
            this->rememberUser(user);
        }

        this->setUser(user);

        this->fireManagerEvent("auth:afterLogin");
    }

    /**
     * @throws Exception
     */
    public function loginById(var id, bool remember = false) -> false | <AuthUser>
    {
        if (typeof id !== "int" && typeof id !== "string") {
            throw new \TypeError("The parameter must be 'int' or 'string'");
        }

        var resolved;

        let resolved = this->adapter->retrieveById(id);
        if (resolved === null) {
            return false;
        }

        this->login(resolved, remember);

        return resolved;
    }

    public function logout() -> void
    {
        var current, recaller, token, tokenRow;

        let current = this->user();

        this->fireManagerEvent("auth:beforeLogout", ["user" : current]);

        let recaller = this->recaller();
        if (recaller !== null && current instanceof AuthRemember) {
            let token    = recaller->getToken();
            let tokenRow = current->getRememberToken(token);
            if (typeof tokenRow === "object") {
                tokenRow->delete();
            }

            if (this->cookies->has(this->getRememberName())) {
                this->cookies->delete(this->getRememberName());
            }
        }

        this->session->remove(this->getName());

        this->fireManagerEvent("auth:afterLogout", ["user" : current]);

        let this->user = null;
    }

    /**
     * @phpstan-param AuthCredentials $credentials
     */
    public function once(array credentials = []) -> bool
    {
        this->fireManagerEvent("auth:beforeLogin");

        if (this->validate(credentials)) {
            this->setUser(this->lastUserAttempted);
            this->fireManagerEvent("auth:afterLogin");

            return true;
        }

        return false;
    }

    /**
     * @param array<string, mixed> $extraConditions
     */
    public function onceBasic(
        string field = "email",
        array extraConditions = []
    ) -> false | <AuthUser> {
        var credentials, user;

        let credentials = this->basicCredentials(field);
        if (credentials === null) {
            return false;
        }

        if (this->once(array_merge(credentials, extraConditions))) {
            /** @var AuthUser $user (non-null after successful once()) */
            let user = this->user;

            return user;
        }

        return false;
    }

    public function user() -> <AuthUser> | null
    {
        var fromRecaller, id, recaller;

        if (this->user !== null) {
            return this->user;
        }

        let id = this->session->get(this->getName());
        if (typeof id === "int" || typeof id === "string") {
            let this->user = this->adapter->retrieveById(id);
        }

        let recaller = this->recaller();
        if (this->user === null && recaller !== null) {
            let fromRecaller = this->userFromRecaller(recaller);
            if (fromRecaller !== null) {
                let this->user = fromRecaller;
                this->session->set(this->getName(), fromRecaller->getAuthIdentifier());
            }
        }

        return this->user;
    }

    /**
     * @phpstan-param AuthCredentials $credentials
     *
     * @phpstan-assert-if-true !null $this->lastUserAttempted
     */
    public function validate(array credentials = []) -> bool
    {
        var resolved;

        let resolved                = this->adapter->retrieveByCredentials(credentials);
        let this->lastUserAttempted = resolved;

        return this->hasValidCredentials(resolved, credentials);
    }

    public function viaRemember() -> bool
    {
        return this->viaRemember;
    }

    /**
     * @param array<string, mixed> $extraConditions
     *
     * @throws Exception
     */
    protected function attemptBasic(string field, array extraConditions = []) -> bool
    {
        var credentials;

        let credentials = this->basicCredentials(field);
        if (credentials === null) {
            return false;
        }

        return this->attempt(array_merge(credentials, extraConditions));
    }

    /**
     * @return array<string, mixed>|null
     */
    protected function basicCredentials(string field) -> array | null
    {
        var basic;

        let basic = this->request->getBasicAuth();
        if (basic === null) {
            return null;
        }

        return [
            field      : basic["username"],
            "password" : basic["password"]
        ];
    }

    protected function createRememberToken(<AuthUser> user) -> <RememberToken>
    {
        var adapter;
        /** @var RememberAdapter $adapter */
        let adapter = this->adapter;

        return adapter->createRememberToken(user);
    }

    protected function recaller() -> <UserRemember> | null
    {
        var raw;

        if (!this->cookies->has(this->getRememberName())) {
            return null;
        }

        let raw = this->cookies->get(this->getRememberName())->getValue();
        if (empty(raw)) {
            return null;
        }

        if (typeof raw === "string") {
            return new UserRemember(raw);
        }

        if (typeof raw !== "array") {
            return null;
        }

        /** @var array<string, mixed> $raw */
        return new UserRemember(raw);
    }

    protected function rememberUser(<AuthUser> user) -> void
    {
        var agent, payload, token;

        let token = this->createRememberToken(user);

        let agent   = (string) this->request->getUserAgent();
        let payload = (new Encode())->__invoke(
            [
                "id"         : user->getAuthIdentifier(),
                "token"      : token->getToken(),
                "user_agent" : agent
            ],
            JSON_THROW_ON_ERROR
        );

        this->cookies->set(
            this->getRememberName(),
            payload,
            time() + 360 * 24 * 60 * 60
        );
    }

    protected function userFromRecaller(<UserRemember> recaller) -> <AuthUser> | null
    {
        var id, resolved;

        if (!(this->adapter instanceof RememberAdapter)) {
            return null;
        }

        let id = recaller->getId();
        if (id === null) {
            return null;
        }

        let resolved = this->adapter->retrieveByToken(
            id,
            recaller->getToken(),
            recaller->getUserAgent()
        );

        let this->viaRemember = resolved !== null;

        return resolved;
    }
}
