/**
 * This file is part of the Zephir.
 *
 * (c) Phalcon Team <team@zephir-lang.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code. If you did not receive
 * a copy of the license it is available through the world-wide-web at the
 * following url: https://docs.zephir-lang.com/en/latest/license
 */

#ifndef ZEPHIR_KERNEL_BACKTRACE_H
#define ZEPHIR_KERNEL_BACKTRACE_H

#ifndef ZEPHIR_RELEASE

void zephir_print_backtrace(void);

#else

#ifndef zephir_print_backtrace
#define zephir_print_backtrace()
#endif

#endif
#endif /* ZEPHIR_KERNEL_BACKTRACE_H */
