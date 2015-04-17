
<<<<<<< HEAD:ext/phalcon/mvc/model/resultset.zep.h
extern zend_class_entry *phalcon_mvc_model_resultset_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Resultset);

PHP_METHOD(Phalcon_Mvc_Model_Resultset, next);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, key);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, rewind);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, seek);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, count);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, offsetExists);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, offsetGet);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, offsetSet);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, offsetUnset);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getType);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getFirst);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getLast);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, setIsFresh);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, isFresh);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, setHydrateMode);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getHydrateMode);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getCache);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, current);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getMessages);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, update);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, delete);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, filter);
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

#ifndef PHALCON_MVC_MODEL_RESULTSET_H
#define PHALCON_MVC_MODEL_RESULTSET_H
>>>>>>> master:ext/mvc/model/resultset.h

#include "php_phalcon.h"

extern zend_class_entry *phalcon_mvc_model_resultset_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Resultset);

#define PHALCON_MVC_MODEL_RESULTSET_TYPE_FULL       0
#define PHALCON_MVC_MODEL_RESULTSET_TYPE_PARTIAL    1

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultset_sethydratemode, 0, 0, 1)
	ZEND_ARG_INFO(0, hydrateMode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultset_update, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_OBJ_INFO(0, conditionCallback, Closure, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultset_delete, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, conditionCallback, Closure, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultset_filter, 0, 0, 1)
	ZEND_ARG_INFO(0, filter)
ZEND_END_ARG_INFO()

<<<<<<< HEAD:ext/phalcon/mvc/model/resultset.zep.h
ZEPHIR_INIT_FUNCS(phalcon_mvc_model_resultset_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Resultset, next, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, key, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, rewind, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Resultset, seek, arginfo_phalcon_mvc_model_resultset_seek, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Resultset, count, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Resultset, offsetExists, arginfo_phalcon_mvc_model_resultset_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, offsetGet, arginfo_phalcon_mvc_model_resultset_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, offsetSet, arginfo_phalcon_mvc_model_resultset_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, offsetUnset, arginfo_phalcon_mvc_model_resultset_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, getFirst, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, getLast, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, setIsFresh, arginfo_phalcon_mvc_model_resultset_setisfresh, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, isFresh, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, setHydrateMode, arginfo_phalcon_mvc_model_resultset_sethydratemode, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, getHydrateMode, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, getCache, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, current, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Resultset, getMessages, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, update, arginfo_phalcon_mvc_model_resultset_update, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, delete, arginfo_phalcon_mvc_model_resultset_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, filter, arginfo_phalcon_mvc_model_resultset_filter, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
=======
#endif /* PHALCON_MVC_MODEL_RESULTSET_H */
>>>>>>> master:ext/mvc/model/resultset.h
