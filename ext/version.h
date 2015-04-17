
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
  |          Nikolaos Dimopoulos <nikos@niden.net>                         |
  +------------------------------------------------------------------------+
*/

#ifndef PHALCON_VERSION_H
#define PHALCON_VERSION_H

#include "php_phalcon.h"

#define PHALCON_VERSION_ALPHA      1
#define PHALCON_VERSION_BETA       2
#define PHALCON_VERSION_RC         3
#define PHALCON_VERSION_STABLE     4

extern zend_class_entry *phalcon_version_ce;

PHALCON_INIT_CLASS(Phalcon_Version);

#endif /* PHALCON_VERSION_H */
