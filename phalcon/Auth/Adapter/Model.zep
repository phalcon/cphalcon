
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
        DoesNotImplement::assert(
            user,
            "Phalcon\\Contracts\\Auth\\AuthRemember",
            "User model",
            "AuthRemember"
        );

        return user->createRememberToken(bin2hex(random_bytes(30)));
    }

    /**
     * Find a user matching the given credentials (excluding 'password' key).
     *
     * @phpstan-param AuthCredentials $credentials
     */
    public function retrieveByCredentials(array credentials) -> <AuthUser> | null
    {
        var key, value, found;
        array bind, conditions;

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

        let found = this->findFirstAsAuthUser(
            [
                "conditions" : join(" AND ", conditions),
                "bind"       : bind
            ]
        );

        if (found === null) {
            this->burnHash();
        }

        return found;
    }

    public function retrieveById(var id) -> <AuthUser> | null
    {
        if (typeof id !== "int" && typeof id !== "string") {
            throw new \TypeError("The parameter must be 'int' or 'string'");
        }

        return this->findFirstAsAuthUser(
            [
                "conditions" : "[" . this->config->getIdColumn() . "] = :id:",
                "bind"       : ["id" : id]
            ]
        );
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

    /**
     * Runs findFirst() with the given parameters and normalizes the result to
     * an ?AuthUser: a missing record yields null, a record that is not an
     * AuthUser throws.
     *
     * @param array{conditions: string, bind: array<string, mixed>} $parameters
     *
     * @throws DoesNotImplement
     */
    private function findFirstAsAuthUser(array parameters) -> <AuthUser> | null
    {
        var found, modelClass;

        /** @var class-string<ModelInterface> $modelClass */
        let modelClass = this->config->getModel();

        let found = {modelClass}::findFirst(parameters);

        if (found === null) {
            return null;
        }

        DoesNotImplement::assert(
            found,
            "Phalcon\\Contracts\\Auth\\AuthUser",
            "User model",
            "AuthUser"
        );

        return found;
    }
}
