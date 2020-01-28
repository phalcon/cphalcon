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

namespace Phalcon\Test\Unit\Assets\Asset;

use Codeception\Example;
use Phalcon\Assets\Asset;
use UnitTester;

class SetLocalCest
{
    /**
     * Tests Phalcon\Assets\Asset :: setLocal() - local
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     *
     * @dataProvider localProvider
     */
    public function assetsAssetSetLocalCssLocal(UnitTester $I, Example $example)
    {
        $I->wantToTest('Assets\Asset - setLocal() css local');

        $asset = new Asset(
            $example['type'],
            $example['path']
        );

        $asset->setLocal(true);

        $I->assertTrue(
            $asset->getLocal()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: setLocal() - remote
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     *
     * @dataProvider remoteProvider
     */
    public function assetsAssetSetLocalCssRemote(UnitTester $I, Example $example)
    {
        $I->wantToTest('Assets\Asset - setLocal() - remote');

        $asset = new Asset(
            $example['type'],
            $example['path']
        );

        $asset->setLocal(false);

        $I->assertFalse(
            $asset->getLocal()
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
