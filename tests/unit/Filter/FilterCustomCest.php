<?php

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
use Phalcon\Test\Unit\Filter\Helper\IPv4;
use Phalcon\Test\Unit\Filter\Helper\FilterBase;
use UnitTester;

class FilterCustomCest extends FilterBase
{
    /**
     * Tests a custom filter IPv4
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeCustomIpv4FilterHex(UnitTester $I)
    {
        $filter = new Filter();
        $filter->add('ipv4', new IPv4());

        $actual = $filter->sanitize('00:1c:42:bf:71:22', 'ipv4');
        $I->assertEmpty($actual);
    }

    /**
     * Tests a custom filter IPv4 IP
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeCustomIpv4FilterIP(UnitTester $I)
    {
        $filter = new Filter();
        $filter->add('ipv4', new IPv4());

        $expected = '127.0.0.1';
        $actual   = $filter->sanitize('127.0.0.1', 'ipv4');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests a custom filter Lambda
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeCustomLambdaFalse(UnitTester $I)
    {
        $filter = new Filter();
        $filter->add(
            'md5',
            function ($value) {
                $filtered = preg_replace('/[^0-9a-f]/', '', $value);

                return (strlen($filtered) != 32) ? false : $value;
            }
        );

        $actual= $filter->sanitize('Lladlad12', 'md5');
        $I->assertFalse($actual);
    }

    /**
     * Tests a custom filter Lambda
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeCustomLambdaFalseTrue(UnitTester $I)
    {
        $filter = new Filter();
        $filter->add(
            'md5',
            function ($value) {
                $filtered = preg_replace('/[^0-9a-f]/', '', $value);

                return (strlen($filtered) != 32) ? false : $value;
            }
        );

        $expected = md5('why?');
        $actual   = $filter->sanitize($expected, 'md5');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests a custom callable filter
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-04-15
     * @issue  https://github.com/phalcon/cphalcon/issues/11581
     */
    public function testSanitizeCustomCallableFilterIp(UnitTester $I)
    {
        $filter = new Filter();
        $filter->add('ipv4', [$this, 'ipv4callback']);

        $expected = '127.0.0.1';
        $actual   = $filter->sanitize('127.0.0.1', 'ipv4');
        $I->assertEquals($expected, $actual);
    }

    public function ipv4callback($value)
    {
        return filter_var($value, FILTER_VALIDATE_IP, FILTER_FLAG_IPV4);
    }
}
