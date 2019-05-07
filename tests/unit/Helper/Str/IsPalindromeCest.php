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

namespace Phalcon\Test\Unit\Helper\Str;

use Phalcon\Helper\Str;
use UnitTester;

/**
 * Class IsPalindromeCest
 */
class IsPalindromeCest
{
    /**
     * Tests Phalcon\Helper\Str :: isPalindrome()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-06
     */
    public function helperStrIsPalindrome(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - isPalindrome()');

        $actual = Str::isPalindrome('racecar');
        $I->assertTrue($actual);
    }
}
