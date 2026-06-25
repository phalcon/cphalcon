
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model\Query\Exceptions\Builder;

use Phalcon\Mvc\Model\Exception;

class InvalidCommonTableExpression extends Exception
{
    public function __construct(string message)
    {
        parent::__construct(message);
    }
}
