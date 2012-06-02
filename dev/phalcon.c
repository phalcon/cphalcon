
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/require.h"
#include "kernel/object.h"
#include "kernel/debug.h"
#include "kernel/assert.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/memory.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

zend_class_entry *phalcon_session_namespace_ce;
zend_class_entry *phalcon_loader_ce;
zend_class_entry *phalcon_text_ce;
zend_class_entry *phalcon_test_ce;
zend_class_entry *phalcon_router_rewrite_ce;
zend_class_entry *phalcon_router_regex_ce;
zend_class_entry *phalcon_config_exception_ce;
zend_class_entry *phalcon_config_adapter_ini_ce;
zend_class_entry *phalcon_exception_ce;
zend_class_entry *phalcon_db_ce;
zend_class_entry *phalcon_logger_ce;
zend_class_entry *phalcon_cache_exception_ce;
zend_class_entry *phalcon_cache_frontend_output_ce;
zend_class_entry *phalcon_cache_frontend_none_ce;
zend_class_entry *phalcon_cache_frontend_data_ce;
zend_class_entry *phalcon_cache_backend_memcache_ce;
zend_class_entry *phalcon_cache_backend_apc_ce;
zend_class_entry *phalcon_cache_backend_file_ce;
zend_class_entry *phalcon_acl_exception_ce;
zend_class_entry *phalcon_acl_adapter_memory_ce;
zend_class_entry *phalcon_acl_role_ce;
zend_class_entry *phalcon_acl_resource_ce;
zend_class_entry *phalcon_cache_ce;
zend_class_entry *phalcon_dispatcher_exception_ce;
zend_class_entry *phalcon_view_ce;
zend_class_entry *phalcon_view_engine_ce;
zend_class_entry *phalcon_view_exception_ce;
zend_class_entry *phalcon_view_engine_php_ce;
zend_class_entry *phalcon_view_engine_twig_ce;
zend_class_entry *phalcon_view_engine_mustache_ce;
zend_class_entry *phalcon_paginator_exception_ce;
zend_class_entry *phalcon_paginator_adapter_array_ce;
zend_class_entry *phalcon_paginator_adapter_model_ce;
zend_class_entry *phalcon_tag_exception_ce;
zend_class_entry *phalcon_tag_select_ce;
zend_class_entry *phalcon_internal_test_ce;
zend_class_entry *phalcon_internal_testparent_ce;
zend_class_entry *phalcon_internal_testtemp_ce;
zend_class_entry *phalcon_internal_testdummy_ce;
zend_class_entry *phalcon_controller_ce;
zend_class_entry *phalcon_request_file_ce;
zend_class_entry *phalcon_paginator_ce;
zend_class_entry *phalcon_utils_ce;
zend_class_entry *phalcon_dispatcher_ce;
zend_class_entry *phalcon_translate_ce;
zend_class_entry *phalcon_db_pool_ce;
zend_class_entry *phalcon_db_profiler_ce;
zend_class_entry *phalcon_db_exception_ce;
zend_class_entry *phalcon_db_reference_ce;
zend_class_entry *phalcon_db_adapter_mysql_ce;
zend_class_entry *phalcon_db_profiler_item_ce;
zend_class_entry *phalcon_db_rawvalue_ce;
zend_class_entry *phalcon_db_column_ce;
zend_class_entry *phalcon_db_index_ce;
zend_class_entry *phalcon_db_dialect_mysql_ce;
zend_class_entry *phalcon_model_validator_uniqueness_ce;
zend_class_entry *phalcon_model_validator_exclusionin_ce;
zend_class_entry *phalcon_model_validator_regex_ce;
zend_class_entry *phalcon_model_validator_inclusionin_ce;
zend_class_entry *phalcon_model_validator_numericality_ce;
zend_class_entry *phalcon_model_validator_email_ce;
zend_class_entry *phalcon_model_query_ce;
zend_class_entry *phalcon_model_exception_ce;
zend_class_entry *phalcon_model_base_ce;
zend_class_entry *phalcon_model_validator_ce;
zend_class_entry *phalcon_model_row_ce;
zend_class_entry *phalcon_model_sanitize_ce;
zend_class_entry *phalcon_model_metadata_ce;
zend_class_entry *phalcon_model_message_ce;
zend_class_entry *phalcon_model_manager_ce;
zend_class_entry *phalcon_model_metadata_memory_ce;
zend_class_entry *phalcon_model_metadata_session_ce;
zend_class_entry *phalcon_model_resultset_ce;
zend_class_entry *phalcon_tag_ce;
zend_class_entry *phalcon_response_ce;
zend_class_entry *phalcon_request_ce;
zend_class_entry *phalcon_transaction_failed_ce;
zend_class_entry *phalcon_transaction_manager_ce;
zend_class_entry *phalcon_controller_front_ce;
zend_class_entry *phalcon_session_ce;
zend_class_entry *phalcon_flash_ce;
zend_class_entry *phalcon_config_ce;
zend_class_entry *phalcon_filter_ce;
zend_class_entry *phalcon_acl_ce;
zend_class_entry *phalcon_translate_exception_ce;
zend_class_entry *phalcon_translate_adapter_array_ce;
zend_class_entry *phalcon_logger_exception_ce;
zend_class_entry *phalcon_logger_adapter_file_ce;
zend_class_entry *phalcon_logger_item_ce;
zend_class_entry *phalcon_transaction_ce;

ZEND_DECLARE_MODULE_GLOBALS(phalcon)

PHP_MINIT_FUNCTION(phalcon){

	zend_class_entry ce00, ce01, ce02, ce03, ce04, ce05, ce06, ce07, ce08, ce09;
	zend_class_entry ce10, ce11, ce12, ce13, ce14, ce15, ce16, ce17, ce18, ce19;
	zend_class_entry ce20, ce21, ce22, ce23, ce24, ce25, ce26, ce27, ce28, ce29;
	zend_class_entry ce30, ce31, ce32, ce33, ce34, ce35, ce36, ce37, ce38, ce39;
	zend_class_entry ce40, ce41, ce42, ce43, ce44, ce45, ce46, ce47, ce48, ce49;
	zend_class_entry ce50, ce51, ce52, ce53, ce54, ce55, ce56, ce57, ce58, ce59;
	zend_class_entry ce60, ce61, ce62, ce63, ce64, ce65, ce66, ce67, ce68, ce69;
	zend_class_entry ce70, ce71, ce72, ce73, ce74, ce75, ce76, ce77, ce78, ce79;
	zend_class_entry ce80, ce81, ce82, ce83, ce84, ce85, ce86, ce87, ce88, ce89;
	zend_class_entry ce90, ce91, ce92, ce93, ce94;


	if(!zend_ce_arrayaccess){
		fprintf(stderr, "Phalcon Error: Interface ArrayAccess was not found");
		return FAILURE;
	}
	if(!zend_ce_iterator){
		fprintf(stderr, "Phalcon Error: Interface Iterator was not found");
		return FAILURE;
	}
	if(!spl_ce_SeekableIterator){
		fprintf(stderr, "Phalcon Error: Interface SeekableIterator was not found");
		return FAILURE;
	}
	if(!spl_ce_Countable){
		fprintf(stderr, "Phalcon Error: Interface Countable was not found");
		return FAILURE;
	}
	if(!zend_ce_serializable){
		fprintf(stderr, "Phalcon Error: Interface Serializable was not found");
		return FAILURE;
	}

	/** Init globals */
	ZEND_INIT_MODULE_GLOBALS(phalcon, php_phalcon_init_globals, NULL);

	INIT_CLASS_ENTRY(ce00, "Phalcon_Session_Namespace", phalcon_session_namespace_functions);
	phalcon_session_namespace_ce = zend_register_internal_class(&ce00 TSRMLS_CC);
	zend_declare_property_null(phalcon_session_namespace_ce, "_name", sizeof("_name")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_session_namespace_ce, "_data", sizeof("_data")-1, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce01, "Phalcon_Loader", phalcon_loader_functions);
	phalcon_loader_ce = zend_register_internal_class(&ce01 TSRMLS_CC);
	zend_declare_property_null(phalcon_loader_ce, "_namespaces", sizeof("_namespaces")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_loader_ce, "_directories", sizeof("_directories")-1, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce02, "Phalcon_Text", phalcon_text_functions);
	phalcon_text_ce = zend_register_internal_class(&ce02 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce03, "Phalcon_Test", phalcon_test_functions);
	phalcon_test_ce = zend_register_internal_class(&ce03 TSRMLS_CC);
	zend_declare_property_null(phalcon_test_ce, "p", sizeof("p")-1, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	INIT_CLASS_ENTRY(ce04, "Phalcon_Router_Rewrite", phalcon_router_rewrite_functions);
	phalcon_router_rewrite_ce = zend_register_internal_class(&ce04 TSRMLS_CC);
	zend_declare_property_null(phalcon_router_rewrite_ce, "_controller", sizeof("_controller")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_router_rewrite_ce, "_action", sizeof("_action")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_router_rewrite_ce, "_params", sizeof("_params")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_router_rewrite_ce, "_prefix", sizeof("_prefix")-1, "", ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce05, "Phalcon_Router_Regex", phalcon_router_regex_functions);
	phalcon_router_regex_ce = zend_register_internal_class(&ce05 TSRMLS_CC);
	zend_declare_property_null(phalcon_router_regex_ce, "_controller", sizeof("_controller")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_router_regex_ce, "_action", sizeof("_action")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_router_regex_ce, "_params", sizeof("_params")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_router_regex_ce, "_baseUri", sizeof("_baseUri")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_router_regex_ce, "_routes", sizeof("_routes")-1, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce06, "Phalcon_Db", phalcon_db_functions);
	phalcon_db_ce = zend_register_internal_class(&ce06 TSRMLS_CC);
	zend_declare_property_null(phalcon_db_ce, "_descriptor", sizeof("_descriptor")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_ce, "_fetchMode", sizeof("_fetchMode")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_ce, "_autoCommit", sizeof("_autoCommit")-1, 1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_ce, "_idConnection", sizeof("_idConnection")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_ce, "_underTransaction", sizeof("_underTransaction")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_ce, "_logger", sizeof("_logger")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_ce, "_profiler", sizeof("_profiler")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_ce, "DB_ASSOC", sizeof("DB_ASSOC")-1, 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_ce, "DB_BOTH", sizeof("DB_BOTH")-1, 2 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_ce, "DB_NUM", sizeof("DB_NUM")-1, 3 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce07, "Phalcon_Logger", phalcon_logger_functions);
	phalcon_logger_ce = zend_register_internal_class(&ce07 TSRMLS_CC);
	zend_declare_property_null(phalcon_logger_ce, "_adapter", sizeof("_adapter")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_ce, "SPECIAL", sizeof("SPECIAL")-1, 9 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_ce, "CUSTOM", sizeof("CUSTOM")-1, 8 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_ce, "DEBUG", sizeof("DEBUG")-1, 7 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_ce, "INFO", sizeof("INFO")-1, 6 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_ce, "NOTICE", sizeof("NOTICE")-1, 5 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_ce, "WARNING", sizeof("WARNING")-1, 4 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_ce, "ERROR", sizeof("ERROR")-1, 3 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_ce, "ALERT", sizeof("ALERT")-1, 2 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_ce, "CRITICAL", sizeof("CRITICAL")-1, 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_ce, "EMERGENCE", sizeof("EMERGENCE")-1, 0 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce08, "Phalcon_Cache_Frontend_Output", phalcon_cache_frontend_output_functions);
	phalcon_cache_frontend_output_ce = zend_register_internal_class(&ce08 TSRMLS_CC);
	zend_declare_property_bool(phalcon_cache_frontend_output_ce, "_buffering", sizeof("_buffering")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_cache_frontend_output_ce, "_frontendOptions", sizeof("_frontendOptions")-1, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce09, "Phalcon_Cache_Frontend_None", phalcon_cache_frontend_none_functions);
	phalcon_cache_frontend_none_ce = zend_register_internal_class(&ce09 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce10, "Phalcon_Cache_Frontend_Data", phalcon_cache_frontend_data_functions);
	phalcon_cache_frontend_data_ce = zend_register_internal_class(&ce10 TSRMLS_CC);
	zend_declare_property_null(phalcon_cache_frontend_data_ce, "_frontendOptions", sizeof("_frontendOptions")-1, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce11, "Phalcon_Cache_Backend_Memcache", phalcon_cache_backend_memcache_functions);
	phalcon_cache_backend_memcache_ce = zend_register_internal_class(&ce11 TSRMLS_CC);
	zend_declare_property_null(phalcon_cache_backend_memcache_ce, "_memcache", sizeof("_memcache")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_cache_backend_memcache_ce, "_frontendObject", sizeof("_frontendObject")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_cache_backend_memcache_ce, "_backendOptions", sizeof("_backendOptions")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_cache_backend_memcache_ce, "_lastKey", sizeof("_lastKey")-1, "", ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce12, "Phalcon_Cache_Backend_Apc", phalcon_cache_backend_apc_functions);
	phalcon_cache_backend_apc_ce = zend_register_internal_class(&ce12 TSRMLS_CC);
	zend_declare_property_null(phalcon_cache_backend_apc_ce, "_frontendObject", sizeof("_frontendObject")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_cache_backend_apc_ce, "_backendOptions", sizeof("_backendOptions")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_cache_backend_apc_ce, "_lastKey", sizeof("_lastKey")-1, "", ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce13, "Phalcon_Cache_Backend_File", phalcon_cache_backend_file_functions);
	phalcon_cache_backend_file_ce = zend_register_internal_class(&ce13 TSRMLS_CC);
	zend_declare_property_null(phalcon_cache_backend_file_ce, "_frontendObject", sizeof("_frontendObject")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_cache_backend_file_ce, "_backendOptions", sizeof("_backendOptions")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_cache_backend_file_ce, "_lastKey", sizeof("_lastKey")-1, "", ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce14, "Phalcon_Acl_Adapter_Memory", phalcon_acl_adapter_memory_functions);
	phalcon_acl_adapter_memory_ce = zend_register_internal_class(&ce14 TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, "_rolesNames", sizeof("_rolesNames")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, "_roles", sizeof("_roles")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, "_resources", sizeof("_resources")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, "_access", sizeof("_access")-1, ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, "_roleInherits", sizeof("_roleInherits")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, "_resourcesNames", sizeof("_resourcesNames")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, "_accessList", sizeof("_accessList")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_long(phalcon_acl_adapter_memory_ce, "_defaultAccess", sizeof("_defaultAccess")-1, 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce15, "Phalcon_Acl_Role", phalcon_acl_role_functions);
	phalcon_acl_role_ce = zend_register_internal_class(&ce15 TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_role_ce, "_name", sizeof("_name")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_role_ce, "_description", sizeof("_description")-1, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce16, "Phalcon_Acl_Resource", phalcon_acl_resource_functions);
	phalcon_acl_resource_ce = zend_register_internal_class(&ce16 TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_resource_ce, "_name", sizeof("_name")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_resource_ce, "_description", sizeof("_description")-1, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce17, "Phalcon_Cache", phalcon_cache_functions);
	phalcon_cache_ce = zend_register_internal_class(&ce17 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce18, "Phalcon_View", phalcon_view_functions);
	phalcon_view_ce = zend_register_internal_class(&ce18 TSRMLS_CC);
	zend_declare_property_string(phalcon_view_ce, "_basePath", sizeof("_basePath")-1, "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_view_ce, "_content", sizeof("_content")-1, "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_view_ce, "_renderLevel", sizeof("_renderLevel")-1, 5, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_view_ce, "_viewParams", sizeof("_viewParams")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_view_ce, "_layoutsDir", sizeof("_layoutsDir")-1, "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_view_ce, "_templatesBefore", sizeof("_templatesBefore")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_view_ce, "_templatesAfter", sizeof("_templatesAfter")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_view_ce, "_engines", sizeof("_engines")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_view_ce, "_registeredEngines", sizeof("_registeredEngines")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_view_ce, "_mainView", sizeof("_mainView")-1, "index", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_view_ce, "_controllerName", sizeof("_controllerName")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_view_ce, "_actionName", sizeof("_actionName")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_view_ce, "_params", sizeof("_params")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_view_ce, "LEVEL_MAIN_LAYOUT", sizeof("LEVEL_MAIN_LAYOUT")-1, 5 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_view_ce, "LEVEL_AFTER_TEMPLATE", sizeof("LEVEL_AFTER_TEMPLATE")-1, 4 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_view_ce, "LEVEL_LAYOUT", sizeof("LEVEL_LAYOUT")-1, 3 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_view_ce, "LEVEL_BEFORE_TEMPLATE", sizeof("LEVEL_BEFORE_TEMPLATE")-1, 2 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_view_ce, "LEVEL_ACTION_VIEW", sizeof("LEVEL_ACTION_VIEW")-1, 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_view_ce, "LEVEL_NO_RENDER", sizeof("LEVEL_NO_RENDER")-1, 0 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce19, "Phalcon_View_Engine", phalcon_view_engine_functions);
	phalcon_view_engine_ce = zend_register_internal_class(&ce19 TSRMLS_CC);
	zend_declare_property_null(phalcon_view_engine_ce, "_view", sizeof("_view")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_view_engine_ce, "_options", sizeof("_options")-1, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce20, "Phalcon_Paginator_Adapter_Array", phalcon_paginator_adapter_array_functions);
	phalcon_paginator_adapter_array_ce = zend_register_internal_class(&ce20 TSRMLS_CC);
	zend_declare_property_null(phalcon_paginator_adapter_array_ce, "_limitRows", sizeof("_limitRows")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_paginator_adapter_array_ce, "_config", sizeof("_config")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_paginator_adapter_array_ce, "_page", sizeof("_page")-1, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce21, "Phalcon_Paginator_Adapter_Model", phalcon_paginator_adapter_model_functions);
	phalcon_paginator_adapter_model_ce = zend_register_internal_class(&ce21 TSRMLS_CC);
	zend_declare_property_null(phalcon_paginator_adapter_model_ce, "_limitRows", sizeof("_limitRows")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_paginator_adapter_model_ce, "_config", sizeof("_config")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_paginator_adapter_model_ce, "_page", sizeof("_page")-1, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce22, "Phalcon_Tag_Select", phalcon_tag_select_functions);
	phalcon_tag_select_ce = zend_register_internal_class(&ce22 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce23, "Phalcon_Internal_TestParent", phalcon_internal_testparent_functions);
	phalcon_internal_testparent_ce = zend_register_internal_class(&ce23 TSRMLS_CC);
	zend_declare_property_long(phalcon_internal_testparent_ce, "_pp0", sizeof("_pp0")-1, 0, ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce24, "Phalcon_Internal_TestTemp", phalcon_internal_testtemp_functions);
	phalcon_internal_testtemp_ce = zend_register_internal_class(&ce24 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce25, "Phalcon_Internal_TestDummy", phalcon_internal_testdummy_functions);
	phalcon_internal_testdummy_ce = zend_register_internal_class(&ce25 TSRMLS_CC);
	zend_declare_property_null(phalcon_internal_testdummy_ce, "_d1", sizeof("_d1")-1, ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce26, "Phalcon_Controller", phalcon_controller_functions);
	phalcon_controller_ce = zend_register_internal_class(&ce26 TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_ce, "dispatcher", sizeof("dispatcher")-1, ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_ce, "request", sizeof("request")-1, ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_ce, "response", sizeof("response")-1, ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_ce, "view", sizeof("view")-1, ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_ce, "model", sizeof("model")-1, ZEND_ACC_PUBLIC TSRMLS_CC);

	INIT_CLASS_ENTRY(ce27, "Phalcon_Request_File", phalcon_request_file_functions);
	phalcon_request_file_ce = zend_register_internal_class(&ce27 TSRMLS_CC);
	zend_declare_property_null(phalcon_request_file_ce, "_name", sizeof("_name")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_request_file_ce, "_tmp", sizeof("_tmp")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_request_file_ce, "_size", sizeof("_size")-1, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce28, "Phalcon_Paginator", phalcon_paginator_functions);
	phalcon_paginator_ce = zend_register_internal_class(&ce28 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce29, "Phalcon_Utils", phalcon_utils_functions);
	phalcon_utils_ce = zend_register_internal_class(&ce29 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce30, "Phalcon_Dispatcher", phalcon_dispatcher_functions);
	phalcon_dispatcher_ce = zend_register_internal_class(&ce30 TSRMLS_CC);
	zend_declare_property_null(phalcon_dispatcher_ce, "_finished", sizeof("_finished")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_dispatcher_ce, "_controllers", sizeof("_controllers")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_dispatcher_ce, "_controllersDir", sizeof("_controllersDir")-1, "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_dispatcher_ce, "_basePath", sizeof("_basePath")-1, "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_dispatcher_ce, "_controllerName", sizeof("_controllerName")-1, "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_dispatcher_ce, "_actionName", sizeof("_actionName")-1, "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_dispatcher_ce, "_params", sizeof("_params")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_dispatcher_ce, "_returnedValue", sizeof("_returnedValue")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_dispatcher_ce, "_lastController", sizeof("_lastController")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_dispatcher_ce, "_defaultController", sizeof("_defaultController")-1, "index", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_dispatcher_ce, "_defaultAction", sizeof("_defaultAction")-1, "index", ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce31, "Phalcon_Translate", phalcon_translate_functions);
	phalcon_translate_ce = zend_register_internal_class(&ce31 TSRMLS_CC);
	zend_declare_property_null(phalcon_translate_ce, "_adapter", sizeof("_adapter")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_class_implements(phalcon_translate_ce TSRMLS_CC, 1, zend_ce_arrayaccess);

	INIT_CLASS_ENTRY(ce32, "Phalcon_Db_Pool", phalcon_db_pool_functions);
	phalcon_db_pool_ce = zend_register_internal_class(&ce32 TSRMLS_CC);
	zend_declare_property_null(phalcon_db_pool_ce, "_connection", sizeof("_connection")-1, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_db_pool_ce, "_defaultDescriptor", sizeof("_defaultDescriptor")-1, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce33, "Phalcon_Db_Profiler", phalcon_db_profiler_functions);
	phalcon_db_profiler_ce = zend_register_internal_class(&ce33 TSRMLS_CC);
	zend_declare_property_null(phalcon_db_profiler_ce, "_allProfiles", sizeof("_allProfiles")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_profiler_ce, "_activeProfile", sizeof("_activeProfile")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_db_profiler_ce, "_totalSeconds", sizeof("_totalSeconds")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce34, "Phalcon_Db_Reference", phalcon_db_reference_functions);
	phalcon_db_reference_ce = zend_register_internal_class(&ce34 TSRMLS_CC);
	zend_declare_property_null(phalcon_db_reference_ce, "_referenceName", sizeof("_referenceName")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_db_reference_ce, "_referencedTable", sizeof("_referencedTable")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_db_reference_ce, "_columns", sizeof("_columns")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_db_reference_ce, "_referencedColumns", sizeof("_referencedColumns")-1, ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce35, "Phalcon_Db_Profiler_Item", phalcon_db_profiler_item_functions);
	phalcon_db_profiler_item_ce = zend_register_internal_class(&ce35 TSRMLS_CC);
	zend_declare_property_null(phalcon_db_profiler_item_ce, "_sqlStatement", sizeof("_sqlStatement")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_profiler_item_ce, "_initialTime", sizeof("_initialTime")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_profiler_item_ce, "_finalTime", sizeof("_finalTime")-1, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce36, "Phalcon_Db_RawValue", phalcon_db_rawvalue_functions);
	phalcon_db_rawvalue_ce = zend_register_internal_class(&ce36 TSRMLS_CC);
	zend_declare_property_null(phalcon_db_rawvalue_ce, "_value", sizeof("_value")-1, ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce37, "Phalcon_Db_Column", phalcon_db_column_functions);
	phalcon_db_column_ce = zend_register_internal_class(&ce37 TSRMLS_CC);
	zend_declare_property_null(phalcon_db_column_ce, "_columnName", sizeof("_columnName")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_db_column_ce, "_schemaName", sizeof("_schemaName")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_db_column_ce, "_type", sizeof("_type")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_long(phalcon_db_column_ce, "_size", sizeof("_size")-1, 0, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_long(phalcon_db_column_ce, "_scale", sizeof("_scale")-1, 0, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_column_ce, "_unsigned", sizeof("_unsigned")-1, 0, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_column_ce, "_notNull", sizeof("_notNull")-1, 0, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_column_ce, "_autoIncrement", sizeof("_autoIncrement")-1, 0, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_column_ce, "_first", sizeof("_first")-1, 0, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_db_column_ce, "_after", sizeof("_after")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_column_ce, "TYPE_INTEGER", sizeof("TYPE_INTEGER")-1, 0 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_column_ce, "TYPE_DATE", sizeof("TYPE_DATE")-1, 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_column_ce, "TYPE_VARCHAR", sizeof("TYPE_VARCHAR")-1, 2 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_column_ce, "TYPE_DECIMAL", sizeof("TYPE_DECIMAL")-1, 3 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_column_ce, "TYPE_DATETIME", sizeof("TYPE_DATETIME")-1, 4 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_column_ce, "TYPE_CHAR", sizeof("TYPE_CHAR")-1, 5 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_column_ce, "TYPE_TEXT", sizeof("TYPE_TEXT")-1, 6 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce38, "Phalcon_Db_Index", phalcon_db_index_functions);
	phalcon_db_index_ce = zend_register_internal_class(&ce38 TSRMLS_CC);
	zend_declare_property_null(phalcon_db_index_ce, "_indexName", sizeof("_indexName")-1, ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce39, "Phalcon_Db_Dialect_Mysql", phalcon_db_dialect_mysql_functions);
	phalcon_db_dialect_mysql_ce = zend_register_internal_class(&ce39 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce40, "Phalcon_Model_Query", phalcon_model_query_functions);
	phalcon_model_query_ce = zend_register_internal_class(&ce40 TSRMLS_CC);
	zend_declare_property_null(phalcon_model_query_ce, "_data", sizeof("_data")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_query_ce, "_manager", sizeof("_manager")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_query_ce, "_models", sizeof("_models")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_query_ce, "_parameters", sizeof("_parameters")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_query_ce, "_conditions", sizeof("_conditions")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_query_ce, "_limit", sizeof("_limit")-1, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce41, "Phalcon_Model_Base", phalcon_model_base_functions);
	phalcon_model_base_ce = zend_register_internal_class(&ce41 TSRMLS_CC);
	zend_declare_property_bool(phalcon_model_base_ce, "_initialized", sizeof("_initialized")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_model_base_ce, "_uniqueKey", sizeof("_uniqueKey")-1, "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_model_base_ce, "_connection", sizeof("_connection")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_model_base_ce, "_schema", sizeof("_schema")-1, "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_model_base_ce, "_source", sizeof("_source")-1, "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_model_base_ce, "_isView", sizeof("_isView")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_model_base_ce, "_dumped", sizeof("_dumped")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_model_base_ce, "_dumpLock", sizeof("_dumpLock")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_base_ce, "_errorMessages", sizeof("_errorMessages")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_base_ce, "_operationMade", sizeof("_operationMade")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_model_base_ce, "_forceExists", sizeof("_forceExists")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_model_base_ce, "_defaultConnection", sizeof("_defaultConnection")-1, 1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_base_ce, "_connectionName", sizeof("_connectionName")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_base_ce, "_manager", sizeof("_manager")-1, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);
	zend_declare_property_bool(phalcon_model_base_ce, "_disableEvents", sizeof("_disableEvents")-1, 0, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);
	zend_declare_property_bool(phalcon_model_base_ce, "_refreshPersistance", sizeof("_refreshPersistance")-1, 1, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_model_base_ce, "OP_CREATE", sizeof("OP_CREATE")-1, 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_model_base_ce, "OP_UPDATE", sizeof("OP_UPDATE")-1, 2 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_model_base_ce, "OP_DELETE", sizeof("OP_DELETE")-1, 3 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce42, "Phalcon_Model_Validator", phalcon_model_validator_functions);
	phalcon_model_validator_ce = zend_register_internal_class(&ce42 TSRMLS_CC);
	zend_declare_property_null(phalcon_model_validator_ce, "_record", sizeof("_record")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_validator_ce, "_fieldName", sizeof("_fieldName")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_validator_ce, "_value", sizeof("_value")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_validator_ce, "_options", sizeof("_options")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_validator_ce, "_messages", sizeof("_messages")-1, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce43, "Phalcon_Model_Row", phalcon_model_row_functions);
	phalcon_model_row_ce = zend_register_internal_class(&ce43 TSRMLS_CC);
	zend_declare_property_null(phalcon_model_row_ce, "_connection", sizeof("_connection")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_model_row_ce, "_columns", sizeof("_columns")-1, ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce44, "Phalcon_Model_Sanitize", phalcon_model_sanitize_functions);
	phalcon_model_sanitize_ce = zend_register_internal_class(&ce44 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce45, "Phalcon_Model_MetaData", phalcon_model_metadata_functions);
	phalcon_model_metadata_ce = zend_register_internal_class(&ce45 TSRMLS_CC);
	zend_declare_property_null(phalcon_model_metadata_ce, "_metaData", sizeof("_metaData")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_model_metadata_ce, "MODELS_ATTRIBUTES", sizeof("MODELS_ATTRIBUTES")-1, 0 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_model_metadata_ce, "MODELS_PRIMARY_KEY", sizeof("MODELS_PRIMARY_KEY")-1, 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_model_metadata_ce, "MODELS_NON_PRIMARY_KEY", sizeof("MODELS_NON_PRIMARY_KEY")-1, 2 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_model_metadata_ce, "MODELS_NOT_NULL", sizeof("MODELS_NOT_NULL")-1, 3 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_model_metadata_ce, "MODELS_DATA_TYPE", sizeof("MODELS_DATA_TYPE")-1, 4 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_model_metadata_ce, "MODELS_DATA_TYPE_NUMERIC", sizeof("MODELS_DATA_TYPE_NUMERIC")-1, 5 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_model_metadata_ce, "MODELS_DATE_AT", sizeof("MODELS_DATE_AT")-1, 6 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_model_metadata_ce, "MODELS_DATE_IN", sizeof("MODELS_DATE_IN")-1, 7 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_model_metadata_ce, "MODELS_IDENTITY_FIELD", sizeof("MODELS_IDENTITY_FIELD")-1, 8 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce46, "Phalcon_Model_Message", phalcon_model_message_functions);
	phalcon_model_message_ce = zend_register_internal_class(&ce46 TSRMLS_CC);
	zend_declare_property_null(phalcon_model_message_ce, "_type", sizeof("_type")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_model_message_ce, "_message", sizeof("_message")-1, ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce47, "Phalcon_Model_Manager", phalcon_model_manager_functions);
	phalcon_model_manager_ce = zend_register_internal_class(&ce47 TSRMLS_CC);
	zend_declare_property_bool(phalcon_model_manager_ce, "_connection", sizeof("_connection")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_manager_ce, "_metadata", sizeof("_metadata")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_manager_ce, "_basePath", sizeof("_basePath")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_manager_ce, "_modelsDir", sizeof("_modelsDir")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_manager_ce, "_models", sizeof("_models")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_manager_ce, "_hasMany", sizeof("_hasMany")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_manager_ce, "_hasOne", sizeof("_hasOne")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_manager_ce, "_belongsTo", sizeof("_belongsTo")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_manager_ce, "_metadataOptions", sizeof("_metadataOptions")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_manager_ce, "_sourceNames", sizeof("_sourceNames")-1, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	INIT_CLASS_ENTRY(ce48, "Phalcon_Model_MetaData_Memory", phalcon_model_metadata_memory_functions);
	phalcon_model_metadata_memory_ce = zend_register_internal_class(&ce48 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce49, "Phalcon_Model_MetaData_Session", phalcon_model_metadata_session_functions);
	phalcon_model_metadata_session_ce = zend_register_internal_class(&ce49 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce50, "Phalcon_Model_Resultset", phalcon_model_resultset_functions);
	phalcon_model_resultset_ce = zend_register_internal_class(&ce50 TSRMLS_CC);
	zend_declare_property_null(phalcon_model_resultset_ce, "_type", sizeof("_type")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_resultset_ce, "_model", sizeof("_model")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_resultset_ce, "_connection", sizeof("_connection")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_resultset_ce, "_resultResource", sizeof("_resultResource")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_model_resultset_ce, "_pointer", sizeof("_pointer")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_resultset_ce, "_count", sizeof("_count")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_resultset_ce, "_activeRow", sizeof("_activeRow")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_resultset_ce, "_rows", sizeof("_rows")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_class_implements(phalcon_model_resultset_ce TSRMLS_CC, 5, zend_ce_iterator, spl_ce_SeekableIterator, spl_ce_Countable, zend_ce_arrayaccess, zend_ce_serializable);

	INIT_CLASS_ENTRY(ce51, "Phalcon_Tag", phalcon_tag_functions);
	phalcon_tag_ce = zend_register_internal_class(&ce51 TSRMLS_CC);
	zend_declare_property_null(phalcon_tag_ce, "_displayValues", sizeof("_displayValues")-1, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);
	zend_declare_property_string(phalcon_tag_ce, "_documentTitle", sizeof("_documentTitle")-1, "", ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);
	zend_declare_property_null(phalcon_tag_ce, "_dispatcher", sizeof("_dispatcher")-1, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	INIT_CLASS_ENTRY(ce52, "Phalcon_Response", phalcon_response_functions);
	phalcon_response_ce = zend_register_internal_class(&ce52 TSRMLS_CC);
	zend_declare_property_null(phalcon_response_ce, "_instance", sizeof("_instance")-1, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_response_ce, "_content", sizeof("_content")-1, ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce53, "Phalcon_Request", phalcon_request_functions);
	phalcon_request_ce = zend_register_internal_class(&ce53 TSRMLS_CC);
	zend_declare_property_null(phalcon_request_ce, "_filter", sizeof("_filter")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_request_ce, "_instance", sizeof("_instance")-1, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce54, "Phalcon_Transaction_Manager", phalcon_transaction_manager_functions);
	phalcon_transaction_manager_ce = zend_register_internal_class(&ce54 TSRMLS_CC);
	zend_declare_property_bool(phalcon_transaction_manager_ce, "_initialized", sizeof("_initialized")-1, 0, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_long(phalcon_transaction_manager_ce, "_number", sizeof("_number")-1, 0, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_transaction_manager_ce, "_transactions", sizeof("_transactions")-1, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_long(phalcon_transaction_manager_ce, "_dependencyPointer", sizeof("_dependencyPointer")-1, 0, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_transaction_manager_ce, "_automaticTransaction", sizeof("_automaticTransaction")-1, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce55, "Phalcon_Controller_Front", phalcon_controller_front_functions);
	phalcon_controller_front_ce = zend_register_internal_class(&ce55 TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_ce, "_instance", sizeof("_instance")-1, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_ce, "_controllersDir", sizeof("_controllersDir")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_ce, "_modelsDir", sizeof("_modelsDir")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_ce, "_viewsDir", sizeof("_viewsDir")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_ce, "_basePath", sizeof("_basePath")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_ce, "_baseUri", sizeof("_baseUri")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_ce, "_dispatcher", sizeof("_dispatcher")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_ce, "_model", sizeof("_model")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_ce, "_view", sizeof("_view")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_ce, "_request", sizeof("_request")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_ce, "_response", sizeof("_response")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_ce, "_router", sizeof("_router")-1, ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce56, "Phalcon_Session", phalcon_session_functions);
	phalcon_session_ce = zend_register_internal_class(&ce56 TSRMLS_CC);
	zend_declare_property_null(phalcon_session_ce, "_uniqueId", sizeof("_uniqueId")-1, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_session_ce, "_options", sizeof("_options")-1, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce57, "Phalcon_Flash", phalcon_flash_functions);
	phalcon_flash_ce = zend_register_internal_class(&ce57 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce58, "Phalcon_Config", phalcon_config_functions);
	phalcon_config_ce = zend_register_internal_class(&ce58 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce59, "Phalcon_Filter", phalcon_filter_functions);
	phalcon_filter_ce = zend_register_internal_class(&ce59 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce60, "Phalcon_Acl", phalcon_acl_functions);
	phalcon_acl_ce = zend_register_internal_class(&ce60 TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_ce, "_adapter", sizeof("_adapter")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_acl_ce, "ALLOW", sizeof("ALLOW")-1, 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_acl_ce, "DENY", sizeof("DENY")-1, 0 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce61, "Phalcon_Translate_Adapter_Array", phalcon_translate_adapter_array_functions);
	phalcon_translate_adapter_array_ce = zend_register_internal_class(&ce61 TSRMLS_CC);
	zend_declare_property_null(phalcon_translate_adapter_array_ce, "_traslate", sizeof("_traslate")-1, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce62, "Phalcon_Logger_Adapter_File", phalcon_logger_adapter_file_functions);
	phalcon_logger_adapter_file_ce = zend_register_internal_class(&ce62 TSRMLS_CC);
	zend_declare_property_null(phalcon_logger_adapter_file_ce, "_fileHandler", sizeof("_fileHandler")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_logger_adapter_file_ce, "_transaction", sizeof("_transaction")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_logger_adapter_file_ce, "_quenue", sizeof("_quenue")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_logger_adapter_file_ce, "_dateFormat", sizeof("_dateFormat")-1, "D, d M y H:i:s O", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_logger_adapter_file_ce, "_format", sizeof("_format")-1, "[%date%][%type%] %message%", ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce63, "Phalcon_Logger_Item", phalcon_logger_item_functions);
	phalcon_logger_item_ce = zend_register_internal_class(&ce63 TSRMLS_CC);
	zend_declare_property_null(phalcon_logger_item_ce, "_type", sizeof("_type")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_logger_item_ce, "message", sizeof("message")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_logger_item_ce, "_time", sizeof("_time")-1, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce64, "Phalcon_Transaction", phalcon_transaction_functions);
	phalcon_transaction_ce = zend_register_internal_class(&ce64 TSRMLS_CC);
	zend_declare_property_null(phalcon_transaction_ce, "_connection", sizeof("_connection")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_bool(phalcon_transaction_ce, "_activeTransaction", sizeof("_activeTransaction")-1, 0, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_bool(phalcon_transaction_ce, "_isNewTransaction", sizeof("_isNewTransaction")-1, 1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_bool(phalcon_transaction_ce, "_rollbackOnAbort", sizeof("_rollbackOnAbort")-1, 0, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_transaction_ce, "_manager", sizeof("_manager")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_long(phalcon_transaction_ce, "_pointer", sizeof("_pointer")-1, 255, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_transaction_ce, "_dependencies", sizeof("_dependencies")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_transaction_ce, "_messages", sizeof("_messages")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_transaction_ce, "_rollbackRecord", sizeof("_rollbackRecord")-1, ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce65, "Phalcon_Exception", phalcon_exception_functions);
	phalcon_exception_ce = zend_register_internal_class_ex(&ce65, NULL, "exception" TSRMLS_CC);
	if(!phalcon_exception_ce){
		phalcon_inherit_not_found("Exception", "Phalcon_Exception");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce66, "Phalcon_Config", phalcon_config_functions);
	phalcon_config_ce = zend_register_internal_class(&ce66 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce67, "Phalcon_View_Engine", phalcon_view_engine_functions);
	phalcon_view_engine_ce = zend_register_internal_class(&ce67 TSRMLS_CC);
	zend_declare_property_null(phalcon_view_engine_ce, "_view", sizeof("_view")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_view_engine_ce, "_options", sizeof("_options")-1, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce68, "Phalcon_Internal_TestParent", phalcon_internal_testparent_functions);
	phalcon_internal_testparent_ce = zend_register_internal_class(&ce68 TSRMLS_CC);
	zend_declare_property_long(phalcon_internal_testparent_ce, "_pp0", sizeof("_pp0")-1, 0, ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce69, "Phalcon_Db", phalcon_db_functions);
	phalcon_db_ce = zend_register_internal_class(&ce69 TSRMLS_CC);
	zend_declare_property_null(phalcon_db_ce, "_descriptor", sizeof("_descriptor")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_ce, "_fetchMode", sizeof("_fetchMode")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_ce, "_autoCommit", sizeof("_autoCommit")-1, 1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_ce, "_idConnection", sizeof("_idConnection")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_ce, "_underTransaction", sizeof("_underTransaction")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_ce, "_logger", sizeof("_logger")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_ce, "_profiler", sizeof("_profiler")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_ce, "DB_ASSOC", sizeof("DB_ASSOC")-1, 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_ce, "DB_BOTH", sizeof("DB_BOTH")-1, 2 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_ce, "DB_NUM", sizeof("DB_NUM")-1, 3 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce70, "Phalcon_Model_Validator", phalcon_model_validator_functions);
	phalcon_model_validator_ce = zend_register_internal_class(&ce70 TSRMLS_CC);
	zend_declare_property_null(phalcon_model_validator_ce, "_record", sizeof("_record")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_validator_ce, "_fieldName", sizeof("_fieldName")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_validator_ce, "_value", sizeof("_value")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_validator_ce, "_options", sizeof("_options")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_validator_ce, "_messages", sizeof("_messages")-1, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce71, "Phalcon_Config_Exception", phalcon_config_exception_functions);
	phalcon_config_exception_ce = zend_register_internal_class_ex(&ce71, NULL, "phalcon_exception" TSRMLS_CC);
	if(!phalcon_config_exception_ce){
		phalcon_inherit_not_found("Phalcon_Exception", "Phalcon_Config_Exception");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce72, "Phalcon_Config_Adapter_Ini", phalcon_config_adapter_ini_functions);
	phalcon_config_adapter_ini_ce = zend_register_internal_class_ex(&ce72, NULL, "phalcon_config" TSRMLS_CC);
	if(!phalcon_config_adapter_ini_ce){
		phalcon_inherit_not_found("Phalcon_Config", "Phalcon_Config_Adapter_Ini");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce73, "Phalcon_Cache_Exception", phalcon_cache_exception_functions);
	phalcon_cache_exception_ce = zend_register_internal_class_ex(&ce73, NULL, "phalcon_exception" TSRMLS_CC);
	if(!phalcon_cache_exception_ce){
		phalcon_inherit_not_found("Phalcon_Exception", "Phalcon_Cache_Exception");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce74, "Phalcon_Acl_Exception", phalcon_acl_exception_functions);
	phalcon_acl_exception_ce = zend_register_internal_class_ex(&ce74, NULL, "phalcon_exception" TSRMLS_CC);
	if(!phalcon_acl_exception_ce){
		phalcon_inherit_not_found("Phalcon_Exception", "Phalcon_Acl_Exception");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce75, "Phalcon_Dispatcher_Exception", phalcon_dispatcher_exception_functions);
	phalcon_dispatcher_exception_ce = zend_register_internal_class_ex(&ce75, NULL, "phalcon_exception" TSRMLS_CC);
	if(!phalcon_dispatcher_exception_ce){
		phalcon_inherit_not_found("Phalcon_Exception", "Phalcon_Dispatcher_Exception");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce76, "Phalcon_View_Exception", phalcon_view_exception_functions);
	phalcon_view_exception_ce = zend_register_internal_class_ex(&ce76, NULL, "phalcon_exception" TSRMLS_CC);
	if(!phalcon_view_exception_ce){
		phalcon_inherit_not_found("Phalcon_Exception", "Phalcon_View_Exception");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce77, "Phalcon_View_Engine_Php", phalcon_view_engine_php_functions);
	phalcon_view_engine_php_ce = zend_register_internal_class_ex(&ce77, NULL, "phalcon_view_engine" TSRMLS_CC);
	if(!phalcon_view_engine_php_ce){
		phalcon_inherit_not_found("Phalcon_View_Engine", "Phalcon_View_Engine_Php");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce78, "Phalcon_View_Engine_Twig", phalcon_view_engine_twig_functions);
	phalcon_view_engine_twig_ce = zend_register_internal_class_ex(&ce78, NULL, "phalcon_view_engine" TSRMLS_CC);
	if(!phalcon_view_engine_twig_ce){
		phalcon_inherit_not_found("Phalcon_View_Engine", "Phalcon_View_Engine_Twig");
		return FAILURE;
	}
	zend_declare_property_null(phalcon_view_engine_twig_ce, "_twig", sizeof("_twig")-1, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce79, "Phalcon_View_Engine_Mustache", phalcon_view_engine_mustache_functions);
	phalcon_view_engine_mustache_ce = zend_register_internal_class_ex(&ce79, NULL, "phalcon_view_engine" TSRMLS_CC);
	if(!phalcon_view_engine_mustache_ce){
		phalcon_inherit_not_found("Phalcon_View_Engine", "Phalcon_View_Engine_Mustache");
		return FAILURE;
	}
	zend_declare_property_null(phalcon_view_engine_mustache_ce, "_mustache", sizeof("_mustache")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_view_engine_mustache_ce, "_params", sizeof("_params")-1, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce80, "Phalcon_Paginator_Exception", phalcon_paginator_exception_functions);
	phalcon_paginator_exception_ce = zend_register_internal_class_ex(&ce80, NULL, "phalcon_exception" TSRMLS_CC);
	if(!phalcon_paginator_exception_ce){
		phalcon_inherit_not_found("Phalcon_Exception", "Phalcon_Paginator_Exception");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce81, "Phalcon_Tag_Exception", phalcon_tag_exception_functions);
	phalcon_tag_exception_ce = zend_register_internal_class_ex(&ce81, NULL, "phalcon_exception" TSRMLS_CC);
	if(!phalcon_tag_exception_ce){
		phalcon_inherit_not_found("Phalcon_Exception", "Phalcon_Tag_Exception");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce82, "Phalcon_Internal_Test", phalcon_internal_test_functions);
	phalcon_internal_test_ce = zend_register_internal_class_ex(&ce82, NULL, "phalcon_internal_testparent" TSRMLS_CC);
	if(!phalcon_internal_test_ce){
		phalcon_inherit_not_found("Phalcon_Internal_TestParent", "Phalcon_Internal_Test");
		return FAILURE;
	}
	zend_declare_property_null(phalcon_internal_test_ce, "_p0", sizeof("_p0")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_internal_test_ce, "_p1", sizeof("_p1")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_string(phalcon_internal_test_ce, "_p2", sizeof("_p2")-1, "str", ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_double(phalcon_internal_test_ce, "_p3", sizeof("_p3")-1, 4.12, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_bool(phalcon_internal_test_ce, "_p4", sizeof("_p4")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_internal_test_ce, "_p5", sizeof("_p5")-1, 1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_string(phalcon_internal_test_ce, "_p6", sizeof("_p6")-1, "12.01", ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_long(phalcon_internal_test_ce, "_p7", sizeof("_p7")-1, 128, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_internal_test_ce, "_p8", sizeof("_p8")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_internal_test_ce, "_p9", sizeof("_p9")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_internal_test_ce, "_sp0", sizeof("_sp0")-1, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_string(phalcon_internal_test_ce, "_sp1", sizeof("_sp1")-1, "hello", ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_internal_test_ce, "_sp2", sizeof("_sp2")-1, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_string(phalcon_internal_test_ce, "_sp3", sizeof("_sp3")-1, "11.20", ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_long(phalcon_internal_test_ce, "_sp4", sizeof("_sp4")-1, 128, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_bool(phalcon_internal_test_ce, "_sp5", sizeof("_sp5")-1, 0, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_bool(phalcon_internal_test_ce, "_sp6", sizeof("_sp6")-1, 1, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_double(phalcon_internal_test_ce, "_sp7", sizeof("_sp7")-1, 3.1415, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_internal_test_ce, "C1", sizeof("C1")-1, 0 TSRMLS_CC);
	zend_declare_class_constant_double(phalcon_internal_test_ce, "C2", sizeof("C2")-1, 2.1 TSRMLS_CC);
	zend_declare_class_constant_bool(phalcon_internal_test_ce, "C3", sizeof("C3")-1, 0 TSRMLS_CC);
	zend_declare_class_constant_bool(phalcon_internal_test_ce, "C4", sizeof("C4")-1, 1 TSRMLS_CC);
	zend_declare_class_constant_null(phalcon_internal_test_ce, "C5", sizeof("C5")-1 TSRMLS_CC);
	zend_declare_class_constant_string(phalcon_internal_test_ce, "C6", sizeof("C6")-1, "str" TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_internal_test_ce, "C7", sizeof("C7")-1, -92 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce83, "Phalcon_Db_Exception", phalcon_db_exception_functions);
	phalcon_db_exception_ce = zend_register_internal_class_ex(&ce83, NULL, "phalcon_exception" TSRMLS_CC);
	if(!phalcon_db_exception_ce){
		phalcon_inherit_not_found("Phalcon_Exception", "Phalcon_Db_Exception");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce84, "Phalcon_Db_Adapter_Mysql", phalcon_db_adapter_mysql_functions);
	phalcon_db_adapter_mysql_ce = zend_register_internal_class_ex(&ce84, NULL, "phalcon_db" TSRMLS_CC);
	if(!phalcon_db_adapter_mysql_ce){
		phalcon_inherit_not_found("Phalcon_Db", "Phalcon_Db_Adapter_Mysql");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce85, "Phalcon_Model_Validator_Uniqueness", phalcon_model_validator_uniqueness_functions);
	phalcon_model_validator_uniqueness_ce = zend_register_internal_class_ex(&ce85, NULL, "phalcon_model_validator" TSRMLS_CC);
	if(!phalcon_model_validator_uniqueness_ce){
		phalcon_inherit_not_found("Phalcon_Model_Validator", "Phalcon_Model_Validator_Uniqueness");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce86, "Phalcon_Model_Validator_Exclusionin", phalcon_model_validator_exclusionin_functions);
	phalcon_model_validator_exclusionin_ce = zend_register_internal_class_ex(&ce86, NULL, "phalcon_model_validator" TSRMLS_CC);
	if(!phalcon_model_validator_exclusionin_ce){
		phalcon_inherit_not_found("Phalcon_Model_Validator", "Phalcon_Model_Validator_Exclusionin");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce87, "Phalcon_Model_Validator_Regex", phalcon_model_validator_regex_functions);
	phalcon_model_validator_regex_ce = zend_register_internal_class_ex(&ce87, NULL, "phalcon_model_validator" TSRMLS_CC);
	if(!phalcon_model_validator_regex_ce){
		phalcon_inherit_not_found("Phalcon_Model_Validator", "Phalcon_Model_Validator_Regex");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce88, "Phalcon_Model_Validator_Inclusionin", phalcon_model_validator_inclusionin_functions);
	phalcon_model_validator_inclusionin_ce = zend_register_internal_class_ex(&ce88, NULL, "phalcon_model_validator" TSRMLS_CC);
	if(!phalcon_model_validator_inclusionin_ce){
		phalcon_inherit_not_found("Phalcon_Model_Validator", "Phalcon_Model_Validator_Inclusionin");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce89, "Phalcon_Model_Validator_Numericality", phalcon_model_validator_numericality_functions);
	phalcon_model_validator_numericality_ce = zend_register_internal_class_ex(&ce89, NULL, "phalcon_model_validator" TSRMLS_CC);
	if(!phalcon_model_validator_numericality_ce){
		phalcon_inherit_not_found("Phalcon_Model_Validator", "Phalcon_Model_Validator_Numericality");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce90, "Phalcon_Model_Validator_Email", phalcon_model_validator_email_functions);
	phalcon_model_validator_email_ce = zend_register_internal_class_ex(&ce90, NULL, "phalcon_model_validator" TSRMLS_CC);
	if(!phalcon_model_validator_email_ce){
		phalcon_inherit_not_found("Phalcon_Model_Validator", "Phalcon_Model_Validator_Email");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce91, "Phalcon_Model_Exception", phalcon_model_exception_functions);
	phalcon_model_exception_ce = zend_register_internal_class_ex(&ce91, NULL, "phalcon_exception" TSRMLS_CC);
	if(!phalcon_model_exception_ce){
		phalcon_inherit_not_found("Phalcon_Exception", "Phalcon_Model_Exception");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce92, "Phalcon_Transaction_Failed", phalcon_transaction_failed_functions);
	phalcon_transaction_failed_ce = zend_register_internal_class_ex(&ce92, NULL, "exception" TSRMLS_CC);
	if(!phalcon_transaction_failed_ce){
		phalcon_inherit_not_found("Exception", "Phalcon_Transaction_Failed");
		return FAILURE;
	}
	zend_declare_property_null(phalcon_transaction_failed_ce, "_record", sizeof("_record")-1, ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce93, "Phalcon_Translate_Exception", phalcon_translate_exception_functions);
	phalcon_translate_exception_ce = zend_register_internal_class_ex(&ce93, NULL, "phalcon_exception" TSRMLS_CC);
	if(!phalcon_translate_exception_ce){
		phalcon_inherit_not_found("Phalcon_Exception", "Phalcon_Translate_Exception");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce94, "Phalcon_Logger_Exception", phalcon_logger_exception_functions);
	phalcon_logger_exception_ce = zend_register_internal_class_ex(&ce94, NULL, "phalcon_exception" TSRMLS_CC);
	if(!phalcon_logger_exception_ce){
		phalcon_inherit_not_found("Phalcon_Exception", "Phalcon_Logger_Exception");
		return FAILURE;
	}
	return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(phalcon){
	return SUCCESS;
}

PHP_RINIT_FUNCTION(phalcon){
#if PHALCON_EXPERIMENTAL_CALL
	return phalcon_init_fcall_cache(TSRMLS_C);
#else
	return SUCCESS;
#endif
}

PHP_RSHUTDOWN_FUNCTION(phalcon){
#if PHALCON_EXPERIMENTAL_CALL
	return phalcon_free_fcall_cache(TSRMLS_C);
#else
	return SUCCESS;
#endif
}

zend_module_entry phalcon_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	PHP_PHALCON_EXTNAME,
	NULL,
	PHP_MINIT(phalcon),
	PHP_MSHUTDOWN(phalcon),
	PHP_RINIT(phalcon),
	PHP_RSHUTDOWN(phalcon),
	NULL,
#if ZEND_MODULE_API_NO >= 20010901
	PHP_PHALCON_VERSION,
#endif
	STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_PHALCON
ZEND_GET_MODULE(phalcon)
#endif

