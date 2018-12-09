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

namespace Phalcon\Test\Unit\Mvc\User\Module;

use UnitTester;

/**
 * Class UnderscoreGetCest
 *
 * @package Phalcon\Test\Unit\Mvc\User\Module
 */
class UnderscoreGetCest
{
    /**
     * Tests Phalcon\Mvc\User\Module :: __get()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcUserModuleUnderscoreGet(UnitTester $I)
    {
        $I->wantToTest("Mvc\User\Module - __get()");
        $I->skipTest("Need implementation");
    }
}
