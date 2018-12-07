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
 * Class SetAttributesCest
 *
 * @package Phalcon\Test\Unit\Assets\Asset\Js
 */
class SetAttributesCest
{
    /**
     * Tests Phalcon\Assets\Asset\Js :: setAttributes()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetJsSetAttributes(UnitTester $I)
    {
        $I->wantToTest("Assets\Asset\Js - setAttributes()");
        $I->skipTest("Need implementation");
    }
}
