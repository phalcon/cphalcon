
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

class FormNotRegistered extends Exception
{
    public function __construct(string name)
    {
        parent::__construct("There is no form with name='" . name . "'");
    }
}
