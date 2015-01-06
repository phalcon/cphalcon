
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

#include "mvc/micro/middlewareinterface.h"
#include "kernel/main.h"

zend_class_entry *phalcon_mvc_micro_middlewareinterface_ce;

static const zend_function_entry phalcon_mvc_micro_middlewareinterface_method_entry[] = {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_MiddlewareInterface, call, arginfo_phalcon_mvc_micro_middlewareinterface_call)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\Micro\MiddlewareInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Micro_MiddlewareInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Mvc\\Micro, MiddlewareInterface, mvc_micro_middlewareinterface, phalcon_mvc_micro_middlewareinterface_method_entry);

	return SUCCESS;
}

/**
 * Calls the middleware
 *
 * @param Phalcon\Mvc\Micro $application
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Micro_MiddlewareInterface, call);

