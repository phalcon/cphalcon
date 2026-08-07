
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
 * Represents a single resolved frame of an exception backtrace.
 */
final class BacktraceItem
{
    protected array args = [];
    protected ?string classLink = null;
    protected ?string className = null;
    protected ?string file = null;
    protected ?array fragment = null;
    protected ?string functionLink = null;
    protected string functionName;
    protected bool hasArgs = false;
    protected ?int line = null;
    protected ?string type = null;

    /**
     * @param string      $functionName
     * @param string|null $type
     * @param string|null $className
     * @param string|null $classLink
     * @param string|null $functionLink
     * @param bool        $hasArgs
     * @param array       $args
     * @param string|null $file
     * @param int|null    $line
     * @param array|null  $fragment
     */
    public function __construct(
        string functionName,
        var type = null,
        var className = null,
        var classLink = null,
        var functionLink = null,
        bool hasArgs = false,
        array args = [],
        var file = null,
        var line = null,
        var fragment = null
    ) {
        let this->functionName = functionName,
            this->type         = type,
            this->className    = className,
            this->classLink    = classLink,
            this->functionLink = functionLink,
            this->hasArgs      = hasArgs,
            this->args         = args,
            this->file         = file,
            this->line         = line,
            this->fragment     = fragment;
    }

    public function getArgs() -> array
    {
        return this->args;
    }

    public function getClassLink() -> string | null
    {
        return this->classLink;
    }

    public function getClassName() -> string | null
    {
        return this->className;
    }

    public function getFile() -> string | null
    {
        return this->file;
    }

    public function getFragment() -> array | null
    {
        return this->fragment;
    }

    public function getFunctionLink() -> string | null
    {
        return this->functionLink;
    }

    public function getFunctionName() -> string
    {
        return this->functionName;
    }

    public function getLine() -> int | null
    {
        return this->line;
    }

    public function getType() -> string | null
    {
        return this->type;
    }

    public function hasArgs() -> bool
    {
        return this->hasArgs;
    }
}
