
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Html\Exceptions;

use Phalcon\Html\Exception;

class AttributeNotRenderable extends Exception
{
    public function __construct(string key, string type)
    {
        parent::__construct(
            "Value at index: \"" . key . "\" type: \"" . type . "\" cannot be rendered"
        );
    }
}
