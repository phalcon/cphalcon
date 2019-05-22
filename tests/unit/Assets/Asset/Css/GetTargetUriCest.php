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

namespace Phalcon\Test\Unit\Assets\Asset\Css;

use Phalcon\Assets\Asset\Css;
use UnitTester;

class GetTargetUriCest
{
    /**
     * Tests Phalcon\Assets\Asset\Css :: getTargetUri() - css local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetCssGetTargetUriLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getTargetUri() - css local');

        $asset = new Css('css/docs.css');

        $expected = '/phalcon/path';

        $asset->setTargetUri($expected);

        $I->assertEquals(
            $expected,
            $asset->getTargetUri()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset\Css :: getTargetUri() - css remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetCssGetTargetUriRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getTargetUri() - css remote');

        $asset = new Css('https://phalcon.ld/css/docs.css', false);

        $expected = '/phalcon/path';

        $asset->setTargetUri($expected);

        $I->assertEquals(
            $expected,
            $asset->getTargetUri()
        );
    }
}
