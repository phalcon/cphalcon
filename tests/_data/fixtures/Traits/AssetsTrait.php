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

trait AssetsTrait
{
    private function assetGetAssetKey(UnitTester $I, AssetInterface $asset, string $expected)
    {
        $I->assertEquals(
            $expected,
            $asset->getAssetKey()
        );
    }

    private function assetGetAttributes(UnitTester $I, AssetInterface $asset, array $expected)
    {
        $I->assertEquals(
            $expected,
            $asset->getAttributes()
        );
    }

    private function assetGetContent(UnitTester $I, AssetInterface $asset, string $expected)
    {
        $I->assertEquals(
            $expected,
            $asset->getContent()
        );
    }

    private function assetGetFilter(UnitTester $I, AssetInterface $asset, bool $expected)
    {
        $I->assertEquals(
            $expected,
            $asset->getFilter()
        );
    }

    private function assetGetLocal(UnitTester $I, AssetInterface $asset)
    {
        $I->assertTrue(
            $asset->getLocal()
        );
    }

    private function assetGetPath(UnitTester $I, AssetInterface $asset, string $expected)
    {
        $I->assertEquals(
            $expected,
            $asset->getPath()
        );
    }

    private function assetGetRealSourcePath(UnitTester $I, AssetInterface $asset, $expected)
    {
        $I->assertEquals(
            $expected,
            $asset->getRealSourcePath()
        );
    }

    private function assetGetRealTargetPath(UnitTester $I, AssetInterface $asset, string $expected)
    {
        $I->assertEquals(
            $expected,
            $asset->getRealTargetPath()
        );
    }

    private function assetGetRealTargetUri(UnitTester $I, AssetInterface $asset, $expected)
    {
        $I->assertEquals(
            $expected,
            $asset->getRealTargetUri()
        );
    }

    private function assetGetSourcePath(UnitTester $I, AssetInterface $asset, string $expected)
    {
        $I->assertEquals(
            $expected,
            $asset->getSourcePath()
        );
    }

    private function assetGetTargetPath(UnitTester $I, AssetInterface $asset, string $expected)
    {
        $I->assertEquals(
            $expected,
            $asset->getTargetPath()
        );
    }

    private function assetGetTargetUri(UnitTester $I, AssetInterface $asset, string $expected)
    {
        $I->assertEquals(
            $expected,
            $asset->getTargetUri()
        );
    }

    private function assetGetType(UnitTester $I, AssetInterface $asset, string $expected)
    {
        $I->assertEquals(
            $expected,
            $asset->getType()
        );
    }
}
