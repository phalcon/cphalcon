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
        $actual = $asset->getAssetKey();
        $I->assertEquals($expected, $actual);
    }

    /**
     * @param UnitTester     $I
     * @param AssetInterface $asset
     * @param array          $expected
     */
    private function assetGetAttributes(UnitTester $I, AssetInterface $asset, array $expected)
    {
        $actual = $asset->getAttributes();
        $I->assertEquals($expected, $actual);
    }

    /**
     * @param UnitTester     $I
     * @param AssetInterface $asset
     * @param string         $expected
     */
    private function assetGetContent(UnitTester $I, AssetInterface $asset, string $expected)
    {
        $actual = $asset->getContent();
        $I->assertEquals($expected, $actual);
    }

    /**
     * @param UnitTester     $I
     * @param AssetInterface $asset
     * @param bool           $expected
     */
    private function assetGetFilter(UnitTester $I, AssetInterface $asset, bool $expected)
    {
        $actual = $asset->getFilter();
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

    /**
     * @param UnitTester     $I
     * @param AssetInterface $asset
     * @param string         $expected
     */
    private function assetGetPath(UnitTester $I, AssetInterface $asset, string $expected)
    {
        $actual = $asset->getPath();
        $I->assertEquals($expected, $actual);
    }

    /**
     * @param UnitTester     $I
     * @param AssetInterface $asset
     * @param mixed          $expected
     */
    private function assetGetRealSourcePath(UnitTester $I, AssetInterface $asset, $expected)
    {
        $actual = $asset->getRealSourcePath();
        $I->assertEquals($expected, $actual);
    }

    /**
     * @param UnitTester     $I
     * @param AssetInterface $asset
     * @param string         $expected
     */
    private function assetGetRealTargetPath(UnitTester $I, AssetInterface $asset, string $expected)
    {
        $actual = $asset->getRealTargetPath();
        $I->assertEquals($expected, $actual);
    }

    /**
     * @param UnitTester     $I
     * @param AssetInterface $asset
     * @param mixed          $expected
     */
    private function assetGetRealTargetUri(UnitTester $I, AssetInterface $asset, $expected)
    {
        $actual = $asset->getRealTargetUri();
        $I->assertEquals($expected, $actual);
    }

    /**
     * @param UnitTester     $I
     * @param AssetInterface $asset
     * @param string         $expected
     */
    private function assetGetSourcePath(UnitTester $I, AssetInterface $asset, string $expected)
    {
        $actual = $asset->getSourcePath();
        $I->assertEquals($expected, $actual);
    }

    /**
     * @param UnitTester     $I
     * @param AssetInterface $asset
     * @param string         $expected
     */
    private function assetGetTargetPath(UnitTester $I, AssetInterface $asset, string $expected)
    {
        $actual = $asset->getTargetPath();
        $I->assertEquals($expected, $actual);
    }

    /**
     * @param UnitTester     $I
     * @param AssetInterface $asset
     * @param string         $expected
     */
    private function assetGetTargetUri(UnitTester $I, AssetInterface $asset, string $expected)
    {
        $actual = $asset->getTargetUri();
        $I->assertEquals($expected, $actual);
    }

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
}
