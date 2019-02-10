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
 * Class SetSourcePathCest
 */
class SetSourcePathCest
{
    /**
     * Tests Phalcon\Assets\Asset\Js :: setSourcePath()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function assetsAssetJsSetSourcePath(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset\Js - setSourcePath()');
        $I->skipTest('Need implementation');
    }
}
