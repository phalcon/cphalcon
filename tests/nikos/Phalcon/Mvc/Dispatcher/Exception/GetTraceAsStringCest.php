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

namespace Phalcon\Test\Unit\Mvc\Dispatcher\Exception;

use UnitTester;

class GetTraceAsStringCest
{
    /**
     * Tests Phalcon\Mvc\Dispatcher\Exception :: getTraceAsString()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function mvcDispatcherExceptionGetTraceAsString(UnitTester $I)
    {
        $I->wantToTest('Mvc\Dispatcher\Exception - getTraceAsString()');

        $I->skipTest('Need implementation');
    }
}
