
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

use Phalcon\Auth\AuthUser;
use Phalcon\Contracts\Auth\Adapter\AdapterConfig;
use Phalcon\Contracts\Auth\AuthUser as AuthUserContract;

/**
 * Common base for adapters whose user records come from an in-memory list
 * (Memory and Stream). Subclasses provide the row source via loadUsers();
 * everything else - credentials matching, hydration, the empty-credentials
 * guard, and a default linear retrieveById - is shared here.
 *
 * @phpstan-import-type AuthCredentials from \Phalcon\Contracts\Auth\Adapter\Adapter
 * @phpstan-type AuthUserRow array{id?: int|string}&array<string, mixed>
 *
 * @template TConfig of AdapterConfig
 * @extends AbstractAdapter<TConfig>
 */
abstract class AbstractArrayAdapter extends AbstractAdapter
{
    /**
     * Walks the user list and returns the first row whose non-'password'
     * keys all match strictly. Returns null when no row matches or when
     * $credentials carries no identifying field at all (only 'password',
     * or empty) - protects callers from the silent "first row wins" footgun.
     *
     * @phpstan-param AuthCredentials $credentials
     */
    public function retrieveByCredentials(array credentials) -> <AuthUserContract> | null
    {
        var row;

        if (!this->hasIdentifyingField(credentials)) {
            return null;
        }

        for row in this->loadUsers() {
            if (this->matchesRow(row, credentials)) {
                return this->hydrate(row);
            }
        }

        return null;
    }

    /**
     * Default linear-scan implementation. Memory overrides this for an O(1)
     * id-keyed lookup; Stream uses this as-is.
     */
    public function retrieveById(var id) -> <AuthUserContract> | null
    {
        if (typeof id !== "int" && typeof id !== "string") {
            throw new \TypeError("The parameter must be 'int' or 'string'");
        }

        var row;

        for row in this->loadUsers() {
            if (isset(row["id"]) && row["id"] === id) {
                return this->hydrate(row);
            }
        }

        return null;
    }

    /**
     * Tests whether a credentials payload carries at least one identifying
     * field (i.e. anything other than 'password'). An empty payload - or a
     * payload that only contains 'password' - is treated as "no lookup".
     *
     * @phpstan-param AuthCredentials $credentials
     */
    protected function hasIdentifyingField(array credentials) -> bool
    {
        var key, value;

        for key, value in credentials {
            if (key !== "password") {
                return true;
            }
        }

        return false;
    }

    /**
     * Hydrates a raw user row into either the configured model class or a
     * Phalcon\Auth\AuthUser value object.
     *
     * @phpstan-param AuthUserRow $row
     */
    protected function hydrate(array row) -> <AuthUserContract>
    {
        var instance, modelClass;

        let modelClass = this->config->getModel();

        if (modelClass !== null) {
            let instance = new {modelClass}();

            if (method_exists(instance, "assign")) {
                instance->assign(row);
            }

            /** @var AuthUserContract $instance */
            return instance;
        }

        return new AuthUser(row);
    }

    /**
     * Returns the source list of user rows. Concrete subclasses decide
     * where they come from (config array, JSON file, etc.).
     *
     * @phpstan-return list<AuthUserRow>
     */
    abstract protected function loadUsers() -> array;

    /**
     * Strict per-key match of a row against credentials, skipping 'password'.
     *
     * @phpstan-param AuthUserRow     $row
     * @phpstan-param AuthCredentials $credentials
     */
    protected function matchesRow(array row, array credentials) -> bool
    {
        var key, value;

        for key, value in credentials {
            if (key === "password") {
                continue;
            }

            if (!isset(row[key]) || row[key] !== value) {
                return false;
            }
        }

        return true;
    }
}
