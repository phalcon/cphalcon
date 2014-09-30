<?php
/**
 * UnitTest.php
 * \Phalcon\Text\UnitTest
 *
 * Tests the Phalcon\Filter component
 *
 * PhalconPHP Framework
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

use \Phalcon\Filter as PhFilter;

class UnitTest extends \Codeception\TestCase\Test
{
    use \Codeception\Specify;


    public function testRandomConstants()
    {
        $this->specify(
            "random constants are not correct",
            function () {

                expect(PhText::RANDOM_ALNUM)->equals(0);
                expect(PhText::RANDOM_ALPHA)->equals(1);
                expect(PhText::RANDOM_HEXDEC)->equals(2);
                expect(PhText::RANDOM_NUMERIC)->equals(3);
                expect(PhText::RANDOM_NOZERO)->equals(4);
            }
        );
    }


    /**
     * Tests Lower
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testSanitizeLowerAll()
    {
        $filter = new PhFilter();

        $expected = 'hello';
        $actual   = $filter->sanitize('HELLO', 'lower');

        $this->assertEquals(
            $expected,
            $actual,
            'Lower all is not correct'
        );
    }

    /**
     * Tests Lower
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testSanitizeLowerMixed()
    {
        $filter = new PhFilter();

        $expected = 'hello';
        $actual   = $filter->sanitize('HeLlO', 'lower');

        $this->assertEquals(
            $expected,
            $actual,
            'Lower mixed is not correct'
        );
    }

    /**
     * Tests Upper
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testSanitizeUpperAll()
    {
        $filter = new PhFilter();

        $expected = 'HELLO';
        $actual   = $filter->sanitize('hello', 'upper');

        $this->assertEquals(
            $expected,
            $actual,
            'Upper all is not correct'
        );
    }

    /**
     * Tests Upper
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testSanitizeUpperMixed()
    {
        $filter = new PhFilter();

        $expected = 'HELLO';
        $actual   = $filter->sanitize('HeLlO', 'upper');

        $this->assertEquals(
            $expected,
            $actual,
            'Upper mixed is not correct'
        );
    }

    /**
     * Tests Multiple filters
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testSanitizeMultiple()
    {
        $filter = new PhFilter();

        $expected = 'lol';
        $actual   = $filter->sanitize('   lol<<   ', array('string', 'trim'));

        $this->assertEquals(
            $expected,
            $actual,
            'Multiple filter is not correct'
        );
    }

    public function testSanitizeArray()
    {
        $filter = new PhFilter();

        $expected = array('1', '2', '3');
        $actual   = $filter->sanitize(array(' 1 ', '  2', '3  '), 'trim');

        $this->assertEquals(
            $expected,
            $actual,
            'Filter an array is not correct'
        );
    }

    public function testSanitizeArrayMultipleFilters()
    {
        $filter = new PhFilter();

        $expected = array('1', '2', '3');
        $actual   = $filter->sanitize(array(' <a href="a">1</a> ', '  <h1>2</h1>', '<p>3</p>  '), array('trim', 'striptags'));

        $this->assertEquals(
            $expected,
            $actual,
            'Filter an array with multiples filters is not correct'
        );
    }
}

