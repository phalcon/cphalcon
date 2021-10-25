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

namespace Phalcon\Tests\Unit\Support\Helper\Str;

use Phalcon\Support\Helper\Str\IsPalindrome;
use UnitTester;

/**
 * Class IsPalindromeCest
 *
 * @package Phalcon\Tests\Unit\Support\Helper\Str
 */
class IsPalindromeCest
{
    /**
     * Tests Phalcon\Support\Helper\Str :: isPalindrome()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperStrIsPalindrome(UnitTester $I)
    {
        $I->wantToTest('Support\Helper\Str - isPalindrome()');

        $object = new IsPalindrome();
        $actual = $object('racecar');
        $I->assertTrue($actual);
    }
}
