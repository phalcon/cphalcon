#include "psr/log/loggerinterface.h"

zend_class_entry *psr_log_loggerinterface_ce;

static const zend_function_entry fe_psr_log_loggerinterface[] = {
	PHP_ABSTRACT_ME(Psr_Log_LoggerInterface, emergency, arginfo_psr_log_loggerinterface_logspecialized)
	PHP_ABSTRACT_ME(Psr_Log_LoggerInterface, alert, arginfo_psr_log_loggerinterface_logspecialized)
	PHP_ABSTRACT_ME(Psr_Log_LoggerInterface, critical, arginfo_psr_log_loggerinterface_logspecialized)
	PHP_ABSTRACT_ME(Psr_Log_LoggerInterface, error, arginfo_psr_log_loggerinterface_logspecialized)
	PHP_ABSTRACT_ME(Psr_Log_LoggerInterface, warning, arginfo_psr_log_loggerinterface_logspecialized)
	PHP_ABSTRACT_ME(Psr_Log_LoggerInterface, notice, arginfo_psr_log_loggerinterface_logspecialized)
	PHP_ABSTRACT_ME(Psr_Log_LoggerInterface, info, arginfo_psr_log_loggerinterface_logspecialized)
	PHP_ABSTRACT_ME(Psr_Log_LoggerInterface, debug, arginfo_psr_log_loggerinterface_logspecialized)
	PHP_ABSTRACT_ME(Psr_Log_LoggerInterface, log, arginfo_psr_log_loggerinterface_log)
	PHP_FE_END
};

PHALCON_INIT_CLASS(Psr_Log_LoggerInterface)
{
	zend_class_entry ce;
	INIT_CLASS_ENTRY(ce, "Psr\\Log\\LoggerInterface", fe_psr_log_loggerinterface);

	psr_log_loggerinterface_ce = zend_register_internal_interface(&ce TSRMLS_CC);
	return (EXPECTED(psr_log_loggerinterface_ce != NULL)) ? SUCCESS : FAILURE;
}
