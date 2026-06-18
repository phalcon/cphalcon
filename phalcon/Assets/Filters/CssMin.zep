
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
 * Filter intended to minify CSS content (remove comments, newlines, and line
 * feeds, and drop the last semicolon of the last property).
 *
 * > NOTE: This functionality is not currently available; `filter()` returns
 * > the content unchanged.
 * {: .alert .alert-info }
 *
 * @deprecated Use Phalcon\Assets\Filters\None, or a custom
 *             Phalcon\Assets\FilterInterface wrapping a real CSS minifier.
 */
class Cssmin implements FilterInterface
{
    /**
     * Filters the content using CSSMIN
     */
    public function filter(string! content) -> string
    {
        return content;
    }
}
