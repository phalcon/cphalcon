
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Phalcon\Db\IndexInterface
 *
 * Interface for Phalcon\Db\Index
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_IndexInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Db, IndexInterface, phalcon, db_indexinterface, phalcon_db_indexinterface_method_entry);

	return SUCCESS;

}

/**
 * Phalcon\Db\Index constructor
 *
 * @param string indexName
 * @param array columns
 * @param string type
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_IndexInterface, __construct);

/**
 * Gets the index name
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_IndexInterface, getName);

/**
 * Gets the columns that comprends the index
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_IndexInterface, getColumns);

/**
 * Gets the index type
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_IndexInterface, getType);

/**
 * Restore a Phalcon\Db\Index object from export
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_IndexInterface, __set_state);

