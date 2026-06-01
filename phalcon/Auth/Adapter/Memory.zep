
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

use Phalcon\Auth\Adapter\Config\MemoryAdapterConfig;
use Phalcon\Auth\Internal\Options;
use Phalcon\Contracts\Auth\AuthUser;
use Phalcon\Contracts\Encryption\Security\Security;

/**
 * In-memory adapter — useful for tests and small read-only user lists.
 *
 * @phpstan-import-type AuthUserRow from AbstractArrayAdapter
 *
 * @extends AbstractArrayAdapter<MemoryAdapterConfig>
 */
class Memory extends AbstractArrayAdapter
{
    /**
     * Map of id => user row for O(1) retrieveById lookup.
     *
     * @phpstan-var array<int|string, AuthUserRow>
     * @var array
     */
    private idStore = [];

    public function __construct(<Security> hasher, <MemoryAdapterConfig> config)
    {
        var row;

        parent::__construct(hasher, config);

        for row in this->loadUsers() {
            if (isset(row["id"])) {
                let this->idStore[row["id"]] = row;
            }
        }
    }

    public static function fromOptions(<Security> hasher, array options) -> <static>
    {
        return new static(
            hasher,
            new MemoryAdapterConfig(
                Options::arrayOption(options, "users", []),
                Options::stringOrNull(options, "model")
            )
        );
    }

    /**
     * Overridden for O(1) lookup via the id index built in the constructor.
     */
    public function retrieveById(var id) -> <AuthUser> | null
    {
        if (typeof id !== "int" && typeof id !== "string") {
            throw new TypeError("The parameter must be 'int' or 'string'");
        }

        if (!isset(this->idStore[id])) {
            return null;
        }

        return this->hydrate(this->idStore[id]);
    }

    protected function loadUsers() -> array
    {
        return this->config->getUsers();
    }
}
