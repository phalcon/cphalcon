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

namespace Phalcon\Test\Unit\Assets\Asset\Js;

use UnitTester;

class IsAutoVersionCest
{
    /**
     * Unit Tests Phalcon\Assets\Asset\Js :: isAutoVersion()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-25
     */
    public function assetsAssetJsIsAutoVersion(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset\Js - isAutoVersion()');

        $I->skipTest('Need implementation');
    }
}
