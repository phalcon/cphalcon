
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

#include "mvc/controllerinterface.h"
#include "kernel/main.h"

zend_class_entry *phalcon_mvc_controllerinterface_ce;

/**
 * Phalcon\Mvc\ControllerInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_ControllerInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Mvc, ControllerInterface, mvc_controllerinterface, NULL);

	return SUCCESS;
}
