
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Acl\Adapter;

use Phalcon\Acl\Enum;
use Phalcon\Contracts\Acl\Adapter\Persistable;
use Phalcon\Storage\Adapter\AdapterInterface as StorageInterface;

/**
 * ACL adapter that persists its policy to any Phalcon\Storage backend
 * (Redis, Apcu, Stream, Memcached, ...) as a whole-policy snapshot.
 *
 * Coarse granularity: the entire policy is loaded into memory and all
 * decisions are computed in memory (inherited from Memory). The backend is a
 * blob sink - it knows nothing about ACL structure.
 *
 * @see Persistable for the closure-persistence caveat.
 */
class Storage extends Memory implements Persistable
{
    /**
     * @var string
     */
    protected key;

    /**
     * @var StorageInterface
     */
    protected storage;

    public function __construct(<StorageInterface> storage, string key = "acl-data")
    {
        let this->storage = storage,
            this->key     = key;

        parent::__construct();

        this->load();
    }

    /**
     * Loads the policy snapshot from the backing store, replacing current
     * in-memory state. Returns false if no snapshot was found.
     */
    public function load() -> bool
    {
        var data;

        let data = this->storage->get(this->key);

        if typeof data !== "array" {
            return false;
        }

        let this->access                   = isset(data["access"]) ? data["access"] : [],
            this->accessList               = isset(data["accessList"]) ? data["accessList"] : ["*!*": true],
            this->components               = isset(data["components"]) ? data["components"] : [],
            this->componentsNames          = isset(data["componentsNames"]) ? data["componentsNames"] : ["*": true],
            this->roles                    = isset(data["roles"]) ? data["roles"] : [],
            this->roleInherits             = isset(data["roleInherits"]) ? data["roleInherits"] : [],
            this->defaultAccess            = isset(data["defaultAccess"]) ? data["defaultAccess"] : Enum::DENY,
            this->noArgumentsDefaultAction = isset(data["noArgumentsDefaultAction"]) ? data["noArgumentsDefaultAction"] : Enum::DENY;

        return true;
    }

    /**
     * Persists the policy snapshot. Callable rules (`functions`) are excluded -
     * closures are not serializable; the static rule set in `access` survives.
     */
    public function save() -> bool
    {
        return this->storage->set(
            this->key,
            [
                "access":                   this->access,
                "accessList":               this->accessList,
                "components":               this->components,
                "componentsNames":          this->componentsNames,
                "roles":                    this->roles,
                "roleInherits":             this->roleInherits,
                "defaultAccess":            this->defaultAccess,
                "noArgumentsDefaultAction": this->noArgumentsDefaultAction
            ]
        );
    }
}
