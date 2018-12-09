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

namespace Phalcon\Test\Unit\Assets\Inline;

use UnitTester;

/**
 * Class GetResourceKeyCest
 *
 * @package Phalcon\Test\Unit\Assets\Inline
 */
class GetResourceKeyCest
{
    /**
     * Tests Phalcon\Assets\Inline :: getResourceKey()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsInlineGetResourceKey(UnitTester $I)
    {
        $I->wantToTest("Assets\Inline - getResourceKey()");
        $I->skipTest("Need implementation");
    }
}
