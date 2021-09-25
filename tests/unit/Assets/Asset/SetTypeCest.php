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

class SetTypeCest
{
    /**
     * Tests Phalcon\Assets\Asset :: setType()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     *
     * @dataProvider provider
     */
    public function assetsAssetSetType(UnitTester $I, Example $example)
    {
        $I->wantToTest('Assets\Asset - setType()');

        $asset = new Asset(
            $example['type'],
            $example['path']
        );

        $asset->setType(
            $example['newType']
        );

        $I->assertEquals(
            $example['newType'],
            $asset->getType()
        );
    }

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
