#include "psr/log/loggertrait.h"
#include "psr/log/abstractlogger.h"
#include "psr/log/loggerinterface.h"

zend_class_entry *psr_log_loggertrait_ce;

#if PHP_VERSION_ID >= 50400

static const zend_function_entry fe_psr_log_loggertrait[] = {
	PHP_ME_MAPPING(emergency, Psr_Log_Emergency, arginfo_psr_log_loggerinterface_logspecialized, ZEND_ACC_PUBLIC)
	PHP_ME_MAPPING(alert, Psr_Log_Alert, arginfo_psr_log_loggerinterface_logspecialized, ZEND_ACC_PUBLIC)
	PHP_ME_MAPPING(critical, Psr_Log_Critical, arginfo_psr_log_loggerinterface_logspecialized, ZEND_ACC_PUBLIC)
	PHP_ME_MAPPING(error, Psr_Log_Error, arginfo_psr_log_loggerinterface_logspecialized, ZEND_ACC_PUBLIC)
	PHP_ME_MAPPING(warning, Psr_Log_Warning, arginfo_psr_log_loggerinterface_logspecialized, ZEND_ACC_PUBLIC)
	PHP_ME_MAPPING(notice, Psr_Log_Notice, arginfo_psr_log_loggerinterface_logspecialized, ZEND_ACC_PUBLIC)
	PHP_ME_MAPPING(info, Psr_Log_Info, arginfo_psr_log_loggerinterface_logspecialized, ZEND_ACC_PUBLIC)
	PHP_ME_MAPPING(debug, Psr_Log_Debug, arginfo_psr_log_loggerinterface_logspecialized, ZEND_ACC_PUBLIC)
	PHP_ABSTRACT_ME(Psr_Log_LoggerTrait, log, arginfo_psr_log_loggerinterface_log)
	PHP_FE_END
};

PHALCON_INIT_CLASS(Psr_Log_LoggerTrait)
{
	zend_class_entry ce;
	INIT_CLASS_ENTRY(ce, "Psr\\Log\\LoggerTrait", fe_psr_log_loggertrait);

	psr_log_loggertrait_ce = zend_register_internal_class(&ce TSRMLS_CC);
	if (EXPECTED(psr_log_loggertrait_ce != NULL)) {
		psr_log_loggertrait_ce->ce_flags |= ZEND_ACC_TRAIT;
		return SUCCESS;
	}

	return FAILURE;
}

#else

PHALCON_INIT_CLASS(Psr_Log_LoggerTrait)
{
	psr_log_loggertrait_ce = NULL;
	return SUCCESS;
}

#endif
