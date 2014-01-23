#ifndef PSR_LOG_ABSTRACTLOGGER_H
#define PSR_LOG_ABSTRACTLOGGER_H

#include "php_phalcon.h"

extern zend_class_entry *psr_log_abstractlogger_ce;

PHALCON_INIT_CLASS(Psr_Log_AbstractLogger);

PHP_FUNCTION(Psr_Log_Emergency);
PHP_FUNCTION(Psr_Log_Alert);
PHP_FUNCTION(Psr_Log_Critical);
PHP_FUNCTION(Psr_Log_Error);
PHP_FUNCTION(Psr_Log_Warning);
PHP_FUNCTION(Psr_Log_Notice);
PHP_FUNCTION(Psr_Log_Info);
PHP_FUNCTION(Psr_Log_Debug);

#endif /* PSR_LOG_ABSTRACTLOGGER_H */
