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

namespace Phalcon\Test\Unit\Validation;

use UnitTester;

/**
 * Class GetDataCest
 */
class GetDataCest
{
    /**
     * Tests Phalcon\Validation :: getData()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function validationGetData(UnitTester $I)
    {
        $I->wantToTest('Validation - getData()');
        $I->skipTest('Need implementation');
    }
}
