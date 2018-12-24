
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
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
 * Restores the internal state of a Phalcon\Db\Column object
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ColumnInterface, __set_state);

/**
 * Check whether field absolute to position in table
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ColumnInterface, getAfterPosition);

/**
 * Returns the type of bind handling
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ColumnInterface, getBindType);

/**
 * Returns default value of column
 *
 * @return mixed|null
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ColumnInterface, getDefault);

/**
 * Returns column name
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ColumnInterface, getName);

/**
 * Returns column scale
 *
 * @return int
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ColumnInterface, getScale);

/**
 * Returns schema's table related to column
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ColumnInterface, getSchemaName);

/**
 * Returns column size
 *
 * @return int
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ColumnInterface, getSize);

/**
 * Returns column type
 *
 * @return int|string
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
 * @return array|string
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

