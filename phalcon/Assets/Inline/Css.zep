
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
use Phalcon\Contracts\Assets\AssetsTypes;

/**
 * Represents an inlined CSS
 *
 * @phpstan-import-type assets_attributes from AssetsTypes
 */
class Css extends InlineBase
{
    /**
     * Css constructor.
     *
     * @param assets_attributes $attributes
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
