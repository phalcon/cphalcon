<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Filter\Filter;

use Phalcon\Filter;
use Phalcon\Test\Fixtures\Filter\Sanitize\IPv4;
use UnitTester;

class CustomCest
{
    /**
     * Tests Phalcon\Filter :: custom has()
     *
     * @param  UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-01-19
     */
    public function filterFilterCustomHas(UnitTester $I)
    {
        $I->wantToTest('Filter\Filter - custom has()');

        $I->assertTrue(
            (new Filter(['ipv4' => IPv4::class]))->has('ipv4')
        );
    }

    /**
     * Tests Phalcon\Filter :: custom sanitizer
     *
     * @param  UnitTester $I
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-01-19
     */
    public function filterFilterCustomSanitizer(UnitTester $I)
    {
        $I->wantToTest('Filter\Filter - custom sanitizer');

        /** @var IPv4 $sanitizer */
        $sanitizer = (new Filter(['ipv4' => IPv4::class]))->get('ipv4');

        $I->assertInstanceOf(
            IPv4::class,
            $sanitizer
        );

        $I->assertEquals(
            '127.0.0.1',
            $sanitizer('127.0.0.1')
        );

        $I->assertFalse(
            $sanitizer('127.0.0')
        );
    }
}
