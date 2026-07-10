
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Html\Escaper;

use Phalcon\Html\Escaper\Traits\EscaperTrait;

/**
 * Shared base for the per-context escaper objects.
 *
 * @todo Remove in v7. Kept only for backwards compatibility; compose
 * Phalcon\Html\Escaper\Traits\EscaperTrait directly instead of extending this.
 */
abstract class AbstractEscaper
{
    use EscaperTrait;
}
