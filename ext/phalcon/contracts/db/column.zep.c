
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
 * Canonical contract for Phalcon\Db\Column.
 *
 * @todo v7 - these will become required interface members. They are
 *            omitted from the v5 line to avoid breaking third-party
 *            implementors:
 *              - getGenerationExpression() : string | null
 *              - isArray()                 : bool
 *              - isGenerated()             : bool
 *              - isGenerationStored()      : bool
 *              - isInvisible()             : bool
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Db_Column)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Db, Column, phalcon, contracts_db_column, phalcon_contracts_db_column_method_entry);

	return SUCCESS;
}

/**
 * Check whether field absolute to position in table
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Column, getAfterPosition);
/**
 * Returns the type of bind handling
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Column, getBindType);
/**
 * Returns default value of column
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Column, getDefault);
/**
 * Returns column name
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Column, getName);
/**
 * Returns column scale
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Column, getScale);
/**
 * Returns column size
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Column, getSize);
/**
 * Returns column type
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Column, getType);
/**
 * Returns column type reference
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Column, getTypeReference);
/**
 * Returns column type values
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Column, getTypeValues);
/**
 * Check whether column has default value
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Column, hasDefault);
/**
 * Auto-Increment
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Column, isAutoIncrement);
/**
 * Check whether column have first position in table
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Column, isFirst);
/**
 * Not null
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Column, isNotNull);
/**
 * Check whether column have an numeric type
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Column, isNumeric);
/**
 * Column is part of the primary key?
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Column, isPrimary);
/**
 * Returns true if number column is unsigned
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Column, isUnsigned);
