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

namespace Phalcon\Test\Unit\Assets\Asset\Css;

use UnitTester;

class GetVersionCest
{
    /**
     * Unit Tests Phalcon\Assets\Asset\Css :: getVersion()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-25
     */
    public function assetsAssetCssGetVersion(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset\Css - getVersion()');

        $I->skipTest('Need implementation');
    }
}
