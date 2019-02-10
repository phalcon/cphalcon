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

namespace Phalcon\Test\Unit\Mvc\Application\Exception;

use UnitTester;

/**
 * Class GetTraceCest
 */
class GetTraceCest
{
    /**
     * Tests Phalcon\Mvc\Application\Exception :: getTrace()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function mvcApplicationExceptionGetTrace(UnitTester $I)
    {
        $I->wantToTest('Mvc\Application\Exception - getTrace()');
        $I->skipTest('Need implementation');
    }
}
