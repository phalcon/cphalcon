
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Phalcon\Db\ColumnInterface
 *
 * Interface for Phalcon\Db\Column
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_ColumnInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Db, ColumnInterface, phalcon, db_columninterface, phalcon_db_columninterface_method_entry);

	return SUCCESS;

}

/**
 * Phalcon\Db\ColumnInterface constructor
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ColumnInterface, __construct);

/**
 * Returns schema's table related to column
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ColumnInterface, getSchemaName);

/**
 * Returns column name
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ColumnInterface, getName);

/**
 * Returns column type
 *
 * @return int
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ColumnInterface, getType);

/**
 * Returns column type reference
 *
 * @return int
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ColumnInterface, getTypeReference);

/**
 * Returns column type values
 *
 * @return int
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ColumnInterface, getTypeValues);

/**
 * Returns column size
 *
 * @return int
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ColumnInterface, getSize);

/**
 * Returns column scale
 *
 * @return int
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ColumnInterface, getScale);

/**
 * Returns true if number column is unsigned
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ColumnInterface, isUnsigned);

/**
 * Not null
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ColumnInterface, isNotNull);

/**
 * Column is part of the primary key?
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ColumnInterface, isPrimary);

/**
 * Auto-Increment
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ColumnInterface, isAutoIncrement);

/**
 * Check whether column have an numeric type
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ColumnInterface, isNumeric);

/**
 * Check whether column have first position in table
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ColumnInterface, isFirst);

/**
 * Check whether field absolute to position in table
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ColumnInterface, getAfterPosition);

/**
 * Returns the type of bind handling
 *
 * @return int
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ColumnInterface, getBindType);

/**
 * Returns default value of column
 *
 * @return int
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ColumnInterface, getDefault);

/**
 * Restores the internal state of a Phalcon\Db\Column object
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ColumnInterface, __set_state);

