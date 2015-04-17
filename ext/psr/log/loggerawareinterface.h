#ifndef PSR_LOG_LOGGERAWAREINTERFACE_H
#define PSR_LOG_LOGGERAWAREINTERFACE_H

#include "php_phalcon.h"

extern zend_class_entry *psr_log_loggerawareinterface_ce;

PHALCON_INIT_CLASS(Psr_Log_LoggerAwareInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_psr_log_loggerawareinterface_setlogger, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, logger, Psr\\Log\\LoggerInterface, 0)
ZEND_END_ARG_INFO()

#endif /* PSR_LOG_LOGGERAWAREINTERFACE_H */
