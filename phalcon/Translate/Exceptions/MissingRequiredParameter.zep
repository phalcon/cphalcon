
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Translate\Exceptions;

use Phalcon\Translate\Exception;

class MissingRequiredParameter extends Exception
{
    /**
     * @var string
     */
    private parameter;

    public function __construct(string parameter)
    {
        let this->parameter = parameter;

        parent::__construct("Parameter '" . parameter . "' is required");
    }

    public function getParameter() -> string
    {
        return this->parameter;
    }
}
