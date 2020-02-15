
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Assets\Filters;

use Phalcon\Assets\FilterInterface;

/**
 * Minify the CSS - removes comments removes newlines and line feeds keeping
 * removes last semicolon from last property
 */
class Cssmin implements FilterInterface
{
    /**
     * Filters the content using CSSMIN
     * NOTE: This functionality is not currently available
     */
    public function filter(string! content) -> string
    {
        return content;
    }
}
