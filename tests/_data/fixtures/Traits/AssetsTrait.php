<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Traits;

use Phalcon\Assets\AssetInterface;
use UnitTester;

/**
 * Trait AssetsTrait
 *
 * @package Phalcon\Test\Fixtures\Traits
 */
trait AssetsTrait
{
    /**
     * @param UnitTester     $I
     * @param AssetInterface $asset
     * @param string         $expected
     */
    private function assetGetType(UnitTester $I, AssetInterface $asset, string $expected)
    {
        $actual = $asset->getType();
        $I->assertEquals($expected, $actual);
    }

    /**
     * @param UnitTester     $I
     * @param AssetInterface $asset
     * @param string         $expected
     */
    private function assetGetAssetKey(UnitTester $I, AssetInterface $asset, string $expected)
    {
        $actual = $asset->getAssetKey();
        $I->assertEquals($expected, $actual);
    }

    /**
     * @param UnitTester     $I
     * @param AssetInterface $asset
     * @param string         $expected
     */
    private function assetGetPath(UnitTester $I, AssetInterface $asset, string $expected)
    {
        $actual   = $asset->getPath();
        $I->assertEquals($expected, $actual);
    }

    /**
     * @param UnitTester     $I
     * @param AssetInterface $asset
     */
    private function assetGetLocal(UnitTester $I, AssetInterface $asset)
    {
        $actual = $asset->getLocal();
        $I->assertTrue($actual);
    }
}
