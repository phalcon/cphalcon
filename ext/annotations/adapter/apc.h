
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

extern zend_class_entry *phalcon_annotations_adapter_apc_ce;

PHALCON_INIT_CLASS(Phalcon_Annotations_Adapter_Apc);

PHP_METHOD(Phalcon_Annotations_Adapter_Apc, read);
PHP_METHOD(Phalcon_Annotations_Adapter_Apc, write);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapter_apc_read, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapter_apc_write, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_annotations_adapter_apc_method_entry){
	PHP_ME(Phalcon_Annotations_Adapter_Apc, read, arginfo_phalcon_annotations_adapter_apc_read, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Annotations_Adapter_Apc, write, arginfo_phalcon_annotations_adapter_apc_write, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};

