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

/**
 * Class SetActionCest
 */
class SetActionCest
{
    /**
     * Tests Phalcon\Forms\Form :: setAction()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function formsFormSetAction(UnitTester $I)
    {
        $I->wantToTest('Forms\Form - setAction()');
        $I->skipTest('Need implementation');
    }
}
