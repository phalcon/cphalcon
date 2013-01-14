
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

extern zend_class_entry *phalcon_annotations_reflection_ce;

PHALCON_INIT_CLASS(Phalcon_Annotations_Reflection);

PHP_METHOD(Phalcon_Annotations_Reflection, __construct);
PHP_METHOD(Phalcon_Annotations_Reflection, getClassAnnotations);
PHP_METHOD(Phalcon_Annotations_Reflection, getMethodAnnotations);
PHP_METHOD(Phalcon_Annotations_Reflection, getPropertiesAnnotations);
PHP_METHOD(Phalcon_Annotations_Reflection, getReflectionData);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_reflection___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, reflectionData)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_annotations_reflection_method_entry){
	PHP_ME(Phalcon_Annotations_Reflection, __construct, arginfo_phalcon_annotations_reflection___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Annotations_Reflection, getClassAnnotations, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Annotations_Reflection, getMethodAnnotations, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Annotations_Reflection, getPropertiesAnnotations, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Annotations_Reflection, getReflectionData, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};

