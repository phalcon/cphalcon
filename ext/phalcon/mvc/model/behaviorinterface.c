
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
 * Phalcon\Mvc\Model\BehaviorInterface
 *
 * Interface for Phalcon\Mvc\Model\Behavior
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_BehaviorInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc\\Model, BehaviorInterface, phalcon, mvc_model_behaviorinterface, phalcon_mvc_model_behaviorinterface_method_entry);


	return SUCCESS;

}

/**
 * Phalcon\Mvc\Model\Behavior
 *
 * @param array options
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_BehaviorInterface, __construct);

/**
 * This method receives the notifications from the EventsManager
 *
 * @param string type
 * @param Phalcon\Mvc\ModelInterface model
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_BehaviorInterface, notify);

/**
 * Calls a method when it's missing in the model
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @param string method
 * @param array arguments
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_BehaviorInterface, missingMethod);

