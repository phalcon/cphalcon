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

class GetRealSourcePathCest
{
    /**
     * Tests Phalcon\Assets\Asset :: getRealSourcePath() - css/js local
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     *
     * @dataProvider localProvider
     */
    public function assetsAssetGetRealSourcePathLocal(UnitTester $I, Example $example)
    {
        $I->wantToTest("Assets\Asset - getRealSourcePath() - {$example['type']} local");

        $asset = new Asset(
            $example['type'],
            $example['path']
        );

        $I->assertEquals('', $asset->getRealSourcePath());
    }

    /**
     * Tests Phalcon\Assets\Asset :: getRealSourcePath() - css/js remote
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     *
     * @dataProvider remoteProvider
     */
    public function assetsAssetGetRealSourcePathRemote(UnitTester $I, Example $example)
    {
        $I->wantToTest("Assets\Asset - getRealSourcePath() - {$example['type']} remote");

        $asset = new Asset(
            $example['type'],
            $example['path'],
            false
        );

        $I->assertEquals(
            $example['path'],
            $asset->getRealSourcePath()
        );
    }

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
