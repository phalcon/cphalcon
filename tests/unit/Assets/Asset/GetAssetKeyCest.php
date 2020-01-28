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

class GetAssetKeyCest
{
    /**
     * Tests Phalcon\Assets\Asset :: getAssetKey()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     *
     * @dataProvider provider
     */
    public function assetsAssetGetAssetKey(UnitTester $I, Example $example)
    {
        $I->wantToTest('Assets\Asset - getAssetKey()');

        $asset = new Asset(
            $example['type'],
            $example['path']
        );

        $assetKey = md5(
            $example['type'] . ':' . $example['path']
        );

        $I->assertEquals(
            $assetKey,
            $asset->getAssetKey()
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
