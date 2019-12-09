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

namespace Phalcon\Test\Unit\Assets\Asset\Js;

use Codeception\Example;
use Phalcon\Assets\Asset\Js;
use UnitTester;

class GetLocalCest
{
    /**
     * Tests Phalcon\Assets\Asset\Js :: getLocal() - default
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsAssetJsGetLocalDefault(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset\Js - getLocal() - default');

        $file = 'js/jquery.js';

        $asset = new Js($file);

        $I->assertTrue(
            $asset->getLocal()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset\Js :: getLocal()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     *
     * @dataProvider provider
     */
    public function assetsAssetJsGetLocal(UnitTester $I, Example $example)
    {
        $I->wantToTest('Assets\Asset\Js - getLocal()');

        $asset = new Js(
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
                'path'  => 'js/jquery.js',
                'local' => true,
            ],
            [
                'path'  => 'https://phalcon.ld/js/jquery.js',
                'local' => false,
            ],
        ];
    }
}
