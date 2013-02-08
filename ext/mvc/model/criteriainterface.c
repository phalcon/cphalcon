
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "kernel/main.h"

/**
 * Phalcon\Mvc\Model\CriteriaInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_CriteriaInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Mvc\\Model, CriteriaInterface, mvc_model_criteriainterface, phalcon_mvc_model_criteriainterface_method_entry);

	return SUCCESS;
}

/**
 * Set a model on which the query will be executed
 *
 * @param string $modelName
 * @return Phalcon\Mvc\Model\CriteriaInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, setModelName);

/**
 * Returns an internal model name on which the criteria will be applied
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, getModelName);

/**
 * Adds the bind parameter to the criteria
 *
 * @param string $bindParams
 * @return Phalcon\Mvc\Model\CriteriaInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, bind);

/**
 * Adds the conditions parameter to the criteria
 *
 * @param string $conditions
 * @return Phalcon\Mvc\Model\CriteriaInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, where);

/**
 * Adds the conditions parameter to the criteria
 *
 * @param string $conditions
 * @return Phalcon\Mvc\Model\CriteriaInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, conditions);

/**
 * Adds the order-by parameter to the criteria
 *
 * @param string $orderColumns
 * @return Phalcon\Mvc\Model\CriteriaInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, order);

/**
 * Adds the limit parameter to the criteria
 *
 * @param int $limit
 * @param int $offset
 * @return Phalcon\Mvc\Model\CriteriaInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, limit);

/**
 * Adds the "for_update" parameter to the criteria
 *
 * @param boolean $forUpdate
 * @return Phalcon\Mvc\Model\CriteriaInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, forUpdate);

/**
 * Adds the "shared_lock" parameter to the criteria
 *
 * @param boolean $sharedLock
 * @return Phalcon\Mvc\Model\Criteria
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, sharedLock);

/**
 * Returns the conditions parameter in the criteria
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, getWhere);

/**
 * Returns the conditions parameter in the criteria
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, getConditions);

/**
 * Returns the limit parameter in the criteria
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, getLimit);

/**
 * Returns the order parameter in the criteria
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, getOrder);

/**
 * Returns all the parameters defined in the criteria
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, getParams);

/**
 * Builds a Phalcon\Mvc\Model\Criteria based on an input array like $_POST
 *
 * @param Phalcon\DiInterface $dependencyInjector
 * @param string $modelName
 * @param array $data
 * @return static
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, fromInput);

/**
 * Executes a find using the parameters built with the criteria
 *
 * @return Phalcon\Mvc\Model\ResultsetInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, execute);

