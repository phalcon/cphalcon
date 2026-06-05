
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

class UniquenessOnlyForPhalconModel extends Exception
{
    public function __construct()
    {
        parent::__construct(
            "The uniqueness validator works only with Phalcon\\Mvc\\Model"
        );
    }
}
