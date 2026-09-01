
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Contracts\Acl\Adapter;

/**
 * Contract for ACL adapters that persist their policy to a backing store as a
 * whole-policy snapshot (coarse granularity).
 *
 * NOTE: callable (closure) rules registered via allow()/deny() are NOT
 * persisted - closures are not serializable. Re-register them in code after
 * load(). The static rule set and role inheritance are persisted in full.
 */
interface Persistable
{
    /**
     * Loads the policy snapshot from the backing store, replacing current
     * in-memory state. Returns false if no snapshot was found.
     */
    public function load() -> bool;

    /**
     * Persists the current policy snapshot to the backing store.
     */
    public function save() -> bool;
}
