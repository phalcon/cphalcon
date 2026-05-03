
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

namespace Phalcon\Html\Helper\Input;

use Phalcon\Html\Escaper\EscaperInterface;
use Phalcon\Html\Helper\Doctype;

/**
 * Generic input helper. The HTML5 `type` attribute is supplied via the
 * constructor, which means the `TagFactory` can register a single class
 * for all type-string-only inputs (color, date, email, hidden, number, ...)
 * and differentiate them through the recipe map. The type can also be
 * changed after construction via `setType()`.
 */
class Generic extends AbstractInput
{
    /**
     * @param EscaperInterface $escaper
     * @param Doctype          $doctype
     * @param string           $type
     */
    public function __construct(
        <EscaperInterface> escaper,
        <Doctype> doctype = null,
        string type = "text"
    ) {
        parent::__construct(escaper, doctype);

        let this->type = type;
    }

    /**
     * Sets the type of the input.
     *
     * @param string $type
     *
     * @return AbstractInput
     */
    public function setType(string type) -> <AbstractInput>
    {
        let this->type = type;

        return this;
    }
}
