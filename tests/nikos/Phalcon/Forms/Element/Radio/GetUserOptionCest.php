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

namespace Phalcon\Test\Unit\Forms\Element\Radio;

use UnitTester;

/**
 * Class GetUserOptionCest
 */
class GetUserOptionCest
{
    /**
     * Tests Phalcon\Forms\Element\Radio :: getUserOption()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function formsElementRadioGetUserOption(UnitTester $I)
    {
        $I->wantToTest('Forms\Element\Radio - getUserOption()');
        $I->skipTest('Need implementation');
    }
}
