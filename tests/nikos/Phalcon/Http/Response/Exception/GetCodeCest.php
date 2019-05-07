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

namespace Phalcon\Test\Unit\Http\Response\Exception;

use UnitTester;

class GetCodeCest
{
    /**
     * Tests Phalcon\Http\Response\Exception :: getCode()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function httpResponseExceptionGetCode(UnitTester $I)
    {
        $I->wantToTest('Http\Response\Exception - getCode()');

        $I->skipTest('Need implementation');
    }
}
