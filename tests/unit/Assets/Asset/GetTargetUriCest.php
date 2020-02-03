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
use Phalcon\Test\Fixtures\Traits\DiTrait;
use UnitTester;

use function dataDir;
use function filemtime;

class GetTargetUriCest
{
    use DiTrait;

    /**
     * executed before each test
     */
    public function _before(UnitTester $I)
    {
        $this->newDi();
        $this->setDiService('escaper');
        $this->setDiService('url');
    }

    /**
     * Tests Phalcon\Assets\Asset :: getTargetUri() - local
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     *
     * @dataProvider localProvider
     */
    public function assetsAssetGetTargetUriLocal(UnitTester $I, Example $example)
    {
        $I->wantToTest('Assets\Asset - getTargetUri() - css local');

        $asset = new Asset(
            $example['type'],
            $example['path']
        );

        $expected = '/phalcon/path';

        $asset->setTargetUri($expected);

        $I->assertEquals(
            $expected,
            $asset->getTargetUri()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: getTargetUri() - remote
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     *
     * @dataProvider remoteProvider
     */
    public function assetsAssetGetTargetUriRemote(UnitTester $I, Example $example)
    {
        $I->wantToTest('Assets\Asset - getTargetUri() - css remote');

        $asset = new Asset(
            $example['type'],
            $example['path'],
            false
        );

        $expected = '/phalcon/path';

        $asset->setTargetUri($expected);

        $I->assertEquals(
            $expected,
            $asset->getTargetUri()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: getTargetUri() - js versioning
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsAssetGetTargetUriJsVersioning(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getTargetUri() - js versioning');

        $source = dataDir('assets/assets/assets-version-1.js');

        $asset = new Asset(
            'js',
            $source,
            true,
            false,
            [],
            '1.0.0'
        );

        $expected = 'js/jquery.js?ver=1.0.0';

        $asset->setTargetUri($expected);

        $I->assertEquals(
            $expected,
            $asset->getTargetUri()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: getTargetUri() - js automatic versioning
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsAssetGetTargetUriJsAutoVersioning(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getTargetUri() - js automatic versioning');

        $source = dataDir('assets/assets/assets-version-1.js');

        $asset = new Asset(
            'js',
            $source,
            true,
            false,
            [],
            null,
            true
        );

        $modificationTime = filemtime($source);
        $expected         = $source . '?ver=' . $modificationTime;

        $asset->setTargetUri($expected);

        $I->assertEquals(
            $expected,
            $asset->getTargetUri()
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
