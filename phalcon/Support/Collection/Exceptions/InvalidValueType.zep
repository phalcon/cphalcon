
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Support\Collection\Exceptions;

use InvalidArgumentException;

class InvalidValueType extends InvalidArgumentException
{
    public function __construct(string type, var value)
    {
        parent::__construct(
            "Value must be of type '" . type
            . "', '" . get_debug_type(value) . "' given"
        );
    }
}
