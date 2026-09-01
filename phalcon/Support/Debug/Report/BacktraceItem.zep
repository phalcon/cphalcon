
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Support\Debug\Report;

use Phalcon\Contracts\Support\SupportTypes;

/**
 * Represents a single resolved frame of an exception backtrace.
 *
 * @phpstan-import-type support_debug_args from SupportTypes
 * @phpstan-import-type support_debug_fragment from SupportTypes
 */
final class BacktraceItem
{
    /**
     * @phpstan-param support_debug_args          $args
     */
    private array args = [];
    private ?string classLink = null;
    private ?string className = null;
    private ?string file = null;
    /**
     * @phpstan-param support_debug_fragment|null $fragment
     */
    private ?array fragment = null;
    private ?string functionLink = null;
    private string functionName;
    private bool hasArgs = false;
    private ?int line = null;
    private ?string type = null;

    public function __construct(
        string functionName,
        string type = null,
        string className = null,
        string classLink = null,
        string functionLink = null,
        bool hasArgs = false,
        array args = [],
        string file = null,
        int line = null,
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
     * @phpstan-return support_debug_args
     */
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

    /**
     * @phpstan-return support_debug_fragment|null
     */
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
