
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Logger\Formatter;

use Phalcon\Logger\Item;

/**
 * Phalcon\Logger\FormatterInterface
 *
 * This interface must be implemented by formatters in Phalcon\Logger
 */
interface FormatterInterface
{
    /**
     * Applies a format to an item
     *
     * @param Item $item
     *
     * @return string
     */
    public function format(<Item> item) -> string | array;
}
