
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

use Phalcon\Auth\Guard\Config\TokenGuardConfig;
use Phalcon\Auth\Internal\Options;
use Phalcon\Contracts\Auth\Adapter\Adapter;
use Phalcon\Contracts\Auth\AuthUser;
use Phalcon\Contracts\Container\Service\Collection;
use Phalcon\Di\DiInterface;
use Phalcon\Http\RequestInterface;

/**
 * @phpstan-import-type AuthCredentials from Adapter
 *
 * @extends AbstractGuard<TokenGuardConfig>
 */
class Token extends AbstractGuard
{
    /**
     * @var RequestInterface
     */
    protected request;

    public function __construct(
        <Adapter> adapter,
        <RequestInterface> request,
        <TokenGuardConfig> config
    ) {
        let this->request = request;

        parent::__construct(adapter, config);
    }

    public static function fromOptions(
        <Adapter> adapter,
        var container,
        array options
    ) -> <static> {
        if (!(container instanceof Collection) && !(container instanceof DiInterface)) {
            throw new \TypeError("The parameter must be an instance of Collection or DiInterface");
        }

        return new static(
            adapter,
            Options::resolveService(container, "Phalcon\\Http\\RequestInterface", "Token guard"),
            new TokenGuardConfig(
                Options::requireString(options, "inputKey", "token guard"),
                Options::requireString(options, "storageKey", "token guard")
            )
        );
    }

    public function getTokenForRequest() -> string | null
    {
        var bearer, header, token;

        let token = this->request->get(this->config->getInputKey(), null, null);

        if (typeof token === "string" && token !== "") {
            return token;
        }

        let header = (string) this->request->getHeader("Authorization");
        if (header !== "" && starts_with(header, "Bearer ")) {
            let bearer = mb_substr(header, 7, null, "UTF-8");
            if (bearer !== "") {
                return bearer;
            }
        }

        return null;
    }

    public function setRequest(<RequestInterface> request) -> <static>
    {
        let this->request = request;

        return this;
    }

    public function user() -> <AuthUser> | null
    {
        var found, token;

        if (this->user !== null) {
            return this->user;
        }

        let token = this->getTokenForRequest();
        if (token === null) {
            return null;
        }

        let found = this->adapter->retrieveByCredentials(
            [
                this->config->getStorageKey() : token
            ]
        );

        if (found !== null) {
            let this->user = found;
        }

        return this->user;
    }

    /**
     * @phpstan-param AuthCredentials $credentials
     */
    public function validate(array credentials = []) -> bool
    {
        var inputKey, token;

        let inputKey = this->config->getInputKey();

        if (!isset(credentials[inputKey])) {
            return false;
        }

        let token = credentials[inputKey];

        return this->adapter->retrieveByCredentials(
            [
                this->config->getStorageKey() : token
            ]
        ) !== null;
    }
}
