
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

use Phalcon\Auth\Adapter\Config\ModelAdapterConfig;
use Phalcon\Auth\Exception;
use Phalcon\Auth\Exceptions\DoesNotImplement;
use Phalcon\Auth\Internal\Options;
use Phalcon\Contracts\Auth\Adapter\RememberAdapter;
use Phalcon\Contracts\Auth\AuthRemember;
use Phalcon\Contracts\Auth\AuthUser;
use Phalcon\Contracts\Auth\RememberToken;
use Phalcon\Contracts\Encryption\Security\Security;
use Phalcon\Mvc\ModelInterface;

/**
 * Phalcon Model-backed adapter.
 *
 * @phpstan-import-type AuthCredentials from \Phalcon\Contracts\Auth\Adapter\Adapter
 *
 * @extends AbstractAdapter<ModelAdapterConfig>
 */
class Model extends AbstractAdapter implements RememberAdapter
{
    public function __construct(<Security> hasher, <ModelAdapterConfig> config)
    {
        parent::__construct(hasher, config);
    }

    public static function fromOptions(<Security> hasher, array options) -> <static>
    {
        var idColumn;
        let idColumn = Options::stringOrNull(options, "idColumn");

        return new static(
            hasher,
            new ModelAdapterConfig(
                Options::requireString(options, "model", "model adapter"),
                idColumn !== null ? idColumn : "id"
            )
        );
    }

    /**
     * Create and persist a new remember token for the user.
     *
     * @throws Exception
     */
    public function createRememberToken(<AuthUser> user) -> <RememberToken>
    {
        if (!(user instanceof AuthRemember)) {
            throw new DoesNotImplement("User model", "AuthRemember");
        }

        return user->createRememberToken(bin2hex(random_bytes(30)));
    }

    /**
     * Find a user matching the given credentials (excluding 'password' key).
     *
     * @phpstan-param AuthCredentials $credentials
     */
    public function retrieveByCredentials(array credentials) -> <AuthUser> | null
    {
        var found, key, modelClass, value;
        array bind, conditions;

        /** @var class-string<ModelInterface> $modelClass */
        let modelClass = this->config->getModel();
        let conditions = [];
        let bind       = [];

        for key, value in credentials {
            if (key === "password") {
                continue;
            }

            let conditions[] = "[" . key . "] = :" . key . ":";
            let bind[key]    = value;
        }

        if (empty(conditions)) {
            return null;
        }

        let found = {modelClass}::findFirst(
            [
                "conditions" : join(" AND ", conditions),
                "bind"       : bind
            ]
        );

        if (found === false) {
            return null;
        }

        /** @var AuthUser $found */
        return found;
    }

    public function retrieveById(var id) -> <AuthUser> | null
    {
        if (typeof id !== "int" && typeof id !== "string") {
            throw new \TypeError("The parameter must be 'int' or 'string'");
        }

        var found, idColumn, modelClass;

        /** @var class-string<ModelInterface> $modelClass */
        let modelClass = this->config->getModel();
        let idColumn   = this->config->getIdColumn();
        let found      = {modelClass}::findFirst(
            [
                "conditions" : "[" . idColumn . "] = :id:",
                "bind"       : ["id" : id]
            ]
        );

        if (found === false) {
            return null;
        }

        /** @var AuthUser $found */
        return found;
    }

    /**
     * Retrieve a user by the remember-me cookie payload.
     */
    public function retrieveByToken(
        var id,
        string token,
        string userAgent = null
    ) -> <AuthUser> | null {
        var tokenRow, user;

        let user = this->retrieveById(id);

        if (user === null) {
            return null;
        }

        if (!(user instanceof AuthRemember)) {
            return null;
        }

        /** @var AuthUser&AuthRemember $user */
        let tokenRow = user->getRememberToken(token);

        if (tokenRow === null) {
            return null;
        }

        if (userAgent !== null && tokenRow->getUserAgent() !== userAgent) {
            return null;
        }

        return user;
    }
}
