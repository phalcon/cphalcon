
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Based on the Action Domain Responder pattern
 * @link    https://pmjones.io/adr/
 */

namespace Phalcon\ADR\Events;

/**
 * The ADR event vocabulary, fired through the native events manager.
 */
class Event
{
    /**
     * @var string
     */
    const ADR_AFTER_EXECUTE_ACTION  = "adr:afterExecuteAction";
    /**
     * @var string
     */
    const ADR_BEFORE_EXECUTE_ACTION = "adr:beforeExecuteAction";
    /**
     * @var string
     */
    const APPLICATION_AFTER_HANDLE  = "application:afterHandle";
    /**
     * @var string
     */
    const APPLICATION_BEFORE_HANDLE = "application:beforeHandle";
    /**
     * @var string
     */
    const PIPELINE_AFTER_DISPATCH   = "pipeline:afterDispatch";
    /**
     * @var string
     */
    const PIPELINE_BEFORE_DISPATCH  = "pipeline:beforeDispatch";

    /**
     * Instantiation not allowed.
     */
    final private function __construct()
    {
    }
}
