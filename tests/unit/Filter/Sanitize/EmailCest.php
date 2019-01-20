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

namespace Phalcon\Test\Unit\Filter\Sanitize;

use Phalcon\Filter\Sanitize\Email;
use UnitTester;

/**
 * Class EmailCest
 */
class EmailCest
{
    /**
     * Tests Phalcon\Filter\Sanitize\Email :: __invoke()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function filterSanitizeEmailInvoke(UnitTester $I)
    {
        $I->wantToTest('Filter\Sanitize\Email - __invoke()');
        $sanitizer = new Email();

        $value    = 'some(one)@exa\\mple.com';
        $expected = 'someone@example.com';
        $actual   = $sanitizer($value);
        $I->assertEquals($expected, $actual);

        $value    = '!(first.guy)
                    @*my-domain**##.com.rx//';
        $expected = '!first.guy@*my-domain**##.com.rx';
        $actual   = $sanitizer($value);
        $I->assertEquals($expected, $actual);
    }
}
