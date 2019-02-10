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

use UnitTester;

/**
 * Class GetTargetPathCest
 */
class GetTargetPathCest
{
    /**
     * Tests Phalcon\Assets\Asset\Js :: getTargetPath()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function assetsAssetJsGetTargetPath(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset\Js - getTargetPath()');
        $I->skipTest('Need implementation');
    }
}
