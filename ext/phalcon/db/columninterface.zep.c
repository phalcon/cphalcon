
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
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */
/**
 * Interface for Phalcon\Db\Column
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_ColumnInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Db, ColumnInterface, phalcon, db_columninterface, phalcon_db_columninterface_method_entry);

	return SUCCESS;
}

/**
 * Check whether field absolute to position in table
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ColumnInterface, getAfterPosition);
/**
 * Returns the type of bind handling
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ColumnInterface, getBindType);
/**
 * Returns default value of column
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ColumnInterface, getDefault);
/**
 * Returns column name
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ColumnInterface, getName);
/**
 * Returns column scale
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ColumnInterface, getScale);
/**
 * Returns column size
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ColumnInterface, getSize);
/**
 * Returns column type
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ColumnInterface, getType);
/**
 * Returns column type reference
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ColumnInterface, getTypeReference);
/**
 * Returns column type values
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ColumnInterface, getTypeValues);
/**
 * Check whether column has default value
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ColumnInterface, hasDefault);
/**
 * Auto-Increment
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ColumnInterface, isAutoIncrement);
/**
 * Check whether column have first position in table
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ColumnInterface, isFirst);
/**
 * Not null
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ColumnInterface, isNotNull);
/**
 * Check whether column have an numeric type
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ColumnInterface, isNumeric);
/**
 * Column is part of the primary key?
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ColumnInterface, isPrimary);
/**
 * Returns true if number column is unsigned
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ColumnInterface, isUnsigned);
