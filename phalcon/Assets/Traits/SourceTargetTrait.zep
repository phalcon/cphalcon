
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Assets\Traits;

/**
 * Shared source/target path, uri and locality state for asset objects
 * (`Asset`, `Collection`).
 */
trait SourceTargetTrait
{
    protected bool isLocal = true;
    protected string sourcePath = "";
    protected string targetPath = "";
    protected string targetUri = "";

    public function getSourcePath() -> string
    {
        return this->sourcePath;
    }

    public function getTargetPath() -> string
    {
        return this->targetPath;
    }

    public function getTargetUri() -> string
    {
        return this->targetUri;
    }

    /**
     * Checks if the asset is local or not
     */
    public function isLocal() -> bool
    {
        return this->isLocal;
    }

    /**
     * Sets if the asset is local or external
     */
    public function setIsLocal(bool flag) -> <static>
    {
        let this->isLocal = flag;

        return this;
    }

    /**
     * Sets the asset's source path
     */
    public function setSourcePath(string sourcePath) -> <static>
    {
        let this->sourcePath = sourcePath;

        return this;
    }

    /**
     * Sets the asset's target path
     */
    public function setTargetPath(string targetPath) -> <static>
    {
        let this->targetPath = targetPath;

        return this;
    }

    /**
     * Sets a target uri for the generated HTML
     */
    public function setTargetUri(string targetUri) -> <static>
    {
        let this->targetUri = targetUri;

        return this;
    }
}
