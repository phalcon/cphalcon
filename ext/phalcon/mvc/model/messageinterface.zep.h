
<<<<<<< HEAD:ext/phalcon/mvc/model/messageinterface.zep.h
=======
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

#ifndef PHALCON_MVC_MODEL_MESSAGEINTERFACE_H
#define PHALCON_MVC_MODEL_MESSAGEINTERFACE_H

#include "php_phalcon.h"

>>>>>>> master:ext/mvc/model/messageinterface.h
extern zend_class_entry *phalcon_mvc_model_messageinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MessageInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_messageinterface_settype, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_messageinterface_setmessage, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_messageinterface_setfield, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

<<<<<<< HEAD:ext/phalcon/mvc/model/messageinterface.zep.h
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_messageinterface___set_state, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, message, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_messageinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MessageInterface, __construct, arginfo_phalcon_mvc_model_messageinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MessageInterface, setType, arginfo_phalcon_mvc_model_messageinterface_settype)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MessageInterface, getType, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MessageInterface, setMessage, arginfo_phalcon_mvc_model_messageinterface_setmessage)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MessageInterface, getMessage, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MessageInterface, setField, arginfo_phalcon_mvc_model_messageinterface_setfield)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MessageInterface, getField, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MessageInterface, __toString, NULL)
	ZEND_FENTRY(__set_state, NULL, arginfo_phalcon_mvc_model_messageinterface___set_state, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
  PHP_FE_END
};
=======
#endif /* PHALCON_MVC_MODEL_MESSAGEINTERFACE_H */
>>>>>>> master:ext/mvc/model/messageinterface.h
