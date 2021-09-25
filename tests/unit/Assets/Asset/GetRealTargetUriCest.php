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

use Codeception\Example;
use Phalcon\Assets\Asset;
use UnitTester;

class GetRealTargetUriCest
{
    /**
     * Tests Phalcon\Assets\Asset :: getRealTargetUri() - local
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     *
     * @dataProvider localProvider
     */
    public function assetsAssetGetAssetKeyLocal(UnitTester $I, Example $example)
    {
        $I->wantToTest('Assets\Asset - getRealTargetUri() - local');

        $asset = new Asset(
            $example['type'],
            $example['path']
        );

        $I->assertEquals(
            $example['path'],
            $asset->getRealTargetUri()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: getRealTargetUri() - remote
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     *
     * @dataProvider remoteProvider
     */
    public function assetsAssetGetAssetKeyRemote(UnitTester $I, Example $example)
    {
        $I->wantToTest('Assets\Asset - getRealTargetUri() - remote');

        $asset = new Asset(
            $example['type'],
            $example['path'],
            false
        );

        $I->assertEquals(
            $example['path'],
            $asset->getRealTargetUri()
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
