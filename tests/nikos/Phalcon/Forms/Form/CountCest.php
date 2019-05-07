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

namespace Phalcon\Test\Unit\Forms\Form;

use UnitTester;

class CountCest
{
    /**
     * Tests Phalcon\Forms\Form :: count()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function formsFormCount(UnitTester $I)
    {
        $I->wantToTest('Forms\Form - count()');

        $I->skipTest('Need implementation');
    }
}
