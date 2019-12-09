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

class GetSourcePathCest
{
    /**
     * Tests Phalcon\Assets\Asset\Js :: getSourcePath()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     *
     * @dataProvider provider
     */
    public function assetsAssetJsGetSourcePath(UnitTester $I, Example $example)
    {
        $I->wantToTest('Assets\Asset - getSourcePath()');

        $asset = new Js(
            $example['path'],
            $example['local']
        );

        $expected = '/phalcon/path';

        $asset->setSourcePath($expected);

        $I->assertEquals(
            $expected,
            $asset->getSourcePath()
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
