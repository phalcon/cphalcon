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
 * Class GetSetSourcePathCest
 *
 * @package Phalcon\Tests\Unit\Assets\Asset\Js
 */
class GetSetSourcePathCest
{
    /**
     * Tests Phalcon\Assets\Asset\Js :: getSourcePath()/setSourcePath()
     *
     * @dataProvider provider
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function assetsAssetJsGetSetSourcePath(UnitTester $I, Example $example)
    {
        $I->wantToTest('Assets\Asset - getSourcePath()/setSourcePath()');

        $asset    = new Js($example['path'], $example['local']);
        $expected = '/phalcon/path';

        $asset->setSourcePath($expected);
        $actual = $asset->getSourcePath();

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
