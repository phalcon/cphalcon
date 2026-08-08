
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Support\Debug\Report;

/**
 * Carries all data collected for an exception, ready to be rendered. Holds no
 * presentation logic.
 */
final class ExceptionReport
{
    /**
     * @var BacktraceItem[]
     */
    private array backtrace = [];
    private string className;
    private string file;
    private array includedFiles = [];
    private int line;
    private int memoryUsage = 0;
    private string message;
    private int peakMemoryUsage = 0;
    private array request = [];
    private array server = [];
    private bool showBackTrace;
    private string uri;
    private array variables = [];

    public function __construct(
        string className,
        string message,
        string file,
        int line,
        bool showBackTrace,
        string uri
    ) {
        let this->className     = className,
            this->message       = message,
            this->file          = file,
            this->line          = line,
            this->showBackTrace = showBackTrace,
            this->uri           = uri;
    }

    /**
     * @return BacktraceItem[]
     */
    public function getBacktrace() -> array
    {
        return this->backtrace;
    }

    public function getClassName() -> string
    {
        return this->className;
    }

    public function getFile() -> string
    {
        return this->file;
    }

    public function getIncludedFiles() -> array
    {
        return this->includedFiles;
    }

    public function getLine() -> int
    {
        return this->line;
    }

    public function getMemoryUsage() -> int
    {
        return this->memoryUsage;
    }

    public function getMessage() -> string
    {
        return this->message;
    }

    public function getPeakMemoryUsage() -> int
    {
        return this->peakMemoryUsage;
    }

    public function getRequest() -> array
    {
        return this->request;
    }

    public function getServer() -> array
    {
        return this->server;
    }

    public function getUri() -> string
    {
        return this->uri;
    }

    public function getVariables() -> array
    {
        return this->variables;
    }

    public function hasVariables() -> bool
    {
        return !empty(this->variables);
    }

    public function isShowBackTrace() -> bool
    {
        return this->showBackTrace;
    }

    /**
     * @param BacktraceItem[] $backtrace
     */
    public function setBacktrace(array backtrace) -> <static>
    {
        let this->backtrace = backtrace;

        return this;
    }

    public function setIncludedFiles(array includedFiles) -> <static>
    {
        let this->includedFiles = includedFiles;

        return this;
    }

    public function setMemoryUsage(int memoryUsage) -> <static>
    {
        let this->memoryUsage = memoryUsage;

        return this;
    }

    public function setPeakMemoryUsage(int peakMemoryUsage) -> <static>
    {
        let this->peakMemoryUsage = peakMemoryUsage;

        return this;
    }

    public function setRequest(array request) -> <static>
    {
        let this->request = request;

        return this;
    }

    public function setServer(array server) -> <static>
    {
        let this->server = server;

        return this;
    }

    public function setVariables(array variables) -> <static>
    {
        let this->variables = variables;

        return this;
    }
}
