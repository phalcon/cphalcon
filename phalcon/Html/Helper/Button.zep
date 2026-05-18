
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

use Phalcon\Html\Escaper\EscaperInterface;
use Phalcon\Html\Exception;

/**
 * Class Button
 *
 * @property bool $forceRaw
 */
class Button extends AbstractHelper
{
    /**
     * @var bool
     */
    protected forceRaw = false;

    /**
     * @param EscaperInterface $escaper
     * @param Doctype          $doctype
     * @param bool             $forceRaw
     */
    public function __construct(
        <EscaperInterface> escaper,
        <Doctype> doctype = null,
        bool forceRaw = false
    ) {
        parent::__construct(escaper, doctype);

        let this->forceRaw = forceRaw;
    }

    /**
     * Produce a `<button>` tag.
     *
     * @param string $text
     * @param array  $attributes
     * @param bool   $raw
     *
     * @return string
     * @throws Exception
     */
    public function __invoke(
        string text,
        array attributes = [],
        bool raw = false
    ) -> string {
        return this->renderFullElement(
            "button",
            text,
            attributes,
            raw || this->forceRaw
        );
    }
}
