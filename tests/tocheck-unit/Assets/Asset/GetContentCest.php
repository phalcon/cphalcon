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

class GetContentCest
{
    /**
     * Tests Phalcon\Assets\Asset :: getContent()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     *
     * @dataProvider provider
     */
    public function assetsAssetGetContent(UnitTester $I, Example $example)
    {
        $I->wantToTest('Assets\Asset - getContent()');

        $asset = new Asset(
            $example['type'],
            $example['path']
        );

        $I->openFile(
            dataDir(
                $example['path']
            )
        );

        $I->seeFileContentsEqual(
            $asset->getContent(
                dataDir()
            )
        );
    }

    protected function provider(): array
    {
        return [
            [
                'type' => 'css',
                'path' => 'assets/assets/1198.css',
            ],
            [
                'type' => 'js',
                'path' => 'assets/assets/signup.js',
            ],
        ];
    }
}
