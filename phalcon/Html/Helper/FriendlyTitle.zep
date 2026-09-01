
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

use Exception;
use Phalcon\Html\Escaper\EscaperInterface;
use Phalcon\Html\Exceptions\FriendlyTitleConversionFailed;
use Phalcon\Support\Helper\Str\Friendly;

/**
 * Converts text to a URL-friendly slug.
 */
class FriendlyTitle extends AbstractHelper
{
    protected <Friendly> friendly;

    public function __construct(<EscaperInterface> escaper)
    {
        parent::__construct(escaper);

        let this->friendly = new Friendly();
    }

    /**
     * @phpstan-param array<array-key, string>|string|null $replace
     */
    public function __invoke(
        string text,
        string separator = "-",
        bool lowercase = true,
        var replace = null
    ) -> string {
        var ex;

        try {
            return this->friendly->__invoke(text, separator, lowercase, replace);
        } catch Exception, ex {
            throw new FriendlyTitleConversionFailed(ex->getMessage());
        }
    }
}
