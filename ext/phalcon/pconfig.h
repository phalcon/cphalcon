
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

#ifndef PHALCON_PCONFIG_H
#define PHALCON_PCONFIG_H

#include "php_phalcon.h"

extern zend_class_entry *phalcon_config_ce;

PHALCON_INIT_CLASS(Phalcon_Config);

/**
 * @internal
 */
PHALCON_STATIC void phalcon_config_construct_internal(zval *this_ptr, zval *array_config);

#endif /* PHALCON_PCONFIG_H */
