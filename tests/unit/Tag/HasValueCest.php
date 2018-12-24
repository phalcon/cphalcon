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
 * Class HasValueCest
 */
class HasValueCest
{
    /**
     * Tests Phalcon\Tag :: hasValue()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function tagHasValue(UnitTester $I)
    {
        $I->wantToTest('Tag - hasValue()');
        $I->skipTest('Need implementation');
    }
}
