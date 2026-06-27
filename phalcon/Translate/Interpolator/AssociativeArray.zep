
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Translate\Interpolator;

use Phalcon\Support\Helper\Str\Interpolate;

/**
 * Class AssociativeArray
 */
class AssociativeArray implements InterpolatorInterface
{
    /**
     * @var Interpolate | null
     */
    protected interpolate = null;

    /**
     * Replaces placeholders by the values passed
     *
     * @phpstan-param array<string, string> $placeholders
     *
     * @return string
     */
    public function replacePlaceholders(
         string translation,
        array placeholders = []
    ) -> string {
        if null === this->interpolate {
            let this->interpolate = new Interpolate();
        }

        return this->interpolate->__invoke(translation, placeholders);
    }
}
