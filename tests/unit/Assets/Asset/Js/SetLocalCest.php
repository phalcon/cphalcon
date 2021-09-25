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

namespace Phalcon\Tests\Unit\Assets\Asset\Js;

use Codeception\Example;
use Phalcon\Assets\Asset\Js;
use UnitTester;

class SetLocalCest
{
    /**
     * Tests Phalcon\Assets\Asset\Js :: setLocal()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     *
     * @dataProvider provider
     */
    public function assetsAssetJsSetLocal(UnitTester $I, Example $example)
    {
        $I->wantToTest('Assets\Asset\Js - setLocal()');

        $asset = new Js(
            $example['path'],
            $example['local']
        );

        $asset->setLocal(
            $example['newLocal']
        );

        $I->assertEquals(
            $example['newLocal'],
            $asset->getLocal()
        );
    }

    protected function provider(): array
    {
        return [
            [
                'path'     => 'js/jquery.js',
                'local'    => true,
                'newLocal' => false,
            ],
            [
                'path'     => 'https://phalcon.ld/js/jquery.js',
                'local'    => false,
                'newLocal' => true,
            ],
        ];
    }
}
