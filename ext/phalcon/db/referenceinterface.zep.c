
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


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
 * Phalcon\Db\ReferenceInterface constructor
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ReferenceInterface, __construct);

/**
 * Gets the index name
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ReferenceInterface, getName);

/**
 * Gets the schema where referenced table is
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ReferenceInterface, getSchemaName);

/**
 * Gets the schema where referenced table is
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ReferenceInterface, getReferencedSchema);

/**
 * Gets local columns which reference is based
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ReferenceInterface, getColumns);

/**
 * Gets the referenced table
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ReferenceInterface, getReferencedTable);

/**
 * Gets referenced columns
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ReferenceInterface, getReferencedColumns);

/**
 * Gets the referenced on delete
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ReferenceInterface, getOnDelete);

/**
 * Gets the referenced on update
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ReferenceInterface, getOnUpdate);

/**
 * Restore a Phalcon\Db\Reference object from export
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ReferenceInterface, __set_state);

