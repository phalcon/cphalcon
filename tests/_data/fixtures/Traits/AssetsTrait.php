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
    private function assetGetAssetKey(UnitTester $I, AssetInterface $asset, string $expected)
    {
        $I->assertEquals(
            $expected,
            $asset->getAssetKey()
        );
    }

    /**
     * @param UnitTester     $I
     * @param AssetInterface $asset
     * @param array          $expected
     */
    private function assetGetAttributes(UnitTester $I, AssetInterface $asset, array $expected)
    {
        $I->assertEquals(
            $expected,
            $asset->getAttributes()
        );
    }

    /**
     * @param UnitTester     $I
     * @param AssetInterface $asset
     * @param string         $expected
     */
    private function assetGetContent(UnitTester $I, AssetInterface $asset, string $expected)
    {
        $I->assertEquals(
            $expected,
            $asset->getContent()
        );
    }

    /**
     * @param UnitTester     $I
     * @param AssetInterface $asset
     * @param bool           $expected
     */
    private function assetGetFilter(UnitTester $I, AssetInterface $asset, bool $expected)
    {
        $I->assertEquals(
            $expected,
            $asset->getFilter()
        );
    }

    /**
     * @param UnitTester     $I
     * @param AssetInterface $asset
     */
    private function assetGetLocal(UnitTester $I, AssetInterface $asset)
    {
        $I->assertTrue(
            $asset->getLocal()
        );
    }

    /**
     * @param UnitTester     $I
     * @param AssetInterface $asset
     * @param string         $expected
     */
    private function assetGetPath(UnitTester $I, AssetInterface $asset, string $expected)
    {
        $I->assertEquals(
            $expected,
            $asset->getPath()
        );
    }

    /**
     * @param UnitTester     $I
     * @param AssetInterface $asset
     * @param mixed          $expected
     */
    private function assetGetRealSourcePath(UnitTester $I, AssetInterface $asset, $expected)
    {
        $I->assertEquals(
            $expected,
            $asset->getRealSourcePath()
        );
    }

    /**
     * @param UnitTester     $I
     * @param AssetInterface $asset
     * @param string         $expected
     */
    private function assetGetRealTargetPath(UnitTester $I, AssetInterface $asset, string $expected)
    {
        $I->assertEquals(
            $expected,
            $asset->getRealTargetPath()
        );
    }

    /**
     * @param UnitTester     $I
     * @param AssetInterface $asset
     * @param mixed          $expected
     */
    private function assetGetRealTargetUri(UnitTester $I, AssetInterface $asset, $expected)
    {
        $I->assertEquals(
            $expected,
            $asset->getRealTargetUri()
        );
    }

    /**
     * @param UnitTester     $I
     * @param AssetInterface $asset
     * @param string         $expected
     */
    private function assetGetSourcePath(UnitTester $I, AssetInterface $asset, string $expected)
    {
        $I->assertEquals(
            $expected,
            $asset->getSourcePath()
        );
    }

    /**
     * @param UnitTester     $I
     * @param AssetInterface $asset
     * @param string         $expected
     */
    private function assetGetTargetPath(UnitTester $I, AssetInterface $asset, string $expected)
    {
        $I->assertEquals(
            $expected,
            $asset->getTargetPath()
        );
    }

    /**
     * @param UnitTester     $I
     * @param AssetInterface $asset
     * @param string         $expected
     */
    private function assetGetTargetUri(UnitTester $I, AssetInterface $asset, string $expected)
    {
        $I->assertEquals(
            $expected,
            $asset->getTargetUri()
        );
    }

    /**
     * @param UnitTester     $I
     * @param AssetInterface $asset
     * @param string         $expected
     */
    private function assetGetType(UnitTester $I, AssetInterface $asset, string $expected)
    {
        $I->assertEquals(
            $expected,
            $asset->getType()
        );
    }
}
