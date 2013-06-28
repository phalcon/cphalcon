
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

extern zend_class_entry *phalcon_translate_adapter_nativearray_ce;

PHALCON_INIT_CLASS(Phalcon_Translate_Adapter_NativeArray);

PHP_METHOD(Phalcon_Translate_Adapter_NativeArray, __construct);
PHP_METHOD(Phalcon_Translate_Adapter_NativeArray, query);
PHP_METHOD(Phalcon_Translate_Adapter_NativeArray, exists);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_nativearray___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_nativearray_query, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, placeholders)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_nativearray_exists, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_translate_adapter_nativearray_method_entry){
	PHP_ME(Phalcon_Translate_Adapter_NativeArray, __construct, arginfo_phalcon_translate_adapter_nativearray___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Translate_Adapter_NativeArray, query, arginfo_phalcon_translate_adapter_nativearray_query, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Translate_Adapter_NativeArray, exists, arginfo_phalcon_translate_adapter_nativearray_exists, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};

