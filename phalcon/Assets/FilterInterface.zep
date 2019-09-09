
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Assets;

/**
 * Interface for custom Phalcon\Assets filters
 */
interface FilterInterface
{
    /**
     * Filters the content returning a string with the filtered content
     */
    public function filter(string! content) -> string;
}
