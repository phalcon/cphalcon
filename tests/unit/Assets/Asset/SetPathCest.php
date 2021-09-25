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

class SetPathCest
{
    /**
     * Tests Phalcon\Assets\Asset :: setPath() - local
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     *
     * @dataProvider localProvider
     */
    public function assetsAssetSetPathLocal(UnitTester $I, Example $example)
    {
        $I->wantToTest('Assets\Asset - setPath() - js local');

        $asset = new Asset(
            $example['type'],
            $example['path']
        );

        $path = '/new/path';

        $asset->setPath($path);

        $I->assertEquals(
            $path,
            $asset->getPath()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: setPath() - remote
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     *
     * @dataProvider remoteProvider
     */
    public function assetsAssetSetPathRemote(UnitTester $I, Example $example)
    {
        $I->wantToTest('Assets\Asset - setPath() - js remote');

        $asset = new Asset(
            $example['type'],
            $example['path'],
            false
        );

        $path = '/new/path';

        $asset->setPath($path);

        $I->assertEquals(
            $path,
            $asset->getPath()
        );
    }

    protected function localProvider(): array
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

    protected function remoteProvider(): array
    {
        return [
            [
                'type' => 'css',
                'path' => 'https://phalcon.ld/css/docs.css',
            ],
            [
                'type' => 'js',
                'path' => 'https://phalcon.ld/js/jquery.js',
            ],
        ];
    }
}
