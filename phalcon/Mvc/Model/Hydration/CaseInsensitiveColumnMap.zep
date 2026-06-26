
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model\Hydration;

class CaseInsensitiveColumnMap
{
    public static function caseInsensitiveColumnMap(var columnMap, var key) -> string
    {
        var cmKey;

        for cmKey in array_keys(columnMap) {
            if strtolower(cmKey) == strtolower(key) {
                return cmKey;
            }
        }

        return key;
    }
}
