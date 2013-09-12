
#ifdef HAVE_CONFIG_H
#include "ext_config.h"
#endif

#include "php.h"
#include "../php_ext.h"
#include "../ext.h"

#include "kernel/main.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */
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
 *
 * @param string modelName
 * @return Phalcon\Mvc\Model\CriteriaInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, setModelName);

/**
 * Returns an internal model name on which the criteria will be applied
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, getModelName);

/**
 * Adds the bind parameter to the criteria
 *
 * @param string bindParams
 * @return Phalcon\Mvc\Model\CriteriaInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, bind);

/**
 * Sets the bind types in the criteria
 * This method replaces all previously set bound parameters
 *
 * @param string bindTypes
 * @return Phalcon\Mvc\Model\Criteria
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, bindTypes);

/**
 * Adds the conditions parameter to the criteria
 *
 * @param string conditions
 * @return Phalcon\Mvc\Model\CriteriaInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, where);

/**
 * Adds the conditions parameter to the criteria
 *
 * @param string conditions
 * @return Phalcon\Mvc\Model\CriteriaInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, conditions);

/**
 * Adds the order-by parameter to the criteria
 *
 * @param string orderColumns
 * @return Phalcon\Mvc\Model\CriteriaInterface
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
 *
 * @param boolean forUpdate
 * @return Phalcon\Mvc\Model\CriteriaInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, forUpdate);

/**
 * Sets the "shared_lock" parameter to the criteria
 *
 * @param boolean sharedLock
 * @return Phalcon\Mvc\Model\Criteria
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, sharedLock);

/**
 * Appends a condition to the current conditions using an AND operator
 *
 * @param string conditions
 * @param array bindParams
 * @param array bindTypes
 * @return Phalcon\Mvc\Model\Criteria
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, andWhere);

/**
 * Appends a condition to the current conditions using an OR operator
 *
 * @param string conditions
 * @param array bindParams
 * @param array bindTypes
 * @return Phalcon\Mvc\Model\Criteria
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, orWhere);

/**
 * Appends a BETWEEN condition to the current conditions
 *
 *<code>
 *	builder->betweenWhere('price', 100.25, 200.50);
 *</code>
 *
 * @param string expr
 * @param mixed minimum
 * @param mixed maximum
 * @return Phalcon\Mvc\Model\Query\Builder
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, betweenWhere);

/**
 * Appends a NOT BETWEEN condition to the current conditions
 *
 *<code>
 *	builder->notBetweenWhere('price', 100.25, 200.50);
 *</code>
 *
 * @param string expr
 * @param mixed minimum
 * @param mixed maximum
 * @return Phalcon\Mvc\Model\Query\Builder
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, notBetweenWhere);

/**
 * Appends an IN condition to the current conditions
 *
 *<code>
 *	builder->inWhere('id', [1, 2, 3]);
 *</code>
 *
 * @param string expr
 * @param array values
 * @return Phalcon\Mvc\Model\Query\Builder
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, inWhere);

/**
 * Appends a NOT IN condition to the current conditions
 *
 *<code>
 *	builder->notInWhere('id', [1, 2, 3]);
 *</code>
 *
 * @param string expr
 * @param array values
 * @return Phalcon\Mvc\Model\Query\Builder
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, notInWhere);

/**
 * Returns the conditions parameter in the criteria
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, getWhere);

/**
 * Returns the conditions parameter in the criteria
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, getConditions);

/**
 * Returns the limit parameter in the criteria
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, getLimit);

/**
 * Returns the order parameter in the criteria
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, getOrder);

/**
 * Returns all the parameters defined in the criteria
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, getParams);

/**
 * Builds a Phalcon\Mvc\Model\Criteria based on an input array like _POST
 *
 * @param Phalcon\DiInterface dependencyInjector
 * @param string modelName
 * @param array data
 * @return static
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, fromInput);

/**
 * Executes a find using the parameters built with the criteria
 *
 * @return Phalcon\Mvc\Model\ResultsetInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, execute);

