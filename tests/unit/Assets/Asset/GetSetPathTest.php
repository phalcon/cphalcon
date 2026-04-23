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

final class GetSetPathTest extends AbstractUnitTestCase
{
    use AssetsTrait;

    /**
     * @dataProvider providerCssJs
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testAssetsAssetGetSetPath(
        string $type,
        string $path
    ): void {
        $asset = new Asset($type, $path);

        $expected = $path;
        $asset->setPath($path);
        $actual = $asset->getPath();
        $this->assertSame($expected, $actual);
    }
}
