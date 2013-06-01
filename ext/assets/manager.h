
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

extern zend_class_entry *phalcon_assets_manager_ce;

PHALCON_INIT_CLASS(Phalcon_Assets_Manager);

PHP_METHOD(Phalcon_Assets_Manager, __construct);
PHP_METHOD(Phalcon_Assets_Manager, setOptions);
PHP_METHOD(Phalcon_Assets_Manager, useImplicitOutput);
PHP_METHOD(Phalcon_Assets_Manager, addCss);
PHP_METHOD(Phalcon_Assets_Manager, addJs);
PHP_METHOD(Phalcon_Assets_Manager, addResourceByType);
PHP_METHOD(Phalcon_Assets_Manager, addResource);
PHP_METHOD(Phalcon_Assets_Manager, set);
PHP_METHOD(Phalcon_Assets_Manager, get);
PHP_METHOD(Phalcon_Assets_Manager, getCss);
PHP_METHOD(Phalcon_Assets_Manager, getJs);
PHP_METHOD(Phalcon_Assets_Manager, collection);
PHP_METHOD(Phalcon_Assets_Manager, outputCss);
PHP_METHOD(Phalcon_Assets_Manager, outputJs);
PHP_METHOD(Phalcon_Assets_Manager, filter);
PHP_METHOD(Phalcon_Assets_Manager, hasChanged);
PHP_METHOD(Phalcon_Assets_Manager, getResourceContent);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_setoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_useimplicitoutput, 0, 0, 1)
	ZEND_ARG_INFO(0, implicitOutput)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_addcss, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, local)
	ZEND_ARG_INFO(0, filter)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_addjs, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, local)
	ZEND_ARG_INFO(0, filter)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_addresourcebytype, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, resource)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_addresource, 0, 0, 1)
	ZEND_ARG_INFO(0, resource)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_set, 0, 0, 2)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_INFO(0, collection)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_get, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_collection, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_outputcss, 0, 0, 0)
	ZEND_ARG_INFO(0, collectionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_outputjs, 0, 0, 0)
	ZEND_ARG_INFO(0, collectionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_haschanged, 0, 0, 1)
	ZEND_ARG_INFO(0, resources)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_getresourcecontent, 0, 0, 1)
	ZEND_ARG_INFO(0, resource)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_assets_manager_method_entry){
	PHP_ME(Phalcon_Assets_Manager, __construct, arginfo_phalcon_assets_manager___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Assets_Manager, setOptions, arginfo_phalcon_assets_manager_setoptions, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Assets_Manager, useImplicitOutput, arginfo_phalcon_assets_manager_useimplicitoutput, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Assets_Manager, addCss, arginfo_phalcon_assets_manager_addcss, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Assets_Manager, addJs, arginfo_phalcon_assets_manager_addjs, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Assets_Manager, addResourceByType, arginfo_phalcon_assets_manager_addresourcebytype, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Assets_Manager, addResource, arginfo_phalcon_assets_manager_addresource, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Assets_Manager, set, arginfo_phalcon_assets_manager_set, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Assets_Manager, get, arginfo_phalcon_assets_manager_get, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Assets_Manager, getCss, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Assets_Manager, getJs, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Assets_Manager, collection, arginfo_phalcon_assets_manager_collection, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Assets_Manager, outputCss, arginfo_phalcon_assets_manager_outputcss, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Assets_Manager, outputJs, arginfo_phalcon_assets_manager_outputjs, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Assets_Manager, filter, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Assets_Manager, hasChanged, arginfo_phalcon_assets_manager_haschanged, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Assets_Manager, getResourceContent, arginfo_phalcon_assets_manager_getresourcecontent, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};

