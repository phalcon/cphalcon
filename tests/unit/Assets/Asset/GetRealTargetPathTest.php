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

namespace Phalcon\Tests\Unit\Assets\Asset;

use Phalcon\Assets\Asset;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;
use Phalcon\Tests\Unit\Assets\Fake\AssetsTrait;
use Phalcon\Tests\Unit\Assets\Fake\FakeAssetFileExistsPositive;
use PHPUnit\Framework\Attributes\DataProvider;

final class GetRealTargetPathTest extends AbstractUnitTestCase
{
    use AssetsTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    #[DataProvider('providerCssJsLocal')]
    public function testAssetsAssetGetRealTargetPath(
        string $type,
        string $path,
        bool $local
    ): void {
        $asset = new Asset($type, $path, $local);

        $expected = $path;
        $actual   = $asset->getRealTargetPath();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testAssetsAssetGetRealTargetPath404(): void
    {
        $file  = 'assets/assets/1198.css';
        $asset = new FakeAssetFileExistsPositive('css', $file);

        $expected = Talon::settings()->supportPath($file);
        $actual   = $asset->getRealTargetPath(Talon::settings()->supportPath() . '/');
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testAssetsAssetGetRealTargetPathRealpathFalse(): void
    {
        $file  = 'assets/assets/nonexistent_file.css';
        $asset = new FakeAssetFileExistsPositive('css', $file);

        $actual = $asset->getRealTargetPath(Talon::settings()->supportPath() . '/');
        $this->assertSame('', $actual);
    }

    /**
     * A symbolic link at the target file would send the write outside the
     * assets directory, so it is refused (empty path).
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-26
     */
    public function testAssetsAssetGetRealTargetPathRejectsSymlink(): void
    {
        $dir    = Talon::settings()->outputPath('tests/assets/');
        $target = $dir . 'symlink-target.css';
        $link   = $dir . 'symlink.css';

        file_put_contents($target, 'a {}');
        $this->safeDeleteFile($link);
        symlink($target, $link);

        $asset  = new Asset('css', 'symlink.css');
        $actual = $asset->getRealTargetPath($dir);

        $this->safeDeleteFile($link);
        $this->safeDeleteFile($target);

        $this->assertSame('', $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testAssetsAssetGetRealTargetPathWithTargetPath(): void
    {
        $path   = 'css/docs.css';
        $target = 'assets/assets/1198.css';
        $asset  = new Asset('css', $path);
        $asset->setTargetPath($target);

        $actual = $asset->getRealTargetPath(Talon::settings()->supportPath() . '/');
        $this->assertStringContainsString('1198.css', $actual);
    }
}
