
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
    /**
     * @var array
     */
    protected args = [];

    /**
     * @var string|null
     */
    protected classLink = null;

    /**
     * @var string|null
     */
    protected className = null;

    /**
     * @var string|null
     */
    protected file = null;

    /**
     * @var array|null
     */
    protected fragment = null;

    /**
     * @var string|null
     */
    protected functionLink = null;

    /**
     * @var string
     */
    protected functionName;

    /**
     * @var bool
     */
    protected hasArgs = false;

    /**
     * @var int|null
     */
    protected line = null;

    /**
     * @var string|null
     */
    protected type = null;

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

    /**
     * @return array
     */
    public function getArgs() -> array
    {
        return this->args;
    }

    /**
     * @return string|null
     */
    public function getClassLink() -> string | null
    {
        return this->classLink;
    }

    /**
     * @return string|null
     */
    public function getClassName() -> string | null
    {
        return this->className;
    }

    /**
     * @return string|null
     */
    public function getFile() -> string | null
    {
        return this->file;
    }

    /**
     * @return array|null
     */
    public function getFragment() -> array | null
    {
        return this->fragment;
    }

    /**
     * @return string|null
     */
    public function getFunctionLink() -> string | null
    {
        return this->functionLink;
    }

    /**
     * @return string
     */
    public function getFunctionName() -> string
    {
        return this->functionName;
    }

    /**
     * @return int|null
     */
    public function getLine() -> int | null
    {
        return this->line;
    }

    /**
     * @return string|null
     */
    public function getType() -> string | null
    {
        return this->type;
    }

    /**
     * @return bool
     */
    public function hasArgs() -> bool
    {
        return this->hasArgs;
    }
}
