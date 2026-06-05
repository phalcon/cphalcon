
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Support;

use Phalcon\Support\Debug\Exceptions\RequestHalted;
use Phalcon\Support\Debug\Exceptions\RuntimeWarning;
use ReflectionClass;
use ReflectionException;
use ReflectionFunction;
use Throwable;

/**
 * Provides debug capabilities to Phalcon applications
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
        var template;

        let template = "
    <link href='" . this->uri . "%s'
          rel='stylesheet'
          type='text/css' />";

        return sprintf(template, "assets/jquery-ui/themes/ui-lightness/jquery-ui.min.css")
            . sprintf(template, "assets/jquery-ui/themes/ui-lightness/theme.css")
            . sprintf(template, "themes/default/style.css");
    }

    /**
     * Returns the JavaScript sources
     */
    public function getJsSources() -> string
    {
        var template;

        let template = "
    <script type='application/javascript'
            src='" . this->uri . "%s'></script>";

        return sprintf(template, "assets/jquery/dist/jquery.min.js")
            . sprintf(template, "assets/jquery-ui/jquery-ui.min.js")
            . sprintf(template, "assets/jquery.scrollTo/jquery.scrollTo.min.js")
            . sprintf(template, "prettify/prettify.js")
            . sprintf(template, "pretty.js");
    }

    /**
     * Generates a link to the current version documentation
     */
    public function getVersion() -> string
    {
        var version, link;

        let version = new Version();
        let link    = "https://docs.phalcon.io/"
            . version->getPart(Version::VERSION_MAJOR)
            . "."
            . version->getPart(Version::VERSION_MEDIUM)
            . "/";

        return "<div class='version'>
    Phalcon Framework <a href='" . link . "' target='_new'>" . version->get() . "</a>
</div>";
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
        var className, escapedMessage, html;

        let className      = get_class(exception);
        let escapedMessage = this->escapeString(exception->getMessage());

        /**
         * CSS static sources to style the error presentation
         * Use the exception info as document's title
         */
        let html = "<!DOCTYPE html>
<html lang='en'>
<head>
    <title>" . className . ":" . escapedMessage . "</title>" . this->getCssSources() . "
</head>
<body>
";

        /**
         * Get the version link
         */
        let html .= this->getVersion();

        /**
         * Main exception info
         */
        let html .= "
<div align='center'>
    <div class='error-main'>
        <h1>" . className . ": " . escapedMessage . "</h1>
        <span class='error-file'>" . exception->getFile() . " (" . exception->getLine() . ")</span>
    </div>";

        /**
         * Check if the developer wants to show the backtrace or not
         */
        if true === this->showBackTrace {
            /**
             * Create the tabs in the page
             */
            /**
             * Create the tabs in the page
             */
            let html .= "

    <div class='error-info'>
        <div id='tabs'>
            <ul>
                <li><a href='#backtrace'>Backtrace</a></li>
                <li><a href='#request'>Request</a></li>
                <li><a href='#server'>Server</a></li>
                <li><a href='#files'>Included Files</a></li>
                <li><a href='#memory'>Memory</a></li>";

            if (!empty(this->data)) {
                let html .= "
                <li><a href='#variables'>Variables</a></li>";
            }

            let html .= "
            </ul>";

            /**
             * Print backtrace
             */
            let html .= this->printBacktrace(exception);

            /**
             * Print _REQUEST superglobal
             */
            let html .= this->printSuperglobal(_REQUEST, "request");

            /**
             * Print _SERVER superglobal
             */
            let html .= this->printSuperglobal(_SERVER, "server");

            /**
             * Show included files
             */
            let html .= this->printIncludedFiles();

            /**
             * Memory usage
             */
            let html .= this->printMemoryUsage();

            /**
             * Print extra variables passed to the component
             */
            let html .= this->printExtraVariables();

            let html .= "
            </div>";
        }

        /**
         * Get JavaScript sources
         */
        return html . this->getJsSources() . "
        </div>
    </body>
</html>";
    }

    /**
     * Sets if files the exception's backtrace must be showed
     *
     * @param array $blacklist
     */
    public function setBlacklist(array blacklist) -> <static>
    {
        var area, result, subArray, value;

        let area     = this->getArrVal(blacklist, "request", []),
            subArray = [],
            result   = [];

        for value in area {
            let value           = mb_strtolower(value),
                subArray[value] = 1;
        }

        let result["request"] = subArray,
            area              = this->getArrVal(blacklist, "server", []),
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

    /**
     * Escapes a string with htmlentities
     *
     * @param string $value
     */
    protected function escapeString(string value) -> string
    {
        return htmlentities(
            str_replace("\n", "\\n", value),
            ENT_COMPAT,
            "utf-8"
        );
    }

    /**
     * Produces a recursive representation of an array
     *
     * @param array $arguments
     * @param int   $number
     *
     * @return string|null
     */
    protected function getArrayDump(array! argument, n = 0) -> string | null
    {
        var numberArguments, dump, varDump, k, v;

        let numberArguments = count(argument);

        if n >= 3 || numberArguments == 0 {
            return null;
        }

        if numberArguments >= 10 {
            return numberArguments;
        }

        let dump = [];

        for k, v in argument {
            if v == "" {
                let varDump = "(empty string)";
            } elseif is_scalar(v) {
                let varDump = this->escapeString(v);
            } elseif typeof v == "array" {
                let varDump = "Array(" . this->getArrayDump(v, n + 1) . ")";
            } elseif typeof v == "object" {
                let varDump = "Object(" . get_class(v) . ")";
            } elseif v === null {
                let varDump = "null";
            } else {
                let varDump = v;
            }

            let dump[] = "[" . k . "] =&gt; " . varDump;
        }

        return join(", ", dump);
    }

    /**
     * Produces an string representation of a variable
     */
    protected function getVarDump(var variable) -> string
    {
        var className, dumpedObject;

        if variable === true {
            return "true";
        }

        if variable === false {
            return "false";
        }

        /**
         * String variables are escaped to avoid XSS injections
         */
        if typeof variable == "string" {
            return this->escapeString(variable);
        }

        /**
         * Scalar variables are just converted to strings
         */
        if is_scalar(variable) {
            return variable;
        }

        /**
         * If the variable is an object print its class name
         */
        if typeof variable == "object" {
            let className = get_class(variable);

            /**
             * Try to check for a "dump" method, this surely produces a better
             * printable representation
             */
            if method_exists(variable, "dump") {
                let dumpedObject = variable->dump();

                /**
                 * dump() must return an array, generate a recursive
                 * representation using `getArrayDump()`
                 */
                return "Object(" . className  . ": " . this->getArrayDump(dumpedObject) . ")";
            } else {

                /**
                 * If dump() is not available just print the class name
                 */
                return "Object(" . className . ")";
            }
        }

        /**
         * Recursively process the array and enclose it in []
         */
        if typeof variable == "array" {
            return "Array(" . this->getArrayDump(variable) . ")";
        }

        /**
         * Null variables are represented as "null"
         */
        if variable === null {
            return "null";
        }

        /**
         * Other types are represented by its type
         */
        return gettype(variable);
    }

    /**
     * Shows a backtrace item
     *
     * @param int   $number
     * @param array $trace
     *
     * @return string
     * @throws ReflectionException
     */
    final protected function showTraceItem(int number, array! trace) -> string
    {
        var className, prepareInternalClass, preparedFunctionName, html,
            classReflection, prepareUriClass, functionName, functionReflection,
            traceArgs, arguments, argument, file, line, lines,
            numberLines, firstLine, lastLine, i, linePosition,
            currentLine, classNameWithLink, functionNameWithLink, parts;

        /**
         * Every trace in the backtrace have a unique number
         */
        let html = "
                    <tr>
                        <td style='text-align: right; vertical-align: top'
                            class='error-number'>
                            #
                        </td>
                        <td>";

        if fetch className, trace["class"] {
            /**
             * We assume that classes starting by Phalcon are framework's
             * classes
             */
            if str_starts_with(className, "Phalcon") {
                /**
                 * Prepare the class name according to the Phalcon's conventions
                 */
                let parts = explode("\\", className);
                let prepareUriClass = parts[0] . "_" . parts[1];

                /**
                 * Generate a link to the official docs
                 */
                let classNameWithLink = "<a target='_new' "
                    . "href='https://docs.phalcon.io/5.0/en/api/" . prepareUriClass . "'>"
                    . className . "</a>";
            } else {
                let classReflection = new ReflectionClass(className);

                /**
                 * Check if classes are PHP's classes
                 */
                if true === classReflection->isInternal() {
                    let prepareInternalClass = str_replace(
                        "_",
                        "-",
                        mb_strtolower(className)
                    );

                    /**
                     * Generate a link to the official docs
                     */
                    let classNameWithLink = "<a target='_new' "
                        . "href='https://secure.php.net/manual/en/class." . prepareInternalClass . ".php'>"
                        . className . "</a>";
                } else {
                    let classNameWithLink = className;
                }
            }

            let html .= "
                        <span class='error-class'>
                            " . classNameWithLink . "
                        </span>";

            /**
             * Object access operator: static/instance
             */
            let html .= trace["type"];
        }

        /**
         * Normally the backtrace contains only classes
         */
        let functionName = trace["function"];

        if isset trace["class"] {
            let functionNameWithLink = functionName;
        } else {
            /**
             * Check if the function exists
             */
            if true === function_exists(functionName) {
                let functionReflection = new ReflectionFunction(functionName);

                /**
                 * Internal functions links to the PHP documentation
                 */
                if true === functionReflection->isInternal() {
                    /**
                     * Prepare function's name according to the conventions in the docs
                     */
                    let preparedFunctionName = str_replace(
                        "_",
                        "-",
                        functionName
                    );

                    let functionNameWithLink = "<a target='_new' "
                        . "href='https://secure.php.net/manual/en/function." . preparedFunctionName . ".php'>"
                        . functionName . "</a>";
                } else {
                    let functionNameWithLink = functionName;
                }
            } else {
                let functionNameWithLink = functionName;
            }
        }

        let html .= "
                        <span class='error-function'>
                            " . functionNameWithLink . "
                        </span>";

        /**
         * Check for arguments in the function
         */
        if fetch traceArgs, trace["args"] {
            let arguments = [];

            for argument in traceArgs {
                /**
                 * Every argument is generated using getVarDump
                 * Append the HTML generated to the argument's list
                 */
                let arguments[] = "
                        <span class='error-parameter'>
                            " . this->getVarDump(argument) . "
                        </span>";
            }

            /**
             * Join all the arguments
             */
            let html .= "(" . join(", ", arguments) . ")";
        }

        /**
         * When 'file' is present, it usually means the function is provided by
         * the user
         */
        if (isset(trace["file"])) {
            let file = trace["file"];
            let line = (string) trace["line"];

            /**
             * Realpath to the file and its line using a special header
             */
            let html .= "
                        <br/>
                        <div class='error-file'>
                            " . file . " (" . line . ")
                        </div>";

            /**
             * The developer can change if the files must be opened or not
             */
            if true === this->showFiles {
                /**
                 * Open the file to an array using 'file', this respects the
                 * openbase-dir directive
                 */
                let lines       = file(file);
                let numberLines = count(lines);

                /**
                 * File fragments just show a piece of the file where the
                 * exception is located
                 */
                if true === this->showFileFragment {
                    /**
                     * Take seven lines back to the current exception's line, @TODO add an option for this
                     */
                    int beforeLine = line - 7;

                    /**
                     * Check for overflows
                     */
                    if beforeLine < 1 {
                        let firstLine = 1;
                    } else {
                        let firstLine = beforeLine;
                    }

                    /**
                     * Take five lines after the current exception's line, @TODO add an option for this
                     */
                    int afterLine = line + 5;

                    /**
                     * Check for overflows
                     */
                    if afterLine > numberLines {
                        let lastLine = numberLines;
                    } else {
                        let lastLine = afterLine;
                    }

                    let html .= "
                        <pre class='prettyprint highlight:" . firstLine . ":" . line . " linenums:" . firstLine . "'>";
                } else {
                    let firstLine = 1;
                    let lastLine  = numberLines;
                    let html      .= "
                        <pre class='prettyprint highlight:" . firstLine . ":" . line . " linenums error-scroll'>";
                }

                let i = firstLine;

                while i <= lastLine {
                    /**
                     * Current line in the file
                     */
                    let linePosition = i - 1;

                    /**
                     * Current line content in the piece of file
                     */
                    let currentLine = lines[linePosition];

                    /**
                     * File fragments are cleaned, removing tabs and comments
                     */
                    if this->showFileFragment && i == firstLine {
                        if preg_match("#\\*\\/#", rtrim(currentLine)) {
                            let currentLine = str_replace(
                                "* /",
                                " ",
                                currentLine
                            );
                        }
                    }

                    /**
                     * Print a non break space if the current line is a line
                     * break, this allows to show the HTML zebra properly
                     */
                    if currentLine == "\n" || currentLine == "\r\n" {
                        let html .= "&nbsp;\n";
                    } else {
                        /**
                         * Don't escape quotes
                         * We assume the file is utf-8 encoded, @TODO add an option for this
                         */
                        let html .= htmlentities(
                            str_replace("\t", "  ", currentLine),
                            ENT_COMPAT,
                            "UTF-8"
                        );
                    }

                    let i++;
                }

                let html .= "
                            </pre>";
            }
        }

        return html . "
                    </td>
                </tr>";
    }

    /**
     * @return string
     */
    private function closeTable() -> string
    {
        return "
                </tbody>
            </table>
        </div>";
    }

    /**
     * @param Throwable $exception
     *
     * @return string
     * @throws ReflectionException
     */
    private function printBacktrace(<\Throwable> exception) -> string
    {
        var html, trace, number, item;

        let html = "

        <div id='backtrace'>
            <table style='border-collapse: collapse; border-spacing: 0; text-align=center; width:100%'>
                <tbody>";

        let trace = exception->getTrace();

        for number, item in trace {
            /**
             * Every line in the trace is rendered using 'showTraceItem'
             */
            let html .= this->showTraceItem(number, item);
        }

        return html . this->closeTable();
    }

    /**
     * @return string
     */
    private function printExtraVariables() -> string
    {
        var html, key, value;

        let html = "";

        if !empty this->data {
            let html .= this->printTableHeader("variables", "Key", "Value");

            for key, value in this->data {
                let html .= "<tr><td class=\"key\">"
                    . key . "</td><td>"
                    . this->getVarDump(value[0])
                    . "</td></tr>";
            }

            let html .= this->closeTable();
        }

        return html;
    }

    /**
     * @return string
     */
    private function printIncludedFiles() -> string
    {
        var html, key, value;

        let html = this->printTableHeader("files", "#", "Path");

        for key, value in get_included_files() {
            let html .= "
                        <tr>
                            <td>" . key . "</td>
                            <td>" . value . "</td>
                        </tr>";
        }

        return html . this->closeTable();
    }

    /**
     * @return string
     */
    private function printMemoryUsage() -> string
    {
        return this->printTableHeader("memory", "Memory", "")
            . "
                    <tr>
                        <td>
                            Usage
                        </td>
                        <td>"
            . memory_get_usage(true)
            . "</td>
                    </tr>
                </tbody>
                </table>
            </div>";
    }

    /**
     * @param array  $source
     * @param string $div
     *
     * @return string
     */
    private function printSuperglobal(array source, string div) -> string
    {
        var html, filter, key, value;

        let html   = this->printTableHeader(div, "Key", "Value");
        let filter = this->getArrVal(this->blacklist, "server", []);

        for key, value in source {
            if !isset filter[mb_strtolower(key)] {
                let html .= "
                    <tr>
                        <td class='key'>" . key . "</td>
                        <td>" . this->getVarDump(value) . "</td>
                    </tr>";
            }
        }

        return html . "
                    </tbody>
                </table>
            </div>";
    }

    /**
     * @param string $divId
     * @param string $headerOne
     * @param string $headerTwo
     * @param string $colspan
     *
     * @return string
     */
    private function printTableHeader(
        string divId,
        string headerOne,
        string headerTwo,
        string colspan = ""
    ) -> string {
        var span;

        if empty colspan {
            let span = "";
        } else {
            let span = " colspan=\"" . colspan . "\"";
        }

        return "
        <div id='" . divId . "'>
            <table style='border-collapse: collapse; border-spacing: 0; text-align: center'
                   class='superglobal-detail'>
                <thead>
                <tr>
                    <th" . span . ">" . headerOne . "</th>
                </tr>
                <tr>
                    <th>" . headerTwo . "</th>
                </tr>
                </thead>
                <tbody>";
    }

    /**
     * @todo Remove this when we get traits
     */
    private function getArrVal(
        array! collection,
        var index,
        var defaultValue = null
    ) -> var {
        var value;

        if unlikely !fetch value, collection[index] {
            return defaultValue;
        }

        return value;
    }
}
