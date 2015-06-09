
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Phalcon\Mvc\Model\CriteriaInterface
 *
 * Interface for Phalcon\Mvc\Model\Criteria
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_CriteriaInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc\\Model, CriteriaInterface, phalcon, mvc_model_criteriainterface, phalcon_mvc_model_criteriainterface_method_entry);

	return SUCCESS;

}

/**
 * Set a model on which the query will be executed
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, setModelName);

/**
 * Returns an internal model name on which the criteria will be applied
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, getModelName);

/**
 * Sets the bound parameters in the criteria
 * This method replaces all previously set bound parameters
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, bind);

/**
 * Sets the bind types in the criteria
 * This method replaces all previously set bound parameters
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, bindTypes);

/**
 * Sets the conditions parameter in the criteria
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, where);

/**
 * Adds the conditions parameter to the criteria
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, conditions);

/**
 * Adds the order-by parameter to the criteria
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, orderBy);

/**
 * Sets the limit parameter to the criteria
 *
 * @param int limit
 * @param int offset
 * @return Phalcon\Mvc\Model\CriteriaInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, limit);

/**
 * Sets the "for_update" parameter to the criteria
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, forUpdate);

/**
 * Sets the "shared_lock" parameter to the criteria
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, sharedLock);

/**
 * Appends a condition to the current conditions using an AND operator
 *
 * @param string conditions
 * @param array bindParams
 * @param array bindTypes
 * @return Phalcon\Mvc\Model\CriteriaInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, andWhere);

/**
 * Appends a condition to the current conditions using an OR operator
 *
 * @param string conditions
 * @param array bindParams
 * @param array bindTypes
 * @return Phalcon\Mvc\Model\CriteriaInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, orWhere);

/**
 * Appends a BETWEEN condition to the current conditions
 *
 *<code>
 *	$criteria->betweenWhere('price', 100.25, 200.50);
 *</code>
 *
 * @param string expr
 * @param mixed minimum
 * @param mixed maximum
 * @return Phalcon\Mvc\Model\CriteriaInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, betweenWhere);

/**
 * Appends a NOT BETWEEN condition to the current conditions
 *
 *<code>
 *	$criteria->notBetweenWhere('price', 100.25, 200.50);
 *</code>
 *
 * @param string expr
 * @param mixed minimum
 * @param mixed maximum
 * @return Phalcon\Mvc\Model\CriteriaInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, notBetweenWhere);

/**
 * Appends an IN condition to the current conditions
 *
 *<code>
 *	$criteria->inWhere('id', [1, 2, 3]);
 *</code>
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, inWhere);

/**
 * Appends a NOT IN condition to the current conditions
 *
 *<code>
 *	$criteria->notInWhere('id', [1, 2, 3]);
 *</code>
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, notInWhere);

/**
 * Returns the conditions parameter in the criteria
 *
 * @return string|null
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, getWhere);

/**
 * Returns the conditions parameter in the criteria
 *
 * @return string|null
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, getConditions);

/**
 * Returns the limit parameter in the criteria, which will be
 * an integer if limit was set without an offset,
 * an array with 'number' and 'offset' keys if an offset was set with the limit,
 * or null if limit has not been set.
 *
 * @return int|array|null
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, getLimit);

/**
 * Returns the order parameter in the criteria
 *
 * @return string|null
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, getOrder);

/**
 * Returns all the parameters defined in the criteria
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, getParams);

/**
 * Builds a Phalcon\Mvc\Model\Criteria based on an input array like _POST
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, fromInput);

/**
 * Executes a find using the parameters built with the criteria
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, execute);

