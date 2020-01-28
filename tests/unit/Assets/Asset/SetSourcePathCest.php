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

class SetSourcePathCest
{
    /**
     * Tests Phalcon\Assets\Asset :: setSourcePath() - local
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     *
     * @dataProvider localProvider
     */
    public function assetsAssetSetSourcePathLocal(UnitTester $I, Example $example)
    {
        $I->wantToTest('Assets\Asset - setSourcePath() - local');

        $asset = new Asset(
            $example['type'],
            $example['path']
        );

        $sourcePath = '/new/path';

        $asset->setSourcePath($sourcePath);

        $I->assertEquals(
            $sourcePath,
            $asset->getSourcePath()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: setSourcePath() - remote
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     *
     * @dataProvider remoteProvider
     */
    public function assetsAssetSetSourcePathRemote(UnitTester $I, Example $example)
    {
        $I->wantToTest('Assets\Asset - setSourcePath() - remote');

        $asset = new Asset(
            $example['type'],
            $example['path'],
            false
        );

        $sourcePath = '/new/path';

        $asset->setSourcePath($sourcePath);

        $I->assertEquals(
            $sourcePath,
            $asset->getSourcePath()
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
