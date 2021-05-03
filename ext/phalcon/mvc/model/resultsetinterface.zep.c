
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
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\Model\ResultsetInterface
 *
 * Interface for Phalcon\Mvc\Model\Resultset
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_ResultsetInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc\\Model, ResultsetInterface, phalcon, mvc_model_resultsetinterface, phalcon_mvc_model_resultsetinterface_method_entry);

	return SUCCESS;
}

/**
 * Deletes every record in the resultset
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ResultsetInterface, delete);
/**
 * Filters a resultset returning only those the developer requires
 *
 *```php
 * $filtered = $robots->filter(
 *     function ($robot) {
 *         if ($robot->id < 3) {
 *             return $robot;
 *         }
 *     }
 * );
 *```
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ResultsetInterface, filter);
/**
 * Returns the associated cache for the resultset
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ResultsetInterface, getCache);
/**
 * Get first row in the resultset
 *
 * @return ModelInterface|Row|null
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ResultsetInterface, getFirst);
/**
 * Returns the current hydration mode
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ResultsetInterface, getHydrateMode);
/**
 * Get last row in the resultset
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ResultsetInterface, getLast);
/**
 * Returns the error messages produced by a batch operation
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ResultsetInterface, getMessages);
/**
 * Returns the internal type of data retrieval that the resultset is using
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ResultsetInterface, getType);
/**
 * Tell if the resultset if fresh or an old one cached
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ResultsetInterface, isFresh);
/**
 * Sets the hydration mode in the resultset
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ResultsetInterface, setHydrateMode);
/**
 * Set if the resultset is fresh or an old one cached
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ResultsetInterface, setIsFresh);
/**
 * Returns a complete resultset as an array, if the resultset has a big number of rows
 * it could consume more memory than currently it does.
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ResultsetInterface, toArray);
/**
 * Updates every record in the resultset
 *
 * @param array data
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ResultsetInterface, update);
