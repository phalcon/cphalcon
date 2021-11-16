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

/**
 * Class GetSetPathCest
 *
 * @package Phalcon\Tests\Unit\Assets\Asset\Js
 */
class GetSetPathCest
{
    /**
     * Tests Phalcon\Assets\Asset\Js :: getPath()/setPath()
     *
     * @dataProvider provider
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function assetsAssetJsGetSetPath(UnitTester $I, Example $example)
    {
        $I->wantToTest('Assets\Asset\Js - getPath()/setPath()');

        $asset = new Js($example['path'], $example['local']);

        $expected = $example['path'];
        $actual   = $asset->getPath();
        $I->assertEquals($expected, $actual);
    }

    /**
     * @return array[]
     */
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
