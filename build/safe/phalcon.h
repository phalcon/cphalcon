/*
<<<<<<< HEAD
 * phalcon.h
 *
 *  Created on: 11 січ. 2014
 *      Author: vladimir
 */
=======
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
>>>>>>> master

#ifndef PHALCON_H
#define PHALCON_H



#ifndef PHALCON_ACL_H
#define PHALCON_ACL_H

#include "php_phalcon.h"

#define PHALCON_ACL_DENY   0
#define PHALCON_ACL_ALLOW  1

zend_class_entry *phalcon_acl_ce;

PHALCON_INIT_CLASS(Phalcon_Acl);

#endif /* PHALCON_ACL_H */


#ifndef PHALCON_ACL_ADAPTER_H
#define PHALCON_ACL_ADAPTER_H

#include "php_phalcon.h"

zend_class_entry *phalcon_acl_adapter_ce;

PHALCON_INIT_CLASS(Phalcon_Acl_Adapter);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_setdefaultaction, 0, 0, 1)
	ZEND_ARG_INFO(0, defaultAccess)
ZEND_END_ARG_INFO()

#endif /* PHALCON_ACL_ADAPTER_H */


#ifndef PHALCON_ACL_ADAPTERINTERFACE_H
#define PHALCON_ACL_ADAPTERINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_acl_adapterinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Acl_AdapterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapterinterface_setdefaultaction, 0, 0, 1)
	ZEND_ARG_INFO(0, defaultAccess)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapterinterface_addrole, 0, 0, 1)
	ZEND_ARG_INFO(0, role)
	ZEND_ARG_INFO(0, accessInherits)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapterinterface_addinherit, 0, 0, 2)
	ZEND_ARG_INFO(0, roleName)
	ZEND_ARG_INFO(0, roleToInherit)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapterinterface_isrole, 0, 0, 1)
	ZEND_ARG_INFO(0, roleName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapterinterface_isresource, 0, 0, 1)
	ZEND_ARG_INFO(0, resourceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapterinterface_addresource, 0, 0, 1)
	ZEND_ARG_INFO(0, resource)
	ZEND_ARG_INFO(0, accessList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapterinterface_addresourceaccess, 0, 0, 2)
	ZEND_ARG_INFO(0, resourceName)
	ZEND_ARG_INFO(0, accessList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapterinterface_dropresourceaccess, 0, 0, 2)
	ZEND_ARG_INFO(0, resourceName)
	ZEND_ARG_INFO(0, accessList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapterinterface_allow, 0, 0, 3)
	ZEND_ARG_INFO(0, roleName)
	ZEND_ARG_INFO(0, resourceName)
	ZEND_ARG_INFO(0, access)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapterinterface_isallowed, 0, 0, 3)
	ZEND_ARG_INFO(0, role)
	ZEND_ARG_INFO(0, resource)
	ZEND_ARG_INFO(0, access)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapterinterface_empty, 0, 0, 0)
ZEND_END_ARG_INFO()

#endif /* PHALCON_ACL_ADAPTERINTERFACE_H */


#ifndef PHALCON_ACL_ADAPTER_MEMORY_H
#define PHALCON_ACL_ADAPTER_MEMORY_H

#include "php_phalcon.h"

zend_class_entry *phalcon_acl_adapter_memory_ce;

PHALCON_INIT_CLASS(Phalcon_Acl_Adapter_Memory);

#endif /* PHALCON_ACL_ADAPTER_MEMORY_H */


#ifndef PHALCON_ACL_EXCEPTION_H
#define PHALCON_ACL_EXCEPTION_H

#include "php_phalcon.h"

zend_class_entry *phalcon_acl_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Acl_Exception);

#endif /* PHALCON_ACL_EXCEPTION_H */


#ifndef PHALCON_ACL_RESOURCE_H
#define PHALCON_ACL_RESOURCE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_acl_resource_ce;

PHALCON_INIT_CLASS(Phalcon_Acl_Resource);

#endif /* PHALCON_ACL_RESOURCE_H */


#ifndef PHALCON_ACL_RESOURCEINTERFACE_H
#define PHALCON_ACL_RESOURCEINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_acl_resourceinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Acl_ResourceInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_resourceinterface_getname, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_resourceinterface_getdescription, 0, 0, 0)
ZEND_END_ARG_INFO()

#endif /* PHALCON_ACL_RESOURCEINTERFACE_H */


#ifndef PHALCON_ACL_ROLE_H
#define PHALCON_ACL_ROLE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_acl_role_ce;

PHALCON_INIT_CLASS(Phalcon_Acl_Role);

#endif /* PHALCON_ACL_ROLE_H */


#ifndef PHALCON_ACL_ROLEINTERFACE_H
#define PHALCON_ACL_ROLEINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_acl_roleinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Acl_RoleInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_roleinterface_getname, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_roleinterface_getdescription, 0, 0, 0)
ZEND_END_ARG_INFO()

#endif /* PHALCON_ACL_ROLEINTERFACE_H */



#ifndef PHALCON_ANNOTATIONS_ADAPTER_H
#define PHALCON_ANNOTATIONS_ADAPTER_H

#include "php_phalcon.h"

zend_class_entry *phalcon_annotations_adapter_ce;

PHALCON_INIT_CLASS(Phalcon_Annotations_Adapter);

#endif /* PHALCON_ANNOTATIONS_ADAPTER_H */

<<<<<<< HEAD
=======
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_writemetadataindex, 0, 0, 4)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, replace)
ZEND_END_ARG_INFO()
>>>>>>> master

#ifndef PHALCON_ANNOTATIONS_ADAPTERINTERFACE_H
#define PHALCON_ANNOTATIONS_ADAPTERINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_annotations_adapterinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Annotations_AdapterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapterinterface_setreader, 0, 0, 1)
	ZEND_ARG_INFO(0, reader)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapterinterface_get, 0, 0, 1)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapterinterface_getmethods, 0, 0, 1)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapterinterface_getmethod, 0, 0, 2)
	ZEND_ARG_INFO(0, className)
	ZEND_ARG_INFO(0, methodName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapterinterface_getproperties, 0, 0, 1)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapterinterface_getproperty, 0, 0, 2)
	ZEND_ARG_INFO(0, className)
	ZEND_ARG_INFO(0, propertyName)
ZEND_END_ARG_INFO()

#endif /* PHALCON_ANNOTATIONS_ADAPTERINTERFACE_H */


<<<<<<< HEAD
#ifndef PHALCON_ANNOTATIONS_ADAPTER_APC_H
#define PHALCON_ANNOTATIONS_ADAPTER_APC_H

#include "php_phalcon.h"
=======
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_setautomaticcreateattributes, 0, 0, 3)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, attributes)
	ZEND_ARG_INFO(0, replace)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_setautomaticupdateattributes, 0, 0, 3)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, attributes)
	ZEND_ARG_INFO(0, replace)
ZEND_END_ARG_INFO()
>>>>>>> master

zend_class_entry *phalcon_annotations_adapter_apc_ce;

PHALCON_INIT_CLASS(Phalcon_Annotations_Adapter_Apc);

#endif /* PHALCON_ANNOTATIONS_ADAPTER_APC_H */


<<<<<<< HEAD
#ifndef PHALCON_ANNOTATIONS_ADAPTER_FILES_H
#define PHALCON_ANNOTATIONS_ADAPTER_FILES_H
=======
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_write, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_metadatainterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, setStrategy, arginfo_phalcon_mvc_model_metadatainterface_setstrategy)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getStrategy, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, readMetaData, arginfo_phalcon_mvc_model_metadatainterface_readmetadata)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, readMetaDataIndex, arginfo_phalcon_mvc_model_metadatainterface_readmetadataindex)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, writeMetaDataIndex, arginfo_phalcon_mvc_model_metadatainterface_writemetadataindex)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, readColumnMap, arginfo_phalcon_mvc_model_metadatainterface_readcolumnmap)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, readColumnMapIndex, arginfo_phalcon_mvc_model_metadatainterface_readcolumnmapindex)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getAttributes, arginfo_phalcon_mvc_model_metadatainterface_getattributes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getPrimaryKeyAttributes, arginfo_phalcon_mvc_model_metadatainterface_getprimarykeyattributes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getNonPrimaryKeyAttributes, arginfo_phalcon_mvc_model_metadatainterface_getnonprimarykeyattributes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getNotNullAttributes, arginfo_phalcon_mvc_model_metadatainterface_getnotnullattributes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getDataTypes, arginfo_phalcon_mvc_model_metadatainterface_getdatatypes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getDataTypesNumeric, arginfo_phalcon_mvc_model_metadatainterface_getdatatypesnumeric)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getIdentityField, arginfo_phalcon_mvc_model_metadatainterface_getidentityfield)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getBindTypes, arginfo_phalcon_mvc_model_metadatainterface_getbindtypes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getAutomaticCreateAttributes, arginfo_phalcon_mvc_model_metadatainterface_getautomaticcreateattributes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getAutomaticUpdateAttributes, arginfo_phalcon_mvc_model_metadatainterface_getautomaticupdateattributes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, setAutomaticCreateAttributes, arginfo_phalcon_mvc_model_metadatainterface_setautomaticcreateattributes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, setAutomaticUpdateAttributes, arginfo_phalcon_mvc_model_metadatainterface_setautomaticupdateattributes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getColumnMap, arginfo_phalcon_mvc_model_metadatainterface_getcolumnmap)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getReverseColumnMap, arginfo_phalcon_mvc_model_metadatainterface_getreversecolumnmap)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, hasAttribute, arginfo_phalcon_mvc_model_metadatainterface_hasattribute)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, isEmpty, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, reset, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, read, arginfo_phalcon_mvc_model_metadatainterface_read)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, write, arginfo_phalcon_mvc_model_metadatainterface_write)
	PHP_FE_END
};



zend_class_entry *phalcon_db_dialectinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Db_DialectInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_limit, 0, 0, 2)
	ZEND_ARG_INFO(0, sqlQuery)
	ZEND_ARG_INFO(0, number)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_forupdate, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_sharedlock, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_select, 0, 0, 1)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_getcolumnlist, 0, 0, 1)
	ZEND_ARG_INFO(0, columnList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_getcolumndefinition, 0, 0, 1)
	ZEND_ARG_INFO(0, column)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_addcolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, column)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_modifycolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, column)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_dropcolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, columnName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_addindex, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_dropindex, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, indexName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_addprimarykey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_dropprimarykey, 0, 0, 2)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_addforeignkey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, reference)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_dropforeignkey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, referenceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_createtable, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_droptable, 0, 0, 2)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_tableexists, 0, 0, 1)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_describecolumns, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_listtables, 0, 0, 0)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_describeindexes, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_describereferences, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_tableoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_createsavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_releasesavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_rollbacksavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_db_dialectinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, limit, arginfo_phalcon_db_dialectinterface_limit)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, forUpdate, arginfo_phalcon_db_dialectinterface_forupdate)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, sharedLock, arginfo_phalcon_db_dialectinterface_sharedlock)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, select, arginfo_phalcon_db_dialectinterface_select)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, getColumnList, arginfo_phalcon_db_dialectinterface_getcolumnlist)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, getColumnDefinition, arginfo_phalcon_db_dialectinterface_getcolumndefinition)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, addColumn, arginfo_phalcon_db_dialectinterface_addcolumn)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, modifyColumn, arginfo_phalcon_db_dialectinterface_modifycolumn)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, dropColumn, arginfo_phalcon_db_dialectinterface_dropcolumn)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, addIndex, arginfo_phalcon_db_dialectinterface_addindex)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, dropIndex, arginfo_phalcon_db_dialectinterface_dropindex)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, addPrimaryKey, arginfo_phalcon_db_dialectinterface_addprimarykey)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, dropPrimaryKey, arginfo_phalcon_db_dialectinterface_dropprimarykey)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, addForeignKey, arginfo_phalcon_db_dialectinterface_addforeignkey)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, dropForeignKey, arginfo_phalcon_db_dialectinterface_dropforeignkey)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, createTable, arginfo_phalcon_db_dialectinterface_createtable)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, dropTable, arginfo_phalcon_db_dialectinterface_droptable)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, tableExists, arginfo_phalcon_db_dialectinterface_tableexists)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, describeColumns, arginfo_phalcon_db_dialectinterface_describecolumns)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, listTables, arginfo_phalcon_db_dialectinterface_listtables)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, describeIndexes, arginfo_phalcon_db_dialectinterface_describeindexes)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, describeReferences, arginfo_phalcon_db_dialectinterface_describereferences)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, tableOptions, arginfo_phalcon_db_dialectinterface_tableoptions)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, supportsSavepoints, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, supportsReleaseSavepoints, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, createSavepoint, arginfo_phalcon_db_dialectinterface_createsavepoint)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, releaseSavepoint, arginfo_phalcon_db_dialectinterface_releasesavepoint)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, rollbackSavepoint, arginfo_phalcon_db_dialectinterface_rollbacksavepoint)
	PHP_FE_END
};



zend_class_entry *phalcon_db_adapterinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Db_AdapterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, descriptor)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_fetchone, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
	ZEND_ARG_INFO(0, fetchMode)
	ZEND_ARG_INFO(0, placeholders)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_fetchall, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
	ZEND_ARG_INFO(0, fetchMode)
	ZEND_ARG_INFO(0, placeholders)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_insert, 0, 0, 2)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_update, 0, 0, 3)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, whereCondition)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, whereCondition)
	ZEND_ARG_INFO(0, placeholders)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_getcolumnlist, 0, 0, 1)
	ZEND_ARG_INFO(0, columnList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_limit, 0, 0, 2)
	ZEND_ARG_INFO(0, sqlQuery)
	ZEND_ARG_INFO(0, number)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_tableexists, 0, 0, 1)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_viewexists, 0, 0, 1)
	ZEND_ARG_INFO(0, viewName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_forupdate, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_sharedlock, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_createtable, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_droptable, 0, 0, 1)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, ifExists)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_createview, 0, 0, 2)
	ZEND_ARG_INFO(0, viewName)
	ZEND_ARG_INFO(0, definition)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_dropview, 0, 0, 1)
	ZEND_ARG_INFO(0, viewName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, ifExists)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_addcolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, column)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_modifycolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, column)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_dropcolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, columnName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_addindex, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_dropindex, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, indexName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_addprimarykey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_dropprimarykey, 0, 0, 2)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_addforeignkey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, reference)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_dropforeignkey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, referenceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_getcolumndefinition, 0, 0, 1)
	ZEND_ARG_INFO(0, column)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_listtables, 0, 0, 0)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_listviews, 0, 0, 0)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_connect, 0, 0, 0)
	ZEND_ARG_INFO(0, descriptor)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_query, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlStatement)
	ZEND_ARG_INFO(0, placeholders)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_execute, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlStatement)
	ZEND_ARG_INFO(0, placeholders)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_escapeidentifier, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_escapestring, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_convertboundparams, 0, 0, 2)
	ZEND_ARG_INFO(0, sqlStatement)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_lastinsertid, 0, 0, 0)
	ZEND_ARG_INFO(0, sequenceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_describeindexes, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_describereferences, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_tableoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_createsavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_releasesavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_rollbacksavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_setnestedtransactionswithsavepoints, 0, 0, 1)
	ZEND_ARG_INFO(0, nestedTransactionsWithSavepoints)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_describecolumns, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_db_adapterinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, __construct, arginfo_phalcon_db_adapterinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, fetchOne, arginfo_phalcon_db_adapterinterface_fetchone)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, fetchAll, arginfo_phalcon_db_adapterinterface_fetchall)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, insert, arginfo_phalcon_db_adapterinterface_insert)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, update, arginfo_phalcon_db_adapterinterface_update)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, delete, arginfo_phalcon_db_adapterinterface_delete)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getColumnList, arginfo_phalcon_db_adapterinterface_getcolumnlist)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, limit, arginfo_phalcon_db_adapterinterface_limit)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, tableExists, arginfo_phalcon_db_adapterinterface_tableexists)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, viewExists, arginfo_phalcon_db_adapterinterface_viewexists)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, forUpdate, arginfo_phalcon_db_adapterinterface_forupdate)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, sharedLock, arginfo_phalcon_db_adapterinterface_sharedlock)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, createTable, arginfo_phalcon_db_adapterinterface_createtable)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, dropTable, arginfo_phalcon_db_adapterinterface_droptable)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, createView, arginfo_phalcon_db_adapterinterface_createview)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, dropView, arginfo_phalcon_db_adapterinterface_dropview)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, addColumn, arginfo_phalcon_db_adapterinterface_addcolumn)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, modifyColumn, arginfo_phalcon_db_adapterinterface_modifycolumn)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, dropColumn, arginfo_phalcon_db_adapterinterface_dropcolumn)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, addIndex, arginfo_phalcon_db_adapterinterface_addindex)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, dropIndex, arginfo_phalcon_db_adapterinterface_dropindex)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, addPrimaryKey, arginfo_phalcon_db_adapterinterface_addprimarykey)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, dropPrimaryKey, arginfo_phalcon_db_adapterinterface_dropprimarykey)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, addForeignKey, arginfo_phalcon_db_adapterinterface_addforeignkey)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, dropForeignKey, arginfo_phalcon_db_adapterinterface_dropforeignkey)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getColumnDefinition, arginfo_phalcon_db_adapterinterface_getcolumndefinition)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, listTables, arginfo_phalcon_db_adapterinterface_listtables)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, listViews, arginfo_phalcon_db_adapterinterface_listviews)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getDescriptor, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getConnectionId, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getSQLStatement, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getRealSQLStatement, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getSQLVariables, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getSQLBindTypes, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getType, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getDialectType, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getDialect, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, connect, arginfo_phalcon_db_adapterinterface_connect)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, query, arginfo_phalcon_db_adapterinterface_query)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, execute, arginfo_phalcon_db_adapterinterface_execute)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, affectedRows, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, close, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, escapeIdentifier, arginfo_phalcon_db_adapterinterface_escapeidentifier)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, escapeString, arginfo_phalcon_db_adapterinterface_escapestring)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, convertBoundParams, arginfo_phalcon_db_adapterinterface_convertboundparams)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, lastInsertId, arginfo_phalcon_db_adapterinterface_lastinsertid)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, begin, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, rollback, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, commit, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, isUnderTransaction, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getInternalHandler, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, describeIndexes, arginfo_phalcon_db_adapterinterface_describeindexes)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, describeReferences, arginfo_phalcon_db_adapterinterface_describereferences)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, tableOptions, arginfo_phalcon_db_adapterinterface_tableoptions)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, useExplicitIdValue, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getDefaultIdValue, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, supportSequences, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, createSavepoint, arginfo_phalcon_db_adapterinterface_createsavepoint)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, releaseSavepoint, arginfo_phalcon_db_adapterinterface_releasesavepoint)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, rollbackSavepoint, arginfo_phalcon_db_adapterinterface_rollbacksavepoint)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, setNestedTransactionsWithSavepoints, arginfo_phalcon_db_adapterinterface_setnestedtransactionswithsavepoints)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, isNestedTransactionsWithSavepoints, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getNestedTransactionSavepointName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, describeColumns, arginfo_phalcon_db_adapterinterface_describecolumns)
	PHP_FE_END
};



zend_class_entry *phalcon_annotations_adapterinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Annotations_AdapterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapterinterface_setreader, 0, 0, 1)
	ZEND_ARG_INFO(0, reader)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapterinterface_get, 0, 0, 1)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapterinterface_getmethods, 0, 0, 1)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapterinterface_getmethod, 0, 0, 2)
	ZEND_ARG_INFO(0, className)
	ZEND_ARG_INFO(0, methodName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapterinterface_getproperties, 0, 0, 1)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapterinterface_getproperty, 0, 0, 2)
	ZEND_ARG_INFO(0, className)
	ZEND_ARG_INFO(0, propertyName)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_annotations_adapterinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Annotations_AdapterInterface, setReader, arginfo_phalcon_annotations_adapterinterface_setreader)
	PHP_ABSTRACT_ME(Phalcon_Annotations_AdapterInterface, getReader, NULL)
	PHP_ABSTRACT_ME(Phalcon_Annotations_AdapterInterface, get, arginfo_phalcon_annotations_adapterinterface_get)
	PHP_ABSTRACT_ME(Phalcon_Annotations_AdapterInterface, getMethods, arginfo_phalcon_annotations_adapterinterface_getmethods)
	PHP_ABSTRACT_ME(Phalcon_Annotations_AdapterInterface, getMethod, arginfo_phalcon_annotations_adapterinterface_getmethod)
	PHP_ABSTRACT_ME(Phalcon_Annotations_AdapterInterface, getProperties, arginfo_phalcon_annotations_adapterinterface_getproperties)
	PHP_ABSTRACT_ME(Phalcon_Annotations_AdapterInterface, getProperty, arginfo_phalcon_annotations_adapterinterface_getproperty)
	PHP_FE_END
};



zend_class_entry *phalcon_logger_adapterinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Logger_AdapterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_setformatter, 0, 0, 1)
	ZEND_ARG_INFO(0, formatter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_setloglevel, 0, 0, 1)
	ZEND_ARG_INFO(0, level)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_log, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_debug, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_error, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_info, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_notice, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_warning, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_alert, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_logger_adapterinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, setFormatter, arginfo_phalcon_logger_adapterinterface_setformatter)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, getFormatter, NULL)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, setLogLevel, arginfo_phalcon_logger_adapterinterface_setloglevel)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, getLogLevel, NULL)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, log, arginfo_phalcon_logger_adapterinterface_log)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, begin, NULL)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, commit, NULL)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, rollback, NULL)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, close, NULL)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, debug, arginfo_phalcon_logger_adapterinterface_debug)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, error, arginfo_phalcon_logger_adapterinterface_error)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, info, arginfo_phalcon_logger_adapterinterface_info)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, notice, arginfo_phalcon_logger_adapterinterface_notice)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, warning, arginfo_phalcon_logger_adapterinterface_warning)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, alert, arginfo_phalcon_logger_adapterinterface_alert)
	PHP_FE_END
};



zend_class_entry *phalcon_logger_formatterinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Logger_FormatterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_formatterinterface_format, 0, 0, 3)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, timestamp)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_logger_formatterinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Logger_FormatterInterface, format, arginfo_phalcon_logger_formatterinterface_format)
	PHP_FE_END
};



zend_class_entry *phalcon_paginator_adapterinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Paginator_AdapterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_paginator_adapterinterface___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_paginator_adapterinterface_setcurrentpage, 0, 0, 1)
	ZEND_ARG_INFO(0, page)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_paginator_adapterinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Paginator_AdapterInterface, __construct, arginfo_phalcon_paginator_adapterinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Paginator_AdapterInterface, setCurrentPage, arginfo_phalcon_paginator_adapterinterface_setcurrentpage)
	PHP_ABSTRACT_ME(Phalcon_Paginator_AdapterInterface, getPaginate, NULL)
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_view_engineinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_View_EngineInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engineinterface___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, view)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engineinterface_partial, 0, 0, 1)
	ZEND_ARG_INFO(0, partialPath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engineinterface_render, 0, 0, 2)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_INFO(0, mustClean)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_view_engineinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Mvc_View_EngineInterface, __construct, arginfo_phalcon_mvc_view_engineinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Mvc_View_EngineInterface, getContent, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_View_EngineInterface, partial, arginfo_phalcon_mvc_view_engineinterface_partial)
	PHP_ABSTRACT_ME(Phalcon_Mvc_View_EngineInterface, render, arginfo_phalcon_mvc_view_engineinterface_render)
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_resultsetinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_ResultsetInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultsetinterface_setisfresh, 0, 0, 1)
	ZEND_ARG_INFO(0, isFresh)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_resultsetinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ResultsetInterface, getType, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ResultsetInterface, getFirst, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ResultsetInterface, getLast, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ResultsetInterface, setIsFresh, arginfo_phalcon_mvc_model_resultsetinterface_setisfresh)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ResultsetInterface, isFresh, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ResultsetInterface, getCache, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ResultsetInterface, toArray, NULL)
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_behaviorinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_BehaviorInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_behaviorinterface___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_behaviorinterface_notify, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_behaviorinterface_missingmethod, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_behaviorinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_BehaviorInterface, __construct, arginfo_phalcon_mvc_model_behaviorinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_BehaviorInterface, notify, arginfo_phalcon_mvc_model_behaviorinterface_notify)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_BehaviorInterface, missingMethod, arginfo_phalcon_mvc_model_behaviorinterface_missingmethod)
	PHP_FE_END
};



zend_class_entry *phalcon_flashinterface_ce;

PHALCON_INIT_CLASS(Phalcon_FlashInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flashinterface_error, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flashinterface_notice, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flashinterface_success, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flashinterface_warning, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flashinterface_message, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_flashinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_FlashInterface, error, arginfo_phalcon_flashinterface_error)
	PHP_ABSTRACT_ME(Phalcon_FlashInterface, notice, arginfo_phalcon_flashinterface_notice)
	PHP_ABSTRACT_ME(Phalcon_FlashInterface, success, arginfo_phalcon_flashinterface_success)
	PHP_ABSTRACT_ME(Phalcon_FlashInterface, warning, arginfo_phalcon_flashinterface_warning)
	PHP_ABSTRACT_ME(Phalcon_FlashInterface, message, arginfo_phalcon_flashinterface_message)
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_resultinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_ResultInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultinterface_setdirtystate, 0, 0, 1)
	ZEND_ARG_INFO(0, dirtyState)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_resultinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ResultInterface, setDirtyState, arginfo_phalcon_mvc_model_resultinterface_setdirtystate)
	PHP_FE_END
};



zend_class_entry *phalcon_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Exception);


zend_class_entry *phalcon_db_adapter_ce;

PHALCON_INIT_CLASS(Phalcon_Db_Adapter);

static PHP_METHOD(Phalcon_Db_Adapter, __construct);
static PHP_METHOD(Phalcon_Db_Adapter, setEventsManager);
static PHP_METHOD(Phalcon_Db_Adapter, getEventsManager);
static PHP_METHOD(Phalcon_Db_Adapter, setDialect);
static PHP_METHOD(Phalcon_Db_Adapter, getDialect);
static PHP_METHOD(Phalcon_Db_Adapter, fetchOne);
static PHP_METHOD(Phalcon_Db_Adapter, fetchAll);
static PHP_METHOD(Phalcon_Db_Adapter, insert);
static PHP_METHOD(Phalcon_Db_Adapter, update);
static PHP_METHOD(Phalcon_Db_Adapter, delete);
static PHP_METHOD(Phalcon_Db_Adapter, getColumnList);
static PHP_METHOD(Phalcon_Db_Adapter, limit);
static PHP_METHOD(Phalcon_Db_Adapter, tableExists);
static PHP_METHOD(Phalcon_Db_Adapter, viewExists);
static PHP_METHOD(Phalcon_Db_Adapter, forUpdate);
static PHP_METHOD(Phalcon_Db_Adapter, sharedLock);
static PHP_METHOD(Phalcon_Db_Adapter, createTable);
static PHP_METHOD(Phalcon_Db_Adapter, dropTable);
static PHP_METHOD(Phalcon_Db_Adapter, createView);
static PHP_METHOD(Phalcon_Db_Adapter, dropView);
static PHP_METHOD(Phalcon_Db_Adapter, addColumn);
static PHP_METHOD(Phalcon_Db_Adapter, modifyColumn);
static PHP_METHOD(Phalcon_Db_Adapter, dropColumn);
static PHP_METHOD(Phalcon_Db_Adapter, addIndex);
static PHP_METHOD(Phalcon_Db_Adapter, dropIndex);
static PHP_METHOD(Phalcon_Db_Adapter, addPrimaryKey);
static PHP_METHOD(Phalcon_Db_Adapter, dropPrimaryKey);
static PHP_METHOD(Phalcon_Db_Adapter, addForeignKey);
static PHP_METHOD(Phalcon_Db_Adapter, dropForeignKey);
static PHP_METHOD(Phalcon_Db_Adapter, getColumnDefinition);
static PHP_METHOD(Phalcon_Db_Adapter, listTables);
static PHP_METHOD(Phalcon_Db_Adapter, listViews);
static PHP_METHOD(Phalcon_Db_Adapter, describeIndexes);
static PHP_METHOD(Phalcon_Db_Adapter, describeReferences);
static PHP_METHOD(Phalcon_Db_Adapter, tableOptions);
static PHP_METHOD(Phalcon_Db_Adapter, createSavepoint);
static PHP_METHOD(Phalcon_Db_Adapter, releaseSavepoint);
static PHP_METHOD(Phalcon_Db_Adapter, rollbackSavepoint);
static PHP_METHOD(Phalcon_Db_Adapter, setNestedTransactionsWithSavepoints);
static PHP_METHOD(Phalcon_Db_Adapter, isNestedTransactionsWithSavepoints);
static PHP_METHOD(Phalcon_Db_Adapter, getNestedTransactionSavepointName);
static PHP_METHOD(Phalcon_Db_Adapter, getDefaultIdValue);
static PHP_METHOD(Phalcon_Db_Adapter, supportSequences);
static PHP_METHOD(Phalcon_Db_Adapter, useExplicitIdValue);
static PHP_METHOD(Phalcon_Db_Adapter, getDescriptor);
static PHP_METHOD(Phalcon_Db_Adapter, getConnectionId);
static PHP_METHOD(Phalcon_Db_Adapter, getSQLStatement);
static PHP_METHOD(Phalcon_Db_Adapter, getRealSQLStatement);
static PHP_METHOD(Phalcon_Db_Adapter, getSQLVariables);
static PHP_METHOD(Phalcon_Db_Adapter, getSQLBindTypes);
static PHP_METHOD(Phalcon_Db_Adapter, getType);
static PHP_METHOD(Phalcon_Db_Adapter, getDialectType);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_seteventsmanager, 0, 0, 1)
	ZEND_ARG_INFO(0, eventsManager)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_setdialect, 0, 0, 1)
	ZEND_ARG_INFO(0, dialect)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_fetchone, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
	ZEND_ARG_INFO(0, fetchMode)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_fetchall, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
	ZEND_ARG_INFO(0, fetchMode)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_insert, 0, 0, 2)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_update, 0, 0, 3)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, whereCondition)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, whereCondition)
	ZEND_ARG_INFO(0, placeholders)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_getcolumnlist, 0, 0, 1)
	ZEND_ARG_INFO(0, columnList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_limit, 0, 0, 2)
	ZEND_ARG_INFO(0, sqlQuery)
	ZEND_ARG_INFO(0, number)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_tableexists, 0, 0, 1)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_viewexists, 0, 0, 1)
	ZEND_ARG_INFO(0, viewName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_forupdate, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_sharedlock, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_createtable, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_droptable, 0, 0, 1)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, ifExists)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_createview, 0, 0, 2)
	ZEND_ARG_INFO(0, viewName)
	ZEND_ARG_INFO(0, definition)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_dropview, 0, 0, 1)
	ZEND_ARG_INFO(0, viewName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, ifExists)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_addcolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, column)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_modifycolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, column)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_dropcolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, columnName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_addindex, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_dropindex, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, indexName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_addprimarykey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_dropprimarykey, 0, 0, 2)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_addforeignkey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, reference)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_dropforeignkey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, referenceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_getcolumndefinition, 0, 0, 1)
	ZEND_ARG_INFO(0, column)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_listtables, 0, 0, 0)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_listviews, 0, 0, 0)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_describeindexes, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_describereferences, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_tableoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_createsavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_releasesavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_rollbacksavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_setnestedtransactionswithsavepoints, 0, 0, 1)
	ZEND_ARG_INFO(0, nestedTransactionsWithSavepoints)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_db_adapter_method_entry){
	PHP_ME(Phalcon_Db_Adapter, __construct, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Db_Adapter, setEventsManager, arginfo_phalcon_db_adapter_seteventsmanager, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, getEventsManager, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, setDialect, arginfo_phalcon_db_adapter_setdialect, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, getDialect, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, fetchOne, arginfo_phalcon_db_adapter_fetchone, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, fetchAll, arginfo_phalcon_db_adapter_fetchall, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, insert, arginfo_phalcon_db_adapter_insert, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, update, arginfo_phalcon_db_adapter_update, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, delete, arginfo_phalcon_db_adapter_delete, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, getColumnList, arginfo_phalcon_db_adapter_getcolumnlist, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, limit, arginfo_phalcon_db_adapter_limit, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, tableExists, arginfo_phalcon_db_adapter_tableexists, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, viewExists, arginfo_phalcon_db_adapter_viewexists, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, forUpdate, arginfo_phalcon_db_adapter_forupdate, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, sharedLock, arginfo_phalcon_db_adapter_sharedlock, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, createTable, arginfo_phalcon_db_adapter_createtable, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, dropTable, arginfo_phalcon_db_adapter_droptable, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, createView, arginfo_phalcon_db_adapter_createview, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, dropView, arginfo_phalcon_db_adapter_dropview, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, addColumn, arginfo_phalcon_db_adapter_addcolumn, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, modifyColumn, arginfo_phalcon_db_adapter_modifycolumn, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, dropColumn, arginfo_phalcon_db_adapter_dropcolumn, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, addIndex, arginfo_phalcon_db_adapter_addindex, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, dropIndex, arginfo_phalcon_db_adapter_dropindex, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, addPrimaryKey, arginfo_phalcon_db_adapter_addprimarykey, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, dropPrimaryKey, arginfo_phalcon_db_adapter_dropprimarykey, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, addForeignKey, arginfo_phalcon_db_adapter_addforeignkey, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, dropForeignKey, arginfo_phalcon_db_adapter_dropforeignkey, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, getColumnDefinition, arginfo_phalcon_db_adapter_getcolumndefinition, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, listTables, arginfo_phalcon_db_adapter_listtables, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, listViews, arginfo_phalcon_db_adapter_listviews, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, describeIndexes, arginfo_phalcon_db_adapter_describeindexes, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, describeReferences, arginfo_phalcon_db_adapter_describereferences, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, tableOptions, arginfo_phalcon_db_adapter_tableoptions, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, createSavepoint, arginfo_phalcon_db_adapter_createsavepoint, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, releaseSavepoint, arginfo_phalcon_db_adapter_releasesavepoint, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, rollbackSavepoint, arginfo_phalcon_db_adapter_rollbacksavepoint, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, setNestedTransactionsWithSavepoints, arginfo_phalcon_db_adapter_setnestedtransactionswithsavepoints, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, isNestedTransactionsWithSavepoints, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, getNestedTransactionSavepointName, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, getDefaultIdValue, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, supportSequences, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, useExplicitIdValue, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, getDescriptor, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, getConnectionId, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, getSQLStatement, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, getRealSQLStatement, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, getSQLVariables, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, getSQLBindTypes, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, getType, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, getDialectType, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_dispatcherinterface_ce;

PHALCON_INIT_CLASS(Phalcon_DispatcherInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcherinterface_setactionsuffix, 0, 0, 1)
	ZEND_ARG_INFO(0, actionSuffix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcherinterface_setdefaultnamespace, 0, 0, 1)
	ZEND_ARG_INFO(0, namespace)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcherinterface_setdefaultaction, 0, 0, 1)
	ZEND_ARG_INFO(0, actionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcherinterface_setactionname, 0, 0, 1)
	ZEND_ARG_INFO(0, actionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcherinterface_setparams, 0, 0, 1)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcherinterface_setparam, 0, 0, 2)
	ZEND_ARG_INFO(0, param)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcherinterface_getparam, 0, 0, 1)
	ZEND_ARG_INFO(0, param)
	ZEND_ARG_INFO(0, filters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcherinterface_forward, 0, 0, 1)
	ZEND_ARG_INFO(0, forward)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_dispatcherinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, setActionSuffix, arginfo_phalcon_dispatcherinterface_setactionsuffix)
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, setDefaultNamespace, arginfo_phalcon_dispatcherinterface_setdefaultnamespace)
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, setDefaultAction, arginfo_phalcon_dispatcherinterface_setdefaultaction)
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, setActionName, arginfo_phalcon_dispatcherinterface_setactionname)
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, getActionName, NULL)
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, setParams, arginfo_phalcon_dispatcherinterface_setparams)
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, getParams, NULL)
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, setParam, arginfo_phalcon_dispatcherinterface_setparam)
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, getParam, arginfo_phalcon_dispatcherinterface_getparam)
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, isFinished, NULL)
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, getReturnedValue, NULL)
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, dispatch, NULL)
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, forward, arginfo_phalcon_dispatcherinterface_forward)
	PHP_FE_END
};



zend_class_entry *phalcon_di_injectable_ce;

PHALCON_INIT_CLASS(Phalcon_DI_Injectable);

static PHP_METHOD(Phalcon_DI_Injectable, setDI);
static PHP_METHOD(Phalcon_DI_Injectable, getDI);
static PHP_METHOD(Phalcon_DI_Injectable, setEventsManager);
static PHP_METHOD(Phalcon_DI_Injectable, getEventsManager);
static PHP_METHOD(Phalcon_DI_Injectable, __get);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_injectable_setdi, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_injectable_seteventsmanager, 0, 0, 1)
	ZEND_ARG_INFO(0, eventsManager)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_injectable___get, 0, 0, 1)
	ZEND_ARG_INFO(0, propertyName)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_di_injectable_method_entry){
	PHP_ME(Phalcon_DI_Injectable, setDI, arginfo_phalcon_di_injectable_setdi, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_DI_Injectable, getDI, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_DI_Injectable, setEventsManager, arginfo_phalcon_di_injectable_seteventsmanager, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_DI_Injectable, getEventsManager, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_DI_Injectable, __get, arginfo_phalcon_di_injectable___get, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_dispatcherinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_DispatcherInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_dispatcherinterface_setcontrollersuffix, 0, 0, 1)
	ZEND_ARG_INFO(0, controllerSuffix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_dispatcherinterface_setdefaultcontroller, 0, 0, 1)
	ZEND_ARG_INFO(0, controllerName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_dispatcherinterface_setcontrollername, 0, 0, 1)
	ZEND_ARG_INFO(0, controllerName)
	ZEND_ARG_INFO(0, isExact)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_dispatcherinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Mvc_DispatcherInterface, setControllerSuffix, arginfo_phalcon_mvc_dispatcherinterface_setcontrollersuffix)
	PHP_ABSTRACT_ME(Phalcon_Mvc_DispatcherInterface, setDefaultController, arginfo_phalcon_mvc_dispatcherinterface_setdefaultcontroller)
	PHP_ABSTRACT_ME(Phalcon_Mvc_DispatcherInterface, setControllerName, arginfo_phalcon_mvc_dispatcherinterface_setcontrollername)
	PHP_ABSTRACT_ME(Phalcon_Mvc_DispatcherInterface, getControllerName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_DispatcherInterface, getLastController, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_DispatcherInterface, getActiveController, NULL)
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_queryinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_QueryInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_queryinterface___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, phql)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_queryinterface_execute, 0, 0, 0)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_queryinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_QueryInterface, __construct, arginfo_phalcon_mvc_model_queryinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_QueryInterface, parse, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_QueryInterface, execute, arginfo_phalcon_mvc_model_queryinterface_execute)
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_router_routeinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Router_RouteInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_routeinterface___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
	ZEND_ARG_INFO(0, httpMethods)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_routeinterface_compilepattern, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_routeinterface_via, 0, 0, 1)
	ZEND_ARG_INFO(0, httpMethods)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_routeinterface_reconfigure, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_routeinterface_setname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_routeinterface_sethttpmethods, 0, 0, 1)
	ZEND_ARG_INFO(0, httpMethods)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_router_routeinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, __construct, arginfo_phalcon_mvc_router_routeinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, compilePattern, arginfo_phalcon_mvc_router_routeinterface_compilepattern)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, via, arginfo_phalcon_mvc_router_routeinterface_via)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, reConfigure, arginfo_phalcon_mvc_router_routeinterface_reconfigure)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, getName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, setName, arginfo_phalcon_mvc_router_routeinterface_setname)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, setHttpMethods, arginfo_phalcon_mvc_router_routeinterface_sethttpmethods)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, getRouteId, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, getPattern, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, getCompiledPattern, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, getPaths, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, getHttpMethods, NULL)
	ZEND_FENTRY(reset, NULL, NULL, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_query_statusinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Query_StatusInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_statusinterface___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, success)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_query_statusinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_StatusInterface, __construct, arginfo_phalcon_mvc_model_query_statusinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_StatusInterface, getModel, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_StatusInterface, getMessages, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_StatusInterface, success, NULL)
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_query_builderinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Query_BuilderInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_columns, 0, 0, 1)
	ZEND_ARG_INFO(0, columns)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_from, 0, 0, 1)
	ZEND_ARG_INFO(0, models)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_addfrom, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_join, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_innerjoin, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_leftjoin, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_rightjoin, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_where, 0, 0, 1)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_andwhere, 0, 0, 1)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_orwhere, 0, 0, 1)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_betweenwhere, 0, 0, 3)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_INFO(0, minimum)
	ZEND_ARG_INFO(0, maximum)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_notbetweenwhere, 0, 0, 3)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_INFO(0, minimum)
	ZEND_ARG_INFO(0, maximum)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_inwhere, 0, 0, 2)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_INFO(0, values)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_notinwhere, 0, 0, 2)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_INFO(0, values)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_orderby, 0, 0, 1)
	ZEND_ARG_INFO(0, orderBy)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_having, 0, 0, 1)
	ZEND_ARG_INFO(0, having)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_limit, 0, 0, 1)
	ZEND_ARG_INFO(0, limit)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_groupby, 0, 0, 1)
	ZEND_ARG_INFO(0, group)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_query_builderinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, __construct, arginfo_phalcon_mvc_model_query_builderinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, columns, arginfo_phalcon_mvc_model_query_builderinterface_columns)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getColumns, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, from, arginfo_phalcon_mvc_model_query_builderinterface_from)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, addFrom, arginfo_phalcon_mvc_model_query_builderinterface_addfrom)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getFrom, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, join, arginfo_phalcon_mvc_model_query_builderinterface_join)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, innerJoin, arginfo_phalcon_mvc_model_query_builderinterface_innerjoin)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, leftJoin, arginfo_phalcon_mvc_model_query_builderinterface_leftjoin)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, rightJoin, arginfo_phalcon_mvc_model_query_builderinterface_rightjoin)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, where, arginfo_phalcon_mvc_model_query_builderinterface_where)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, andWhere, arginfo_phalcon_mvc_model_query_builderinterface_andwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, orWhere, arginfo_phalcon_mvc_model_query_builderinterface_orwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, betweenWhere, arginfo_phalcon_mvc_model_query_builderinterface_betweenwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, notBetweenWhere, arginfo_phalcon_mvc_model_query_builderinterface_notbetweenwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, inWhere, arginfo_phalcon_mvc_model_query_builderinterface_inwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, notInWhere, arginfo_phalcon_mvc_model_query_builderinterface_notinwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getWhere, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, orderBy, arginfo_phalcon_mvc_model_query_builderinterface_orderby)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getOrderBy, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, having, arginfo_phalcon_mvc_model_query_builderinterface_having)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getHaving, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, limit, arginfo_phalcon_mvc_model_query_builderinterface_limit)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getLimit, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, groupBy, arginfo_phalcon_mvc_model_query_builderinterface_groupby)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getGroupBy, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getPhql, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getQuery, NULL)
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_collectioninterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_CollectionInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface_setid, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface_setconnectionservice, 0, 0, 1)
	ZEND_ARG_INFO(0, connectionService)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface_readattribute, 0, 0, 1)
	ZEND_ARG_INFO(0, attribute)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface_writeattribute, 0, 0, 2)
	ZEND_ARG_INFO(0, attribute)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface_cloneresult, 0, 0, 2)
	ZEND_ARG_INFO(0, collection)
	ZEND_ARG_INFO(0, document)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface_fireevent, 0, 0, 1)
	ZEND_ARG_INFO(0, eventName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface_fireeventcancel, 0, 0, 1)
	ZEND_ARG_INFO(0, eventName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface_appendmessage, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface_findbyid, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface_findfirst, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface_find, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface_count, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_collectioninterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, __construct, arginfo_phalcon_mvc_collectioninterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, setId, arginfo_phalcon_mvc_collectioninterface_setid)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, getId, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, getReservedAttributes, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, getSource, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, setConnectionService, arginfo_phalcon_mvc_collectioninterface_setconnectionservice)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, getConnection, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, readAttribute, arginfo_phalcon_mvc_collectioninterface_readattribute)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, writeAttribute, arginfo_phalcon_mvc_collectioninterface_writeattribute)
	ZEND_FENTRY(cloneResult, NULL, arginfo_phalcon_mvc_collectioninterface_cloneresult, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, fireEvent, arginfo_phalcon_mvc_collectioninterface_fireevent)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, fireEventCancel, arginfo_phalcon_mvc_collectioninterface_fireeventcancel)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, validationHasFailed, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, getMessages, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, appendMessage, arginfo_phalcon_mvc_collectioninterface_appendmessage)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, save, NULL)
	ZEND_FENTRY(findById, NULL, arginfo_phalcon_mvc_collectioninterface_findbyid, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(findFirst, NULL, arginfo_phalcon_mvc_collectioninterface_findfirst, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(find, NULL, arginfo_phalcon_mvc_collectioninterface_find, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(count, NULL, arginfo_phalcon_mvc_collectioninterface_count, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, delete, NULL)
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_transactioninterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_TransactionInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transactioninterface___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
	ZEND_ARG_INFO(0, autoBegin)
	ZEND_ARG_INFO(0, service)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transactioninterface_settransactionmanager, 0, 0, 1)
	ZEND_ARG_INFO(0, manager)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transactioninterface_rollback, 0, 0, 0)
	ZEND_ARG_INFO(0, rollbackMessage)
	ZEND_ARG_INFO(0, rollbackRecord)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transactioninterface_setisnewtransaction, 0, 0, 1)
	ZEND_ARG_INFO(0, isNew)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transactioninterface_setrollbackonabort, 0, 0, 1)
	ZEND_ARG_INFO(0, rollbackOnAbort)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transactioninterface_setrollbackedrecord, 0, 0, 1)
	ZEND_ARG_INFO(0, record)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_transactioninterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_TransactionInterface, __construct, arginfo_phalcon_mvc_model_transactioninterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_TransactionInterface, setTransactionManager, arginfo_phalcon_mvc_model_transactioninterface_settransactionmanager)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_TransactionInterface, begin, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_TransactionInterface, commit, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_TransactionInterface, rollback, arginfo_phalcon_mvc_model_transactioninterface_rollback)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_TransactionInterface, getConnection, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_TransactionInterface, setIsNewTransaction, arginfo_phalcon_mvc_model_transactioninterface_setisnewtransaction)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_TransactionInterface, setRollbackOnAbort, arginfo_phalcon_mvc_model_transactioninterface_setrollbackonabort)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_TransactionInterface, isManaged, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_TransactionInterface, getMessages, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_TransactionInterface, isValid, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_TransactionInterface, setRollbackedRecord, arginfo_phalcon_mvc_model_transactioninterface_setrollbackedrecord)
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_urlinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_UrlInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_urlinterface_setbaseuri, 0, 0, 1)
	ZEND_ARG_INFO(0, baseUri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_urlinterface_setbasepath, 0, 0, 1)
	ZEND_ARG_INFO(0, basePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_urlinterface_get, 0, 0, 0)
	ZEND_ARG_INFO(0, uri)
	ZEND_ARG_INFO(0, args)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_urlinterface_path, 0, 0, 0)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_urlinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Mvc_UrlInterface, setBaseUri, arginfo_phalcon_mvc_urlinterface_setbaseuri)
	PHP_ABSTRACT_ME(Phalcon_Mvc_UrlInterface, getBaseUri, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_UrlInterface, setBasePath, arginfo_phalcon_mvc_urlinterface_setbasepath)
	PHP_ABSTRACT_ME(Phalcon_Mvc_UrlInterface, getBasePath, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_UrlInterface, get, arginfo_phalcon_mvc_urlinterface_get)
	PHP_ABSTRACT_ME(Phalcon_Mvc_UrlInterface, path, arginfo_phalcon_mvc_urlinterface_path)
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_viewinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_ViewInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_setviewsdir, 0, 0, 1)
	ZEND_ARG_INFO(0, viewsDir)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_setlayoutsdir, 0, 0, 1)
	ZEND_ARG_INFO(0, layoutsDir)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_setpartialsdir, 0, 0, 1)
	ZEND_ARG_INFO(0, partialsDir)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_setbasepath, 0, 0, 1)
	ZEND_ARG_INFO(0, basePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_setrenderlevel, 0, 0, 1)
	ZEND_ARG_INFO(0, level)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_setmainview, 0, 0, 1)
	ZEND_ARG_INFO(0, viewPath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_setlayout, 0, 0, 1)
	ZEND_ARG_INFO(0, layout)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_settemplatebefore, 0, 0, 1)
	ZEND_ARG_INFO(0, templateBefore)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_settemplateafter, 0, 0, 1)
	ZEND_ARG_INFO(0, templateAfter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_setparamtoview, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_setvar, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_registerengines, 0, 0, 1)
	ZEND_ARG_INFO(0, engines)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_render, 0, 0, 2)
	ZEND_ARG_INFO(0, controllerName)
	ZEND_ARG_INFO(0, actionName)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_pick, 0, 0, 1)
	ZEND_ARG_INFO(0, renderView)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_partial, 0, 0, 1)
	ZEND_ARG_INFO(0, partialPath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_cache, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_setcontent, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_viewinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, setViewsDir, arginfo_phalcon_mvc_viewinterface_setviewsdir)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, getViewsDir, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, setLayoutsDir, arginfo_phalcon_mvc_viewinterface_setlayoutsdir)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, getLayoutsDir, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, setPartialsDir, arginfo_phalcon_mvc_viewinterface_setpartialsdir)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, getPartialsDir, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, setBasePath, arginfo_phalcon_mvc_viewinterface_setbasepath)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, setRenderLevel, arginfo_phalcon_mvc_viewinterface_setrenderlevel)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, setMainView, arginfo_phalcon_mvc_viewinterface_setmainview)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, getMainView, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, setLayout, arginfo_phalcon_mvc_viewinterface_setlayout)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, getLayout, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, setTemplateBefore, arginfo_phalcon_mvc_viewinterface_settemplatebefore)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, cleanTemplateBefore, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, setTemplateAfter, arginfo_phalcon_mvc_viewinterface_settemplateafter)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, cleanTemplateAfter, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, setParamToView, arginfo_phalcon_mvc_viewinterface_setparamtoview)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, setVar, arginfo_phalcon_mvc_viewinterface_setvar)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, getParamsToView, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, getControllerName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, getActionName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, getParams, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, start, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, registerEngines, arginfo_phalcon_mvc_viewinterface_registerengines)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, render, arginfo_phalcon_mvc_viewinterface_render)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, pick, arginfo_phalcon_mvc_viewinterface_pick)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, partial, arginfo_phalcon_mvc_viewinterface_partial)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, finish, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, getCache, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, cache, arginfo_phalcon_mvc_viewinterface_cache)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, setContent, arginfo_phalcon_mvc_viewinterface_setcontent)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, getContent, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, getActiveRenderPath, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, disable, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, enable, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, reset, NULL)
	PHP_FE_END
};



zend_class_entry *phalcon_http_requestinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Http_RequestInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_get, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_getpost, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_getquery, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_getserver, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_has, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_haspost, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_hasquery, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_hasserver, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_getheader, 0, 0, 1)
	ZEND_ARG_INFO(0, header)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_getclientaddress, 0, 0, 0)
	ZEND_ARG_INFO(0, trustForwardedHeader)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_ismethod, 0, 0, 1)
	ZEND_ARG_INFO(0, methods)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_hasfiles, 0, 0, 0)
	ZEND_ARG_INFO(0, notErrored)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_getuploadedfiles, 0, 0, 0)
	ZEND_ARG_INFO(0, notErrored)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_http_requestinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, get, arginfo_phalcon_http_requestinterface_get)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getPost, arginfo_phalcon_http_requestinterface_getpost)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getQuery, arginfo_phalcon_http_requestinterface_getquery)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getServer, arginfo_phalcon_http_requestinterface_getserver)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, has, arginfo_phalcon_http_requestinterface_has)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, hasPost, arginfo_phalcon_http_requestinterface_haspost)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, hasQuery, arginfo_phalcon_http_requestinterface_hasquery)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, hasServer, arginfo_phalcon_http_requestinterface_hasserver)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getHeader, arginfo_phalcon_http_requestinterface_getheader)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getScheme, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isAjax, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isSoapRequested, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isSecureRequest, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getRawBody, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getServerAddress, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getServerName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getHttpHost, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getClientAddress, arginfo_phalcon_http_requestinterface_getclientaddress)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getMethod, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getUserAgent, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isMethod, arginfo_phalcon_http_requestinterface_ismethod)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isPost, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isGet, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isPut, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isHead, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isDelete, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isOptions, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, hasFiles, arginfo_phalcon_http_requestinterface_hasfiles)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getUploadedFiles, arginfo_phalcon_http_requestinterface_getuploadedfiles)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getHTTPReferer, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getAcceptableContent, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getBestAccept, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getClientCharsets, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getBestCharset, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getLanguages, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getBestLanguage, NULL)
	PHP_FE_END
};



zend_class_entry *phalcon_http_responseinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Http_ResponseInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_responseinterface_setstatuscode, 0, 0, 2)
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_responseinterface_setheader, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_responseinterface_setrawheader, 0, 0, 1)
	ZEND_ARG_INFO(0, header)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_responseinterface_setexpires, 0, 0, 1)
	ZEND_ARG_INFO(0, datetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_responseinterface_setcontenttype, 0, 0, 1)
	ZEND_ARG_INFO(0, contentType)
	ZEND_ARG_INFO(0, charset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_responseinterface_redirect, 0, 0, 0)
	ZEND_ARG_INFO(0, location)
	ZEND_ARG_INFO(0, externalRedirect)
	ZEND_ARG_INFO(0, statusCode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_responseinterface_setcontent, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_responseinterface_setjsoncontent, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_responseinterface_appendcontent, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_responseinterface_setfiletosend, 0, 0, 1)
	ZEND_ARG_INFO(0, filePath)
	ZEND_ARG_INFO(0, attachmentName)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_http_responseinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, setStatusCode, arginfo_phalcon_http_responseinterface_setstatuscode)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, getHeaders, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, setHeader, arginfo_phalcon_http_responseinterface_setheader)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, setRawHeader, arginfo_phalcon_http_responseinterface_setrawheader)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, resetHeaders, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, setExpires, arginfo_phalcon_http_responseinterface_setexpires)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, setNotModified, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, setContentType, arginfo_phalcon_http_responseinterface_setcontenttype)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, redirect, arginfo_phalcon_http_responseinterface_redirect)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, setContent, arginfo_phalcon_http_responseinterface_setcontent)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, setJsonContent, arginfo_phalcon_http_responseinterface_setjsoncontent)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, appendContent, arginfo_phalcon_http_responseinterface_appendcontent)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, getContent, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, sendHeaders, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, sendCookies, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, send, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, setFileToSend, arginfo_phalcon_http_responseinterface_setfiletosend)
	PHP_FE_END
};



zend_class_entry *phalcon_db_referenceinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Db_ReferenceInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_referenceinterface___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, referenceName)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_referenceinterface___set_state, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_db_referenceinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Db_ReferenceInterface, __construct, arginfo_phalcon_db_referenceinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Db_ReferenceInterface, getName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ReferenceInterface, getSchemaName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ReferenceInterface, getReferencedSchema, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ReferenceInterface, getColumns, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ReferenceInterface, getReferencedTable, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ReferenceInterface, getReferencedColumns, NULL)
	ZEND_FENTRY(__set_state, NULL, arginfo_phalcon_db_referenceinterface___set_state, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};



zend_class_entry *phalcon_db_columninterface_ce;

PHALCON_INIT_CLASS(Phalcon_Db_ColumnInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_columninterface___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, columnName)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_columninterface___set_state, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_db_columninterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, __construct, arginfo_phalcon_db_columninterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, getSchemaName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, getName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, getType, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, getSize, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, getScale, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, isUnsigned, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, isNotNull, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, isPrimary, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, isAutoIncrement, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, isNumeric, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, isFirst, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, getAfterPosition, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, getBindType, NULL)
	ZEND_FENTRY(__set_state, NULL, arginfo_phalcon_db_columninterface___set_state, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};



zend_class_entry *phalcon_db_indexinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Db_IndexInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_indexinterface___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, indexName)
	ZEND_ARG_INFO(0, columns)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_indexinterface___set_state, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_db_indexinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Db_IndexInterface, __construct, arginfo_phalcon_db_indexinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Db_IndexInterface, getName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_IndexInterface, getColumns, NULL)
	ZEND_FENTRY(__set_state, NULL, arginfo_phalcon_db_indexinterface___set_state, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};



zend_class_entry *phalcon_http_request_fileinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Http_Request_FileInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_fileinterface___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_fileinterface_moveto, 0, 0, 1)
	ZEND_ARG_INFO(0, destination)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_http_request_fileinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Http_Request_FileInterface, __construct, arginfo_phalcon_http_request_fileinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Http_Request_FileInterface, getSize, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_Request_FileInterface, getName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_Request_FileInterface, getTempName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_Request_FileInterface, getType, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_Request_FileInterface, getRealType, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_Request_FileInterface, moveTo, arginfo_phalcon_http_request_fileinterface_moveto)
	PHP_FE_END
};



zend_class_entry *phalcon_http_response_cookiesinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Http_Response_CookiesInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_cookiesinterface_useencryption, 0, 0, 1)
	ZEND_ARG_INFO(0, useEncryption)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_cookiesinterface_set, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, expire)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, secure)
	ZEND_ARG_INFO(0, domain)
	ZEND_ARG_INFO(0, httpOnly)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_cookiesinterface_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_cookiesinterface_has, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_cookiesinterface_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_http_response_cookiesinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Http_Response_CookiesInterface, useEncryption, arginfo_phalcon_http_response_cookiesinterface_useencryption)
	PHP_ABSTRACT_ME(Phalcon_Http_Response_CookiesInterface, isUsingEncryption, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_Response_CookiesInterface, set, arginfo_phalcon_http_response_cookiesinterface_set)
	PHP_ABSTRACT_ME(Phalcon_Http_Response_CookiesInterface, get, arginfo_phalcon_http_response_cookiesinterface_get)
	PHP_ABSTRACT_ME(Phalcon_Http_Response_CookiesInterface, has, arginfo_phalcon_http_response_cookiesinterface_has)
	PHP_ABSTRACT_ME(Phalcon_Http_Response_CookiesInterface, delete, arginfo_phalcon_http_response_cookiesinterface_delete)
	PHP_ABSTRACT_ME(Phalcon_Http_Response_CookiesInterface, send, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_Response_CookiesInterface, reset, NULL)
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_modelinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_ModelInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, dependencyInjector)
	ZEND_ARG_INFO(0, modelsManager)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_settransaction, 0, 0, 1)
	ZEND_ARG_INFO(0, transaction)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_setconnectionservice, 0, 0, 1)
	ZEND_ARG_INFO(0, connectionService)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_setwriteconnectionservice, 0, 0, 1)
	ZEND_ARG_INFO(0, connectionService)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_setreadconnectionservice, 0, 0, 1)
	ZEND_ARG_INFO(0, connectionService)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_assign, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, columnMap)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_cloneresultmap, 0, 0, 3)
	ZEND_ARG_INFO(0, base)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, columnMap)
	ZEND_ARG_INFO(0, dirtyState)
	ZEND_ARG_INFO(0, keepSnapshots)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_cloneresult, 0, 0, 2)
	ZEND_ARG_INFO(0, base)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, dirtyState)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_cloneresultmaphydrate, 0, 0, 3)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, columnMap)
	ZEND_ARG_INFO(0, hydrationMode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_find, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_findfirst, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_query, 0, 0, 0)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_count, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_sum, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_maximum, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_minimum, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_average, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_fireevent, 0, 0, 1)
	ZEND_ARG_INFO(0, eventName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_fireeventcancel, 0, 0, 1)
	ZEND_ARG_INFO(0, eventName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_appendmessage, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_save, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, whiteList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_create, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, whiteList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_update, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, whiteList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_readattribute, 0, 0, 1)
	ZEND_ARG_INFO(0, attribute)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_writeattribute, 0, 0, 2)
	ZEND_ARG_INFO(0, attribute)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_getrelated, 0, 0, 1)
	ZEND_ARG_INFO(0, alias)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_modelinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, __construct, arginfo_phalcon_mvc_modelinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, setTransaction, arginfo_phalcon_mvc_modelinterface_settransaction)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, getSource, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, getSchema, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, setConnectionService, arginfo_phalcon_mvc_modelinterface_setconnectionservice)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, setWriteConnectionService, arginfo_phalcon_mvc_modelinterface_setwriteconnectionservice)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, setReadConnectionService, arginfo_phalcon_mvc_modelinterface_setreadconnectionservice)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, getReadConnectionService, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, getWriteConnectionService, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, getReadConnection, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, getWriteConnection, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, assign, arginfo_phalcon_mvc_modelinterface_assign)
	ZEND_FENTRY(cloneResultMap, NULL, arginfo_phalcon_mvc_modelinterface_cloneresultmap, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(cloneResult, NULL, arginfo_phalcon_mvc_modelinterface_cloneresult, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(cloneResultMapHydrate, NULL, arginfo_phalcon_mvc_modelinterface_cloneresultmaphydrate, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(find, NULL, arginfo_phalcon_mvc_modelinterface_find, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(findFirst, NULL, arginfo_phalcon_mvc_modelinterface_findfirst, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(query, NULL, arginfo_phalcon_mvc_modelinterface_query, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(count, NULL, arginfo_phalcon_mvc_modelinterface_count, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(sum, NULL, arginfo_phalcon_mvc_modelinterface_sum, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(maximum, NULL, arginfo_phalcon_mvc_modelinterface_maximum, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(minimum, NULL, arginfo_phalcon_mvc_modelinterface_minimum, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(average, NULL, arginfo_phalcon_mvc_modelinterface_average, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, fireEvent, arginfo_phalcon_mvc_modelinterface_fireevent)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, fireEventCancel, arginfo_phalcon_mvc_modelinterface_fireeventcancel)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, appendMessage, arginfo_phalcon_mvc_modelinterface_appendmessage)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, validationHasFailed, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, getMessages, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, save, arginfo_phalcon_mvc_modelinterface_save)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, create, arginfo_phalcon_mvc_modelinterface_create)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, update, arginfo_phalcon_mvc_modelinterface_update)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, delete, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, getOperationMade, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, refresh, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, readAttribute, arginfo_phalcon_mvc_modelinterface_readattribute)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, writeAttribute, arginfo_phalcon_mvc_modelinterface_writeattribute)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, getRelated, arginfo_phalcon_mvc_modelinterface_getrelated)
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_micro_collectioninterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Micro_CollectionInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_setprefix, 0, 0, 1)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_sethandler, 0, 0, 1)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_INFO(0, lazy)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_setlazy, 0, 0, 1)
	ZEND_ARG_INFO(0, lazy)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_map, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_get, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_post, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_put, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_patch, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_head, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_delete, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_options, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_micro_collectioninterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, setPrefix, arginfo_phalcon_mvc_micro_collectioninterface_setprefix)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, getPrefix, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, getHandlers, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, setHandler, arginfo_phalcon_mvc_micro_collectioninterface_sethandler)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, setLazy, arginfo_phalcon_mvc_micro_collectioninterface_setlazy)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, isLazy, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, getHandler, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, map, arginfo_phalcon_mvc_micro_collectioninterface_map)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, get, arginfo_phalcon_mvc_micro_collectioninterface_get)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, post, arginfo_phalcon_mvc_micro_collectioninterface_post)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, put, arginfo_phalcon_mvc_micro_collectioninterface_put)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, patch, arginfo_phalcon_mvc_micro_collectioninterface_patch)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, head, arginfo_phalcon_mvc_micro_collectioninterface_head)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, delete, arginfo_phalcon_mvc_micro_collectioninterface_delete)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, options, arginfo_phalcon_mvc_micro_collectioninterface_options)
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_routerinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_RouterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_setdefaultmodule, 0, 0, 1)
	ZEND_ARG_INFO(0, moduleName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_setdefaultcontroller, 0, 0, 1)
	ZEND_ARG_INFO(0, controllerName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_setdefaultaction, 0, 0, 1)
	ZEND_ARG_INFO(0, actionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_setdefaults, 0, 0, 1)
	ZEND_ARG_INFO(0, defaults)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_handle, 0, 0, 0)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_add, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
	ZEND_ARG_INFO(0, httpMethods)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_addget, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_addpost, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_addput, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_adddelete, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_addoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_addhead, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_getroutebyid, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_getroutebyname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_routerinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, setDefaultModule, arginfo_phalcon_mvc_routerinterface_setdefaultmodule)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, setDefaultController, arginfo_phalcon_mvc_routerinterface_setdefaultcontroller)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, setDefaultAction, arginfo_phalcon_mvc_routerinterface_setdefaultaction)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, setDefaults, arginfo_phalcon_mvc_routerinterface_setdefaults)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, handle, arginfo_phalcon_mvc_routerinterface_handle)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, add, arginfo_phalcon_mvc_routerinterface_add)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, addGet, arginfo_phalcon_mvc_routerinterface_addget)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, addPost, arginfo_phalcon_mvc_routerinterface_addpost)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, addPut, arginfo_phalcon_mvc_routerinterface_addput)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, addDelete, arginfo_phalcon_mvc_routerinterface_adddelete)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, addOptions, arginfo_phalcon_mvc_routerinterface_addoptions)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, addHead, arginfo_phalcon_mvc_routerinterface_addhead)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, clear, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, getModuleName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, getControllerName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, getActionName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, getParams, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, getMatchedRoute, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, getMatches, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, wasMatched, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, getRoutes, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, getRouteById, arginfo_phalcon_mvc_routerinterface_getroutebyid)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, getRouteByName, arginfo_phalcon_mvc_routerinterface_getroutebyname)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, isExactControllerName, NULL)
	PHP_FE_END
};



zend_class_entry *phalcon_http_response_headersinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Http_Response_HeadersInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_headersinterface_set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_headersinterface_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_headersinterface_setraw, 0, 0, 1)
	ZEND_ARG_INFO(0, header)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_headersinterface___set_state, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_http_response_headersinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Http_Response_HeadersInterface, set, arginfo_phalcon_http_response_headersinterface_set)
	PHP_ABSTRACT_ME(Phalcon_Http_Response_HeadersInterface, get, arginfo_phalcon_http_response_headersinterface_get)
	PHP_ABSTRACT_ME(Phalcon_Http_Response_HeadersInterface, setRaw, arginfo_phalcon_http_response_headersinterface_setraw)
	PHP_ABSTRACT_ME(Phalcon_Http_Response_HeadersInterface, send, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_Response_HeadersInterface, reset, NULL)
	ZEND_FENTRY(__set_state, NULL, arginfo_phalcon_http_response_headersinterface___set_state, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};



zend_class_entry *phalcon_diinterface_ce;

PHALCON_INIT_CLASS(Phalcon_DiInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_diinterface_set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, definition)
	ZEND_ARG_INFO(0, shared)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_diinterface_setshared, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_diinterface_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_diinterface_attempt, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, definition)
	ZEND_ARG_INFO(0, shared)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_diinterface_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_diinterface_getshared, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_diinterface_setraw, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, rawDefinition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_diinterface_getraw, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_diinterface_getservice, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_diinterface_has, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_diinterface_setdefault, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_diinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_DiInterface, set, arginfo_phalcon_diinterface_set)
	PHP_ABSTRACT_ME(Phalcon_DiInterface, setShared, arginfo_phalcon_diinterface_setshared)
	PHP_ABSTRACT_ME(Phalcon_DiInterface, remove, arginfo_phalcon_diinterface_remove)
	PHP_ABSTRACT_ME(Phalcon_DiInterface, attempt, arginfo_phalcon_diinterface_attempt)
	PHP_ABSTRACT_ME(Phalcon_DiInterface, get, arginfo_phalcon_diinterface_get)
	PHP_ABSTRACT_ME(Phalcon_DiInterface, getShared, arginfo_phalcon_diinterface_getshared)
	PHP_ABSTRACT_ME(Phalcon_DiInterface, setRaw, arginfo_phalcon_diinterface_setraw)
	PHP_ABSTRACT_ME(Phalcon_DiInterface, getRaw, arginfo_phalcon_diinterface_getraw)
	PHP_ABSTRACT_ME(Phalcon_DiInterface, getService, arginfo_phalcon_diinterface_getservice)
	PHP_ABSTRACT_ME(Phalcon_DiInterface, has, arginfo_phalcon_diinterface_has)
	PHP_ABSTRACT_ME(Phalcon_DiInterface, wasFreshInstance, NULL)
	PHP_ABSTRACT_ME(Phalcon_DiInterface, getServices, NULL)
	ZEND_FENTRY(setDefault, NULL, arginfo_phalcon_diinterface_setdefault, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(getDefault, NULL, NULL, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(reset, NULL, NULL, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_relationinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_RelationInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_relationinterface___construct, 0, 0, 4)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, referencedModel)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, referencedFields)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_relationinterface_setintermediaterelation, 0, 0, 3)
	ZEND_ARG_INFO(0, intermediateFields)
	ZEND_ARG_INFO(0, intermediateModel)
	ZEND_ARG_INFO(0, intermediateReferencedFields)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_relationinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, __construct, arginfo_phalcon_mvc_model_relationinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, setIntermediateRelation, arginfo_phalcon_mvc_model_relationinterface_setintermediaterelation)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, getType, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, getReferencedModel, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, getFields, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, getReferencedFields, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, getOptions, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, isForeignKey, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, getForeignKey, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, isThrough, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, getIntermediateFields, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, getIntermediateModel, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, getIntermediateReferencedFields, NULL)
	PHP_FE_END
};



zend_class_entry *phalcon_acl_resourceinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Acl_ResourceInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_resourceinterface___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, description)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_acl_resourceinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Acl_ResourceInterface, __construct, arginfo_phalcon_acl_resourceinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Acl_ResourceInterface, getName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Acl_ResourceInterface, getDescription, NULL)
	PHP_ABSTRACT_ME(Phalcon_Acl_ResourceInterface, __toString, NULL)
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_managerinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_ManagerInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_initialize, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_isinitialized, 0, 0, 1)
	ZEND_ARG_INFO(0, modelName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_load, 0, 0, 2)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, newInstance)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_addhasone, 0, 0, 4)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, referencedModel)
	ZEND_ARG_INFO(0, referencedFields)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_addbelongsto, 0, 0, 4)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, referencedModel)
	ZEND_ARG_INFO(0, referencedFields)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_addhasmany, 0, 0, 4)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, referencedModel)
	ZEND_ARG_INFO(0, referencedFields)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_existsbelongsto, 0, 0, 2)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, modelRelation)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_existshasmany, 0, 0, 2)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, modelRelation)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_existshasone, 0, 0, 2)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, modelRelation)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_getbelongstorecords, 0, 0, 4)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, modelRelation)
	ZEND_ARG_INFO(0, record)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_gethasmanyrecords, 0, 0, 4)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, modelRelation)
	ZEND_ARG_INFO(0, record)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_gethasonerecords, 0, 0, 4)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, modelRelation)
	ZEND_ARG_INFO(0, record)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_getbelongsto, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_gethasmany, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_gethasone, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_gethasoneandhasmany, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_getrelations, 0, 0, 1)
	ZEND_ARG_INFO(0, modelName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_getrelationsbetween, 0, 0, 2)
	ZEND_ARG_INFO(0, first)
	ZEND_ARG_INFO(0, second)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_createquery, 0, 0, 1)
	ZEND_ARG_INFO(0, phql)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_executequery, 0, 0, 1)
	ZEND_ARG_INFO(0, phql)
	ZEND_ARG_INFO(0, placeholders)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_createbuilder, 0, 0, 0)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_addbehavior, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, behavior)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_notifyevent, 0, 0, 2)
	ZEND_ARG_INFO(0, eventName)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_missingmethod, 0, 0, 3)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, eventName)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_managerinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, initialize, arginfo_phalcon_mvc_model_managerinterface_initialize)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, isInitialized, arginfo_phalcon_mvc_model_managerinterface_isinitialized)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getLastInitialized, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, load, arginfo_phalcon_mvc_model_managerinterface_load)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, addHasOne, arginfo_phalcon_mvc_model_managerinterface_addhasone)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, addBelongsTo, arginfo_phalcon_mvc_model_managerinterface_addbelongsto)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, addHasMany, arginfo_phalcon_mvc_model_managerinterface_addhasmany)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, existsBelongsTo, arginfo_phalcon_mvc_model_managerinterface_existsbelongsto)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, existsHasMany, arginfo_phalcon_mvc_model_managerinterface_existshasmany)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, existsHasOne, arginfo_phalcon_mvc_model_managerinterface_existshasone)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getBelongsToRecords, arginfo_phalcon_mvc_model_managerinterface_getbelongstorecords)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getHasManyRecords, arginfo_phalcon_mvc_model_managerinterface_gethasmanyrecords)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getHasOneRecords, arginfo_phalcon_mvc_model_managerinterface_gethasonerecords)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getBelongsTo, arginfo_phalcon_mvc_model_managerinterface_getbelongsto)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getHasMany, arginfo_phalcon_mvc_model_managerinterface_gethasmany)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getHasOne, arginfo_phalcon_mvc_model_managerinterface_gethasone)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getHasOneAndHasMany, arginfo_phalcon_mvc_model_managerinterface_gethasoneandhasmany)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getRelations, arginfo_phalcon_mvc_model_managerinterface_getrelations)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getRelationsBetween, arginfo_phalcon_mvc_model_managerinterface_getrelationsbetween)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, createQuery, arginfo_phalcon_mvc_model_managerinterface_createquery)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, executeQuery, arginfo_phalcon_mvc_model_managerinterface_executequery)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, createBuilder, arginfo_phalcon_mvc_model_managerinterface_createbuilder)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, addBehavior, arginfo_phalcon_mvc_model_managerinterface_addbehavior)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, notifyEvent, arginfo_phalcon_mvc_model_managerinterface_notifyevent)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, missingMethod, arginfo_phalcon_mvc_model_managerinterface_missingmethod)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getLastQuery, NULL)
	PHP_FE_END
};



zend_class_entry *phalcon_filterinterface_ce;

PHALCON_INIT_CLASS(Phalcon_FilterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filterinterface_add, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filterinterface_sanitize, 0, 0, 2)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, filters)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_filterinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_FilterInterface, add, arginfo_phalcon_filterinterface_add)
	PHP_ABSTRACT_ME(Phalcon_FilterInterface, sanitize, arginfo_phalcon_filterinterface_sanitize)
	PHP_ABSTRACT_ME(Phalcon_FilterInterface, getFilters, NULL)
	PHP_FE_END
};



zend_class_entry *phalcon_cryptinterface_ce;

PHALCON_INIT_CLASS(Phalcon_CryptInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cryptinterface_setcipher, 0, 0, 1)
	ZEND_ARG_INFO(0, cipher)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cryptinterface_setmode, 0, 0, 1)
	ZEND_ARG_INFO(0, mode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cryptinterface_setkey, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cryptinterface_encrypt, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cryptinterface_decrypt, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cryptinterface_encryptbase64, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cryptinterface_decryptbase64, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_cryptinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_CryptInterface, setCipher, arginfo_phalcon_cryptinterface_setcipher)
	PHP_ABSTRACT_ME(Phalcon_CryptInterface, getCipher, NULL)
	PHP_ABSTRACT_ME(Phalcon_CryptInterface, setMode, arginfo_phalcon_cryptinterface_setmode)
	PHP_ABSTRACT_ME(Phalcon_CryptInterface, getMode, NULL)
	PHP_ABSTRACT_ME(Phalcon_CryptInterface, setKey, arginfo_phalcon_cryptinterface_setkey)
	PHP_ABSTRACT_ME(Phalcon_CryptInterface, getKey, NULL)
	PHP_ABSTRACT_ME(Phalcon_CryptInterface, encrypt, arginfo_phalcon_cryptinterface_encrypt)
	PHP_ABSTRACT_ME(Phalcon_CryptInterface, decrypt, arginfo_phalcon_cryptinterface_decrypt)
	PHP_ABSTRACT_ME(Phalcon_CryptInterface, encryptBase64, arginfo_phalcon_cryptinterface_encryptbase64)
	PHP_ABSTRACT_ME(Phalcon_CryptInterface, decryptBase64, arginfo_phalcon_cryptinterface_decryptbase64)
	PHP_ABSTRACT_ME(Phalcon_CryptInterface, getAvailableCiphers, NULL)
	PHP_ABSTRACT_ME(Phalcon_CryptInterface, getAvailableModes, NULL)
	PHP_FE_END
};



zend_class_entry *phalcon_acl_roleinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Acl_RoleInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_roleinterface___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, description)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_acl_roleinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Acl_RoleInterface, __construct, arginfo_phalcon_acl_roleinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Acl_RoleInterface, getName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Acl_RoleInterface, getDescription, NULL)
	PHP_ABSTRACT_ME(Phalcon_Acl_RoleInterface, __toString, NULL)
	PHP_FE_END
};



zend_class_entry *phalcon_session_baginterface_ce;

PHALCON_INIT_CLASS(Phalcon_Session_BagInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_baginterface_set, 0, 0, 2)
	ZEND_ARG_INFO(0, property)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_baginterface_get, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_baginterface_has, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_baginterface___set, 0, 0, 2)
	ZEND_ARG_INFO(0, property)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_baginterface___get, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_baginterface___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_session_baginterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Session_BagInterface, initialize, NULL)
	PHP_ABSTRACT_ME(Phalcon_Session_BagInterface, destroy, NULL)
	PHP_ABSTRACT_ME(Phalcon_Session_BagInterface, set, arginfo_phalcon_session_baginterface_set)
	PHP_ABSTRACT_ME(Phalcon_Session_BagInterface, get, arginfo_phalcon_session_baginterface_get)
	PHP_ABSTRACT_ME(Phalcon_Session_BagInterface, has, arginfo_phalcon_session_baginterface_has)
	PHP_ABSTRACT_ME(Phalcon_Session_BagInterface, __set, arginfo_phalcon_session_baginterface___set)
	PHP_ABSTRACT_ME(Phalcon_Session_BagInterface, __get, arginfo_phalcon_session_baginterface___get)
	PHP_ABSTRACT_ME(Phalcon_Session_BagInterface, __isset, arginfo_phalcon_session_baginterface___isset)
	PHP_FE_END
};



zend_class_entry *phalcon_session_adapterinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Session_AdapterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapterinterface___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapterinterface_setoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapterinterface_get, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapterinterface_set, 0, 0, 2)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapterinterface_has, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapterinterface_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_session_adapterinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, __construct, arginfo_phalcon_session_adapterinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, start, NULL)
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, setOptions, arginfo_phalcon_session_adapterinterface_setoptions)
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, getOptions, NULL)
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, get, arginfo_phalcon_session_adapterinterface_get)
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, set, arginfo_phalcon_session_adapterinterface_set)
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, has, arginfo_phalcon_session_adapterinterface_has)
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, remove, arginfo_phalcon_session_adapterinterface_remove)
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, getId, NULL)
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, isStarted, NULL)
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, destroy, NULL)
	PHP_FE_END
};



zend_class_entry *phalcon_di_serviceinterface_ce;

PHALCON_INIT_CLASS(Phalcon_DI_ServiceInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_serviceinterface___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, definition)
	ZEND_ARG_INFO(0, shared)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_serviceinterface_setshared, 0, 0, 1)
	ZEND_ARG_INFO(0, shared)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_serviceinterface_setdefinition, 0, 0, 1)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_serviceinterface_resolve, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_serviceinterface___set_state, 0, 0, 1)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_di_serviceinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_DI_ServiceInterface, __construct, arginfo_phalcon_di_serviceinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_DI_ServiceInterface, getName, NULL)
	PHP_ABSTRACT_ME(Phalcon_DI_ServiceInterface, setShared, arginfo_phalcon_di_serviceinterface_setshared)
	PHP_ABSTRACT_ME(Phalcon_DI_ServiceInterface, isShared, NULL)
	PHP_ABSTRACT_ME(Phalcon_DI_ServiceInterface, setDefinition, arginfo_phalcon_di_serviceinterface_setdefinition)
	PHP_ABSTRACT_ME(Phalcon_DI_ServiceInterface, getDefinition, NULL)
	PHP_ABSTRACT_ME(Phalcon_DI_ServiceInterface, resolve, arginfo_phalcon_di_serviceinterface_resolve)
	ZEND_FENTRY(__set_state, NULL, arginfo_phalcon_di_serviceinterface___set_state, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};



zend_class_entry *phalcon_annotations_readerinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Annotations_ReaderInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_readerinterface_parse, 0, 0, 1)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_readerinterface_parsedocblock, 0, 0, 1)
	ZEND_ARG_INFO(0, docBlock)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_INFO(0, line)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_annotations_readerinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Annotations_ReaderInterface, parse, arginfo_phalcon_annotations_readerinterface_parse)
	ZEND_FENTRY(parseDocBlock, NULL, arginfo_phalcon_annotations_readerinterface_parsedocblock, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};



zend_class_entry *phalcon_events_managerinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Events_ManagerInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_managerinterface_attach, 0, 0, 2)
	ZEND_ARG_INFO(0, eventType)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_managerinterface_dettachall, 0, 0, 0)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_managerinterface_fire, 0, 0, 2)
	ZEND_ARG_INFO(0, eventType)
	ZEND_ARG_INFO(0, source)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_managerinterface_getlisteners, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_events_managerinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Events_ManagerInterface, attach, arginfo_phalcon_events_managerinterface_attach)
	PHP_ABSTRACT_ME(Phalcon_Events_ManagerInterface, dettachAll, arginfo_phalcon_events_managerinterface_dettachall)
	PHP_ABSTRACT_ME(Phalcon_Events_ManagerInterface, fire, arginfo_phalcon_events_managerinterface_fire)
	PHP_ABSTRACT_ME(Phalcon_Events_ManagerInterface, getListeners, arginfo_phalcon_events_managerinterface_getlisteners)
	PHP_FE_END
};



zend_class_entry *phalcon_escaperinterface_ce;

PHALCON_INIT_CLASS(Phalcon_EscaperInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaperinterface_setencoding, 0, 0, 1)
	ZEND_ARG_INFO(0, encoding)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaperinterface_sethtmlquotetype, 0, 0, 1)
	ZEND_ARG_INFO(0, quoteType)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaperinterface_escapehtml, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaperinterface_escapehtmlattr, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaperinterface_escapecss, 0, 0, 1)
	ZEND_ARG_INFO(0, css)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaperinterface_escapejs, 0, 0, 1)
	ZEND_ARG_INFO(0, js)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaperinterface_escapeurl, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_escaperinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_EscaperInterface, setEncoding, arginfo_phalcon_escaperinterface_setencoding)
	PHP_ABSTRACT_ME(Phalcon_EscaperInterface, getEncoding, NULL)
	PHP_ABSTRACT_ME(Phalcon_EscaperInterface, setHtmlQuoteType, arginfo_phalcon_escaperinterface_sethtmlquotetype)
	PHP_ABSTRACT_ME(Phalcon_EscaperInterface, escapeHtml, arginfo_phalcon_escaperinterface_escapehtml)
	PHP_ABSTRACT_ME(Phalcon_EscaperInterface, escapeHtmlAttr, arginfo_phalcon_escaperinterface_escapehtmlattr)
	PHP_ABSTRACT_ME(Phalcon_EscaperInterface, escapeCss, arginfo_phalcon_escaperinterface_escapecss)
	PHP_ABSTRACT_ME(Phalcon_EscaperInterface, escapeJs, arginfo_phalcon_escaperinterface_escapejs)
	PHP_ABSTRACT_ME(Phalcon_EscaperInterface, escapeUrl, arginfo_phalcon_escaperinterface_escapeurl)
	PHP_FE_END
};



zend_class_entry *phalcon_acl_adapterinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Acl_AdapterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapterinterface_setdefaultaction, 0, 0, 1)
	ZEND_ARG_INFO(0, defaultAccess)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapterinterface_addrole, 0, 0, 1)
	ZEND_ARG_INFO(0, role)
	ZEND_ARG_INFO(0, accessInherits)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapterinterface_addinherit, 0, 0, 2)
	ZEND_ARG_INFO(0, roleName)
	ZEND_ARG_INFO(0, roleToInherit)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapterinterface_isrole, 0, 0, 1)
	ZEND_ARG_INFO(0, roleName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapterinterface_isresource, 0, 0, 1)
	ZEND_ARG_INFO(0, resourceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapterinterface_addresource, 0, 0, 1)
	ZEND_ARG_INFO(0, resource)
	ZEND_ARG_INFO(0, accessList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapterinterface_addresourceaccess, 0, 0, 2)
	ZEND_ARG_INFO(0, resourceName)
	ZEND_ARG_INFO(0, accessList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapterinterface_dropresourceaccess, 0, 0, 2)
	ZEND_ARG_INFO(0, resourceName)
	ZEND_ARG_INFO(0, accessList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapterinterface_allow, 0, 0, 3)
	ZEND_ARG_INFO(0, roleName)
	ZEND_ARG_INFO(0, resourceName)
	ZEND_ARG_INFO(0, access)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapterinterface_deny, 0, 0, 3)
	ZEND_ARG_INFO(0, roleName)
	ZEND_ARG_INFO(0, resourceName)
	ZEND_ARG_INFO(0, access)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapterinterface_isallowed, 0, 0, 3)
	ZEND_ARG_INFO(0, role)
	ZEND_ARG_INFO(0, resource)
	ZEND_ARG_INFO(0, access)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_acl_adapterinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, setDefaultAction, arginfo_phalcon_acl_adapterinterface_setdefaultaction)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, getDefaultAction, NULL)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, addRole, arginfo_phalcon_acl_adapterinterface_addrole)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, addInherit, arginfo_phalcon_acl_adapterinterface_addinherit)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, isRole, arginfo_phalcon_acl_adapterinterface_isrole)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, isResource, arginfo_phalcon_acl_adapterinterface_isresource)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, addResource, arginfo_phalcon_acl_adapterinterface_addresource)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, addResourceAccess, arginfo_phalcon_acl_adapterinterface_addresourceaccess)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, dropResourceAccess, arginfo_phalcon_acl_adapterinterface_dropresourceaccess)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, allow, arginfo_phalcon_acl_adapterinterface_allow)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, deny, arginfo_phalcon_acl_adapterinterface_deny)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, isAllowed, arginfo_phalcon_acl_adapterinterface_isallowed)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, getActiveRole, NULL)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, getActiveResource, NULL)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, getActiveAccess, NULL)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, getRoles, NULL)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, getResources, NULL)
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_transaction_managerinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Transaction_ManagerInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_managerinterface___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_managerinterface_get, 0, 0, 0)
	ZEND_ARG_INFO(0, autoBegin)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_managerinterface_rollback, 0, 0, 0)
	ZEND_ARG_INFO(0, collect)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_managerinterface_notifyrollback, 0, 0, 1)
	ZEND_ARG_INFO(0, transaction)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_managerinterface_notifycommit, 0, 0, 1)
	ZEND_ARG_INFO(0, transaction)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_transaction_managerinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Transaction_ManagerInterface, __construct, arginfo_phalcon_mvc_model_transaction_managerinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Transaction_ManagerInterface, has, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Transaction_ManagerInterface, get, arginfo_phalcon_mvc_model_transaction_managerinterface_get)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Transaction_ManagerInterface, rollbackPendent, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Transaction_ManagerInterface, commit, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Transaction_ManagerInterface, rollback, arginfo_phalcon_mvc_model_transaction_managerinterface_rollback)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Transaction_ManagerInterface, notifyRollback, arginfo_phalcon_mvc_model_transaction_managerinterface_notifyrollback)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Transaction_ManagerInterface, notifyCommit, arginfo_phalcon_mvc_model_transaction_managerinterface_notifycommit)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Transaction_ManagerInterface, collectTransactions, NULL)
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_criteriainterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_CriteriaInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_setmodelname, 0, 0, 1)
	ZEND_ARG_INFO(0, modelName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_bind, 0, 0, 1)
	ZEND_ARG_INFO(0, bindParams)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_bindtypes, 0, 0, 1)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_where, 0, 0, 1)
	ZEND_ARG_INFO(0, conditions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_conditions, 0, 0, 1)
	ZEND_ARG_INFO(0, conditions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_orderby, 0, 0, 1)
	ZEND_ARG_INFO(0, orderColumns)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_limit, 0, 0, 1)
	ZEND_ARG_INFO(0, limit)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_forupdate, 0, 0, 0)
	ZEND_ARG_INFO(0, forUpdate)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_sharedlock, 0, 0, 0)
	ZEND_ARG_INFO(0, sharedLock)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_andwhere, 0, 0, 1)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_orwhere, 0, 0, 1)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_betweenwhere, 0, 0, 3)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_INFO(0, minimum)
	ZEND_ARG_INFO(0, maximum)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_notbetweenwhere, 0, 0, 3)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_INFO(0, minimum)
	ZEND_ARG_INFO(0, maximum)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_inwhere, 0, 0, 2)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_INFO(0, values)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_notinwhere, 0, 0, 2)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_INFO(0, values)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_frominput, 0, 0, 3)
	ZEND_ARG_INFO(0, dependencyInjector)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_criteriainterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, setModelName, arginfo_phalcon_mvc_model_criteriainterface_setmodelname)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, getModelName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, bind, arginfo_phalcon_mvc_model_criteriainterface_bind)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, bindTypes, arginfo_phalcon_mvc_model_criteriainterface_bindtypes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, where, arginfo_phalcon_mvc_model_criteriainterface_where)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, conditions, arginfo_phalcon_mvc_model_criteriainterface_conditions)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, orderBy, arginfo_phalcon_mvc_model_criteriainterface_orderby)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, limit, arginfo_phalcon_mvc_model_criteriainterface_limit)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, forUpdate, arginfo_phalcon_mvc_model_criteriainterface_forupdate)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, sharedLock, arginfo_phalcon_mvc_model_criteriainterface_sharedlock)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, andWhere, arginfo_phalcon_mvc_model_criteriainterface_andwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, orWhere, arginfo_phalcon_mvc_model_criteriainterface_orwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, betweenWhere, arginfo_phalcon_mvc_model_criteriainterface_betweenwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, notBetweenWhere, arginfo_phalcon_mvc_model_criteriainterface_notbetweenwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, inWhere, arginfo_phalcon_mvc_model_criteriainterface_inwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, notInWhere, arginfo_phalcon_mvc_model_criteriainterface_notinwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, getWhere, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, getConditions, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, getLimit, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, getOrder, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, getParams, NULL)
	ZEND_FENTRY(fromInput, NULL, arginfo_phalcon_mvc_model_criteriainterface_frominput, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, execute, NULL)
	PHP_FE_END
};



zend_class_entry *phalcon_translate_adapterinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Translate_AdapterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapterinterface___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapterinterface__, 0, 0, 1)
	ZEND_ARG_INFO(0, translateKey)
	ZEND_ARG_INFO(0, placeholders)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapterinterface_query, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, placeholders)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapterinterface_exists, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_translate_adapterinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Translate_AdapterInterface, __construct, arginfo_phalcon_translate_adapterinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Translate_AdapterInterface, _, arginfo_phalcon_translate_adapterinterface__)
	PHP_ABSTRACT_ME(Phalcon_Translate_AdapterInterface, query, arginfo_phalcon_translate_adapterinterface_query)
	PHP_ABSTRACT_ME(Phalcon_Translate_AdapterInterface, exists, arginfo_phalcon_translate_adapterinterface_exists)
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_messageinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_MessageInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_messageinterface___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_messageinterface_settype, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_messageinterface_setmessage, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_messageinterface_setfield, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_messageinterface___set_state, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_messageinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MessageInterface, __construct, arginfo_phalcon_mvc_model_messageinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MessageInterface, setType, arginfo_phalcon_mvc_model_messageinterface_settype)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MessageInterface, getType, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MessageInterface, setMessage, arginfo_phalcon_mvc_model_messageinterface_setmessage)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MessageInterface, getMessage, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MessageInterface, setField, arginfo_phalcon_mvc_model_messageinterface_setfield)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MessageInterface, getField, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MessageInterface, __toString, NULL)
	ZEND_FENTRY(__set_state, NULL, arginfo_phalcon_mvc_model_messageinterface___set_state, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Exception);


zend_class_entry *phalcon_di_ce;

PHALCON_INIT_CLASS(Phalcon_DI);

static PHP_METHOD(Phalcon_DI, __construct);
static PHP_METHOD(Phalcon_DI, set);
static PHP_METHOD(Phalcon_DI, setShared);
static PHP_METHOD(Phalcon_DI, remove);
static PHP_METHOD(Phalcon_DI, attempt);
static PHP_METHOD(Phalcon_DI, setRaw);
static PHP_METHOD(Phalcon_DI, getRaw);
static PHP_METHOD(Phalcon_DI, getService);
static PHP_METHOD(Phalcon_DI, get);
static PHP_METHOD(Phalcon_DI, getShared);
static PHP_METHOD(Phalcon_DI, has);
static PHP_METHOD(Phalcon_DI, wasFreshInstance);
static PHP_METHOD(Phalcon_DI, getServices);
static PHP_METHOD(Phalcon_DI, __call);
static PHP_METHOD(Phalcon_DI, setDefault);
static PHP_METHOD(Phalcon_DI, getDefault);
static PHP_METHOD(Phalcon_DI, reset);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, definition)
	ZEND_ARG_INFO(0, shared)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_setshared, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_attempt, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, definition)
	ZEND_ARG_INFO(0, shared)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_setraw, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, rawDefinition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_getraw, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_getservice, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_getshared, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_has, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di___call, 0, 0, 1)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_setdefault, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_di_method_entry){
	PHP_ME(Phalcon_DI, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_DI, set, arginfo_phalcon_di_set, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_DI, setShared, arginfo_phalcon_di_setshared, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_DI, remove, arginfo_phalcon_di_remove, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_DI, attempt, arginfo_phalcon_di_attempt, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_DI, setRaw, arginfo_phalcon_di_setraw, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_DI, getRaw, arginfo_phalcon_di_getraw, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_DI, getService, arginfo_phalcon_di_getservice, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_DI, get, arginfo_phalcon_di_get, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_DI, getShared, arginfo_phalcon_di_getshared, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_DI, has, arginfo_phalcon_di_has, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_DI, wasFreshInstance, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_DI, getServices, NULL, ZEND_ACC_PUBLIC) 
	PHP_MALIAS(Phalcon_DI, offsetExists, has, arginfo_phalcon_di_has, ZEND_ACC_PUBLIC)
	PHP_MALIAS(Phalcon_DI, offsetSet, setShared, arginfo_phalcon_di_setshared, ZEND_ACC_PUBLIC)
	PHP_MALIAS(Phalcon_DI, offsetGet, getShared, arginfo_phalcon_di_getshared, ZEND_ACC_PUBLIC)
	PHP_MALIAS(Phalcon_DI, offsetUnset, remove, arginfo_phalcon_di_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DI, __call, arginfo_phalcon_di___call, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_DI, setDefault, arginfo_phalcon_di_setdefault, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_DI, getDefault, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_DI, reset, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_forms_element_ce;

PHALCON_INIT_CLASS(Phalcon_Forms_Element);

static PHP_METHOD(Phalcon_Forms_Element, __construct);
static PHP_METHOD(Phalcon_Forms_Element, setForm);
static PHP_METHOD(Phalcon_Forms_Element, getForm);
static PHP_METHOD(Phalcon_Forms_Element, setName);
static PHP_METHOD(Phalcon_Forms_Element, getName);
static PHP_METHOD(Phalcon_Forms_Element, setFilters);
static PHP_METHOD(Phalcon_Forms_Element, addFilter);
static PHP_METHOD(Phalcon_Forms_Element, getFilters);
static PHP_METHOD(Phalcon_Forms_Element, addValidators);
static PHP_METHOD(Phalcon_Forms_Element, addValidator);
static PHP_METHOD(Phalcon_Forms_Element, getValidators);
static PHP_METHOD(Phalcon_Forms_Element, prepareAttributes);
static PHP_METHOD(Phalcon_Forms_Element, setAttribute);
static PHP_METHOD(Phalcon_Forms_Element, getAttribute);
static PHP_METHOD(Phalcon_Forms_Element, setAttributes);
static PHP_METHOD(Phalcon_Forms_Element, getAttributes);
static PHP_METHOD(Phalcon_Forms_Element, setUserOption);
static PHP_METHOD(Phalcon_Forms_Element, getUserOption);
static PHP_METHOD(Phalcon_Forms_Element, setUserOptions);
static PHP_METHOD(Phalcon_Forms_Element, getUserOptions);
static PHP_METHOD(Phalcon_Forms_Element, setLabel);
static PHP_METHOD(Phalcon_Forms_Element, getLabel);
static PHP_METHOD(Phalcon_Forms_Element, label);
static PHP_METHOD(Phalcon_Forms_Element, setDefault);
static PHP_METHOD(Phalcon_Forms_Element, getDefault);
static PHP_METHOD(Phalcon_Forms_Element, getValue);
static PHP_METHOD(Phalcon_Forms_Element, getMessages);
static PHP_METHOD(Phalcon_Forms_Element, hasMessages);
static PHP_METHOD(Phalcon_Forms_Element, setMessages);
static PHP_METHOD(Phalcon_Forms_Element, appendMessage);
static PHP_METHOD(Phalcon_Forms_Element, clear);
static PHP_METHOD(Phalcon_Forms_Element, __toString);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_setform, 0, 0, 1)
	ZEND_ARG_INFO(0, form)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_setname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_setfilters, 0, 0, 1)
	ZEND_ARG_INFO(0, filters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_addfilter, 0, 0, 1)
	ZEND_ARG_INFO(0, filter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_addvalidators, 0, 0, 1)
	ZEND_ARG_INFO(0, validators)
	ZEND_ARG_INFO(0, merge)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_addvalidator, 0, 0, 1)
	ZEND_ARG_INFO(0, validator)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_prepareattributes, 0, 0, 0)
	ZEND_ARG_INFO(0, attributes)
	ZEND_ARG_INFO(0, useChecked)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_setattribute, 0, 0, 2)
	ZEND_ARG_INFO(0, attribute)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_getattribute, 0, 0, 1)
	ZEND_ARG_INFO(0, attribute)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_setattributes, 0, 0, 1)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_setuseroption, 0, 0, 2)
	ZEND_ARG_INFO(0, option)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_getuseroption, 0, 0, 1)
	ZEND_ARG_INFO(0, option)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_setuseroptions, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_setlabel, 0, 0, 1)
	ZEND_ARG_INFO(0, label)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_setdefault, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_setmessages, 0, 0, 1)
	ZEND_ARG_INFO(0, group)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_appendmessage, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_forms_element_method_entry){
	PHP_ME(Phalcon_Forms_Element, __construct, arginfo_phalcon_forms_element___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Forms_Element, setForm, arginfo_phalcon_forms_element_setform, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Forms_Element, getForm, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Forms_Element, setName, arginfo_phalcon_forms_element_setname, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Forms_Element, getName, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Forms_Element, setFilters, arginfo_phalcon_forms_element_setfilters, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Forms_Element, addFilter, arginfo_phalcon_forms_element_addfilter, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Forms_Element, getFilters, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Forms_Element, addValidators, arginfo_phalcon_forms_element_addvalidators, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Forms_Element, addValidator, arginfo_phalcon_forms_element_addvalidator, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Forms_Element, getValidators, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Forms_Element, prepareAttributes, arginfo_phalcon_forms_element_prepareattributes, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Forms_Element, setAttribute, arginfo_phalcon_forms_element_setattribute, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Forms_Element, getAttribute, arginfo_phalcon_forms_element_getattribute, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Forms_Element, setAttributes, arginfo_phalcon_forms_element_setattributes, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Forms_Element, getAttributes, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Forms_Element, setUserOption, arginfo_phalcon_forms_element_setuseroption, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Forms_Element, getUserOption, arginfo_phalcon_forms_element_getuseroption, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Forms_Element, setUserOptions, arginfo_phalcon_forms_element_setuseroptions, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Forms_Element, getUserOptions, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Forms_Element, setLabel, arginfo_phalcon_forms_element_setlabel, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Forms_Element, getLabel, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Forms_Element, label, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Forms_Element, setDefault, arginfo_phalcon_forms_element_setdefault, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Forms_Element, getDefault, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Forms_Element, getValue, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Forms_Element, getMessages, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Forms_Element, hasMessages, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Forms_Element, setMessages, arginfo_phalcon_forms_element_setmessages, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Forms_Element, appendMessage, arginfo_phalcon_forms_element_appendmessage, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Forms_Element, clear, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Forms_Element, __toString, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_validation_validator_ce;

PHALCON_INIT_CLASS(Phalcon_Validation_Validator);

static PHP_METHOD(Phalcon_Validation_Validator, __construct);
static PHP_METHOD(Phalcon_Validation_Validator, isSetOption);
static PHP_METHOD(Phalcon_Validation_Validator, getOption);
static PHP_METHOD(Phalcon_Validation_Validator, setOption);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator_issetoption, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator_getoption, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator_setoption, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_validation_validator_method_entry){
	PHP_ME(Phalcon_Validation_Validator, __construct, arginfo_phalcon_validation_validator___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Validation_Validator, isSetOption, arginfo_phalcon_validation_validator_issetoption, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Validation_Validator, getOption, arginfo_phalcon_validation_validator_getoption, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Validation_Validator, setOption, arginfo_phalcon_validation_validator_setoption, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_validator_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Validator);

static PHP_METHOD(Phalcon_Mvc_Model_Validator, __construct);
static PHP_METHOD(Phalcon_Mvc_Model_Validator, appendMessage);
static PHP_METHOD(Phalcon_Mvc_Model_Validator, getMessages);
static PHP_METHOD(Phalcon_Mvc_Model_Validator, getOptions);
static PHP_METHOD(Phalcon_Mvc_Model_Validator, getOption);
static PHP_METHOD(Phalcon_Mvc_Model_Validator, isSetOption);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_validator___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_validator_method_entry){
	PHP_ME(Phalcon_Mvc_Model_Validator, __construct, arginfo_phalcon_mvc_model_validator___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Mvc_Model_Validator, appendMessage, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Validator, getMessages, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Validator, getOptions, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Validator, getOption, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Validator, isSetOption, NULL, ZEND_ACC_PROTECTED) 
	PHP_FE_END
};



zend_class_entry *phalcon_cache_backend_ce;

PHALCON_INIT_CLASS(Phalcon_Cache_Backend);

static PHP_METHOD(Phalcon_Cache_Backend, __construct);
static PHP_METHOD(Phalcon_Cache_Backend, start);
static PHP_METHOD(Phalcon_Cache_Backend, stop);
static PHP_METHOD(Phalcon_Cache_Backend, getFrontend);
static PHP_METHOD(Phalcon_Cache_Backend, getOptions);
static PHP_METHOD(Phalcon_Cache_Backend, isFresh);
static PHP_METHOD(Phalcon_Cache_Backend, isStarted);
static PHP_METHOD(Phalcon_Cache_Backend, setLastKey);
static PHP_METHOD(Phalcon_Cache_Backend, getLastKey);
static PHP_METHOD(Phalcon_Cache_Backend, getLifetime);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, frontend)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_start, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_stop, 0, 0, 0)
	ZEND_ARG_INFO(0, stopBuffer)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_setlastkey, 0, 0, 1)
	ZEND_ARG_INFO(0, lastKey)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_cache_backend_method_entry){
	PHP_ME(Phalcon_Cache_Backend, __construct, arginfo_phalcon_cache_backend___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Cache_Backend, start, arginfo_phalcon_cache_backend_start, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend, stop, arginfo_phalcon_cache_backend_stop, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend, getFrontend, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend, getOptions, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend, isFresh, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend, isStarted, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend, setLastKey, arginfo_phalcon_cache_backend_setlastkey, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend, getLastKey, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend, getLifetime, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_metadata_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_MetaData);

static PHP_METHOD(Phalcon_Mvc_Model_MetaData, _initialize);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, setDI);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, getDI);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, setStrategy);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, getStrategy);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, readMetaData);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, readMetaDataIndex);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, writeMetaDataIndex);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, readColumnMap);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, readColumnMapIndex);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, getAttributes);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, getPrimaryKeyAttributes);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, getNonPrimaryKeyAttributes);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, getNotNullAttributes);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, getDataTypes);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, getDataTypesNumeric);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, getIdentityField);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, getBindTypes);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, getAutomaticCreateAttributes);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, getAutomaticUpdateAttributes);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, setAutomaticCreateAttributes);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, setAutomaticUpdateAttributes);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, getColumnMap);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, getReverseColumnMap);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, hasAttribute);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, isEmpty);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, reset);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_setdi, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_setstrategy, 0, 0, 1)
	ZEND_ARG_INFO(0, strategy)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_readmetadata, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_readmetadataindex, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_writemetadataindex, 0, 0, 4)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, replace)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_readcolumnmap, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_readcolumnmapindex, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, index)
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

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_setautomaticcreateattributes, 0, 0, 3)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, attributes)
	ZEND_ARG_INFO(0, replace)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_setautomaticupdateattributes, 0, 0, 3)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, attributes)
	ZEND_ARG_INFO(0, replace)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_getcolumnmap, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_getreversecolumnmap, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_hasattribute, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, attribute)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_metadata_method_entry){
	PHP_ME(Phalcon_Mvc_Model_MetaData, _initialize, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_MetaData, setDI, arginfo_phalcon_mvc_model_metadata_setdi, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_MetaData, getDI, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_MetaData, setStrategy, arginfo_phalcon_mvc_model_metadata_setstrategy, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_MetaData, getStrategy, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_MetaData, readMetaData, arginfo_phalcon_mvc_model_metadata_readmetadata, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_MetaData, readMetaDataIndex, arginfo_phalcon_mvc_model_metadata_readmetadataindex, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_MetaData, writeMetaDataIndex, arginfo_phalcon_mvc_model_metadata_writemetadataindex, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_MetaData, readColumnMap, arginfo_phalcon_mvc_model_metadata_readcolumnmap, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_MetaData, readColumnMapIndex, arginfo_phalcon_mvc_model_metadata_readcolumnmapindex, ZEND_ACC_PUBLIC) 
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
	PHP_ME(Phalcon_Mvc_Model_MetaData, getColumnMap, arginfo_phalcon_mvc_model_metadata_getcolumnmap, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_MetaData, getReverseColumnMap, arginfo_phalcon_mvc_model_metadata_getreversecolumnmap, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_MetaData, hasAttribute, arginfo_phalcon_mvc_model_metadata_hasattribute, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_MetaData, isEmpty, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_MetaData, reset, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_db_adapter_pdo_ce;

PHALCON_INIT_CLASS(Phalcon_Db_Adapter_Pdo);

static PHP_METHOD(Phalcon_Db_Adapter_Pdo, __construct);
static PHP_METHOD(Phalcon_Db_Adapter_Pdo, connect);
static PHP_METHOD(Phalcon_Db_Adapter_Pdo, prepare);
static PHP_METHOD(Phalcon_Db_Adapter_Pdo, executePrepared);
static PHP_METHOD(Phalcon_Db_Adapter_Pdo, query);
static PHP_METHOD(Phalcon_Db_Adapter_Pdo, execute);
static PHP_METHOD(Phalcon_Db_Adapter_Pdo, affectedRows);
static PHP_METHOD(Phalcon_Db_Adapter_Pdo, close);
static PHP_METHOD(Phalcon_Db_Adapter_Pdo, escapeIdentifier);
static PHP_METHOD(Phalcon_Db_Adapter_Pdo, escapeString);
static PHP_METHOD(Phalcon_Db_Adapter_Pdo, convertBoundParams);
static PHP_METHOD(Phalcon_Db_Adapter_Pdo, lastInsertId);
static PHP_METHOD(Phalcon_Db_Adapter_Pdo, begin);
static PHP_METHOD(Phalcon_Db_Adapter_Pdo, rollback);
static PHP_METHOD(Phalcon_Db_Adapter_Pdo, commit);
static PHP_METHOD(Phalcon_Db_Adapter_Pdo, getTransactionLevel);
static PHP_METHOD(Phalcon_Db_Adapter_Pdo, isUnderTransaction);
static PHP_METHOD(Phalcon_Db_Adapter_Pdo, getInternalHandler);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, descriptor)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_connect, 0, 0, 0)
	ZEND_ARG_INFO(0, descriptor)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_prepare, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlStatement)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_executeprepared, 0, 0, 3)
	ZEND_ARG_INFO(0, statement)
	ZEND_ARG_INFO(0, placeholders)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_query, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlStatement)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_execute, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlStatement)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_escapeidentifier, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_escapestring, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_convertboundparams, 0, 0, 2)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_lastinsertid, 0, 0, 0)
	ZEND_ARG_INFO(0, sequenceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_begin, 0, 0, 0)
	ZEND_ARG_INFO(0, nesting)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_rollback, 0, 0, 0)
	ZEND_ARG_INFO(0, nesting)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_commit, 0, 0, 0)
	ZEND_ARG_INFO(0, nesting)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_db_adapter_pdo_method_entry){
	PHP_ME(Phalcon_Db_Adapter_Pdo, __construct, arginfo_phalcon_db_adapter_pdo___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Db_Adapter_Pdo, connect, arginfo_phalcon_db_adapter_pdo_connect, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter_Pdo, prepare, arginfo_phalcon_db_adapter_pdo_prepare, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter_Pdo, executePrepared, arginfo_phalcon_db_adapter_pdo_executeprepared, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter_Pdo, query, arginfo_phalcon_db_adapter_pdo_query, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter_Pdo, execute, arginfo_phalcon_db_adapter_pdo_execute, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter_Pdo, affectedRows, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter_Pdo, close, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter_Pdo, escapeIdentifier, arginfo_phalcon_db_adapter_pdo_escapeidentifier, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter_Pdo, escapeString, arginfo_phalcon_db_adapter_pdo_escapestring, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter_Pdo, convertBoundParams, arginfo_phalcon_db_adapter_pdo_convertboundparams, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter_Pdo, lastInsertId, arginfo_phalcon_db_adapter_pdo_lastinsertid, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter_Pdo, begin, arginfo_phalcon_db_adapter_pdo_begin, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter_Pdo, rollback, arginfo_phalcon_db_adapter_pdo_rollback, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter_Pdo, commit, arginfo_phalcon_db_adapter_pdo_commit, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter_Pdo, getTransactionLevel, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter_Pdo, isUnderTransaction, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter_Pdo, getInternalHandler, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_db_dialect_ce;

PHALCON_INIT_CLASS(Phalcon_Db_Dialect);

static PHP_METHOD(Phalcon_Db_Dialect, limit);
static PHP_METHOD(Phalcon_Db_Dialect, forUpdate);
static PHP_METHOD(Phalcon_Db_Dialect, sharedLock);
static PHP_METHOD(Phalcon_Db_Dialect, getColumnList);
static PHP_METHOD(Phalcon_Db_Dialect, getSqlExpression);
static PHP_METHOD(Phalcon_Db_Dialect, getSqlTable);
static PHP_METHOD(Phalcon_Db_Dialect, select);
static PHP_METHOD(Phalcon_Db_Dialect, supportsSavepoints);
static PHP_METHOD(Phalcon_Db_Dialect, supportsReleaseSavepoints);
static PHP_METHOD(Phalcon_Db_Dialect, createSavepoint);
static PHP_METHOD(Phalcon_Db_Dialect, releaseSavepoint);
static PHP_METHOD(Phalcon_Db_Dialect, rollbackSavepoint);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_limit, 0, 0, 2)
	ZEND_ARG_INFO(0, sqlQuery)
	ZEND_ARG_INFO(0, number)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_forupdate, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sharedlock, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_getcolumnlist, 0, 0, 1)
	ZEND_ARG_INFO(0, columnList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_getsqlexpression, 0, 0, 1)
	ZEND_ARG_INFO(0, expression)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_getsqltable, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_select, 0, 0, 1)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_createsavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_releasesavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_rollbacksavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_db_dialect_method_entry){
	PHP_ME(Phalcon_Db_Dialect, limit, arginfo_phalcon_db_dialect_limit, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect, forUpdate, arginfo_phalcon_db_dialect_forupdate, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect, sharedLock, arginfo_phalcon_db_dialect_sharedlock, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect, getColumnList, arginfo_phalcon_db_dialect_getcolumnlist, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect, getSqlExpression, arginfo_phalcon_db_dialect_getsqlexpression, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect, getSqlTable, arginfo_phalcon_db_dialect_getsqltable, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect, select, arginfo_phalcon_db_dialect_select, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect, supportsSavepoints, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect, supportsReleaseSavepoints, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect, createSavepoint, arginfo_phalcon_db_dialect_createsavepoint, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect, releaseSavepoint, arginfo_phalcon_db_dialect_releasesavepoint, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect, rollbackSavepoint, arginfo_phalcon_db_dialect_rollbacksavepoint, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_annotations_adapter_ce;

PHALCON_INIT_CLASS(Phalcon_Annotations_Adapter);

static PHP_METHOD(Phalcon_Annotations_Adapter, setReader);
static PHP_METHOD(Phalcon_Annotations_Adapter, getReader);
static PHP_METHOD(Phalcon_Annotations_Adapter, get);
static PHP_METHOD(Phalcon_Annotations_Adapter, getMethods);
static PHP_METHOD(Phalcon_Annotations_Adapter, getMethod);
static PHP_METHOD(Phalcon_Annotations_Adapter, getProperties);
static PHP_METHOD(Phalcon_Annotations_Adapter, getProperty);

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



zend_class_entry *phalcon_logger_adapter_ce;

PHALCON_INIT_CLASS(Phalcon_Logger_Adapter);

static PHP_METHOD(Phalcon_Logger_Adapter, setLogLevel);
static PHP_METHOD(Phalcon_Logger_Adapter, getLogLevel);
static PHP_METHOD(Phalcon_Logger_Adapter, setFormatter);
static PHP_METHOD(Phalcon_Logger_Adapter, begin);
static PHP_METHOD(Phalcon_Logger_Adapter, commit);
static PHP_METHOD(Phalcon_Logger_Adapter, rollback);
static PHP_METHOD(Phalcon_Logger_Adapter, emergence);
static PHP_METHOD(Phalcon_Logger_Adapter, debug);
static PHP_METHOD(Phalcon_Logger_Adapter, error);
static PHP_METHOD(Phalcon_Logger_Adapter, info);
static PHP_METHOD(Phalcon_Logger_Adapter, notice);
static PHP_METHOD(Phalcon_Logger_Adapter, warning);
static PHP_METHOD(Phalcon_Logger_Adapter, alert);
static PHP_METHOD(Phalcon_Logger_Adapter, log);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_setloglevel, 0, 0, 1)
	ZEND_ARG_INFO(0, level)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_setformatter, 0, 0, 1)
	ZEND_ARG_INFO(0, formatter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_emergence, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_debug, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_error, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_info, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_notice, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_warning, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_alert, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_log, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_logger_adapter_method_entry){
	PHP_ME(Phalcon_Logger_Adapter, setLogLevel, arginfo_phalcon_logger_adapter_setloglevel, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Logger_Adapter, getLogLevel, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Logger_Adapter, setFormatter, arginfo_phalcon_logger_adapter_setformatter, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Logger_Adapter, begin, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Logger_Adapter, commit, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Logger_Adapter, rollback, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Logger_Adapter, emergence, arginfo_phalcon_logger_adapter_emergence, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Logger_Adapter, debug, arginfo_phalcon_logger_adapter_debug, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Logger_Adapter, error, arginfo_phalcon_logger_adapter_error, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Logger_Adapter, info, arginfo_phalcon_logger_adapter_info, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Logger_Adapter, notice, arginfo_phalcon_logger_adapter_notice, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Logger_Adapter, warning, arginfo_phalcon_logger_adapter_warning, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Logger_Adapter, alert, arginfo_phalcon_logger_adapter_alert, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Logger_Adapter, log, arginfo_phalcon_logger_adapter_log, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_logger_formatter_ce;

PHALCON_INIT_CLASS(Phalcon_Logger_Formatter);

static PHP_METHOD(Phalcon_Logger_Formatter, getTypeString);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_formatter_gettypestring, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_logger_formatter_method_entry){
	PHP_ME(Phalcon_Logger_Formatter, getTypeString, arginfo_phalcon_logger_formatter_gettypestring, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_resultset_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Resultset);

static PHP_METHOD(Phalcon_Mvc_Model_Resultset, next);
static PHP_METHOD(Phalcon_Mvc_Model_Resultset, key);
static PHP_METHOD(Phalcon_Mvc_Model_Resultset, rewind);
static PHP_METHOD(Phalcon_Mvc_Model_Resultset, seek);
static PHP_METHOD(Phalcon_Mvc_Model_Resultset, count);
static PHP_METHOD(Phalcon_Mvc_Model_Resultset, offsetExists);
static PHP_METHOD(Phalcon_Mvc_Model_Resultset, offsetGet);
static PHP_METHOD(Phalcon_Mvc_Model_Resultset, offsetSet);
static PHP_METHOD(Phalcon_Mvc_Model_Resultset, offsetUnset);
static PHP_METHOD(Phalcon_Mvc_Model_Resultset, getType);
static PHP_METHOD(Phalcon_Mvc_Model_Resultset, getFirst);
static PHP_METHOD(Phalcon_Mvc_Model_Resultset, getLast);
static PHP_METHOD(Phalcon_Mvc_Model_Resultset, setIsFresh);
static PHP_METHOD(Phalcon_Mvc_Model_Resultset, isFresh);
static PHP_METHOD(Phalcon_Mvc_Model_Resultset, setHydrateMode);
static PHP_METHOD(Phalcon_Mvc_Model_Resultset, getHydrateMode);
static PHP_METHOD(Phalcon_Mvc_Model_Resultset, getCache);
static PHP_METHOD(Phalcon_Mvc_Model_Resultset, current);
static PHP_METHOD(Phalcon_Mvc_Model_Resultset, getMessages);
static PHP_METHOD(Phalcon_Mvc_Model_Resultset, delete);
static PHP_METHOD(Phalcon_Mvc_Model_Resultset, filter);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultset_seek, 0, 0, 1)
	ZEND_ARG_INFO(0, position)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultset_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultset_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultset_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultset_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultset_setisfresh, 0, 0, 1)
	ZEND_ARG_INFO(0, isFresh)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultset_sethydratemode, 0, 0, 1)
	ZEND_ARG_INFO(0, hydrateMode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultset_delete, 0, 0, 0)
	ZEND_ARG_INFO(0, conditionCallback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultset_filter, 0, 0, 1)
	ZEND_ARG_INFO(0, filter)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_resultset_method_entry){
	PHP_ME(Phalcon_Mvc_Model_Resultset, next, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Resultset, key, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Resultset, rewind, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Resultset, seek, arginfo_phalcon_mvc_model_resultset_seek, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Resultset, count, NULL, ZEND_ACC_PUBLIC) 
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
	PHP_ME(Phalcon_Mvc_Model_Resultset, current, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Resultset, getMessages, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Resultset, delete, arginfo_phalcon_mvc_model_resultset_delete, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Resultset, filter, arginfo_phalcon_mvc_model_resultset_filter, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};
>>>>>>> master

#include "php_phalcon.h"

zend_class_entry *phalcon_annotations_adapter_files_ce;

PHALCON_INIT_CLASS(Phalcon_Annotations_Adapter_Files);

#endif /* PHALCON_ANNOTATIONS_ADAPTER_FILES_H */


#ifndef PHALCON_ANNOTATIONS_ADAPTER_MEMORY_H
#define PHALCON_ANNOTATIONS_ADAPTER_MEMORY_H

#include "php_phalcon.h"

zend_class_entry *phalcon_annotations_adapter_memory_ce;

PHALCON_INIT_CLASS(Phalcon_Annotations_Adapter_Memory);

#endif /* PHALCON_ANNOTATIONS_ADAPTER_MEMORY_H */


#ifndef PHALCON_ANNOTATIONS_ADAPTER_XCACHE_H
#define PHALCON_ANNOTATIONS_ADAPTER_XCACHE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_annotations_adapter_xcache_ce;

PHALCON_INIT_CLASS(Phalcon_Annotations_Adapter_Xcache);

#endif /* PHALCON_ANNOTATIONS_ADAPTER_XCACHE_H */


#ifndef PHALCON_ANNOTATIONS_ANNOTATION_H
#define PHALCON_ANNOTATIONS_ANNOTATION_H

#include "php_phalcon.h"

zend_class_entry *phalcon_annotations_annotation_ce;

PHALCON_INIT_CLASS(Phalcon_Annotations_Annotation);

#endif /* PHALCON_ANNOTATIONS_ANNOTATION_H */


#ifndef PHALCON_ANNOTATIONS_COLLECTION_H
#define PHALCON_ANNOTATIONS_COLLECTION_H

#include "php_phalcon.h"

zend_class_entry *phalcon_annotations_collection_ce;

PHALCON_INIT_CLASS(Phalcon_Annotations_Collection);

#endif /* PHALCON_ANNOTATIONS_COLLECTION_H */


#ifndef PHALCON_ANNOTATIONS_EXCEPTION_H
#define PHALCON_ANNOTATIONS_EXCEPTION_H

#include "php_phalcon.h"

zend_class_entry *phalcon_annotations_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Annotations_Exception);

#endif /* PHALCON_ANNOTATIONS_EXCEPTION_H */


#ifndef PHALCON_ANNOTATIONS_READER_H
#define PHALCON_ANNOTATIONS_READER_H

#include "php_phalcon.h"

zend_class_entry *phalcon_annotations_reader_ce;

PHALCON_INIT_CLASS(Phalcon_Annotations_Reader);

#endif /* PHALCON_ANNOTATIONS_READER_H */


#ifndef PHALCON_ANNOTATIONS_READERINTERFACE_H
#define PHALCON_ANNOTATIONS_READERINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_annotations_readerinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Annotations_ReaderInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_readerinterface_parse, 0, 0, 1)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_readerinterface_parsedocblock, 0, 0, 1)
	ZEND_ARG_INFO(0, docBlock)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_INFO(0, line)
ZEND_END_ARG_INFO()

#endif /* PHALCON_ANNOTATIONS_READERINTERFACE_H */


#ifndef PHALCON_ANNOTATIONS_REFLECTION_H
#define PHALCON_ANNOTATIONS_REFLECTION_H

#include "php_phalcon.h"

zend_class_entry *phalcon_annotations_reflection_ce;

PHALCON_INIT_CLASS(Phalcon_Annotations_Reflection);

#endif /* PHALCON_ANNOTATIONS_REFLECTION_H */



#ifndef PHALCON_ASSETS_COLLECTION_H
#define PHALCON_ASSETS_COLLECTION_H

#include "php_phalcon.h"

zend_class_entry *phalcon_assets_collection_ce;

PHALCON_INIT_CLASS(Phalcon_Assets_Collection);

#endif /* PHALCON_ASSETS_COLLECTION_H */


#ifndef PHALCON_ASSETS_EXCEPTION_H
#define PHALCON_ASSETS_EXCEPTION_H

#include "php_phalcon.h"

zend_class_entry *phalcon_assets_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Assets_Exception);

#endif /* PHALCON_ASSETS_EXCEPTION_H */


#ifndef PHALCON_ASSETS_FILTERINTERFACE_H
#define PHALCON_ASSETS_FILTERINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_assets_filterinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Assets_FilterInterface);

#endif /* PHALCON_ASSETS_FILTERINTERFACE_H */


#ifndef PHALCON_ASSETS_FILTERS_NONE_H
#define PHALCON_ASSETS_FILTERS_NONE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_assets_filters_none_ce;

PHALCON_INIT_CLASS(Phalcon_Assets_Filters_None);

#endif /* PHALCON_ASSETS_FILTERS_NONE_H */


#ifndef PHALCON_ASSETS_FILTERS_CSSMIN_H
#define PHALCON_ASSETS_FILTERS_CSSMIN_H

#include "php_phalcon.h"

zend_class_entry *phalcon_assets_filters_cssmin_ce;

PHALCON_INIT_CLASS(Phalcon_Assets_Filters_Cssmin);

#endif /* PHALCON_ASSETS_FILTERS_CSSMIN_H */


#ifndef PHALCON_ASSETS_FILTERS_JSMIN_H
#define PHALCON_ASSETS_FILTERS_JSMIN_H

#include "php_phalcon.h"

zend_class_entry *phalcon_assets_filters_jsmin_ce;

PHALCON_INIT_CLASS(Phalcon_Assets_Filters_Jsmin);

#endif /* PHALCON_ASSETS_FILTERS_JSMIN_H */

#ifndef PHALCON_ASSETS_MANAGER_H
#define PHALCON_ASSETS_MANAGER_H

#include "php_phalcon.h"

zend_class_entry *phalcon_assets_manager_ce;

PHALCON_INIT_CLASS(Phalcon_Assets_Manager);

#endif /* PHALCON_ASSETS_MANAGER_H */


<<<<<<< HEAD
#ifndef PHALCON_ASSETS_RESOURCE_H
#define PHALCON_ASSETS_RESOURCE_H
=======
static PHP_METHOD(Phalcon_Config, __construct);
static PHP_METHOD(Phalcon_Config, offsetExists);
static PHP_METHOD(Phalcon_Config, get);
static PHP_METHOD(Phalcon_Config, offsetGet);
static PHP_METHOD(Phalcon_Config, offsetSet);
static PHP_METHOD(Phalcon_Config, offsetUnset);
static PHP_METHOD(Phalcon_Config, merge);
static PHP_METHOD(Phalcon_Config, toArray);
static PHP_METHOD(Phalcon_Config, count);
static PHP_METHOD(Phalcon_Config, __wakeup);
static PHP_METHOD(Phalcon_Config, __set_state);
>>>>>>> master

#include "php_phalcon.h"

zend_class_entry *phalcon_assets_resource_ce;

PHALCON_INIT_CLASS(Phalcon_Assets_Resource);

#endif /* PHALCON_ASSETS_RESOURCE_H */


#ifndef PHALCON_ASSETS_RESOURCE_JS_H
#define PHALCON_ASSETS_RESOURCE_JS_H

#include "php_phalcon.h"

zend_class_entry *phalcon_assets_resource_js_ce;

PHALCON_INIT_CLASS(Phalcon_Assets_Resource_Js);

<<<<<<< HEAD
#endif /* PHALCON_ASSETS_RESOURCE_JS_H */

=======
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config___wakeup, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config___set_state, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_config_method_entry){
	PHP_ME(Phalcon_Config, __construct, arginfo_phalcon_config___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Config, offsetExists, arginfo_phalcon_config_offsetexists, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Config, get, arginfo_phalcon_config_get, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Config, offsetGet, arginfo_phalcon_config_offsetget, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Config, offsetSet, arginfo_phalcon_config_offsetset, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Config, offsetUnset, arginfo_phalcon_config_offsetunset, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Config, merge, arginfo_phalcon_config_merge, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Config, toArray, arginfo_phalcon_config_toarray, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Config, count, arginfo_phalcon_config_count, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Config, __wakeup, arginfo_phalcon_config___wakeup, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Config, __set_state, arginfo_phalcon_config___set_state, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_MALIAS(Phalcon_Config, __get, offsetGet, arginfo_phalcon_config_offsetget, ZEND_ACC_PUBLIC)
	PHP_MALIAS(Phalcon_Config, __set, offsetSet, arginfo_phalcon_config_offsetset, ZEND_ACC_PUBLIC)
	PHP_MALIAS(Phalcon_Config, __isset, offsetExists, arginfo_phalcon_config_offsetexists, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
>>>>>>> master

#ifndef PHALCON_ASSETS_RESOURCE_CSS_H
#define PHALCON_ASSETS_RESOURCE_CSS_H

#include "php_phalcon.h"

zend_class_entry *phalcon_assets_resource_css_ce;

PHALCON_INIT_CLASS(Phalcon_Assets_Resource_Css);

#endif /* PHALCON_ASSETS_RESOURCE_CSS_H */



<<<<<<< HEAD
#ifndef PHALCON_CACHE_BACKEND_H
#define PHALCON_CACHE_BACKEND_H
=======
static PHP_METHOD(Phalcon_Mvc_Router, __construct);
static PHP_METHOD(Phalcon_Mvc_Router, setDI);
static PHP_METHOD(Phalcon_Mvc_Router, getDI);
static PHP_METHOD(Phalcon_Mvc_Router, getRewriteUri);
static PHP_METHOD(Phalcon_Mvc_Router, setUriSource);
static PHP_METHOD(Phalcon_Mvc_Router, removeExtraSlashes);
static PHP_METHOD(Phalcon_Mvc_Router, setDefaultNamespace);
static PHP_METHOD(Phalcon_Mvc_Router, setDefaultModule);
static PHP_METHOD(Phalcon_Mvc_Router, setDefaultController);
static PHP_METHOD(Phalcon_Mvc_Router, setDefaultAction);
static PHP_METHOD(Phalcon_Mvc_Router, setDefaults);
static PHP_METHOD(Phalcon_Mvc_Router, handle);
static PHP_METHOD(Phalcon_Mvc_Router, add);
static PHP_METHOD(Phalcon_Mvc_Router, addGet);
static PHP_METHOD(Phalcon_Mvc_Router, addPost);
static PHP_METHOD(Phalcon_Mvc_Router, addPut);
static PHP_METHOD(Phalcon_Mvc_Router, addPatch);
static PHP_METHOD(Phalcon_Mvc_Router, addDelete);
static PHP_METHOD(Phalcon_Mvc_Router, addOptions);
static PHP_METHOD(Phalcon_Mvc_Router, addHead);
static PHP_METHOD(Phalcon_Mvc_Router, mount);
static PHP_METHOD(Phalcon_Mvc_Router, notFound);
static PHP_METHOD(Phalcon_Mvc_Router, clear);
static PHP_METHOD(Phalcon_Mvc_Router, getNamespaceName);
static PHP_METHOD(Phalcon_Mvc_Router, getModuleName);
static PHP_METHOD(Phalcon_Mvc_Router, getControllerName);
static PHP_METHOD(Phalcon_Mvc_Router, getActionName);
static PHP_METHOD(Phalcon_Mvc_Router, getParams);
static PHP_METHOD(Phalcon_Mvc_Router, getMatchedRoute);
static PHP_METHOD(Phalcon_Mvc_Router, getMatches);
static PHP_METHOD(Phalcon_Mvc_Router, wasMatched);
static PHP_METHOD(Phalcon_Mvc_Router, getRoutes);
static PHP_METHOD(Phalcon_Mvc_Router, getRouteById);
static PHP_METHOD(Phalcon_Mvc_Router, getRouteByName);
static PHP_METHOD(Phalcon_Mvc_Router, isExactControllerName);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, defaultRoutes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_setdi, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()
>>>>>>> master

#include "php_phalcon.h"

zend_class_entry *phalcon_cache_backend_ce;

PHALCON_INIT_CLASS(Phalcon_Cache_Backend);

#endif /* PHALCON_CACHE_BACKEND_H */


#ifndef PHALCON_CACHE_BACKENDINTERFACE_H
#define PHALCON_CACHE_BACKENDINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_cache_backendinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Cache_BackendInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backendinterface_start, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backendinterface_stop, 0, 0, 0)
	ZEND_ARG_INFO(0, stopBuffer)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backendinterface_setlastkey, 0, 0, 1)
	ZEND_ARG_INFO(0, lastKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backendinterface_get, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backendinterface_save, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, lifetime)
	ZEND_ARG_INFO(0, stopBuffer)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backendinterface_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backendinterface_querykeys, 0, 0, 0)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backendinterface_exists, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backendinterface_increment, 0, 0, 0)
	ZEND_ARG_INFO(0, key_name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backendinterface_decrement, 0, 0, 0)
	ZEND_ARG_INFO(0, key_name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

#endif /* PHALCON_CACHE_BACKENDINTERFACE_H */

<<<<<<< HEAD
=======
PHALCON_INIT_FUNCS(phalcon_mvc_router_method_entry){
	PHP_ME(Phalcon_Mvc_Router, __construct, arginfo_phalcon_mvc_router___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Mvc_Router, setDI, arginfo_phalcon_mvc_router_setdi, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, getDI, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, getRewriteUri, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, setUriSource, arginfo_phalcon_mvc_router_seturisource, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, removeExtraSlashes, arginfo_phalcon_mvc_router_removeextraslashes, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, setDefaultNamespace, arginfo_phalcon_mvc_router_setdefaultnamespace, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, setDefaultModule, arginfo_phalcon_mvc_router_setdefaultmodule, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, setDefaultController, arginfo_phalcon_mvc_router_setdefaultcontroller, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, setDefaultAction, arginfo_phalcon_mvc_router_setdefaultaction, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, setDefaults, arginfo_phalcon_mvc_router_setdefaults, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, handle, arginfo_phalcon_mvc_router_handle, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, add, arginfo_phalcon_mvc_router_add, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, addGet, arginfo_phalcon_mvc_router_addget, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, addPost, arginfo_phalcon_mvc_router_addpost, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, addPut, arginfo_phalcon_mvc_router_addput, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, addPatch, arginfo_phalcon_mvc_router_addpatch, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, addDelete, arginfo_phalcon_mvc_router_adddelete, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, addOptions, arginfo_phalcon_mvc_router_addoptions, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, addHead, arginfo_phalcon_mvc_router_addhead, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, mount, arginfo_phalcon_mvc_router_mount, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, notFound, arginfo_phalcon_mvc_router_notfound, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, clear, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, getNamespaceName, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, getModuleName, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, getControllerName, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, getActionName, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, getParams, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, getMatchedRoute, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, getMatches, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, wasMatched, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, getRoutes, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, getRouteById, arginfo_phalcon_mvc_router_getroutebyid, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, getRouteByName, arginfo_phalcon_mvc_router_getroutebyname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, isExactControllerName, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
>>>>>>> master

#ifndef PHALCON_CACHE_BACKEND_APC_H
#define PHALCON_CACHE_BACKEND_APC_H

<<<<<<< HEAD
#include "php_phalcon.h"

zend_class_entry *phalcon_cache_backend_apc_ce;
=======
zend_class_entry *phalcon_acl_adapter_ce;
>>>>>>> master

PHALCON_INIT_CLASS(Phalcon_Cache_Backend_Apc);

#endif /* PHALCON_CACHE_BACKEND_APC_H */


#ifndef PHALCON_CACHE_BACKEND_FILE_H
#define PHALCON_CACHE_BACKEND_FILE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_cache_backend_file_ce;

PHALCON_INIT_CLASS(Phalcon_Cache_Backend_File);

#endif /* PHALCON_CACHE_BACKEND_FILE_H */


<<<<<<< HEAD
#ifndef PHALCON_CACHE_BACKEND_LIBMEMCACHED_H
#define PHALCON_CACHE_BACKEND_LIBMEMCACHED_H
=======
static PHP_METHOD(Phalcon_Session_Adapter, __construct);
static PHP_METHOD(Phalcon_Session_Adapter, __destruct);
static PHP_METHOD(Phalcon_Session_Adapter, start);
static PHP_METHOD(Phalcon_Session_Adapter, setOptions);
static PHP_METHOD(Phalcon_Session_Adapter, getOptions);
static PHP_METHOD(Phalcon_Session_Adapter, get);
static PHP_METHOD(Phalcon_Session_Adapter, set);
static PHP_METHOD(Phalcon_Session_Adapter, has);
static PHP_METHOD(Phalcon_Session_Adapter, remove);
static PHP_METHOD(Phalcon_Session_Adapter, getId);
static PHP_METHOD(Phalcon_Session_Adapter, isStarted);
static PHP_METHOD(Phalcon_Session_Adapter, destroy);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()
>>>>>>> master

#include "php_phalcon.h"

zend_class_entry *phalcon_cache_backend_libmemcached_ce;

PHALCON_INIT_CLASS(Phalcon_Cache_Backend_Libmemcached);

#endif /* PHALCON_CACHE_BACKEND_LIBMEMCACHED_H */


<<<<<<< HEAD
#ifndef PHALCON_CACHE_BACKEND_MEMCACHE_H
#define PHALCON_CACHE_BACKEND_MEMCACHE_H
=======
PHALCON_INIT_FUNCS(phalcon_session_adapter_method_entry){
	PHP_ME(Phalcon_Session_Adapter, __construct, arginfo_phalcon_session_adapter___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Session_Adapter, __destruct, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_DTOR)
	PHP_ME(Phalcon_Session_Adapter, start, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Session_Adapter, setOptions, arginfo_phalcon_session_adapter_setoptions, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Session_Adapter, getOptions, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Session_Adapter, get, arginfo_phalcon_session_adapter_get, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Session_Adapter, set, arginfo_phalcon_session_adapter_set, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Session_Adapter, has, arginfo_phalcon_session_adapter_has, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Session_Adapter, remove, arginfo_phalcon_session_adapter_remove, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Session_Adapter, getId, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Session_Adapter, isStarted, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Session_Adapter, destroy, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};
>>>>>>> master

#include "php_phalcon.h"

zend_class_entry *phalcon_cache_backend_memcache_ce;

PHALCON_INIT_CLASS(Phalcon_Cache_Backend_Memcache);

#endif /* PHALCON_CACHE_BACKEND_MEMCACHE_H */


#ifndef PHALCON_CACHE_BACKEND_MEMORY_H
#define PHALCON_CACHE_BACKEND_MEMORY_H

#include "php_phalcon.h"

zend_class_entry *phalcon_cache_backend_memory_ce;

PHALCON_INIT_CLASS(Phalcon_Cache_Backend_Memory);

#endif /* PHALCON_CACHE_BACKEND_MEMORY_H */


#ifndef PHALCON_CACHE_BACKEND_MONGO_H
#define PHALCON_CACHE_BACKEND_MONGO_H

#include "php_phalcon.h"

zend_class_entry *phalcon_cache_backend_mongo_ce;

PHALCON_INIT_CLASS(Phalcon_Cache_Backend_Mongo);

<<<<<<< HEAD
#endif /* PHALCON_CACHE_BACKEND_MONGO_H */
=======
static PHP_METHOD(Phalcon_Tag, setDI);
static PHP_METHOD(Phalcon_Tag, getDI);
static PHP_METHOD(Phalcon_Tag, getUrlService);
static PHP_METHOD(Phalcon_Tag, getEscaperService);
static PHP_METHOD(Phalcon_Tag, getAutoescape);
static PHP_METHOD(Phalcon_Tag, setAutoescape);
static PHP_METHOD(Phalcon_Tag, setDefault);
static PHP_METHOD(Phalcon_Tag, setDefaults);
static PHP_METHOD(Phalcon_Tag, hasValue);
static PHP_METHOD(Phalcon_Tag, getValue);
static PHP_METHOD(Phalcon_Tag, resetInput);
static PHP_METHOD(Phalcon_Tag, linkTo);
static PHP_METHOD(Phalcon_Tag, _inputField);
static PHP_METHOD(Phalcon_Tag, _inputFieldChecked);
static PHP_METHOD(Phalcon_Tag, textField);
static PHP_METHOD(Phalcon_Tag, numericField);
static PHP_METHOD(Phalcon_Tag, emailField);
static PHP_METHOD(Phalcon_Tag, dateField);
static PHP_METHOD(Phalcon_Tag, passwordField);
static PHP_METHOD(Phalcon_Tag, hiddenField);
static PHP_METHOD(Phalcon_Tag, fileField);
static PHP_METHOD(Phalcon_Tag, checkField);
static PHP_METHOD(Phalcon_Tag, radioField);
static PHP_METHOD(Phalcon_Tag, imageInput);
static PHP_METHOD(Phalcon_Tag, submitButton);
static PHP_METHOD(Phalcon_Tag, selectStatic);
static PHP_METHOD(Phalcon_Tag, select);
static PHP_METHOD(Phalcon_Tag, textArea);
static PHP_METHOD(Phalcon_Tag, form);
static PHP_METHOD(Phalcon_Tag, endForm);
static PHP_METHOD(Phalcon_Tag, setTitle);
static PHP_METHOD(Phalcon_Tag, appendTitle);
static PHP_METHOD(Phalcon_Tag, prependTitle);
static PHP_METHOD(Phalcon_Tag, getTitle);
static PHP_METHOD(Phalcon_Tag, stylesheetLink);
static PHP_METHOD(Phalcon_Tag, javascriptInclude);
static PHP_METHOD(Phalcon_Tag, image);
static PHP_METHOD(Phalcon_Tag, friendlyTitle);
static PHP_METHOD(Phalcon_Tag, setDocType);
static PHP_METHOD(Phalcon_Tag, getDocType);
static PHP_METHOD(Phalcon_Tag, tagHtml);
static PHP_METHOD(Phalcon_Tag, tagHtmlClose);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_setdi, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()
>>>>>>> master


#ifndef PHALCON_CACHE_BACKEND_XCACHE_H
#define PHALCON_CACHE_BACKEND_XCACHE_H

#include "php_phalcon.h"

<<<<<<< HEAD
zend_class_entry *phalcon_cache_backend_xcache_ce;

PHALCON_INIT_CLASS(Phalcon_Cache_Backend_Xcache);
=======
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_hasvalue, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()
>>>>>>> master

#endif /* PHALCON_CACHE_BACKEND_XCACHE_H */


#ifndef PHALCON_CACHE_EXCEPTION_H
#define PHALCON_CACHE_EXCEPTION_H

#include "php_phalcon.h"

zend_class_entry *phalcon_cache_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Cache_Exception);

#endif /* PHALCON_CACHE_EXCEPTION_H */


#ifndef PHALCON_CACHE_FRONTENDINTERFACE_H
#define PHALCON_CACHE_FRONTENDINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_cache_frontendinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Cache_FrontendInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontendinterface_empty, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontendinterface_beforestore, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontendinterface_afterretrieve, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

#endif /* PHALCON_CACHE_FRONTENDINTERFACE_H */


#ifndef PHALCON_CACHE_FRONTEND_BASE64_H
#define PHALCON_CACHE_FRONTEND_BASE64_H

#include "php_phalcon.h"

zend_class_entry *phalcon_cache_frontend_base64_ce;

PHALCON_INIT_CLASS(Phalcon_Cache_Frontend_Base64);

#endif /* PHALCON_CACHE_FRONTEND_BASE64_H */


#ifndef PHALCON_CACHE_FRONTEND_DATA_H
#define PHALCON_CACHE_FRONTEND_DATA_H

#include "php_phalcon.h"

zend_class_entry *phalcon_cache_frontend_data_ce;

PHALCON_INIT_CLASS(Phalcon_Cache_Frontend_Data);

#endif /* PHALCON_CACHE_FRONTEND_DATA_H */


#ifndef PHALCON_CACHE_FRONTEND_IGBINARY_H
#define PHALCON_CACHE_FRONTEND_IGBINARY_H

<<<<<<< HEAD
#include "php_phalcon.h"
=======
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_taghtml, 0, 0, 1)
	ZEND_ARG_INFO(0, tagName)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_INFO(0, selfClose)
	ZEND_ARG_INFO(0, onlyStart)
	ZEND_ARG_INFO(0, useEol)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_taghtmlclose, 0, 0, 1)
	ZEND_ARG_INFO(0, tagName)
	ZEND_ARG_INFO(0, useEol)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_tag_method_entry){
	PHP_ME(Phalcon_Tag, setDI, arginfo_phalcon_tag_setdi, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, getDI, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, getUrlService, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, getEscaperService, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, getAutoescape, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, setAutoescape, arginfo_phalcon_tag_setautoescape, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, setDefault, arginfo_phalcon_tag_setdefault, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, setDefaults, arginfo_phalcon_tag_setdefaults, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_MALIAS(Phalcon_Tag, displayTo, setDefault, arginfo_phalcon_tag_setdefault, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, hasValue, arginfo_phalcon_tag_hasvalue, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, getValue, arginfo_phalcon_tag_getvalue, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, resetInput, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, linkTo, arginfo_phalcon_tag_linkto, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, _inputField, NULL, ZEND_ACC_STATIC|ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Tag, _inputFieldChecked, NULL, ZEND_ACC_STATIC|ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Tag, textField, arginfo_phalcon_tag_textfield, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Tag, numericField, arginfo_phalcon_tag_numericfield, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Tag, emailField, arginfo_phalcon_tag_emailfield, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Tag, dateField, arginfo_phalcon_tag_datefield, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Tag, passwordField, arginfo_phalcon_tag_passwordfield, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Tag, hiddenField, arginfo_phalcon_tag_hiddenfield, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Tag, fileField, arginfo_phalcon_tag_filefield, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Tag, checkField, arginfo_phalcon_tag_checkfield, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Tag, radioField, arginfo_phalcon_tag_radiofield, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Tag, imageInput, arginfo_phalcon_tag_imageinput, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Tag, submitButton, arginfo_phalcon_tag_submitbutton, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Tag, selectStatic, arginfo_phalcon_tag_selectstatic, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, select, arginfo_phalcon_tag_select, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, textArea, arginfo_phalcon_tag_textarea, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Tag, form, arginfo_phalcon_tag_form, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, endForm, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, setTitle, arginfo_phalcon_tag_settitle, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, appendTitle, arginfo_phalcon_tag_appendtitle, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, prependTitle, arginfo_phalcon_tag_prependtitle, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, getTitle, arginfo_phalcon_tag_gettitle, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, stylesheetLink, arginfo_phalcon_tag_stylesheetlink, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, javascriptInclude, arginfo_phalcon_tag_javascriptinclude, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, image, arginfo_phalcon_tag_image, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, friendlyTitle, arginfo_phalcon_tag_friendlytitle, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, setDocType, arginfo_phalcon_tag_setdoctype, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, getDocType, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, tagHtml, arginfo_phalcon_tag_taghtml, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, tagHtmlClose, arginfo_phalcon_tag_taghtmlclose, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_FE_END
};
>>>>>>> master

zend_class_entry *phalcon_cache_frontend_igbinary_ce;

PHALCON_INIT_CLASS(Phalcon_Cache_Frontend_Igbinary);

#endif /* PHALCON_CACHE_FRONTEND_IGBINARY_H */


#ifndef PHALCON_CACHE_FRONTEND_JSON_H
#define PHALCON_CACHE_FRONTEND_JSON_H

#include "php_phalcon.h"

zend_class_entry *phalcon_cache_frontend_json_ce;

PHALCON_INIT_CLASS(Phalcon_Cache_Frontend_Json);

#endif /* PHALCON_CACHE_FRONTEND_JSON_H */


#ifndef PHALCON_CACHE_FRONTEND_NONE_H
#define PHALCON_CACHE_FRONTEND_NONE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_cache_frontend_none_ce;

PHALCON_INIT_CLASS(Phalcon_Cache_Frontend_None);

#endif /* PHALCON_CACHE_FRONTEND_NONE_H */


#ifndef PHALCON_CACHE_FRONTEND_OUTPUT_H
#define PHALCON_CACHE_FRONTEND_OUTPUT_H

#include "php_phalcon.h"

zend_class_entry *phalcon_cache_frontend_output_ce;

PHALCON_INIT_CLASS(Phalcon_Cache_Frontend_Output);

#endif /* PHALCON_CACHE_FRONTEND_OUTPUT_H */


#ifndef PHALCON_CACHE_MULTIPLE_H
#define PHALCON_CACHE_MULTIPLE_H

zend_class_entry *phalcon_cache_multiple_ce;

PHALCON_INIT_CLASS(Phalcon_Cache_Multiple);

#endif /* PHALCON_CACHE_MULTIPLE_H */



#ifndef PHALCON_CLI_CONSOLE_H
#define PHALCON_CLI_CONSOLE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_cli_console_ce;

PHALCON_INIT_CLASS(Phalcon_CLI_Console);

#endif /* PHALCON_CLI_CONSOLE_H */


#ifndef PHALCON_CLI_CONSOLE_EXCEPTION_H
#define PHALCON_CLI_CONSOLE_EXCEPTION_H

#include "php_phalcon.h"

zend_class_entry *phalcon_cli_console_exception_ce;

PHALCON_INIT_CLASS(Phalcon_CLI_Console_Exception);

#endif /* PHALCON_CLI_CONSOLE_EXCEPTION_H */


#ifndef PHALCON_CLI_DISPATCHER_H
#define PHALCON_CLI_DISPATCHER_H

#include "php_phalcon.h"

zend_class_entry *phalcon_cli_dispatcher_ce;

PHALCON_INIT_CLASS(Phalcon_CLI_Dispatcher);

#endif /* PHALCON_CLI_DISPATCHER_H */


#ifndef PHALCON_CLI_DISPATCHER_EXCEPTION_H
#define PHALCON_CLI_DISPATCHER_EXCEPTION_H

#include "php_phalcon.h"

zend_class_entry *phalcon_cli_dispatcher_exception_ce;

PHALCON_INIT_CLASS(Phalcon_CLI_Dispatcher_Exception);

#endif /* PHALCON_CLI_DISPATCHER_EXCEPTION_H */


#ifndef PHALCON_CLI_ROUTER_H
#define PHALCON_CLI_ROUTER_H

#include "php_phalcon.h"

zend_class_entry *phalcon_cli_router_ce;

PHALCON_INIT_CLASS(Phalcon_CLI_Router);

#endif /* PHALCON_CLI_ROUTER_H */


#ifndef PHALCON_CLI_ROUTER_EXCEPTION_H
#define PHALCON_CLI_ROUTER_EXCEPTION_H

#include "php_phalcon.h"

zend_class_entry *phalcon_cli_router_exception_ce;

PHALCON_INIT_CLASS(Phalcon_CLI_Router_Exception);

#endif /* PHALCON_CLI_ROUTER_EXCEPTION_H */


#ifndef PHALCON_CLI_TASK_H
#define PHALCON_CLI_TASK_H

#include "php_phalcon.h"

zend_class_entry *phalcon_cli_task_ce;

PHALCON_INIT_CLASS(Phalcon_CLI_Task);

#endif /* PHALCON_CLI_TASK_H */



#ifndef PHALCON_PCONFIG_H
#define PHALCON_PCONFIG_H

#include "php_phalcon.h"

zend_class_entry *phalcon_config_ce;

PHALCON_INIT_CLASS(Phalcon_Config);

static void phalcon_config_construct_internal(zval *this_ptr, zval *array_config TSRMLS_DC);

#endif /* PHALCON_PCONFIG_H */


#ifndef PHALCON_CONFIG_ADAPTER_INI_H
#define PHALCON_CONFIG_ADAPTER_INI_H

#include "php_phalcon.h"

zend_class_entry *phalcon_config_adapter_ini_ce;

PHALCON_INIT_CLASS(Phalcon_Config_Adapter_Ini);

#endif /* PHALCON_CONFIG_ADAPTER_INI_H */


#ifndef PHALCON_CONFIG_ADAPTER_JSON_H
#define PHALCON_CONFIG_ADAPTER_JSON_H

#include "php_phalcon.h"

zend_class_entry *phalcon_config_adapter_json_ce;

PHALCON_INIT_CLASS(Phalcon_Config_Adapter_Json);

#endif /* PHALCON_CONFIG_ADAPTER_JSON_H */


#ifndef PHALCON_CONFIG_ADAPTER_PHP_H
#define PHALCON_CONFIG_ADAPTER_PHP_H

#include "php_phalcon.h"

zend_class_entry *phalcon_config_adapter_php_ce;

PHALCON_INIT_CLASS(Phalcon_Config_Adapter_Php);

#endif /* PHALCON_CONFIG_ADAPTER_PHP_H */


#ifndef PHALCON_CONFIG_EXCEPTION_H
#define PHALCON_CONFIG_EXCEPTION_H

#include "php_phalcon.h"

zend_class_entry *phalcon_config_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Config_Exception);

#endif /* PHALCON_CONFIG_EXCEPTION_H */



#ifndef PHALCON_CRYPT_H
#define PHALCON_CRYPT_H

#include "php_phalcon.h"

#define PHALCON_CRYPT_PADDING_DEFAULT        0
#define PHALCON_CRYPT_PADDING_ANSI_X_923     1
#define PHALCON_CRYPT_PADDING_PKCS7          2
#define PHALCON_CRYPT_PADDING_ISO_10126      3
#define PHALCON_CRYPT_PADDING_ISO_IEC_7816_4 4
#define PHALCON_CRYPT_PADDING_ZERO           5
#define PHALCON_CRYPT_PADDING_SPACE          6

zend_class_entry *phalcon_crypt_ce;

PHALCON_INIT_CLASS(Phalcon_Crypt);

#endif /* PHALCON_CRYPT_H */


#ifndef PHALCON_CRYPTINTERFACE_H
#define PHALCON_CRYPTINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_cryptinterface_ce;

PHALCON_INIT_CLASS(Phalcon_CryptInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cryptinterface_setcipher, 0, 0, 1)
	ZEND_ARG_INFO(0, cipher)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cryptinterface_setmode, 0, 0, 1)
	ZEND_ARG_INFO(0, mode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cryptinterface_setkey, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cryptinterface_encrypt, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cryptinterface_decrypt, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cryptinterface_encryptbase64, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, safe)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cryptinterface_decryptbase64, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, safe)
ZEND_END_ARG_INFO()

#endif /* PHALCON_CRYPTINTERFACE_H */


#ifndef PHALCON_CRYPT_EXCEPTION_H
#define PHALCON_CRYPT_EXCEPTION_H

#include "php_phalcon.h"

zend_class_entry *phalcon_crypt_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Crypt_Exception);

#endif /* PHALCON_CRYPT_EXCEPTION_H */



#ifndef PHALCON_DB_H
#define PHALCON_DB_H

#include "php_phalcon.h"

zend_class_entry *phalcon_db_ce;

PHALCON_INIT_CLASS(Phalcon_Db);

#endif /* PHALCON_DB_H */


#ifndef PHALCON_DB_ADAPTER_H
#define PHALCON_DB_ADAPTER_H

#include "php_phalcon.h"

zend_class_entry *phalcon_db_adapter_ce;

PHALCON_INIT_CLASS(Phalcon_Db_Adapter);

#endif /* PHALCON_DB_ADAPTER_H */


#ifndef PHALCON_DB_ADAPTERINTERFACE_H
#define PHALCON_DB_ADAPTERINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_db_adapterinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Db_AdapterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_fetchone, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
	ZEND_ARG_INFO(0, fetchMode)
	ZEND_ARG_INFO(0, placeholders)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_fetchall, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
	ZEND_ARG_INFO(0, fetchMode)
	ZEND_ARG_INFO(0, placeholders)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_insert, 0, 0, 2)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_update, 0, 0, 3)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, whereCondition)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, whereCondition)
	ZEND_ARG_INFO(0, placeholders)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_getcolumnlist, 0, 0, 1)
	ZEND_ARG_INFO(0, columnList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_limit, 0, 0, 2)
	ZEND_ARG_INFO(0, sqlQuery)
	ZEND_ARG_INFO(0, number)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_tableexists, 0, 0, 1)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_viewexists, 0, 0, 1)
	ZEND_ARG_INFO(0, viewName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_forupdate, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_sharedlock, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_createtable, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_droptable, 0, 0, 1)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, ifExists)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_createview, 0, 0, 2)
	ZEND_ARG_INFO(0, viewName)
	ZEND_ARG_INFO(0, definition)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_dropview, 0, 0, 1)
	ZEND_ARG_INFO(0, viewName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, ifExists)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_addcolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, column)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_modifycolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, column)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_dropcolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, columnName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_addindex, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_dropindex, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, indexName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_addprimarykey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_dropprimarykey, 0, 0, 2)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_addforeignkey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, reference)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_dropforeignkey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, referenceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_getcolumndefinition, 0, 0, 1)
	ZEND_ARG_INFO(0, column)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_listtables, 0, 0, 0)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_listviews, 0, 0, 0)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_connect, 0, 0, 0)
	ZEND_ARG_INFO(0, descriptor)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_query, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlStatement)
	ZEND_ARG_INFO(0, placeholders)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_execute, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlStatement)
	ZEND_ARG_INFO(0, placeholders)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_escapeidentifier, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_escapestring, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_convertboundparams, 0, 0, 2)
	ZEND_ARG_INFO(0, sqlStatement)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_lastinsertid, 0, 0, 0)
	ZEND_ARG_INFO(0, sequenceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_describeindexes, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_describereferences, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_tableoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_createsavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_releasesavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_rollbacksavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_setnestedtransactionswithsavepoints, 0, 0, 1)
	ZEND_ARG_INFO(0, nestedTransactionsWithSavepoints)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_describecolumns, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

#endif /* PHALCON_DB_ADAPTERINTERFACE_H */


#ifndef PHALCON_DB_ADAPTER_PDO_H
#define PHALCON_DB_ADAPTER_PDO_H

#include "php_phalcon.h"

zend_class_entry *phalcon_db_adapter_pdo_ce;

PHALCON_INIT_CLASS(Phalcon_Db_Adapter_Pdo);

#endif /* PHALCON_DB_ADAPTER_PDO_H */


#ifndef PHALCON_DB_ADAPTER_MYSQL_H
#define PHALCON_DB_ADAPTER_MYSQL_H

#include "php_phalcon.h"

zend_class_entry *phalcon_db_adapter_pdo_mysql_ce;

PHALCON_INIT_CLASS(Phalcon_Db_Adapter_Pdo_Mysql);

#endif /* PHALCON_DB_ADAPTER_MYSQL_H */


#ifndef PHALCON_DB_ADAPTER_PDO_ORACLE_H
#define PHALCON_DB_ADAPTER_PDO_ORACLE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_db_adapter_pdo_oracle_ce;

PHALCON_INIT_CLASS(Phalcon_Db_Adapter_Pdo_Oracle);

#endif /* PHALCON_DB_ADAPTER_PDO_ORACLE_H */


#ifndef PHALCON_DB_ADAPTER_PDO_POSTGRESQL_H
#define PHALCON_DB_ADAPTER_PDO_POSTGRESQL_H

#include "php_phalcon.h"

zend_class_entry *phalcon_db_adapter_pdo_postgresql_ce;

PHALCON_INIT_CLASS(Phalcon_Db_Adapter_Pdo_Postgresql);

#endif /* PHALCON_DB_ADAPTER_PDO_POSTGRESQL_H */


#ifndef PHALCON_DB_ADAPTER_PDO_SQLITE
#define PHALCON_DB_ADAPTER_PDO_SQLITE

#include "php_phalcon.h"

zend_class_entry *phalcon_db_adapter_pdo_sqlite_ce;

PHALCON_INIT_CLASS(Phalcon_Db_Adapter_Pdo_Sqlite);

#endif /* PHALCON_DB_ADAPTER_PDO_SQLITE */


#ifndef PHALCON_DB_COLUMN_H
#define PHALCON_DB_COLUMN_H

#include "php_phalcon.h"

zend_class_entry *phalcon_db_column_ce;

PHALCON_INIT_CLASS(Phalcon_Db_Column);

#endif /* PHALCON_DB_COLUMN_H */


#ifndef PHALCON_DB_COLUMNINTERFACE_H
#define PHALCON_DB_COLUMNINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_db_columninterface_ce;

PHALCON_INIT_CLASS(Phalcon_Db_ColumnInterface);

#endif /* PHALCON_DB_COLUMNINTERFACE_H */


#ifndef PHALCON_DB_DIALECT_H
#define PHALCON_DB_DIALECT_H

#include "php_phalcon.h"

zend_class_entry *phalcon_db_dialect_ce;

PHALCON_INIT_CLASS(Phalcon_Db_Dialect);

#endif /* PHALCON_DB_DIALECT_H */


#ifndef PHALCON_DB_DIALECTINTERFACE_H
#define PHALCON_DB_DIALECTINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_db_dialectinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Db_DialectInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_limit, 0, 0, 2)
	ZEND_ARG_INFO(0, sqlQuery)
	ZEND_ARG_INFO(0, number)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_forupdate, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_sharedlock, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_select, 0, 0, 1)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_getcolumnlist, 0, 0, 1)
	ZEND_ARG_INFO(0, columnList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_getcolumndefinition, 0, 0, 1)
	ZEND_ARG_INFO(0, column)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_addcolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, column)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_modifycolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, column)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_dropcolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, columnName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_addindex, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_dropindex, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, indexName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_addprimarykey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_dropprimarykey, 0, 0, 2)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_addforeignkey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, reference)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_dropforeignkey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, referenceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_createtable, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_droptable, 0, 0, 2)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_createview, 0, 0, 3)
	ZEND_ARG_INFO(0, viewName)
	ZEND_ARG_INFO(0, definition)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_dropview, 0, 0, 2)
	ZEND_ARG_INFO(0, viewName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, ifExists)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_tableexists, 0, 0, 1)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_viewexists, 0, 0, 1)
	ZEND_ARG_INFO(0, viewName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_describecolumns, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_listtables, 0, 0, 0)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_describeindexes, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_describereferences, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_tableoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_createsavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_releasesavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_rollbacksavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

#endif /* PHALCON_DB_DIALECTINTERFACE_H */


#ifndef PHALCON_DB_DIALECT_MYSQL_H
#define PHALCON_DB_DIALECT_MYSQL_H

#include "php_phalcon.h"

zend_class_entry *phalcon_db_dialect_mysql_ce;

PHALCON_INIT_CLASS(Phalcon_Db_Dialect_Mysql);

#endif /* PHALCON_DB_DIALECT_MYSQL_H */


#ifndef PHALCON_DB_DIALECT_ORACLE_H
#define PHALCON_DB_DIALECT_ORACLE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_db_dialect_oracle_ce;

PHALCON_INIT_CLASS(Phalcon_Db_Dialect_Oracle);

#endif /* PHALCON_DB_DIALECT_ORACLE_H */


#ifndef PHALCON_DB_DIALECT_POSTGRESQL_H
#define PHALCON_DB_DIALECT_POSTGRESQL_H

#include "php_phalcon.h"

zend_class_entry *phalcon_db_dialect_postgresql_ce;

PHALCON_INIT_CLASS(Phalcon_Db_Dialect_Postgresql);

#endif /* PHALCON_DB_DIALECT_POSTGRESQL_H */


#ifndef PHALCON_DB_DIALECT_SQLITE_H
#define PHALCON_DB_DIALECT_SQLITE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_db_dialect_sqlite_ce;

PHALCON_INIT_CLASS(Phalcon_Db_Dialect_Sqlite);

#endif /* PHALCON_DB_DIALECT_SQLITE_H */


#ifndef PHALCON_DB_EXCEPTION_H
#define PHALCON_DB_EXCEPTION_H

#include "php_phalcon.h"

zend_class_entry *phalcon_db_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Db_Exception);

#endif /* PHALCON_DB_EXCEPTION_H */


#ifndef PHALCON_DB_INDEX_H
#define PHALCON_DB_INDEX_H

#include "php_phalcon.h"

zend_class_entry *phalcon_db_index_ce;

PHALCON_INIT_CLASS(Phalcon_Db_Index);

#endif /* PHALCON_DB_INDEX_H */


#ifndef PHALCON_DB_INDEXINTERFACE_H
#define PHALCON_DB_INDEXINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_db_indexinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Db_IndexInterface);

#endif /* PHALCON_DB_INDEXINTERFACE_H */


#ifndef PHALCON_DB_PROFILER_H
#define PHALCON_DB_PROFILER_H

#include "php_phalcon.h"

zend_class_entry *phalcon_db_profiler_ce;

PHALCON_INIT_CLASS(Phalcon_Db_Profiler);

#endif /* PHALCON_DB_PROFILER_H */


#ifndef PHALCON_DB_PROFILER_ITEM_H
#define PHALCON_DB_PROFILER_ITEM_H

#include "php_phalcon.h"

zend_class_entry *phalcon_db_profiler_item_ce;

PHALCON_INIT_CLASS(Phalcon_Db_Profiler_Item);

#endif /* PHALCON_DB_PROFILER_ITEM_H */


#ifndef PHALCON_DB_RAWVALUE_H
#define PHALCON_DB_RAWVALUE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_db_rawvalue_ce;

PHALCON_INIT_CLASS(Phalcon_Db_RawValue);

#endif /* PHALCON_DB_RAWVALUE_H */


#ifndef PHALCON_DB_REFERENCE_H
#define PHALCON_DB_REFERENCE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_db_reference_ce;

PHALCON_INIT_CLASS(Phalcon_Db_Reference);

#endif /* PHALCON_DB_REFERENCE_H */


#ifndef PHALCON_DB_REFERENCEINTERFACE_H
#define PHALCON_DB_REFERENCEINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_db_referenceinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Db_ReferenceInterface);

#endif /* PHALCON_DB_REFERENCEINTERFACE_H */


#ifndef PHALCON_DB_RESULTINTERFACE_H
#define PHALCON_DB_RESULTINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_db_resultinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Db_ResultInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_resultinterface_dataseek, 0, 0, 1)
	ZEND_ARG_INFO(0, number)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_resultinterface_execute, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_resultinterface_fetch, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_resultinterface_fetcharray, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_resultinterface_fetchall, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_resultinterface_numrows, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_resultinterface_getinternalresult, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_resultinterface_setfetchmode, 0, 0, 1)
	ZEND_ARG_INFO(0, fetchMode)
ZEND_END_ARG_INFO()

#endif /* PHALCON_DB_RESULTINTERFACE_H */


#ifndef PHALCON_DB_RESULT_PDO_H
#define PHALCON_DB_RESULT_PDO_H

#include "php_phalcon.h"

zend_class_entry *phalcon_db_result_pdo_ce;

PHALCON_INIT_CLASS(Phalcon_Db_Result_Pdo);

#endif /* PHALCON_DB_RESULT_PDO_H */



#ifndef PHALCON_DEBUG_H
#define PHALCON_DEBUG_H

#include "php_phalcon.h"

zend_class_entry *phalcon_debug_ce;

PHALCON_INIT_CLASS(Phalcon_Debug);

#endif /* PHALCON_DEBUG_H */



#ifndef PHALCON_DI_H
#define PHALCON_DI_H

#include "php_phalcon.h"

zend_class_entry *phalcon_di_ce;

PHALCON_INIT_CLASS(Phalcon_DI);

static void phalcon_di_set_services(zval *this_ptr, zval *services TSRMLS_DC);

#endif /* PHALCON_DI_H */


#ifndef PHALCON_DIINTERFACE_H
#define PHALCON_DIINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_diinterface_ce;

PHALCON_INIT_CLASS(Phalcon_DiInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_diinterface_set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, definition)
	ZEND_ARG_INFO(0, shared)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_diinterface_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_diinterface_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_diinterface_getshared, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_diinterface_getservice, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_diinterface_setservice, 0, 0, 1)
	ZEND_ARG_INFO(0, rawDefinition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_diinterface_has, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_diinterface_setdefault, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

#endif /* PHALCON_DIINTERFACE_H */


#ifndef PHALCON_DI_EXCEPTION_H
#define PHALCON_DI_EXCEPTION_H

#include "php_phalcon.h"

zend_class_entry *phalcon_di_exception_ce;

PHALCON_INIT_CLASS(Phalcon_DI_Exception);

#endif /* PHALCON_DI_EXCEPTION_H */


#ifndef PHALCON_DI_FACTORYDEFAULT_H
#define PHALCON_DI_FACTORYDEFAULT_H

#include "php_phalcon.h"

zend_class_entry *phalcon_di_factorydefault_ce;

PHALCON_INIT_CLASS(Phalcon_DI_FactoryDefault);

#endif /* PHALCON_DI_FACTORYDEFAULT_H */


#ifndef PHALCON_DI_FACTORYDEFAULT_CLI_H
#define PHALCON_DI_FACTORYDEFAULT_CLI_H

#include "php_phalcon.h"

zend_class_entry *phalcon_di_factorydefault_cli_ce;

PHALCON_INIT_CLASS(Phalcon_DI_FactoryDefault_CLI);

#endif /* PHALCON_DI_FACTORYDEFAULT_CLI_H */


#ifndef PHALCON_DI_INJECTIONAWAREINTERFACE_H
#define PHALCON_DI_INJECTIONAWAREINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_di_injectionawareinterface_ce;

PHALCON_INIT_CLASS(Phalcon_DI_InjectionAwareInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_injectionawareinterface_getdi, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_injectionawareinterface_setdi, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

#endif /* PHALCON_DI_INJECTIONAWAREINTERFACE_H */


#ifndef PHALCON_DI_INJECTABLE_H
#define PHALCON_DI_INJECTABLE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_di_injectable_ce;

PHALCON_INIT_CLASS(Phalcon_DI_Injectable);

#endif /* PHALCON_DI_INJECTABLE_H */


#ifndef PHALCON_DI_SERVICE_H
#define PHALCON_DI_SERVICE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_di_service_ce;

PHALCON_INIT_CLASS(Phalcon_DI_Service);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_service_setsharedinstance, 0, 0, 1)
	ZEND_ARG_INFO(0, sharedInstance)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_service_setparameter, 0, 0, 2)
	ZEND_ARG_INFO(0, position)
	ZEND_ARG_INFO(0, parameter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_service_getparameter, 0, 0, 1)
	ZEND_ARG_INFO(0, position)
ZEND_END_ARG_INFO()

#endif /* PHALCON_DI_SERVICE_H */


#ifndef PHALCON_DI_SERVICEINTERFACE_H
#define PHALCON_DI_SERVICEINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_di_serviceinterface_ce;

PHALCON_INIT_CLASS(Phalcon_DI_ServiceInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_serviceinterface_setshared, 0, 0, 1)
	ZEND_ARG_INFO(0, shared)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_serviceinterface_setdefinition, 0, 0, 1)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_serviceinterface_resolve, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_serviceinterface_getname, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_serviceinterface_isshared, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_serviceinterface_isresolved, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_serviceinterface_getdefinition, 0, 0, 0)
ZEND_END_ARG_INFO()

#endif /* PHALCON_DI_SERVICEINTERFACE_H */


#ifndef PHALCON_DI_SERVICE_BUILDER_H
#define PHALCON_DI_SERVICE_BUILDER_H

#include "php_phalcon.h"

zend_class_entry *phalcon_di_service_builder_ce;

PHALCON_INIT_CLASS(Phalcon_DI_Service_Builder);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_service_builder_build, 0, 0, 2)
	ZEND_ARG_INFO(0, dependencyInjector)
	ZEND_ARG_INFO(0, definition)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

#endif /* PHALCON_DI_SERVICE_BUILDER_H */



#ifndef PHALCON_DISPATCHER_H
#define PHALCON_DISPATCHER_H

#include "php_phalcon.h"

zend_class_entry *phalcon_dispatcher_ce;

PHALCON_INIT_CLASS(Phalcon_Dispatcher);

#endif /* PHALCON_DISPATCHER_H */


#ifndef PHALCON_DISPATCHERINTERFACE_H
#define PHALCON_DISPATCHERINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_dispatcherinterface_ce;

PHALCON_INIT_CLASS(Phalcon_DispatcherInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcherinterface_setactionsuffix, 0, 0, 1)
	ZEND_ARG_INFO(0, actionSuffix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcherinterface_setdefaultnamespace, 0, 0, 1)
	ZEND_ARG_INFO(0, namespace)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcherinterface_setdefaultaction, 0, 0, 1)
	ZEND_ARG_INFO(0, actionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcherinterface_setactionname, 0, 0, 1)
	ZEND_ARG_INFO(0, actionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcherinterface_setparams, 0, 0, 1)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcherinterface_setparam, 0, 0, 2)
	ZEND_ARG_INFO(0, param)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcherinterface_getparam, 0, 0, 1)
	ZEND_ARG_INFO(0, param)
	ZEND_ARG_INFO(0, filters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcherinterface_forward, 0, 0, 1)
	ZEND_ARG_INFO(0, forward)
ZEND_END_ARG_INFO()

#endif /* PHALCON_DISPATCHERINTERFACE_H */



#ifndef PHALCON_ESCAPER_H
#define PHALCON_ESCAPER_H

#include "php_phalcon.h"

zend_class_entry *phalcon_escaper_ce;

PHALCON_INIT_CLASS(Phalcon_Escaper);

#endif /* PHALCON_ESCAPER_H */


#ifndef PHALCON_ESCAPERINTERFACE_H
#define PHALCON_ESCAPERINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_escaperinterface_ce;

PHALCON_INIT_CLASS(Phalcon_EscaperInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaperinterface_setencoding, 0, 0, 1)
	ZEND_ARG_INFO(0, encoding)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaperinterface_sethtmlquotetype, 0, 0, 1)
	ZEND_ARG_INFO(0, quoteType)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaperinterface_escapehtml, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaperinterface_escapehtmlattr, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaperinterface_escapecss, 0, 0, 1)
	ZEND_ARG_INFO(0, css)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaperinterface_escapejs, 0, 0, 1)
	ZEND_ARG_INFO(0, js)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaperinterface_escapeurl, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
ZEND_END_ARG_INFO()

#endif /* PHALCON_ESCAPERINTERFACE_H */


#ifndef PHALCON_ESCAPER_EXCEPTION_H
#define PHALCON_ESCAPER_EXCEPTION_H

#include "php_phalcon.h"

zend_class_entry *phalcon_escaper_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Escaper_Exception);

#endif /* PHALCON_ESCAPER_EXCEPTION_H */



#ifndef PHALCON_EVENT_H
#define PHALCON_EVENT_H

#include "php_phalcon.h"

zend_class_entry *phalcon_events_event_ce;

PHALCON_INIT_CLASS(Phalcon_Events_Event);

#endif /* PHALCON_EVENT_H */


#ifndef PHALCON_EVENTS_EVENTSAWAREINTERFACE_H
#define PHALCON_EVENTS_EVENTSAWAREINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_events_eventsawareinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Events_EventsAwareInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_eventsawareinterface_geteventsmanager, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_eventsawareinterface_seteventsmanager, 0, 0, 1)
	ZEND_ARG_INFO(0, eventsManager)
ZEND_END_ARG_INFO()

#endif /* PHALCON_EVENTS_EVENTSAWAREINTERFACE_H */


#ifndef PHALCON_EVENTS_EXCEPTION_H
#define PHALCON_EVENTS_EXCEPTION_H

#include "php_phalcon.h"

zend_class_entry *phalcon_events_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Events_Exception);

#endif


#ifndef PHALCON_EVENTS_MANAGERINTERFACE_H
#define PHALCON_EVENTS_MANAGERINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_events_managerinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Events_ManagerInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_managerinterface_attach, 0, 0, 2)
	ZEND_ARG_INFO(0, eventType)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_managerinterface_detachall, 0, 0, 0)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_managerinterface_fire, 0, 0, 2)
	ZEND_ARG_INFO(0, eventType)
	ZEND_ARG_INFO(0, source)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_managerinterface_getlisteners, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

#endif /* PHALCON_EVENTS_MANAGERINTERFACE_H */


#ifndef PHALCON_EVENTS_MANAGER_H
#define PHALCON_EVENTS_MANAGER_H

#include "php_phalcon.h"

zend_class_entry *phalcon_events_manager_ce;

PHALCON_INIT_CLASS(Phalcon_Events_Manager);

#endif /* PHALCON_EVENTS_MANAGER_H */



#ifndef PHALCON_EXCEPTION_H
#define PHALCON_EXCEPTION_H

#include "php_phalcon.h"

zend_class_entry *phalcon_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Exception);

#endif /* PHALCON_EXCEPTION_H */



#ifndef PHALCON_FILTER_H
#define PHALCON_FILTER_H

#include "php_phalcon.h"

zend_class_entry *phalcon_filter_ce;

PHALCON_INIT_CLASS(Phalcon_Filter);

#endif /* PHALCON_FILTER_H */


#ifndef PHALCON_FILTERINTERFACE_H
#define PHALCON_FILTERINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_filterinterface_ce;

PHALCON_INIT_CLASS(Phalcon_FilterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filterinterface_add, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filterinterface_sanitize, 0, 0, 2)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, filters)
ZEND_END_ARG_INFO()

#endif /* PHALCON_FILTERINTERFACE_H */


#ifndef PHALCON_FILTER_EXCEPTION_H
#define PHALCON_FILTER_EXCEPTION_H

#include "php_phalcon.h"

zend_class_entry *phalcon_filter_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Filter_Exception);

#endif /* PHALCON_FILTER_EXCEPTION_H */


#ifndef PHALCON_FILTER_USERFILTERINTERFACE_H
#define PHALCON_FILTER_USERFILTERINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_filter_userfilterinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Filter_UserFilterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_userfilterinterface_filter, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

#endif /* PHALCON_FILTER_USERFILTERINTERFACE_H */



#ifndef PHALCON_FLASH_H
#define PHALCON_FLASH_H

#include "php_phalcon.h"

zend_class_entry *phalcon_flash_ce;

PHALCON_INIT_CLASS(Phalcon_Flash);

#endif /* PHALCON_FLASH_H */


#ifndef PHALCON_FLASHINTERFACE_H
#define PHALCON_FLASHINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_flashinterface_ce;

PHALCON_INIT_CLASS(Phalcon_FlashInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flashinterface_error, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flashinterface_notice, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flashinterface_success, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flashinterface_warning, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flashinterface_message, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

#endif /* PHALCON_FLASHINTERFACE_H */


#ifndef PHALCON_FLASH_DIRECT_H
#define PHALCON_FLASH_DIRECT_H

#include "php_phalcon.h"

zend_class_entry *phalcon_flash_direct_ce;

PHALCON_INIT_CLASS(Phalcon_Flash_Direct);

#endif /* PHALCON_FLASH_DIRECT_H */


#ifndef PHALCON_FLASH_EXCEPTION_H
#define PHALCON_FLASH_EXCEPTION_H

#include "php_phalcon.h"

<<<<<<< HEAD
zend_class_entry *phalcon_flash_exception_ce;
=======
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_checkhash, 0, 0, 2)
	ZEND_ARG_INFO(0, password)
	ZEND_ARG_INFO(0, passwordHash)
	ZEND_ARG_INFO(0, maxPasswordLength)
ZEND_END_ARG_INFO()
>>>>>>> master

PHALCON_INIT_CLASS(Phalcon_Flash_Exception);

#endif /* PHALCON_FLASH_EXCEPTION_H */


#ifndef PHALCON_FLASH_SESSION_H
#define PHALCON_FLASH_SESSION_H

#include "php_phalcon.h"

zend_class_entry *phalcon_flash_session_ce;

PHALCON_INIT_CLASS(Phalcon_Flash_Session);

#endif /* PHALCON_FLASH_SESSION_H */



#ifndef PHALCON_FORMS_ELEMENT_H
#define PHALCON_FORMS_ELEMENT_H

#include "php_phalcon.h"

zend_class_entry *phalcon_forms_element_ce;

PHALCON_INIT_CLASS(Phalcon_Forms_Element);

#endif /* PHALCON_FORMS_ELEMENT_H */


#ifndef PHALCON_FORMS_ELEMENTINTERFACE_H
#define PHALCON_FORMS_ELEMENTINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_forms_elementinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Forms_ElementInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_setform, 0, 0, 1)
	ZEND_ARG_INFO(0, form)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_setname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_setfilters, 0, 0, 1)
	ZEND_ARG_INFO(0, filters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_addfilter, 0, 0, 1)
	ZEND_ARG_INFO(0, filter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_addvalidators, 0, 0, 1)
	ZEND_ARG_INFO(0, validators)
	ZEND_ARG_INFO(0, merge)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_addvalidator, 0, 0, 1)
	ZEND_ARG_INFO(0, validator)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_prepareattributes, 0, 0, 0)
	ZEND_ARG_INFO(0, attributes)
	ZEND_ARG_INFO(0, useChecked)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_setattribute, 0, 0, 2)
	ZEND_ARG_INFO(0, attribute)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_getattribute, 0, 0, 1)
	ZEND_ARG_INFO(0, attribute)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_setattributes, 0, 0, 1)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_setuseroption, 0, 0, 2)
	ZEND_ARG_INFO(0, option)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_getuseroption, 0, 0, 1)
	ZEND_ARG_INFO(0, option)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_setuseroptions, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_setlabel, 0, 0, 1)
	ZEND_ARG_INFO(0, label)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_setdefault, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_setmessages, 0, 0, 1)
	ZEND_ARG_INFO(0, group)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_appendmessage, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_render, 0, 0, 0)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

#endif /* PHALCON_FORMS_ELEMENTINTERFACE_H */


#ifndef PHALCON_FORMS_ELEMENT_CHECK_H
#define PHALCON_FORMS_ELEMENT_CHECK_H

#include "php_phalcon.h"

zend_class_entry *phalcon_forms_element_check_ce;

PHALCON_INIT_CLASS(Phalcon_Forms_Element_Check);

#endif /* PHALCON_FORMS_ELEMENT_CHECK_H */


#ifndef PHALCON_FORMS_ELEMENT_DATE_H
#define PHALCON_FORMS_ELEMENT_DATE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_forms_element_date_ce;

PHALCON_INIT_CLASS(Phalcon_Forms_Element_Date);

#endif /* PHALCON_FORMS_ELEMENT_DATE_H */


#ifndef PHALCON_FORMS_ELEMENT_EMAIL_H
#define PHALCON_FORMS_ELEMENT_EMAIL_H

#include "php_phalcon.h"

zend_class_entry *phalcon_forms_element_email_ce;

PHALCON_INIT_CLASS(Phalcon_Forms_Element_Email);

#endif /* PHALCON_FORMS_ELEMENT_EMAIL_H */


#ifndef PHALCON_FORMS_ELEMENT_FILE_H
#define PHALCON_FORMS_ELEMENT_FILE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_forms_element_file_ce;

PHALCON_INIT_CLASS(Phalcon_Forms_Element_File);

#endif /* PHALCON_FORMS_ELEMENT_FILE_H */


#ifndef PHALCON_FORMS_ELEMENT_HIDDEN_H
#define PHALCON_FORMS_ELEMENT_HIDDEN_H

#include "php_phalcon.h"

zend_class_entry *phalcon_forms_element_hidden_ce;

PHALCON_INIT_CLASS(Phalcon_Forms_Element_Hidden);

#endif /* PHALCON_FORMS_ELEMENT_HIDDEN_H */


#ifndef PHALCON_FORMS_ELEMENT_NUMERIC_H
#define PHALCON_FORMS_ELEMENT_NUMERIC_H

#include "php_phalcon.h"

zend_class_entry *phalcon_forms_element_numeric_ce;

PHALCON_INIT_CLASS(Phalcon_Forms_Element_Numeric);

#endif /* PHALCON_FORMS_ELEMENT_NUMERIC_H */


#ifndef PHALCON_FORMS_ELEMENT_PASSWORD_H
#define PHALCON_FORMS_ELEMENT_PASSWORD_H

#include "php_phalcon.h"

zend_class_entry *phalcon_forms_element_password_ce;

PHALCON_INIT_CLASS(Phalcon_Forms_Element_Password);

#endif /* PHALCON_FORMS_ELEMENT_PASSWORD_H */

#ifndef PHALCON_FORMS_ELEMENT_RADIO_H
#define PHALCON_FORMS_ELEMENT_RADIO_H

#include "php_phalcon.h"

zend_class_entry *phalcon_forms_element_radio_ce;

PHALCON_INIT_CLASS(Phalcon_Forms_Element_Radio);

#endif /* PHALCON_FORMS_ELEMENT_RADIO_H */


#ifndef PHALCON_FORMS_ELEMENT_SELECT_H
#define PHALCON_FORMS_ELEMENT_SELECT_H

#include "php_phalcon.h"

zend_class_entry *phalcon_forms_element_select_ce;

PHALCON_INIT_CLASS(Phalcon_Forms_Element_Select);

#endif /* PHALCON_FORMS_ELEMENT_SELECT_H */


#ifndef PHALCON_FORMS_ELEMENT_SUBMIT_H
#define PHALCON_FORMS_ELEMENT_SUBMIT_H

#include "php_phalcon.h"

zend_class_entry *phalcon_forms_element_submit_ce;

PHALCON_INIT_CLASS(Phalcon_Forms_Element_Submit);

#endif /* PHALCON_FORMS_ELEMENT_SUBMIT_H */


#ifndef PHALCON_FORMS_ELEMENT_TEXT_H
#define PHALCON_FORMS_ELEMENT_TEXT_H

#include "php_phalcon.h"

zend_class_entry *phalcon_forms_element_text_ce;

PHALCON_INIT_CLASS(Phalcon_Forms_Element_Text);

#endif /* PHALCON_FORMS_ELEMENT_TEXT_H */


#ifndef PHALCON_FORMS_ELEMENT_TEXTAREA_H
#define PHALCON_FORMS_ELEMENT_TEXTAREA_H

#include "php_phalcon.h"

zend_class_entry *phalcon_forms_element_textarea_ce;

PHALCON_INIT_CLASS(Phalcon_Forms_Element_TextArea);

#endif /* PHALCON_FORMS_ELEMENT_TEXTAREA_H */


#ifndef PHALCON_FORMS_EXCEPTION_H
#define PHALCON_FORMS_EXCEPTION_H

#include "php_phalcon.h"

zend_class_entry *phalcon_forms_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Forms_Exception);

#endif /* PHALCON_FORMS_EXCEPTION_H */


#ifndef PHALCON_FORMS_FORM_H
#define PHALCON_FORMS_FORM_H

#include "php_phalcon.h"

zend_class_entry *phalcon_forms_form_ce;

PHALCON_INIT_CLASS(Phalcon_Forms_Form);

#endif /* PHALCON_FORMS_FORM_H */


#ifndef PHALCON_FORMS_MANAGER_H
#define PHALCON_FORMS_MANAGER_H

#include "php_phalcon.h"

zend_class_entry *phalcon_forms_manager_ce;

PHALCON_INIT_CLASS(Phalcon_Forms_Manager);

#endif /* PHALCON_FORMS_MANAGER_H */



#ifndef PHALCON_HTTP_COOKIE_H
#define PHALCON_HTTP_COOKIE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_http_cookie_ce;

PHALCON_INIT_CLASS(Phalcon_Http_Cookie);

#endif /* PHALCON_HTTP_COOKIE_H */


#ifndef PHALCON_HTTP_COOKIE_EXCEPTION_H
#define PHALCON_HTTP_COOKIE_EXCEPTION_H

#include "php_phalcon.h"

zend_class_entry *phalcon_http_cookie_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Http_Cookie_Exception);

#endif /* PHALCON_HTTP_COOKIE_EXCEPTION_H */


#ifndef PHALCON_HTTP_REQUEST_H
#define PHALCON_HTTP_REQUEST_H

#include "php_phalcon.h"

zend_class_entry *phalcon_http_request_ce;

PHALCON_INIT_CLASS(Phalcon_Http_Request);

#endif /* PHALCON_HTTP_REQUEST_H */


#ifndef PHALCON_HTTP_REQUESTINTERFACE_H
#define PHALCON_HTTP_REQUESTINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_http_requestinterface_ce;

<<<<<<< HEAD
PHALCON_INIT_CLASS(Phalcon_Http_RequestInterface);
=======
static PHP_METHOD(Phalcon_Annotations_Annotation, __construct);
static PHP_METHOD(Phalcon_Annotations_Annotation, getName);
static PHP_METHOD(Phalcon_Annotations_Annotation, getExpression);
static PHP_METHOD(Phalcon_Annotations_Annotation, getExprArguments);
static PHP_METHOD(Phalcon_Annotations_Annotation, getArguments);
static PHP_METHOD(Phalcon_Annotations_Annotation, numberArguments);
static PHP_METHOD(Phalcon_Annotations_Annotation, getArgument);
static PHP_METHOD(Phalcon_Annotations_Annotation, hasArgument);
>>>>>>> master

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_get, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_getpost, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_getput, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_getquery, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

<<<<<<< HEAD
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_getserver, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_has, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_hasput, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_haspost, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()
=======
PHALCON_INIT_FUNCS(phalcon_annotations_annotation_method_entry){
	PHP_ME(Phalcon_Annotations_Annotation, __construct, arginfo_phalcon_annotations_annotation___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Annotations_Annotation, getName, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Annotations_Annotation, getExpression, arginfo_phalcon_annotations_annotation_getexpression, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Annotations_Annotation, getExprArguments, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Annotations_Annotation, getArguments, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Annotations_Annotation, numberArguments, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Annotations_Annotation, getArgument, arginfo_phalcon_annotations_annotation_getargument, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Annotations_Annotation, hasArgument, arginfo_phalcon_annotations_annotation_hasargument, ZEND_ACC_PUBLIC) 
	PHP_MALIAS(Phalcon_Annotations_Annotation, getNamedArgument, getArgument, arginfo_phalcon_annotations_annotation_getargument, ZEND_ACC_PUBLIC)
	PHP_MALIAS(Phalcon_Annotations_Annotation, getNamedParameter, getArgument, arginfo_phalcon_annotations_annotation_getargument, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
	PHP_MALIAS(Phalcon_Annotations_Annotation, hasNamedArgument, hasArgument, arginfo_phalcon_annotations_annotation_hasargument, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
>>>>>>> master

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_hasquery, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_hasserver, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_getheader, 0, 0, 1)
	ZEND_ARG_INFO(0, header)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_getclientaddress, 0, 0, 0)
	ZEND_ARG_INFO(0, trustForwardedHeader)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_ismethod, 0, 0, 1)
	ZEND_ARG_INFO(0, methods)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_hasfiles, 0, 0, 0)
	ZEND_ARG_INFO(0, notErrored)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_getuploadedfiles, 0, 0, 0)
	ZEND_ARG_INFO(0, notErrored)
ZEND_END_ARG_INFO()

#endif /* PHALCON_HTTP_REQUESTINTERFACE_H */


#ifndef PHALCON_HTTP_REQUEST_EXCEPTION_H
#define PHALCON_HTTP_REQUEST_EXCEPTION_H

#include "php_phalcon.h"

zend_class_entry *phalcon_http_request_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Http_Request_Exception);

#endif /* PHALCON_HTTP_REQUEST_EXCEPTION_H */


#ifndef PHALCON_HTTP_REQUEST_FILE_H
#define PHALCON_HTTP_REQUEST_FILE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_http_request_file_ce;

PHALCON_INIT_CLASS(Phalcon_Http_Request_File);

#endif /* PHALCON_HTTP_REQUEST_FILE_H */


#ifndef PHALCON_HTTP_REQUEST_FILEINTERFACE_H
#define PHALCON_HTTP_REQUEST_FILEINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_http_request_fileinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Http_Request_FileInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_fileinterface_moveto, 0, 0, 1)
	ZEND_ARG_INFO(0, destination)
ZEND_END_ARG_INFO()

#endif /* PHALCON_HTTP_REQUEST_FILEINTERFACE_H */


#ifndef PHALCON_HTTP_RESPONSE_H
#define PHALCON_HTTP_RESPONSE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_http_response_ce;

PHALCON_INIT_CLASS(Phalcon_Http_Response);

#endif /* PHALCON_HTTP_RESPONSE_H */


#ifndef PHALCON_HTTP_RESPONSEINTERFACE_H
#define PHALCON_HTTP_RESPONSEINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_http_responseinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Http_ResponseInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_responseinterface_setstatuscode, 0, 0, 2)
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_responseinterface_setheader, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_responseinterface_setrawheader, 0, 0, 1)
	ZEND_ARG_INFO(0, header)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_responseinterface_setexpires, 0, 0, 1)
	ZEND_ARG_INFO(0, datetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_responseinterface_setcontenttype, 0, 0, 1)
	ZEND_ARG_INFO(0, contentType)
	ZEND_ARG_INFO(0, charset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_responseinterface_redirect, 0, 0, 0)
	ZEND_ARG_INFO(0, location)
	ZEND_ARG_INFO(0, externalRedirect)
	ZEND_ARG_INFO(0, statusCode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_responseinterface_setcontent, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_responseinterface_setjsoncontent, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_responseinterface_appendcontent, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_responseinterface_setfiletosend, 0, 0, 1)
	ZEND_ARG_INFO(0, filePath)
	ZEND_ARG_INFO(0, attachmentName)
ZEND_END_ARG_INFO()

#endif /* PHALCON_HTTP_RESPONSEINTERFACE_H */


#ifndef PHALCON_HTTP_RESPONSE_COOKIES_H
#define PHALCON_HTTP_RESPONSE_COOKIES_H

#include "php_phalcon.h"

zend_class_entry *phalcon_http_response_cookies_ce;

PHALCON_INIT_CLASS(Phalcon_Http_Response_Cookies);

#endif /* PHALCON_HTTP_RESPONSE_COOKIES_H */


#ifndef PHALCON_HTTP_REQUEST_COOKIESINTERFACE_H
#define PHALCON_HTTP_REQUEST_COOKIESINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_http_response_cookiesinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Http_Response_CookiesInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_cookiesinterface_useencryption, 0, 0, 1)
	ZEND_ARG_INFO(0, useEncryption)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_cookiesinterface_set, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, expire)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, secure)
	ZEND_ARG_INFO(0, domain)
	ZEND_ARG_INFO(0, httpOnly)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_cookiesinterface_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_cookiesinterface_has, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_cookiesinterface_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

#endif /* PHALCON_HTTP_REQUEST_COOKIESINTERFACE_H */


#ifndef PHALCON_HTTP_RESPONSE_EXCEPTION_H
#define PHALCON_HTTP_RESPONSE_EXCEPTION_H

#include "php_phalcon.h"

zend_class_entry *phalcon_http_response_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Http_Response_Exception);

#endif /* PHALCON_HTTP_RESPONSE_EXCEPTION_H */


#ifndef PHALCON_HTTP_RESPONSE_HEADERS_H
#define PHALCON_HTTP_RESPONSE_HEADERS_H

#include "php_phalcon.h"

zend_class_entry *phalcon_http_response_headers_ce;

PHALCON_INIT_CLASS(Phalcon_Http_Response_Headers);

#endif /* PHALCON_HTTP_RESPONSE_HEADERS_H */


#ifndef PHALCON_HTTP_RESPONSE_HEADERSINTERFACE_H
#define PHALCON_HTTP_RESPONSE_HEADERSINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_http_response_headersinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Http_Response_HeadersInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_headersinterface_set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_headersinterface_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_headersinterface_setraw, 0, 0, 1)
	ZEND_ARG_INFO(0, header)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_headersinterface_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, header_index)
ZEND_END_ARG_INFO()

#endif /* PHALCON_HTTP_RESPONSE_HEADERSINTERFACE_H */



#ifndef PHALCON_IMAGE_H
#define PHALCON_IMAGE_H

#include "php_phalcon.h"

/* Resizing constraints */
#define PHALCON_IMAGE_NONE           1
#define PHALCON_IMAGE_WIDTH          2
#define PHALCON_IMAGE_HEIGHT         3
#define PHALCON_IMAGE_AUTO           4
#define PHALCON_IMAGE_INVERSE        5
#define PHALCON_IMAGE_PRECISE        6
#define PHALCON_IMAGE_TENSILE        7

/* Flipping directions */
#define PHALCON_IMAGE_HORIZONTAL    11
#define PHALCON_IMAGE_VERTICAL      12

/* Driver: GD, ImageMagick, etc */
#define PHALCON_IMAGE_GD            21
#define PHALCON_IMAGE_IMAGICK       22


zend_class_entry *phalcon_image_ce;

PHALCON_INIT_CLASS(Phalcon_Image);

#endif /* PHALCON_IMAGE_H */


#ifndef PHALCON_IMAGE_ADAPTER_H
#define PHALCON_IMAGE_ADAPTER_H

#include "php_phalcon.h"

zend_class_entry *phalcon_image_adapter_ce;

PHALCON_INIT_CLASS(Phalcon_Image_Adapter);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter__resize, 0, 0, 2)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter__liquidrescale, 0, 0, 4)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, delta_x)
	ZEND_ARG_INFO(0, regidity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter__crop, 0, 0, 4)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, offset_x)
	ZEND_ARG_INFO(0, offset_y)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter__rotate, 0, 0, 1)
	ZEND_ARG_INFO(0, degrees)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter__flip, 0, 0, 1)
	ZEND_ARG_INFO(0, direction)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter__sharpen, 0, 0, 1)
	ZEND_ARG_INFO(0, amount)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter__reflection, 0, 0, 3)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, opacity)
	ZEND_ARG_INFO(0, fade_in)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter__watermark, 0, 0, 4)
	ZEND_ARG_INFO(0, watermark)
	ZEND_ARG_INFO(0, offset_x)
	ZEND_ARG_INFO(0, offset_y)
	ZEND_ARG_INFO(0, opacity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter__text, 0, 0, 9)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, offset_x)
	ZEND_ARG_INFO(0, offset_y)
	ZEND_ARG_INFO(0, opacity)
	ZEND_ARG_INFO(0, r)
	ZEND_ARG_INFO(0, g)
	ZEND_ARG_INFO(0, b)
	ZEND_ARG_INFO(0, size)
	ZEND_ARG_INFO(0, fontfile)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter__mask, 0, 0, 1)
	ZEND_ARG_INFO(0, mask)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter__blur, 0, 0, 1)
	ZEND_ARG_INFO(0, radius)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter__pixelate, 0, 0, 1)
	ZEND_ARG_INFO(0, amount)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter__background, 0, 0, 4)
	ZEND_ARG_INFO(0, r)
	ZEND_ARG_INFO(0, g)
	ZEND_ARG_INFO(0, b)
	ZEND_ARG_INFO(0, opacity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter__save, 0, 0, 2)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_INFO(0, quality)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter__render, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, quality)
ZEND_END_ARG_INFO()

#endif /* PHALCON_IMAGE_ADAPTER_H */


#ifndef PHALCON_IMAGE_ADAPTERINTERFACE_H
#define PHALCON_IMAGE_ADAPTERINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_image_adapterinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Image_AdapterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_resize, 0, 0, 0)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, master)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_liquidrescale, 0, 0, 2)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, delta_x)
	ZEND_ARG_INFO(0, rigidity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_crop, 0, 0, 2)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, offset_x)
	ZEND_ARG_INFO(0, offset_y)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_rotate, 0, 0, 1)
	ZEND_ARG_INFO(0, degrees)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_flip, 0, 0, 1)
	ZEND_ARG_INFO(0, direction)
ZEND_END_ARG_INFO()

<<<<<<< HEAD
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_sharpen, 0, 0, 1)
	ZEND_ARG_INFO(0, amount)
ZEND_END_ARG_INFO()
=======
static PHP_METHOD(Phalcon_Logger_Formatter_Firephp, getTypeString);
static PHP_METHOD(Phalcon_Logger_Formatter_Firephp, getShowBacktrace);
static PHP_METHOD(Phalcon_Logger_Formatter_Firephp, setShowBacktrace);
static PHP_METHOD(Phalcon_Logger_Formatter_Firephp, format);
>>>>>>> master

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_reflection, 0, 0, 0)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, opacity)
	ZEND_ARG_INFO(0, fade_in)
ZEND_END_ARG_INFO()

<<<<<<< HEAD
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_watermark, 0, 0, 1)
	ZEND_ARG_INFO(0, watermark)
	ZEND_ARG_INFO(0, offset_x)
	ZEND_ARG_INFO(0, offset_y)
	ZEND_ARG_INFO(0, opacity)
ZEND_END_ARG_INFO()
=======
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_formatter_firephp_getshowbacktrace, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_formatter_firephp_setshowbacktrace, 0, 0, 0)
	ZEND_ARG_INFO(0, show)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_logger_formatter_firephp_method_entry){
	PHP_ME(Phalcon_Logger_Formatter_Firephp, getTypeString, arginfo_phalcon_logger_formatter_gettypestring, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Formatter_Firephp, getShowBacktrace, arginfo_phalcon_logger_formatter_firephp_getshowbacktrace, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Formatter_Firephp, setShowBacktrace, arginfo_phalcon_logger_formatter_firephp_setshowbacktrace, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Formatter_Firephp, format, arginfo_phalcon_logger_formatter_firephp_format, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
>>>>>>> master

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_text, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, offset_x)
	ZEND_ARG_INFO(0, offset_y)
	ZEND_ARG_INFO(0, opacity)
	ZEND_ARG_INFO(0, color)
	ZEND_ARG_INFO(0, size)
	ZEND_ARG_INFO(0, fontfile)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_mask, 0, 0, 1)
	ZEND_ARG_INFO(0, mask)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_background, 0, 0, 1)
	ZEND_ARG_INFO(0, color)
	ZEND_ARG_INFO(0, quality)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_blur, 0, 0, 0)
	ZEND_ARG_INFO(0, radius)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_pixelate, 0, 0, 0)
	ZEND_ARG_INFO(0, amount)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_save, 0, 0, 0)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_INFO(0, quality)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_render, 0, 0, 0)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, quality)
ZEND_END_ARG_INFO()

#endif /* PHALCON_IMAGE_ADAPTERINTERFACE_H */


#ifndef PHALCON_IMAGE_ADAPTER_GD_H
#define PHALCON_IMAGE_ADAPTER_GD_H

#include "php_phalcon.h"

zend_class_entry *phalcon_image_adapter_gd_ce;

PHALCON_INIT_CLASS(Phalcon_Image_Adapter_GD);

#endif /* PHALCON_IMAGE_ADAPTER_GD_H */


#ifndef PHALCON_IMAGE_ADAPTER_IMAGICK_H
#define PHALCON_IMAGE_ADAPTER_IMAGICK_H

#include "php_phalcon.h"

zend_class_entry *phalcon_image_adapter_imagick_ce;

PHALCON_INIT_CLASS(Phalcon_Image_Adapter_Imagick);

#endif /* PHALCON_IMAGE_ADAPTER_IMAGICK_H */


#ifndef PHALCON_IMAGE_EXCEPTION
#define PHALCON_IMAGE_EXCEPTION

<<<<<<< HEAD
#include "php_phalcon.h"
=======
PHALCON_INIT_FUNCS(phalcon_logger_adapter_file_method_entry){
	PHP_ME(Phalcon_Logger_Adapter_File, __construct, arginfo_phalcon_logger_adapter_file___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Logger_Adapter_File, getFormatter, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Logger_Adapter_File, logInternal, arginfo_phalcon_logger_adapter_file_loginternal, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Logger_Adapter_File, close, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Logger_Adapter_File, __wakeup, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
>>>>>>> master

zend_class_entry *phalcon_image_exception_ce;

<<<<<<< HEAD
PHALCON_INIT_CLASS(Phalcon_Image_Exception);

#endif /* PHALCON_IMAGE_EXCEPTION */
=======
#ifndef PHALCON_LOGGER_ADAPTER_FIREPHP_H
#define PHALCON_LOGGER_ADAPTER_FIREPHP_H
>>>>>>> master



#ifndef PHALCON_KERNEL_H
#define PHALCON_KERNEL_H

#include "php_phalcon.h"

zend_class_entry *phalcon_kernel_ce;

PHALCON_INIT_CLASS(Phalcon_Kernel);

#endif /* PHALCON_KERNEL_H */



#ifndef PHALCON_LOADER_H
#define PHALCON_LOADER_H

#include "php_phalcon.h"

zend_class_entry *phalcon_loader_ce;

PHALCON_INIT_CLASS(Phalcon_Loader);

#endif /* PHALCON_LOADER_H */


#ifndef PHALCON_LOADER_EXCEPTION_H
#define PHALCON_LOADER_EXCEPTION_H

#include "php_phalcon.h"

zend_class_entry *phalcon_loader_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Loader_Exception);

#endif /* PHALCON_LOADER_EXCEPTION_H */



#ifndef PHALCON_LOGGER_H
#define PHALCON_LOGGER_H

#include "php_phalcon.h"

#define PHALCON_LOGGER_EMERGENCY  0
#define PHALCON_LOGGER_CRITICAL   1
#define PHALCON_LOGGER_ALERT      2
#define PHALCON_LOGGER_ERROR      3
#define PHALCON_LOGGER_WARNING    4
#define PHALCON_LOGGER_NOTICE     5
#define PHALCON_LOGGER_INFO       6
#define PHALCON_LOGGER_DEBUG      7
#define PHALCON_LOGGER_CUSTOM     8
#define PHALCON_LOGGER_SPECIAL    9

zend_class_entry *phalcon_logger_ce;

PHALCON_INIT_CLASS(Phalcon_Logger);

#endif /* PHALCON_LOGGER_H */


#ifndef PHALCON_LOGGER_ADAPTER_H
#define PHALCON_LOGGER_ADAPTER_H

#include "php_phalcon.h"

zend_class_entry *phalcon_logger_adapter_ce;

PHALCON_INIT_CLASS(Phalcon_Logger_Adapter);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_loginternal, 0, 0, 4)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, time)
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

#endif /* PHALCON_LOGGER_ADAPTER_H */


#ifndef PHALCON_LOGGER_ADAPTERINTERFACE_H
#define PHALCON_LOGGER_ADAPTERINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_logger_adapterinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Logger_AdapterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_setformatter, 0, 0, 1)
	ZEND_ARG_INFO(0, formatter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_setloglevel, 0, 0, 1)
	ZEND_ARG_INFO(0, level)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_log, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_debug, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_error, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_info, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_notice, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_warning, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_critical, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_alert, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_emergency, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

#endif /* PHALCON_LOGGER_ADAPTERINTERFACE_H */


#ifndef PHALCON_LOGGER_ADAPTER_FILE_H
#define PHALCON_LOGGER_ADAPTER_FILE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_logger_adapter_file_ce;

PHALCON_INIT_CLASS(Phalcon_Logger_Adapter_File);

#endif /* PHALCON_LOGGER_ADAPTER_FILE_H */


#ifndef PHALCON_LOGGER_ADAPTER_FIREPHP_H
#define PHALCON_LOGGER_ADAPTER_FIREPHP_H

#include "php_phalcon.h"

zend_class_entry *phalcon_logger_adapter_firephp_ce;

PHALCON_INIT_CLASS(Phalcon_Logger_Adapter_Firephp);

#endif /* PHALCON_LOGGER_ADAPTER_FIREPHP_H */


#ifndef PHALCON_LOGGER_ADAPTER_STREAM_H
#define PHALCON_LOGGER_ADAPTER_STREAM_H

#include "php_phalcon.h"

zend_class_entry *phalcon_logger_adapter_stream_ce;

PHALCON_INIT_CLASS(Phalcon_Logger_Adapter_Stream);

#endif /* PHALCON_LOGGER_ADAPTER_STREAM_H */


#ifndef PHALCON_LOGGER_ADAPTER_SYSLOG_H
#define PHALCON_LOGGER_ADAPTER_SYSLOG_H

#include "php_phalcon.h"

zend_class_entry *phalcon_logger_adapter_syslog_ce;

PHALCON_INIT_CLASS(Phalcon_Logger_Adapter_Syslog);

#endif /* PHALCON_LOGGER_ADAPTER_SYSLOG_H */


#ifndef PHALCON_LOGGER_EXCEPTION_H
#define PHALCON_LOGGER_EXCEPTION_H

#include "php_phalcon.h"

zend_class_entry *phalcon_logger_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Logger_Exception);

#endif /* PHALCON_LOGGER_EXCEPTION_H */


#ifndef PHALCON_LOGGER_FORMATTER_H
#define PHALCON_LOGGER_FORMATTER_H

#include "php_phalcon.h"

zend_class_entry *phalcon_logger_formatter_ce;

PHALCON_INIT_CLASS(Phalcon_Logger_Formatter);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_formatter_gettypestring, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_formatter_interpolate, 0, 0, 2)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

#endif /* PHALCON_LOGGER_FORMATTER_H */


#ifndef PHALCON_LOGGER_FORMATTERINTERFACE_H
#define PHALCON_LOGGER_FORMATTERINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_logger_formatterinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Logger_FormatterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_formatterinterface_format, 0, 0, 4)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, timestamp)
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

#endif /* PHALCON_LOGGER_FORMATTERINTERFACE_H */


#ifndef PHALCON_LOGGER_FORMATTER_FIREPHP_H
#define PHALCON_LOGGER_FORMATTER_FIREPHP_H

#include "php_phalcon.h"

zend_class_entry *phalcon_logger_formatter_firephp_ce;

PHALCON_INIT_CLASS(Phalcon_Logger_Formatter_Firephp);

#endif /* PHALCON_LOGGER_FORMATTER_FIREPHP_H */


#ifndef PHALCON_LOGGER_FORMATTER_JSON_H
#define PHALCON_LOGGER_FORMATTER_JSON_H

#include "php_phalcon.h"

zend_class_entry *phalcon_logger_formatter_json_ce;

PHALCON_INIT_CLASS(Phalcon_Logger_Formatter_Json);

#endif /* PHALCON_LOGGER_FORMATTER_JSON_H */


#ifndef PHALCON_LOGGER_FORMATTER_LINE_H
#define PHALCON_LOGGER_FORMATTER_LINE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_logger_formatter_line_ce;

PHALCON_INIT_CLASS(Phalcon_Logger_Formatter_Line);

#endif /* PHALCON_LOGGER_FORMATTER_LINE_H */


#ifndef PHALCON_LOGGER_FORMATTER_SYSLOG_H
#define PHALCON_LOGGER_FORMATTER_SYSLOG_H

#include "php_phalcon.h"

zend_class_entry *phalcon_logger_formatter_syslog_ce;

PHALCON_INIT_CLASS(Phalcon_Logger_Formatter_Syslog);

#endif /* PHALCON_LOGGER_FORMATTER_SYSLOG_H */


#ifndef PHALCON_LOGGER_ITEM_H
#define PHALCON_LOGGER_ITEM_H

#include "php_phalcon.h"

zend_class_entry *phalcon_logger_item_ce;

PHALCON_INIT_CLASS(Phalcon_Logger_Item);

#endif /* PHALCON_LOGGER_ITEM_H */


#ifndef PHALCON_LOGGER_MULTIPLE_H
#define PHALCON_LOGGER_MULTIPLE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_logger_multiple_ce;

PHALCON_INIT_CLASS(Phalcon_Logger_Multiple);

#endif /* PHALCON_LOGGER_MULTIPLE_H */



#ifndef PHALCON_MVC_APPLICATION_H
#define PHALCON_MVC_APPLICATION_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_application_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Application);

#endif /* PHALCON_MVC_APPLICATION_H */


#ifndef PHALCON_MVC_APPLICATION_EXCEPTION_H
#define PHALCON_MVC_APPLICATION_EXCEPTION_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_application_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Application_Exception);

#endif /* PHALCON_MVC_APPLICATION_EXCEPTION_H */


#ifndef PHALCON_MVC_COLLECTION_H
#define PHALCON_MVC_COLLECTION_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_collection_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Collection);

#endif /* PHALCON_MVC_COLLECTION_H */


#ifndef PHALCON_MVC_COLLECTIONINTERFACE_H
#define PHALCON_MVC_COLLECTIONINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_collectioninterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_CollectionInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface_setid, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface_setconnectionservice, 0, 0, 1)
	ZEND_ARG_INFO(0, connectionService)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface_readattribute, 0, 0, 1)
	ZEND_ARG_INFO(0, attribute)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface_writeattribute, 0, 0, 2)
	ZEND_ARG_INFO(0, attribute)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface_cloneresult, 0, 0, 2)
	ZEND_ARG_INFO(0, collection)
	ZEND_ARG_INFO(0, document)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface_fireevent, 0, 0, 1)
	ZEND_ARG_INFO(0, eventName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface_fireeventcancel, 0, 0, 1)
	ZEND_ARG_INFO(0, eventName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface_appendmessage, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface_findbyid, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface_findfirst, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface_find, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface_count, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

#endif /* PHALCON_MVC_COLLECTIONINTERFACE_H */


#ifndef PHALCON_MVC_COLLECTION_DOCUMENT_H
#define PHALCON_MVC_COLLECTION_DOCUMENT_H

<<<<<<< HEAD
#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_collection_document_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Collection_Document);

#endif /* PHALCON_MVC_COLLECTION_DOCUMENT_H */
=======
zend_class_entry *phalcon_translate_exception_ce;
>>>>>>> master


#ifndef PHALCON_MVC_COLLECTION_EXCEPTION_H
#define PHALCON_MVC_COLLECTION_EXCEPTION_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_collection_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Collection_Exception);

#endif /* PHALCON_MVC_COLLECTION_EXCEPTION_H */


#ifndef PHALCON_MVC_COLLECTION_MANAGER_H
#define PHALCON_MVC_COLLECTION_MANAGER_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_collection_manager_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Collection_Manager);

#endif /* PHALCON_MVC_COLLECTION_MANAGER_H */


#ifndef PHALCON_MVC_COLLECTION_MANAGERINTERFACE_H
#define PHALCON_MVC_COLLECTION_MANAGERINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_collection_managerinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Collection_ManagerInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_setcustomeventsmanager, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, eventsManager)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_getcustomeventsmanager, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_initialize, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_isinitialized, 0, 0, 1)
	ZEND_ARG_INFO(0, modelName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_setconnectionservice, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, connectionService)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_useimplicitobjectids, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, useImplicitObjectIds)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_isusingimplicitobjectids, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_getconnection, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_notifyevent, 0, 0, 2)
	ZEND_ARG_INFO(0, eventName)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

#endif /* PHALCON_MVC_COLLECTION_MANAGERINTERFACE_H */


#ifndef PHALCON_MVC_CONTROLLER_H
#define PHALCON_MVC_CONTROLLER_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_controller_ce;

<<<<<<< HEAD
PHALCON_INIT_CLASS(Phalcon_Mvc_Controller);

#endif /* PHALCON_MVC_CONTROLLER_H */
=======
zend_class_entry *phalcon_assets_manager_ce;
>>>>>>> master


#ifndef PHALCON_MVC_CONTROLLERINTERFACE_H
#define PHALCON_MVC_CONTROLLERINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_controllerinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_ControllerInterface);

#endif /* PHALCON_MVC_CONTROLLERINTERFACE_H */


#ifndef PHALCON_MVC_DISPATCHER_H
#define PHALCON_MVC_DISPATCHER_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_dispatcher_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Dispatcher);

<<<<<<< HEAD
#endif /* PHALCON_MVC_DISPATCHER_H */


#ifndef PHALCON_MVC_DISPATCHERINTERFACE_H
#define PHALCON_MVC_DISPATCHERINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_dispatcherinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_DispatcherInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_dispatcherinterface_setcontrollersuffix, 0, 0, 1)
	ZEND_ARG_INFO(0, controllerSuffix)
=======
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_output, 0, 0, 2)
	ZEND_ARG_INFO(0, collection)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_INFO(0, type)
>>>>>>> master
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_dispatcherinterface_setdefaultcontroller, 0, 0, 1)
	ZEND_ARG_INFO(0, controllerName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_dispatcherinterface_setcontrollername, 0, 0, 1)
	ZEND_ARG_INFO(0, controllerName)
	ZEND_ARG_INFO(0, isExact)
ZEND_END_ARG_INFO()

#endif /* PHALCON_MVC_DISPATCHERINTERFACE_H */


#ifndef PHALCON_MVC_DISPATCHER_EXCEPTION_H
#define PHALCON_MVC_DISPATCHER_EXCEPTION_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_dispatcher_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Dispatcher_Exception);

#endif /* PHALCON_MVC_DISPATCHER_EXCEPTION_H */


#ifndef PHALCON_MVC_MICRO_H
#define PHALCON_MVC_MICRO_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_micro_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Micro);

#endif /* PHALCON_MVC_MICRO_H */


#ifndef PHALCON_MVC_MICRO_COLLECTION_H
#define PHALCON_MVC_MICRO_COLLECTION_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_micro_collection_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Micro_Collection);

#endif /* PHALCON_MVC_MICRO_COLLECTION_H */


#ifndef PHALCON_MVC_MICRO_COLLECTIONINTERFACE_H
#define PHALCON_MVC_MICRO_COLLECTIONINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_micro_collectioninterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Micro_CollectionInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_setprefix, 0, 0, 1)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_sethandler, 0, 0, 1)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_INFO(0, lazy)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_setlazy, 0, 0, 1)
	ZEND_ARG_INFO(0, lazy)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_map, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_get, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_post, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_put, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_patch, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_head, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_delete, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_options, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

#endif /* PHALCON_MVC_MICRO_COLLECTIONINTERFACE_H */


#ifndef PHALCON_MVC_MICRO_EXCEPTION_H
#define PHALCON_MVC_MICRO_EXCEPTION_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_micro_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Micro_Exception);

#endif /* PHALCON_MVC_MICRO_EXCEPTION_H */


#ifndef PHALCON_MVC_MICRO_LAZYLOADER_H
#define PHALCON_MVC_MICRO_LAZYLOADER_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_micro_lazyloader_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Micro_LazyLoader);

#endif /* PHALCON_MVC_MICRO_LAZYLOADER_H */


#ifndef PHALCON_MVC_MICRO_MIDDLEWAREINTERFACE_H
#define PHALCON_MVC_MICRO_MIDDLEWAREINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_micro_middlewareinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Micro_MiddlewareInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_middlewareinterface_call, 0, 0, 1)
	ZEND_ARG_INFO(0, application)
ZEND_END_ARG_INFO()

#endif /* PHALCON_MVC_MICRO_MIDDLEWAREINTERFACE_H */


#ifndef PHALCON_MVC_MODEL_H
#define PHALCON_MVC_MODEL_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model);

#endif /* PHALCON_MVC_MODEL_H */


#ifndef PHALCON_MVC_MODELINTERFACE_H
#define PHALCON_MVC_MODELINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_modelinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_ModelInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_settransaction, 0, 0, 1)
	ZEND_ARG_INFO(0, transaction)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_setconnectionservice, 0, 0, 1)
	ZEND_ARG_INFO(0, connectionService)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_setwriteconnectionservice, 0, 0, 1)
	ZEND_ARG_INFO(0, connectionService)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_setreadconnectionservice, 0, 0, 1)
	ZEND_ARG_INFO(0, connectionService)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_assign, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, columnMap)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_cloneresultmap, 0, 0, 3)
	ZEND_ARG_INFO(0, base)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, columnMap)
	ZEND_ARG_INFO(0, dirtyState)
	ZEND_ARG_INFO(0, keepSnapshots)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_cloneresult, 0, 0, 2)
	ZEND_ARG_INFO(0, base)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, dirtyState)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_cloneresultmaphydrate, 0, 0, 3)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, columnMap)
	ZEND_ARG_INFO(0, hydrationMode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_find, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_findfirst, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_query, 0, 0, 0)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_count, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_sum, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_maximum, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_minimum, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_average, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_fireevent, 0, 0, 1)
	ZEND_ARG_INFO(0, eventName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_fireeventcancel, 0, 0, 1)
	ZEND_ARG_INFO(0, eventName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_appendmessage, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_getmessages, 0, 0, 0)
	ZEND_ARG_INFO(0, filter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_save, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, whiteList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_create, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, whiteList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_update, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, whiteList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_readattribute, 0, 0, 1)
	ZEND_ARG_INFO(0, attribute)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_writeattribute, 0, 0, 2)
	ZEND_ARG_INFO(0, attribute)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_getrelated, 0, 0, 1)
	ZEND_ARG_INFO(0, alias)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

#endif /* PHALCON_MVC_MODELINTERFACE_H */


#ifndef PHALCON_MVC_MODEL_BEHAVIOR_H
#define PHALCON_MVC_MODEL_BEHAVIOR_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_behavior_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Behavior);

#endif /* PHALCON_MVC_MODEL_BEHAVIOR_H */


#ifndef PHALCON_MVC_MODEL_BEHAVIORINTERFACE_H
#define PHALCON_MVC_MODEL_BEHAVIORINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_behaviorinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_BehaviorInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_behaviorinterface_notify, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_behaviorinterface_missingmethod, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

#endif /* PHALCON_MVC_MODEL_BEHAVIORINTERFACE_H */


#ifndef PHALCON_MVC_MODEL_BEHAVIOR_SOFTDELETE_H
#define PHALCON_MVC_MODEL_BEHAVIOR_SOFTDELETE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_behavior_softdelete_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Behavior_SoftDelete);

#endif /* PHALCON_MVC_MODEL_BEHAVIOR_SOFTDELETE_H */


#ifndef PHALCON_MVC_MODEL_BEHAVIOR_TIMESTAMPABLE_H
#define PHALCON_MVC_MODEL_BEHAVIOR_TIMESTAMPABLE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_behavior_timestampable_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Behavior_Timestampable);

#endif /* PHALCON_MVC_MODEL_BEHAVIOR_TIMESTAMPABLE_H */


#ifndef PHALCON_MVC_MODEL_CRITERIA_H
#define PHALCON_MVC_MODEL_CRITERIA_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_criteria_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Criteria);

#endif /* PHALCON_MVC_MODEL_CRITERIA_H */


#ifndef PHALCON_MVC_MODEL_CRITERIAINTERFACE_H
#define PHALCON_MVC_MODEL_CRITERIAINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_criteriainterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_CriteriaInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_setmodelname, 0, 0, 1)
	ZEND_ARG_INFO(0, modelName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_bind, 0, 0, 1)
	ZEND_ARG_INFO(0, bindParams)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_bindtypes, 0, 0, 1)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_where, 0, 0, 1)
	ZEND_ARG_INFO(0, conditions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_conditions, 0, 0, 1)
	ZEND_ARG_INFO(0, conditions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_orderby, 0, 0, 1)
	ZEND_ARG_INFO(0, orderColumns)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_limit, 0, 0, 1)
	ZEND_ARG_INFO(0, limit)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_forupdate, 0, 0, 0)
	ZEND_ARG_INFO(0, forUpdate)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_sharedlock, 0, 0, 0)
	ZEND_ARG_INFO(0, sharedLock)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_andwhere, 0, 0, 1)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_orwhere, 0, 0, 1)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_betweenwhere, 0, 0, 3)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_INFO(0, minimum)
	ZEND_ARG_INFO(0, maximum)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_notbetweenwhere, 0, 0, 3)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_INFO(0, minimum)
	ZEND_ARG_INFO(0, maximum)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_inwhere, 0, 0, 2)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_INFO(0, values)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_notinwhere, 0, 0, 2)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_INFO(0, values)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_frominput, 0, 0, 3)
	ZEND_ARG_INFO(0, dependencyInjector)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_columns, 0, 0, 1)
	ZEND_ARG_INFO(0, columns)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_join, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, alias)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

#endif /* PHALCON_MVC_MODEL_CRITERIAINTERFACE_H */


#ifndef PHALCON_MVC_MODEL_EXCEPTION_H
#define PHALCON_MVC_MODEL_EXCEPTION_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Exception);

#endif /* PHALCON_MVC_MODEL_EXCEPTION_H */


#ifndef PHALCON_MVC_MODEL_MANAGER_H
#define PHALCON_MVC_MODEL_MANAGER_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_manager_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Manager);

#endif /* PHALCON_MVC_MODEL_MANAGER_H */


#ifndef PHALCON_MVC_MODEL_MANAGERINTERFACE_H
#define PHALCON_MVC_MODEL_MANAGERINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_managerinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_ManagerInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_initialize, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_isinitialized, 0, 0, 1)
	ZEND_ARG_INFO(0, modelName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_load, 0, 0, 2)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, newInstance)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_addhasone, 0, 0, 4)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, referencedModel)
	ZEND_ARG_INFO(0, referencedFields)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_addbelongsto, 0, 0, 4)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, referencedModel)
	ZEND_ARG_INFO(0, referencedFields)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_addhasmany, 0, 0, 4)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, referencedModel)
	ZEND_ARG_INFO(0, referencedFields)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_existsbelongsto, 0, 0, 2)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, modelRelation)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_existshasmany, 0, 0, 2)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, modelRelation)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_existshasone, 0, 0, 2)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, modelRelation)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_getbelongstorecords, 0, 0, 4)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, modelRelation)
	ZEND_ARG_INFO(0, record)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_gethasmanyrecords, 0, 0, 4)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, modelRelation)
	ZEND_ARG_INFO(0, record)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_gethasonerecords, 0, 0, 4)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, modelRelation)
	ZEND_ARG_INFO(0, record)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_getbelongsto, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_gethasmany, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_gethasone, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_gethasoneandhasmany, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_getrelations, 0, 0, 1)
	ZEND_ARG_INFO(0, modelName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_getrelationsbetween, 0, 0, 2)
	ZEND_ARG_INFO(0, first)
	ZEND_ARG_INFO(0, second)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_createquery, 0, 0, 1)
	ZEND_ARG_INFO(0, phql)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_executequery, 0, 0, 1)
	ZEND_ARG_INFO(0, phql)
	ZEND_ARG_INFO(0, placeholders)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_createbuilder, 0, 0, 0)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_addbehavior, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, behavior)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_notifyevent, 0, 0, 2)
	ZEND_ARG_INFO(0, eventName)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_missingmethod, 0, 0, 3)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, eventName)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

#endif /* PHALCON_MVC_MODEL_MANAGERINTERFACE_H */


#ifndef PHALCON_MVC_MODEL_MESSAGE_H
#define PHALCON_MVC_MODEL_MESSAGE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_message_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Message);

#endif /* PHALCON_MVC_MODEL_MESSAGE_H */


#ifndef PHALCON_MVC_MODEL_MESSAGEINTERFACE_H
#define PHALCON_MVC_MODEL_MESSAGEINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_messageinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_MessageInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_messageinterface_settype, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_messageinterface_setmessage, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_messageinterface_setfield, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

#endif /* PHALCON_MVC_MODEL_MESSAGEINTERFACE_H */


#ifndef PHALCON_MVC_MODEL_METADATA_H
#define PHALCON_MVC_MODEL_METADATA_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_metadata_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_MetaData);

#define PHALCON_MVC_MODEL_METADATA_MODELS_ATTRIBUTES                   0
#define PHALCON_MVC_MODEL_METADATA_MODELS_PRIMARY_KEY                  1
#define PHALCON_MVC_MODEL_METADATA_MODELS_NON_PRIMARY_KEY              2
#define PHALCON_MVC_MODEL_METADATA_MODELS_NOT_NULL                     3
#define PHALCON_MVC_MODEL_METADATA_MODELS_DATA_TYPES                   4
#define PHALCON_MVC_MODEL_METADATA_MODELS_DATA_TYPES_NUMERIC           5
#define PHALCON_MVC_MODEL_METADATA_MODELS_DATE_AT                      6
#define PHALCON_MVC_MODEL_METADATA_MODELS_DATE_IN                      7
#define PHALCON_MVC_MODEL_METADATA_MODELS_IDENTITY_COLUMN              8
#define PHALCON_MVC_MODEL_METADATA_MODELS_DATA_TYPES_BIND              9
#define PHALCON_MVC_MODEL_METADATA_MODELS_AUTOMATIC_DEFAULT_INSERT    10
#define PHALCON_MVC_MODEL_METADATA_MODELS_AUTOMATIC_DEFAULT_UPDATE    11

#define PHALCON_MVC_MODEL_METADATA_MODELS_COLUMN_MAP                   0
#define PHALCON_MVC_MODEL_METADATA_MODELS_REVERSE_COLUMN_MAP           1

#endif /* PHALCON_MVC_MODEL_METADATA_H */


#ifndef PHALCON_MVC_MODEL_METADADTAINTERFACE_H
#define PHALCON_MVC_MODEL_METADADTAINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_metadatainterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_MetaDataInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_setstrategy, 0, 0, 1)
	ZEND_ARG_INFO(0, strategy)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_readmetadata, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_readmetadataindex, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_writemetadataindex, 0, 0, 4)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, replace)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_readcolumnmap, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_readcolumnmapindex, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getattributes, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getprimarykeyattributes, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getnonprimarykeyattributes, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getnotnullattributes, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getdatatypes, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getdatatypesnumeric, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getidentityfield, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getbindtypes, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getautomaticcreateattributes, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getautomaticupdateattributes, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_setautomaticcreateattributes, 0, 0, 3)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, attributes)
	ZEND_ARG_INFO(0, replace)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_setautomaticupdateattributes, 0, 0, 3)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, attributes)
	ZEND_ARG_INFO(0, replace)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getcolumnmap, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getreversecolumnmap, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_hasattribute, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, attribute)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_read, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_write, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_reset, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_isempty, 0, 0, 0)
ZEND_END_ARG_INFO()

#endif /* PHALCON_MVC_MODEL_METADADTAINTERFACE_H */


#ifndef PHALCON_MVC_MODEL_METADATA_APC_H
#define PHALCON_MVC_MODEL_METADATA_APC_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_metadata_apc_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Apc);

#endif /* PHALCON_MVC_MODEL_METADATA_APC_H */


#ifndef PHALCON_MVC_MODEL_METADATA_FILES_H
#define PHALCON_MVC_MODEL_METADATA_FILES_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_metadata_files_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Files);

#endif /* PHALCON_MVC_MODEL_METADATA_FILES_H */

<<<<<<< HEAD
=======
PHALCON_INIT_FUNCS(phalcon_mvc_model_method_entry){
	PHP_ME(Phalcon_Mvc_Model, __construct, arginfo_phalcon_mvc_model___construct, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Mvc_Model, setDI, arginfo_phalcon_mvc_model_setdi, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, getDI, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, setEventsManager, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model, getEventsManager, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model, getModelsMetaData, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, getModelsManager, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, setTransaction, arginfo_phalcon_mvc_model_settransaction, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, setSource, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model, getSource, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, setSchema, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model, getSchema, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, setConnectionService, arginfo_phalcon_mvc_model_setconnectionservice, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, setReadConnectionService, arginfo_phalcon_mvc_model_setreadconnectionservice, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, setWriteConnectionService, arginfo_phalcon_mvc_model_setwriteconnectionservice, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, getReadConnectionService, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, getWriteConnectionService, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, setDirtyState, arginfo_phalcon_mvc_model_setdirtystate, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, getDirtyState, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, getReadConnection, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, getWriteConnection, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, assign, arginfo_phalcon_mvc_model_assign, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, cloneResultMap, arginfo_phalcon_mvc_model_cloneresultmap, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Mvc_Model, cloneResultMapHydrate, arginfo_phalcon_mvc_model_cloneresultmaphydrate, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Mvc_Model, cloneResult, arginfo_phalcon_mvc_model_cloneresult, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Mvc_Model, find, arginfo_phalcon_mvc_model_find, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Mvc_Model, findFirst, arginfo_phalcon_mvc_model_findfirst, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Mvc_Model, query, arginfo_phalcon_mvc_model_query, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Mvc_Model, _exists, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model, _groupResult, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Mvc_Model, count, arginfo_phalcon_mvc_model_count, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Mvc_Model, sum, arginfo_phalcon_mvc_model_sum, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Mvc_Model, maximum, arginfo_phalcon_mvc_model_maximum, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Mvc_Model, minimum, arginfo_phalcon_mvc_model_minimum, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Mvc_Model, average, arginfo_phalcon_mvc_model_average, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Mvc_Model, fireEvent, arginfo_phalcon_mvc_model_fireevent, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, fireEventCancel, arginfo_phalcon_mvc_model_fireeventcancel, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, _cancelOperation, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model, appendMessage, arginfo_phalcon_mvc_model_appendmessage, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, validate, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model, validationHasFailed, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, getMessages, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, _checkForeignKeysRestrict, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model, _checkForeignKeysReverseRestrict, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model, _checkForeignKeysReverseCascade, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model, _preSave, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model, _postSave, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model, _doLowInsert, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model, _doLowUpdate, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model, _preSaveRelatedRecords, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model, _postSaveRelatedRecords, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model, save, arginfo_phalcon_mvc_model_save, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, create, arginfo_phalcon_mvc_model_create, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, update, arginfo_phalcon_mvc_model_update, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, delete, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, getOperationMade, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, refresh, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, skipOperation, arginfo_phalcon_mvc_model_skipoperation, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, readAttribute, arginfo_phalcon_mvc_model_readattribute, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, writeAttribute, arginfo_phalcon_mvc_model_writeattribute, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, skipAttributes, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model, skipAttributesOnCreate, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model, skipAttributesOnUpdate, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model, hasOne, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, belongsTo, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, hasMany, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, hasManyToMany, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, addBehavior, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, keepSnapshots, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model, setSnapshotData, arginfo_phalcon_mvc_model_setsnapshotdata, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, hasSnapshotData, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, getSnapshotData, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, hasChanged, arginfo_phalcon_mvc_model_haschanged, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, getChangedFields, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, useDynamicUpdate, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model, getRelated, arginfo_phalcon_mvc_model_getrelated, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, _getRelatedRecords, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model, __call, arginfo_phalcon_mvc_model___call, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, __callStatic, arginfo_phalcon_mvc_model___callstatic, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Mvc_Model, __set, arginfo_phalcon_mvc_model___set, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, __get, arginfo_phalcon_mvc_model___get, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, __isset, arginfo_phalcon_mvc_model___isset, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, serialize, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, unserialize, arginfo_phalcon_mvc_model_unserialize, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, dump, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, toArray, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, setup, arginfo_phalcon_mvc_model_setup, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_FE_END
};
>>>>>>> master

#ifndef PHALCON_MVC_MODEL_METADATA_MEMORY_H
#define PHALCON_MVC_MODEL_METADATA_MEMORY_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_metadata_memory_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Memory);

#endif /* PHALCON_MVC_MODEL_METADATA_MEMORY_H */


#ifndef PHALCON_MVC_MODEL_METADATA_XCACHE_H
#define PHALCON_MVC_MODEL_METADATA_XCACHE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_metadata_xcache_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Xcache);

#endif /* PHALCON_MVC_MODEL_METADATA_XCACHE_H */


#ifndef PHALCON_MVC_MODEL_METADATA_SESSION_H
#define PHALCON_MVC_MODEL_METADATA_SESSION_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_metadata_session_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Session);

#endif /* PHALCON_MVC_MODEL_METADATA_SESSION_H */


#ifndef PHALCON_MVC_MODEL_METADATA_STRATEGY_ANNOTATIONS_H
#define PHALCON_MVC_MODEL_METADATA_STRATEGY_ANNOTATIONS_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_metadata_strategy_annotations_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Strategy_Annotations);

#endif /* PHALCON_MVC_MODEL_METADATA_STRATEGY_ANNOTATIONS_H */


#ifndef PHALCON_MVC_MODEL_METADATA_STRATEGY_INTROSPECTION_H
#define PHALCON_MVC_MODEL_METADATA_STRATEGY_INTROSPECTION_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_metadata_strategy_introspection_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Strategy_Introspection);

#endif /* PHALCON_MVC_MODEL_METADATA_STRATEGY_INTROSPECTION_H */


#ifndef PHALCON_MVC_MODEL_QUERY_H
#define PHALCON_MVC_MODEL_QUERY_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_query_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Query);

#endif /* PHALCON_MVC_MODEL_QUERY_H */


#ifndef PHALCON_MVC_MODEL_QUERYINTERFACE_H
#define PHALCON_MVC_MODEL_QUERYINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_queryinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_QueryInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_queryinterface_execute, 0, 0, 0)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

#endif /* PHALCON_MVC_MODEL_QUERYINTERFACE_H */


#ifndef PHALCON_MVC_QUERY_BUILDER_H
#define PHALCON_MVC_QUERY_BUILDER_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_query_builder_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Query_Builder);

#endif /* PHALCON_MVC_QUERY_BUILDER_H */


#ifndef PHALCON_MVC_MODEL_QUERY_BUILDERINTERFACE_H
#define PHALCON_MVC_MODEL_QUERY_BUILDERINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_query_builderinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Query_BuilderInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_distinct, 0, 0, 1)
	ZEND_ARG_INFO(0, distinct)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_columns, 0, 0, 1)
	ZEND_ARG_INFO(0, columns)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_from, 0, 0, 1)
	ZEND_ARG_INFO(0, models)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_addfrom, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_join, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_innerjoin, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_leftjoin, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_rightjoin, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_where, 0, 0, 1)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_andwhere, 0, 0, 1)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_orwhere, 0, 0, 1)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_betweenwhere, 0, 0, 3)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_INFO(0, minimum)
	ZEND_ARG_INFO(0, maximum)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_notbetweenwhere, 0, 0, 3)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_INFO(0, minimum)
	ZEND_ARG_INFO(0, maximum)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_inwhere, 0, 0, 2)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_INFO(0, values)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_notinwhere, 0, 0, 2)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_INFO(0, values)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_orderby, 0, 0, 1)
	ZEND_ARG_INFO(0, orderBy)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_having, 0, 0, 1)
	ZEND_ARG_INFO(0, having)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_limit, 0, 0, 1)
	ZEND_ARG_INFO(0, limit)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_groupby, 0, 0, 1)
	ZEND_ARG_INFO(0, group)
ZEND_END_ARG_INFO()

#endif /* PHALCON_MVC_MODEL_QUERY_BUILDERINTERFACE_H */


#ifndef PHALCON_MVC_MODEL_QUERY_LANG_H
#define PHALCON_MVC_MODEL_QUERY_LANG_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_query_lang_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Query_Lang);

#endif /* PHALCON_MVC_MODEL_QUERY_LANG_H */


#ifndef PHALCON_MVC_MODEL_QUERY_STATUS_H
#define PHALCON_MVC_MODEL_QUERY_STATUS_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_query_status_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Query_Status);

#endif /* PHALCON_MVC_MODEL_QUERY_STATUS_H */


#ifndef PHALCON_MVC_MODEL_QUERY_STATUSINTERFACE_H
#define PHALCON_MVC_MODEL_QUERY_STATUSINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_query_statusinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Query_StatusInterface);

#endif /* PHALCON_MVC_MODEL_QUERY_STATUSINTERFACE_H */


#ifndef PHALCON_MVC_MODEL_RELATION_H
#define PHALCON_MVC_MODEL_RELATION_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_relation_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Relation);

#endif /* PHALCON_MVC_MODEL_RELATION_H */


#ifndef PHALCON_MVC_MODEL_RELATIONINTERFACE_H
#define PHALCON_MVC_MODEL_RELATIONINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_relationinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_RelationInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_relationinterface_setintermediaterelation, 0, 0, 3)
	ZEND_ARG_INFO(0, intermediateFields)
	ZEND_ARG_INFO(0, intermediateModel)
	ZEND_ARG_INFO(0, intermediateReferencedFields)
ZEND_END_ARG_INFO()

#endif /* PHALCON_MVC_MODEL_RELATIONINTERFACE_H */


#ifndef PHALCON_MVC_MODEL_RESULTINTERFACE_H
#define PHALCON_MVC_MODEL_RESULTINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_resultinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_ResultInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultinterface_setdirtystate, 0, 0, 1)
	ZEND_ARG_INFO(0, dirtyState)
ZEND_END_ARG_INFO()

#endif /* PHALCON_MVC_MODEL_RESULTINTERFACE_H */


#ifndef PHALCON_MVC_MODEL_RESULTSET_H
#define PHALCON_MVC_MODEL_RESULTSET_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_resultset_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Resultset);

#define PHALCON_MVC_MODEL_RESULTSET_TYPE_FULL       0
#define PHALCON_MVC_MODEL_RESULTSET_TYPE_PARTIAL    1

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultset_sethydratemode, 0, 0, 1)
	ZEND_ARG_INFO(0, hydrateMode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultset_delete, 0, 0, 0)
	ZEND_ARG_INFO(0, conditionCallback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultset_filter, 0, 0, 1)
	ZEND_ARG_INFO(0, filter)
ZEND_END_ARG_INFO()

#endif /* PHALCON_MVC_MODEL_RESULTSET_H */


#ifndef PHALCON_MVC_MODEL_RESULTSETINTERFACE_H
#define PHALCON_MVC_MODEL_RESULTSETINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_resultsetinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_ResultsetInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultsetinterface_setisfresh, 0, 0, 1)
	ZEND_ARG_INFO(0, isFresh)
ZEND_END_ARG_INFO()

#endif /* PHALCON_MVC_MODEL_RESULTSETINTERFACE_H */


#ifndef PHALCON_MVC_MODEL_RESULTSET_COMPLEX_H
#define PHALCON_MVC_MODEL_RESULTSET_COMPLEX_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_resultset_complex_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Resultset_Complex);

#endif /* PHALCON_MVC_MODEL_RESULTSET_COMPLEX_H */


#ifndef PHALCON_MVC_MODEL_RESULTSET_SIMPLE_H
#define PHALCON_MVC_MODEL_RESULTSET_SIMPLE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_resultset_simple_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Resultset_Simple);

#endif /* PHALCON_MVC_MODEL_RESULTSET_SIMPLE_H */


#ifndef PHALCON_MVC_MODEL_ROW_H
#define PHALCON_MVC_MODEL_ROW_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_row_ce;

<<<<<<< HEAD
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Row);
=======
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_dispatcher_setcontrollername, 0, 0, 1)
	ZEND_ARG_INFO(0, controllerName)
	ZEND_ARG_INFO(0, isExact)
ZEND_END_ARG_INFO()
>>>>>>> master

#endif /* PHALCON_MVC_MODEL_ROW_H */


#ifndef PHALCON_MVC_MODEL_TRANSACTION_H
#define PHALCON_MVC_MODEL_TRANSACTION_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_transaction_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Transaction);

#endif /* PHALCON_MVC_MODEL_TRANSACTION_H */


#ifndef PHALCON_MVC_MODEL_TRANSACTIONINTERFACE_H
#define PHALCON_MVC_MODEL_TRANSACTIONINTERFACE_H

<<<<<<< HEAD
#include "php_phalcon.h"
=======
static PHP_METHOD(Phalcon_Mvc_Model_Row, setDirtyState);
static PHP_METHOD(Phalcon_Mvc_Model_Row, offsetExists);
static PHP_METHOD(Phalcon_Mvc_Model_Row, offsetGet);
static PHP_METHOD(Phalcon_Mvc_Model_Row, offsetSet);
static PHP_METHOD(Phalcon_Mvc_Model_Row, offsetUnset);
static PHP_METHOD(Phalcon_Mvc_Model_Row, toArray);
>>>>>>> master

zend_class_entry *phalcon_mvc_model_transactioninterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_TransactionInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transactioninterface_settransactionmanager, 0, 0, 1)
	ZEND_ARG_INFO(0, manager)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transactioninterface_rollback, 0, 0, 0)
	ZEND_ARG_INFO(0, rollbackMessage)
	ZEND_ARG_INFO(0, rollbackRecord)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transactioninterface_setisnewtransaction, 0, 0, 1)
	ZEND_ARG_INFO(0, isNew)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transactioninterface_setrollbackonabort, 0, 0, 1)
	ZEND_ARG_INFO(0, rollbackOnAbort)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transactioninterface_setrollbackedrecord, 0, 0, 1)
	ZEND_ARG_INFO(0, record)
ZEND_END_ARG_INFO()

<<<<<<< HEAD
#endif /* PHALCON_MVC_MODEL_TRANSACTIONINTERFACE_H */
=======
PHALCON_INIT_FUNCS(phalcon_mvc_model_row_method_entry){
	PHP_ME(Phalcon_Mvc_Model_Row, setDirtyState, arginfo_phalcon_mvc_model_row_setdirtystate, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Row, offsetExists, arginfo_phalcon_mvc_model_row_offsetexists, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Row, offsetGet, arginfo_phalcon_mvc_model_row_offsetget, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Row, offsetSet, arginfo_phalcon_mvc_model_row_offsetset, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Row, offsetUnset, arginfo_phalcon_mvc_model_row_offsetunset, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Row, toArray, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};
>>>>>>> master


#ifndef PHALCON_MVC_MODEL_TRANSACTION_EXCEPTION_H
#define PHALCON_MVC_MODEL_TRANSACTION_EXCEPTION_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_transaction_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Transaction_Exception);

#endif /* PHALCON_MVC_MODEL_TRANSACTION_EXCEPTION_H */


#ifndef PHALCON_MVC_MODEL_TRANSACTION_FAILED_H
#define PHALCON_MVC_MODEL_TRANSACTION_FAILED_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_transaction_failed_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Transaction_Failed);

#endif /* PHALCON_MVC_MODEL_TRANSACTION_FAILED_H */


#ifndef PHALCON_MVC_MODEL_TRANSACTION_MANAGER_H
#define PHALCON_MVC_MODEL_TRANSACTION_MANAGER_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_transaction_manager_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Transaction_Manager);

#endif /* PHALCON_MVC_MODEL_TRANSACTION_MANAGER_H */

<<<<<<< HEAD
=======
static PHP_METHOD(Phalcon_Mvc_Micro_Collection, setPrefix);
static PHP_METHOD(Phalcon_Mvc_Micro_Collection, getPrefix);
static PHP_METHOD(Phalcon_Mvc_Micro_Collection, getHandlers);
static PHP_METHOD(Phalcon_Mvc_Micro_Collection, setHandler);
static PHP_METHOD(Phalcon_Mvc_Micro_Collection, setLazy);
static PHP_METHOD(Phalcon_Mvc_Micro_Collection, isLazy);
static PHP_METHOD(Phalcon_Mvc_Micro_Collection, getHandler);
static PHP_METHOD(Phalcon_Mvc_Micro_Collection, map);
static PHP_METHOD(Phalcon_Mvc_Micro_Collection, get);
static PHP_METHOD(Phalcon_Mvc_Micro_Collection, post);
static PHP_METHOD(Phalcon_Mvc_Micro_Collection, put);
static PHP_METHOD(Phalcon_Mvc_Micro_Collection, patch);
static PHP_METHOD(Phalcon_Mvc_Micro_Collection, head);
static PHP_METHOD(Phalcon_Mvc_Micro_Collection, delete);
static PHP_METHOD(Phalcon_Mvc_Micro_Collection, options);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collection_setprefix, 0, 0, 1)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()
>>>>>>> master

#ifndef PHALCON_MVC_MODEL_TRANSACTION_MANAGERINTERFACE_H
#define PHALCON_MVC_MODEL_TRANSACTION_MANAGERINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_transaction_managerinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Transaction_ManagerInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_managerinterface_get, 0, 0, 0)
	ZEND_ARG_INFO(0, autoBegin)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_managerinterface_rollback, 0, 0, 0)
	ZEND_ARG_INFO(0, collect)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_managerinterface_notifyrollback, 0, 0, 1)
	ZEND_ARG_INFO(0, transaction)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_managerinterface_notifycommit, 0, 0, 1)
	ZEND_ARG_INFO(0, transaction)
ZEND_END_ARG_INFO()

#endif /* PHALCON_MVC_MODEL_TRANSACTION_MANAGERINTERFACE_H */


<<<<<<< HEAD
#ifndef PHALCON_MVC_MODEL_VALIDATIONFAILED_H
#define PHALCON_MVC_MODEL_VALIDATIONFAILED_H
=======
PHALCON_INIT_FUNCS(phalcon_mvc_micro_collection_method_entry){
	PHP_ME(Phalcon_Mvc_Micro_Collection, setPrefix, arginfo_phalcon_mvc_micro_collection_setprefix, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Micro_Collection, getPrefix, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Micro_Collection, getHandlers, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Micro_Collection, setHandler, arginfo_phalcon_mvc_micro_collection_sethandler, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Micro_Collection, setLazy, arginfo_phalcon_mvc_micro_collection_setlazy, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Micro_Collection, isLazy, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Micro_Collection, getHandler, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Micro_Collection, map, arginfo_phalcon_mvc_micro_collection_map, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Micro_Collection, get, arginfo_phalcon_mvc_micro_collection_get, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Micro_Collection, post, arginfo_phalcon_mvc_micro_collection_post, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Micro_Collection, put, arginfo_phalcon_mvc_micro_collection_put, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Micro_Collection, patch, arginfo_phalcon_mvc_micro_collection_patch, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Micro_Collection, head, arginfo_phalcon_mvc_micro_collection_head, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Micro_Collection, delete, arginfo_phalcon_mvc_micro_collection_delete, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Micro_Collection, options, arginfo_phalcon_mvc_micro_collection_options, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};
>>>>>>> master

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_validationfailed_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_ValidationFailed);

#endif /* PHALCON_MVC_MODEL_VALIDATIONFAILED_H */


#ifndef PHALCON_MVC_MODEL_VALIDATOR_H
#define PHALCON_MVC_MODEL_VALIDATOR_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_validator_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Validator);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_validator___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

#endif /* PHALCON_MVC_MODEL_VALIDATOR_H */


#ifndef PHALCON_MVC_MODEL_VALIDATORINTERFACE_H
#define PHALCON_MVC_MODEL_VALIDATORINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_validatorinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_ValidatorInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_validatorinterface_validate, 0, 0, 1)
	ZEND_ARG_INFO(0, record)
ZEND_END_ARG_INFO()

#endif /* PHALCON_MVC_MODEL_VALIDATORINTERFACE_H */


#ifndef PHALCON_MVC_MODEL_VALIDATOR_EMAIL_H
#define PHALCON_MVC_MODEL_VALIDATOR_EMAIL_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_validator_email_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Validator_Email);

#endif /* PHALCON_MVC_MODEL_VALIDATOR_EMAIL_H */


#ifndef PHALCON_MVC_MODEL_VALIDATOR_EXCLUSIONIN_H
#define PHALCON_MVC_MODEL_VALIDATOR_EXCLUSIONIN_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_validator_exclusionin_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Validator_Exclusionin);

#endif /* PHALCON_MVC_MODEL_VALIDATOR_EXCLUSIONIN_H */


#ifndef PHALCON_MVC_MODEL_VALIDATOR_INCLUSIONIN_H
#define PHALCON_MVC_MODEL_VALIDATOR_INCLUSIONIN_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_validator_inclusionin_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Validator_Inclusionin);

#endif /* PHALCON_MVC_MODEL_VALIDATOR_INCLUSIONIN_H */


#ifndef PHALCON_MVC_MODEL_VALIDATOR_NUMERICALITY_H
#define PHALCON_MVC_MODEL_VALIDATOR_NUMERICALITY_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_validator_numericality_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Validator_Numericality);

#endif /* PHALCON_MVC_MODEL_VALIDATOR_NUMERICALITY_H */


#ifndef PHALCON_MVC_MODEL_VALIDATOR_PRESENCEOF_H
#define PHALCON_MVC_MODEL_VALIDATOR_PRESENCEOF_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_validator_presenceof_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Validator_PresenceOf);

#endif /* PHALCON_MVC_MODEL_VALIDATOR_PRESENCEOF_H */


#ifndef PHALCON_MVC_MODEL_VALIDATOR_REGEX_H
#define PHALCON_MVC_MODEL_VALIDATOR_REGEX_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_validator_regex_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Validator_Regex);

#endif /* PHALCON_MVC_MODEL_VALIDATOR_REGEX_H */


#ifndef PHALCON_MVC_MODEL_VALIDATOR_STRINGLENGTH_H
#define PHALCON_MVC_MODEL_VALIDATOR_STRINGLENGTH_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_validator_stringlength_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Validator_StringLength);

#endif /* PHALCON_MVC_MODEL_VALIDATOR_STRINGLENGTH_H */


#ifndef PHALCON_MVC_MODEL_VALIDATOR_UNIQUENESS_H
#define PHALCON_MVC_MODEL_VALIDATOR_UNIQUENESS_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_validator_uniqueness_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Validator_Uniqueness);

#endif /* PHALCON_MVC_MODEL_VALIDATOR_UNIQUENESS_H */


#ifndef PHALCON_MVC_MODEL_VALIDATOR_URL_H
#define PHALCON_MVC_MODEL_VALIDATOR_URL_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_validator_url_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Validator_Url);

#endif /* PHALCON_MVC_MODEL_VALIDATOR_URL_H */


#ifndef PHALCON_MVC_MODULEDEFINITIONINTERFACE_H
#define PHALCON_MVC_MODULEDEFINITIONINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_moduledefinitioninterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_ModuleDefinitionInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_moduledefinitioninterface_registerservices, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

#endif /* PHALCON_MVC_MODULEDEFINITIONINTERFACE_H */


#ifndef PHALCON_MVC_ROUTER_H
#define PHALCON_MVC_ROUTER_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_router_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Router);

#endif /* PHALCON_MVC_ROUTER_H */


#ifndef PHALCON_MVC_ROUTERINTERFACE_H
#define PHALCON_MVC_ROUTERINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_routerinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_RouterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_setdefaultmodule, 0, 0, 1)
	ZEND_ARG_INFO(0, moduleName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_setdefaultcontroller, 0, 0, 1)
	ZEND_ARG_INFO(0, controllerName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_setdefaultaction, 0, 0, 1)
	ZEND_ARG_INFO(0, actionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_setdefaults, 0, 0, 1)
	ZEND_ARG_INFO(0, defaults)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_handle, 0, 0, 0)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_add, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
	ZEND_ARG_INFO(0, httpMethods)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_addget, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_addpost, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_addput, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_adddelete, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_addoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_addpatch, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_addhead, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_getroutebyid, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_getroutebyname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

#endif /* PHALCON_MVC_ROUTERINTERFACE_H */


#ifndef PHALCON_MVC_ROUTER_ANNOTATIONS_H
#define PHALCON_MVC_ROUTER_ANNOTATIONS_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_router_annotations_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Router_Annotations);

#endif /* PHALCON_MVC_ROUTER_ANNOTATIONS_H */


#ifndef PHALCON_MVC_ROUTER_EXCEPTION_H
#define PHALCON_MVC_ROUTER_EXCEPTION_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_router_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Router_Exception);

#endif /* PHALCON_MVC_ROUTER_EXCEPTION_H */


#ifndef PHALCON_MVC_ROUTER_GROUP_H
#define PHALCON_MVC_ROUTER_GROUP_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_router_group_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Router_Group);

#endif /* PHALCON_MVC_ROUTER_GROUP_H */


#ifndef PHALCON_MVC_ROUTER_ROUTE_H
#define PHALCON_MVC_ROUTER_ROUTE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_router_route_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Router_Route);

#endif /* PHALCON_MVC_ROUTER_ROUTE_H */


#ifndef PHALCON_MVC_ROUTER_ROUTEINTERFACE_H
#define PHALCON_MVC_ROUTER_ROUTEINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_router_routeinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Router_RouteInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_routeinterface_compilepattern, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_routeinterface_via, 0, 0, 1)
	ZEND_ARG_INFO(0, httpMethods)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_routeinterface_reconfigure, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_routeinterface_setname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_routeinterface_sethttpmethods, 0, 0, 1)
	ZEND_ARG_INFO(0, httpMethods)
ZEND_END_ARG_INFO()

#endif /* PHALCON_MVC_ROUTER_ROUTEINTERFACE_H */


#ifndef PHALCON_MVC_URL_H
#define PHALCON_MVC_URL_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_url_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Url);

#endif /* PHALCON_MVC_URL_H */


#ifndef PHALCON_MVC_URLINTERFACE_H
#define PHALCON_MVC_URLINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_urlinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_UrlInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_urlinterface_setbaseuri, 0, 0, 1)
	ZEND_ARG_INFO(0, baseUri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_urlinterface_setbasepath, 0, 0, 1)
	ZEND_ARG_INFO(0, basePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_urlinterface_get, 0, 0, 0)
	ZEND_ARG_INFO(0, uri)
	ZEND_ARG_INFO(0, args)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_urlinterface_path, 0, 0, 0)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

#endif /* PHALCON_MVC_URLINTERFACE_H */


#ifndef PHALCON_MVC_URL_EXCEPTION_H
#define PHALCON_MVC_URL_EXCEPTION_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_url_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Url_Exception);

#endif /* PHALCON_MVC_URL_EXCEPTION_H */


#ifndef PHALCON_MVC_USER_COMPONENT
#define PHALCON_MVC_USER_COMPONENT

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_user_component_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_User_Component);

#endif /* PHALCON_MVC_USER_COMPONENT */


#ifndef PHALCON_MVC_USER_MODULE_H
#define PHALCON_MVC_USER_MODULE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_user_module_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_User_Module);

#endif /* PHALCON_MVC_USER_MODULE_H */


#ifndef PHALCON_MVC_USER_PLUGIN_H
#define PHALCON_MVC_USER_PLUGIN_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_user_plugin_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_User_Plugin);

#endif /* PHALCON_MVC_USER_PLUGIN_H */


#ifndef PHALCON_MVC_VIEW_H
#define PHALCON_MVC_VIEW_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_view_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_View);

#endif /* PHALCON_MVC_VIEW_H */


#ifndef PHALCON_MVC_VIEWINTERFACE_H
#define PHALCON_MVC_VIEWINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_viewinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_ViewInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_setviewsdir, 0, 0, 1)
	ZEND_ARG_INFO(0, viewsDir)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_setlayoutsdir, 0, 0, 1)
	ZEND_ARG_INFO(0, layoutsDir)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_setpartialsdir, 0, 0, 1)
	ZEND_ARG_INFO(0, partialsDir)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_setbasepath, 0, 0, 1)
	ZEND_ARG_INFO(0, basePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_setrenderlevel, 0, 0, 1)
	ZEND_ARG_INFO(0, level)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_setmainview, 0, 0, 1)
	ZEND_ARG_INFO(0, viewPath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_setlayout, 0, 0, 1)
	ZEND_ARG_INFO(0, layout)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_settemplatebefore, 0, 0, 1)
	ZEND_ARG_INFO(0, templateBefore)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_settemplateafter, 0, 0, 1)
	ZEND_ARG_INFO(0, templateAfter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_setparamtoview, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_setvar, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_registerengines, 0, 0, 1)
	ZEND_ARG_INFO(0, engines)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_render, 0, 0, 2)
	ZEND_ARG_INFO(0, controllerName)
	ZEND_ARG_INFO(0, actionName)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_pick, 0, 0, 1)
	ZEND_ARG_INFO(0, renderView)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_partial, 0, 0, 1)
	ZEND_ARG_INFO(0, partialPath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_cache, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_setcontent, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

#endif /* PHALCON_MVC_VIEWINTERFACE_H */


#ifndef PHALCON_MVC_VIEW_ENGINE_H
#define PHALCON_MVC_VIEW_ENGINE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_view_engine_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_View_Engine);

#endif /* PHALCON_MVC_VIEW_ENGINE_H */


#ifndef PHALCON_MVC_VIEW_ENGINEINTERFACE_H
#define PHALCON_MVC_VIEW_ENGINEINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_view_engineinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_View_EngineInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engineinterface_partial, 0, 0, 1)
	ZEND_ARG_INFO(0, partialPath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engineinterface_render, 0, 0, 2)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_INFO(0, mustClean)
ZEND_END_ARG_INFO()

#endif /* PHALCON_MVC_VIEW_ENGINEINTERFACE_H */


#ifndef PHALCON_MVC_VIEW_ENGINE_PHP_H
#define PHALCON_MVC_VIEW_ENGINE_PHP_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_view_engine_php_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_View_Engine_Php);

#endif /* PHALCON_MVC_VIEW_ENGINE_PHP_H */


#ifndef PHALCON_MVC_VIEW_ENGINE_VOLT_H
#define PHALCON_MVC_VIEW_ENGINE_VOLT_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_view_engine_volt_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_View_Engine_Volt);

#endif /* PHALCON_MVC_VIEW_ENGINE_VOLT_H */


#ifndef PHALCON_MVC_VIEW_ENGINE_VOLT_COMPILER_H
#define PHALCON_MVC_VIEW_ENGINE_VOLT_COMPILER_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_view_engine_volt_compiler_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_View_Engine_Volt_Compiler);

#endif /* PHALCON_MVC_VIEW_ENGINE_VOLT_COMPILER_H */


#ifndef PHALCON_MVC_VIEW_EXCEPTION_H
#define PHALCON_MVC_VIEW_EXCEPTION_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_view_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_View_Exception);

#endif /* PHALCON_MVC_VIEW_EXCEPTION_H */


#ifndef PHALCON_MVC_VIEW_SIMPLE_H
#define PHALCON_MVC_VIEW_SIMPLE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_view_simple_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_View_Simple);

#endif /* PHALCON_MVC_VIEW_SIMPLE_H */



#ifndef PHALCON_PAGINATOR_ADAPTERINTERFACE_H
#define PHALCON_PAGINATOR_ADAPTERINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_paginator_adapterinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Paginator_AdapterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_paginator_adapterinterface_setcurrentpage, 0, 0, 1)
	ZEND_ARG_INFO(0, page)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_paginator_adapterinterface_getcurrentpage, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_paginator_adapterinterface_getpaginate, 0, 0, 0)
ZEND_END_ARG_INFO()

#endif /* PHALCON_PAGINATOR_ADAPTERINTERFACE_H */


#ifndef PHALCON_PAGINATOR_ADAPTER_MODEL_H
#define PHALCON_PAGINATOR_ADAPTER_MODEL_H

#include "php_phalcon.h"

zend_class_entry *phalcon_paginator_adapter_model_ce;

PHALCON_INIT_CLASS(Phalcon_Paginator_Adapter_Model);

#endif /* PHALCON_PAGINATOR_ADAPTER_MODEL_H */


#ifndef PHALCON_PAGINATOR_ADAPTER_NATIVEARRAY_H
#define PHALCON_PAGINATOR_ADAPTER_NATIVEARRAY_H

#include "php_phalcon.h"

zend_class_entry *phalcon_paginator_adapter_nativearray_ce;

PHALCON_INIT_CLASS(Phalcon_Paginator_Adapter_NativeArray);

#endif /* PHALCON_PAGINATOR_ADAPTER_NATIVEARRAY_H */


#ifndef PHALCON_PAGINATOR_ADAPTER_QUERYBUILDER_H
#define PHALCON_PAGINATOR_ADAPTER_QUERYBUILDER_H

#include "php_phalcon.h"

zend_class_entry *phalcon_paginator_adapter_querybuilder_ce;

PHALCON_INIT_CLASS(Phalcon_Paginator_Adapter_QueryBuilder);

#endif /* PHALCON_PAGINATOR_ADAPTER_QUERYBUILDER_H */


#ifndef PHALCON_PAGINATOR_EXCEPTION_H
#define PHALCON_PAGINATOR_EXCEPTION_H

#include "php_phalcon.h"

zend_class_entry *phalcon_paginator_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Paginator_Exception);

#endif /* PHALCON_PAGINATOR_EXCEPTION_H */

#ifndef PSR_LOG_ABSTRACTLOGGER_H
#define PSR_LOG_ABSTRACTLOGGER_H

#include "php_phalcon.h"

zend_class_entry *psr_log_abstractlogger_ce;

PHALCON_INIT_CLASS(Psr_Log_AbstractLogger);

PHP_FUNCTION(Psr_Log_Emergency);
PHP_FUNCTION(Psr_Log_Alert);
PHP_FUNCTION(Psr_Log_Critical);
PHP_FUNCTION(Psr_Log_Error);
PHP_FUNCTION(Psr_Log_Warning);
PHP_FUNCTION(Psr_Log_Notice);
PHP_FUNCTION(Psr_Log_Info);
PHP_FUNCTION(Psr_Log_Debug);

#endif /* PSR_LOG_ABSTRACTLOGGER_H */
#ifndef PSR_LOG_INVALIDARGUMENTEXCEPTION_H
#define PSR_LOG_INVALIDARGUMENTEXCEPTION_H

#include "php_phalcon.h"

zend_class_entry *psr_log_invalidargumentexception_ce;

PHALCON_INIT_CLASS(Psr_Log_InvalidArgumentException);

#endif /* PSR_LOG_INVALIDARGUMENTEXCEPTION_H */
#ifndef PSR_LOG_LOGGERAWAREINTERFACE_H
#define PSR_LOG_LOGGERAWAREINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *psr_log_loggerawareinterface_ce;

PHALCON_INIT_CLASS(Psr_Log_LoggerAwareInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_psr_log_loggerawareinterface_setlogger, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, logger, Psr\\Log\\LoggerInterface, 0)
ZEND_END_ARG_INFO()

#endif /* PSR_LOG_LOGGERAWAREINTERFACE_H */
#ifndef PSR_LOG_LOGGERAWARETRAIT_H
#define PSR_LOG_LOGGERAWARETRAIT_H

#include "php_phalcon.h"

zend_class_entry *psr_log_loggerawaretrait_ce;

PHALCON_INIT_CLASS(Psr_Log_LoggerAwareTrait);

#endif /* PSR_LOG_LOGGERAWARETRAIT_H */
#ifndef PSR_LOG_LOGGERINTERFACE_H
#define PSR_LOG_LOGGERINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *psr_log_loggerinterface_ce;

PHALCON_INIT_CLASS(Psr_Log_LoggerInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_psr_log_loggerinterface_log, 0, 0, 2)
	ZEND_ARG_INFO(0, level)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_psr_log_loggerinterface_logspecialized, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

#endif /* PSR_LOG_LOGGERINTERFACE_H */
#ifndef PSR_LOG_LOGGERTRAIT_H
#define PSR_LOG_LOGGERTRAIT_H

#include "php_phalcon.h"

zend_class_entry *psr_log_loggertrait_ce;

PHALCON_INIT_CLASS(Psr_Log_LoggerTrait);

#endif /* PSR_LOG_LOGGERTRAIT_H */
#ifndef PSR_LOG_LOGLEVEL_H
#define PSR_LOG_LOGLEVEL_H

#include "php_phalcon.h"

#define PSR_LOG_LOGLEVEL_EMERGENCY    "emergency"
#define PSR_LOG_LOGLEVEL_ALERT        "alert"
#define PSR_LOG_LOGLEVEL_CRITICAL     "critical"
#define PSR_LOG_LOGLEVEL_ERROR        "error"
#define PSR_LOG_LOGLEVEL_WARNING      "warning"
#define PSR_LOG_LOGLEVEL_NOTICE       "notice"
#define PSR_LOG_LOGLEVEL_INFO         "info"
#define PSR_LOG_LOGLEVEL_DEBUG        "debug"

zend_class_entry *psr_log_loglevel_ce;

PHALCON_INIT_CLASS(Psr_Log_LogLevel);

#endif /* PSR_LOG_LOGLEVEL_H */
#ifndef PSR_LOG_NULLLOGGER_H
#define PSR_LOG_NULLLOGGER_H

#include "php_phalcon.h"

zend_class_entry *psr_log_nulllogger_ce;

PHALCON_INIT_CLASS(Psr_Log_NullLogger);

#endif /* PSR_LOG_NULLLOGGER_H */



#ifndef PHALCON_QUEUE_BEANSTALK_H
#define PHALCON_QUEUE_BEANSTALK_H

#include "php_phalcon.h"

zend_class_entry *phalcon_queue_beanstalk_ce;

PHALCON_INIT_CLASS(Phalcon_Queue_Beanstalk);

#endif /* PHALCON_QUEUE_BEANSTALK_H */


#ifndef PHALCON_QUEUE_BEANSTALK_JOB_H
#define PHALCON_QUEUE_BEANSTALK_JOB_H

#include "php_phalcon.h"

zend_class_entry *phalcon_queue_beanstalk_job_ce;

PHALCON_INIT_CLASS(Phalcon_Queue_Beanstalk_Job);

#endif /* PHALCON_QUEUE_BEANSTALK_JOB_H */


#ifndef PHALCON_REGISTRY_H
#define PHALCON_REGISTRY_H

#include "php_phalcon.h"

zend_class_entry *phalcon_registry_ce;

PHALCON_INIT_CLASS(Phalcon_Registry);

#endif /* PHALCON_REGISTRY_H */



#ifndef PHALCON_SECURITY_H
#define PHALCON_SECURITY_H

#include "php_phalcon.h"

zend_class_entry *phalcon_security_ce;

#define PHALCON_SECURITY_CRYPT_DEFAULT          0
#define PHALCON_SECURITY_CRYPT_STD_DES          1
#define PHALCON_SECURITY_CRYPT_EXT_DES          2
#define PHALCON_SECURITY_CRYPT_MD5              3
#define PHALCON_SECURITY_CRYPT_BLOWFISH         4
#define PHALCON_SECURITY_CRYPT_BLOWFISH_X       5
#define PHALCON_SECURITY_CRYPT_BLOWFISH_Y       6
#define PHALCON_SECURITY_CRYPT_SHA256           7
#define PHALCON_SECURITY_CRYPT_SHA512           8

PHALCON_INIT_CLASS(Phalcon_Security);

#endif /* PHALCON_SECURITY_H */


#ifndef PHALCON_SECURITY_EXCEPTION_H
#define PHALCON_SECURITY_EXCEPTION_H

#include "php_phalcon.h"

zend_class_entry *phalcon_security_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Security_Exception);

#endif /* PHALCON_SECURITY_EXCEPTION_H */



#ifndef PHALCON_SESSION_ADAPTER_H
#define PHALCON_SESSION_ADAPTER_H

#include "php_phalcon.h"

zend_class_entry *phalcon_session_adapter_ce;

PHALCON_INIT_CLASS(Phalcon_Session_Adapter);

#endif /* PHALCON_SESSION_ADAPTER_H */


#ifndef PHALCON_SESSION_ADAPTERINTERFACE_H
#define PHALCON_SESSION_ADAPTERINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_session_adapterinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Session_AdapterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapterinterface_setoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapterinterface_destroy, 0, 0, 0)
	ZEND_ARG_INFO(0, session_id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapterinterface_get, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapterinterface_set, 0, 0, 2)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapterinterface_has, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapterinterface_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapterinterface_start, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapterinterface_getoptions, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapterinterface_getid, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapterinterface_isstarted, 0, 0, 0)
ZEND_END_ARG_INFO()

#endif /* PHALCON_SESSION_ADAPTERINTERFACE_H */


#ifndef PHALCON_SESSION_ADAPTER_FILES_H
#define PHALCON_SESSION_ADAPTER_FILES_H

#include "php_phalcon.h"

zend_class_entry *phalcon_session_adapter_files_ce;

PHALCON_INIT_CLASS(Phalcon_Session_Adapter_Files);

#endif /* PHALCON_SESSION_ADAPTER_FILES_H */


#ifndef PHALCON_SESSION_BAG_H
#define PHALCON_SESSION_BAG_H

#include "php_phalcon.h"

zend_class_entry *phalcon_session_bag_ce;

PHALCON_INIT_CLASS(Phalcon_Session_Bag);

#endif /* PHALCON_SESSION_BAG_H */


#ifndef PHALCON_SESSION_BAGINTERFACE_H
#define PHALCON_SESSION_BAGINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_session_baginterface_ce;

PHALCON_INIT_CLASS(Phalcon_Session_BagInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_baginterface_set, 0, 0, 2)
	ZEND_ARG_INFO(0, property)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_baginterface_get, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_baginterface_has, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_baginterface_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

#endif /* PHALCON_SESSION_BAGINTERFACE_H */


#ifndef PHALCON_SESSION_EXCEPTION_H
#define PHALCON_SESSION_EXCEPTION_H

#include "php_phalcon.h"

zend_class_entry *phalcon_session_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Session_Exception);

#endif /* PHALCON_SESSION_EXCEPTION_H */



#ifndef PHALCON_TAG_H
#define PHALCON_TAG_H

#include "php_phalcon.h"

void phalcon_tag_render_attributes(zval *code, zval *attributes TSRMLS_DC);

zend_class_entry *phalcon_tag_ce;

PHALCON_INIT_CLASS(Phalcon_Tag);

#endif /* PHALCON_TAG_H */


#ifndef PHALCON_TAG_EXCEPTION_H
#define PHALCON_TAG_EXCEPTION_H

#include "php_phalcon.h"

zend_class_entry *phalcon_tag_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Tag_Exception);

#endif /* PHALCON_TAG_EXCEPTION_H */


#ifndef PHALCON_TAG_SELECT_H
#define PHALCON_TAG_SELECT_H

#include "php_phalcon.h"

zend_class_entry *phalcon_tag_select_ce;

PHALCON_INIT_CLASS(Phalcon_Tag_Select);

#endif /* PHALCON_TAG_SELECT_H */



#ifndef PHALCON_TRANSLATE_ADAPTER_H
#define PHALCON_TRANSLATE_ADAPTER_H

#include "php_phalcon.h"

zend_class_entry *phalcon_translate_adapter_ce;
zend_object_handlers phalcon_translate_adapter_object_handlers;

PHALCON_INIT_CLASS(Phalcon_Translate_Adapter);

#endif /* PHALCON_TRANSLATE_ADAPTER_H */


#ifndef PHALCON_TRANSLATE_ADAPTERINTERFACE_H
#define PHALCON_TRANSLATE_ADAPTERINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_translate_adapterinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Translate_AdapterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapterinterface_query, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, placeholders)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapterinterface_exists, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

#endif /* PHALCON_TRANSLATE_ADAPTERINTERFACE_H */


#ifndef PHALCON_TRANSLATE_ADAPTER_NATIVEARRAY_H
#define PHALCON_TRANSLATE_ADAPTER_NATIVEARRAY_H

#include "php_phalcon.h"

zend_class_entry *phalcon_translate_adapter_nativearray_ce;

PHALCON_INIT_CLASS(Phalcon_Translate_Adapter_NativeArray);

#endif /* PHALCON_TRANSLATE_ADAPTER_NATIVEARRAY_H */


#ifndef PHALCON_TRANSLATE_EXCEPTION_H
#define PHALCON_TRANSLATE_EXCEPTION_H

#include "php_phalcon.h"

zend_class_entry *phalcon_translate_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Translate_Exception);

#endif /* PHALCON_TRANSLATE_EXCEPTION_H */



#ifndef PHALCON_TEXT_H
#define PHALCON_TEXT_H

#include "php_phalcon.h"

#define PHALCON_TEXT_RANDOM_ALNUM    0
#define PHALCON_TEXT_RANDOM_ALPHA    1
#define PHALCON_TEXT_RANDOM_HEXDEC   2
#define PHALCON_TEXT_RANDOM_NUMERIC  3
#define PHALCON_TEXT_RANDOM_NOZERO   4

zend_class_entry *phalcon_text_ce;

PHALCON_INIT_CLASS(Phalcon_Text);

#endif /* PHALCON_TEXT_H */



#ifndef PHALCON_VALIDATION_H
#define PHALCON_VALIDATION_H

#include "php_phalcon.h"

zend_class_entry *phalcon_validation_ce;

PHALCON_INIT_CLASS(Phalcon_Validation);

static int phalcon_validation_getdefaultmessage_helper(const zend_class_entry *ce, zval **return_value_ptr, zval *this_ptr, const char *type TSRMLS_DC);

#endif /* PHALCON_VALIDATION_H */


#ifndef PHALCON_VALIDATION_EXCEPTION_H
#define PHALCON_VALIDATION_EXCEPTION_H

#include "php_phalcon.h"

zend_class_entry *phalcon_validation_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Validation_Exception);

#endif /* PHALCON_VALIDATION_EXCEPTION_H */


#ifndef PHALCON_VALIDATION_MESSAGE_H
#define PHALCON_VALIDATION_MESSAGE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_validation_message_ce;

PHALCON_INIT_CLASS(Phalcon_Validation_Message);

static zval* phalcon_validation_message_construct_helper(zval *message, zval *field, const char *type, zval *code TSRMLS_DC) PHALCON_ATTR_NONNULL;

#endif /* PHALCON_VALIDATION_MESSAGE_H */


#ifndef PHALCON_VALIDATION_MESSAGE_GROUP_H
#define PHALCON_VALIDATION_MESSAGE_GROUP_H

#include "php_phalcon.h"

zend_class_entry *phalcon_validation_message_group_ce;

PHALCON_INIT_CLASS(Phalcon_Validation_Message_Group);

static void phalcon_validation_group_construct_helper(zval *object, zval *messages TSRMLS_DC);

#endif /* PHALCON_VALIDATION_MESSAGE_GROUP_H */


#ifndef PHALCON_VALIDATION_VALIDATOR_H
#define PHALCON_VALIDATION_VALIDATOR_H

#include "php_phalcon.h"

zend_class_entry *phalcon_validation_validator_ce;

PHALCON_INIT_CLASS(Phalcon_Validation_Validator);

static int phalcon_validation_validator_getoption_helper(const zend_class_entry *ce, zval **result, zval *this_ptr, const char *option TSRMLS_DC);

static inline int phalcon_validation_validator_isempty_helper(const zval *v)
{
	return
			Z_TYPE_P(v) == IS_NULL
		 || (Z_TYPE_P(v) == IS_STRING && !Z_STRLEN_P(v))
		 || (Z_TYPE_P(v) == IS_ARRAY && !zend_hash_num_elements(Z_ARRVAL_P(v)))
	;
}

#endif /* PHALCON_VALIDATION_VALIDATOR_H */


#ifndef PHALCON_VALIDATION_VALIDATORINTERFACE_H
#define PHALCON_VALIDATION_VALIDATORINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_validation_validatorinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Validation_ValidatorInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validatorinterface_issetoption, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validatorinterface_getoption, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validatorinterface_setoption, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validatorinterface_validate, 0, 0, 2)
	ZEND_ARG_INFO(0, validator)
	ZEND_ARG_INFO(0, attribute)
ZEND_END_ARG_INFO()

#endif /* PHALCON_VALIDATION_VALIDATORINTERFACE_H */


#ifndef PHALCON_VALIDATION_VALIDATOR_BETWEEN_H
#define PHALCON_VALIDATION_VALIDATOR_BETWEEN_H

#include "php_phalcon.h"

zend_class_entry *phalcon_validation_validator_between_ce;

PHALCON_INIT_CLASS(Phalcon_Validation_Validator_Between);

#endif /* PHALCON_VALIDATION_VALIDATOR_BETWEEN_H */


#ifndef PHALCON_VALIDATION_VALIDATOR_INCLUSION_H
#define PHALCON_VALIDATION_VALIDATOR_INCLUSION_H

#include "php_phalcon.h"

zend_class_entry *phalcon_validation_validator_confirmation_ce;

PHALCON_INIT_CLASS(Phalcon_Validation_Validator_Confirmation);

#endif /* PHALCON_VALIDATION_VALIDATOR_INCLUSION_H */


#ifndef PHALCON_VALIDATION_VALIDATOR_EMAIL_H
#define PHALCON_VALIDATION_VALIDATOR_EMAIL_H

#include "php_phalcon.h"

zend_class_entry *phalcon_validation_validator_email_ce;

PHALCON_INIT_CLASS(Phalcon_Validation_Validator_Email);

#endif /* PHALCON_VALIDATION_VALIDATOR_EMAIL_H */


#ifndef PHALCON_VALIDATION_VALIDATOR_EXCLUSIONIN_H
#define PHALCON_VALIDATION_VALIDATOR_EXCLUSIONIN_H

#include "php_phalcon.h"

zend_class_entry *phalcon_validation_validator_exclusionin_ce;

PHALCON_INIT_CLASS(Phalcon_Validation_Validator_ExclusionIn);

#endif /* PHALCON_VALIDATION_VALIDATOR_EXCLUSIONIN_H */


#ifndef PHALCON_VALIDATION_VALIDATOR_IDENTICAL_H
#define PHALCON_VALIDATION_VALIDATOR_IDENTICAL_H

#include "php_phalcon.h"

zend_class_entry *phalcon_validation_validator_identical_ce;

PHALCON_INIT_CLASS(Phalcon_Validation_Validator_Identical);

#endif /* PHALCON_VALIDATION_VALIDATOR_IDENTICAL_H */


#ifndef PHALCON_VALIDATION_VALIDATOR_INCLUSIONIN_H
#define PHALCON_VALIDATION_VALIDATOR_INCLUSIONIN_H

#include "php_phalcon.h"

zend_class_entry *phalcon_validation_validator_inclusionin_ce;

PHALCON_INIT_CLASS(Phalcon_Validation_Validator_InclusionIn);

#endif /* PHALCON_VALIDATION_VALIDATOR_INCLUSIONIN_H */


#ifndef PHALCON_VALIDATION_VALIDATOR_PRESENCEOF_H
#define PHALCON_VALIDATION_VALIDATOR_PRESENCEOF_H

#include "php_phalcon.h"

zend_class_entry *phalcon_validation_validator_presenceof_ce;

PHALCON_INIT_CLASS(Phalcon_Validation_Validator_PresenceOf);

#endif /* PHALCON_VALIDATION_VALIDATOR_PRESENCEOF_H */


#ifndef PHALCON_VALIDATION_VALIDATOR_REGEX_H
#define PHALCON_VALIDATION_VALIDATOR_REGEX_H

#include "php_phalcon.h"

zend_class_entry *phalcon_validation_validator_regex_ce;

PHALCON_INIT_CLASS(Phalcon_Validation_Validator_Regex);

#endif /* PHALCON_VALIDATION_VALIDATOR_REGEX_H */


#ifndef PHALCON_VALIDATION_VALIDATOR_STRINGLENGTH_H
#define PHALCON_VALIDATION_VALIDATOR_STRINGLENGTH_H

#include "php_phalcon.h"

<<<<<<< HEAD
zend_class_entry *phalcon_validation_validator_stringlength_ce;
=======
static PHP_METHOD(Phalcon_Events_Manager, attach);
static PHP_METHOD(Phalcon_Events_Manager, enablePriorities);
static PHP_METHOD(Phalcon_Events_Manager, arePrioritiesEnabled);
static PHP_METHOD(Phalcon_Events_Manager, collectResponses);
static PHP_METHOD(Phalcon_Events_Manager, isCollecting);
static PHP_METHOD(Phalcon_Events_Manager, getResponses);
static PHP_METHOD(Phalcon_Events_Manager, detachAll);
static PHP_METHOD(Phalcon_Events_Manager, fireQueue);
static PHP_METHOD(Phalcon_Events_Manager, fire);
static PHP_METHOD(Phalcon_Events_Manager, hasListeners);
static PHP_METHOD(Phalcon_Events_Manager, getListeners);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_manager_attach, 0, 0, 2)
	ZEND_ARG_INFO(0, eventType)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_INFO(0, priority)
ZEND_END_ARG_INFO()
>>>>>>> master

PHALCON_INIT_CLASS(Phalcon_Validation_Validator_StringLength);

#endif /* PHALCON_VALIDATION_VALIDATOR_STRINGLENGTH_H */

<<<<<<< HEAD
=======
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_manager_detachall, 0, 0, 0)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()
>>>>>>> master

#ifndef PHALCON_VALIDATION_VALIDATOR_URL_H
#define PHALCON_VALIDATION_VALIDATOR_URL_H

#include "php_phalcon.h"

zend_class_entry *phalcon_validation_validator_url_ce;

PHALCON_INIT_CLASS(Phalcon_Validation_Validator_Url);

<<<<<<< HEAD
#endif /* PHALCON_VALIDATION_VALIDATOR_URL_H */
=======
PHALCON_INIT_FUNCS(phalcon_events_manager_method_entry){
	PHP_ME(Phalcon_Events_Manager, attach, arginfo_phalcon_events_manager_attach, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Events_Manager, enablePriorities, arginfo_phalcon_events_manager_enablepriorities, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Events_Manager, arePrioritiesEnabled, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Events_Manager, collectResponses, arginfo_phalcon_events_manager_collectresponses, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Events_Manager, isCollecting, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Events_Manager, getResponses, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Events_Manager, detachAll, arginfo_phalcon_events_manager_detachall, ZEND_ACC_PUBLIC)
	PHP_MALIAS(Phalcon_Events_Manager, dettachAll, detachAll, arginfo_phalcon_events_manager_detachall, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
	PHP_ME(Phalcon_Events_Manager, fireQueue, arginfo_phalcon_events_manager_firequeue, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Events_Manager, fire, arginfo_phalcon_events_manager_fire, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Events_Manager, hasListeners, arginfo_phalcon_events_manager_haslisteners, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Events_Manager, getListeners, arginfo_phalcon_events_manager_getlisteners, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};
>>>>>>> master



#ifndef PHALCON_VERSION_H
#define PHALCON_VERSION_H

#include "php_phalcon.h"

#define PHALCON_VERSION_ALPHA      1
#define PHALCON_VERSION_BETA       2
#define PHALCON_VERSION_RC         3
#define PHALCON_VERSION_STABLE     4

zend_class_entry *phalcon_version_ce;

PHALCON_INIT_CLASS(Phalcon_Version);

#endif /* PHALCON_VERSION_H */

#endif /* PHALCON_H */
