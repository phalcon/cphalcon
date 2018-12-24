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

namespace Phalcon\Test\Unit\Assets\Asset\Js;

use Phalcon\Assets\Asset\Js;
use Phalcon\Test\Fixtures\Traits\AssetsTrait;
use UnitTester;

/**
 * Class SetPathCest
 */
class SetPathCest
{
    use AssetsTrait;

    /**
     * Tests Phalcon\Assets\Asset :: setPath() - js local
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetJsSetPathLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setPath() - js local');
        $asset = new Js('js/jquery.js');

        $expected = '/new/path';
        $asset->setPath($expected);
        $this->assetGetPath($I, $asset, $expected);
    }

    /**
     * Tests Phalcon\Assets\Asset :: setPath() - js remote
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetJsSetPathRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setPath() - js remote');
        $asset = new Js('https://phalcon.ld/js/jquery.js');

        $expected = '/new/path';
        $asset->setPath($expected);
        $this->assetGetPath($I, $asset, $expected);
    }
}
