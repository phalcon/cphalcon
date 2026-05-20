
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Forms\Exceptions;

use Phalcon\Forms\Exception;

class UnknownFormElementType extends Exception
{
    public function __construct(string type)
    {
        parent::__construct("Unknown form element type \"" . type . "\"");
    }
}
