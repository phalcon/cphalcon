
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Assets\Inline;

use Phalcon\Assets\Inline as InlineBase;

/**
 * Represents an inlined CSS
 */
class Css extends InlineBase
{
    /**
     * Phalcon\Assets\Inline\Css constructor
     */
    public function __construct(
        string content,
        bool filter = true,
        array attributes = []
    ) {
        if (true === empty(attributes)) {
            let attributes = [
                "type": "text/css"
            ];
        }

        parent::__construct("css", content, filter, attributes);
    }
}
