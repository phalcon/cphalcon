
<<<<<<< HEAD:ext/phalcon/translate/adapter.zep.h
extern zend_class_entry *phalcon_translate_adapter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Translate_Adapter);

PHP_METHOD(Phalcon_Translate_Adapter, t);
PHP_METHOD(Phalcon_Translate_Adapter, _);
PHP_METHOD(Phalcon_Translate_Adapter, offsetSet);
PHP_METHOD(Phalcon_Translate_Adapter, offsetExists);
PHP_METHOD(Phalcon_Translate_Adapter, offsetUnset);
PHP_METHOD(Phalcon_Translate_Adapter, offsetGet);
PHP_METHOD(Phalcon_Translate_Adapter, replacePlaceholders);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_t, 0, 0, 1)
	ZEND_ARG_INFO(0, translateKey)
	ZEND_ARG_INFO(0, placeholders)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter__, 0, 0, 1)
	ZEND_ARG_INFO(0, translateKey)
	ZEND_ARG_INFO(0, placeholders)
ZEND_END_ARG_INFO()
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

#ifndef PHALCON_TRANSLATE_ADAPTER_H
#define PHALCON_TRANSLATE_ADAPTER_H
>>>>>>> master:ext/translate/adapter.h

#include "php_phalcon.h"

extern zend_class_entry *phalcon_translate_adapter_ce;
extern zend_object_handlers phalcon_translate_adapter_object_handlers;

<<<<<<< HEAD:ext/phalcon/translate/adapter.zep.h
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_replaceplaceholders, 0, 0, 1)
	ZEND_ARG_INFO(0, translation)
	ZEND_ARG_INFO(0, placeholders)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_translate_adapter_method_entry) {
	PHP_ME(Phalcon_Translate_Adapter, t, arginfo_phalcon_translate_adapter_t, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter, _, arginfo_phalcon_translate_adapter__, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter, offsetSet, arginfo_phalcon_translate_adapter_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter, offsetExists, arginfo_phalcon_translate_adapter_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter, offsetUnset, arginfo_phalcon_translate_adapter_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter, offsetGet, arginfo_phalcon_translate_adapter_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter, replacePlaceholders, arginfo_phalcon_translate_adapter_replaceplaceholders, ZEND_ACC_PROTECTED)
  PHP_FE_END
};
=======
PHALCON_INIT_CLASS(Phalcon_Translate_Adapter);

#endif /* PHALCON_TRANSLATE_ADAPTER_H */
>>>>>>> master:ext/translate/adapter.h
