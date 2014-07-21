/*
 * phalcon.h
 *
 *  Created on: 11 січ. 2014
 *      Author: vladimir
 */

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


#ifndef PHALCON_ANNOTATIONS_ADAPTERINTERFACE_H
#define PHALCON_ANNOTATIONS_ADAPTERINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_annotations_adapterinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Annotations_AdapterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapterinterface_read, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapterinterface_write, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

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


#ifndef PHALCON_ANNOTATIONS_ADAPTER_APC_H
#define PHALCON_ANNOTATIONS_ADAPTER_APC_H

#include "php_phalcon.h"

zend_class_entry *phalcon_annotations_adapter_apc_ce;

PHALCON_INIT_CLASS(Phalcon_Annotations_Adapter_Apc);

#endif /* PHALCON_ANNOTATIONS_ADAPTER_APC_H */


#ifndef PHALCON_ANNOTATIONS_ADAPTER_FILES_H
#define PHALCON_ANNOTATIONS_ADAPTER_FILES_H

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


#ifndef PHALCON_ASSETS_RESOURCE_H
#define PHALCON_ASSETS_RESOURCE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_assets_resource_ce;

PHALCON_INIT_CLASS(Phalcon_Assets_Resource);

#endif /* PHALCON_ASSETS_RESOURCE_H */


#ifndef PHALCON_ASSETS_RESOURCE_JS_H
#define PHALCON_ASSETS_RESOURCE_JS_H

#include "php_phalcon.h"

zend_class_entry *phalcon_assets_resource_js_ce;

PHALCON_INIT_CLASS(Phalcon_Assets_Resource_Js);

#endif /* PHALCON_ASSETS_RESOURCE_JS_H */


#ifndef PHALCON_ASSETS_RESOURCE_CSS_H
#define PHALCON_ASSETS_RESOURCE_CSS_H

#include "php_phalcon.h"

zend_class_entry *phalcon_assets_resource_css_ce;

PHALCON_INIT_CLASS(Phalcon_Assets_Resource_Css);

#endif /* PHALCON_ASSETS_RESOURCE_CSS_H */



#ifndef PHALCON_CACHE_BACKEND_H
#define PHALCON_CACHE_BACKEND_H

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


#ifndef PHALCON_CACHE_BACKEND_APC_H
#define PHALCON_CACHE_BACKEND_APC_H

#include "php_phalcon.h"

zend_class_entry *phalcon_cache_backend_apc_ce;

PHALCON_INIT_CLASS(Phalcon_Cache_Backend_Apc);

#endif /* PHALCON_CACHE_BACKEND_APC_H */


#ifndef PHALCON_CACHE_BACKEND_FILE_H
#define PHALCON_CACHE_BACKEND_FILE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_cache_backend_file_ce;

PHALCON_INIT_CLASS(Phalcon_Cache_Backend_File);

#endif /* PHALCON_CACHE_BACKEND_FILE_H */


#ifndef PHALCON_CACHE_BACKEND_LIBMEMCACHED_H
#define PHALCON_CACHE_BACKEND_LIBMEMCACHED_H

#include "php_phalcon.h"

zend_class_entry *phalcon_cache_backend_libmemcached_ce;

PHALCON_INIT_CLASS(Phalcon_Cache_Backend_Libmemcached);

#endif /* PHALCON_CACHE_BACKEND_LIBMEMCACHED_H */


#ifndef PHALCON_CACHE_BACKEND_MEMCACHE_H
#define PHALCON_CACHE_BACKEND_MEMCACHE_H

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

#endif /* PHALCON_CACHE_BACKEND_MONGO_H */


#ifndef PHALCON_CACHE_BACKEND_XCACHE_H
#define PHALCON_CACHE_BACKEND_XCACHE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_cache_backend_xcache_ce;

PHALCON_INIT_CLASS(Phalcon_Cache_Backend_Xcache);

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

#include "php_phalcon.h"

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


#ifndef PHALCON_CONFIG_ADAPTER_YAML_H
#define PHALCON_CONFIG_ADAPTER_YAML_H

#include "php_phalcon.h"

zend_class_entry *phalcon_config_adapter_yaml_ce;

PHALCON_INIT_CLASS(Phalcon_Config_Adapter_Yaml);

#endif /* PHALCON_CONFIG_ADAPTER_YAML_H */


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
	ZEND_ARG_INFO(0, fetchArg1)
	ZEND_ARG_INFO(0, fetchArg2)
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

zend_class_entry *phalcon_flash_exception_ce;

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

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_sharpen, 0, 0, 1)
	ZEND_ARG_INFO(0, amount)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_reflection, 0, 0, 0)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, opacity)
	ZEND_ARG_INFO(0, fade_in)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_watermark, 0, 0, 1)
	ZEND_ARG_INFO(0, watermark)
	ZEND_ARG_INFO(0, offset_x)
	ZEND_ARG_INFO(0, offset_y)
	ZEND_ARG_INFO(0, opacity)
ZEND_END_ARG_INFO()

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

#include "php_phalcon.h"

zend_class_entry *phalcon_image_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Image_Exception);

#endif /* PHALCON_IMAGE_EXCEPTION */



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

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_collection_document_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Collection_Document);

#endif /* PHALCON_MVC_COLLECTION_DOCUMENT_H */


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

PHALCON_INIT_CLASS(Phalcon_Mvc_Controller);

#endif /* PHALCON_MVC_CONTROLLER_H */


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

#endif /* PHALCON_MVC_DISPATCHER_H */


#ifndef PHALCON_MVC_DISPATCHERINTERFACE_H
#define PHALCON_MVC_DISPATCHERINTERFACE_H

#include "php_phalcon.h"

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

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Row);

#endif /* PHALCON_MVC_MODEL_ROW_H */


#ifndef PHALCON_MVC_MODEL_TRANSACTION_H
#define PHALCON_MVC_MODEL_TRANSACTION_H

#include "php_phalcon.h"

zend_class_entry *phalcon_mvc_model_transaction_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Transaction);

#endif /* PHALCON_MVC_MODEL_TRANSACTION_H */


#ifndef PHALCON_MVC_MODEL_TRANSACTIONINTERFACE_H
#define PHALCON_MVC_MODEL_TRANSACTIONINTERFACE_H

#include "php_phalcon.h"

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

#endif /* PHALCON_MVC_MODEL_TRANSACTIONINTERFACE_H */


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


#ifndef PHALCON_MVC_MODEL_VALIDATIONFAILED_H
#define PHALCON_MVC_MODEL_VALIDATIONFAILED_H

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
	ZEND_ARG_INFO(0, local)
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


#ifndef PHALCON_SESSION_ADAPTER_MEMCACHE_H
#define PHALCON_SESSION_ADAPTER_MEMCACHE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_session_adapter_memcache_ce;

PHALCON_INIT_CLASS(Phalcon_Session_Adapter_Memcache);

#endif /* PHALCON_SESSION_ADAPTER_MEMCACHE_H */


#ifndef PHALCON_SESSION_ADAPTER_LIBMEMCACHED_H
#define PHALCON_SESSION_ADAPTER_LIBMEMCACHED_H

#include "php_phalcon.h"

zend_class_entry *phalcon_session_adapter_libmemcached_ce;

PHALCON_INIT_CLASS(Phalcon_Session_Adapter_Libmemcached);

#endif /* PHALCON_SESSION_ADAPTER_LIBMEMCACHED_H */



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


#ifndef PHALCON_TRANSLATE_ADAPTER_GETTEXT_H
#define PHALCON_TRANSLATE_ADAPTER_GETTEXT_H

#include "php_phalcon.h"

zend_class_entry *phalcon_translate_adapter_gettext_ce;

PHALCON_INIT_CLASS(Phalcon_Translate_Adapter_Gettext);

#endif /* PHALCON_TRANSLATE_ADAPTER_GETTEXT_H */



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


#ifndef PHALCON_VALIDATION_MESSAGEINTERFACE_H
#define PHALCON_VALIDATION_MESSAGEINTERFACE_H

#include "php_phalcon.h"

zend_class_entry *phalcon_validation_messageinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Validation_MessageInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_messageinterface_settype, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_messageinterface_setcode, 0, 0, 1)
	ZEND_ARG_INFO(0, code)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_messageinterface_setmessage, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_messageinterface_setfield, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

#endif /* PHALCON_VALIDATION_MESSAGEINTERFACE_H */


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

zend_class_entry *phalcon_validation_validator_stringlength_ce;

PHALCON_INIT_CLASS(Phalcon_Validation_Validator_StringLength);

#endif /* PHALCON_VALIDATION_VALIDATOR_STRINGLENGTH_H */


#ifndef PHALCON_VALIDATION_VALIDATOR_URL_H
#define PHALCON_VALIDATION_VALIDATOR_URL_H

#include "php_phalcon.h"

zend_class_entry *phalcon_validation_validator_url_ce;

PHALCON_INIT_CLASS(Phalcon_Validation_Validator_Url);

#endif /* PHALCON_VALIDATION_VALIDATOR_URL_H */



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
