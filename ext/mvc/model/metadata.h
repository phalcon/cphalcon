
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
  +------------------------------------------------------------------------+
*/

extern zend_class_entry *phalcon_mvc_model_metadata_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_MetaData);

PHP_METHOD(Phalcon_Mvc_Model_MetaData, _initializeMetaData);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, readMetaDataIndex);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, writeMetaDataIndex);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getAttributes);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getPrimaryKeyAttributes);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getNonPrimaryKeyAttributes);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getNotNullAttributes);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getDataTypes);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getDataTypesNumeric);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getIdentityField);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getBindTypes);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getAutomaticCreateAttributes);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getAutomaticUpdateAttributes);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, setAutomaticCreateAttributes);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, setAutomaticUpdateAttributes);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, isEmpty);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, reset);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_readmetadataindex, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_writemetadataindex, 0, 0, 3)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_getattributes, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_getprimarykeyattributes, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_getnonprimarykeyattributes, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_getnotnullattributes, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_getdatatypes, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_getdatatypesnumeric, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_getidentityfield, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_getbindtypes, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_getautomaticcreateattributes, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_getautomaticupdateattributes, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_setautomaticcreateattributes, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_setautomaticupdateattributes, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_metadata_method_entry){
	PHP_ME(Phalcon_Mvc_Model_MetaData, _initializeMetaData, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_MetaData, readMetaDataIndex, arginfo_phalcon_mvc_model_metadata_readmetadataindex, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_MetaData, writeMetaDataIndex, arginfo_phalcon_mvc_model_metadata_writemetadataindex, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_MetaData, getAttributes, arginfo_phalcon_mvc_model_metadata_getattributes, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_MetaData, getPrimaryKeyAttributes, arginfo_phalcon_mvc_model_metadata_getprimarykeyattributes, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_MetaData, getNonPrimaryKeyAttributes, arginfo_phalcon_mvc_model_metadata_getnonprimarykeyattributes, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_MetaData, getNotNullAttributes, arginfo_phalcon_mvc_model_metadata_getnotnullattributes, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_MetaData, getDataTypes, arginfo_phalcon_mvc_model_metadata_getdatatypes, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_MetaData, getDataTypesNumeric, arginfo_phalcon_mvc_model_metadata_getdatatypesnumeric, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_MetaData, getIdentityField, arginfo_phalcon_mvc_model_metadata_getidentityfield, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_MetaData, getBindTypes, arginfo_phalcon_mvc_model_metadata_getbindtypes, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_MetaData, getAutomaticCreateAttributes, arginfo_phalcon_mvc_model_metadata_getautomaticcreateattributes, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_MetaData, getAutomaticUpdateAttributes, arginfo_phalcon_mvc_model_metadata_getautomaticupdateattributes, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_MetaData, setAutomaticCreateAttributes, arginfo_phalcon_mvc_model_metadata_setautomaticcreateattributes, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_MetaData, setAutomaticUpdateAttributes, arginfo_phalcon_mvc_model_metadata_setautomaticupdateattributes, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_MetaData, isEmpty, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_MetaData, reset, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};

