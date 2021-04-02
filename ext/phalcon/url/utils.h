
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#ifndef PHALCON_URL_UTILS_H
#define PHALCON_URL_UTILS_H

#include <Zend/zend.h>

/* Extract named parameters */
void phalcon_get_uri(zval *return_value, zval *path);
void phalcon_extract_named_params(zval *return_value, zval *str, zval *matches);
void phalcon_replace_paths(zval *return_value, zval *pattern, zval *paths, zval *uri);

#endif /* PHALCON_URL_UTILS_H */
