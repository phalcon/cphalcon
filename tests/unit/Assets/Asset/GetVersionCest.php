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

use UnitTester;

class GetVersionCest
{
    /**
     * Unit Tests Phalcon\Assets\Asset :: getVersion()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-25
     */
    public function assetsAssetGetVersion(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getVersion()');

        $I->skipTest('Need implementation');
    }
}
