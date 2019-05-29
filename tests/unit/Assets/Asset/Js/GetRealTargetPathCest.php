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

namespace Phalcon\Test\Unit\Assets\Asset\Js;

use Codeception\Example;
use Phalcon\Assets\Asset\Js;
use UnitTester;

class GetRealTargetPathCest
{
    /**
     * Tests Phalcon\Assets\Asset\Js :: getRealTargetPath()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     *
     * @dataProvider provider
     */
    public function assetsAssetJsGetAssetKey(UnitTester $I, Example $example)
    {
        $I->wantToTest('Assets\Asset\Js - getRealTargetPath()');

        $asset = new Js(
            $example['path']
        );

        $I->assertEquals(
            $example['path'],
            $asset->getRealTargetPath()
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
