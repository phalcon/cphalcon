
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model\Exceptions;

use Phalcon\Mvc\Model\Exception;

class PrimaryKeyRequired extends Exception
{
    public function __construct(string className)
    {
        parent::__construct(
            "A primary key must be defined in the model in order to perform the operation in '" . className . "'"
        );
    }
}
