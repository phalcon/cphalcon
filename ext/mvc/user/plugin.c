
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

#include "mvc/user/plugin.h"
#include "di/injectable.h"
#include "kernel/main.h"

/**
 * Phalcon\Mvc\User\Plugin
 *
 * This class can be used to provide user plugins an easy access to services
 * in the application
 */
zend_class_entry *phalcon_mvc_user_plugin_ce;

/**
 * Phalcon\Mvc\User\Plugin initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_User_Plugin){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\User, Plugin, mvc_user_plugin, phalcon_di_injectable_ce, NULL, 0);

	return SUCCESS;
}
