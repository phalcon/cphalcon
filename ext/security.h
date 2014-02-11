
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

#ifndef PHALCON_SECURITY_H
#define PHALCON_SECURITY_H

#include "php_phalcon.h"

extern zend_class_entry *phalcon_security_ce;

#define PHALCON_SECURITY_CRYPT_DEFAULT          0
#define PHALCON_SECURITY_CRYPT_STD_DES          1
#define PHALCON_SECURITY_CRYPT_EXT_DES          2
#define PHALCON_SECURITY_CRYPT_MD5              3
#define PHALCON_SECURITY_CRYPT_BLOWFISH         4
#define PHALCON_SECURITY_CRYPT_BLOWFISH_X       5
#define PHALCON_SECURITY_CRYPT_BLOWFISH_Y       6
#define PHALCON_SECURITY_CRYPT_SHA256           7
#define PHALCON_SECURITY_CRYPT_SHA512           8

PHALCON_INIT_CLASS(Phalcon_Security);

#endif /* PHALCON_SECURITY_H */
