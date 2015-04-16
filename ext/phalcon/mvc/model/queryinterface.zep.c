
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Phalcon\Mvc\Model\QueryInterface
 *
 * Interface for Phalcon\Mvc\Model\Query
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_QueryInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc\\Model, QueryInterface, phalcon, mvc_model_queryinterface, phalcon_mvc_model_queryinterface_method_entry);

	return SUCCESS;

}

/**
 * Parses the intermediate code produced by Phalcon\Mvc\Model\Query\Lang generating another
 * intermediate representation that could be executed by Phalcon\Mvc\Model\Query
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_QueryInterface, parse);

/**
 * Sets the cache parameters of the query
 *
 * @param array cacheOptions
 * @return Phalcon\Mvc\Model\Query
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_QueryInterface, cache);

/**
 * Returns the current cache options
 *
 * @param array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_QueryInterface, getCacheOptions);

/**
 * Tells to the query if only the first row in the resultset must be returned
 *
 * @param boolean uniqueRow
 * @return Phalcon\Mvc\Model\Query
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_QueryInterface, setUniqueRow);

/**
 * Check if the query is programmed to get only the first row in the resultset
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_QueryInterface, getUniqueRow);

/**
 * Executes a parsed PHQL statement
 *
 * @param array bindParams
 * @param array bindTypes
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_QueryInterface, execute);

