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

class GetLocalCest
{
    /**
     * Tests Phalcon\Assets\Asset\Css :: getLocal() - css local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetCssGetLocalLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getLocal() - css local');

        $file = 'css/docs.css';

        $asset = new Css($file);

        $I->assertTrue(
            $asset->getLocal()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset\Css :: getLocal() - css remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetCssGetLocalRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getLocal() - css remote');

        $file = 'https://phalcon.ld/css/docs.css';

        $asset = new Css($file);

        $I->assertTrue(
            $asset->getLocal()
        );
    }
}
