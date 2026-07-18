
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

namespace Phalcon\Contracts\Front;

/**
 * [_FrontTypeAliases_][] provides custom PHPStan types to aid static analysis.
 *
 * - ```
 *   front_exit_status_int int<0,254>
 *   ```
 *     - An `int` exit status code: `0` for success, `1` to `254` for
 *       non-success. The value `255` is reserved by PHP itself.
 *
 * @phpstan-type front_exit_status_int int<0,254>
 */
interface FrontTypeAliases
{
}
