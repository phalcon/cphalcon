
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Contract for ACL adapters that persist their policy to a backing store as a
 * whole-policy snapshot (coarse granularity).
 *
 * NOTE: callable (closure) rules registered via allow()/deny() are NOT
 * persisted - closures are not serializable. Re-register them in code after
 * load(). The static rule set and role inheritance are persisted in full.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Acl_Adapter_Persistable)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Acl\\Adapter, Persistable, phalcon, contracts_acl_adapter_persistable, phalcon_contracts_acl_adapter_persistable_method_entry);

	return SUCCESS;
}

/**
 * Loads the policy snapshot from the backing store, replacing current
 * in-memory state. Returns false if no snapshot was found.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Acl_Adapter_Persistable, load);
/**
 * Persists the current policy snapshot to the backing store.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Acl_Adapter_Persistable, save);
