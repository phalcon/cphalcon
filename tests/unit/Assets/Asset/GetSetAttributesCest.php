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
 * Class SetAttributesCest
 *
 * @package Phalcon\Tests\Unit\Assets\Asset
 */
class GetSetAttributesCest
{
    /**
     * Tests Phalcon\Assets\Asset :: getAttributes()/setAttributes()
     *
     * @dataProvider provider
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function assetsAssetGetSetAttributes(UnitTester $I, Example $example)
    {
        $I->wantToTest('Assets\Asset - getAttributes()/setAttributes()');

        $asset      = new Asset($example['type'], $example['path']);
        $attributes = [
            'data-key' => 'phalcon',
        ];

        $asset->setAttributes($attributes);
        $actual = $asset->getAttributes();
        $I->assertEquals($attributes, $actual);
    }

    /**
     * @return array[]
     */
    protected function provider(): array
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
}
