
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Acl\Adapter;

use Phalcon\Acl\Component;
use Phalcon\Acl\Enum;
use Phalcon\Acl\Exceptions\InvalidSnapshot;
use Phalcon\Acl\Role;
use Phalcon\Contracts\Acl\Adapter\Persistable;
use Phalcon\Storage\Adapter\AdapterInterface as StorageInterface;

/**
 * ACL adapter that persists its policy to any Phalcon\Storage backend
 * (Redis, Apcu, Stream, Memcached, ...) as a whole-policy snapshot.
 *
 * The snapshot is a versioned, scalar-only structure: roles and components are
 * stored as `name => description` maps and rebuilt into objects on load, so the
 * snapshot round-trips through any serializer (php, json, igbinary, msgpack).
 *
 * Callable (closure) rules are not serializable. Any access key backed by a
 * closure is persisted as DENY, so a reloaded policy fails closed until the
 * closure is re-registered after load().
 *
 * Single-writer contract: mutations are in-memory until save() is called, and
 * save() writes the whole snapshot (last-write-wins, no atomic check-and-set).
 * Use external locking when multiple processes write the same key.
 *
 * @see Persistable
 */
class Storage extends Memory implements Persistable
{
    /**
     * @var int
     */
    const SNAPSHOT_VERSION = 1;

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
     * in-memory state. Returns false when no compatible snapshot exists; throws
     * Phalcon\Acl\Exceptions\InvalidSnapshot on an incompatible version or a
     * malformed structure.
     */
    public function load() -> bool
    {
        var data, version, name, description, rebuiltRoles, rebuiltComponents;

        let data = this->storage->get(this->key);

        if typeof data === "object" {
            let data = this->normalizeToArray(data);
        }

        if typeof data !== "array" {
            return false;
        }

        if !isset data["version"] {
            return false;
        }

        let version = data["version"];

        if version != self::SNAPSHOT_VERSION {
            throw new InvalidSnapshot(
                "Incompatible ACL snapshot version '" . version .
                "'; expected '" . self::SNAPSHOT_VERSION . "'"
            );
        }

        if unlikely (
            typeof data["access"] !== "array" ||
            typeof data["accessList"] !== "array" ||
            typeof data["components"] !== "array" ||
            typeof data["componentsNames"] !== "array" ||
            typeof data["roles"] !== "array" ||
            typeof data["roleInherits"] !== "array"
        ) {
            throw new InvalidSnapshot("Malformed ACL snapshot structure");
        }

        let rebuiltRoles = [];
        for name, description in data["roles"] {
            let rebuiltRoles[name] = new Role(name, description);
        }

        let rebuiltComponents = [];
        for name, description in data["components"] {
            let rebuiltComponents[name] = new Component(name, description);
        }

        let this->access                   = data["access"],
            this->accessList               = data["accessList"],
            this->components               = rebuiltComponents,
            this->componentsNames          = data["componentsNames"],
            this->roles                    = rebuiltRoles,
            this->roleInherits             = data["roleInherits"],
            this->defaultAccess            = isset(data["defaultAccess"]) ? data["defaultAccess"] : Enum::DENY,
            this->noArgumentsDefaultAction = isset(data["noArgumentsDefaultAction"]) ? data["noArgumentsDefaultAction"] : Enum::DENY;

        return true;
    }

    /**
     * Persists the policy snapshot. Closure-backed access keys are written as
     * DENY (fail closed); roles/components are written as scalar name =>
     * description maps for serializer independence.
     */
    public function save() -> bool
    {
        var accessKey, componentName, componentObject, roleName, roleObject;
        var access, components, roles;

        let access = this->access;
        for accessKey in array_keys(this->functions) {
            let access[accessKey] = Enum::DENY;
        }

        let components = [];
        for componentName, componentObject in this->components {
            let components[componentName] = componentObject->getDescription();
        }

        let roles = [];
        for roleName, roleObject in this->roles {
            let roles[roleName] = roleObject->getDescription();
        }

        return this->storage->set(
            this->key,
            [
                "version":                  self::SNAPSHOT_VERSION,
                "access":                   access,
                "accessList":               this->accessList,
                "components":               components,
                "componentsNames":          this->componentsNames,
                "roles":                    roles,
                "roleInherits":             this->roleInherits,
                "defaultAccess":            this->defaultAccess,
                "noArgumentsDefaultAction": this->noArgumentsDefaultAction
            ]
        );
    }

    /**
     * Recursively converts stdClass into nested arrays so a snapshot stored
     * through an object-decoding serializer (e.g. JSON) is read back the same
     * way as the array-decoding serializers (php, igbinary, msgpack).
     */
    private function normalizeToArray(var value) -> var
    {
        var item, key, result;

        if typeof value === "object" {
            let value = get_object_vars(value);
        }

        if typeof value !== "array" {
            return value;
        }

        let result = [];
        for key, item in value {
            let result[key] = this->normalizeToArray(item);
        }

        return result;
    }
}
