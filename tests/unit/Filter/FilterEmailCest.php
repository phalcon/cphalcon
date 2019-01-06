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

namespace Phalcon\Test\Unit\Filter;

use Phalcon\Test\Unit\Filter\Helper\FilterBase;
use UnitTester;

class FilterEmailCest extends FilterBase
{
    /**
     * Tests Email
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeEmail(UnitTester $I)
    {
        $expected = 'someone@example.com';
        $value    = 'some(one)@exa\\mple.com';
        $this->sanitizer($I, 'email', $expected, $value);

        $expected = '!first.guy@*my-domain**##.com.rx';
        $value    = '!(first.guy)
                    @*my-domain**##.com.rx//';
        $this->sanitizer($I, 'email', $expected, $value);
    }
}
