
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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
  |          Kenji Minamoto <kenji.minamoto@gmail.com>                     |
  +------------------------------------------------------------------------+
*/

extern zend_class_entry *phalcon_mvc_collection_manager_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Collection_Manager);

PHP_METHOD(Phalcon_Mvc_Collection_Manager, __construct);
PHP_METHOD(Phalcon_Mvc_Collection_Manager, isInitialized);
PHP_METHOD(Phalcon_Mvc_Collection_Manager, initialize);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_manager_isinitialized, 0, 0, 1)
	ZEND_ARG_INFO(0, collection)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_manager_initialize, 0, 0, 1)
	ZEND_ARG_INFO(0, collection)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_collection_manager_method_entry){
	PHP_ME(Phalcon_Mvc_Collection_Manager, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Mvc_Collection_Manager, isInitialized, arginfo_phalcon_mvc_collection_manager_isinitialized, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Collection_Manager, initialize, arginfo_phalcon_mvc_collection_manager_initialize, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};

