<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Assets\Exceptions;

use Phalcon\Assets\Exceptions\AssetSourceTargetCollision;
use Phalcon\Assets\Exceptions\InvalidAssetSourcePath;
use Phalcon\Assets\Exceptions\InvalidAssetTargetPath;
use Phalcon\Assets\Exceptions\InvalidTargetPath;
use Phalcon\Assets\Exceptions\TargetPathIsDirectory;
use Phalcon\Tests\AbstractUnitTestCase;

use function uniqid;

final class MessageTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-25
     */
    public function testAssetsExceptionsAssetSourceTargetCollisionMessage(): void
    {
        $path      = uniqid('path-');
        $exception = new AssetSourceTargetCollision($path);

        $expected = "Asset '" . $path . "' has the same source and target paths";
        $this->assertSame($expected, $exception->getMessage());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-25
     */
    public function testAssetsExceptionsInvalidAssetSourcePathMessage(): void
    {
        $path      = uniqid('path-');
        $exception = new InvalidAssetSourcePath($path);

        $expected = "Asset '" . $path . "' does not have a valid source path";
        $this->assertSame($expected, $exception->getMessage());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-25
     */
    public function testAssetsExceptionsInvalidAssetTargetPathMessage(): void
    {
        $path      = uniqid('path-');
        $exception = new InvalidAssetTargetPath($path);

        $expected = "Asset '" . $path . "' does not have a valid target path";
        $this->assertSame($expected, $exception->getMessage());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-25
     */
    public function testAssetsExceptionsInvalidTargetPathMessage(): void
    {
        $path      = uniqid('path-');
        $exception = new InvalidTargetPath($path);

        $expected = "Path '" . $path . "' is not a valid target path";
        $this->assertSame($expected, $exception->getMessage());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-25
     */
    public function testAssetsExceptionsTargetPathIsDirectoryMessage(): void
    {
        $path      = uniqid('path-');
        $exception = new TargetPathIsDirectory($path);

        $expected = "Path '" . $path
            . "' is not a valid target path, it is a directory.";
        $this->assertSame($expected, $exception->getMessage());
    }
}
