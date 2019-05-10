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

use Phalcon\Assets\Asset;
use Phalcon\Test\Fixtures\Traits\AssetsTrait;
use UnitTester;

class GetTargetUriCest
{
    use AssetsTrait;

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
        $this->assetGetTargetUri($I, $asset, $expected);
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
        $this->assetGetTargetUri($I, $asset, $expected);
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
        $this->assetGetTargetUri($I, $asset, $expected);
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
        $this->assetGetTargetUri($I, $asset, $expected);
    }
}
