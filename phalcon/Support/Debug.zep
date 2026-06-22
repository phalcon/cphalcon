
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Support;

use Phalcon\Contracts\Support\Debug\Renderer;
use Phalcon\Support\Debug\Exceptions\RequestHalted;
use Phalcon\Support\Debug\Exceptions\RuntimeWarning;
use Phalcon\Support\Debug\Renderer\HtmlRenderer;
use Phalcon\Support\Debug\ReportBuilder;
use Phalcon\Support\Helper\Arr\Get;
use ReflectionException;
use Throwable;

/**
 * Listens for uncaught exceptions and renders them. Acts as a thin coordinator
 * delegating data collection to ReportBuilder and presentation to a Renderer.
 */
class Debug
{
    /**
     * @var array
     */
    protected blacklist = ["request" : [], "server" : []];

    /**
     * @var array
     */
    protected data = [];

    /**
     * @var bool
     */
    protected hideDocumentRoot = false;

    /**
     * @var bool
     */
    protected static isActive = false;

    /**
     * @var Renderer
     */
    protected renderer;

    /**
     * @var ReportBuilder
     */
    protected reportBuilder;

    /**
     * @var bool
     */
    protected showBackTrace = true;

    /**
     * @var bool
     */
    protected showFileFragment = false;

    /**
     * @var bool
     */
    protected showFiles = true;

    /**
     * @var string
    */
    protected uri = "https://assets.phalcon.io/debug/5.0.x/";

    public function __construct()
    {
        let this->renderer      = new HtmlRenderer();
        let this->reportBuilder = new ReportBuilder();
    }

    /**
     * Clears are variables added previously
     */
    public function clearVars() -> <static>
    {
        let this->data = [];

        return this;
    }

    /**
     * Adds a variable to the debug output
     *
     * @param mixed $variable
     */
    public function debugVar(var varz) -> <static>
    {
        let this->data[] = [
            varz,
            debug_backtrace(),
            time()
        ];

        return this;
    }

    /**
     * Returns the CSS sources
     */
    public function getCssSources() -> string
    {
        return this->renderer->getCssSources(this->uri);
    }

    /**
     * Returns the JavaScript sources
     */
    public function getJsSources() -> string
    {
        return this->renderer->getJsSources(this->uri);
    }

    /**
     * Returns the renderer used to produce the output
     */
    public function getRenderer() -> <Renderer>
    {
        return this->renderer;
    }

    /**
     * Generates a link to the current version documentation
     */
    public function getVersion() -> string
    {
        return this->renderer->getVersion();
    }

    /**
     * Halts the request showing a backtrace
     *
     * @throws RequestHalted
     */
    public function halt() -> void
    {
        throw new RequestHalted();
    }

    /**
     * Listen for uncaught exceptions and non silent notices or warnings
     *
     * @param bool $exceptions
     * @param bool $lowSeverity
     */
    public function listen(bool exceptions = true, bool lowSeverity = false) -> <static>
    {
        if exceptions {
            this->listenExceptions();
        }

        if lowSeverity {
            this->listenLowSeverity();
        }

        return this;
    }

    /**
     * Listen for uncaught exceptions
     */
    public function listenExceptions() -> <static>
    {
        set_exception_handler(
            [this, "onUncaughtException"]
        );

        return this;
    }

    /**
     * Listen for non silent notices or warnings
     */
    public function listenLowSeverity() -> <static>
    {
        set_error_handler(
            [this, "onUncaughtLowSeverity"]
        );

        set_exception_handler(
            [this, "onUncaughtException"]
        );

        return this;
    }

    /**
     * Handles uncaught exceptions
     *
     * @throws ReflectionException
     */
    public function onUncaughtException(<\Throwable> exception) -> bool
    {
        var obLevel;

        let obLevel = ob_get_level();

        /**
         * Cancel the output buffer if active
         */
        if obLevel > 0 {
            ob_end_clean();
        }

        /**
         * Avoid that multiple exceptions being showed
         */
        if true !== self::isActive {
            /**
             * Globally block the debug component to avoid other exceptions to be shown
             */
            let self::isActive = true;

            /**
             * Print the HTML, @TODO, add an option to store the HTML
             */
            echo this->renderHtml(exception);

            /**
             * Unlock the exception renderer
             */
            let self::isActive = false;

            return true;
        }

        echo exception->getMessage();

        return false;
    }

    /**
     * Throws an exception when a notice or warning is raised
     */
    public function onUncaughtLowSeverity(severity, message, file, line) -> void
    {
        if unlikely error_reporting() & severity {
            throw new RuntimeWarning(message, 0, severity, file, line);
        }
    }

    /**
     * Render exception to html format.
     *
     * @param Throwable $exception
     *
     * @return string
     * @throws ReflectionException
     */
    public function renderHtml(<\Throwable> exception) -> string
    {
        return this->renderer->render(
            this->reportBuilder->build(
                exception,
                this->blacklist,
                this->showBackTrace,
                this->showFiles,
                this->showFileFragment,
                this->uri,
                this->data
            )
        );
    }

    /**
     * Sets if files the exception's backtrace must be showed
     *
     * @param array $blacklist
     */
    public function setBlacklist(array blacklist) -> <static>
    {
        var area, result, subArray, value, getter;

        let getter   = new Get(),
            area     = getter->__invoke(blacklist, "request", []),
            subArray = [],
            result   = [];

        for value in area {
            let value           = mb_strtolower(value),
                subArray[value] = 1;
        }

        let result["request"] = subArray,
            area              = getter->__invoke(blacklist, "server", []),
            subArray          = [];

        for value in area {
            let value           = mb_strtolower(value),
                subArray[value] = 1;
        }

        let result["server"] = subArray,
            this->blacklist = result;

        return this;
    }

    /**
     * Sets the renderer used to produce the output
     *
     * @param Renderer $renderer
     */
    public function setRenderer(<Renderer> renderer) -> <static>
    {
        let this->renderer = renderer;

        return this;
    }

    /**
     * Sets if files the exception's backtrace must be showed
     *
     * @param bool $showBackTrace
     */
    public function setShowBackTrace(bool showBackTrace) -> <static>
    {
        let this->showBackTrace = showBackTrace;

        return this;
    }

    /**
     * Sets if files must be completely opened and showed in the output
     * or just the fragment related to the exception
     *
     * @param bool $showFileFragment
     */
    public function setShowFileFragment(bool showFileFragment) -> <static>
    {
        let this->showFileFragment = showFileFragment;

        return this;
    }

    /**
     * Set if files part of the backtrace must be shown in the output
     *
     * @param bool $showFiles
     */
    public function setShowFiles(bool showFiles) -> <static>
    {
        let this->showFiles = showFiles;

        return this;
    }

    /**
     * Change the base URI for static resources
     *
     * @param string $uri
     */
    public function setUri(string! uri) -> <static>
    {
        let this->uri = uri;

        return this;
    }
}
