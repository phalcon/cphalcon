
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

#ifndef PHALCON_MVC_URL_UTILS_H
#define PHALCON_MVC_URL_UTILS_H

#include <Zend/zend.h>

/* Extract named parameters */
void phalcon_get_uri(zval *return_value, zval *path);
void phalcon_extract_named_params(zval *return_value, zval *str, zval *matches);
void phalcon_replace_paths(zval *return_value, zval *pattern, zval *paths, zval *uri TSRMLS_DC);

#endif /* PHALCON_MVC_URL_UTILS_H */
