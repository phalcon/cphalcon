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

/**
 * Class GetAssetKeyCest
 */
class GetAssetKeyCest
{
    /**
     * Tests Phalcon\Assets\Asset :: getAssetKey()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function assetsAssetGetAssetKey(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getAssetKey()');
        $I->skipTest('Need implementation');
    }
}
