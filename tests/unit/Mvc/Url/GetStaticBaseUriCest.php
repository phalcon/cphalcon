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

namespace Phalcon\Test\Unit\Mvc\Url;

use UnitTester;

/**
 * Class GetStaticBaseUriCest
 *
 * @package Phalcon\Test\Unit\Mvc\Url
 */
class GetStaticBaseUriCest
{
    /**
     * Tests Phalcon\Mvc\Url :: getStaticBaseUri()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcUrlGetStaticBaseUri(UnitTester $I)
    {
        $I->wantToTest("Mvc\Url - getStaticBaseUri()");
        $I->skipTest("Need implementation");
    }
}
