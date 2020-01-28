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

namespace Phalcon\Test\Unit\Assets\Asset;

use Codeception\Example;
use Phalcon\Assets\Asset;
use UnitTester;

class GetAttributesCest
{
    /**
     * Tests Phalcon\Assets\Asset :: getAttributes()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     *
     * @dataProvider provider
     */
    public function assetsAssetGetAttributes(UnitTester $I, Example $example)
    {
        $I->wantToTest('Assets\Asset - getAttributes()');

        $attributes = [
            'data-key' => 'phalcon',
        ];

        $asset = new Asset(
            $example['type'],
            $example['path'],
            true,
            false,
            $attributes
        );

        $I->assertEquals(
            $attributes,
            $asset->getAttributes()
        );
    }

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
