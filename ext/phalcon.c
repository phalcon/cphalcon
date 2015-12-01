
/*
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

#include "php_phalcon.h"

#include <main/php_ini.h>
#include <ext/standard/info.h>
#include <Zend/zend_extensions.h>

#if PHP_VERSION_ID < 50500
#include <locale.h>
#endif

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/mbstring.h"
#include "interned-strings.h"

#include "phalcon.h"

int nusphere_dbg_present;

ZEND_DECLARE_MODULE_GLOBALS(phalcon)

PHP_INI_BEGIN()
	/* Enables/Disables debug */
	STD_PHP_INI_BOOLEAN("phalcon.debug.enable_debug",           "0", PHP_INI_ALL,    OnUpdateBool, debug.enable_debug,           zend_phalcon_globals, phalcon_globals)
	/* Enables/Disables globally the internal events */
	STD_PHP_INI_BOOLEAN("phalcon.orm.events",                   "1", PHP_INI_ALL,    OnUpdateBool, orm.events,                   zend_phalcon_globals, phalcon_globals)
	/* Enables/Disables virtual foreign keys */
	STD_PHP_INI_BOOLEAN("phalcon.orm.virtual_foreign_keys",     "1", PHP_INI_ALL,    OnUpdateBool, orm.virtual_foreign_keys,     zend_phalcon_globals, phalcon_globals)
	/* Enables/Disables column renaming */
	STD_PHP_INI_BOOLEAN("phalcon.orm.column_renaming",          "1", PHP_INI_ALL,    OnUpdateBool, orm.column_renaming,          zend_phalcon_globals, phalcon_globals)
	/* Enables/Disables automatic NOT NULL validation */
	STD_PHP_INI_BOOLEAN("phalcon.orm.not_null_validations",     "1", PHP_INI_ALL,    OnUpdateBool, orm.not_null_validations,     zend_phalcon_globals, phalcon_globals)
	/* Enables/Disables automatic length validation */
	STD_PHP_INI_BOOLEAN("phalcon.orm.length_validations",       "1", PHP_INI_ALL,    OnUpdateBool, orm.length_validations,       zend_phalcon_globals, phalcon_globals)
	/* Enables/Disables throwing an exception if save fails */
	STD_PHP_INI_BOOLEAN("phalcon.orm.exception_on_failed_save", "0", PHP_INI_ALL,    OnUpdateBool, orm.exception_on_failed_save, zend_phalcon_globals, phalcon_globals)
	/* Enables/Disables literals in PHQL */
	STD_PHP_INI_BOOLEAN("phalcon.orm.enable_literals",          "1", PHP_INI_ALL,    OnUpdateBool, orm.enable_literals,          zend_phalcon_globals, phalcon_globals)
	/* Enables/Disables AST cache */
	STD_PHP_INI_BOOLEAN("phalcon.orm.enable_ast_cache",         "1", PHP_INI_ALL,    OnUpdateBool, orm.enable_ast_cache,         zend_phalcon_globals, phalcon_globals)
	/* Enables/Disables property method */
	STD_PHP_INI_BOOLEAN("phalcon.orm.enable_property_method",   "1", PHP_INI_ALL,    OnUpdateBool, orm.enable_property_method,   zend_phalcon_globals, phalcon_globals)
	/* Enables/Disables auto convert column value follow database data type */
	STD_PHP_INI_BOOLEAN("phalcon.orm.enable_auto_convert",      "1", PHP_INI_ALL,    OnUpdateBool, orm.enable_auto_convert,      zend_phalcon_globals, phalcon_globals)
	STD_PHP_INI_BOOLEAN("phalcon.orm.allow_update_primary",     "0", PHP_INI_ALL,    OnUpdateBool, orm.allow_update_primary,     zend_phalcon_globals, phalcon_globals)
	STD_PHP_INI_BOOLEAN("phalcon.orm.enable_strict",            "0", PHP_INI_ALL,    OnUpdateBool, orm.enable_strict,            zend_phalcon_globals, phalcon_globals)
	/* Enables/Disables auttomatic escape */
	STD_PHP_INI_BOOLEAN("phalcon.db.escape_identifiers",        "1", PHP_INI_ALL,    OnUpdateBool, db.escape_identifiers,        zend_phalcon_globals, phalcon_globals)
	/* Whether to register PSR-3 classes */
	STD_PHP_INI_BOOLEAN("phalcon.register_psr3_classes",        "0", PHP_INI_SYSTEM, OnUpdateBool, register_psr3_classes,        zend_phalcon_globals, phalcon_globals)
PHP_INI_END()

static PHP_MINIT_FUNCTION(phalcon)
{
#if PHP_VERSION_ID < 50500
	char* old_lc_all = setlocale(LC_ALL, NULL);
	if (old_lc_all) {
		size_t len = strlen(old_lc_all);
		char *tmp  = calloc(len+1, 1);
		if (UNEXPECTED(!tmp)) {
			return FAILURE;
		}

		memcpy(tmp, old_lc_all, len);
		old_lc_all = tmp;
	}

	setlocale(LC_ALL, "C");
#endif

	REGISTER_INI_ENTRIES();

	nusphere_dbg_present = (zend_get_extension("DBG") != NULL);

	/* 1. Register exceptions */
	PHALCON_INIT(Phalcon_Exception);
	PHALCON_INIT(Phalcon_Debug_Exception);
	PHALCON_INIT(Phalcon_Acl_Exception);
	PHALCON_INIT(Phalcon_Annotations_Exception);
	PHALCON_INIT(Phalcon_Assets_Exception);
	PHALCON_INIT(Phalcon_Cache_Exception);
	PHALCON_INIT(Phalcon_Crypt_Exception);
	PHALCON_INIT(Phalcon_CLI_Console_Exception);
	PHALCON_INIT(Phalcon_CLI_Dispatcher_Exception);
	PHALCON_INIT(Phalcon_CLI_Router_Exception);
	PHALCON_INIT(Phalcon_Db_Exception);
	PHALCON_INIT(Phalcon_DI_Exception);
	PHALCON_INIT(Phalcon_Escaper_Exception);
	PHALCON_INIT(Phalcon_Events_Exception);
	PHALCON_INIT(Phalcon_Filter_Exception);
	PHALCON_INIT(Phalcon_Flash_Exception);
	PHALCON_INIT(Phalcon_Forms_Exception);
	PHALCON_INIT(Phalcon_Http_Cookie_Exception);
	PHALCON_INIT(Phalcon_Http_Request_Exception);
	PHALCON_INIT(Phalcon_Http_Response_Exception);
	PHALCON_INIT(Phalcon_Http_Client_Exception);
	PHALCON_INIT(Phalcon_Image_Exception);
	PHALCON_INIT(Phalcon_Mvc_Application_Exception);
	PHALCON_INIT(Phalcon_Mvc_Collection_Exception);
	PHALCON_INIT(Phalcon_Mvc_Dispatcher_Exception);
	PHALCON_INIT(Phalcon_Mvc_Model_Exception);
	PHALCON_INIT(Phalcon_Mvc_Model_Transaction_Exception);
	PHALCON_INIT(Phalcon_Mvc_Router_Exception);
	PHALCON_INIT(Phalcon_Mvc_Url_Exception);
	PHALCON_INIT(Phalcon_Mvc_View_Exception);
	PHALCON_INIT(Phalcon_Paginator_Exception);
	PHALCON_INIT(Phalcon_Tag_Exception);
	PHALCON_INIT(Phalcon_Validation_Exception);
	PHALCON_INIT(Phalcon_Security_Exception);
	PHALCON_INIT(Phalcon_Session_Exception);
	PHALCON_INIT(Phalcon_Config_Exception);
	PHALCON_INIT(Phalcon_Loader_Exception);
	PHALCON_INIT(Phalcon_Logger_Exception);
	PHALCON_INIT(Phalcon_Translate_Exception);
	PHALCON_INIT(Phalcon_Mvc_Micro_Exception);
	PHALCON_INIT(Phalcon_Mvc_JsonRpc_Exception);
	PHALCON_INIT(Phalcon_JsonRpc_Client_Exception);
	PHALCON_INIT(Phalcon_Chart_Exception);

	/* 2. Register interfaces */
	PHALCON_INIT(Phalcon_DiInterface);
	PHALCON_INIT(Phalcon_DI_InjectionAwareInterface);
	PHALCON_INIT(Phalcon_Events_EventsAwareInterface);

	PHALCON_INIT(Phalcon_Acl_AdapterInterface);
	PHALCON_INIT(Phalcon_Acl_ResourceInterface);
	PHALCON_INIT(Phalcon_Acl_RoleInterface);
	PHALCON_INIT(Phalcon_Annotations_AdapterInterface);
	PHALCON_INIT(Phalcon_Annotations_ReaderInterface);
	PHALCON_INIT(Phalcon_Assets_FilterInterface);
	PHALCON_INIT(Phalcon_Cache_BackendInterface);
	PHALCON_INIT(Phalcon_Cache_FrontendInterface);
	PHALCON_INIT(Phalcon_CryptInterface);
	PHALCON_INIT(Phalcon_Db_AdapterInterface);
	PHALCON_INIT(Phalcon_Db_ColumnInterface);
	PHALCON_INIT(Phalcon_Db_DialectInterface);
	PHALCON_INIT(Phalcon_Db_IndexInterface);
	PHALCON_INIT(Phalcon_Db_ReferenceInterface);
	PHALCON_INIT(Phalcon_Db_ResultInterface);
	PHALCON_INIT(Phalcon_DispatcherInterface);
	PHALCON_INIT(Phalcon_DI_ServiceInterface);
	PHALCON_INIT(Phalcon_Config_AdapterInterface);
	PHALCON_INIT(Phalcon_EscaperInterface);
	PHALCON_INIT(Phalcon_Events_ManagerInterface);
	PHALCON_INIT(Phalcon_FlashInterface);
	PHALCON_INIT(Phalcon_FilterInterface);
	PHALCON_INIT(Phalcon_Filter_UserFilterInterface);
	PHALCON_INIT(Phalcon_Forms_ElementInterface);
	PHALCON_INIT(Phalcon_Http_RequestInterface);
	PHALCON_INIT(Phalcon_Http_Request_FileInterface);
	PHALCON_INIT(Phalcon_Http_ResponseInterface);
	PHALCON_INIT(Phalcon_Http_Response_CookiesInterface);
	PHALCON_INIT(Phalcon_Http_Response_HeadersInterface);
	PHALCON_INIT(Phalcon_Http_Client_AdapterInterface);
	PHALCON_INIT(Phalcon_Image_AdapterInterface);
	PHALCON_INIT(Phalcon_Logger_AdapterInterface);
	PHALCON_INIT(Phalcon_Logger_FormatterInterface);
	PHALCON_INIT(Phalcon_Mvc_CollectionInterface);
	PHALCON_INIT(Phalcon_Mvc_Collection_ManagerInterface);
	PHALCON_INIT(Phalcon_Mvc_Collection_MessageInterface);
	PHALCON_INIT(Phalcon_Mvc_ControllerInterface);
	PHALCON_INIT(Phalcon_Mvc_DispatcherInterface);
	PHALCON_INIT(Phalcon_Mvc_Micro_CollectionInterface);
	PHALCON_INIT(Phalcon_Mvc_Micro_MiddlewareInterface);
	PHALCON_INIT(Phalcon_Mvc_ModelInterface);
	PHALCON_INIT(Phalcon_Mvc_Model_BehaviorInterface);
	PHALCON_INIT(Phalcon_Mvc_Model_CriteriaInterface);
	PHALCON_INIT(Phalcon_Mvc_Model_ManagerInterface);
	PHALCON_INIT(Phalcon_Mvc_Model_MessageInterface);
	PHALCON_INIT(Phalcon_Mvc_Model_MetaDataInterface);
	PHALCON_INIT(Phalcon_Mvc_Model_QueryInterface);
	PHALCON_INIT(Phalcon_Mvc_Model_Query_BuilderInterface);
	PHALCON_INIT(Phalcon_Mvc_Model_Query_StatusInterface);
	PHALCON_INIT(Phalcon_Mvc_Model_RelationInterface);
	PHALCON_INIT(Phalcon_Mvc_Model_ResultInterface);
	PHALCON_INIT(Phalcon_Mvc_Model_ResultsetInterface);
	PHALCON_INIT(Phalcon_Mvc_Model_TransactionInterface);
	PHALCON_INIT(Phalcon_Mvc_Model_Transaction_ManagerInterface);
	PHALCON_INIT(Phalcon_Mvc_Model_ValidatorInterface);
	PHALCON_INIT(Phalcon_Mvc_ModuleDefinitionInterface);
	PHALCON_INIT(Phalcon_Mvc_RouterInterface);
	PHALCON_INIT(Phalcon_Mvc_Router_RouteInterface);
	PHALCON_INIT(Phalcon_Mvc_UrlInterface);
	PHALCON_INIT(Phalcon_Mvc_ViewInterface);
	PHALCON_INIT(Phalcon_Mvc_View_EngineInterface);
	PHALCON_INIT(Phalcon_Mvc_View_ModelInterface);
	PHALCON_INIT(Phalcon_Paginator_AdapterInterface);
	PHALCON_INIT(Phalcon_Session_AdapterInterface);
	PHALCON_INIT(Phalcon_Session_BagInterface);
	PHALCON_INIT(Phalcon_Translate_AdapterInterface);
	PHALCON_INIT(Phalcon_Validation_ValidatorInterface);
	PHALCON_INIT(Phalcon_Validation_MessageInterface);

	/* 3. Register PSR-3 classes */
	if (PHALCON_GLOBAL(register_psr3_classes)) {
		PHALCON_INIT(Psr_Log_LoggerAwareInterface);
		PHALCON_INIT(Psr_Log_LoggerInterface);
		PHALCON_INIT(Psr_Log_InvalidArgumentException);
		PHALCON_INIT(Psr_Log_LogLevel);
		PHALCON_INIT(Psr_Log_AbstractLogger);
		PHALCON_INIT(Psr_Log_NullLogger);
		PHALCON_INIT(Psr_Log_LoggerAwareTrait);
		PHALCON_INIT(Psr_Log_LoggerTrait);
	}

	/* 4. Register everything else */
	PHALCON_INIT(Phalcon_DI_Injectable);
	PHALCON_INIT(Phalcon_DI);
	PHALCON_INIT(Phalcon_Db_Adapter);
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
	PHALCON_INIT(Phalcon_Mvc_View_Model);
	PHALCON_INIT(Phalcon_Translate_Adapter);
	PHALCON_INIT(Phalcon_Cache_Frontend_Data);
	PHALCON_INIT(Phalcon_DI_FactoryDefault);
	PHALCON_INIT(Phalcon_Config);
	PHALCON_INIT(Phalcon_Config_Adapter);
	PHALCON_INIT(Phalcon_Config_Adapter_Ini);
	PHALCON_INIT(Phalcon_Config_Adapter_Json);
	PHALCON_INIT(Phalcon_Config_Adapter_Php);
	PHALCON_INIT(Phalcon_Config_Adapter_Yaml);
	PHALCON_INIT(Phalcon_Mvc_Router);
	PHALCON_INIT(Phalcon_Acl_Adapter);
	PHALCON_INIT(Phalcon_Session_Adapter);
	PHALCON_INIT(Phalcon_Db);
	PHALCON_INIT(Phalcon_Acl);
	PHALCON_INIT(Phalcon_Tag);
	PHALCON_INIT(Phalcon_Cache_Multiple);
	PHALCON_INIT(Phalcon_Cache_Backend_Apc);
	PHALCON_INIT(Phalcon_Cache_Backend_File);
	PHALCON_INIT(Phalcon_Cache_Backend_Memory);
	PHALCON_INIT(Phalcon_Cache_Backend_Xcache);
	PHALCON_INIT(Phalcon_Cache_Backend_Mongo);
	PHALCON_INIT(Phalcon_Cache_Backend_Memcache);
	PHALCON_INIT(Phalcon_Cache_Backend_Libmemcached);
	PHALCON_INIT(Phalcon_Cache_Backend_Redis);
	PHALCON_INIT(Phalcon_Cache_Frontend_Json);
	PHALCON_INIT(Phalcon_Cache_Frontend_Output);
	PHALCON_INIT(Phalcon_Cache_Frontend_None);
	PHALCON_INIT(Phalcon_Cache_Frontend_Base64);
	PHALCON_INIT(Phalcon_Cache_Frontend_Igbinary);
	PHALCON_INIT(Phalcon_Tag_Select);
	PHALCON_INIT(Phalcon_Paginator_Adapter_Model);
	PHALCON_INIT(Phalcon_Paginator_Adapter_NativeArray);
	PHALCON_INIT(Phalcon_Paginator_Adapter_QueryBuilder);
	PHALCON_INIT(Phalcon_Paginator_Adapter_Sql);
	PHALCON_INIT(Phalcon_Validation);
	PHALCON_INIT(Phalcon_Validation_Message);
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
	PHALCON_INIT(Phalcon_Validation_Validator_Url);
	PHALCON_INIT(Phalcon_Validation_Validator_File);
	PHALCON_INIT(Phalcon_Validation_Validator_Numericality);
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
	PHALCON_INIT(Phalcon_Db_Profiler);
	PHALCON_INIT(Phalcon_Db_Profiler_Item);
	PHALCON_INIT(Phalcon_Db_RawValue);
	PHALCON_INIT(Phalcon_Db_Reference);
	PHALCON_INIT(Phalcon_Db_Result_Pdo);
	PHALCON_INIT(Phalcon_Acl_Role);
	PHALCON_INIT(Phalcon_Acl_Resource);
	PHALCON_INIT(Phalcon_Acl_Adapter_Memory);
	PHALCON_INIT(Phalcon_Kernel);
	PHALCON_INIT(Phalcon_Debug);
	PHALCON_INIT(Phalcon_Debug_Dump);
	PHALCON_INIT(Phalcon_Text);
	PHALCON_INIT(Phalcon_Date);
	PHALCON_INIT(Phalcon_Security);
	PHALCON_INIT(Phalcon_Security_Random);
	PHALCON_INIT(Phalcon_Version);
	PHALCON_INIT(Phalcon_Session_Bag);
	PHALCON_INIT(Phalcon_Session_Adapter_Files);
	PHALCON_INIT(Phalcon_Session_Adapter_Memcache);
	PHALCON_INIT(Phalcon_Session_Adapter_Libmemcached);
	PHALCON_INIT(Phalcon_Filter);
	PHALCON_INIT(Phalcon_DI_FactoryDefault_CLI);
	PHALCON_INIT(Phalcon_DI_Service);
	PHALCON_INIT(Phalcon_DI_Service_Builder);
	PHALCON_INIT(Phalcon_Flash_Direct);
	PHALCON_INIT(Phalcon_Flash_Session);
	PHALCON_INIT(Phalcon_CLI_Task);
	PHALCON_INIT(Phalcon_CLI_Router);
	PHALCON_INIT(Phalcon_CLI_Console);
	PHALCON_INIT(Phalcon_CLI_Dispatcher);
	PHALCON_INIT(Phalcon_Annotations_Reader);
	PHALCON_INIT(Phalcon_Annotations_Annotation);
	PHALCON_INIT(Phalcon_Annotations_Adapter_Apc);
	PHALCON_INIT(Phalcon_Annotations_Collection);
	PHALCON_INIT(Phalcon_Annotations_Reflection);
	PHALCON_INIT(Phalcon_Annotations_Adapter_Xcache);
	PHALCON_INIT(Phalcon_Annotations_Adapter_Files);
	PHALCON_INIT(Phalcon_Annotations_Adapter_Memory);
	PHALCON_INIT(Phalcon_Loader);
	PHALCON_INIT(Phalcon_Logger);
	PHALCON_INIT(Phalcon_Logger_Item);
	PHALCON_INIT(Phalcon_Logger_Multiple);
	PHALCON_INIT(Phalcon_Logger_Formatter_Json);
	PHALCON_INIT(Phalcon_Logger_Formatter_Line);
	PHALCON_INIT(Phalcon_Logger_Formatter_Firephp);
	PHALCON_INIT(Phalcon_Logger_Adapter_Stream);
	PHALCON_INIT(Phalcon_Logger_Adapter_Syslog);
	PHALCON_INIT(Phalcon_Logger_Adapter_File);
	PHALCON_INIT(Phalcon_Logger_Adapter_Firephp);
	PHALCON_INIT(Phalcon_Logger_Formatter_Syslog);
	PHALCON_INIT(Phalcon_Forms_Form);
	PHALCON_INIT(Phalcon_Forms_Manager);
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
	PHALCON_INIT(Phalcon_Forms_Element_Radio);
	PHALCON_INIT(Phalcon_Crypt);
	PHALCON_INIT(Phalcon_Translate_Adapter_NativeArray);
	PHALCON_INIT(Phalcon_Translate_Adapter_Gettext);
	PHALCON_INIT(Phalcon_Escaper);
	PHALCON_INIT(Phalcon_Assets_Manager);
	PHALCON_INIT(Phalcon_Assets_Resource_Js);
	PHALCON_INIT(Phalcon_Assets_Collection);
	PHALCON_INIT(Phalcon_Assets_Filters_None);
	PHALCON_INIT(Phalcon_Assets_Filters_Cssmin);
	PHALCON_INIT(Phalcon_Assets_Filters_Jsmin);
	PHALCON_INIT(Phalcon_Assets_Resource_Css);
	PHALCON_INIT(Phalcon_Http_Request);
	PHALCON_INIT(Phalcon_Http_Cookie);
	PHALCON_INIT(Phalcon_Http_Response);
	PHALCON_INIT(Phalcon_Http_Request_File);
	PHALCON_INIT(Phalcon_Http_Response_Cookies);
	PHALCON_INIT(Phalcon_Http_Response_Headers);
	PHALCON_INIT(Phalcon_Http_Uri);
	PHALCON_INIT(Phalcon_Http_Client);
	PHALCON_INIT(Phalcon_Http_Client_Header);
	PHALCON_INIT(Phalcon_Http_Client_Response);
	PHALCON_INIT(Phalcon_Http_Client_Adapter);
	PHALCON_INIT(Phalcon_Http_Client_Adapter_Curl);
	PHALCON_INIT(Phalcon_Http_Client_Adapter_Stream);
	PHALCON_INIT(Phalcon_Mvc_JsonRpc);
	PHALCON_INIT(Phalcon_JsonRpc_Client);
	PHALCON_INIT(Phalcon_JsonRpc_Client_Response);
	PHALCON_INIT(Phalcon_Queue_Beanstalk);
	PHALCON_INIT(Phalcon_Queue_Beanstalk_Job);
	PHALCON_INIT(Phalcon_Mvc_View);
	PHALCON_INIT(Phalcon_Mvc_Url);
	PHALCON_INIT(Phalcon_Mvc_Model);
	PHALCON_INIT(Phalcon_Mvc_Micro);
	PHALCON_INIT(Phalcon_Mvc_Application);
	PHALCON_INIT(Phalcon_Mvc_Collection);
	PHALCON_INIT(Phalcon_Mvc_Controller);
	PHALCON_INIT(Phalcon_Mvc_Collection_Document);
	PHALCON_INIT(Phalcon_Mvc_Collection_Manager);
	PHALCON_INIT(Phalcon_Mvc_Collection_Message);
	PHALCON_INIT(Phalcon_Mvc_Collection_GridFS);
	PHALCON_INIT(Phalcon_Mvc_Collection_Resultset);
	PHALCON_INIT(Phalcon_Mvc_Dispatcher);
	PHALCON_INIT(Phalcon_Mvc_Model_Row);
	PHALCON_INIT(Phalcon_Mvc_Model_Query);
	PHALCON_INIT(Phalcon_Mvc_Micro_Collection);
	PHALCON_INIT(Phalcon_Mvc_Micro_Exception);
	PHALCON_INIT(Phalcon_Mvc_Micro_LazyLoader);
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
	PHALCON_INIT(Phalcon_Mvc_Model_MetaData_Memcache);
	PHALCON_INIT(Phalcon_Mvc_Model_MetaData_Libmemcached);
	PHALCON_INIT(Phalcon_Mvc_Model_MetaData_Redis);
	PHALCON_INIT(Phalcon_Mvc_Model_MetaData_Mongo);
	PHALCON_INIT(Phalcon_Mvc_Model_MetaData_Cache);
	PHALCON_INIT(Phalcon_Mvc_Model_Validator_Uniqueness);
	PHALCON_INIT(Phalcon_Mvc_Model_Validator_PresenceOf);
	PHALCON_INIT(Phalcon_Mvc_Model_Transaction_Failed);
	PHALCON_INIT(Phalcon_Mvc_Model_Behavior_SoftDelete);
	PHALCON_INIT(Phalcon_Mvc_Model_Behavior_NestedSet);
	PHALCON_INIT(Phalcon_Mvc_Model_Transaction_Manager);
	PHALCON_INIT(Phalcon_Mvc_Model_Behavior_Timestampable);
	PHALCON_INIT(Phalcon_Mvc_Model_MetaData_Strategy_Annotations);
	PHALCON_INIT(Phalcon_Mvc_Model_MetaData_Strategy_Introspection);
	PHALCON_INIT(Phalcon_Mvc_Model_Validator_Inclusionin);
	PHALCON_INIT(Phalcon_Mvc_Model_Validator_Numericality);
	PHALCON_INIT(Phalcon_Mvc_Model_Validator_Exclusionin);
	PHALCON_INIT(Phalcon_Mvc_Model_Validator_StringLength);
	PHALCON_INIT(Phalcon_Mvc_Router_Route);
	PHALCON_INIT(Phalcon_Mvc_Router_Group);
	PHALCON_INIT(Phalcon_Mvc_Router_Annotations);
	PHALCON_INIT(Phalcon_Mvc_User_Module);
	PHALCON_INIT(Phalcon_Mvc_User_Plugin);
	PHALCON_INIT(Phalcon_Mvc_User_Component);
	PHALCON_INIT(Phalcon_Mvc_View_Simple);
	PHALCON_INIT(Phalcon_Mvc_View_Engine_Volt);
	PHALCON_INIT(Phalcon_Mvc_View_Engine_Php);
	PHALCON_INIT(Phalcon_Mvc_View_Engine_Volt_Compiler);
	PHALCON_INIT(Phalcon_Events_Event);
	PHALCON_INIT(Phalcon_Events_Manager);
	PHALCON_INIT(Phalcon_Events_Listener);
	PHALCON_INIT(Phalcon_Image);
	PHALCON_INIT(Phalcon_Image_Adapter);
	PHALCON_INIT(Phalcon_Image_Adapter_GD);
	PHALCON_INIT(Phalcon_Image_Adapter_Imagick);
	PHALCON_INIT(Phalcon_Amf);
	PHALCON_INIT(Phalcon_Amf_Header);
	PHALCON_INIT(Phalcon_Amf_Message);
	PHALCON_INIT(Phalcon_Amf_Packet);
	PHALCON_INIT(Phalcon_Amf_Deserializer);
	PHALCON_INIT(Phalcon_Amf_Serializer);
	PHALCON_INIT(Phalcon_Amf_Exception);
	PHALCON_INIT(Phalcon_Mvc_Amf);
	PHALCON_INIT(Phalcon_Mvc_Amf_Exception);
	PHALCON_INIT(Phalcon_Registry);
	PHALCON_INIT(Phalcon_Mvc_Model_Validator_Json);
	PHALCON_INIT(Phalcon_Arr);
	PHALCON_INIT(Phalcon_Chart_QRcode);
	PHALCON_INIT(Phalcon_Chart_Captcha);
	PHALCON_INIT(Phalcon_Scws);
	PHALCON_INIT(Phalcon_Async);

#if PHP_VERSION_ID < 50500
	setlocale(LC_ALL, old_lc_all);
	free(old_lc_all);
#endif

/*
	orig_execute_internal = zend_execute_internal;
	if (!zend_execute_internal && !getenv("PHALCON_NO_RVO")) {
		zend_execute_internal = phalcon_execute_internal;
	}
*/

#if 0
	{
		zend_module_entry *entry;
		if (zend_hash_find(&module_registry, ZEND_STRS("mbstring"), (void**)&entry) == SUCCESS) {
#ifdef ZTS
			mbstring_globals_id = *(entry->globals_id_ptr);
#else
			mbstring_globals    = ((zend_mbstring_globals*)(entry->globals_ptr));
#endif
		}
	}
#endif

	return SUCCESS;
}

static PHP_MSHUTDOWN_FUNCTION(phalcon){

	phalcon_deinitialize_memory(TSRMLS_C);

	assert(PHALCON_GLOBAL(orm).ast_cache == NULL);

	UNREGISTER_INI_ENTRIES();
/*
	zend_execute_internal = orig_execute_internal;
*/
	return SUCCESS;
}

static PHP_RINIT_FUNCTION(phalcon){

	zend_phalcon_globals *phalcon_globals_ptr = PHALCON_VGLOBAL;

	php_phalcon_init_globals(phalcon_globals_ptr TSRMLS_CC);
	phalcon_init_interned_strings(TSRMLS_C);

	phalcon_initialize_memory(phalcon_globals_ptr TSRMLS_CC);

	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(phalcon){
	phalcon_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}

static PHP_MINFO_FUNCTION(phalcon)
{
	php_info_print_table_start();
	php_info_print_table_row(2, "Phalcon Framework", "enabled");
	php_info_print_table_row(2, "Phalcon Version", PHP_PHALCON_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_end();

	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(phalcon)
{
	php_phalcon_init_globals(phalcon_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(phalcon)
{
	phalcon_deinitialize_memory(TSRMLS_C);
}

static
#if ZEND_MODULE_API_NO > 20060613
const
#endif
zend_module_dep phalcon_deps[] = {
	ZEND_MOD_REQUIRED("spl")
	ZEND_MOD_REQUIRED("date")
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
#if PHALCON_USE_PHP_HASH
	ZEND_MOD_REQUIRED("hash")
#else
	ZEND_MOD_OPTIONAL("hash")
#endif
	ZEND_MOD_OPTIONAL("apc")
	ZEND_MOD_OPTIONAL("apcu")
	ZEND_MOD_OPTIONAL("XCache")
	ZEND_MOD_OPTIONAL("memcache")
	ZEND_MOD_OPTIONAL("memcached")
	ZEND_MOD_OPTIONAL("mongo")
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
	ini_entries,
	phalcon_deps,
	PHP_PHALCON_EXTNAME,
	NULL,
	PHP_MINIT(phalcon),
	PHP_MSHUTDOWN(phalcon),
	PHP_RINIT(phalcon),
	PHP_RSHUTDOWN(phalcon),
	PHP_MINFO(phalcon),
	PHP_PHALCON_VERSION,
	ZEND_MODULE_GLOBALS(phalcon),
	PHP_GINIT(phalcon),
	PHP_GSHUTDOWN(phalcon),
	NULL, /* ZEND_MODULE_POST_ZEND_DEACTIVATE_N(phalcon), */
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_PHALCON
ZEND_GET_MODULE(phalcon)
#endif
