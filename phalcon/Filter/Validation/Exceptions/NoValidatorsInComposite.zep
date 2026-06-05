
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

class NoValidatorsInComposite extends Exception
{
    public function __construct(string className)
    {
        parent::__construct(className . " does not have any validator added");
    }
}
