
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by lcobucci/clock
 *
 * @link    https://github.com/lcobucci/clock
 * @license https://github.com/lcobucci/clock/blob/3.7.x/LICENSE
 */
ZEPHIR_INIT_CLASS(Phalcon_Time_Clock_ClockInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Time\\Clock, ClockInterface, phalcon, time_clock_clockinterface, phalcon_time_clock_clockinterface_method_entry);

	return SUCCESS;
}

ZEPHIR_DOC_METHOD(Phalcon_Time_Clock_ClockInterface, now);
