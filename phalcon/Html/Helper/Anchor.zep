
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

use Phalcon\Contracts\Html\HtmlTypes;
use Phalcon\Html\Escaper\EscaperInterface;

/**
 * Class Anchor
 *
 * @phpstan-import-type html_attributes from HtmlTypes
 */
class Anchor extends AbstractHelper
{
    protected bool forceRaw = false;

    public function __construct(
        <EscaperInterface> escaper,
        <Doctype> doctype = null,
        bool forceRaw = false
    ) {
        parent::__construct(escaper, doctype);

        let this->forceRaw = forceRaw;
    }

    /**
     * Produce a `<a>` tag
     *
     * @phpstan-param html_attributes $attributes
     */
    public function __invoke(
        string href,
        string text,
        array attributes = [],
        bool raw = false
    ) -> string {
        return this->renderFullElement(
            "a",
            text,
            this->injectAttribute("href", href, attributes),
            raw || this->forceRaw
        );
    }
}
