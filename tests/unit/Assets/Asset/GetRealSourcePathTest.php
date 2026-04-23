<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Assets\Asset;

use Phalcon\Assets\Asset;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Assets\Fake\AssetsTrait;

final class GetRealSourcePathTest extends AbstractUnitTestCase
{
    use AssetsTrait;

    /**
     * @return string[][]
     */
    public static function localProvider(): array
    {
        return [
            [
                'css',
                'css/docs.css',
            ],
            [
                'js',
                'js/jquery.js',
            ],
        ];
    }

    /**
     * @return string[][]
     */
    public static function remoteProvider(): array
    {
        return [
            [
                'css',
                'https://phalcon.ld/css/docs.css',
            ],
            [
                'js',
                'https://phalcon.ld/js/jquery.js',
            ],
        ];
    }

    /**
     * @dataProvider localProvider
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testAssetsAssetGetRealSourcePathLocal(
        string $type,
        string $path
    ): void {
        $asset  = new Asset($type, $path);
        $actual = $asset->getRealSourcePath();
        $this->assertEmpty($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testAssetsAssetGetRealSourcePathWithSourcePath(): void
    {
        $asset = new Asset('css', 'css/docs.css');
        $asset->setSourcePath('assets/assets/1198.css');

        $actual = $asset->getRealSourcePath(supportDir());
        $this->assertNotEmpty($actual);
        $this->assertStringContainsString('1198.css', $actual);
    }

    /**
     * @dataProvider remoteProvider
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testAssetsAssetGetRealSourcePathRemote(
        string $type,
        string $path
    ): void {
        if (PHP_OS_FAMILY === 'Windows') {
            $this->markTestSkipped('Need to fix Windows new lines...');
        }

        $asset = new Asset($type, $path, false);

        $expected = $path;
        $actual   = $asset->getRealSourcePath();
        $this->assertSame($expected, $actual);
    }
}
