
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Logger\Formatter;

use DateTimeImmutable;
use DateTimeZone;
use Phalcon\Logger;
use Phalcon\Logger\Item;

abstract class AbstractFormatter implements FormatterInterface
{
    /**
     * Default date format
     *
     * @var string
     */
    protected dateFormat { get, set };
}
