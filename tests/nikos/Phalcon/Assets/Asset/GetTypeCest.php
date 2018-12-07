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
 * Class GetTypeCest
 *
 * @package Phalcon\Test\Unit\Assets\Asset
 */
class GetTypeCest
{
    /**
     * Tests Phalcon\Assets\Asset :: getType()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetType(UnitTester $I)
    {
        $I->wantToTest("Assets\Asset - getType()");
        $I->skipTest("Need implementation");
    }
}
