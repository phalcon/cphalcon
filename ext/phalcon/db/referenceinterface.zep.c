
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Db\Reference
 *
 * Interface for Phalcon\Db\Reference
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_ReferenceInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Db, ReferenceInterface, phalcon, db_referenceinterface, phalcon_db_referenceinterface_method_entry);

	return SUCCESS;

}

/**
 * Gets the index name
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ReferenceInterface, getName);

/**
 * Gets the schema where referenced table is
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ReferenceInterface, getSchemaName);

/**
 * Gets the schema where referenced table is
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ReferenceInterface, getReferencedSchema);

/**
 * Gets local columns which reference is based
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ReferenceInterface, getColumns);

/**
 * Gets the referenced table
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ReferenceInterface, getReferencedTable);

/**
 * Gets referenced columns
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ReferenceInterface, getReferencedColumns);

/**
 * Gets the referenced on delete
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ReferenceInterface, getOnDelete);

/**
 * Gets the referenced on update
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ReferenceInterface, getOnUpdate);

/**
 * Restore a Phalcon\Db\Reference object from export
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ReferenceInterface, __set_state);

