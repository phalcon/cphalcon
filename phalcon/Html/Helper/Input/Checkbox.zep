
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

/**
 * Renders an `<input type="checkbox">`. Behavior (label wrapping, `unchecked`
 * companion, loose-by-default `checked` match) lives in `AbstractChecked`.
 */
class Checkbox extends AbstractChecked
{
    /**
     * @var string
     */
    protected type = "checkbox";
}
