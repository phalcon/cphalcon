
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Filter\Validation\Exceptions;

use Phalcon\Filter\Validation\Exception;

class InvalidFieldType extends Exception
{
    public function __construct()
    {
        parent::__construct("Field must be passed as array of fields or string");
    }
}
