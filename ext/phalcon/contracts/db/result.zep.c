
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
 * Canonical contract for Phalcon\Db result objects.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Db_Result)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Db, Result, phalcon, contracts_db_result, phalcon_contracts_db_result_method_entry);

	return SUCCESS;
}

/**
 * Moves internal resultset cursor to another position letting us to fetch a
 * certain row
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Result, dataSeek);
/**
 * Allows to execute the statement again. Some database systems don't
 * support scrollable cursors. So, as cursors are forward only, we need to
 * execute the cursor again to fetch rows from the beginning
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Result, execute);
/**
 * Fetches an array/object of strings that corresponds to the fetched row,
 * or FALSE if there are no more rows. This method is affected by the active
 * fetch flag set using `Phalcon\Db\Result\Pdo::setFetchMode()`
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Result, fetch);
/**
 * Returns an array of arrays containing all the records in the result. This
 * method is affected by the active fetch flag set using
 * `Phalcon\Db\Result\Pdo::setFetchMode()`
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Result, fetchAll);
/**
 * Returns an array of strings that corresponds to the fetched row, or FALSE
 * if there are no more rows. This method is affected by the active fetch
 * flag set using `Phalcon\Db\Result\Pdo::setFetchMode()`
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Result, fetchArray);
/**
 * Gets the internal PDO result object
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Result, getInternalResult);
/**
 * Gets number of rows returned by a resultset
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Result, numRows);
/**
 * Changes the fetching mode affecting Phalcon\Db\Result\Pdo::fetch()
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Result, setFetchMode);
