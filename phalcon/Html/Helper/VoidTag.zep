
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by AuraPHP
 * @link    https://github.com/auraphp/Aura.Html
 * @license https://github.com/auraphp/Aura.Html/blob/2.x/LICENSE
 */

namespace Phalcon\Html\Helper;

use Phalcon\Html\Exception;

/**
 * Generic void-tag escape hatch. Renders a self-closing tag for any name
 * without a dedicated helper. The trailing `/` is emitted only for XHTML
 * doctypes, matching the `Input/AbstractInput::__toString` convention.
 */
class VoidTag extends AbstractHelper
{
    /**
     * @param string $name
     * @param array  $attributes
     *
     * @return string
     * @throws Exception
     */
    public function __invoke(string name, array attributes = []) -> string
    {
        var closeTag;

        let closeTag = "";
        if null !== this->doctype && this->doctype->getType() > Doctype::HTML5 {
            let closeTag = "/";
        }

        return this->renderTag(name, attributes, closeTag);
    }
}
