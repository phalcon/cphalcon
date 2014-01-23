#include "psr/log/loglevel.h"

zend_class_entry *psr_log_loglevel_ce;

PHALCON_INIT_CLASS(Psr_Log_LogLevel)
{
	zend_class_entry ce;
	INIT_CLASS_ENTRY(ce, "Psr\\Log\\LogLevel", NULL);

	psr_log_loglevel_ce = zend_register_internal_class(&ce TSRMLS_CC);
	if (EXPECTED(psr_log_loglevel_ce != NULL)) {
		zend_declare_class_constant_stringl(psr_log_loglevel_ce, ZEND_STRS("EMERGENCY"), ZEND_STRS(PSR_LOG_LOGLEVEL_EMERGENCY) TSRMLS_CC);
		zend_declare_class_constant_stringl(psr_log_loglevel_ce, ZEND_STRS("ALERT"),     ZEND_STRS(PSR_LOG_LOGLEVEL_ALERT)     TSRMLS_CC);
		zend_declare_class_constant_stringl(psr_log_loglevel_ce, ZEND_STRS("CRITICAL"),  ZEND_STRS(PSR_LOG_LOGLEVEL_CRITICAL)  TSRMLS_CC);
		zend_declare_class_constant_stringl(psr_log_loglevel_ce, ZEND_STRS("ERROR"),     ZEND_STRS(PSR_LOG_LOGLEVEL_ERROR)     TSRMLS_CC);
		zend_declare_class_constant_stringl(psr_log_loglevel_ce, ZEND_STRS("WARNING"),   ZEND_STRS(PSR_LOG_LOGLEVEL_WARNING)   TSRMLS_CC);
		zend_declare_class_constant_stringl(psr_log_loglevel_ce, ZEND_STRS("NOTICE"),    ZEND_STRS(PSR_LOG_LOGLEVEL_NOTICE)    TSRMLS_CC);
		zend_declare_class_constant_stringl(psr_log_loglevel_ce, ZEND_STRS("INFO"),      ZEND_STRS(PSR_LOG_LOGLEVEL_INFO)      TSRMLS_CC);
		zend_declare_class_constant_stringl(psr_log_loglevel_ce, ZEND_STRS("DEBUG"),     ZEND_STRS(PSR_LOG_LOGLEVEL_DEBUG)     TSRMLS_CC);

		return SUCCESS;
	}

	return FAILURE;
}
