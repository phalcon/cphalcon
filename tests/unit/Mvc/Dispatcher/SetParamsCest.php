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

namespace Phalcon\Test\Unit\Mvc\Dispatcher;

use UnitTester;

/**
 * Class SetParamsCest
 */
class SetParamsCest
{
    /**
     * Tests Phalcon\Mvc\Dispatcher :: setParams()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcDispatcherSetParams(UnitTester $I)
    {
        $I->wantToTest('Mvc\Dispatcher - setParams()');
        $I->skipTest('Need implementation');
    }
}
