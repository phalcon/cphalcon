
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

class AssociativeArray implements InterpolatorInterface
{
    /**
     * Replaces placeholders by the values passed
     */
    public function replacePlaceholders(
        string! translation,
        array placeholders = []
    ) -> string {
        var interpolate, key, value;
        array replace = [];

        let interpolate = new Interpolate();

        for key, value in placeholders {
            let replace["%" . key . "%"] = value;
        }

        return interpolate(translation, replace);
    }
}
