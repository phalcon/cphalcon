
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
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Interface for Phalcon\Db\Result objects
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_ResultInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Db, ResultInterface, phalcon, db_resultinterface, phalcon_db_resultinterface_method_entry);

	return SUCCESS;
}

/**
 * Moves internal resultset cursor to another position letting us to fetch a
 * certain row
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ResultInterface, dataSeek);
/**
 * Allows to execute the statement again. Some database systems don't
 * support scrollable cursors. So, as cursors are forward only, we need to
 * execute the cursor again to fetch rows from the beginning
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ResultInterface, execute);
/**
 * Fetches an array/object of strings that corresponds to the fetched row,
 * or FALSE if there are no more rows. This method is affected by the active
 * fetch flag set using `Phalcon\Db\Result\Pdo::setFetchMode()`
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ResultInterface, fetch);
/**
 * Returns an array of arrays containing all the records in the result. This
 * method is affected by the active fetch flag set using
 * `Phalcon\Db\Result\Pdo::setFetchMode()`
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ResultInterface, fetchAll);
/**
 * Returns an array of strings that corresponds to the fetched row, or FALSE
 * if there are no more rows. This method is affected by the active fetch
 * flag set using `Phalcon\Db\Result\Pdo::setFetchMode()`
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ResultInterface, fetchArray);
/**
 * Gets the internal PDO result object
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ResultInterface, getInternalResult);
/**
 * Gets number of rows returned by a resultset
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ResultInterface, numRows);
/**
 * Changes the fetching mode affecting Phalcon\Db\Result\Pdo::fetch()
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ResultInterface, setFetchMode);
