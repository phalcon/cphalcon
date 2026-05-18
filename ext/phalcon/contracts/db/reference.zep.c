
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

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
 * Canonical contract for Phalcon\Db\Reference.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Db_Reference)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Db, Reference, phalcon, contracts_db_reference, phalcon_contracts_db_reference_method_entry);

	return SUCCESS;
}

/**
 * Gets local columns which reference is based
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Reference, getColumns);
/**
 * Gets the index name
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Reference, getName);
/**
 * Gets the referenced on delete
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Reference, getOnDelete);
/**
 * Gets the referenced on update
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Reference, getOnUpdate);
/**
 * Gets referenced columns
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Reference, getReferencedColumns);
/**
 * Gets the schema where referenced table is
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Reference, getReferencedSchema);
/**
 * Gets the referenced table
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Reference, getReferencedTable);
/**
 * Gets the schema where referenced table is
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Reference, getSchemaName);
