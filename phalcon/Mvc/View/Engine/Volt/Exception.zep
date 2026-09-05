
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\View\Engine\Volt;

use Phalcon\Contracts\Mvc\MvcTypes;
use Phalcon\Mvc\View\Exception as BaseException;

/**
 * Class for exceptions thrown by Phalcon\Mvc\View
 *
 * @phpstan-import-type mvc_volt_node from MvcTypes
 */
class Exception extends BaseException
{
    /**
     * @var array
     *
     * @phpstan-var mvc_volt_node
     */
    protected statement = [];

    /**
     * @param string message
     * @param array statement
     * @param int code
     * @param \Exception|null previous
     *
     * @phpstan-param mvc_volt_node $statement
     */
    public function __construct(string message = "", array statement = [], int code = 0, <\Exception> previous = null)
    {
        let this->statement = statement;

        parent::__construct(message, code, previous);
    }

    /**
     * Gets currently parsed statement (if any).
     *
     * @return array
     *
     * @phpstan-return mvc_volt_node
     */
    public function getStatement() -> array
    {
        var statement;

        let statement = this->statement;

        if typeof statement !== "array" {
            let statement = [];
        }

        return statement;
    }
}
