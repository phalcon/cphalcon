
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model\Query\Exceptions;

use Phalcon\Mvc\Model\Exception;

class BindParameterNotInPlaceholders extends Exception
{
    public function __construct(string wildcard)
    {
        parent::__construct(
            "Bound parameter '"
            . wildcard
            . "' cannot be replaced because it is not in the placeholders list"
        );

    }
}
