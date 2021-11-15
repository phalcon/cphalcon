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

use Codeception\Example;
use Phalcon\Assets\Asset;
use UnitTester;

/**
 * Class GetRealSourcePathCest
 *
 * @package Phalcon\Tests\Unit\Assets\Asset
 */
class GetRealSourcePathCest
{
    /**
     * Tests Phalcon\Assets\Asset :: getRealSourcePath() - css/js local
     *
     * @dataProvider localProvider
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function assetsAssetGetRealSourcePathLocal(UnitTester $I, Example $example)
    {
        $I->wantToTest("Assets\Asset - getRealSourcePath() - {$example['type']} local");

        $asset  = new Asset($example['type'], $example['path']);
        $actual = $asset->getRealSourcePath();
        $I->assertEmpty($actual);
    }

    /**
     * Tests Phalcon\Assets\Asset :: getRealSourcePath() - css/js remote
     *
     * @dataProvider remoteProvider
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function assetsAssetGetRealSourcePathRemote(UnitTester $I, Example $example)
    {
        $I->wantToTest("Assets\Asset - getRealSourcePath() - {$example['type']} remote");

        $asset = new Asset($example['type'], $example['path'], false);

        $expected = $example['path'];
        $actual   = $asset->getRealSourcePath();
        $I->assertEquals($expected, $actual);
    }

    /**
     * @return string[][]
     */
    protected function localProvider(): array
    {
        return [
            [
                'type' => 'css',
                'path' => 'css/docs.css',
            ],
            [
                'type' => 'js',
                'path' => 'js/jquery.js',
            ],
        ];
    }

    /**
     * @return string[][]
     */
    protected function remoteProvider(): array
    {
        return [
            [
                'type' => 'css',
                'path' => 'https://phalcon.ld/css/docs.css',
            ],
            [
                'type' => 'js',
                'path' => 'https://phalcon.ld/js/jquery.js',
            ],
        ];
    }
}
