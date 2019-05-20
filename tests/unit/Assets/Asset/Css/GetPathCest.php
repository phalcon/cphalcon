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

class GetPathCest
{
    /**
     * Tests Phalcon\Assets\Asset\Css :: getPath() - css local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetCssGetPathLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getPath() - css local');

        $path = 'css/docs.css';

        $asset = new Css($path);

        $I->assertEquals(
            $path,
            $asset->getPath()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset\Css :: getPath() - css remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetCssGetPathRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getPath() - css remote');

        $path = 'https://phalcon.ld/css/docs.css';

        $asset = new Css($path);

        $I->assertEquals(
            $path,
            $asset->getPath()
        );
    }
}
