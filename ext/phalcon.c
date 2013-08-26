
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "ext/standard/info.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/framework/orm.h"

zend_class_entry *phalcon_di_ce;
zend_class_entry *phalcon_acl_ce;
zend_class_entry *phalcon_tag_ce;
zend_class_entry *phalcon_db_ce;
zend_class_entry *phalcon_text_ce;
zend_class_entry *phalcon_cache_exception_ce;
zend_class_entry *phalcon_cache_multiple_ce;
zend_class_entry *phalcon_cache_backend_ce;
zend_class_entry *phalcon_cache_backend_mongo_ce;
zend_class_entry *phalcon_cache_frontend_json_ce;
zend_class_entry *phalcon_cache_backend_xcache_ce;
zend_class_entry *phalcon_cache_frontend_none_ce;
zend_class_entry *phalcon_cache_frontend_data_ce;
zend_class_entry *phalcon_cache_backend_file_ce;
zend_class_entry *phalcon_cache_backend_memory_ce;
zend_class_entry *phalcon_cache_backend_apc_ce;
zend_class_entry *phalcon_cache_frontend_base64_ce;
zend_class_entry *phalcon_cache_frontendinterface_ce;
zend_class_entry *phalcon_cache_frontend_igbinary_ce;
zend_class_entry *phalcon_cache_backendinterface_ce;
zend_class_entry *phalcon_cache_frontend_output_ce;
zend_class_entry *phalcon_cache_backend_memcache_ce;
zend_class_entry *phalcon_cache_backend_libmemcached_ce;
zend_class_entry *phalcon_tag_select_ce;
zend_class_entry *phalcon_tag_exception_ce;
zend_class_entry *phalcon_paginator_exception_ce;
zend_class_entry *phalcon_paginator_adapter_model_ce;
zend_class_entry *phalcon_paginator_adapterinterface_ce;
zend_class_entry *phalcon_paginator_adapter_nativearray_ce;
zend_class_entry *phalcon_paginator_adapter_querybuilder_ce;
zend_class_entry *phalcon_validation_ce;
zend_class_entry *phalcon_validation_validator_ce;
zend_class_entry *phalcon_validation_exception_ce;
zend_class_entry *phalcon_validation_message_ce;
zend_class_entry *phalcon_validation_message_group_ce;
zend_class_entry *phalcon_validation_validator_between_ce;
zend_class_entry *phalcon_validation_validator_email_ce;
zend_class_entry *phalcon_validation_validator_regex_ce;
zend_class_entry *phalcon_validation_validator_exclusionin_ce;
zend_class_entry *phalcon_validation_validator_inclusionin_ce;
zend_class_entry *phalcon_validation_validatorinterface_ce;
zend_class_entry *phalcon_validation_validator_identical_ce;
zend_class_entry *phalcon_validation_validator_presenceof_ce;
zend_class_entry *phalcon_validation_validator_stringlength_ce;
zend_class_entry *phalcon_validation_validator_confirmation_ce;
zend_class_entry *phalcon_db_index_ce;
zend_class_entry *phalcon_db_exception_ce;
zend_class_entry *phalcon_db_dialect_ce;
zend_class_entry *phalcon_db_profiler_ce;
zend_class_entry *phalcon_db_reference_ce;
zend_class_entry *phalcon_db_rawvalue_ce;
zend_class_entry *phalcon_db_adapter_ce;
zend_class_entry *phalcon_db_column_ce;
zend_class_entry *phalcon_db_adapter_pdo_ce;
zend_class_entry *phalcon_db_adapter_pdo_mysql_ce;
zend_class_entry *phalcon_db_adapterinterface_ce;
zend_class_entry *phalcon_db_adapter_pdo_oracle_ce;
zend_class_entry *phalcon_db_adapter_pdo_sqlite_ce;
zend_class_entry *phalcon_db_adapter_pdo_postgresql_ce;
zend_class_entry *phalcon_db_columninterface_ce;
zend_class_entry *phalcon_db_dialect_mysql_ce;
zend_class_entry *phalcon_db_dialect_oracle_ce;
zend_class_entry *phalcon_db_dialect_sqlite_ce;
zend_class_entry *phalcon_db_dialectinterface_ce;
zend_class_entry *phalcon_db_dialect_postgresql_ce;
zend_class_entry *phalcon_db_indexinterface_ce;
zend_class_entry *phalcon_db_profiler_item_ce;
zend_class_entry *phalcon_db_result_pdo_ce;
zend_class_entry *phalcon_db_resultinterface_ce;
zend_class_entry *phalcon_db_referenceinterface_ce;
zend_class_entry *phalcon_acl_role_ce;
zend_class_entry *phalcon_acl_adapter_ce;
zend_class_entry *phalcon_acl_resource_ce;
zend_class_entry *phalcon_acl_exception_ce;
zend_class_entry *phalcon_acl_adapterinterface_ce;
zend_class_entry *phalcon_acl_adapter_memory_ce;
zend_class_entry *phalcon_acl_roleinterface_ce;
zend_class_entry *phalcon_acl_resourceinterface_ce;
zend_class_entry *phalcon_security_ce;
zend_class_entry *phalcon_version_ce;
zend_class_entry *phalcon_kernel_ce;
zend_class_entry *phalcon_debug_ce;
zend_class_entry *phalcon_session_ce;
zend_class_entry *phalcon_security_exception_ce;
zend_class_entry *phalcon_session_bag_ce;
zend_class_entry *phalcon_session_adapter_ce;
zend_class_entry *phalcon_session_baginterface_ce;
zend_class_entry *phalcon_session_exception_ce;
zend_class_entry *phalcon_session_adapterinterface_ce;
zend_class_entry *phalcon_session_adapter_files_ce;
zend_class_entry *phalcon_filter_ce;
zend_class_entry *phalcon_di_service_ce;
zend_class_entry *phalcon_di_exception_ce;
zend_class_entry *phalcon_di_factorydefault_ce;
zend_class_entry *phalcon_di_factorydefault_cli_ce;
zend_class_entry *phalcon_di_injectable_ce;
zend_class_entry *phalcon_di_injectionawareinterface_ce;
zend_class_entry *phalcon_di_service_builder_ce;
zend_class_entry *phalcon_di_serviceinterface_ce;
zend_class_entry *phalcon_diinterface_ce;
zend_class_entry *phalcon_filter_exception_ce;
zend_class_entry *phalcon_filterinterface_ce;
zend_class_entry *phalcon_filter_userfilterinterface_ce;
zend_class_entry *phalcon_dispatcher_ce;
zend_class_entry *phalcon_dispatcherinterface_ce;
zend_class_entry *phalcon_flash_ce;
zend_class_entry *phalcon_cli_task_ce;
zend_class_entry *phalcon_flash_direct_ce;
zend_class_entry *phalcon_flashinterface_ce;
zend_class_entry *phalcon_flash_session_ce;
zend_class_entry *phalcon_flash_exception_ce;
zend_class_entry *phalcon_cli_console_ce;
zend_class_entry *phalcon_cli_router_ce;
zend_class_entry *phalcon_cli_dispatcher_ce;
zend_class_entry *phalcon_cli_console_exception_ce;
zend_class_entry *phalcon_cli_dispatcher_exception_ce;
zend_class_entry *phalcon_cli_router_exception_ce;
zend_class_entry *phalcon_annotations_adapter_ce;
zend_class_entry *phalcon_annotations_reader_ce;
zend_class_entry *phalcon_annotations_adapter_apc_ce;
zend_class_entry *phalcon_annotations_exception_ce;
zend_class_entry *phalcon_annotations_annotation_ce;
zend_class_entry *phalcon_annotations_reflection_ce;
zend_class_entry *phalcon_annotations_collection_ce;
zend_class_entry *phalcon_annotations_adapterinterface_ce;
zend_class_entry *phalcon_annotations_adapter_xcache_ce;
zend_class_entry *phalcon_annotations_readerinterface_ce;
zend_class_entry *phalcon_annotations_adapter_files_ce;
zend_class_entry *phalcon_annotations_adapter_memory_ce;
zend_class_entry *phalcon_config_ce;
zend_class_entry *phalcon_logger_ce;
zend_class_entry *phalcon_loader_ce;
zend_class_entry *phalcon_loader_exception_ce;
zend_class_entry *phalcon_logger_item_ce;
zend_class_entry *phalcon_logger_formatter_ce;
zend_class_entry *phalcon_logger_exception_ce;
zend_class_entry *phalcon_logger_multiple_ce;
zend_class_entry *phalcon_logger_adapter_ce;
zend_class_entry *phalcon_logger_adapter_file_ce;
zend_class_entry *phalcon_logger_adapter_syslog_ce;
zend_class_entry *phalcon_logger_adapter_firephp_ce;
zend_class_entry *phalcon_logger_adapterinterface_ce;
zend_class_entry *phalcon_logger_formatter_json_ce;
zend_class_entry *phalcon_logger_formatter_line_ce;
zend_class_entry *phalcon_logger_formatter_firephp_ce;
zend_class_entry *phalcon_logger_adapter_stream_ce;
zend_class_entry *phalcon_logger_formatter_syslog_ce;
zend_class_entry *phalcon_logger_formatterinterface_ce;
zend_class_entry *phalcon_config_exception_ce;
zend_class_entry *phalcon_config_adapter_ini_ce;
zend_class_entry *phalcon_config_adapter_json_ce;
zend_class_entry *phalcon_forms_form_ce;
zend_class_entry *phalcon_forms_element_ce;
zend_class_entry *phalcon_forms_exception_ce;
zend_class_entry *phalcon_forms_manager_ce;
zend_class_entry *phalcon_forms_element_check_ce;
zend_class_entry *phalcon_forms_element_email_ce;
zend_class_entry *phalcon_forms_element_submit_ce;
zend_class_entry *phalcon_forms_element_select_ce;
zend_class_entry *phalcon_forms_element_file_ce;
zend_class_entry *phalcon_forms_element_date_ce;
zend_class_entry *phalcon_forms_element_hidden_ce;
zend_class_entry *phalcon_forms_element_text_ce;
zend_class_entry *phalcon_forms_element_textarea_ce;
zend_class_entry *phalcon_forms_elementinterface_ce;
zend_class_entry *phalcon_forms_element_numeric_ce;
zend_class_entry *phalcon_forms_element_password_ce;
zend_class_entry *phalcon_crypt_ce;
zend_class_entry *phalcon_translate_ce;
zend_class_entry *phalcon_translate_exception_ce;
zend_class_entry *phalcon_translate_adapter_ce;
zend_class_entry *phalcon_translate_adapterinterface_ce;
zend_class_entry *phalcon_translate_adapter_nativearray_ce;
zend_class_entry *phalcon_cryptinterface_ce;
zend_class_entry *phalcon_crypt_exception_ce;
zend_class_entry *phalcon_escaper_ce;
zend_class_entry *phalcon_escaperinterface_ce;
zend_class_entry *phalcon_escaper_exception_ce;
zend_class_entry *phalcon_assets_resource_ce;
zend_class_entry *phalcon_assets_manager_ce;
zend_class_entry *phalcon_assets_exception_ce;
zend_class_entry *phalcon_assets_collection_ce;
zend_class_entry *phalcon_assets_filters_none_ce;
zend_class_entry *phalcon_assets_resource_js_ce;
zend_class_entry *phalcon_assets_filters_jsmin_ce;
zend_class_entry *phalcon_assets_resource_css_ce;
zend_class_entry *phalcon_assets_filterinterface_ce;
zend_class_entry *phalcon_assets_filters_cssmin_ce;
zend_class_entry *phalcon_http_request_ce;
zend_class_entry *phalcon_http_cookie_ce;
zend_class_entry *phalcon_http_response_ce;
zend_class_entry *phalcon_http_request_file_ce;
zend_class_entry *phalcon_http_cookie_exception_ce;
zend_class_entry *phalcon_http_responseinterface_ce;
zend_class_entry *phalcon_http_requestinterface_ce;
zend_class_entry *phalcon_http_response_exception_ce;
zend_class_entry *phalcon_http_response_cookies_ce;
zend_class_entry *phalcon_http_response_headers_ce;
zend_class_entry *phalcon_http_request_exception_ce;
zend_class_entry *phalcon_http_request_fileinterface_ce;
zend_class_entry *phalcon_http_response_headersinterface_ce;
zend_class_entry *phalcon_http_response_cookiesinterface_ce;
zend_class_entry *phalcon_queue_beanstalk_ce;
zend_class_entry *phalcon_queue_beanstalk_job_ce;
zend_class_entry *phalcon_mvc_url_ce;
zend_class_entry *phalcon_mvc_view_ce;
zend_class_entry *phalcon_mvc_router_ce;
zend_class_entry *phalcon_mvc_model_ce;
zend_class_entry *phalcon_mvc_micro_ce;
zend_class_entry *phalcon_mvc_user_module_ce;
zend_class_entry *phalcon_mvc_user_plugin_ce;
zend_class_entry *phalcon_mvc_urlinterface_ce;
zend_class_entry *phalcon_mvc_view_engine_ce;
zend_class_entry *phalcon_mvc_view_simple_ce;
zend_class_entry *phalcon_mvc_dispatcher_ce;
zend_class_entry *phalcon_mvc_collection_ce;
zend_class_entry *phalcon_mvc_application_ce;
zend_class_entry *phalcon_mvc_controller_ce;
zend_class_entry *phalcon_mvc_model_row_ce;
zend_class_entry *phalcon_mvc_router_route_ce;
zend_class_entry *phalcon_mvc_router_group_ce;
zend_class_entry *phalcon_mvc_model_query_ce;
zend_class_entry *phalcon_mvc_application_exception_ce;
zend_class_entry *phalcon_mvc_collection_manager_ce;
zend_class_entry *phalcon_mvc_controllerinterface_ce;
zend_class_entry *phalcon_mvc_collection_document_ce;
zend_class_entry *phalcon_mvc_collectioninterface_ce;
zend_class_entry *phalcon_mvc_collection_exception_ce;
zend_class_entry *phalcon_mvc_collection_managerinterface_ce;
zend_class_entry *phalcon_mvc_dispatcher_exception_ce;
zend_class_entry *phalcon_mvc_dispatcherinterface_ce;
zend_class_entry *phalcon_mvc_model_criteria_ce;
zend_class_entry *phalcon_mvc_model_behavior_ce;
zend_class_entry *phalcon_mvc_model_metadata_ce;
zend_class_entry *phalcon_mvc_micro_lazyloader_ce;
zend_class_entry *phalcon_mvc_micro_collection_ce;
zend_class_entry *phalcon_mvc_model_message_ce;
zend_class_entry *phalcon_mvc_model_manager_ce;
zend_class_entry *phalcon_mvc_model_relation_ce;
zend_class_entry *phalcon_mvc_micro_exception_ce;
zend_class_entry *phalcon_mvc_model_resultset_ce;
zend_class_entry *phalcon_mvc_model_exception_ce;
zend_class_entry *phalcon_mvc_model_validator_ce;
zend_class_entry *phalcon_mvc_modelinterface_ce;
zend_class_entry *phalcon_mvc_model_query_lang_ce;
zend_class_entry *phalcon_mvc_micro_collectioninterface_ce;
zend_class_entry *phalcon_mvc_micro_middlewareinterface_ce;
zend_class_entry *phalcon_mvc_model_query_builder_ce;
zend_class_entry *phalcon_mvc_model_validator_url_ce;
zend_class_entry *phalcon_mvc_model_transaction_ce;
zend_class_entry *phalcon_mvc_model_queryinterface_ce;
zend_class_entry *phalcon_mvc_model_query_status_ce;
zend_class_entry *phalcon_mvc_model_metadata_apc_ce;
zend_class_entry *phalcon_mvc_model_metadata_files_ce;
zend_class_entry *phalcon_mvc_model_resultsetinterface_ce;
zend_class_entry *phalcon_mvc_model_behaviorinterface_ce;
zend_class_entry *phalcon_mvc_model_resultinterface_ce;
zend_class_entry *phalcon_mvc_model_metadatainterface_ce;
zend_class_entry *phalcon_mvc_model_metadata_xcache_ce;
zend_class_entry *phalcon_mvc_model_resultset_simple_ce;
zend_class_entry *phalcon_mvc_model_resultset_complex_ce;
zend_class_entry *phalcon_mvc_model_metadata_memory_ce;
zend_class_entry *phalcon_mvc_model_validatorinterface_ce;
zend_class_entry *phalcon_mvc_model_transaction_failed_ce;
zend_class_entry *phalcon_mvc_model_managerinterface_ce;
zend_class_entry *phalcon_mvc_model_criteriainterface_ce;
zend_class_entry *phalcon_mvc_model_relationinterface_ce;
zend_class_entry *phalcon_mvc_model_validator_email_ce;
zend_class_entry *phalcon_mvc_model_metadata_session_ce;
zend_class_entry *phalcon_mvc_model_validator_regex_ce;
zend_class_entry *phalcon_mvc_model_messageinterface_ce;
zend_class_entry *phalcon_mvc_model_validationfailed_ce;
zend_class_entry *phalcon_mvc_model_query_builderinterface_ce;
zend_class_entry *phalcon_mvc_model_behavior_timestampable_ce;
zend_class_entry *phalcon_mvc_model_query_statusinterface_ce;
zend_class_entry *phalcon_mvc_model_transaction_exception_ce;
zend_class_entry *phalcon_mvc_model_validator_stringlength_ce;
zend_class_entry *phalcon_mvc_model_transactioninterface_ce;
zend_class_entry *phalcon_mvc_model_validator_numericality_ce;
zend_class_entry *phalcon_mvc_model_validator_inclusionin_ce;
zend_class_entry *phalcon_mvc_model_validator_exclusionin_ce;
zend_class_entry *phalcon_mvc_model_transaction_manager_ce;
zend_class_entry *phalcon_mvc_model_validator_uniqueness_ce;
zend_class_entry *phalcon_mvc_model_validator_presenceof_ce;
zend_class_entry *phalcon_mvc_model_behavior_softdelete_ce;
zend_class_entry *phalcon_mvc_model_metadata_strategy_annotations_ce;
zend_class_entry *phalcon_mvc_model_transaction_managerinterface_ce;
zend_class_entry *phalcon_mvc_model_metadata_strategy_introspection_ce;
zend_class_entry *phalcon_mvc_moduledefinitioninterface_ce;
zend_class_entry *phalcon_mvc_router_exception_ce;
zend_class_entry *phalcon_mvc_routerinterface_ce;
zend_class_entry *phalcon_mvc_router_annotations_ce;
zend_class_entry *phalcon_mvc_router_routeinterface_ce;
zend_class_entry *phalcon_mvc_user_component_ce;
zend_class_entry *phalcon_mvc_url_exception_ce;
zend_class_entry *phalcon_mvc_view_exception_ce;
zend_class_entry *phalcon_mvc_view_engine_php_ce;
zend_class_entry *phalcon_mvc_viewinterface_ce;
zend_class_entry *phalcon_mvc_view_engine_volt_ce;
zend_class_entry *phalcon_mvc_view_engineinterface_ce;
zend_class_entry *phalcon_mvc_view_engine_volt_compiler_ce;
zend_class_entry *phalcon_events_event_ce;
zend_class_entry *phalcon_events_exception_ce;
zend_class_entry *phalcon_events_manager_ce;
zend_class_entry *phalcon_events_managerinterface_ce;
zend_class_entry *phalcon_events_eventsawareinterface_ce;
zend_class_entry *phalcon_exception_ce;
zend_class_entry *phalcon_image_ce;
zend_class_entry *phalcon_image_adapter_ce;
zend_class_entry *phalcon_image_adapterinterface_ce;
zend_class_entry *phalcon_image_exception_ce;
zend_class_entry *phalcon_image_adapter_gd_ce;
zend_class_entry *phalcon_image_adapter_imagick_ce;
zend_class_entry *phalcon_utils_date_ce;
zend_class_entry *phalcon_utils_arr_ce;

ZEND_DECLARE_MODULE_GLOBALS(phalcon)

#if PHP_VERSION_ID >= 50500
static void (*orig_execute_internal)(zend_execute_data *, zend_fcall_info *, int TSRMLS_DC) = NULL;
#else
static void (*orig_execute_internal)(zend_execute_data *, int TSRMLS_DC) = NULL;
#endif

#if PHP_VERSION_ID >= 50500

static void phalcon_execute_internal(zend_execute_data *execute_data_ptr, zend_fcall_info *fci, int return_value_used TSRMLS_DC)
{
	if (fci) {
		((zend_internal_function *) execute_data_ptr->function_state.function)->handler(fci->param_count, *fci->retval_ptr_ptr, fci->retval_ptr_ptr, fci->object_ptr, return_value_used TSRMLS_CC);
	}
	else {
		zval **return_value_ptr = EX_TMP_VAR(execute_data_ptr, execute_data_ptr->opline->result.var)->var.ptr_ptr;
		((zend_internal_function *) execute_data_ptr->function_state.function)->handler(execute_data_ptr->opline->extended_value, *return_value_ptr, return_value_ptr, execute_data_ptr->object, return_value_used TSRMLS_CC);
	}
}

#else

static void phalcon_execute_internal(zend_execute_data *execute_data_ptr, int return_value_used TSRMLS_DC)
{
#if PHP_VERSION_ID < 50400
	zval **return_value_ptr = &(*(temp_variable *)((char *) execute_data_ptr->Ts + execute_data_ptr->opline->result.u.var)).var.ptr;
#else
	zval **return_value_ptr = &(*(temp_variable *)((char *) execute_data_ptr->Ts + execute_data_ptr->opline->result.var)).var.ptr;
#endif

	((zend_internal_function *) execute_data_ptr->function_state.function)->handler(execute_data_ptr->opline->extended_value, *return_value_ptr, return_value_ptr, execute_data_ptr->object, return_value_used TSRMLS_CC);
}

#endif

static PHP_MINIT_FUNCTION(phalcon){

	PHALCON_INIT(Phalcon_DI_InjectionAwareInterface);
	PHALCON_INIT(Phalcon_Forms_ElementInterface);
	PHALCON_INIT(Phalcon_Mvc_Model_ValidatorInterface);
	PHALCON_INIT(Phalcon_Validation_ValidatorInterface);
	PHALCON_INIT(Phalcon_Events_EventsAwareInterface);
	PHALCON_INIT(Phalcon_Cache_BackendInterface);
	PHALCON_INIT(Phalcon_Cache_FrontendInterface);
	PHALCON_INIT(Phalcon_Mvc_Model_MetaDataInterface);
	PHALCON_INIT(Phalcon_Db_DialectInterface);
	PHALCON_INIT(Phalcon_Db_AdapterInterface);
	PHALCON_INIT(Phalcon_Annotations_AdapterInterface);
	PHALCON_INIT(Phalcon_Logger_AdapterInterface);
	PHALCON_INIT(Phalcon_Logger_FormatterInterface);
	PHALCON_INIT(Phalcon_Paginator_AdapterInterface);
	PHALCON_INIT(Phalcon_Mvc_View_EngineInterface);
	PHALCON_INIT(Phalcon_Mvc_Model_ResultsetInterface);
	PHALCON_INIT(Phalcon_Mvc_Model_BehaviorInterface);
	PHALCON_INIT(Phalcon_FlashInterface);
	PHALCON_INIT(Phalcon_Mvc_Model_ResultInterface);
	PHALCON_INIT(Phalcon_Exception);
	PHALCON_INIT(Phalcon_Db_Adapter);
	PHALCON_INIT(Phalcon_DispatcherInterface);
	PHALCON_INIT(Phalcon_DI_Injectable);
	PHALCON_INIT(Phalcon_Mvc_DispatcherInterface);
	PHALCON_INIT(Phalcon_Mvc_Model_QueryInterface);
	PHALCON_INIT(Phalcon_Mvc_Router_RouteInterface);
	PHALCON_INIT(Phalcon_Mvc_Model_Query_StatusInterface);
	PHALCON_INIT(Phalcon_Mvc_Model_Query_BuilderInterface);
	PHALCON_INIT(Phalcon_Mvc_CollectionInterface);
	PHALCON_INIT(Phalcon_Mvc_Model_TransactionInterface);
	PHALCON_INIT(Phalcon_Mvc_UrlInterface);
	PHALCON_INIT(Phalcon_Mvc_ViewInterface);
	PHALCON_INIT(Phalcon_Http_RequestInterface);
	PHALCON_INIT(Phalcon_Http_ResponseInterface);
	PHALCON_INIT(Phalcon_Db_ReferenceInterface);
	PHALCON_INIT(Phalcon_Db_ColumnInterface);
	PHALCON_INIT(Phalcon_Db_IndexInterface);
	PHALCON_INIT(Phalcon_Http_Request_FileInterface);
	PHALCON_INIT(Phalcon_Http_Response_CookiesInterface);
	PHALCON_INIT(Phalcon_Mvc_ModelInterface);
	PHALCON_INIT(Phalcon_Mvc_Micro_CollectionInterface);
	PHALCON_INIT(Phalcon_Mvc_RouterInterface);
	PHALCON_INIT(Phalcon_Http_Response_HeadersInterface);
	PHALCON_INIT(Phalcon_DiInterface);
	PHALCON_INIT(Phalcon_Mvc_Model_RelationInterface);
	PHALCON_INIT(Phalcon_Acl_ResourceInterface);
	PHALCON_INIT(Phalcon_Mvc_Model_ManagerInterface);
	PHALCON_INIT(Phalcon_FilterInterface);
	PHALCON_INIT(Phalcon_CryptInterface);
	PHALCON_INIT(Phalcon_Acl_RoleInterface);
	PHALCON_INIT(Phalcon_Session_BagInterface);
	PHALCON_INIT(Phalcon_Session_AdapterInterface);
	PHALCON_INIT(Phalcon_DI_ServiceInterface);
	PHALCON_INIT(Phalcon_Annotations_ReaderInterface);
	PHALCON_INIT(Phalcon_Events_ManagerInterface);
	PHALCON_INIT(Phalcon_EscaperInterface);
	PHALCON_INIT(Phalcon_Acl_AdapterInterface);
	PHALCON_INIT(Phalcon_Mvc_Model_Transaction_ManagerInterface);
	PHALCON_INIT(Phalcon_Mvc_Model_CriteriaInterface);
	PHALCON_INIT(Phalcon_Translate_AdapterInterface);
	PHALCON_INIT(Phalcon_Mvc_Model_MessageInterface);
	PHALCON_INIT(Phalcon_Mvc_Model_Exception);
	PHALCON_INIT(Phalcon_DI);
	PHALCON_INIT(Phalcon_Forms_Element);
	PHALCON_INIT(Phalcon_Validation_Validator);
	PHALCON_INIT(Phalcon_Mvc_Model_Validator);
	PHALCON_INIT(Phalcon_Cache_Backend);
	PHALCON_INIT(Phalcon_Mvc_Model_MetaData);
	PHALCON_INIT(Phalcon_Db_Adapter_Pdo);
	PHALCON_INIT(Phalcon_Db_Dialect);
	PHALCON_INIT(Phalcon_Annotations_Adapter);
	PHALCON_INIT(Phalcon_Logger_Adapter);
	PHALCON_INIT(Phalcon_Logger_Formatter);
	PHALCON_INIT(Phalcon_Mvc_Model_Resultset);
	PHALCON_INIT(Phalcon_Mvc_Model_Behavior);
	PHALCON_INIT(Phalcon_Assets_Resource);
	PHALCON_INIT(Phalcon_Flash);
	PHALCON_INIT(Phalcon_Dispatcher);
	PHALCON_INIT(Phalcon_Mvc_View_Engine);
	PHALCON_INIT(Phalcon_Translate_Adapter);
	PHALCON_INIT(Phalcon_Cache_Frontend_Data);
	PHALCON_INIT(Phalcon_DI_FactoryDefault);
	PHALCON_INIT(Phalcon_Config);
	PHALCON_INIT(Phalcon_Mvc_Model_Transaction_Exception);
	PHALCON_INIT(Phalcon_Mvc_Router);
	PHALCON_INIT(Phalcon_Acl_Adapter);
	PHALCON_INIT(Phalcon_Session_Adapter);
	PHALCON_INIT(Phalcon_Db);
	PHALCON_INIT(Phalcon_Acl);
	PHALCON_INIT(Phalcon_Tag);
	PHALCON_INIT(Phalcon_Cache_Exception);
	PHALCON_INIT(Phalcon_Cache_Multiple);
	PHALCON_INIT(Phalcon_Cache_Backend_Apc);
	PHALCON_INIT(Phalcon_Cache_Backend_File);
	PHALCON_INIT(Phalcon_Cache_Backend_Memory);
	PHALCON_INIT(Phalcon_Cache_Backend_Xcache);
	PHALCON_INIT(Phalcon_Cache_Backend_Mongo);
	PHALCON_INIT(Phalcon_Cache_Backend_Memcache);
	PHALCON_INIT(Phalcon_Cache_Backend_Libmemcached);
	PHALCON_INIT(Phalcon_Cache_Frontend_Json);
	PHALCON_INIT(Phalcon_Cache_Frontend_Output);
	PHALCON_INIT(Phalcon_Cache_Frontend_None);
	PHALCON_INIT(Phalcon_Cache_Frontend_Base64);
	PHALCON_INIT(Phalcon_Cache_Frontend_Igbinary);
	PHALCON_INIT(Phalcon_Tag_Select);
	PHALCON_INIT(Phalcon_Tag_Exception);
	PHALCON_INIT(Phalcon_Paginator_Exception);
	PHALCON_INIT(Phalcon_Paginator_Adapter_Model);
	PHALCON_INIT(Phalcon_Paginator_Adapter_NativeArray);
	PHALCON_INIT(Phalcon_Paginator_Adapter_QueryBuilder);
	PHALCON_INIT(Phalcon_Validation);
	PHALCON_INIT(Phalcon_Validation_Message);
	PHALCON_INIT(Phalcon_Validation_Exception);
	PHALCON_INIT(Phalcon_Validation_Message_Group);
	PHALCON_INIT(Phalcon_Validation_Validator_Regex);
	PHALCON_INIT(Phalcon_Validation_Validator_Email);
	PHALCON_INIT(Phalcon_Validation_Validator_Between);
	PHALCON_INIT(Phalcon_Validation_Validator_Identical);
	PHALCON_INIT(Phalcon_Validation_Validator_PresenceOf);
	PHALCON_INIT(Phalcon_Validation_Validator_InclusionIn);
	PHALCON_INIT(Phalcon_Validation_Validator_StringLength);
	PHALCON_INIT(Phalcon_Validation_Validator_ExclusionIn);
	PHALCON_INIT(Phalcon_Validation_Validator_Confirmation);
	PHALCON_INIT(Phalcon_Db_Index);
	PHALCON_INIT(Phalcon_Db_Column);
	PHALCON_INIT(Phalcon_Db_Adapter_Pdo_Sqlite);
	PHALCON_INIT(Phalcon_Db_Adapter_Pdo_Mysql);
	PHALCON_INIT(Phalcon_Db_Adapter_Pdo_Oracle);
	PHALCON_INIT(Phalcon_Db_Adapter_Pdo_Postgresql);
	PHALCON_INIT(Phalcon_Db_Dialect_Sqlite);
	PHALCON_INIT(Phalcon_Db_Dialect_Mysql);
	PHALCON_INIT(Phalcon_Db_Dialect_Oracle);
	PHALCON_INIT(Phalcon_Db_Dialect_Postgresql);
	PHALCON_INIT(Phalcon_Db_Exception);
	PHALCON_INIT(Phalcon_Db_Profiler);
	PHALCON_INIT(Phalcon_Db_Profiler_Item);
	PHALCON_INIT(Phalcon_Db_RawValue);
	PHALCON_INIT(Phalcon_Db_Reference);
	PHALCON_INIT(Phalcon_Db_Result_Pdo);
	PHALCON_INIT(Phalcon_Db_ResultInterface);
	PHALCON_INIT(Phalcon_Acl_Role);
	PHALCON_INIT(Phalcon_Acl_Resource);
	PHALCON_INIT(Phalcon_Acl_Adapter_Memory);
	PHALCON_INIT(Phalcon_Acl_Exception);
	PHALCON_INIT(Phalcon_Kernel);
	PHALCON_INIT(Phalcon_Debug);
	PHALCON_INIT(Phalcon_Text);
	PHALCON_INIT(Phalcon_Security);
	PHALCON_INIT(Phalcon_Security_Exception);
	PHALCON_INIT(Phalcon_Version);
	PHALCON_INIT(Phalcon_Session);
	PHALCON_INIT(Phalcon_Session_Bag);
	PHALCON_INIT(Phalcon_Session_Exception);
	PHALCON_INIT(Phalcon_Session_Adapter_Files);
	PHALCON_INIT(Phalcon_Filter);
	PHALCON_INIT(Phalcon_DI_Exception);
	PHALCON_INIT(Phalcon_DI_FactoryDefault_CLI);
	PHALCON_INIT(Phalcon_DI_Service);
	PHALCON_INIT(Phalcon_DI_Service_Builder);
	PHALCON_INIT(Phalcon_Filter_Exception);
	PHALCON_INIT(Phalcon_Filter_UserFilterInterface);
	PHALCON_INIT(Phalcon_Flash_Direct);
	PHALCON_INIT(Phalcon_Flash_Exception);
	PHALCON_INIT(Phalcon_Flash_Session);
	PHALCON_INIT(Phalcon_CLI_Task);
	PHALCON_INIT(Phalcon_CLI_Router);
	PHALCON_INIT(Phalcon_CLI_Console);
	PHALCON_INIT(Phalcon_CLI_Console_Exception);
	PHALCON_INIT(Phalcon_CLI_Dispatcher);
	PHALCON_INIT(Phalcon_CLI_Dispatcher_Exception);
	PHALCON_INIT(Phalcon_CLI_Router_Exception);
	PHALCON_INIT(Phalcon_Annotations_Reader);
	PHALCON_INIT(Phalcon_Annotations_Exception);
	PHALCON_INIT(Phalcon_Annotations_Annotation);
	PHALCON_INIT(Phalcon_Annotations_Adapter_Apc);
	PHALCON_INIT(Phalcon_Annotations_Collection);
	PHALCON_INIT(Phalcon_Annotations_Reflection);
	PHALCON_INIT(Phalcon_Annotations_Adapter_Xcache);
	PHALCON_INIT(Phalcon_Annotations_Adapter_Files);
	PHALCON_INIT(Phalcon_Annotations_Adapter_Memory);
	PHALCON_INIT(Phalcon_Loader);
	PHALCON_INIT(Phalcon_Logger);
	PHALCON_INIT(Phalcon_Loader_Exception);
	PHALCON_INIT(Phalcon_Logger_Item);
	PHALCON_INIT(Phalcon_Logger_Multiple);
	PHALCON_INIT(Phalcon_Logger_Exception);
	PHALCON_INIT(Phalcon_Logger_Formatter_Json);
	PHALCON_INIT(Phalcon_Logger_Formatter_Line);
	PHALCON_INIT(Phalcon_Logger_Formatter_Firephp);
	PHALCON_INIT(Phalcon_Logger_Adapter_Stream);
	PHALCON_INIT(Phalcon_Logger_Adapter_Syslog);
	PHALCON_INIT(Phalcon_Logger_Adapter_File);
	PHALCON_INIT(Phalcon_Logger_Adapter_Firephp);
	PHALCON_INIT(Phalcon_Logger_Formatter_Syslog);
	PHALCON_INIT(Phalcon_Config_Adapter_Ini);
	PHALCON_INIT(Phalcon_Config_Adapter_Json);
	PHALCON_INIT(Phalcon_Config_Exception);
	PHALCON_INIT(Phalcon_Forms_Form);
	PHALCON_INIT(Phalcon_Forms_Manager);
	PHALCON_INIT(Phalcon_Forms_Exception);
	PHALCON_INIT(Phalcon_Forms_Element_Text);
	PHALCON_INIT(Phalcon_Forms_Element_Date);
	PHALCON_INIT(Phalcon_Forms_Element_File);
	PHALCON_INIT(Phalcon_Forms_Element_Hidden);
	PHALCON_INIT(Phalcon_Forms_Element_Select);
	PHALCON_INIT(Phalcon_Forms_Element_Check);
	PHALCON_INIT(Phalcon_Forms_Element_Numeric);
	PHALCON_INIT(Phalcon_Forms_Element_Email);
	PHALCON_INIT(Phalcon_Forms_Element_Submit);
	PHALCON_INIT(Phalcon_Forms_Element_Password);
	PHALCON_INIT(Phalcon_Forms_Element_TextArea);
	PHALCON_INIT(Phalcon_Crypt);
	PHALCON_INIT(Phalcon_Translate);
	PHALCON_INIT(Phalcon_Translate_Exception);
	PHALCON_INIT(Phalcon_Translate_Adapter_NativeArray);
	PHALCON_INIT(Phalcon_Crypt_Exception);
	PHALCON_INIT(Phalcon_Escaper);
	PHALCON_INIT(Phalcon_Escaper_Exception);
	PHALCON_INIT(Phalcon_Assets_Manager);
	PHALCON_INIT(Phalcon_Assets_Resource_Js);
	PHALCON_INIT(Phalcon_Assets_Collection);
	PHALCON_INIT(Phalcon_Assets_Exception);
	PHALCON_INIT(Phalcon_Assets_Filters_None);
	PHALCON_INIT(Phalcon_Assets_Filters_Cssmin);
	PHALCON_INIT(Phalcon_Assets_Filters_Jsmin);
	PHALCON_INIT(Phalcon_Assets_Resource_Css);
	PHALCON_INIT(Phalcon_Assets_FilterInterface);
	PHALCON_INIT(Phalcon_Http_Request);
	PHALCON_INIT(Phalcon_Http_Cookie);
	PHALCON_INIT(Phalcon_Http_Response);
	PHALCON_INIT(Phalcon_Http_Cookie_Exception);
	PHALCON_INIT(Phalcon_Http_Request_File);
	PHALCON_INIT(Phalcon_Http_Response_Cookies);
	PHALCON_INIT(Phalcon_Http_Response_Headers);
	PHALCON_INIT(Phalcon_Http_Request_Exception);
	PHALCON_INIT(Phalcon_Http_Response_Exception);
	PHALCON_INIT(Phalcon_Queue_Beanstalk);
	PHALCON_INIT(Phalcon_Queue_Beanstalk_Job);
	PHALCON_INIT(Phalcon_Mvc_View);
	PHALCON_INIT(Phalcon_Mvc_Url);
	PHALCON_INIT(Phalcon_Mvc_Model);
	PHALCON_INIT(Phalcon_Mvc_Micro);
	PHALCON_INIT(Phalcon_Mvc_Application);
	PHALCON_INIT(Phalcon_Mvc_Application_Exception);
	PHALCON_INIT(Phalcon_Mvc_Collection);
	PHALCON_INIT(Phalcon_Mvc_Controller);
	PHALCON_INIT(Phalcon_Mvc_Collection_Exception);
	PHALCON_INIT(Phalcon_Mvc_Collection_Document);
	PHALCON_INIT(Phalcon_Mvc_Collection_ManagerInterface);
	PHALCON_INIT(Phalcon_Mvc_Collection_Manager);
	PHALCON_INIT(Phalcon_Mvc_ControllerInterface);
	PHALCON_INIT(Phalcon_Mvc_Dispatcher);
	PHALCON_INIT(Phalcon_Mvc_Dispatcher_Exception);
	PHALCON_INIT(Phalcon_Mvc_Model_Row);
	PHALCON_INIT(Phalcon_Mvc_Model_Query);
	PHALCON_INIT(Phalcon_Mvc_Micro_Collection);
	PHALCON_INIT(Phalcon_Mvc_Micro_Exception);
	PHALCON_INIT(Phalcon_Mvc_Micro_LazyLoader);
	PHALCON_INIT(Phalcon_Mvc_Micro_MiddlewareInterface);
	PHALCON_INIT(Phalcon_Mvc_Model_Criteria);
	PHALCON_INIT(Phalcon_Mvc_Model_Manager);
	PHALCON_INIT(Phalcon_Mvc_Model_Message);
	PHALCON_INIT(Phalcon_Mvc_Model_Relation);
	PHALCON_INIT(Phalcon_Mvc_Model_Transaction);
	PHALCON_INIT(Phalcon_Mvc_Model_Query_Lang);
	PHALCON_INIT(Phalcon_Mvc_Model_Validator_Url);
	PHALCON_INIT(Phalcon_Mvc_Model_Query_Status);
	PHALCON_INIT(Phalcon_Mvc_Model_MetaData_Apc);
	PHALCON_INIT(Phalcon_Mvc_Model_MetaData_Files);
	PHALCON_INIT(Phalcon_Mvc_Model_Query_Builder);
	PHALCON_INIT(Phalcon_Mvc_Model_Validator_Regex);
	PHALCON_INIT(Phalcon_Mvc_Model_ValidationFailed);
	PHALCON_INIT(Phalcon_Mvc_Model_Resultset_Simple);
	PHALCON_INIT(Phalcon_Mvc_Model_Resultset_Complex);
	PHALCON_INIT(Phalcon_Mvc_Model_MetaData_Memory);
	PHALCON_INIT(Phalcon_Mvc_Model_MetaData_Xcache);
	PHALCON_INIT(Phalcon_Mvc_Model_Validator_Email);
	PHALCON_INIT(Phalcon_Mvc_Model_MetaData_Session);
	PHALCON_INIT(Phalcon_Mvc_Model_Validator_Uniqueness);
	PHALCON_INIT(Phalcon_Mvc_Model_Validator_PresenceOf);
	PHALCON_INIT(Phalcon_Mvc_Model_Transaction_Failed);
	PHALCON_INIT(Phalcon_Mvc_Model_Behavior_SoftDelete);
	PHALCON_INIT(Phalcon_Mvc_Model_Transaction_Manager);
	PHALCON_INIT(Phalcon_Mvc_Model_Behavior_Timestampable);
	PHALCON_INIT(Phalcon_Mvc_Model_MetaData_Strategy_Annotations);
	PHALCON_INIT(Phalcon_Mvc_Model_MetaData_Strategy_Introspection);
	PHALCON_INIT(Phalcon_Mvc_Model_Validator_Inclusionin);
	PHALCON_INIT(Phalcon_Mvc_Model_Validator_Numericality);
	PHALCON_INIT(Phalcon_Mvc_Model_Validator_Exclusionin);
	PHALCON_INIT(Phalcon_Mvc_Model_Validator_StringLength);
	PHALCON_INIT(Phalcon_Mvc_ModuleDefinitionInterface);
	PHALCON_INIT(Phalcon_Mvc_Router_Route);
	PHALCON_INIT(Phalcon_Mvc_Router_Group);
	PHALCON_INIT(Phalcon_Mvc_Router_Exception);
	PHALCON_INIT(Phalcon_Mvc_Router_Annotations);
	PHALCON_INIT(Phalcon_Mvc_User_Module);
	PHALCON_INIT(Phalcon_Mvc_User_Plugin);
	PHALCON_INIT(Phalcon_Mvc_Url_Exception);
	PHALCON_INIT(Phalcon_Mvc_User_Component);
	PHALCON_INIT(Phalcon_Mvc_View_Simple);
	PHALCON_INIT(Phalcon_Mvc_View_Exception);
	PHALCON_INIT(Phalcon_Mvc_View_Engine_Volt);
	PHALCON_INIT(Phalcon_Mvc_View_Engine_Php);
	PHALCON_INIT(Phalcon_Mvc_View_Engine_Volt_Compiler);
	PHALCON_INIT(Phalcon_Events_Event);
	PHALCON_INIT(Phalcon_Events_Manager);
	PHALCON_INIT(Phalcon_Events_Exception);
	PHALCON_INIT(Phalcon_Image);
	PHALCON_INIT(Phalcon_Image_Adapter);
	PHALCON_INIT(Phalcon_Image_AdapterInterface);
	PHALCON_INIT(Phalcon_Image_Exception);
	PHALCON_INIT(Phalcon_Image_Adapter_GD);
	PHALCON_INIT(Phalcon_Image_Adapter_Imagick);
	PHALCON_INIT(Phalcon_Utils_Date);
	PHALCON_INIT(Phalcon_Utils_Arr);

	orig_execute_internal = zend_execute_internal;
	if (!zend_execute_internal && !getenv("PHALCON_NO_RVO")) {
		zend_execute_internal = phalcon_execute_internal;
	}

	return SUCCESS;
}

#ifndef PHALCON_RELEASE
static PHP_MSHUTDOWN_FUNCTION(phalcon){

	assert(PHALCON_GLOBAL(function_cache) == NULL);
	assert(PHALCON_GLOBAL(orm).parser_cache == NULL);
	assert(PHALCON_GLOBAL(orm).ast_cache == NULL);

	return SUCCESS;
}
#endif

static PHP_RINIT_FUNCTION(phalcon){

	php_phalcon_init_globals(PHALCON_VGLOBAL TSRMLS_CC);
	phalcon_init_interned_strings(TSRMLS_C);

	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(phalcon){

	if (PHALCON_GLOBAL(start_memory) != NULL) {
		phalcon_clean_restore_stack(TSRMLS_C);
	}

	if (PHALCON_GLOBAL(function_cache) != NULL) {
		zend_hash_destroy(PHALCON_GLOBAL(function_cache));
		FREE_HASHTABLE(PHALCON_GLOBAL(function_cache));
		PHALCON_GLOBAL(function_cache) = NULL;
	}

	phalcon_orm_destroy_cache(TSRMLS_C);

	return SUCCESS;
}

static PHP_MINFO_FUNCTION(phalcon)
{
	php_info_print_table_start();
	php_info_print_table_row(2, "Phalcon Framework", "enabled");
	php_info_print_table_row(2, "Phalcon Version", PHP_PHALCON_VERSION);
	php_info_print_table_end();
}

static PHP_GINIT_FUNCTION(phalcon)
{
	phalcon_memory_entry *start;

	php_phalcon_init_globals(phalcon_globals TSRMLS_CC);

	start = (phalcon_memory_entry *) pecalloc(1, sizeof(phalcon_memory_entry), 1);
/* pecalloc() will take care of these members
	start->pointer      = 0;
	start->hash_pointer = 0;
	start->prev = NULL;
	start->next = NULL;
*/
	start->addresses       = pecalloc(24, sizeof(zval*), 1);
	start->capacity        = 24;
	start->hash_addresses  = pecalloc(8, sizeof(zval*), 1);
	start->hash_capacity   = 8;

	phalcon_globals->start_memory = start;
}

static PHP_GSHUTDOWN_FUNCTION(phalcon)
{
	assert(phalcon_globals->start_memory != NULL);

	pefree(phalcon_globals->start_memory->hash_addresses, 1);
	pefree(phalcon_globals->start_memory->addresses, 1);
	pefree(phalcon_globals->start_memory, 1);
	phalcon_globals->start_memory = NULL;
}

static
#if ZEND_MODULE_API_NO > 20060613
const
#endif
zend_module_dep phalcon_deps[] = {
	ZEND_MOD_REQUIRED("spl")
#if PHALCON_USE_PHP_JSON
	ZEND_MOD_REQUIRED("json")
#else
	ZEND_MOD_OPTIONAL("json")
#endif
#if PHALCON_USE_PHP_SESSION
	ZEND_MOD_REQUIRED("session")
#else
	ZEND_MOD_OPTIONAL("session")
#endif
#if PHALCON_USE_PHP_PCRE
	ZEND_MOD_REQUIRED("pcre")
#else
	ZEND_MOD_OPTIONAL("pcre")
#endif
	ZEND_MOD_OPTIONAL("filter")
	ZEND_MOD_OPTIONAL("iconv")
	ZEND_MOD_OPTIONAL("libxml")
	ZEND_MOD_OPTIONAL("mbstring")
	ZEND_MOD_OPTIONAL("mcrypt")
	ZEND_MOD_OPTIONAL("openssl")
	ZEND_MOD_OPTIONAL("pdo")
	ZEND_MOD_OPTIONAL("gd")
	ZEND_MOD_OPTIONAL("imagick")
	ZEND_MOD_END
};

zend_module_entry phalcon_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	phalcon_deps,
	PHP_PHALCON_EXTNAME,
	NULL,
	PHP_MINIT(phalcon),
#ifndef PHALCON_RELEASE
	PHP_MSHUTDOWN(phalcon),
#else
	NULL
#endif
	PHP_RINIT(phalcon),
	PHP_RSHUTDOWN(phalcon),
	PHP_MINFO(phalcon),
	PHP_PHALCON_VERSION,
	ZEND_MODULE_GLOBALS(phalcon),
	PHP_GINIT(phalcon),
	PHP_GSHUTDOWN(phalcon),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_PHALCON
ZEND_GET_MODULE(phalcon)
#endif
