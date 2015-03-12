
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

#ifndef PHALCON_DB_COLUMN_H
#define PHALCON_DB_COLUMN_H

#include "php_phalcon.h"

extern zend_class_entry *phalcon_db_column_ce;

PHALCON_INIT_CLASS(Phalcon_Db_Column);

#define PHALCON_DB_COLUMN_TYPE_INTEGER			0
#define PHALCON_DB_COLUMN_TYPE_DATE				1
#define PHALCON_DB_COLUMN_TYPE_VARCHAR			2
#define PHALCON_DB_COLUMN_TYPE_DECIMAL			3
#define PHALCON_DB_COLUMN_TYPE_DATETIME			4
#define PHALCON_DB_COLUMN_TYPE_CHAR				5
#define PHALCON_DB_COLUMN_TYPE_TEXT				6
#define PHALCON_DB_COLUMN_TYPE_FLOAT			7
#define PHALCON_DB_COLUMN_TYPE_BOOLEAN			8
#define PHALCON_DB_COLUMN_TYPE_DOUBLE			9
#define PHALCON_DB_COLUMN_TYPE_JSON				10
#define PHALCON_DB_COLUMN_TYPE_ARRAY			11
#define PHALCON_DB_COLUMN_TYPE_OTHER			100

#define PHALCON_DB_COLUMN_BIND_PARAM_NULL		0
#define PHALCON_DB_COLUMN_BIND_PARAM_INT		1
#define PHALCON_DB_COLUMN_BIND_PARAM_STR		2
#define PHALCON_DB_COLUMN_BIND_PARAM_BOOL		5
#define PHALCON_DB_COLUMN_BIND_PARAM_DECIMAL	32
#define PHALCON_DB_COLUMN_BIND_SKIP				1024

#endif /* PHALCON_DB_COLUMN_H */
