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

namespace Phalcon\Test\Unit\Assets\Asset\Css;

use Codeception\Example;
use Phalcon\Assets\Asset\Css;
use UnitTester;

class GetLocalCest
{
    /**
     * Tests Phalcon\Assets\Asset\Css :: getLocal() - default
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsAssetCssGetLocalDefault(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset\Css - getLocal() - default');

        $file = 'css/docs.css';

        $asset = new Css($file);

        $I->assertTrue(
            $asset->getLocal()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset\Css :: getLocal()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     *
     * @dataProvider provider
     */
    public function assetsAssetCssGetLocal(UnitTester $I, Example $example)
    {
        $I->wantToTest('Assets\Asset\Css - getLocal()');

        $asset = new Css(
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
                'path'  => 'css/docs.css',
                'local' => true,
            ],
            [
                'path'  => 'https://phalcon.ld/css/docs.css',
                'local' => false,
            ],
        ];
    }
}
