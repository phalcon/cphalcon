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

class GetLocalCest
{
    /**
     * Tests Phalcon\Assets\Asset :: getLocal() - default
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     *
     * @dataProvider defaultProvider
     */
    public function assetsAssetGetLocalJsDefault(UnitTester $I, Example $example)
    {
        $I->wantToTest('Assets\Asset - getLocal() - default');

        $asset = new Asset(
            $example['type'],
            $example['path']
        );

        $I->assertTrue(
            $asset->getLocal()
        );
    }

    protected function defaultProvider(): array
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
     * Tests Phalcon\Assets\Asset :: getLocal()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     *
     * @dataProvider provider
     */
    public function assetsAssetGetLocal(UnitTester $I, Example $example)
    {
        $I->wantToTest('Assets\Asset - getLocal()');

        $asset = new Asset(
            $example['type'],
            $example['path'],
            $example['local']
        );

        $I->assertEquals(
            $example['local'],
            $asset->getLocal()
        );
    }

    protected function provider(): array
    {
        return [
            [
                'type'  => 'css',
                'path'  => 'css/docs.css',
                'local' => true,
            ],
            [
                'type'  => 'css',
                'path'  => 'https://phalcon.ld/css/docs.css',
                'local' => false,
            ],
            [
                'type'  => 'js',
                'path'  => 'js/jquery.js',
                'local' => true,
            ],
            [
                'type'  => 'js',
                'path'  => 'https://phalcon.ld/js/jquery.js',
                'local' => false,
            ],
        ];
    }
}
