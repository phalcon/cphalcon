
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
 * Canonical contract for Phalcon\Db\Index.
 *
 * @todo v7 - these will become required interface members. They are
 *            omitted from the v5 line to avoid breaking third-party
 *            implementors:
 *              - getDirections() : array
 *              - getWhere()      : string
 *              - isConcurrent()  : bool
 *              - isInvisible()   : bool
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Db_Index)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Db, Index, phalcon, contracts_db_index, phalcon_contracts_db_index_method_entry);

	return SUCCESS;
}

/**
 * Gets the columns that corresponds the index
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Index, getColumns);
/**
 * Gets the index name
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Index, getName);
/**
 * Gets the index type
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Index, getType);
