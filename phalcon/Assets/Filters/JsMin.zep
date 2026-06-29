
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
 * Filter intended to minify JavaScript content (remove comments and the
 * characters that are insignificant to JavaScript - tabs, carriage returns,
 * and most spaces and linefeeds).
 *
 * > NOTE: This functionality is not currently available; `filter()` returns
 * > the content unchanged.
 * {: .alert .alert-info }
 *
 * @deprecated Use Phalcon\Assets\Filters\None, or a custom
 *             Phalcon\Assets\FilterInterface wrapping a real JS minifier.
 */
class Jsmin implements FilterInterface
{
    /**
     * Filters the content using JSMIN
     */
    public function filter( string content) -> string
    {
        return content;
    }
}
