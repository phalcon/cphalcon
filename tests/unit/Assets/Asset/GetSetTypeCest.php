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

/**
 * Class GetSetTypeCest
 *
 * @package Phalcon\Tests\Unit\Assets\Asset
 */
class GetSetTypeCest
{
    /**
     * Tests Phalcon\Assets\Asset :: getType()/setType()
     *
     * @dataProvider provider
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function assetsAssetSetType(UnitTester $I, Example $example)
    {
        $I->wantToTest('Assets\Asset - getType()/setType()');

        $asset = new Asset($example['type'], $example['path']);

        $asset->setType($example['newType']);
        $expected = $example['newType'];
        $actual   = $asset->getType();
        $I->assertEquals($expected, $actual);
    }

    /**
     * @return string[][]
     */
    protected function provider(): array
    {
        return [
            [
                'type'    => 'css',
                'path'    => 'css/docs.css',
                'newType' => 'js',
            ],
            [
                'type'    => 'css',
                'path'    => 'js/jquery.js',
                'newType' => 'js',
            ],
        ];
    }
}
