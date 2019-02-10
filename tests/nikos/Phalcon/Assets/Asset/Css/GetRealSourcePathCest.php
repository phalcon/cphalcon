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
 * Class GetRealSourcePathCest
 */
class GetRealSourcePathCest
{
    /**
     * Tests Phalcon\Assets\Asset\Css :: getRealSourcePath()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function assetsAssetCssGetRealSourcePath(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset\Css - getRealSourcePath()');
        $I->skipTest('Need implementation');
    }
}
