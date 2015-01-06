
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
  |          Vladimir Kolesnikov <vladimir@extrememember.com>              |
  +------------------------------------------------------------------------+
*/

#include "psr/log/abstractlogger.h"
#include "psr/log/loggerinterface.h"
#include "psr/log/loglevel.h"

zend_class_entry *psr_log_abstractlogger_ce;

static void psr_log_abstractlogger_log_helper(INTERNAL_FUNCTION_PARAMETERS, const char *lvl)
{
	zval *level, *message, *context = NULL;
	zval *retval = NULL;
	zval **params[3] = { &level, &message, &context };
	zval function_name = zval_used_for_init;
	zend_fcall_info fci;
	zend_fcall_info_cache fcic;
	zend_class_entry *ce;

	if (FAILURE == zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &message, &context)) {
		RETURN_NULL();
	}

	ce = Z_OBJCE_P(getThis());

	if (!context) {
		MAKE_STD_ZVAL(context);
		array_init(context);
		Z_SET_REFCOUNT_P(context, 0);
	}

	MAKE_STD_ZVAL(level);
	ZVAL_STRING(level, lvl, 1);
	Z_SET_REFCOUNT_P(level, 0);

	fci.size           = sizeof(fci);
	fci.function_table = &ce->function_table;
	fci.object_ptr     = getThis();
	fci.function_name  = &function_name;
	fci.retval_ptr_ptr = &retval;
	fci.param_count    = 3;
	fci.params         = params;
	fci.no_separation  = 1;
	fci.symbol_table   = NULL;

	fcic.initialized   = 1;
	fcic.object_ptr    = getThis();
	fcic.calling_scope = ce;
	fcic.called_scope  = ce;

	if (zend_hash_quick_find(fci.function_table, ZEND_STRS("log"), zend_inline_hash_func(ZEND_STRS("log")), (void**)&fcic.function_handler) == FAILURE) {
		fcic.initialized = 0;
		ZVAL_STRING(&function_name, "log", 0);
	}

	zend_call_function(&fci, &fcic TSRMLS_CC);

	if (retval) {
		zval_ptr_dtor(&retval);
	}
}

PHP_FUNCTION(Psr_Log_Emergency)
{
	psr_log_abstractlogger_log_helper(INTERNAL_FUNCTION_PARAM_PASSTHRU, PSR_LOG_LOGLEVEL_EMERGENCY);
}

PHP_FUNCTION(Psr_Log_Alert)
{
	psr_log_abstractlogger_log_helper(INTERNAL_FUNCTION_PARAM_PASSTHRU, PSR_LOG_LOGLEVEL_ALERT);
}

PHP_FUNCTION(Psr_Log_Critical)
{
	psr_log_abstractlogger_log_helper(INTERNAL_FUNCTION_PARAM_PASSTHRU, PSR_LOG_LOGLEVEL_CRITICAL);
}

PHP_FUNCTION(Psr_Log_Error)
{
	psr_log_abstractlogger_log_helper(INTERNAL_FUNCTION_PARAM_PASSTHRU, PSR_LOG_LOGLEVEL_ERROR);
}

PHP_FUNCTION(Psr_Log_Warning)
{
	psr_log_abstractlogger_log_helper(INTERNAL_FUNCTION_PARAM_PASSTHRU, PSR_LOG_LOGLEVEL_WARNING);
}

PHP_FUNCTION(Psr_Log_Notice)
{
	psr_log_abstractlogger_log_helper(INTERNAL_FUNCTION_PARAM_PASSTHRU, PSR_LOG_LOGLEVEL_NOTICE);
}

PHP_FUNCTION(Psr_Log_Info)
{
	psr_log_abstractlogger_log_helper(INTERNAL_FUNCTION_PARAM_PASSTHRU, PSR_LOG_LOGLEVEL_INFO);
}

PHP_FUNCTION(Psr_Log_Debug)
{
	psr_log_abstractlogger_log_helper(INTERNAL_FUNCTION_PARAM_PASSTHRU, PSR_LOG_LOGLEVEL_DEBUG);
}

static const zend_function_entry fe_psr_log_abstractlogger[] = {
	PHP_ME_MAPPING(emergency, Psr_Log_Emergency, arginfo_psr_log_loggerinterface_logspecialized, ZEND_ACC_PUBLIC)
	PHP_ME_MAPPING(alert, Psr_Log_Alert, arginfo_psr_log_loggerinterface_logspecialized, ZEND_ACC_PUBLIC)
	PHP_ME_MAPPING(critical, Psr_Log_Critical, arginfo_psr_log_loggerinterface_logspecialized, ZEND_ACC_PUBLIC)
	PHP_ME_MAPPING(error, Psr_Log_Error, arginfo_psr_log_loggerinterface_logspecialized, ZEND_ACC_PUBLIC)
	PHP_ME_MAPPING(warning, Psr_Log_Warning, arginfo_psr_log_loggerinterface_logspecialized, ZEND_ACC_PUBLIC)
	PHP_ME_MAPPING(notice, Psr_Log_Notice, arginfo_psr_log_loggerinterface_logspecialized, ZEND_ACC_PUBLIC)
	PHP_ME_MAPPING(info, Psr_Log_Info, arginfo_psr_log_loggerinterface_logspecialized, ZEND_ACC_PUBLIC)
	PHP_ME_MAPPING(debug, Psr_Log_Debug, arginfo_psr_log_loggerinterface_logspecialized, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

PHALCON_INIT_CLASS(Psr_Log_AbstractLogger)
{
	zend_class_entry ce;
	INIT_CLASS_ENTRY(ce, "Psr\\Log\\AbstractLogger", fe_psr_log_abstractlogger);

	psr_log_abstractlogger_ce = zend_register_internal_class(&ce TSRMLS_CC);
	if (EXPECTED(psr_log_abstractlogger_ce != NULL)) {
		zend_class_implements(psr_log_abstractlogger_ce TSRMLS_CC, 1, psr_log_loggerinterface_ce);
		return SUCCESS;
	}

	return FAILURE;
}
