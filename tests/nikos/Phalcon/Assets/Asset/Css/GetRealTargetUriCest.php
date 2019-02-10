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

use UnitTester;

/**
 * Class GetRealTargetUriCest
 */
class GetRealTargetUriCest
{
    /**
     * Tests Phalcon\Assets\Asset\Css :: getRealTargetUri()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function assetsAssetCssGetRealTargetUri(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset\Css - getRealTargetUri()');
        $I->skipTest('Need implementation');
    }
}
