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

use Phalcon\Filter;
use Phalcon\Test\Unit\Filter\Helper\FilterBase;
use UnitTester;

class FilterUrlCest extends FilterBase
{
    /**
     * Tests Url
     *
     * @author Zamrony P. Juhara <zamronypj@yahoo.com>
     * @since  2017-03-23
     */
    public function testSanitizeUrl(UnitTester $I)
    {
        $expected = 'http://juhara.com';
        $value    = 'http://juhara��.co�m';
        $this->sanitizer($I, 'url', $expected, $value);
    }
}
