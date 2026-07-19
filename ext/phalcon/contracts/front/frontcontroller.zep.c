
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
 * Implementation of this file has been copied and re-implemented from
 * front-interop, which cannot be used as a Composer dependency because it
 * declares a different root namespace. Once that changes, the copy will be
 * replaced with the actual Composer dependency.
 *
 * @link    https://github.com/front-interop/interface
 * @license https://github.com/front-interop/interface/blob/1.x/LICENSE.md
 */
/**
 * [_FrontController_][] affords an entry point into the outermost presentation
 * layer in any execution context (HTTP, CLI, etc.).
 *
 * @phpstan-import-type front_exit_status_int from FrontTypeAliases
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Front_FrontController)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Front, FrontController, phalcon, contracts_front_frontcontroller, phalcon_contracts_front_frontcontroller_method_entry);

	return SUCCESS;
}

/**
 * Runs the front controller.
 *
 * - Directives:
 *
 *     - Implementations MUST report success by returning an integer `0`.
 *
 *     - Implementations MUST report non-success by returning an integer
 *       between `1` and `254` (inclusive).
 *
 *     - Implementations MUST gracefully handle all [_Throwable_][]s.
 *
 *     - Implementations MUST NOT [`exit()`][], [`die()`][], or otherwise
 *       avoid returning.
 *
 * - Notes:
 *
 *     - **The return value is intended as an exit status code.** Exit
 *       status codes may be received initially by the in-process logic
 *       that invoked `run()` (bootstrap scripts, test harnesses, etc.),
 *       and may ultimately be received by a parent process (shell,
 *       supervisor, init system, CI runner, monitoring tool, or similar)
 *       via [`exit()`][]. Whether or not the exit status is consumed by the
 *       calling code or parent process depends on the execution
 *       environment: php-fpm and mod_php typically have no consumer,
 *       whereas worker loops, supervised long-running processes, runtime
 *       layers, and CI harnesses do.
 *
 *     - **"Success" and "non-success" are context-dependent.** In an HTTP
 *       context, "success" typically means that the request was processed
 *       and a response was emitted regardless of the HTTP status code,
 *       whereas "non-success" may indicate that a [_Throwable_][] had to be
 *       handled by the _FrontController_ itself. In a command line context,
 *       "success" typically means that the command completed without
 *       errors, whereas "non-success" may be one of several error
 *       conditions (cf. the [`sysexits.h`][] conventions where applicable).
 *
 *     - **The exit status code `255` is reserved by PHP itself.** Cf.
 *       [`exit()`][]: "Exit codes should be in the range 0 to 254, the exit
 *       code 255 is reserved by PHP and should not be used."
 *
 *     - **Handle all possible exceptions.** The logic calling the front
 *       controller should not have to deal with any exceptions bubbling up
 *       from it.
 *
 *     - **Graceful handling means returning, not exiting.** A "graceful"
 *       handler catches the [_Throwable_][], turns it into a non-success
 *       exit status, and returns that status from `run()` rather than
 *       calling [`exit()`][].
 *
 *     - **Return the exit status; leave termination to the caller.** The
 *       value of an exit status code comes from letting the caller decide
 *       what to do with it: a worker loop, queue worker, or test harness
 *       needs `run()` to hand control back so it can continue, retry, or
 *       assert on the result. An implementation that calls [`exit()`][]
 *       inside `run()` prevents those uses, terminating the process before
 *       the caller regains control.
 *
 * @return front_exit_status_int
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Front_FrontController, run);
