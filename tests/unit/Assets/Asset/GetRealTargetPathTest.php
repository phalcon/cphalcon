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
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Assets\Fake\AssetsTrait;
use Phalcon\Tests\Unit\Assets\Fake\FakeAssetFileExistsPositive;

use function supportDir;

final class GetRealTargetPathTest extends AbstractUnitTestCase
{
    use AssetsTrait;

    /**
     * @dataProvider providerCssJsLocal
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
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
    public function testAssetsAssetGetRealTargetPathWithTargetPath(): void
    {
        $path   = 'css/docs.css';
        $target = 'assets/assets/1198.css';
        $asset  = new Asset('css', $path);
        $asset->setTargetPath($target);

        $actual = $asset->getRealTargetPath(supportDir());
        $this->assertStringContainsString('1198.css', $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testAssetsAssetGetRealTargetPathRealpathFalse(): void
    {
        $file  = 'assets/assets/nonexistent_file.css';
        $asset = new FakeAssetFileExistsPositive('css', $file);

        $actual = $asset->getRealTargetPath(supportDir());
        $this->assertSame('', $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testAssetsAssetGetRealTargetPath404(): void
    {
        if (PHP_OS_FAMILY === 'Windows') {
            $this->markTestSkipped('Need to fix Windows new lines...');
        }

        $file  = 'assets/assets/1198.css';
        $asset = new FakeAssetFileExistsPositive('css', $file);

        $expected = supportDir($file);
        $actual   = $asset->getRealTargetPath(supportDir());
        $this->assertSame($expected, $actual);
    }
}
