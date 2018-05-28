<?php

namespace Phalcon\Test\Unit\Filter;

use Phalcon\Filter;
use Phalcon\Test\Unit\Filter\Helper\IPv4;

/**
 * \Phalcon\Test\Unit\Filter\FilterCustomTest
 * Tests the \Phalcon\Filter component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Filter
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class FilterCustomTest extends Helper\FilterBase
{
    /**
     * Tests a custom filter IPv4
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeCustomIpv4FilterHex()
    {
        $this->specify(
            "custom filter does not return correct hex",
            function () {
                $filter = new Filter();

                $filter->add('ipv4', new IPv4());

                expect($filter->sanitize('00:1c:42:bf:71:22', 'ipv4'))->isEmpty();
            }
        );
    }

    /**
     * Tests a custom filter IPv4 IP
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeCustomIpv4FilterIP()
    {
        $this->specify(
            "custom filter does not return correct IP",
            function () {
                $filter = new Filter();

                $filter->add('ipv4', new IPv4());

                $expected = '127.0.0.1';
                $actual   = $filter->sanitize('127.0.0.1', 'ipv4');
                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests a custom filter Lambda
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeCustomLambdaFalse()
    {
        $this->specify(
            "lambda custom filter does not return false",
            function () {
                $filter = new Filter();

                $filter->add(
                    'md5',
                    function ($value) {
                        $filtered = preg_replace('/[^0-9a-f]/', '', $value);

                        return (strlen($filtered) != 32) ? false : $value;
                    }
                );

                $actual   = $filter->sanitize('Lladlad12', 'md5');
                expect($actual)->false();
            }
        );
    }

    /**
     * Tests a custom filter Lambda
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeCustomLambdaFalseTrue()
    {
        $this->specify(
            "lambda custom filter does not return true",
            function () {
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
                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests a custom callable filter
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-04-15
     * @issue  https://github.com/phalcon/cphalcon/issues/11581
     */
    public function testSanitizeCustomCallableFilterIp()
    {
        $this->specify(
            "callable filter does not return correct IP",
            function () {
                $filter = new Filter();

                $filter->add('ipv4', [$this, 'ipv4callback']);

                expect($filter->sanitize('127.0.0.1', 'ipv4'))->equals('127.0.0.1');
            }
        );
    }

    public function ipv4callback($value)
    {
        return filter_var($value, FILTER_VALIDATE_IP, FILTER_FLAG_IPV4);
    }
}
