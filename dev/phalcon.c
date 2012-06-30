
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

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

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
zend_class_entry *phalcon_cache_backend_ce;
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
zend_class_entry *phalcon_request_exception_ce;
zend_class_entry *phalcon_request_file_ce;
zend_class_entry *phalcon_paginator_ce;
zend_class_entry *phalcon_utils_ce;
zend_class_entry *phalcon_response_exception_ce;
zend_class_entry *phalcon_response_headers_ce;
zend_class_entry *phalcon_dispatcher_ce;
zend_class_entry *phalcon_translate_ce;
zend_class_entry *phalcon_db_pool_ce;
zend_class_entry *phalcon_db_profiler_ce;
zend_class_entry *phalcon_db_exception_ce;
zend_class_entry *phalcon_db_reference_ce;
zend_class_entry *phalcon_db_adapter_mysql_ce;
zend_class_entry *phalcon_db_adapter_postgresql_ce;
zend_class_entry *phalcon_db_profiler_item_ce;
zend_class_entry *phalcon_db_rawvalue_ce;
zend_class_entry *phalcon_db_column_ce;
zend_class_entry *phalcon_db_index_ce;
zend_class_entry *phalcon_db_result_mysql_ce;
zend_class_entry *phalcon_db_result_postgresql_ce;
zend_class_entry *phalcon_db_dialect_mysql_ce;
zend_class_entry *phalcon_db_dialect_postgresql_ce;
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
zend_class_entry *phalcon_model_metadata_apc_ce;
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
zend_class_entry *phalcon_loader_exception_ce;

ZEND_DECLARE_MODULE_GLOBALS(phalcon)

PHP_MINIT_FUNCTION(phalcon){

	zend_class_entry ce_session_namespace;
	zend_class_entry ce_loader;
	zend_class_entry ce_text;
	zend_class_entry ce_test;
	zend_class_entry ce_router_rewrite;
	zend_class_entry ce_router_regex;
	zend_class_entry ce_db;
	zend_class_entry ce_logger;
	zend_class_entry ce_cache_frontend_output;
	zend_class_entry ce_cache_frontend_none;
	zend_class_entry ce_cache_frontend_data;
	zend_class_entry ce_cache_backend;
	zend_class_entry ce_acl_adapter_memory;
	zend_class_entry ce_acl_role;
	zend_class_entry ce_acl_resource;
	zend_class_entry ce_cache;
	zend_class_entry ce_view;
	zend_class_entry ce_view_engine;
	zend_class_entry ce_paginator_adapter_array;
	zend_class_entry ce_paginator_adapter_model;
	zend_class_entry ce_tag_select;
	zend_class_entry ce_internal_testparent;
	zend_class_entry ce_internal_testtemp;
	zend_class_entry ce_internal_testdummy;
	zend_class_entry ce_controller;
	zend_class_entry ce_request_file;
	zend_class_entry ce_paginator;
	zend_class_entry ce_utils;
	zend_class_entry ce_response_headers;
	zend_class_entry ce_dispatcher;
	zend_class_entry ce_translate;
	zend_class_entry ce_db_pool;
	zend_class_entry ce_db_profiler;
	zend_class_entry ce_db_reference;
	zend_class_entry ce_db_profiler_item;
	zend_class_entry ce_db_rawvalue;
	zend_class_entry ce_db_column;
	zend_class_entry ce_db_index;
	zend_class_entry ce_db_result_mysql;
	zend_class_entry ce_db_result_postgresql;
	zend_class_entry ce_db_dialect_mysql;
	zend_class_entry ce_db_dialect_postgresql;
	zend_class_entry ce_model_query;
	zend_class_entry ce_model_base;
	zend_class_entry ce_model_validator;
	zend_class_entry ce_model_row;
	zend_class_entry ce_model_sanitize;
	zend_class_entry ce_model_metadata;
	zend_class_entry ce_model_message;
	zend_class_entry ce_model_manager;
	zend_class_entry ce_model_metadata_memory;
	zend_class_entry ce_model_metadata_apc;
	zend_class_entry ce_model_metadata_session;
	zend_class_entry ce_model_resultset;
	zend_class_entry ce_tag;
	zend_class_entry ce_response;
	zend_class_entry ce_request;
	zend_class_entry ce_transaction_manager;
	zend_class_entry ce_controller_front;
	zend_class_entry ce_session;
	zend_class_entry ce_flash;
	zend_class_entry ce_config;
	zend_class_entry ce_filter;
	zend_class_entry ce_acl;
	zend_class_entry ce_translate_adapter_array;
	zend_class_entry ce_logger_adapter_file;
	zend_class_entry ce_logger_item;
	zend_class_entry ce_transaction;
	zend_class_entry ce_exception;
	zend_class_entry ce_config_exception;
	zend_class_entry ce_config_adapter_ini;
	zend_class_entry ce_cache_exception;
	zend_class_entry ce_cache_backend_memcache;
	zend_class_entry ce_cache_backend_apc;
	zend_class_entry ce_cache_backend_file;
	zend_class_entry ce_acl_exception;
	zend_class_entry ce_dispatcher_exception;
	zend_class_entry ce_view_exception;
	zend_class_entry ce_view_engine_php;
	zend_class_entry ce_view_engine_twig;
	zend_class_entry ce_view_engine_mustache;
	zend_class_entry ce_paginator_exception;
	zend_class_entry ce_tag_exception;
	zend_class_entry ce_internal_test;
	zend_class_entry ce_request_exception;
	zend_class_entry ce_response_exception;
	zend_class_entry ce_db_exception;
	zend_class_entry ce_db_adapter_mysql;
	zend_class_entry ce_db_adapter_postgresql;
	zend_class_entry ce_model_validator_uniqueness;
	zend_class_entry ce_model_validator_exclusionin;
	zend_class_entry ce_model_validator_regex;
	zend_class_entry ce_model_validator_inclusionin;
	zend_class_entry ce_model_validator_numericality;
	zend_class_entry ce_model_validator_email;
	zend_class_entry ce_model_exception;
	zend_class_entry ce_transaction_failed;
	zend_class_entry ce_translate_exception;
	zend_class_entry ce_logger_exception;
	zend_class_entry ce_loader_exception;

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

	INIT_CLASS_ENTRY(ce_session_namespace, "Phalcon_Session_Namespace", phalcon_session_namespace_functions);
	phalcon_session_namespace_ce = zend_register_internal_class(&ce_session_namespace TSRMLS_CC);
	zend_declare_property_null(phalcon_session_namespace_ce, SL("_name"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_session_namespace_ce, SL("_data"), ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_loader, "Phalcon_Loader", phalcon_loader_functions);
	phalcon_loader_ce = zend_register_internal_class(&ce_loader TSRMLS_CC);
	zend_declare_property_null(phalcon_loader_ce, SL("_namespaces"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_loader_ce, SL("_directories"), ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_text, "Phalcon_Text", phalcon_text_functions);
	phalcon_text_ce = zend_register_internal_class(&ce_text TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_test, "Phalcon_Test", phalcon_test_functions);
	phalcon_test_ce = zend_register_internal_class(&ce_test TSRMLS_CC);
	zend_declare_property_null(phalcon_test_ce, SL("p"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_router_rewrite, "Phalcon_Router_Rewrite", phalcon_router_rewrite_functions);
	phalcon_router_rewrite_ce = zend_register_internal_class(&ce_router_rewrite TSRMLS_CC);
	zend_declare_property_null(phalcon_router_rewrite_ce, SL("_controller"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_router_rewrite_ce, SL("_action"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_router_rewrite_ce, SL("_params"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_router_rewrite_ce, SL("_prefix"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_router_regex, "Phalcon_Router_Regex", phalcon_router_regex_functions);
	phalcon_router_regex_ce = zend_register_internal_class(&ce_router_regex TSRMLS_CC);
	zend_declare_property_null(phalcon_router_regex_ce, SL("_controller"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_router_regex_ce, SL("_action"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_router_regex_ce, SL("_params"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_router_regex_ce, SL("_baseUri"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_router_regex_ce, SL("_routes"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_router_regex_ce, SL("_currentRoute"), ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_db, "Phalcon_Db", phalcon_db_functions);
	phalcon_db_ce = zend_register_internal_class(&ce_db TSRMLS_CC);
	zend_declare_property_null(phalcon_db_ce, SL("_descriptor"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_ce, SL("_idConnection"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_ce, SL("_autoCommit"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_ce, SL("_underTransaction"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_ce, SL("_logger"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_ce, SL("_profiler"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_ce, SL("DB_ASSOC"), 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_ce, SL("DB_BOTH"), 2 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_ce, SL("DB_NUM"), 3 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_logger, "Phalcon_Logger", phalcon_logger_functions);
	phalcon_logger_ce = zend_register_internal_class(&ce_logger TSRMLS_CC);
	zend_declare_property_null(phalcon_logger_ce, SL("_adapter"), ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_ce, SL("SPECIAL"), 9 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_ce, SL("CUSTOM"), 8 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_ce, SL("DEBUG"), 7 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_ce, SL("INFO"), 6 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_ce, SL("NOTICE"), 5 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_ce, SL("WARNING"), 4 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_ce, SL("ERROR"), 3 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_ce, SL("ALERT"), 2 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_ce, SL("CRITICAL"), 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_ce, SL("EMERGENCE"), 0 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_cache_frontend_output, "Phalcon_Cache_Frontend_Output", phalcon_cache_frontend_output_functions);
	phalcon_cache_frontend_output_ce = zend_register_internal_class(&ce_cache_frontend_output TSRMLS_CC);
	zend_declare_property_bool(phalcon_cache_frontend_output_ce, SL("_buffering"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_cache_frontend_output_ce, SL("_frontendOptions"), ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_cache_frontend_none, "Phalcon_Cache_Frontend_None", phalcon_cache_frontend_none_functions);
	phalcon_cache_frontend_none_ce = zend_register_internal_class(&ce_cache_frontend_none TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_cache_frontend_data, "Phalcon_Cache_Frontend_Data", phalcon_cache_frontend_data_functions);
	phalcon_cache_frontend_data_ce = zend_register_internal_class(&ce_cache_frontend_data TSRMLS_CC);
	zend_declare_property_null(phalcon_cache_frontend_data_ce, SL("_frontendOptions"), ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_cache_backend, "Phalcon_Cache_Backend", phalcon_cache_backend_functions);
	phalcon_cache_backend_ce = zend_register_internal_class(&ce_cache_backend TSRMLS_CC);
	zend_declare_property_null(phalcon_cache_backend_ce, SL("_frontendObject"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_cache_backend_ce, SL("_backendOptions"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_cache_backend_ce, SL("_prefix"), "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_cache_backend_ce, SL("_lastKey"), "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_cache_backend_ce, SL("_fresh"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_cache_backend_ce, SL("_started"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_acl_adapter_memory, "Phalcon_Acl_Adapter_Memory", phalcon_acl_adapter_memory_functions);
	phalcon_acl_adapter_memory_ce = zend_register_internal_class(&ce_acl_adapter_memory TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_rolesNames"), ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_roles"), ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_resources"), ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_access"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_roleInherits"), ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_resourcesNames"), ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_accessList"), ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_long(phalcon_acl_adapter_memory_ce, SL("_defaultAccess"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_acl_role, "Phalcon_Acl_Role", phalcon_acl_role_functions);
	phalcon_acl_role_ce = zend_register_internal_class(&ce_acl_role TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_role_ce, SL("_name"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_role_ce, SL("_description"), ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_acl_resource, "Phalcon_Acl_Resource", phalcon_acl_resource_functions);
	phalcon_acl_resource_ce = zend_register_internal_class(&ce_acl_resource TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_resource_ce, SL("_name"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_resource_ce, SL("_description"), ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_cache, "Phalcon_Cache", phalcon_cache_functions);
	phalcon_cache_ce = zend_register_internal_class(&ce_cache TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_view, "Phalcon_View", phalcon_view_functions);
	phalcon_view_ce = zend_register_internal_class(&ce_view TSRMLS_CC);
	zend_declare_property_null(phalcon_view_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_view_ce, SL("_basePath"), "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_view_ce, SL("_content"), "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_view_ce, SL("_renderLevel"), 5, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_view_ce, SL("_viewParams"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_view_ce, SL("_layoutsDir"), "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_view_ce, SL("_templatesBefore"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_view_ce, SL("_templatesAfter"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_view_ce, SL("_engines"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_view_ce, SL("_registeredEngines"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_view_ce, SL("_mainView"), "index", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_view_ce, SL("_controllerName"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_view_ce, SL("_actionName"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_view_ce, SL("_params"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_view_ce, SL("_pickView"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_view_ce, SL("_cache"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_view_ce, SL("_cacheLevel"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_view_ce, SL("LEVEL_MAIN_LAYOUT"), 5 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_view_ce, SL("LEVEL_AFTER_TEMPLATE"), 4 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_view_ce, SL("LEVEL_LAYOUT"), 3 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_view_ce, SL("LEVEL_BEFORE_TEMPLATE"), 2 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_view_ce, SL("LEVEL_ACTION_VIEW"), 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_view_ce, SL("LEVEL_NO_RENDER"), 0 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_view_engine, "Phalcon_View_Engine", phalcon_view_engine_functions);
	phalcon_view_engine_ce = zend_register_internal_class(&ce_view_engine TSRMLS_CC);
	zend_declare_property_null(phalcon_view_engine_ce, SL("_view"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_view_engine_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_paginator_adapter_array, "Phalcon_Paginator_Adapter_Array", phalcon_paginator_adapter_array_functions);
	phalcon_paginator_adapter_array_ce = zend_register_internal_class(&ce_paginator_adapter_array TSRMLS_CC);
	zend_declare_property_null(phalcon_paginator_adapter_array_ce, SL("_limitRows"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_paginator_adapter_array_ce, SL("_config"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_paginator_adapter_array_ce, SL("_page"), ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_paginator_adapter_model, "Phalcon_Paginator_Adapter_Model", phalcon_paginator_adapter_model_functions);
	phalcon_paginator_adapter_model_ce = zend_register_internal_class(&ce_paginator_adapter_model TSRMLS_CC);
	zend_declare_property_null(phalcon_paginator_adapter_model_ce, SL("_limitRows"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_paginator_adapter_model_ce, SL("_config"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_paginator_adapter_model_ce, SL("_page"), ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_tag_select, "Phalcon_Tag_Select", phalcon_tag_select_functions);
	phalcon_tag_select_ce = zend_register_internal_class(&ce_tag_select TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_internal_testparent, "Phalcon_Internal_TestParent", phalcon_internal_testparent_functions);
	phalcon_internal_testparent_ce = zend_register_internal_class(&ce_internal_testparent TSRMLS_CC);
	zend_declare_property_long(phalcon_internal_testparent_ce, SL("_pp0"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_internal_testtemp, "Phalcon_Internal_TestTemp", phalcon_internal_testtemp_functions);
	phalcon_internal_testtemp_ce = zend_register_internal_class(&ce_internal_testtemp TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_internal_testdummy, "Phalcon_Internal_TestDummy", phalcon_internal_testdummy_functions);
	phalcon_internal_testdummy_ce = zend_register_internal_class(&ce_internal_testdummy TSRMLS_CC);
	zend_declare_property_null(phalcon_internal_testdummy_ce, SL("_d1"), ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_controller, "Phalcon_Controller", phalcon_controller_functions);
	phalcon_controller_ce = zend_register_internal_class(&ce_controller TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_ce, SL("dispatcher"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_ce, SL("request"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_ce, SL("response"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_ce, SL("view"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_ce, SL("model"), ZEND_ACC_PUBLIC TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_request_file, "Phalcon_Request_File", phalcon_request_file_functions);
	phalcon_request_file_ce = zend_register_internal_class(&ce_request_file TSRMLS_CC);
	zend_declare_property_null(phalcon_request_file_ce, SL("_name"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_request_file_ce, SL("_tmp"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_request_file_ce, SL("_size"), ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_paginator, "Phalcon_Paginator", phalcon_paginator_functions);
	phalcon_paginator_ce = zend_register_internal_class(&ce_paginator TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_utils, "Phalcon_Utils", phalcon_utils_functions);
	phalcon_utils_ce = zend_register_internal_class(&ce_utils TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_response_headers, "Phalcon_Response_Headers", phalcon_response_headers_functions);
	phalcon_response_headers_ce = zend_register_internal_class(&ce_response_headers TSRMLS_CC);
	zend_declare_property_null(phalcon_response_headers_ce, SL("_headers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_dispatcher, "Phalcon_Dispatcher", phalcon_dispatcher_functions);
	phalcon_dispatcher_ce = zend_register_internal_class(&ce_dispatcher TSRMLS_CC);
	zend_declare_property_null(phalcon_dispatcher_ce, SL("_finished"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_dispatcher_ce, SL("_controllers"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_dispatcher_ce, SL("_controllersDir"), "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_dispatcher_ce, SL("_basePath"), "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_dispatcher_ce, SL("_controllerName"), "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_dispatcher_ce, SL("_actionName"), "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_dispatcher_ce, SL("_params"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_dispatcher_ce, SL("_returnedValue"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_dispatcher_ce, SL("_lastController"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_dispatcher_ce, SL("_defaultController"), "index", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_dispatcher_ce, SL("_defaultAction"), "index", ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_translate, "Phalcon_Translate", phalcon_translate_functions);
	phalcon_translate_ce = zend_register_internal_class(&ce_translate TSRMLS_CC);
	zend_declare_property_null(phalcon_translate_ce, SL("_adapter"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_class_implements(phalcon_translate_ce TSRMLS_CC, 1, zend_ce_arrayaccess);

	INIT_CLASS_ENTRY(ce_db_pool, "Phalcon_Db_Pool", phalcon_db_pool_functions);
	phalcon_db_pool_ce = zend_register_internal_class(&ce_db_pool TSRMLS_CC);
	zend_declare_property_null(phalcon_db_pool_ce, SL("_connection"), ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_db_pool_ce, SL("_defaultDescriptor"), ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_db_profiler, "Phalcon_Db_Profiler", phalcon_db_profiler_functions);
	phalcon_db_profiler_ce = zend_register_internal_class(&ce_db_profiler TSRMLS_CC);
	zend_declare_property_null(phalcon_db_profiler_ce, SL("_allProfiles"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_profiler_ce, SL("_activeProfile"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_db_profiler_ce, SL("_totalSeconds"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_db_reference, "Phalcon_Db_Reference", phalcon_db_reference_functions);
	phalcon_db_reference_ce = zend_register_internal_class(&ce_db_reference TSRMLS_CC);
	zend_declare_property_null(phalcon_db_reference_ce, SL("_referenceName"), ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_db_reference_ce, SL("_referencedTable"), ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_db_reference_ce, SL("_columns"), ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_db_reference_ce, SL("_referencedColumns"), ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_db_profiler_item, "Phalcon_Db_Profiler_Item", phalcon_db_profiler_item_functions);
	phalcon_db_profiler_item_ce = zend_register_internal_class(&ce_db_profiler_item TSRMLS_CC);
	zend_declare_property_null(phalcon_db_profiler_item_ce, SL("_sqlStatement"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_profiler_item_ce, SL("_initialTime"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_profiler_item_ce, SL("_finalTime"), ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_db_rawvalue, "Phalcon_Db_RawValue", phalcon_db_rawvalue_functions);
	phalcon_db_rawvalue_ce = zend_register_internal_class(&ce_db_rawvalue TSRMLS_CC);
	zend_declare_property_null(phalcon_db_rawvalue_ce, SL("_value"), ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_db_column, "Phalcon_Db_Column", phalcon_db_column_functions);
	phalcon_db_column_ce = zend_register_internal_class(&ce_db_column TSRMLS_CC);
	zend_declare_property_null(phalcon_db_column_ce, SL("_columnName"), ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_db_column_ce, SL("_schemaName"), ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_db_column_ce, SL("_type"), ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_long(phalcon_db_column_ce, SL("_size"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_long(phalcon_db_column_ce, SL("_scale"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_column_ce, SL("_unsigned"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_column_ce, SL("_notNull"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_column_ce, SL("_autoIncrement"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_column_ce, SL("_first"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_db_column_ce, SL("_after"), ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_INTEGER"), 0 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_DATE"), 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_VARCHAR"), 2 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_DECIMAL"), 3 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_DATETIME"), 4 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_CHAR"), 5 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_TEXT"), 6 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_db_index, "Phalcon_Db_Index", phalcon_db_index_functions);
	phalcon_db_index_ce = zend_register_internal_class(&ce_db_index TSRMLS_CC);
	zend_declare_property_null(phalcon_db_index_ce, SL("_indexName"), ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_db_result_mysql, "Phalcon_Db_Result_Mysql", phalcon_db_result_mysql_functions);
	phalcon_db_result_mysql_ce = zend_register_internal_class(&ce_db_result_mysql TSRMLS_CC);
	zend_declare_property_long(phalcon_db_result_mysql_ce, SL("_fetchMode"), 3, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_result_mysql_ce, SL("_result"), ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_db_result_postgresql, "Phalcon_Db_Result_Postgresql", phalcon_db_result_postgresql_functions);
	phalcon_db_result_postgresql_ce = zend_register_internal_class(&ce_db_result_postgresql TSRMLS_CC);
	zend_declare_property_long(phalcon_db_result_postgresql_ce, SL("_fetchMode"), 3, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_result_postgresql_ce, SL("_result"), ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_db_dialect_mysql, "Phalcon_Db_Dialect_Mysql", phalcon_db_dialect_mysql_functions);
	phalcon_db_dialect_mysql_ce = zend_register_internal_class(&ce_db_dialect_mysql TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_db_dialect_postgresql, "Phalcon_Db_Dialect_Postgresql", phalcon_db_dialect_postgresql_functions);
	phalcon_db_dialect_postgresql_ce = zend_register_internal_class(&ce_db_dialect_postgresql TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_model_query, "Phalcon_Model_Query", phalcon_model_query_functions);
	phalcon_model_query_ce = zend_register_internal_class(&ce_model_query TSRMLS_CC);
	zend_declare_property_null(phalcon_model_query_ce, SL("_data"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_query_ce, SL("_manager"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_query_ce, SL("_models"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_query_ce, SL("_parameters"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_query_ce, SL("_conditions"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_query_ce, SL("_limit"), ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_model_base, "Phalcon_Model_Base", phalcon_model_base_functions);
	phalcon_model_base_ce = zend_register_internal_class(&ce_model_base TSRMLS_CC);
	zend_declare_property_bool(phalcon_model_base_ce, SL("_initialized"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_model_base_ce, SL("_uniqueKey"), "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_model_base_ce, SL("_connection"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_model_base_ce, SL("_schema"), "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_model_base_ce, SL("_source"), "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_model_base_ce, SL("_isView"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_model_base_ce, SL("_dumped"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_model_base_ce, SL("_dumpLock"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_base_ce, SL("_errorMessages"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_base_ce, SL("_operationMade"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_model_base_ce, SL("_forceExists"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_model_base_ce, SL("_defaultConnection"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_base_ce, SL("_connectionName"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_base_ce, SL("_manager"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);
	zend_declare_property_bool(phalcon_model_base_ce, SL("_disableEvents"), 0, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);
	zend_declare_property_bool(phalcon_model_base_ce, SL("_refreshPersistance"), 1, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_model_base_ce, SL("OP_CREATE"), 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_model_base_ce, SL("OP_UPDATE"), 2 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_model_base_ce, SL("OP_DELETE"), 3 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_model_validator, "Phalcon_Model_Validator", phalcon_model_validator_functions);
	phalcon_model_validator_ce = zend_register_internal_class(&ce_model_validator TSRMLS_CC);
	zend_declare_property_null(phalcon_model_validator_ce, SL("_record"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_validator_ce, SL("_fieldName"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_validator_ce, SL("_value"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_validator_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_validator_ce, SL("_messages"), ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_model_row, "Phalcon_Model_Row", phalcon_model_row_functions);
	phalcon_model_row_ce = zend_register_internal_class(&ce_model_row TSRMLS_CC);
	zend_declare_property_null(phalcon_model_row_ce, SL("_connection"), ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_model_row_ce, SL("_columns"), ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_model_sanitize, "Phalcon_Model_Sanitize", NULL);
	phalcon_model_sanitize_ce = zend_register_internal_class(&ce_model_sanitize TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_model_metadata, "Phalcon_Model_MetaData", phalcon_model_metadata_functions);
	phalcon_model_metadata_ce = zend_register_internal_class(&ce_model_metadata TSRMLS_CC);
	zend_declare_property_bool(phalcon_model_metadata_ce, SL("_changed"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_metadata_ce, SL("_metaData"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_model_metadata_ce, SL("MODELS_ATTRIBUTES"), 0 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_model_metadata_ce, SL("MODELS_PRIMARY_KEY"), 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_model_metadata_ce, SL("MODELS_NON_PRIMARY_KEY"), 2 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_model_metadata_ce, SL("MODELS_NOT_NULL"), 3 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_model_metadata_ce, SL("MODELS_DATA_TYPE"), 4 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_model_metadata_ce, SL("MODELS_DATA_TYPE_NUMERIC"), 5 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_model_metadata_ce, SL("MODELS_DATE_AT"), 6 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_model_metadata_ce, SL("MODELS_DATE_IN"), 7 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_model_metadata_ce, SL("MODELS_IDENTITY_FIELD"), 8 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_model_message, "Phalcon_Model_Message", phalcon_model_message_functions);
	phalcon_model_message_ce = zend_register_internal_class(&ce_model_message TSRMLS_CC);
	zend_declare_property_null(phalcon_model_message_ce, SL("_type"), ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_model_message_ce, SL("_message"), ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_model_manager, "Phalcon_Model_Manager", phalcon_model_manager_functions);
	phalcon_model_manager_ce = zend_register_internal_class(&ce_model_manager TSRMLS_CC);
	zend_declare_property_bool(phalcon_model_manager_ce, SL("_connection"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_manager_ce, SL("_metadata"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_manager_ce, SL("_cache"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_manager_ce, SL("_basePath"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_manager_ce, SL("_modelsDir"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_manager_ce, SL("_models"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_manager_ce, SL("_hasMany"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_manager_ce, SL("_hasOne"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_manager_ce, SL("_belongsTo"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_manager_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_manager_ce, SL("_sourceNames"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);
	zend_declare_property_null(phalcon_model_manager_ce, SL("_default"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_model_metadata_memory, "Phalcon_Model_MetaData_Memory", phalcon_model_metadata_memory_functions);
	phalcon_model_metadata_memory_ce = zend_register_internal_class(&ce_model_metadata_memory TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_model_metadata_apc, "Phalcon_Model_MetaData_Apc", phalcon_model_metadata_apc_functions);
	phalcon_model_metadata_apc_ce = zend_register_internal_class(&ce_model_metadata_apc TSRMLS_CC);
	zend_declare_property_string(phalcon_model_metadata_apc_ce, SL("_suffix"), "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_model_metadata_apc_ce, SL("_ttl"), 172800, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_model_metadata_session, "Phalcon_Model_MetaData_Session", phalcon_model_metadata_session_functions);
	phalcon_model_metadata_session_ce = zend_register_internal_class(&ce_model_metadata_session TSRMLS_CC);
	zend_declare_property_string(phalcon_model_metadata_session_ce, SL("_suffix"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_model_resultset, "Phalcon_Model_Resultset", phalcon_model_resultset_functions);
	phalcon_model_resultset_ce = zend_register_internal_class(&ce_model_resultset TSRMLS_CC);
	zend_declare_property_null(phalcon_model_resultset_ce, SL("_type"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_resultset_ce, SL("_model"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_resultset_ce, SL("_result"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_model_resultset_ce, SL("_pointer"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_resultset_ce, SL("_count"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_resultset_ce, SL("_activeRow"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_resultset_ce, SL("_rows"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_class_implements(phalcon_model_resultset_ce TSRMLS_CC, 5, zend_ce_iterator, spl_ce_SeekableIterator, spl_ce_Countable, zend_ce_arrayaccess, zend_ce_serializable);

	INIT_CLASS_ENTRY(ce_tag, "Phalcon_Tag", phalcon_tag_functions);
	phalcon_tag_ce = zend_register_internal_class(&ce_tag TSRMLS_CC);
	zend_declare_property_null(phalcon_tag_ce, SL("_displayValues"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);
	zend_declare_property_string(phalcon_tag_ce, SL("_documentTitle"), "", ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);
	zend_declare_property_null(phalcon_tag_ce, SL("_dispatcher"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_response, "Phalcon_Response", phalcon_response_functions);
	phalcon_response_ce = zend_register_internal_class(&ce_response TSRMLS_CC);
	zend_declare_property_null(phalcon_response_ce, SL("_instance"), ZEND_ACC_STATIC|ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_response_ce, SL("_content"), "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_response_ce, SL("_headers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_request, "Phalcon_Request", phalcon_request_functions);
	phalcon_request_ce = zend_register_internal_class(&ce_request TSRMLS_CC);
	zend_declare_property_null(phalcon_request_ce, SL("_filter"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_request_ce, SL("_instance"), ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_transaction_manager, "Phalcon_Transaction_Manager", phalcon_transaction_manager_functions);
	phalcon_transaction_manager_ce = zend_register_internal_class(&ce_transaction_manager TSRMLS_CC);
	zend_declare_property_bool(phalcon_transaction_manager_ce, SL("_initialized"), 0, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_long(phalcon_transaction_manager_ce, SL("_number"), 0, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_transaction_manager_ce, SL("_transactions"), ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_long(phalcon_transaction_manager_ce, SL("_dependencyPointer"), 0, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_transaction_manager_ce, SL("_automaticTransaction"), ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_controller_front, "Phalcon_Controller_Front", phalcon_controller_front_functions);
	phalcon_controller_front_ce = zend_register_internal_class(&ce_controller_front TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_ce, SL("_instance"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_ce, SL("_controllersDir"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_ce, SL("_modelsDir"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_ce, SL("_viewsDir"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_ce, SL("_basePath"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_ce, SL("_baseUri"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_ce, SL("_dispatcher"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_ce, SL("_model"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_ce, SL("_view"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_ce, SL("_request"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_ce, SL("_response"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_ce, SL("_router"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_ce, SL("_modelsConfig"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_ce, SL("_viewsConfig"), ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_session, "Phalcon_Session", phalcon_session_functions);
	phalcon_session_ce = zend_register_internal_class(&ce_session TSRMLS_CC);
	zend_declare_property_null(phalcon_session_ce, SL("_uniqueId"), ZEND_ACC_STATIC|ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_session_ce, SL("_options"), ZEND_ACC_STATIC|ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_session_ce, SL("_started"), 0, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC TSRMLS_CC);
	// _exists is not a bool so that it can be NULL meaning it hasn't been set yet.
	zend_declare_property_null(phalcon_session_ce, SL("_exists"), ZEND_ACC_STATIC|ZEND_ACC_PUBLIC TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_flash, "Phalcon_Flash", phalcon_flash_functions);
	phalcon_flash_ce = zend_register_internal_class(&ce_flash TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_config, "Phalcon_Config", phalcon_config_functions);
	phalcon_config_ce = zend_register_internal_class(&ce_config TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_filter, "Phalcon_Filter", phalcon_filter_functions);
	phalcon_filter_ce = zend_register_internal_class(&ce_filter TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_acl, "Phalcon_Acl", phalcon_acl_functions);
	phalcon_acl_ce = zend_register_internal_class(&ce_acl TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_ce, SL("_adapter"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_acl_ce, SL("ALLOW"), 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_acl_ce, SL("DENY"), 0 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_translate_adapter_array, "Phalcon_Translate_Adapter_Array", phalcon_translate_adapter_array_functions);
	phalcon_translate_adapter_array_ce = zend_register_internal_class(&ce_translate_adapter_array TSRMLS_CC);
	zend_declare_property_null(phalcon_translate_adapter_array_ce, SL("_traslate"), ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_logger_adapter_file, "Phalcon_Logger_Adapter_File", phalcon_logger_adapter_file_functions);
	phalcon_logger_adapter_file_ce = zend_register_internal_class(&ce_logger_adapter_file TSRMLS_CC);
	zend_declare_property_null(phalcon_logger_adapter_file_ce, SL("_fileHandler"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_logger_adapter_file_ce, SL("_transaction"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_logger_adapter_file_ce, SL("_quenue"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_logger_adapter_file_ce, SL("_dateFormat"), "D, d M y H:i:s O", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_logger_adapter_file_ce, SL("_format"), "[%date%][%type%] %message%", ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_logger_item, "Phalcon_Logger_Item", phalcon_logger_item_functions);
	phalcon_logger_item_ce = zend_register_internal_class(&ce_logger_item TSRMLS_CC);
	zend_declare_property_null(phalcon_logger_item_ce, SL("_type"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_logger_item_ce, SL("message"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_logger_item_ce, SL("_time"), ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_transaction, "Phalcon_Transaction", phalcon_transaction_functions);
	phalcon_transaction_ce = zend_register_internal_class(&ce_transaction TSRMLS_CC);
	zend_declare_property_null(phalcon_transaction_ce, SL("_connection"), ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_bool(phalcon_transaction_ce, SL("_activeTransaction"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_bool(phalcon_transaction_ce, SL("_isNewTransaction"), 1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_bool(phalcon_transaction_ce, SL("_rollbackOnAbort"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_transaction_ce, SL("_manager"), ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_long(phalcon_transaction_ce, SL("_pointer"), 255, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_transaction_ce, SL("_dependencies"), ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_transaction_ce, SL("_messages"), ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_transaction_ce, SL("_rollbackRecord"), ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_exception, "Phalcon_Exception", NULL);
	phalcon_exception_ce = zend_register_internal_class_ex(&ce_exception, NULL, "exception" TSRMLS_CC);
	if(!phalcon_exception_ce){
		phalcon_inherit_not_found("Exception", "Phalcon_Exception");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce_config_exception, "Phalcon_Config_Exception", NULL);
	phalcon_config_exception_ce = zend_register_internal_class_ex(&ce_config_exception, NULL, "phalcon_exception" TSRMLS_CC);
	if(!phalcon_config_exception_ce){
		phalcon_inherit_not_found("Phalcon_Exception", "Phalcon_Config_Exception");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce_config_adapter_ini, "Phalcon_Config_Adapter_Ini", phalcon_config_adapter_ini_functions);
	phalcon_config_adapter_ini_ce = zend_register_internal_class_ex(&ce_config_adapter_ini, NULL, "phalcon_config" TSRMLS_CC);
	if(!phalcon_config_adapter_ini_ce){
		phalcon_inherit_not_found("Phalcon_Config", "Phalcon_Config_Adapter_Ini");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce_cache_exception, "Phalcon_Cache_Exception", NULL);
	phalcon_cache_exception_ce = zend_register_internal_class_ex(&ce_cache_exception, NULL, "phalcon_exception" TSRMLS_CC);
	if(!phalcon_cache_exception_ce){
		phalcon_inherit_not_found("Phalcon_Exception", "Phalcon_Cache_Exception");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce_cache_backend_memcache, "Phalcon_Cache_Backend_Memcache", phalcon_cache_backend_memcache_functions);
	phalcon_cache_backend_memcache_ce = zend_register_internal_class_ex(&ce_cache_backend_memcache, NULL, "phalcon_cache_backend" TSRMLS_CC);
	if(!phalcon_cache_backend_memcache_ce){
		phalcon_inherit_not_found("Phalcon_Cache_Backend", "Phalcon_Cache_Backend_Memcache");
		return FAILURE;
	}
	zend_declare_property_null(phalcon_cache_backend_memcache_ce, SL("_memcache"), ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_cache_backend_apc, "Phalcon_Cache_Backend_Apc", phalcon_cache_backend_apc_functions);
	phalcon_cache_backend_apc_ce = zend_register_internal_class_ex(&ce_cache_backend_apc, NULL, "phalcon_cache_backend" TSRMLS_CC);
	if(!phalcon_cache_backend_apc_ce){
		phalcon_inherit_not_found("Phalcon_Cache_Backend", "Phalcon_Cache_Backend_Apc");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce_cache_backend_file, "Phalcon_Cache_Backend_File", phalcon_cache_backend_file_functions);
	phalcon_cache_backend_file_ce = zend_register_internal_class_ex(&ce_cache_backend_file, NULL, "phalcon_cache_backend" TSRMLS_CC);
	if(!phalcon_cache_backend_file_ce){
		phalcon_inherit_not_found("Phalcon_Cache_Backend", "Phalcon_Cache_Backend_File");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce_acl_exception, "Phalcon_Acl_Exception", NULL);
	phalcon_acl_exception_ce = zend_register_internal_class_ex(&ce_acl_exception, NULL, "phalcon_exception" TSRMLS_CC);
	if(!phalcon_acl_exception_ce){
		phalcon_inherit_not_found("Phalcon_Exception", "Phalcon_Acl_Exception");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce_dispatcher_exception, "Phalcon_Dispatcher_Exception", NULL);
	phalcon_dispatcher_exception_ce = zend_register_internal_class_ex(&ce_dispatcher_exception, NULL, "phalcon_exception" TSRMLS_CC);
	if(!phalcon_dispatcher_exception_ce){
		phalcon_inherit_not_found("Phalcon_Exception", "Phalcon_Dispatcher_Exception");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce_view_exception, "Phalcon_View_Exception", NULL);
	phalcon_view_exception_ce = zend_register_internal_class_ex(&ce_view_exception, NULL, "phalcon_exception" TSRMLS_CC);
	if(!phalcon_view_exception_ce){
		phalcon_inherit_not_found("Phalcon_Exception", "Phalcon_View_Exception");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce_view_engine_php, "Phalcon_View_Engine_Php", phalcon_view_engine_php_functions);
	phalcon_view_engine_php_ce = zend_register_internal_class_ex(&ce_view_engine_php, NULL, "phalcon_view_engine" TSRMLS_CC);
	if(!phalcon_view_engine_php_ce){
		phalcon_inherit_not_found("Phalcon_View_Engine", "Phalcon_View_Engine_Php");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce_view_engine_twig, "Phalcon_View_Engine_Twig", phalcon_view_engine_twig_functions);
	phalcon_view_engine_twig_ce = zend_register_internal_class_ex(&ce_view_engine_twig, NULL, "phalcon_view_engine" TSRMLS_CC);
	if(!phalcon_view_engine_twig_ce){
		phalcon_inherit_not_found("Phalcon_View_Engine", "Phalcon_View_Engine_Twig");
		return FAILURE;
	}
	zend_declare_property_null(phalcon_view_engine_twig_ce, SL("_twig"), ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_view_engine_mustache, "Phalcon_View_Engine_Mustache", phalcon_view_engine_mustache_functions);
	phalcon_view_engine_mustache_ce = zend_register_internal_class_ex(&ce_view_engine_mustache, NULL, "phalcon_view_engine" TSRMLS_CC);
	if(!phalcon_view_engine_mustache_ce){
		phalcon_inherit_not_found("Phalcon_View_Engine", "Phalcon_View_Engine_Mustache");
		return FAILURE;
	}
	zend_declare_property_null(phalcon_view_engine_mustache_ce, SL("_mustache"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_view_engine_mustache_ce, SL("_params"), ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_paginator_exception, "Phalcon_Paginator_Exception", NULL);
	phalcon_paginator_exception_ce = zend_register_internal_class_ex(&ce_paginator_exception, NULL, "phalcon_exception" TSRMLS_CC);
	if(!phalcon_paginator_exception_ce){
		phalcon_inherit_not_found("Phalcon_Exception", "Phalcon_Paginator_Exception");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce_tag_exception, "Phalcon_Tag_Exception", NULL);
	phalcon_tag_exception_ce = zend_register_internal_class_ex(&ce_tag_exception, NULL, "phalcon_exception" TSRMLS_CC);
	if(!phalcon_tag_exception_ce){
		phalcon_inherit_not_found("Phalcon_Exception", "Phalcon_Tag_Exception");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce_internal_test, "Phalcon_Internal_Test", phalcon_internal_test_functions);
	phalcon_internal_test_ce = zend_register_internal_class_ex(&ce_internal_test, NULL, "phalcon_internal_testparent" TSRMLS_CC);
	if(!phalcon_internal_test_ce){
		phalcon_inherit_not_found("Phalcon_Internal_TestParent", "Phalcon_Internal_Test");
		return FAILURE;
	}
	zend_declare_property_null(phalcon_internal_test_ce, SL("_p0"), ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_internal_test_ce, SL("_p1"), ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_string(phalcon_internal_test_ce, SL("_p2"), "str", ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_double(phalcon_internal_test_ce, SL("_p3"), 4.12, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_bool(phalcon_internal_test_ce, SL("_p4"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_internal_test_ce, SL("_p5"), 1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_string(phalcon_internal_test_ce, SL("_p6"), "12.01", ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_long(phalcon_internal_test_ce, SL("_p7"), 128, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_internal_test_ce, SL("_p8"), ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_internal_test_ce, SL("_p9"), ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_internal_test_ce, SL("_sp0"), ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_string(phalcon_internal_test_ce, SL("_sp1"), "hello", ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_internal_test_ce, SL("_sp2"), ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_string(phalcon_internal_test_ce, SL("_sp3"), "11.20", ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_long(phalcon_internal_test_ce, SL("_sp4"), 128, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_bool(phalcon_internal_test_ce, SL("_sp5"), 0, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_bool(phalcon_internal_test_ce, SL("_sp6"), 1, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_double(phalcon_internal_test_ce, SL("_sp7"), 3.1415, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_internal_test_ce, SL("C1"), 0 TSRMLS_CC);
	zend_declare_class_constant_double(phalcon_internal_test_ce, SL("C2"), 2.1 TSRMLS_CC);
	zend_declare_class_constant_bool(phalcon_internal_test_ce, SL("C3"), 0 TSRMLS_CC);
	zend_declare_class_constant_bool(phalcon_internal_test_ce, SL("C4"), 1 TSRMLS_CC);
	zend_declare_class_constant_null(phalcon_internal_test_ce, SL("C5") TSRMLS_CC);
	zend_declare_class_constant_string(phalcon_internal_test_ce, SL("C6"), "str" TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_internal_test_ce, SL("C7"), -92 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_request_exception, "Phalcon_Request_Exception", NULL);
	phalcon_request_exception_ce = zend_register_internal_class_ex(&ce_request_exception, NULL, "phalcon_exception" TSRMLS_CC);
	if(!phalcon_request_exception_ce){
		phalcon_inherit_not_found("Phalcon_Exception", "Phalcon_Request_Exception");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce_response_exception, "Phalcon_Response_Exception", NULL);
	phalcon_response_exception_ce = zend_register_internal_class_ex(&ce_response_exception, NULL, "phalcon_exception" TSRMLS_CC);
	if(!phalcon_response_exception_ce){
		phalcon_inherit_not_found("Phalcon_Exception", "Phalcon_Response_Exception");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce_db_exception, "Phalcon_Db_Exception", NULL);
	phalcon_db_exception_ce = zend_register_internal_class_ex(&ce_db_exception, NULL, "phalcon_exception" TSRMLS_CC);
	if(!phalcon_db_exception_ce){
		phalcon_inherit_not_found("Phalcon_Exception", "Phalcon_Db_Exception");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce_db_adapter_mysql, "Phalcon_Db_Adapter_Mysql", phalcon_db_adapter_mysql_functions);
	phalcon_db_adapter_mysql_ce = zend_register_internal_class_ex(&ce_db_adapter_mysql, NULL, "phalcon_db" TSRMLS_CC);
	if(!phalcon_db_adapter_mysql_ce){
		phalcon_inherit_not_found("Phalcon_Db", "Phalcon_Db_Adapter_Mysql");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce_db_adapter_postgresql, "Phalcon_Db_Adapter_Postgresql", phalcon_db_adapter_postgresql_functions);
	phalcon_db_adapter_postgresql_ce = zend_register_internal_class_ex(&ce_db_adapter_postgresql, NULL, "phalcon_db" TSRMLS_CC);
	if(!phalcon_db_adapter_postgresql_ce){
		phalcon_inherit_not_found("Phalcon_Db", "Phalcon_Db_Adapter_Postgresql");
		return FAILURE;
	}
	zend_declare_property_null(phalcon_db_adapter_postgresql_ce, SL("_lastResultset"), ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_model_validator_uniqueness, "Phalcon_Model_Validator_Uniqueness", phalcon_model_validator_uniqueness_functions);
	phalcon_model_validator_uniqueness_ce = zend_register_internal_class_ex(&ce_model_validator_uniqueness, NULL, "phalcon_model_validator" TSRMLS_CC);
	if(!phalcon_model_validator_uniqueness_ce){
		phalcon_inherit_not_found("Phalcon_Model_Validator", "Phalcon_Model_Validator_Uniqueness");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce_model_validator_exclusionin, "Phalcon_Model_Validator_Exclusionin", phalcon_model_validator_exclusionin_functions);
	phalcon_model_validator_exclusionin_ce = zend_register_internal_class_ex(&ce_model_validator_exclusionin, NULL, "phalcon_model_validator" TSRMLS_CC);
	if(!phalcon_model_validator_exclusionin_ce){
		phalcon_inherit_not_found("Phalcon_Model_Validator", "Phalcon_Model_Validator_Exclusionin");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce_model_validator_regex, "Phalcon_Model_Validator_Regex", phalcon_model_validator_regex_functions);
	phalcon_model_validator_regex_ce = zend_register_internal_class_ex(&ce_model_validator_regex, NULL, "phalcon_model_validator" TSRMLS_CC);
	if(!phalcon_model_validator_regex_ce){
		phalcon_inherit_not_found("Phalcon_Model_Validator", "Phalcon_Model_Validator_Regex");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce_model_validator_inclusionin, "Phalcon_Model_Validator_Inclusionin", phalcon_model_validator_inclusionin_functions);
	phalcon_model_validator_inclusionin_ce = zend_register_internal_class_ex(&ce_model_validator_inclusionin, NULL, "phalcon_model_validator" TSRMLS_CC);
	if(!phalcon_model_validator_inclusionin_ce){
		phalcon_inherit_not_found("Phalcon_Model_Validator", "Phalcon_Model_Validator_Inclusionin");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce_model_validator_numericality, "Phalcon_Model_Validator_Numericality", phalcon_model_validator_numericality_functions);
	phalcon_model_validator_numericality_ce = zend_register_internal_class_ex(&ce_model_validator_numericality, NULL, "phalcon_model_validator" TSRMLS_CC);
	if(!phalcon_model_validator_numericality_ce){
		phalcon_inherit_not_found("Phalcon_Model_Validator", "Phalcon_Model_Validator_Numericality");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce_model_validator_email, "Phalcon_Model_Validator_Email", phalcon_model_validator_email_functions);
	phalcon_model_validator_email_ce = zend_register_internal_class_ex(&ce_model_validator_email, NULL, "phalcon_model_validator" TSRMLS_CC);
	if(!phalcon_model_validator_email_ce){
		phalcon_inherit_not_found("Phalcon_Model_Validator", "Phalcon_Model_Validator_Email");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce_model_exception, "Phalcon_Model_Exception", NULL);
	phalcon_model_exception_ce = zend_register_internal_class_ex(&ce_model_exception, NULL, "phalcon_exception" TSRMLS_CC);
	if(!phalcon_model_exception_ce){
		phalcon_inherit_not_found("Phalcon_Exception", "Phalcon_Model_Exception");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce_transaction_failed, "Phalcon_Transaction_Failed", phalcon_transaction_failed_functions);
	phalcon_transaction_failed_ce = zend_register_internal_class_ex(&ce_transaction_failed, NULL, "exception" TSRMLS_CC);
	if(!phalcon_transaction_failed_ce){
		phalcon_inherit_not_found("Exception", "Phalcon_Transaction_Failed");
		return FAILURE;
	}
	zend_declare_property_null(phalcon_transaction_failed_ce, SL("_record"), ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce_translate_exception, "Phalcon_Translate_Exception", NULL);
	phalcon_translate_exception_ce = zend_register_internal_class_ex(&ce_translate_exception, NULL, "phalcon_exception" TSRMLS_CC);
	if(!phalcon_translate_exception_ce){
		phalcon_inherit_not_found("Phalcon_Exception", "Phalcon_Translate_Exception");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce_logger_exception, "Phalcon_Logger_Exception", NULL);
	phalcon_logger_exception_ce = zend_register_internal_class_ex(&ce_logger_exception, NULL, "phalcon_exception" TSRMLS_CC);
	if(!phalcon_logger_exception_ce){
		phalcon_inherit_not_found("Phalcon_Exception", "Phalcon_Logger_Exception");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce_loader_exception, "Phalcon_Loader_Exception", NULL);
	phalcon_loader_exception_ce = zend_register_internal_class_ex(&ce_loader_exception, NULL, "phalcon_exception" TSRMLS_CC);
	if(!phalcon_loader_exception_ce){
		phalcon_inherit_not_found("Phalcon_Exception", "Phalcon_Loader_Exception");
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

