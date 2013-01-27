
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

extern zend_class_entry *phalcon_annotations_adapter_ce;

PHALCON_INIT_CLASS(Phalcon_Annotations_Adapter);

PHP_METHOD(Phalcon_Annotations_Adapter, setReader);
PHP_METHOD(Phalcon_Annotations_Adapter, getReader);
PHP_METHOD(Phalcon_Annotations_Adapter, get);
PHP_METHOD(Phalcon_Annotations_Adapter, getMethods);
PHP_METHOD(Phalcon_Annotations_Adapter, getMethod);
PHP_METHOD(Phalcon_Annotations_Adapter, getProperties);
PHP_METHOD(Phalcon_Annotations_Adapter, getProperty);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapter_setreader, 0, 0, 1)
	ZEND_ARG_INFO(0, reader)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapter_get, 0, 0, 1)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapter_getmethods, 0, 0, 1)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapter_getmethod, 0, 0, 2)
	ZEND_ARG_INFO(0, className)
	ZEND_ARG_INFO(0, methodName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapter_getproperties, 0, 0, 1)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapter_getproperty, 0, 0, 2)
	ZEND_ARG_INFO(0, className)
	ZEND_ARG_INFO(0, propertyName)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_annotations_adapter_method_entry){
	PHP_ME(Phalcon_Annotations_Adapter, setReader, arginfo_phalcon_annotations_adapter_setreader, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Annotations_Adapter, getReader, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Annotations_Adapter, get, arginfo_phalcon_annotations_adapter_get, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Annotations_Adapter, getMethods, arginfo_phalcon_annotations_adapter_getmethods, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Annotations_Adapter, getMethod, arginfo_phalcon_annotations_adapter_getmethod, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Annotations_Adapter, getProperties, arginfo_phalcon_annotations_adapter_getproperties, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Annotations_Adapter, getProperty, arginfo_phalcon_annotations_adapter_getproperty, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};

