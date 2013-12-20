/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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

#ifndef PHALCON_KERNEL_SESSION_H
#define PHALCON_KERNEL_SESSION_H

void phalcon_session_start(TSRMLS_D);
void phalcon_session_destroy(TSRMLS_D);
void phalcon_get_session_id(zval *return_value, zval **return_value_ptr TSRMLS_DC);
void phalcon_set_session_id(zval *sid TSRMLS_DC);
void phalcon_session_write_close(TSRMLS_D);

#endif /* PHALCON_KERNEL_SESSION_H */
