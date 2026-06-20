
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Support\Debug;

use Phalcon\Support\Debug\Report\BacktraceItem;
use Phalcon\Support\Debug\Report\ExceptionReport;
use Phalcon\Support\Helper\Arr\Get;
use ReflectionClass;
use ReflectionException;
use ReflectionFunction;
use Throwable;

/**
 * Collects the runtime data for an exception (backtrace, superglobals, included
 * files, memory, variables) into an ExceptionReport. Holds no presentation
 * logic.
 */
class ReportBuilder
{
    /**
     * @param Throwable $exception
     * @param array     $blacklist
     * @param bool      $showBackTrace
     * @param bool      $showFiles
     * @param bool      $showFileFragment
     * @param string    $uri
     * @param array     $data
     *
     * @return ExceptionReport
     * @throws ReflectionException
     */
    public function build(
        <\Throwable> exception,
        array blacklist,
        bool showBackTrace,
        bool showFiles,
        bool showFileFragment,
        string uri,
        array data
    ) -> <ExceptionReport> {
        var report, items, trace, item, getter;

        let report = new ExceptionReport(
            get_class(exception),
            exception->getMessage(),
            exception->getFile(),
            exception->getLine(),
            showBackTrace,
            uri
        );

        if showBackTrace !== true {
            return report;
        }

        let items = [];
        let trace = exception->getTrace();

        for item in trace {
            let items[] = this->buildItem(item, showFiles, showFileFragment);
        }

        let getter = new Get();

        report->setBacktrace(items);
        report->setRequest(
            this->filter(_REQUEST, getter->__invoke(blacklist, "request", []))
        );
        report->setServer(
            this->filter(_SERVER, getter->__invoke(blacklist, "server", []))
        );
        report->setIncludedFiles(get_included_files());
        report->setMemoryUsage(memory_get_usage(true));
        report->setVariables(data);

        return report;
    }

    /**
     * @param string $file
     * @param int    $line
     * @param bool   $showFileFragment
     *
     * @return array
     */
    private function buildFragment(string file, int line, bool showFileFragment) -> array
    {
        var lines, numberLines, firstLine, lastLine, mode, beforeLine, afterLine;

        let lines = file(file);
        if false === lines {
            let lines = [];
        }

        let numberLines = count(lines);

        if showFileFragment === true {
            let beforeLine = line - 7,
                firstLine  = (beforeLine < 1) ? 1 : beforeLine,
                afterLine  = line + 5,
                lastLine   = (afterLine > numberLines) ? numberLines : afterLine,
                mode       = "fragment";
        } else {
            let firstLine = 1,
                lastLine  = numberLines,
                mode      = "full";
        }

        return [
            "mode":      mode,
            "firstLine": firstLine,
            "line":      line,
            "lastLine":  lastLine,
            "lines":     lines
        ];
    }

    /**
     * @param array $trace
     * @param bool  $showFiles
     * @param bool  $showFileFragment
     *
     * @return BacktraceItem
     * @throws ReflectionException
     */
    private function buildItem(array trace, bool showFiles, bool showFileFragment) -> <BacktraceItem>
    {
        var className, classLink, type, functionLink, functionName,
            hasArgs, args, file, line, fragment;

        let className    = null,
            classLink    = null,
            type         = null,
            functionLink = null,
            file         = null,
            line         = null,
            fragment     = null,
            args         = [];

        if isset trace["class"] {
            let className = trace["class"];

            if isset trace["type"] {
                let type = trace["type"];
            }

            let classLink = this->resolveClassLink(className);
        }

        let functionName = trace["function"];

        if !isset trace["class"] {
            let functionLink = this->resolveFunctionLink(functionName);
        }

        let hasArgs = isset trace["args"];
        if hasArgs {
            let args = trace["args"];
        }

        if isset trace["file"] {
            let file = trace["file"],
                line = trace["line"];

            if showFiles === true {
                let fragment = this->buildFragment(file, line, showFileFragment);
            }
        }

        return new BacktraceItem(
            functionName,
            type,
            className,
            classLink,
            functionLink,
            hasArgs,
            args,
            file,
            line,
            fragment
        );
    }

    /**
     * @param array $source
     * @param array $blacklist
     *
     * @return array
     */
    private function filter(array source, array blacklist) -> array
    {
        var result, key, value;

        let result = [];

        for key, value in source {
            if !isset blacklist[mb_strtolower(key)] {
                let result[key] = value;
            }
        }

        return result;
    }

    /**
     * @param string $className
     *
     * @return string|null
     * @throws ReflectionException
     */
    private function resolveClassLink(string className) -> string | null
    {
        var parts, reflection, prepared;

        if str_starts_with(className, "Phalcon") {
            let parts = explode("\\", className);

            return "https://docs.phalcon.io/5.0/en/api/" . parts[0] . "_" . parts[1];
        }

        let reflection = new ReflectionClass(className);

        if reflection->isInternal() === true {
            let prepared = str_replace("_", "-", mb_strtolower(className));

            return "https://secure.php.net/manual/en/class." . prepared . ".php";
        }

        return null;
    }

    /**
     * @param string $functionName
     *
     * @return string|null
     * @throws ReflectionException
     */
    private function resolveFunctionLink(string functionName) -> string | null
    {
        var reflection, prepared;

        if function_exists(functionName) !== true {
            return null;
        }

        let reflection = new ReflectionFunction(functionName);

        if reflection->isInternal() !== true {
            return null;
        }

        let prepared = str_replace("_", "-", functionName);

        return "https://secure.php.net/manual/en/function." . prepared . ".php";
    }
}
