
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "ext/standard/info.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

zend_class_entry *phalcon_exception_ce;
zend_class_entry *phalcon_di_injectable_ce;
zend_class_entry *phalcon_assets_resource_ce;
zend_class_entry *phalcon_flash_ce;
zend_class_entry *phalcon_validation_validator_ce;
zend_class_entry *phalcon_acl_adapter_ce;
zend_class_entry *phalcon_di_ce;
zend_class_entry *phalcon_di_factorydefault_ce;
zend_class_entry *phalcon_dispatcher_ce;
zend_class_entry *phalcon_mvc_model_exception_ce;
zend_class_entry *phalcon_session_adapter_ce;
zend_class_entry *phalcon_acl_ce;
zend_class_entry *phalcon_acl_adapter_memory_ce;
zend_class_entry *phalcon_acl_exception_ce;
zend_class_entry *phalcon_acl_resource_ce;
zend_class_entry *phalcon_acl_role_ce;
zend_class_entry *phalcon_annotations_adapter_ce;
zend_class_entry *phalcon_annotations_adapter_apc_ce;
zend_class_entry *phalcon_annotations_adapter_files_ce;
zend_class_entry *phalcon_annotations_adapter_memory_ce;
zend_class_entry *phalcon_annotations_adapter_xcache_ce;
zend_class_entry *phalcon_annotations_annotation_ce;
zend_class_entry *phalcon_annotations_collection_ce;
zend_class_entry *phalcon_annotations_exception_ce;
zend_class_entry *phalcon_annotations_reader_ce;
zend_class_entry *phalcon_annotations_reflection_ce;
zend_class_entry *phalcon_assets_collection_ce;
zend_class_entry *phalcon_assets_exception_ce;
zend_class_entry *phalcon_assets_filters_cssmin_ce;
zend_class_entry *phalcon_assets_filters_jsmin_ce;
zend_class_entry *phalcon_assets_filters_none_ce;
zend_class_entry *phalcon_assets_manager_ce;
zend_class_entry *phalcon_assets_resource_css_ce;
zend_class_entry *phalcon_assets_resource_js_ce;
zend_class_entry *phalcon_cache_backend_ce;
zend_class_entry *phalcon_cache_backend_apc_ce;
zend_class_entry *phalcon_cache_backend_file_ce;
zend_class_entry *phalcon_cache_backend_libmemcached_ce;
zend_class_entry *phalcon_cache_backend_memcache_ce;
zend_class_entry *phalcon_cache_backend_memory_ce;
zend_class_entry *phalcon_cache_backend_mongo_ce;
zend_class_entry *phalcon_cache_backend_xcache_ce;
zend_class_entry *phalcon_cache_exception_ce;
zend_class_entry *phalcon_cache_frontend_base64_ce;
zend_class_entry *phalcon_cache_frontend_data_ce;
zend_class_entry *phalcon_cache_frontend_igbinary_ce;
zend_class_entry *phalcon_cache_frontend_json_ce;
zend_class_entry *phalcon_cache_frontend_none_ce;
zend_class_entry *phalcon_cache_frontend_output_ce;
zend_class_entry *phalcon_cache_multiple_ce;
zend_class_entry *phalcon_cli_console_ce;
zend_class_entry *phalcon_cli_console_exception_ce;
zend_class_entry *phalcon_cli_dispatcher_ce;
zend_class_entry *phalcon_cli_dispatcher_exception_ce;
zend_class_entry *phalcon_cli_router_ce;
zend_class_entry *phalcon_cli_router_exception_ce;
zend_class_entry *phalcon_cli_task_ce;
zend_class_entry *phalcon_config_ce;
zend_class_entry *phalcon_config_adapter_ini_ce;
zend_class_entry *phalcon_config_adapter_json_ce;
zend_class_entry *phalcon_config_exception_ce;
zend_class_entry *phalcon_crypt_ce;
zend_class_entry *phalcon_crypt_exception_ce;
zend_class_entry *phalcon_db_ce;
zend_class_entry *phalcon_db_adapter_ce;
zend_class_entry *phalcon_db_adapter_pdo_ce;
zend_class_entry *phalcon_db_adapter_pdo_mysql_ce;
zend_class_entry *phalcon_db_adapter_pdo_oracle_ce;
zend_class_entry *phalcon_db_adapter_pdo_postgresql_ce;
zend_class_entry *phalcon_db_adapter_pdo_sqlite_ce;
zend_class_entry *phalcon_db_column_ce;
zend_class_entry *phalcon_db_dialect_ce;
zend_class_entry *phalcon_db_dialect_mysql_ce;
zend_class_entry *phalcon_db_dialect_oracle_ce;
zend_class_entry *phalcon_db_dialect_postgresql_ce;
zend_class_entry *phalcon_db_dialect_sqlite_ce;
zend_class_entry *phalcon_db_exception_ce;
zend_class_entry *phalcon_db_index_ce;
zend_class_entry *phalcon_db_profiler_ce;
zend_class_entry *phalcon_db_profiler_item_ce;
zend_class_entry *phalcon_db_rawvalue_ce;
zend_class_entry *phalcon_db_reference_ce;
zend_class_entry *phalcon_db_result_pdo_ce;
zend_class_entry *phalcon_debug_ce;
zend_class_entry *phalcon_di_exception_ce;
zend_class_entry *phalcon_di_factorydefault_cli_ce;
zend_class_entry *phalcon_di_service_ce;
zend_class_entry *phalcon_di_service_builder_ce;
zend_class_entry *phalcon_escaper_ce;
zend_class_entry *phalcon_escaper_exception_ce;
zend_class_entry *phalcon_events_event_ce;
zend_class_entry *phalcon_events_exception_ce;
zend_class_entry *phalcon_events_manager_ce;
zend_class_entry *phalcon_filter_ce;
zend_class_entry *phalcon_filter_exception_ce;
zend_class_entry *phalcon_flash_direct_ce;
zend_class_entry *phalcon_flash_exception_ce;
zend_class_entry *phalcon_flash_session_ce;
zend_class_entry *phalcon_forms_element_ce;
zend_class_entry *phalcon_forms_element_check_ce;
zend_class_entry *phalcon_forms_element_date_ce;
zend_class_entry *phalcon_forms_element_email_ce;
zend_class_entry *phalcon_forms_element_file_ce;
zend_class_entry *phalcon_forms_element_hidden_ce;
zend_class_entry *phalcon_forms_element_numeric_ce;
zend_class_entry *phalcon_forms_element_password_ce;
zend_class_entry *phalcon_forms_element_select_ce;
zend_class_entry *phalcon_forms_element_submit_ce;
zend_class_entry *phalcon_forms_element_text_ce;
zend_class_entry *phalcon_forms_element_textarea_ce;
zend_class_entry *phalcon_forms_exception_ce;
zend_class_entry *phalcon_forms_form_ce;
zend_class_entry *phalcon_forms_manager_ce;
zend_class_entry *phalcon_http_cookie_ce;
zend_class_entry *phalcon_http_cookie_exception_ce;
zend_class_entry *phalcon_http_request_ce;
zend_class_entry *phalcon_http_request_exception_ce;
zend_class_entry *phalcon_http_request_file_ce;
zend_class_entry *phalcon_http_response_ce;
zend_class_entry *phalcon_http_response_cookies_ce;
zend_class_entry *phalcon_http_response_exception_ce;
zend_class_entry *phalcon_http_response_headers_ce;
zend_class_entry *phalcon_image_ce;
zend_class_entry *phalcon_image_adapter_ce;
zend_class_entry *phalcon_image_adapter_gd_ce;
zend_class_entry *phalcon_image_adapter_imagick_ce;
zend_class_entry *phalcon_image_adapterinterface_ce;
zend_class_entry *phalcon_image_exception_ce;
zend_class_entry *phalcon_kernel_ce;
zend_class_entry *phalcon_loader_ce;
zend_class_entry *phalcon_loader_exception_ce;
zend_class_entry *phalcon_logger_ce;
zend_class_entry *phalcon_logger_adapter_ce;
zend_class_entry *phalcon_logger_adapter_file_ce;
zend_class_entry *phalcon_logger_adapter_firephp_ce;
zend_class_entry *phalcon_logger_adapter_stream_ce;
zend_class_entry *phalcon_logger_adapter_syslog_ce;
zend_class_entry *phalcon_logger_exception_ce;
zend_class_entry *phalcon_logger_formatter_ce;
zend_class_entry *phalcon_logger_formatter_firephp_ce;
zend_class_entry *phalcon_logger_formatter_json_ce;
zend_class_entry *phalcon_logger_formatter_line_ce;
zend_class_entry *phalcon_logger_formatter_syslog_ce;
zend_class_entry *phalcon_logger_item_ce;
zend_class_entry *phalcon_logger_multiple_ce;
zend_class_entry *phalcon_mvc_application_ce;
zend_class_entry *phalcon_mvc_application_exception_ce;
zend_class_entry *phalcon_mvc_collection_ce;
zend_class_entry *phalcon_mvc_collection_document_ce;
zend_class_entry *phalcon_mvc_collection_exception_ce;
zend_class_entry *phalcon_mvc_collection_manager_ce;
zend_class_entry *phalcon_mvc_controller_ce;
zend_class_entry *phalcon_mvc_dispatcher_ce;
zend_class_entry *phalcon_mvc_dispatcher_exception_ce;
zend_class_entry *phalcon_mvc_micro_ce;
zend_class_entry *phalcon_mvc_micro_collection_ce;
zend_class_entry *phalcon_mvc_micro_exception_ce;
zend_class_entry *phalcon_mvc_micro_lazyloader_ce;
zend_class_entry *phalcon_mvc_model_ce;
zend_class_entry *phalcon_mvc_model_behavior_ce;
zend_class_entry *phalcon_mvc_model_behavior_softdelete_ce;
zend_class_entry *phalcon_mvc_model_behavior_timestampable_ce;
zend_class_entry *phalcon_mvc_model_criteria_ce;
zend_class_entry *phalcon_mvc_model_manager_ce;
zend_class_entry *phalcon_mvc_model_message_ce;
zend_class_entry *phalcon_mvc_model_metadata_ce;
zend_class_entry *phalcon_mvc_model_metadata_apc_ce;
zend_class_entry *phalcon_mvc_model_metadata_files_ce;
zend_class_entry *phalcon_mvc_model_metadata_memory_ce;
zend_class_entry *phalcon_mvc_model_metadata_session_ce;
zend_class_entry *phalcon_mvc_model_metadata_strategy_annotations_ce;
zend_class_entry *phalcon_mvc_model_metadata_strategy_introspection_ce;
zend_class_entry *phalcon_mvc_model_metadata_xcache_ce;
zend_class_entry *phalcon_mvc_model_query_ce;
zend_class_entry *phalcon_mvc_model_query_builder_ce;
zend_class_entry *phalcon_mvc_model_query_lang_ce;
zend_class_entry *phalcon_mvc_model_query_status_ce;
zend_class_entry *phalcon_mvc_model_relation_ce;
zend_class_entry *phalcon_mvc_model_resultset_ce;
zend_class_entry *phalcon_mvc_model_resultset_complex_ce;
zend_class_entry *phalcon_mvc_model_resultset_simple_ce;
zend_class_entry *phalcon_mvc_model_row_ce;
zend_class_entry *phalcon_mvc_model_transaction_ce;
zend_class_entry *phalcon_mvc_model_transaction_exception_ce;
zend_class_entry *phalcon_mvc_model_transaction_failed_ce;
zend_class_entry *phalcon_mvc_model_transaction_manager_ce;
zend_class_entry *phalcon_mvc_model_validationfailed_ce;
zend_class_entry *phalcon_mvc_model_validator_ce;
zend_class_entry *phalcon_mvc_model_validator_email_ce;
zend_class_entry *phalcon_mvc_model_validator_exclusionin_ce;
zend_class_entry *phalcon_mvc_model_validator_inclusionin_ce;
zend_class_entry *phalcon_mvc_model_validator_numericality_ce;
zend_class_entry *phalcon_mvc_model_validator_presenceof_ce;
zend_class_entry *phalcon_mvc_model_validator_regex_ce;
zend_class_entry *phalcon_mvc_model_validator_stringlength_ce;
zend_class_entry *phalcon_mvc_model_validator_uniqueness_ce;
zend_class_entry *phalcon_mvc_model_validator_url_ce;
zend_class_entry *phalcon_mvc_router_ce;
zend_class_entry *phalcon_mvc_router_annotations_ce;
zend_class_entry *phalcon_mvc_router_exception_ce;
zend_class_entry *phalcon_mvc_router_group_ce;
zend_class_entry *phalcon_mvc_router_route_ce;
zend_class_entry *phalcon_mvc_url_ce;
zend_class_entry *phalcon_mvc_url_exception_ce;
zend_class_entry *phalcon_mvc_user_component_ce;
zend_class_entry *phalcon_mvc_user_module_ce;
zend_class_entry *phalcon_mvc_user_plugin_ce;
zend_class_entry *phalcon_mvc_view_ce;
zend_class_entry *phalcon_mvc_view_engine_ce;
zend_class_entry *phalcon_mvc_view_engine_php_ce;
zend_class_entry *phalcon_mvc_view_engine_volt_ce;
zend_class_entry *phalcon_mvc_view_engine_volt_compiler_ce;
zend_class_entry *phalcon_mvc_view_exception_ce;
zend_class_entry *phalcon_mvc_view_simple_ce;
zend_class_entry *phalcon_paginator_adapter_model_ce;
zend_class_entry *phalcon_paginator_adapter_nativearray_ce;
zend_class_entry *phalcon_paginator_adapter_querybuilder_ce;
zend_class_entry *phalcon_paginator_exception_ce;
zend_class_entry *phalcon_queue_beanstalk_ce;
zend_class_entry *phalcon_queue_beanstalk_job_ce;
zend_class_entry *phalcon_security_ce;
zend_class_entry *phalcon_security_exception_ce;
zend_class_entry *phalcon_session_ce;
zend_class_entry *phalcon_session_adapter_files_ce;
zend_class_entry *phalcon_session_bag_ce;
zend_class_entry *phalcon_session_exception_ce;
zend_class_entry *phalcon_tag_ce;
zend_class_entry *phalcon_tag_exception_ce;
zend_class_entry *phalcon_tag_select_ce;
zend_class_entry *phalcon_text_ce;
zend_class_entry *phalcon_translate_ce;
zend_class_entry *phalcon_translate_adapter_ce;
zend_class_entry *phalcon_translate_adapter_nativearray_ce;
zend_class_entry *phalcon_translate_exception_ce;
zend_class_entry *phalcon_validation_ce;
zend_class_entry *phalcon_validation_exception_ce;
zend_class_entry *phalcon_validation_message_ce;
zend_class_entry *phalcon_validation_message_group_ce;
zend_class_entry *phalcon_validation_validator_between_ce;
zend_class_entry *phalcon_validation_validator_confirmation_ce;
zend_class_entry *phalcon_validation_validator_email_ce;
zend_class_entry *phalcon_validation_validator_exclusionin_ce;
zend_class_entry *phalcon_validation_validator_identical_ce;
zend_class_entry *phalcon_validation_validator_inclusionin_ce;
zend_class_entry *phalcon_validation_validator_presenceof_ce;
zend_class_entry *phalcon_validation_validator_regex_ce;
zend_class_entry *phalcon_validation_validator_stringlength_ce;
zend_class_entry *phalcon_version_ce;

ZEND_DECLARE_MODULE_GLOBALS(phalcon)

PHP_MINIT_FUNCTION(phalcon){

	/** Init globals */
	ZEND_INIT_MODULE_GLOBALS(phalcon, php_zephir_init_globals, NULL);

	ZEPHIR_INIT(Phalcon_Exception);
	ZEPHIR_INIT(Phalcon_DI_Injectable);
	ZEPHIR_INIT(Phalcon_Assets_Resource);
	ZEPHIR_INIT(Phalcon_Flash);
	ZEPHIR_INIT(Phalcon_Validation_Validator);
	ZEPHIR_INIT(Phalcon_Acl_Adapter);
	ZEPHIR_INIT(Phalcon_Di);
	ZEPHIR_INIT(Phalcon_DI_FactoryDefault);
	ZEPHIR_INIT(Phalcon_Dispatcher);
	ZEPHIR_INIT(Phalcon_Mvc_Model_Exception);
	ZEPHIR_INIT(Phalcon_Session_Adapter);
	ZEPHIR_INIT(Phalcon_Acl);
	ZEPHIR_INIT(Phalcon_Acl_Adapter_Memory);
	ZEPHIR_INIT(Phalcon_Acl_Exception);
	ZEPHIR_INIT(Phalcon_Acl_Resource);
	ZEPHIR_INIT(Phalcon_Acl_Role);
	ZEPHIR_INIT(Phalcon_Annotations_Adapter);
	ZEPHIR_INIT(Phalcon_Annotations_Adapter_Apc);
	ZEPHIR_INIT(Phalcon_Annotations_Adapter_Files);
	ZEPHIR_INIT(Phalcon_Annotations_Adapter_Memory);
	ZEPHIR_INIT(Phalcon_Annotations_Adapter_Xcache);
	ZEPHIR_INIT(Phalcon_Annotations_Annotation);
	ZEPHIR_INIT(Phalcon_Annotations_Collection);
	ZEPHIR_INIT(Phalcon_Annotations_Exception);
	ZEPHIR_INIT(Phalcon_Annotations_Reader);
	ZEPHIR_INIT(Phalcon_Annotations_Reflection);
	ZEPHIR_INIT(Phalcon_Assets_Collection);
	ZEPHIR_INIT(Phalcon_Assets_Exception);
	ZEPHIR_INIT(Phalcon_Assets_Filters_Cssmin);
	ZEPHIR_INIT(Phalcon_Assets_Filters_Jsmin);
	ZEPHIR_INIT(Phalcon_Assets_Filters_None);
	ZEPHIR_INIT(Phalcon_Assets_Manager);
	ZEPHIR_INIT(Phalcon_Assets_Resource_Css);
	ZEPHIR_INIT(Phalcon_Assets_Resource_Js);
	ZEPHIR_INIT(Phalcon_Cache_Backend);
	ZEPHIR_INIT(Phalcon_Cache_Backend_Apc);
	ZEPHIR_INIT(Phalcon_Cache_Backend_File);
	ZEPHIR_INIT(Phalcon_Cache_Backend_Libmemcached);
	ZEPHIR_INIT(Phalcon_Cache_Backend_Memcache);
	ZEPHIR_INIT(Phalcon_Cache_Backend_Memory);
	ZEPHIR_INIT(Phalcon_Cache_Backend_Mongo);
	ZEPHIR_INIT(Phalcon_Cache_Backend_XCache);
	ZEPHIR_INIT(Phalcon_Cache_Exception);
	ZEPHIR_INIT(Phalcon_Cache_Frontend_Base64);
	ZEPHIR_INIT(Phalcon_Cache_Frontend_Data);
	ZEPHIR_INIT(Phalcon_Cache_Frontend_IgBinary);
	ZEPHIR_INIT(Phalcon_Cache_Frontend_Json);
	ZEPHIR_INIT(Phalcon_Cache_Frontend_None);
	ZEPHIR_INIT(Phalcon_Cache_Frontend_Output);
	ZEPHIR_INIT(Phalcon_Cache_Multiple);
	ZEPHIR_INIT(Phalcon_Cli_Console);
	ZEPHIR_INIT(Phalcon_CLI_Console_Exception);
	ZEPHIR_INIT(Phalcon_CLI_Dispatcher);
	ZEPHIR_INIT(Phalcon_CLI_Dispatcher_Exception);
	ZEPHIR_INIT(Phalcon_CLI_Router);
	ZEPHIR_INIT(Phalcon_CLI_Router_Exception);
	ZEPHIR_INIT(Phalcon_CLI_Task);
	ZEPHIR_INIT(Phalcon_Config);
	ZEPHIR_INIT(Phalcon_Config_Adapter_Ini);
	ZEPHIR_INIT(Phalcon_Config_Adapter_Json);
	ZEPHIR_INIT(Phalcon_Config_Exception);
	ZEPHIR_INIT(Phalcon_Crypt);
	ZEPHIR_INIT(Phalcon_Crypt_Exception);
	ZEPHIR_INIT(Phalcon_Db);
	ZEPHIR_INIT(Phalcon_Db_Adapter);
	ZEPHIR_INIT(Phalcon_Db_Adapter_Pdo);
	ZEPHIR_INIT(Phalcon_Db_Adapter_Pdo_MySQL);
	ZEPHIR_INIT(Phalcon_Db_Adapter_Pdo_Oracle);
	ZEPHIR_INIT(Phalcon_Db_Adapter_Pdo_PostgreSQL);
	ZEPHIR_INIT(Phalcon_Db_Adapter_Pdo_Sqlite);
	ZEPHIR_INIT(Phalcon_Db_Column);
	ZEPHIR_INIT(Phalcon_Db_Dialect);
	ZEPHIR_INIT(Phalcon_Db_Dialect_MySQL);
	ZEPHIR_INIT(Phalcon_Db_Dialect_Oracle);
	ZEPHIR_INIT(Phalcon_Db_Dialect_PostgreSQL);
	ZEPHIR_INIT(Phalcon_Db_Dialect_Sqlite);
	ZEPHIR_INIT(Phalcon_Db_Exception);
	ZEPHIR_INIT(Phalcon_Db_Index);
	ZEPHIR_INIT(Phalcon_Db_Profiler);
	ZEPHIR_INIT(Phalcon_Db_Profiler_Item);
	ZEPHIR_INIT(Phalcon_Db_RawValue);
	ZEPHIR_INIT(Phalcon_Db_Reference);
	ZEPHIR_INIT(Phalcon_Db_Result_Pdo);
	ZEPHIR_INIT(Phalcon_Debug);
	ZEPHIR_INIT(Phalcon_DI_Exception);
	ZEPHIR_INIT(Phalcon_DI_FactoryDefault_Cli);
	ZEPHIR_INIT(Phalcon_DI_Service);
	ZEPHIR_INIT(Phalcon_DI_Service_Builder);
	ZEPHIR_INIT(Phalcon_Escaper);
	ZEPHIR_INIT(Phalcon_Escaper_Exception);
	ZEPHIR_INIT(Phalcon_Events_Event);
	ZEPHIR_INIT(Phalcon_Events_Exception);
	ZEPHIR_INIT(Phalcon_Events_Manager);
	ZEPHIR_INIT(Phalcon_Filter);
	ZEPHIR_INIT(Phalcon_Filter_Exception);
	ZEPHIR_INIT(Phalcon_Flash_Direct);
	ZEPHIR_INIT(Phalcon_Flash_Exception);
	ZEPHIR_INIT(Phalcon_Flash_Session);
	ZEPHIR_INIT(Phalcon_Forms_Element);
	ZEPHIR_INIT(Phalcon_Forms_Element_Check);
	ZEPHIR_INIT(Phalcon_Forms_Element_Date);
	ZEPHIR_INIT(Phalcon_Forms_Element_Email);
	ZEPHIR_INIT(Phalcon_Forms_Element_File);
	ZEPHIR_INIT(Phalcon_Forms_Element_Hidden);
	ZEPHIR_INIT(Phalcon_Forms_Element_Numeric);
	ZEPHIR_INIT(Phalcon_Forms_Element_Password);
	ZEPHIR_INIT(Phalcon_Forms_Element_Select);
	ZEPHIR_INIT(Phalcon_Forms_Element_Submit);
	ZEPHIR_INIT(Phalcon_Forms_Element_Text);
	ZEPHIR_INIT(Phalcon_Forms_Element_Textarea);
	ZEPHIR_INIT(Phalcon_Forms_Exception);
	ZEPHIR_INIT(Phalcon_Forms_Form);
	ZEPHIR_INIT(Phalcon_Forms_Manager);
	ZEPHIR_INIT(Phalcon_Http_Cookie);
	ZEPHIR_INIT(Phalcon_Http_Cookie_Exception);
	ZEPHIR_INIT(Phalcon_Http_Request);
	ZEPHIR_INIT(Phalcon_Http_Request_Exception);
	ZEPHIR_INIT(Phalcon_Http_Request_File);
	ZEPHIR_INIT(Phalcon_Http_Response);
	ZEPHIR_INIT(Phalcon_Http_Response_Cookies);
	ZEPHIR_INIT(Phalcon_Http_Response_Exception);
	ZEPHIR_INIT(Phalcon_Http_Response_Headers);
	ZEPHIR_INIT(Phalcon_Image);
	ZEPHIR_INIT(Phalcon_Image_Adapter);
	ZEPHIR_INIT(Phalcon_Image_Adapter_Gd);
	ZEPHIR_INIT(Phalcon_Image_Adapter_Imagick);
	ZEPHIR_INIT(Phalcon_Image_AdapterInterface);
	ZEPHIR_INIT(Phalcon_Image_Exception);
	ZEPHIR_INIT(Phalcon_Kernel);
	ZEPHIR_INIT(Phalcon_Loader);
	ZEPHIR_INIT(Phalcon_Loader_Exception);
	ZEPHIR_INIT(Phalcon_Logger);
	ZEPHIR_INIT(Phalcon_Logger_Adapter);
	ZEPHIR_INIT(Phalcon_Logger_Adapter_File);
	ZEPHIR_INIT(Phalcon_Logger_Adapter_FirePHP);
	ZEPHIR_INIT(Phalcon_Logger_Adapter_Stream);
	ZEPHIR_INIT(Phalcon_Logger_Adapter_Syslog);
	ZEPHIR_INIT(Phalcon_Logger_Exception);
	ZEPHIR_INIT(Phalcon_Logger_Formatter);
	ZEPHIR_INIT(Phalcon_Logger_Formatter_FirePHP);
	ZEPHIR_INIT(Phalcon_Logger_Formatter_Json);
	ZEPHIR_INIT(Phalcon_Logger_Formatter_Line);
	ZEPHIR_INIT(Phalcon_Logger_Formatter_Syslog);
	ZEPHIR_INIT(Phalcon_Logger_Item);
	ZEPHIR_INIT(Phalcon_Logger_Multiple);
	ZEPHIR_INIT(Phalcon_Mvc_Application);
	ZEPHIR_INIT(Phalcon_Mvc_Application_Exception);
	ZEPHIR_INIT(Phalcon_Mvc_Collection);
	ZEPHIR_INIT(Phalcon_Mvc_Collection_Document);
	ZEPHIR_INIT(Phalcon_Mvc_Collection_Exception);
	ZEPHIR_INIT(Phalcon_Mvc_Collection_Manager);
	ZEPHIR_INIT(Phalcon_Mvc_Controller);
	ZEPHIR_INIT(Phalcon_Mvc_Dispatcher);
	ZEPHIR_INIT(Phalcon_Mvc_Dispatcher_Exception);
	ZEPHIR_INIT(Phalcon_Mvc_Micro);
	ZEPHIR_INIT(Phalcon_Mvc_Micro_Collection);
	ZEPHIR_INIT(Phalcon_Mvc_Micro_Exception);
	ZEPHIR_INIT(Phalcon_Mvc_Micro_LazyLoader);
	ZEPHIR_INIT(Phalcon_Mvc_Model);
	ZEPHIR_INIT(Phalcon_Mvc_Model_Behavior);
	ZEPHIR_INIT(Phalcon_Mvc_Model_Behavior_SoftDelete);
	ZEPHIR_INIT(Phalcon_Mvc_Model_Behavior_Timestampable);
	ZEPHIR_INIT(Phalcon_Mvc_Model_Criteria);
	ZEPHIR_INIT(Phalcon_Mvc_Model_Manager);
	ZEPHIR_INIT(Phalcon_Mvc_Model_Message);
	ZEPHIR_INIT(Phalcon_Mvc_Model_MetaData);
	ZEPHIR_INIT(Phalcon_Mvc_Model_MetaData_Apc);
	ZEPHIR_INIT(Phalcon_Mvc_Model_MetaData_Files);
	ZEPHIR_INIT(Phalcon_Mvc_Model_MetaData_Memory);
	ZEPHIR_INIT(Phalcon_Mvc_Model_MetaData_Session);
	ZEPHIR_INIT(Phalcon_Mvc_Model_MetaData_Strategy_Annotations);
	ZEPHIR_INIT(Phalcon_Mvc_Model_MetaData_Strategy_Introspection);
	ZEPHIR_INIT(Phalcon_Mvc_Model_MetaData_XCache);
	ZEPHIR_INIT(Phalcon_Mvc_Model_Query);
	ZEPHIR_INIT(Phalcon_Mvc_Model_Query_Builder);
	ZEPHIR_INIT(Phalcon_Mvc_Model_Query_Lang);
	ZEPHIR_INIT(Phalcon_Mvc_Model_Query_Status);
	ZEPHIR_INIT(Phalcon_Mvc_Model_Relation);
	ZEPHIR_INIT(Phalcon_Mvc_Model_Resultset);
	ZEPHIR_INIT(Phalcon_Mvc_Model_Resultset_Complex);
	ZEPHIR_INIT(Phalcon_Mvc_Model_Resultset_Simple);
	ZEPHIR_INIT(Phalcon_Mvc_Model_Row);
	ZEPHIR_INIT(Phalcon_Mvc_Model_Transaction);
	ZEPHIR_INIT(Phalcon_Mvc_Model_Transaction_Exception);
	ZEPHIR_INIT(Phalcon_Mvc_Model_Transaction_Failed);
	ZEPHIR_INIT(Phalcon_Mvc_Model_Transaction_Manager);
	ZEPHIR_INIT(Phalcon_Mvc_Model_ValidationFailed);
	ZEPHIR_INIT(Phalcon_Mvc_Model_Validator);
	ZEPHIR_INIT(Phalcon_Mvc_Model_Validator_Email);
	ZEPHIR_INIT(Phalcon_Mvc_Model_Validator_ExclusionIn);
	ZEPHIR_INIT(Phalcon_Mvc_Model_Validator_InclusionIn);
	ZEPHIR_INIT(Phalcon_Mvc_Model_Validator_Numericality);
	ZEPHIR_INIT(Phalcon_Mvc_Model_Validator_PresenceOf);
	ZEPHIR_INIT(Phalcon_Mvc_Model_Validator_Regex);
	ZEPHIR_INIT(Phalcon_Mvc_Model_Validator_StringLength);
	ZEPHIR_INIT(Phalcon_Mvc_Model_Validator_Uniqueness);
	ZEPHIR_INIT(Phalcon_Mvc_Model_Validator_Url);
	ZEPHIR_INIT(Phalcon_Mvc_Router);
	ZEPHIR_INIT(Phalcon_Mvc_Router_Annotations);
	ZEPHIR_INIT(Phalcon_Mvc_Router_Exception);
	ZEPHIR_INIT(Phalcon_Mvc_Router_Group);
	ZEPHIR_INIT(Phalcon_Mvc_Router_Route);
	ZEPHIR_INIT(Phalcon_Mvc_Url);
	ZEPHIR_INIT(Phalcon_Mvc_Url_Exception);
	ZEPHIR_INIT(Phalcon_Mvc_User_Component);
	ZEPHIR_INIT(Phalcon_Mvc_User_Module);
	ZEPHIR_INIT(Phalcon_Mvc_User_Plugin);
	ZEPHIR_INIT(Phalcon_Mvc_View);
	ZEPHIR_INIT(Phalcon_Mvc_View_Engine);
	ZEPHIR_INIT(Phalcon_Mvc_View_Engine_Php);
	ZEPHIR_INIT(Phalcon_Mvc_View_Engine_Volt);
	ZEPHIR_INIT(Phalcon_Mvc_View_Engine_Volt_Compiler);
	ZEPHIR_INIT(Phalcon_Mvc_View_Exception);
	ZEPHIR_INIT(Phalcon_Mvc_View_Simple);
	ZEPHIR_INIT(Phalcon_Paginator_Adapter_Model);
	ZEPHIR_INIT(Phalcon_Paginator_Adapter_NativeArray);
	ZEPHIR_INIT(Phalcon_Paginator_Adapter_QueryBuilder);
	ZEPHIR_INIT(Phalcon_Paginator_Exception);
	ZEPHIR_INIT(Phalcon_Queue_Beanstalk);
	ZEPHIR_INIT(Phalcon_Queue_Beanstalk_Job);
	ZEPHIR_INIT(Phalcon_Security);
	ZEPHIR_INIT(Phalcon_Security_Exception);
	ZEPHIR_INIT(Phalcon_Session);
	ZEPHIR_INIT(Phalcon_Session_Adapter_Files);
	ZEPHIR_INIT(Phalcon_Session_Bag);
	ZEPHIR_INIT(Phalcon_Session_Exception);
	ZEPHIR_INIT(Phalcon_Tag);
	ZEPHIR_INIT(Phalcon_Tag_Exception);
	ZEPHIR_INIT(Phalcon_Tag_Select);
	ZEPHIR_INIT(Phalcon_Text);
	ZEPHIR_INIT(Phalcon_Translate);
	ZEPHIR_INIT(Phalcon_Translate_Adapter);
	ZEPHIR_INIT(Phalcon_Translate_Adapter_NativeArray);
	ZEPHIR_INIT(Phalcon_Translate_Exception);
	ZEPHIR_INIT(Phalcon_Validation);
	ZEPHIR_INIT(Phalcon_Validation_Exception);
	ZEPHIR_INIT(Phalcon_Validation_Message);
	ZEPHIR_INIT(Phalcon_Validation_Message_Group);
	ZEPHIR_INIT(Phalcon_Validation_Validator_Between);
	ZEPHIR_INIT(Phalcon_Validation_Validator_Confirmation);
	ZEPHIR_INIT(Phalcon_Validation_Validator_Email);
	ZEPHIR_INIT(Phalcon_Validation_Validator_ExclusionIn);
	ZEPHIR_INIT(Phalcon_Validation_Validator_Identical);
	ZEPHIR_INIT(Phalcon_Validation_Validator_InclusionIn);
	ZEPHIR_INIT(Phalcon_Validation_Validator_PresenceOf);
	ZEPHIR_INIT(Phalcon_Validation_Validator_Regex);
	ZEPHIR_INIT(Phalcon_Validation_Validator_StringLength);
	ZEPHIR_INIT(Phalcon_Version);
	return SUCCESS;
}

#ifndef PHALCON_RELEASE
static PHP_MSHUTDOWN_FUNCTION(phalcon){

	assert(ZEPHIR_GLOBAL(function_cache) == NULL);
	//assert(ZEPHIR_GLOBAL(orm).parser_cache == NULL);
	//assert(ZEPHIR_GLOBAL(orm).ast_cache == NULL);

	return SUCCESS;
}
#endif

static PHP_RINIT_FUNCTION(phalcon){

	php_zephir_init_globals(ZEPHIR_VGLOBAL TSRMLS_CC);
	//phalcon_init_interned_strings(TSRMLS_C);

	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(phalcon){

	if (ZEPHIR_GLOBAL(start_memory) != NULL) {
		zephir_clean_restore_stack(TSRMLS_C);
	}

	if (ZEPHIR_GLOBAL(function_cache) != NULL) {
		zend_hash_destroy(ZEPHIR_GLOBAL(function_cache));
		FREE_HASHTABLE(ZEPHIR_GLOBAL(function_cache));
		ZEPHIR_GLOBAL(function_cache) = NULL;
	}

	return SUCCESS;
}

static PHP_MINFO_FUNCTION(phalcon)
{
	php_info_print_table_start();
	php_info_print_table_row(2, "Version", PHP_PHALCON_VERSION);
	php_info_print_table_end();
}

static PHP_GINIT_FUNCTION(phalcon)
{
	zephir_memory_entry *start;

	php_zephir_init_globals(zephir_globals TSRMLS_CC);

	start = (zephir_memory_entry *) pecalloc(1, sizeof(zephir_memory_entry), 1);
	start->addresses       = pecalloc(24, sizeof(zval*), 1);
	start->capacity        = 24;
	start->hash_addresses  = pecalloc(8, sizeof(zval*), 1);
	start->hash_capacity   = 8;

	zephir_globals->start_memory = start;
}

static PHP_GSHUTDOWN_FUNCTION(phalcon)
{
	assert(zephir_globals->start_memory != NULL);

	pefree(zephir_globals->start_memory->hash_addresses, 1);
	pefree(zephir_globals->start_memory->addresses, 1);
	pefree(zephir_globals->start_memory, 1);
	zephir_globals->start_memory = NULL;
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
	NULL,
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
