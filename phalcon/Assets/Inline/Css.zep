
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Assets\Inline;

use Phalcon\Assets\Inline as InlineBase;

/**
 * Phalcon\Assets\Inline\Css
 *
 * Represents an inlined CSS
 */
class Css extends InlineBase
{
    /**
     * Phalcon\Assets\Inline\Css
     *
     * @param array attributes
     */
    public function __construct(string content, bool filter = true, attributes = null) -> void
    {
        if attributes == null {
            let attributes = ["type": "text/css"];
        }

        parent::__construct("css", content, filter, attributes);
    }
}
