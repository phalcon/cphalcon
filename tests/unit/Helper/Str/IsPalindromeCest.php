<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Helper\Str;

use Phalcon\Helper\Str;
use UnitTester;

class IsPalindromeCest
{
    /**
     * Tests Phalcon\Helper\Str :: isPalindrome()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-06
     */
    public function helperStrIsPalindrome(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - isPalindrome()');

        $actual = Str::isPalindrome('racecar');
        $I->assertTrue($actual);
    }
}
