
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Contracts\Logger\Formatter;

use Phalcon\Logger\Item;

/**
 * Canonical contract for Phalcon\Logger formatters.
 */
interface Formatter
{
    /**
     * Applies a format to an item
     *
     * @param Item $item
     *
     * @return string
     */
    public function format(<Item> item) -> string;
}
