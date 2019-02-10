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

namespace Phalcon\Test\Unit\Translate\Exception;

use UnitTester;

/**
 * Class GetTraceCest
 */
class GetTraceCest
{
    /**
     * Tests Phalcon\Translate\Exception :: getTrace()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function translateExceptionGetTrace(UnitTester $I)
    {
        $I->wantToTest('Translate\Exception - getTrace()');
        $I->skipTest('Need implementation');
    }
}
