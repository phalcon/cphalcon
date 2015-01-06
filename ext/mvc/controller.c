
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

#include "mvc/controller.h"
#include "mvc/controllerinterface.h"
#include "di/injectable.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"

/**
 * Phalcon\Mvc\Controller
 *
 * Every application controller should extend this class that encapsulates all the controller functionality
 *
 * The controllers provide the “flow” between models and views. Controllers are responsible
 * for processing the incoming requests from the web browser, interrogating the models for data,
 * and passing that data on to the views for presentation.
 *
 *<code>
 *
 *class PeopleController extends \Phalcon\Mvc\Controller
 *{
 *
 *  //This action will be executed by default
 *  public function indexAction()
 *  {
 *
 *  }
 *
 *  public function findAction()
 *  {
 *
 *  }
 *
 *  public function saveAction()
 *  {
 *   //Forwards flow to the index action
 *   return $this->dispatcher->forward(array('controller' => 'people', 'action' => 'index'));
 *  }
 *
 *}
 *
 *</code>
 */
zend_class_entry *phalcon_mvc_controller_ce;

PHP_METHOD(Phalcon_Mvc_Controller, __construct);

static const zend_function_entry phalcon_mvc_controller_method_entry[] = {
	PHP_ME(Phalcon_Mvc_Controller, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL|ZEND_ACC_CTOR)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\Controller initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Controller){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc, Controller, mvc_controller, phalcon_di_injectable_ce, phalcon_mvc_controller_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_class_implements(phalcon_mvc_controller_ce TSRMLS_CC, 1, phalcon_mvc_controllerinterface_ce);
	return SUCCESS;
}

/**
 * Phalcon\Mvc\Controller constructor
 *
 */
PHP_METHOD(Phalcon_Mvc_Controller, __construct){

	if (phalcon_method_exists_ex(this_ptr, SS("onconstruct") TSRMLS_CC) == SUCCESS) {
		PHALCON_MM_GROW();
		PHALCON_CALL_METHOD(NULL, this_ptr, "onconstruct");
		PHALCON_MM_RESTORE();
	}
}
