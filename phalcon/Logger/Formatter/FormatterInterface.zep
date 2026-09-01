
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Logger\Formatter;

use Phalcon\Contracts\Logger\Formatter\Formatter as FormatterContract;

/**
 * Phalcon\Logger\FormatterInterface
 *
 * This interface must be implemented by formatters in Phalcon\Logger
 *
 * @psalm-suppress DeprecatedInterface
 * @deprecated Will be removed in a future major release.
 *             Use {@see \Phalcon\Contracts\Logger\Formatter\Formatter} instead.
 */
interface FormatterInterface extends FormatterContract
{
}
