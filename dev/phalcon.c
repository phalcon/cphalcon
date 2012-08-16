
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
zend_class_entry *phalcon_di_ce;
zend_class_entry *phalcon_text_ce;
zend_class_entry *phalcon_mvc_router_ce;
zend_class_entry *phalcon_mvc_dispatcher_exception_ce;
zend_class_entry *phalcon_mvc_view_ce;
zend_class_entry *phalcon_mvc_view_engine_ce;
zend_class_entry *phalcon_mvc_view_exception_ce;
zend_class_entry *phalcon_mvc_view_engine_php_ce;
zend_class_entry *phalcon_mvc_view_engine_twig_ce;
zend_class_entry *phalcon_mvc_view_engine_mustache_ce;
zend_class_entry *phalcon_mvc_url_ce;
zend_class_entry *phalcon_mvc_controller_ce;
zend_class_entry *phalcon_mvc_application_exception_ce;
zend_class_entry *phalcon_mvc_dispatcher_ce;
zend_class_entry *phalcon_mvc_model_ce;
zend_class_entry *phalcon_mvc_model_validator_uniqueness_ce;
zend_class_entry *phalcon_mvc_model_validator_exclusionin_ce;
zend_class_entry *phalcon_mvc_model_validator_regex_ce;
zend_class_entry *phalcon_mvc_model_validator_inclusionin_ce;
zend_class_entry *phalcon_mvc_model_validator_numericality_ce;
zend_class_entry *phalcon_mvc_model_validator_email_ce;
zend_class_entry *phalcon_mvc_model_query_ce;
zend_class_entry *phalcon_mvc_model_query_lang_ce;
zend_class_entry *phalcon_mvc_model_exception_ce;
zend_class_entry *phalcon_mvc_model_validator_ce;
zend_class_entry *phalcon_mvc_model_row_ce;
zend_class_entry *phalcon_mvc_model_transaction_exception_ce;
zend_class_entry *phalcon_mvc_model_transaction_failed_ce;
zend_class_entry *phalcon_mvc_model_transaction_manager_ce;
zend_class_entry *phalcon_mvc_model_metadata_ce;
zend_class_entry *phalcon_mvc_model_message_ce;
zend_class_entry *phalcon_mvc_model_manager_ce;
zend_class_entry *phalcon_mvc_model_metadata_memory_ce;
zend_class_entry *phalcon_mvc_model_metadata_apc_ce;
zend_class_entry *phalcon_mvc_model_metadata_session_ce;
zend_class_entry *phalcon_mvc_model_resultset_ce;
zend_class_entry *phalcon_mvc_model_transaction_ce;
zend_class_entry *phalcon_mvc_application_ce;
zend_class_entry *phalcon_test_ce;
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
zend_class_entry *phalcon_registry_ce;
zend_class_entry *phalcon_paginator_exception_ce;
zend_class_entry *phalcon_paginator_adapter_array_ce;
zend_class_entry *phalcon_paginator_adapter_model_ce;
zend_class_entry *phalcon_tag_exception_ce;
zend_class_entry *phalcon_tag_select_ce;
zend_class_entry *phalcon_internal_test_ce;
zend_class_entry *phalcon_internal_testparent_ce;
zend_class_entry *phalcon_internal_testtemp_ce;
zend_class_entry *phalcon_internal_testdummy_ce;
zend_class_entry *phalcon_paginator_ce;
zend_class_entry *phalcon_translate_ce;
zend_class_entry *phalcon_db_profiler_ce;
zend_class_entry *phalcon_db_exception_ce;
zend_class_entry *phalcon_db_reference_ce;
zend_class_entry *phalcon_db_dialect_ce;
zend_class_entry *phalcon_db_adapter_pdo_mysql_ce;
zend_class_entry *phalcon_db_adapter_pdo_postgresql_ce;
zend_class_entry *phalcon_db_adapter_pdo_ce;
zend_class_entry *phalcon_db_profiler_item_ce;
zend_class_entry *phalcon_db_rawvalue_ce;
zend_class_entry *phalcon_db_column_ce;
zend_class_entry *phalcon_db_index_ce;
zend_class_entry *phalcon_db_result_pdo_ce;
zend_class_entry *phalcon_db_dialect_mysql_ce;
zend_class_entry *phalcon_db_dialect_postgresql_ce;
zend_class_entry *phalcon_tag_ce;
zend_class_entry *phalcon_http_request_exception_ce;
zend_class_entry *phalcon_http_request_file_ce;
zend_class_entry *phalcon_http_response_exception_ce;
zend_class_entry *phalcon_http_response_headers_ce;
zend_class_entry *phalcon_http_response_ce;
zend_class_entry *phalcon_http_request_ce;
zend_class_entry *phalcon_session_ce;
zend_class_entry *phalcon_flash_ce;
zend_class_entry *phalcon_config_ce;
zend_class_entry *phalcon_filter_ce;
zend_class_entry *phalcon_di_exception_ce;
zend_class_entry *phalcon_events_event_ce;
zend_class_entry *phalcon_events_exception_ce;
zend_class_entry *phalcon_events_manager_ce;
zend_class_entry *phalcon_acl_ce;
zend_class_entry *phalcon_translate_exception_ce;
zend_class_entry *phalcon_translate_adapter_array_ce;
zend_class_entry *phalcon_logger_exception_ce;
zend_class_entry *phalcon_logger_adapter_file_ce;
zend_class_entry *phalcon_logger_item_ce;
zend_class_entry *phalcon_loader_exception_ce;

ZEND_DECLARE_MODULE_GLOBALS(phalcon)

PHP_MINIT_FUNCTION(phalcon){


	if(!zend_ce_serializable){
		fprintf(stderr, "Phalcon Error: Interface Serializable was not found");
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
	if(!zend_ce_arrayaccess){
		fprintf(stderr, "Phalcon Error: Interface ArrayAccess was not found");
		return FAILURE;
	}

	/** Init globals */
	ZEND_INIT_MODULE_GLOBALS(phalcon, php_phalcon_init_globals, NULL);

	PHALCON_REGISTER_CLASS(Phalcon\\Session, Namespace, session_namespace, phalcon_session_namespace_method_entry, 0);
	zend_declare_property_null(phalcon_session_namespace_ce, SL("_name"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_session_namespace_ce, SL("_data"), ZEND_ACC_PROTECTED TSRMLS_CC);

	PHALCON_REGISTER_CLASS(Phalcon, Loader, loader, phalcon_loader_method_entry, 0);
	zend_declare_property_null(phalcon_loader_ce, SL("_eventsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_loader_ce, SL("_foundPath"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_loader_ce, SL("_checkedPath"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_loader_ce, SL("_classes"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_loader_ce, SL("_extensions"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_loader_ce, SL("_namespaces"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_loader_ce, SL("_directories"), ZEND_ACC_PROTECTED TSRMLS_CC);

	PHALCON_REGISTER_CLASS(Phalcon, DI, di, phalcon_di_method_entry, 0);
	zend_declare_property_null(phalcon_di_ce, SL("_services"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_di_ce, SL("_sharedInstances"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_di_ce, SL("_freshInstance"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_di_ce, SL("_default"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	PHALCON_REGISTER_CLASS(Phalcon, Text, text, phalcon_text_method_entry, 0);

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc, Router, mvc_router, phalcon_mvc_router_method_entry, 0);
	zend_declare_property_null(phalcon_mvc_router_ce, SL("_module"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_ce, SL("_controller"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_ce, SL("_action"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_ce, SL("_params"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_ce, SL("_baseUri"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_ce, SL("_routes"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_ce, SL("_currentRoute"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_ce, SL("_matches"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_mvc_router_ce, SL("_wasMatched"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_ce, SL("_defaultModule"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_ce, SL("_defaultController"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_router_ce, SL("_defaultAction"), ZEND_ACC_PROTECTED TSRMLS_CC);

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc, View, mvc_view, phalcon_mvc_view_method_entry, 0);
	zend_declare_property_null(phalcon_mvc_view_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_mvc_view_ce, SL("_basePath"), "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_mvc_view_ce, SL("_content"), "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_mvc_view_ce, SL("_renderLevel"), 5, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_ce, SL("_viewParams"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_mvc_view_ce, SL("_layoutsDir"), "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_ce, SL("_templatesBefore"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_ce, SL("_templatesAfter"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_mvc_view_ce, SL("_engines"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_ce, SL("_registeredEngines"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_mvc_view_ce, SL("_mainView"), "index", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_ce, SL("_controllerName"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_ce, SL("_actionName"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_ce, SL("_params"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_ce, SL("_pickView"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_ce, SL("_cache"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_mvc_view_ce, SL("_cacheLevel"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_view_ce, SL("LEVEL_MAIN_LAYOUT"), 5 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_view_ce, SL("LEVEL_AFTER_TEMPLATE"), 4 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_view_ce, SL("LEVEL_LAYOUT"), 3 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_view_ce, SL("LEVEL_BEFORE_TEMPLATE"), 2 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_view_ce, SL("LEVEL_ACTION_VIEW"), 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_view_ce, SL("LEVEL_NO_RENDER"), 0 TSRMLS_CC);

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc\\View, Engine, mvc_view_engine, phalcon_mvc_view_engine_method_entry, 0);
	zend_declare_property_null(phalcon_mvc_view_engine_ce, SL("_view"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_engine_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc, Url, mvc_url, phalcon_mvc_url_method_entry, 0);
	zend_declare_property_null(phalcon_mvc_url_ce, SL("_baseUri"), ZEND_ACC_PROTECTED TSRMLS_CC);

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc, Controller, mvc_controller, phalcon_mvc_controller_method_entry, 0);
	zend_declare_property_null(phalcon_mvc_controller_ce, SL("di"), ZEND_ACC_PROTECTED TSRMLS_CC);

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc, Dispatcher, mvc_dispatcher, phalcon_mvc_dispatcher_method_entry, 0);
	zend_declare_property_null(phalcon_mvc_dispatcher_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_dispatcher_ce, SL("_eventManager"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_dispatcher_ce, SL("_finished"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_mvc_dispatcher_ce, SL("_controllerName"), "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_mvc_dispatcher_ce, SL("_actionName"), "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_dispatcher_ce, SL("_params"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_dispatcher_ce, SL("_returnedValue"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_dispatcher_ce, SL("_lastController"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_mvc_dispatcher_ce, SL("_defaultNamespace"), "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_mvc_dispatcher_ce, SL("_defaultController"), "index", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_mvc_dispatcher_ce, SL("_defaultAction"), "index", ZEND_ACC_PROTECTED TSRMLS_CC);

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc, Model, mvc_model, phalcon_mvc_model_method_entry, ZEND_ACC_ABSTRACT);
	zend_declare_property_null(phalcon_mvc_model_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_ce, SL("_uniqueKey"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_ce, SL("_schema"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_ce, SL("_source"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_mvc_model_ce, SL("_dumped"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_ce, SL("_errorMessages"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_ce, SL("_operationMade"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_mvc_model_ce, SL("_forceExists"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_mvc_model_ce, SL("_connectionService"), "db", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_mvc_model_ce, SL("_disableEvents"), 0, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);
	zend_declare_property_bool(phalcon_mvc_model_ce, SL("_refreshPersistance"), 1, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_ce, SL("OP_CREATE"), 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_ce, SL("OP_UPDATE"), 2 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_ce, SL("OP_DELETE"), 3 TSRMLS_CC);
	zend_class_implements(phalcon_mvc_model_ce TSRMLS_CC, 1, zend_ce_serializable);

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc\\Model, Query, mvc_model_query, phalcon_mvc_model_query_method_entry, 0);
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_data"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_manager"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_models"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_parameters"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_conditions"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("_limit"), ZEND_ACC_PROTECTED TSRMLS_CC);

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc\\Model\\Query, Lang, mvc_model_query_lang, phalcon_mvc_model_query_lang_method_entry, 0);

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc\\Model, Validator, mvc_model_validator, phalcon_mvc_model_validator_method_entry, ZEND_ACC_ABSTRACT);
	zend_declare_property_null(phalcon_mvc_model_validator_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_validator_ce, SL("_messages"), ZEND_ACC_PROTECTED TSRMLS_CC);

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc\\Model, Row, mvc_model_row, phalcon_mvc_model_row_method_entry, 0);
	zend_declare_property_null(phalcon_mvc_model_row_ce, SL("_columns"), ZEND_ACC_PROTECTED TSRMLS_CC);

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc\\Model\\Transaction, Manager, mvc_model_transaction_manager, phalcon_mvc_model_transaction_manager_method_entry, 0);
	zend_declare_property_bool(phalcon_mvc_model_transaction_manager_ce, SL("_initialized"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_mvc_model_transaction_manager_ce, SL("_number"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_transaction_manager_ce, SL("_transactions"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_mvc_model_transaction_manager_ce, SL("_dependencyPointer"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_transaction_manager_ce, SL("_automaticTransaction"), ZEND_ACC_PROTECTED TSRMLS_CC);

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc\\Model, MetaData, mvc_model_metadata, phalcon_mvc_model_metadata_method_entry, 0);
	zend_declare_property_bool(phalcon_mvc_model_metadata_ce, SL("_changed"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_metadata_ce, SL("_metaData"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_metadata_ce, SL("MODELS_ATTRIBUTES"), 0 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_metadata_ce, SL("MODELS_PRIMARY_KEY"), 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_metadata_ce, SL("MODELS_NON_PRIMARY_KEY"), 2 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_metadata_ce, SL("MODELS_NOT_NULL"), 3 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_metadata_ce, SL("MODELS_DATA_TYPE"), 4 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_metadata_ce, SL("MODELS_DATA_TYPE_NUMERIC"), 5 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_metadata_ce, SL("MODELS_DATE_AT"), 6 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_metadata_ce, SL("MODELS_DATE_IN"), 7 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_metadata_ce, SL("MODELS_IDENTITY_FIELD"), 8 TSRMLS_CC);

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc\\Model, Message, mvc_model_message, phalcon_mvc_model_message_method_entry, 0);
	zend_declare_property_null(phalcon_mvc_model_message_ce, SL("_type"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_message_ce, SL("_message"), ZEND_ACC_PROTECTED TSRMLS_CC);

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc\\Model, Manager, mvc_model_manager, phalcon_mvc_model_manager_method_entry, 0);
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_eventManager"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_hasMany"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_hasOne"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_belongsTo"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_initialized"), ZEND_ACC_PROTECTED TSRMLS_CC);

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc\\Model, Resultset, mvc_model_resultset, phalcon_mvc_model_resultset_method_entry, 0);
	zend_declare_property_null(phalcon_mvc_model_resultset_ce, SL("_type"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_resultset_ce, SL("_model"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_resultset_ce, SL("_result"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_resultset_ce, SL("_cache"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_mvc_model_resultset_ce, SL("_pointer"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_resultset_ce, SL("_count"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_resultset_ce, SL("_activeRow"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_resultset_ce, SL("_rows"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_class_implements(phalcon_mvc_model_resultset_ce TSRMLS_CC, 5, zend_ce_iterator, spl_ce_SeekableIterator, spl_ce_Countable, zend_ce_arrayaccess, zend_ce_serializable);

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc\\Model, Transaction, mvc_model_transaction, phalcon_mvc_model_transaction_method_entry, 0);
	zend_declare_property_null(phalcon_mvc_model_transaction_ce, SL("_connection"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_mvc_model_transaction_ce, SL("_activeTransaction"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_mvc_model_transaction_ce, SL("_isNewTransaction"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_mvc_model_transaction_ce, SL("_rollbackOnAbort"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_transaction_ce, SL("_manager"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_mvc_model_transaction_ce, SL("_pointer"), 255, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_transaction_ce, SL("_dependencies"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_transaction_ce, SL("_messages"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_transaction_ce, SL("_rollbackRecord"), ZEND_ACC_PROTECTED TSRMLS_CC);

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc, Application, mvc_application, phalcon_mvc_application_method_entry, 0);
	zend_declare_property_null(phalcon_mvc_application_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_application_ce, SL("_modules"), ZEND_ACC_PROTECTED TSRMLS_CC);

	PHALCON_REGISTER_CLASS(Phalcon, Test, test, phalcon_test_method_entry, 0);

	PHALCON_REGISTER_CLASS(Phalcon, Db, db, phalcon_db_method_entry, ZEND_ACC_ABSTRACT);
	zend_declare_property_null(phalcon_db_ce, SL("_eventsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_ce, SL("_descriptor"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_ce, SL("_connectionId"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_ce, SL("_sqlStatement"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_db_ce, SL("_connectionConsecutive"), 0, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_ce, SL("FETCH_ASSOC"), 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_ce, SL("FETCH_BOTH"), 2 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_ce, SL("FETCH_NUM"), 3 TSRMLS_CC);

	PHALCON_REGISTER_CLASS(Phalcon, Logger, logger, phalcon_logger_method_entry, ZEND_ACC_ABSTRACT);
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

	PHALCON_REGISTER_CLASS(Phalcon\\Cache\\Frontend, Output, cache_frontend_output, phalcon_cache_frontend_output_method_entry, 0);
	zend_declare_property_bool(phalcon_cache_frontend_output_ce, SL("_buffering"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_cache_frontend_output_ce, SL("_frontendOptions"), ZEND_ACC_PROTECTED TSRMLS_CC);

	PHALCON_REGISTER_CLASS(Phalcon\\Cache\\Frontend, None, cache_frontend_none, phalcon_cache_frontend_none_method_entry, 0);

	PHALCON_REGISTER_CLASS(Phalcon\\Cache\\Frontend, Data, cache_frontend_data, phalcon_cache_frontend_data_method_entry, 0);
	zend_declare_property_null(phalcon_cache_frontend_data_ce, SL("_frontendOptions"), ZEND_ACC_PROTECTED TSRMLS_CC);

	PHALCON_REGISTER_CLASS(Phalcon\\Cache, Backend, cache_backend, phalcon_cache_backend_method_entry, ZEND_ACC_ABSTRACT);
	zend_declare_property_null(phalcon_cache_backend_ce, SL("_frontendObject"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_cache_backend_ce, SL("_backendOptions"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_cache_backend_ce, SL("_prefix"), "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_cache_backend_ce, SL("_lastKey"), "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_cache_backend_ce, SL("_fresh"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_cache_backend_ce, SL("_started"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	PHALCON_REGISTER_CLASS(Phalcon\\Acl\\Adapter, Memory, acl_adapter_memory, phalcon_acl_adapter_memory_method_entry, 0);
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_rolesNames"), ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_roles"), ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_resources"), ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_access"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_roleInherits"), ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_resourcesNames"), ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_accessList"), ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_long(phalcon_acl_adapter_memory_ce, SL("_defaultAccess"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	PHALCON_REGISTER_CLASS(Phalcon\\Acl, Role, acl_role, phalcon_acl_role_method_entry, 0);
	zend_declare_property_null(phalcon_acl_role_ce, SL("_name"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_role_ce, SL("_description"), ZEND_ACC_PROTECTED TSRMLS_CC);

	PHALCON_REGISTER_CLASS(Phalcon\\Acl, Resource, acl_resource, phalcon_acl_resource_method_entry, 0);
	zend_declare_property_null(phalcon_acl_resource_ce, SL("_name"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_resource_ce, SL("_description"), ZEND_ACC_PROTECTED TSRMLS_CC);

	PHALCON_REGISTER_CLASS(Phalcon, Registry, registry, phalcon_registry_method_entry, 0);

	PHALCON_REGISTER_CLASS(Phalcon\\Paginator\\Adapter, Array, paginator_adapter_array, phalcon_paginator_adapter_array_method_entry, 0);
	zend_declare_property_null(phalcon_paginator_adapter_array_ce, SL("_limitRows"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_paginator_adapter_array_ce, SL("_config"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_paginator_adapter_array_ce, SL("_page"), ZEND_ACC_PROTECTED TSRMLS_CC);

	PHALCON_REGISTER_CLASS(Phalcon\\Paginator\\Adapter, Model, paginator_adapter_model, phalcon_paginator_adapter_model_method_entry, 0);
	zend_declare_property_null(phalcon_paginator_adapter_model_ce, SL("_limitRows"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_paginator_adapter_model_ce, SL("_config"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_paginator_adapter_model_ce, SL("_page"), ZEND_ACC_PROTECTED TSRMLS_CC);

	PHALCON_REGISTER_CLASS(Phalcon\\Tag, Select, tag_select, phalcon_tag_select_method_entry, ZEND_ACC_ABSTRACT);

	PHALCON_REGISTER_CLASS(Phalcon\\Internal, TestParent, internal_testparent, phalcon_internal_testparent_method_entry, 0);
	zend_declare_property_long(phalcon_internal_testparent_ce, SL("_pp0"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);

	PHALCON_REGISTER_CLASS(Phalcon\\Internal, TestTemp, internal_testtemp, phalcon_internal_testtemp_method_entry, 0);

	PHALCON_REGISTER_CLASS(Phalcon\\Internal, TestDummy, internal_testdummy, phalcon_internal_testdummy_method_entry, 0);
	zend_declare_property_null(phalcon_internal_testdummy_ce, SL("_d1"), ZEND_ACC_PRIVATE TSRMLS_CC);

	PHALCON_REGISTER_CLASS(Phalcon, Paginator, paginator, phalcon_paginator_method_entry, ZEND_ACC_ABSTRACT);

	PHALCON_REGISTER_CLASS(Phalcon, Translate, translate, phalcon_translate_method_entry, ZEND_ACC_ABSTRACT);
	zend_class_implements(phalcon_translate_ce TSRMLS_CC, 1, zend_ce_arrayaccess);

	PHALCON_REGISTER_CLASS(Phalcon\\Db, Profiler, db_profiler, phalcon_db_profiler_method_entry, 0);
	zend_declare_property_null(phalcon_db_profiler_ce, SL("_allProfiles"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_profiler_ce, SL("_activeProfile"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_db_profiler_ce, SL("_totalSeconds"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	PHALCON_REGISTER_CLASS(Phalcon\\Db, Reference, db_reference, phalcon_db_reference_method_entry, 0);
	zend_declare_property_null(phalcon_db_reference_ce, SL("_referenceName"), ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_db_reference_ce, SL("_referencedTable"), ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_db_reference_ce, SL("_columns"), ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_db_reference_ce, SL("_referencedColumns"), ZEND_ACC_PRIVATE TSRMLS_CC);

	PHALCON_REGISTER_CLASS(Phalcon\\Db, Dialect, db_dialect, phalcon_db_dialect_method_entry, 0);

	PHALCON_REGISTER_CLASS(Phalcon\\Db\\Profiler, Item, db_profiler_item, phalcon_db_profiler_item_method_entry, 0);
	zend_declare_property_null(phalcon_db_profiler_item_ce, SL("_sqlStatement"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_profiler_item_ce, SL("_initialTime"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_profiler_item_ce, SL("_finalTime"), ZEND_ACC_PROTECTED TSRMLS_CC);

	PHALCON_REGISTER_CLASS(Phalcon\\Db, RawValue, db_rawvalue, phalcon_db_rawvalue_method_entry, 0);
	zend_declare_property_null(phalcon_db_rawvalue_ce, SL("_value"), ZEND_ACC_PROTECTED TSRMLS_CC);

	PHALCON_REGISTER_CLASS(Phalcon\\Db, Column, db_column, phalcon_db_column_method_entry, 0);
	zend_declare_property_null(phalcon_db_column_ce, SL("_columnName"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_column_ce, SL("_schemaName"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_column_ce, SL("_type"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_column_ce, SL("_isNumeric"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_db_column_ce, SL("_size"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_db_column_ce, SL("_scale"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_column_ce, SL("_unsigned"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_column_ce, SL("_notNull"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_column_ce, SL("_primary"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_column_ce, SL("_autoIncrement"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_column_ce, SL("_first"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_column_ce, SL("_after"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_INTEGER"), 0 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_DATE"), 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_VARCHAR"), 2 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_DECIMAL"), 3 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_DATETIME"), 4 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_CHAR"), 5 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_TEXT"), 6 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_FLOAT"), 7 TSRMLS_CC);

	PHALCON_REGISTER_CLASS(Phalcon\\Db, Index, db_index, phalcon_db_index_method_entry, 0);
	zend_declare_property_null(phalcon_db_index_ce, SL("_indexName"), ZEND_ACC_PRIVATE TSRMLS_CC);

	PHALCON_REGISTER_CLASS(Phalcon\\Db\\Result, Pdo, db_result_pdo, phalcon_db_result_pdo_method_entry, 0);
	zend_declare_property_long(phalcon_db_result_pdo_ce, SL("_fetchMode"), 4, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_result_pdo_ce, SL("_pdoStatement"), ZEND_ACC_PROTECTED TSRMLS_CC);

	PHALCON_REGISTER_CLASS(Phalcon\\Db\\Dialect, Mysql, db_dialect_mysql, phalcon_db_dialect_mysql_method_entry, 0);

	PHALCON_REGISTER_CLASS(Phalcon\\Db\\Dialect, Postgresql, db_dialect_postgresql, phalcon_db_dialect_postgresql_method_entry, ZEND_ACC_ABSTRACT);

	PHALCON_REGISTER_CLASS(Phalcon, Tag, tag, phalcon_tag_method_entry, ZEND_ACC_ABSTRACT);
	zend_declare_property_null(phalcon_tag_ce, SL("_displayValues"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);
	zend_declare_property_string(phalcon_tag_ce, SL("_documentTitle"), "", ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);
	zend_declare_property_null(phalcon_tag_ce, SL("_dispatcher"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	PHALCON_REGISTER_CLASS(Phalcon\\Http\\Request, File, http_request_file, phalcon_http_request_file_method_entry, 0);
	zend_declare_property_null(phalcon_http_request_file_ce, SL("_name"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_request_file_ce, SL("_tmp"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_request_file_ce, SL("_size"), ZEND_ACC_PROTECTED TSRMLS_CC);

	PHALCON_REGISTER_CLASS(Phalcon\\Http\\Response, Headers, http_response_headers, phalcon_http_response_headers_method_entry, 0);
	zend_declare_property_null(phalcon_http_response_headers_ce, SL("_headers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	PHALCON_REGISTER_CLASS(Phalcon\\Http, Response, http_response, phalcon_http_response_method_entry, 0);
	zend_declare_property_string(phalcon_http_response_ce, SL("_content"), "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_response_ce, SL("_headers"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_response_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);

	PHALCON_REGISTER_CLASS(Phalcon\\Http, Request, http_request, phalcon_http_request_method_entry, 0);
	zend_declare_property_null(phalcon_http_request_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);

	PHALCON_REGISTER_CLASS(Phalcon, Session, session, phalcon_session_method_entry, ZEND_ACC_ABSTRACT);
	zend_declare_property_null(phalcon_session_ce, SL("_uniqueId"), ZEND_ACC_STATIC|ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_session_ce, SL("_options"), ZEND_ACC_STATIC|ZEND_ACC_PROTECTED TSRMLS_CC);

	PHALCON_REGISTER_CLASS(Phalcon, Flash, flash, phalcon_flash_method_entry, ZEND_ACC_ABSTRACT);

	PHALCON_REGISTER_CLASS(Phalcon, Config, config, phalcon_config_method_entry, 0);

	PHALCON_REGISTER_CLASS(Phalcon, Filter, filter, phalcon_filter_method_entry, 0);

	PHALCON_REGISTER_CLASS(Phalcon\\Events, Event, events_event, phalcon_events_event_method_entry, 0);
	zend_declare_property_null(phalcon_events_event_ce, SL("_type"), ZEND_ACC_PROTECTED TSRMLS_CC);

	PHALCON_REGISTER_CLASS(Phalcon\\Events, Manager, events_manager, phalcon_events_manager_method_entry, 0);
	zend_declare_property_null(phalcon_events_manager_ce, SL("_events"), ZEND_ACC_PROTECTED TSRMLS_CC);

	PHALCON_REGISTER_CLASS(Phalcon, Acl, acl, phalcon_acl_method_entry, 0);
	zend_declare_property_null(phalcon_acl_ce, SL("_adapter"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_acl_ce, SL("ALLOW"), 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_acl_ce, SL("DENY"), 0 TSRMLS_CC);

	PHALCON_REGISTER_CLASS(Phalcon\\Translate\\Adapter, Array, translate_adapter_array, phalcon_translate_adapter_array_method_entry, 0);
	zend_declare_property_null(phalcon_translate_adapter_array_ce, SL("_traslate"), ZEND_ACC_PROTECTED TSRMLS_CC);

	PHALCON_REGISTER_CLASS(Phalcon\\Logger, Item, logger_item, phalcon_logger_item_method_entry, 0);
	zend_declare_property_null(phalcon_logger_item_ce, SL("_type"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_logger_item_ce, SL("message"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_logger_item_ce, SL("_time"), ZEND_ACC_PROTECTED TSRMLS_CC);

	PHALCON_REGISTER_CLASS_EX(Phalcon, Exception, exception, "exception", NULL, 0);

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model, Exception, mvc_model_exception, "phalcon\\exception", NULL, 0);

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Db\\Adapter, Pdo, db_adapter_pdo, "phalcon\\db", phalcon_db_adapter_pdo_method_entry, ZEND_ACC_ABSTRACT);
	zend_declare_property_null(phalcon_db_adapter_pdo_ce, SL("_pdo"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_adapter_pdo_ce, SL("_dialect"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_adapter_pdo_ce, SL("_affectedRows"), ZEND_ACC_PROTECTED TSRMLS_CC);

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Dispatcher, Exception, mvc_dispatcher_exception, "phalcon\\exception", NULL, 0);

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\View, Exception, mvc_view_exception, "phalcon\\exception", NULL, 0);

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\View\\Engine, Php, mvc_view_engine_php, "phalcon\\mvc\\view\\engine", phalcon_mvc_view_engine_php_method_entry, 0);

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\View\\Engine, Twig, mvc_view_engine_twig, "phalcon\\mvc\\view\\engine", phalcon_mvc_view_engine_twig_method_entry, 0);
	zend_declare_property_null(phalcon_mvc_view_engine_twig_ce, SL("_twig"), ZEND_ACC_PROTECTED TSRMLS_CC);

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\View\\Engine, Mustache, mvc_view_engine_mustache, "phalcon\\mvc\\view\\engine", phalcon_mvc_view_engine_mustache_method_entry, 0);
	zend_declare_property_null(phalcon_mvc_view_engine_mustache_ce, SL("_mustache"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_engine_mustache_ce, SL("_params"), ZEND_ACC_PROTECTED TSRMLS_CC);

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Application, Exception, mvc_application_exception, "phalcon\\exception", NULL, 0);

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Validator, Uniqueness, mvc_model_validator_uniqueness, "phalcon\\mvc\\model\\validator", phalcon_mvc_model_validator_uniqueness_method_entry, 0);

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Validator, Exclusionin, mvc_model_validator_exclusionin, "phalcon\\mvc\\model\\validator", phalcon_mvc_model_validator_exclusionin_method_entry, 0);

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Validator, Regex, mvc_model_validator_regex, "phalcon\\mvc\\model\\validator", phalcon_mvc_model_validator_regex_method_entry, 0);

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Validator, Inclusionin, mvc_model_validator_inclusionin, "phalcon\\mvc\\model\\validator", phalcon_mvc_model_validator_inclusionin_method_entry, 0);

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Validator, Numericality, mvc_model_validator_numericality, "phalcon\\mvc\\model\\validator", phalcon_mvc_model_validator_numericality_method_entry, 0);

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Validator, Email, mvc_model_validator_email, "phalcon\\mvc\\model\\validator", phalcon_mvc_model_validator_email_method_entry, 0);

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Transaction, Exception, mvc_model_transaction_exception, "phalcon\\mvc\\model\\exception", NULL, 0);

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Transaction, Failed, mvc_model_transaction_failed, "exception", phalcon_mvc_model_transaction_failed_method_entry, 0);
	zend_declare_property_null(phalcon_mvc_model_transaction_failed_ce, SL("_record"), ZEND_ACC_PROTECTED TSRMLS_CC);

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\MetaData, Memory, mvc_model_metadata_memory, "phalcon\\mvc\\model\\metadata", phalcon_mvc_model_metadata_memory_method_entry, 0);

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\MetaData, Apc, mvc_model_metadata_apc, "phalcon\\mvc\\model\\metadata", phalcon_mvc_model_metadata_apc_method_entry, 0);
	zend_declare_property_string(phalcon_mvc_model_metadata_apc_ce, SL("_suffix"), "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_mvc_model_metadata_apc_ce, SL("_ttl"), 172800, ZEND_ACC_PROTECTED TSRMLS_CC);

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\MetaData, Session, mvc_model_metadata_session, "phalcon\\mvc\\model\\metadata", phalcon_mvc_model_metadata_session_method_entry, 0);
	zend_declare_property_string(phalcon_mvc_model_metadata_session_ce, SL("_suffix"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Config, Exception, config_exception, "phalcon\\exception", NULL, 0);

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Config\\Adapter, Ini, config_adapter_ini, "phalcon\\config", phalcon_config_adapter_ini_method_entry, 0);

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Cache, Exception, cache_exception, "phalcon\\exception", NULL, 0);

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Cache\\Backend, Memcache, cache_backend_memcache, "phalcon\\cache\\backend", phalcon_cache_backend_memcache_method_entry, 0);
	zend_declare_property_null(phalcon_cache_backend_memcache_ce, SL("_memcache"), ZEND_ACC_PROTECTED TSRMLS_CC);

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Cache\\Backend, Apc, cache_backend_apc, "phalcon\\cache\\backend", phalcon_cache_backend_apc_method_entry, 0);

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Cache\\Backend, File, cache_backend_file, "phalcon\\cache\\backend", phalcon_cache_backend_file_method_entry, 0);

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Acl, Exception, acl_exception, "phalcon\\exception", NULL, 0);

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Paginator, Exception, paginator_exception, "phalcon\\exception", NULL, 0);

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Tag, Exception, tag_exception, "phalcon\\exception", NULL, 0);

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Internal, Test, internal_test, "phalcon\\internal\\testparent", phalcon_internal_test_method_entry, 0);
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

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Db, Exception, db_exception, "phalcon\\exception", NULL, 0);

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Db\\Adapter\\Pdo, Mysql, db_adapter_pdo_mysql, "phalcon\\db\\adapter\\pdo", phalcon_db_adapter_pdo_mysql_method_entry, 0);
	zend_declare_property_string(phalcon_db_adapter_pdo_mysql_ce, SL("_type"), "mysql", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_db_adapter_pdo_mysql_ce, SL("_dialect"), "mysql", ZEND_ACC_PROTECTED TSRMLS_CC);

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Db\\Adapter\\Pdo, Postgresql, db_adapter_pdo_postgresql, "phalcon\\db\\adapter\\pdo", phalcon_db_adapter_pdo_postgresql_method_entry, 0);
	zend_declare_property_string(phalcon_db_adapter_pdo_postgresql_ce, SL("_type"), "pgsql", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_db_adapter_pdo_postgresql_ce, SL("_dialect"), "postgresql", ZEND_ACC_PROTECTED TSRMLS_CC);

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Http\\Request, Exception, http_request_exception, "phalcon\\exception", NULL, 0);

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Http\\Response, Exception, http_response_exception, "phalcon\\exception", NULL, 0);

	PHALCON_REGISTER_CLASS_EX(Phalcon\\DI, Exception, di_exception, "phalcon\\exception", NULL, 0);

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Events, Exception, events_exception, "phalcon\\exception", NULL, 0);

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Translate, Exception, translate_exception, "phalcon\\exception", NULL, 0);

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Logger, Exception, logger_exception, "phalcon\\exception", NULL, 0);

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Logger\\Adapter, File, logger_adapter_file, "phalcon\\logger", phalcon_logger_adapter_file_method_entry, 0);
	zend_declare_property_null(phalcon_logger_adapter_file_ce, SL("_fileHandler"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_logger_adapter_file_ce, SL("_transaction"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_logger_adapter_file_ce, SL("_quenue"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_logger_adapter_file_ce, SL("_dateFormat"), "D, d M y H:i:s O", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_logger_adapter_file_ce, SL("_format"), "[%date%][%type%] %message%", ZEND_ACC_PROTECTED TSRMLS_CC);

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Loader, Exception, loader_exception, "phalcon\\exception", NULL, 0);
	return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(phalcon){
	return SUCCESS;
}

PHP_RINIT_FUNCTION(phalcon){
return SUCCESS;
}

PHP_RSHUTDOWN_FUNCTION(phalcon){
return SUCCESS;
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

