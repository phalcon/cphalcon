
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

#include "mvc/model/resultinterface.h"
#include "kernel/main.h"

zend_class_entry *phalcon_mvc_model_resultinterface_ce;

static const zend_function_entry phalcon_mvc_model_resultinterface_method_entry[] = {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ResultInterface, setDirtyState, arginfo_phalcon_mvc_model_resultinterface_setdirtystate)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\Model\ResultInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_ResultInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Mvc\\Model, ResultInterface, mvc_model_resultinterface, phalcon_mvc_model_resultinterface_method_entry);

	return SUCCESS;
}

/**
 * Sets the object's state
 *
 * @param boolean $dirtyState
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_ResultInterface, setDirtyState);
