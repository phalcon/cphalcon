
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
