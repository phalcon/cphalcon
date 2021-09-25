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

namespace Phalcon\Tests\Unit\Assets\Asset\Js;

use Phalcon\Assets\Asset\Js;
use UnitTester;

class IsSetAutoVersionCest
{
    /**
     * Unit Tests Phalcon\Assets\Asset\Js :: isAutoVersion() / setAutoVersion()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-02-02
     */
    public function assetsAssetJsIsSetAutoVersion(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset\Js - isAutoVersion() / setAutoVersion()');

        $asset = new Js('js/jquery.js');

        $I->assertFalse($asset->isAutoVersion());

        $asset->setAutoVersion(true);

        $I->assertTrue($asset->isAutoVersion());
    }
}
