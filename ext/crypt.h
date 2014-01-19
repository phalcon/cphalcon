
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

#ifndef PHALCON_CRYPT_H
#define PHALCON_CRYPT_H

#include "php_phalcon.h"

/**
 * @brief mcrypt default padding
 */
#define PHALCON_CRYPT_PADDING_DEFAULT        0
/**
 * @brief ANSI X.923 padding
 * @see http://en.wikipedia.org/wiki/Padding_%28cryptography%29#ANSI_X.923
 */
#define PHALCON_CRYPT_PADDING_ANSI_X_923     1
/**
 * @brief PKCS7 padding
 * @see http://en.wikipedia.org/wiki/Padding_%28cryptography%29#PKCS7
 */
#define PHALCON_CRYPT_PADDING_PKCS7          2
/**
 * @brief ISO 10126 padding
 * @see http://en.wikipedia.org/wiki/Padding_%28cryptography%29#ISO_10126
 */
#define PHALCON_CRYPT_PADDING_ISO_10126      3
/**
 * @brief ISO/IEC 7816-4 padding
 * @see http://en.wikipedia.org/wiki/Padding_%28cryptography%29#ISO.2FIEC_7816-4
 */
#define PHALCON_CRYPT_PADDING_ISO_IEC_7816_4 4
/**
 * @brief Zero padding
 * @see http://en.wikipedia.org/wiki/Padding_%28cryptography%29#Zero_padding
 */
#define PHALCON_CRYPT_PADDING_ZERO           5
#define PHALCON_CRYPT_PADDING_SPACE          6

extern zend_class_entry *phalcon_crypt_ce;

PHALCON_INIT_CLASS(Phalcon_Crypt);

#endif /* PHALCON_CRYPT_H */
