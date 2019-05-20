<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Assets\Asset;

use function dataDir;
use function filemtime;
use Phalcon\Assets\Asset;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use UnitTester;

class GetTargetUriCest
{
    use DiTrait;

    /**
     * executed before each test
     */
    public function _before(UnitTester $I)
    {
        $this->newDi();
        $this->setDiEscaper();
        $this->setDiUrl();
    }

    /**
     * Tests Phalcon\Assets\Asset :: getTargetUri() - css local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetTargetUriCssLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getTargetUri() - css local');

        $asset = new Asset('css', 'css/docs.css');

        $expected = '/phalcon/path';

        $asset->setTargetUri($expected);

        $I->assertEquals(
            $expected,
            $asset->getTargetUri()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: getTargetUri() - css remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetTargetUriCssRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getTargetUri() - css remote');

        $asset = new Asset('css', 'https://phalcon.ld/css/docs.css', false);

        $expected = '/phalcon/path';

        $asset->setTargetUri($expected);

        $I->assertEquals(
            $expected,
            $asset->getTargetUri()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: getTargetUri() - js local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetTargetUriJsLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getTargetUri() - js local');

        $asset = new Asset('js', 'js/jquery.js');

        $expected = '/phalcon/path';

        $asset->setTargetUri($expected);

        $I->assertEquals(
            $expected,
            $asset->getTargetUri()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: getTargetUri() - js remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetTargetUriJsRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getTargetUri() - js remote');

        $asset = new Asset('js', 'https://phalcon.ld/js/jquery.js', false);

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
     * @author Phalcon Team <team@phalconphp.com>
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
     * @author Phalcon Team <team@phalconphp.com>
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
}
