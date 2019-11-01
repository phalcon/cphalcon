
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Translate\Interpolator;

class AssociativeArray implements InterpolatorInterface
{
    /**
     * Replaces placeholders by the values passed
     */
    public function replacePlaceholders(
        string! translation,
        array placeholders = []
    ) -> string {
        var key, value;

        for key, value in placeholders {
            let translation = str_replace(
                "%" . key . "%",
                value,
                translation
            );
        }

        return translation;
    }
}
