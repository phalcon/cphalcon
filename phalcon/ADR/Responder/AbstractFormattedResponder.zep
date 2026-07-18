
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Based on the Action Domain Responder pattern
 * @link    https://pmjones.io/adr/
 */

namespace Phalcon\ADR\Responder;

/**
 * Base for content-type responders: composes Status, Redirect and Format
 * responders into a chain. Subclasses bind the formatter(s).
 */
abstract class AbstractFormattedResponder extends ChainResponder
{
    public function __construct(array formatters = [])
    {
        parent::__construct(
            [
                new StatusResponder(),
                new RedirectResponder(),
                new FormatResponder(formatters)
            ]
        );
    }
}
