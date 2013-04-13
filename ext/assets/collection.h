
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

extern zend_class_entry *phalcon_assets_collection_ce;

PHALCON_INIT_CLASS(Phalcon_Assets_Collection);

PHP_METHOD(Phalcon_Assets_Collection, add);
PHP_METHOD(Phalcon_Assets_Collection, addCss);
PHP_METHOD(Phalcon_Assets_Collection, addJs);
PHP_METHOD(Phalcon_Assets_Collection, getResources);
PHP_METHOD(Phalcon_Assets_Collection, count);
PHP_METHOD(Phalcon_Assets_Collection, rewind);
PHP_METHOD(Phalcon_Assets_Collection, current);
PHP_METHOD(Phalcon_Assets_Collection, key);
PHP_METHOD(Phalcon_Assets_Collection, next);
PHP_METHOD(Phalcon_Assets_Collection, valid);
PHP_METHOD(Phalcon_Assets_Collection, setPrefix);
PHP_METHOD(Phalcon_Assets_Collection, getPrefix);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_collection_add, 0, 0, 1)
	ZEND_ARG_INFO(0, resource)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_collection_addcss, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, local)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_collection_addjs, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, local)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_collection_setprefix, 0, 0, 1)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_assets_collection_method_entry){
	PHP_ME(Phalcon_Assets_Collection, add, arginfo_phalcon_assets_collection_add, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Assets_Collection, addCss, arginfo_phalcon_assets_collection_addcss, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Assets_Collection, addJs, arginfo_phalcon_assets_collection_addjs, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Assets_Collection, getResources, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Assets_Collection, count, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Assets_Collection, rewind, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Assets_Collection, current, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Assets_Collection, key, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Assets_Collection, next, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Assets_Collection, valid, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Assets_Collection, setPrefix, arginfo_phalcon_assets_collection_setprefix, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Assets_Collection, getPrefix, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};

