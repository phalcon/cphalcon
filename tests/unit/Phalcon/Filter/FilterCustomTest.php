<?php
/**
 * FilterCustomTest.php
 * \Phalcon\Text\FilterCustomTest
 *
 * Tests the Phalcon\Filter component
 *
 * Phalcon Framework
 *
 * @copyright (c) 2011-2014 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

namespace Phalcon\Tests\unit\Phalcon\Filter;

use \PhalconTest\Filter as PhTFilter;
use Phalcon\Tests\unit\Phalcon\Filter\Helper\IPv4 as PhTestFilterIPv4;

class FilterCustomTest extends Helper\FilterBase
{
    /**
     * Tests a custom filter IPv4
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeCustomIPv4FilterHex()
    {
        $this->specify(
            "custom filter does not return correct hex",
            function () {

                $filter = new PhTFilter();

                $filter->add('ipv4', new PhTestFilterIPv4());

                $actual   = $filter->sanitize('00:1c:42:bf:71:22', 'ipv4');
                expect($actual)->isEmpty();
            }
        );
    }

    /**
     * Tests a custom filter IPv4 IP
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeCustomIPv4FilterIP()
    {
        $this->specify(
            "custom filter does not return correct IP",
            function () {

                $filter = new PhTFilter();

                $filter->add('ipv4', new PhTestFilterIPv4());

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

                $filter = new PhTFilter();

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

                $filter = new PhTFilter();

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
}
