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

namespace Phalcon\Test\Unit\Application\Exception;

use UnitTester;

/**
 * Class GetLineCest
 */
class GetLineCest
{
    /**
     * Tests Phalcon\Application\Exception :: getLine()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function applicationExceptionGetLine(UnitTester $I)
    {
        $I->wantToTest('Application\Exception - getLine()');
        $I->skipTest('Need implementation');
    }
}
