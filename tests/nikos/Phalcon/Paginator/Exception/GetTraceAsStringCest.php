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

namespace Phalcon\Test\Unit\Paginator\Exception;

use UnitTester;

/**
 * Class GetTraceAsStringCest
 */
class GetTraceAsStringCest
{
    /**
     * Tests Phalcon\Paginator\Exception :: getTraceAsString()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function paginatorExceptionGetTraceAsString(UnitTester $I)
    {
        $I->wantToTest('Paginator\Exception - getTraceAsString()');
        $I->skipTest('Need implementation');
    }
}
