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

namespace Phalcon\Test\Unit\Tag;

use UnitTester;

/**
 * Class NumericFieldCest
 */
class NumericFieldCest
{
    /**
     * Tests Phalcon\Tag :: numericField()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function tagNumericField(UnitTester $I)
    {
        $I->wantToTest('Tag - numericField()');
        $I->skipTest('Need implementation');
    }
}
