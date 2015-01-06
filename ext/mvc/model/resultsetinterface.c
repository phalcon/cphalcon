
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#include "mvc/model/resultsetinterface.h"
#include "kernel/main.h"

zend_class_entry *phalcon_mvc_model_resultsetinterface_ce;

static const zend_function_entry phalcon_mvc_model_resultsetinterface_method_entry[] = {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ResultsetInterface, getType, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ResultsetInterface, getFirst, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ResultsetInterface, getLast, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ResultsetInterface, setIsFresh, arginfo_phalcon_mvc_model_resultsetinterface_setisfresh)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ResultsetInterface, isFresh, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ResultsetInterface, getCache, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ResultsetInterface, toArray, NULL)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\Model\ResultsetInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_ResultsetInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Mvc\\Model, ResultsetInterface, mvc_model_resultsetinterface, phalcon_mvc_model_resultsetinterface_method_entry);

	return SUCCESS;
}

/**
 * Returns the internal type of data retrieval that the resultset is using
 *
 * @return int
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_ResultsetInterface, getType);

/**
 * Get first row in the resultset
 *
 * @return Phalcon\Mvc\ModelInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_ResultsetInterface, getFirst);

/**
 * Get last row in the resultset
 *
 * @return Phalcon\Mvc\ModelInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_ResultsetInterface, getLast);

/**
 * Set if the resultset is fresh or an old one cached
 *
 * @param boolean $isFresh
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_ResultsetInterface, setIsFresh);

/**
 * Tell if the resultset if fresh or an old one cached
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_ResultsetInterface, isFresh);

/**
 * Returns the associated cache for the resultset
 *
 * @return Phalcon\Cache\BackendInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_ResultsetInterface, getCache);

/**
 * Returns a complete resultset as an array, if the resultset has a big number of rows
 * it could consume more memory than currently it does.
 *
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_ResultsetInterface, toArray);
