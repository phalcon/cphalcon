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

namespace Phalcon\Tests\Unit\Assets\Asset\Css;

use Codeception\Example;
use Phalcon\Assets\Asset\Css;
use UnitTester;

class SetAttributesCest
{
    /**
     * Tests Phalcon\Assets\Asset\Css :: setAttributes()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     *
     * @dataProvider provider
     */
    public function assetsAssetCssSetAttributes(UnitTester $I, Example $example)
    {
        $I->wantToTest('Assets\Asset\Css - setAttributes()');

        $asset = new Css(
            $example['path'],
            $example['local']
        );

        $attributes = [
            'data-key' => 'phalcon',
        ];

        $asset->setAttributes($attributes);

        $I->assertEquals(
            $attributes,
            $asset->getAttributes()
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
