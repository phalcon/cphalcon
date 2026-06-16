
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Logger;

use Phalcon\Contracts\Logger\Logger as LoggerContract;

/**
 * Interface for Phalcon based logger objects.
 *
 * @psalm-suppress DeprecatedInterface
 * @deprecated Will be removed in a future major release.
 *             Use {@see \Phalcon\Contracts\Logger\Logger} instead.
 */
interface LoggerInterface extends LoggerContract
{
}
