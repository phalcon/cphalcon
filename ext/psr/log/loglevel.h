
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

#ifndef PSR_LOG_LOGLEVEL_H
#define PSR_LOG_LOGLEVEL_H

#include "php_phalcon.h"

#define PSR_LOG_LOGLEVEL_EMERGENCY    "emergency"
#define PSR_LOG_LOGLEVEL_ALERT        "alert"
#define PSR_LOG_LOGLEVEL_CRITICAL     "critical"
#define PSR_LOG_LOGLEVEL_ERROR        "error"
#define PSR_LOG_LOGLEVEL_WARNING      "warning"
#define PSR_LOG_LOGLEVEL_NOTICE       "notice"
#define PSR_LOG_LOGLEVEL_INFO         "info"
#define PSR_LOG_LOGLEVEL_DEBUG        "debug"

extern zend_class_entry *psr_log_loglevel_ce;

PHALCON_INIT_CLASS(Psr_Log_LogLevel);

#endif /* PSR_LOG_LOGLEVEL_H */
