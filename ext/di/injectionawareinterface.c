
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

#include "di/injectionawareinterface.h"

#include "kernel/main.h"

zend_class_entry *phalcon_di_injectionawareinterface_ce;

static const zend_function_entry phalcon_di_injectionawareinterface_method_entry[] = {
	PHP_ABSTRACT_ME(Phalcon_DI_InjectionAwareInterface, setDI, arginfo_phalcon_di_injectionawareinterface_setdi)
	PHP_ABSTRACT_ME(Phalcon_DI_InjectionAwareInterface, getDI, arginfo_phalcon_di_injectionawareinterface_getdi)
	PHP_FE_END
};

/**
 * Phalcon\DI\InjectionAwareInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_DI_InjectionAwareInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\DI, InjectionAwareInterface, di_injectionawareinterface, phalcon_di_injectionawareinterface_method_entry);

	return SUCCESS;
}

/**
 * Sets the dependency injector
 *
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHALCON_DOC_METHOD(Phalcon_DI_InjectionAwareInterface, setDI);

/**
 * Returns the internal dependency injector
 *
 * @return Phalcon\DiInterface
 */
PHALCON_DOC_METHOD(Phalcon_DI_InjectionAwareInterface, getDI);

