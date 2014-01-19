
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

#ifndef PHALCON_TEXT_H
#define PHALCON_TEXT_H

#include "php_phalcon.h"

#define PHALCON_TEXT_RANDOM_ALNUM    0
#define PHALCON_TEXT_RANDOM_ALPHA    1
#define PHALCON_TEXT_RANDOM_HEXDEC   2
#define PHALCON_TEXT_RANDOM_NUMERIC  3
#define PHALCON_TEXT_RANDOM_NOZERO   4

extern zend_class_entry *phalcon_text_ce;

PHALCON_INIT_CLASS(Phalcon_Text);

#endif /* PHALCON_TEXT_H */
