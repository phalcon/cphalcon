/*
  +------------------------------------------------------------------------+
  | Zephir Language                                                        |
  +------------------------------------------------------------------------+
<<<<<<< HEAD:ext/kernel/exit.c
  | Copyright (c) 2011-2015 Zephir Team (http://www.zephir-lang.com)       |
=======
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
>>>>>>> master:ext/mvc/controllerinterface.c
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@zephir-lang.com so we can send you a copy immediately.      |
  +------------------------------------------------------------------------+
  | Authors: Song Yeung <netyum@163.com>                                   |
  +------------------------------------------------------------------------+
*/

<<<<<<< HEAD:ext/kernel/exit.c
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "php_main.h"

=======
#include "mvc/controllerinterface.h"
>>>>>>> master:ext/mvc/controllerinterface.c
#include "kernel/main.h"
#include "kernel/exit.h"

<<<<<<< HEAD:ext/kernel/exit.c
void zephir_exit_empty() {
	TSRMLS_FETCH();
	zend_bailout();
}

void zephir_exit(zval *ptr)  {
	TSRMLS_FETCH();
	if (Z_TYPE_P(ptr) == IS_LONG) {
		EG(exit_status) = Z_LVAL_P(ptr);
	} else {
		zend_print_variable(ptr);
	}
	zephir_exit_empty();
}
=======
zend_class_entry *phalcon_mvc_controllerinterface_ce;

/**
 * Phalcon\Mvc\ControllerInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_ControllerInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Mvc, ControllerInterface, mvc_controllerinterface, NULL);

	return SUCCESS;
}
>>>>>>> master:ext/mvc/controllerinterface.c
