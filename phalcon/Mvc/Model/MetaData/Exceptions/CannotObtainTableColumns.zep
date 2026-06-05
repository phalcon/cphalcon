
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model\MetaData\Exceptions;

use Phalcon\Mvc\Model\Exception;

class CannotObtainTableColumns extends Exception
{
    public function __construct(string completeTable, string className)
    {
        parent::__construct(
            "Cannot obtain table columns for the mapped source '" . completeTable . "' used in model " . className
        );
    }
}
