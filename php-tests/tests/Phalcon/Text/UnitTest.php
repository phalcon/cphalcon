<?php
/**
 * UnitTest.php
 * \Phalcon\Text\UnitTest
 *
 * Tests the \Phalcon\Text component
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

namespace Phalcon\Text;

use \Phalcon\Test\UnitTestCase as PhTestUnitTestCase;

use Phalcon\Text as PhText;

class UnitTest extends PhTestUnitTestCase
{
    /**
     * Tests the camelize function
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-30
     */
    public function testCamelizeString()
    {
        $camelizeTests = array (
            'camelize'        => 'Camelize',
            'CameLiZe'        => 'Camelize',
            'cAmeLize'        => 'Camelize',
            '_camelize'       => 'Camelize',
            '123camelize'     => '123camelize',
            'c_a_m_e_l_i_z_e' => 'CAMELIZE',
            'Camelize'        => 'Camelize',
            'camel_ize'       => 'CamelIze',
            'CameLize'        => 'Camelize',
            'CAMELIZE'        => 'Camelize',
            'camelizE'        => 'Camelize'
        );

        $template = "Text::camelize did not convert the string '%s' correctly";

        foreach ($camelizeTests as $input => $camelized) {
            $expected = $camelized;
            $actual   = PhText::camelize($input);
            $this->assertEquals(
                $expected,
                $actual,
                sprintf($template, $input)
            );
        }
    }

    /**
     * Tests the uncamelize function
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-10-30
     */
    public function testUncamelizeString()
    {

        $uncamelizeTests = array (
            'camelize'        => 'camelize',
            'CameLiZe'        => 'came_li_ze',
            'cAmeLize'        => 'c_ame_lize',
            '_camelize'       => '_camelize',
            '123camelize'     => '123camelize',
            'c_a_m_e_l_i_z_e' => 'c_a_m_e_l_i_z_e',
            'Camelize'        => 'camelize',
            'camel_ize'       => 'camel_ize',
            'CameLize'        => 'came_lize',
        );

        $template = "Text::uncamelize did not convert the string '%s' correctly";

        foreach ($uncamelizeTests as $input => $uncamelized) {
            $expected = $uncamelized;
            $actual   = PhText::uncamelize($input);
            $this->assertEquals(
                $expected,
                $actual,
                sprintf($template, $input)
            );
        }
    }

    public function testIncrement()
    {
        $this->assertEquals(PhText::increment('file'), 'file_1');
        $this->assertEquals(PhText::increment('file_1'), 'file_2');
        $this->assertEquals(PhText::increment('file_2'), 'file_3');
        $this->assertEquals(PhText::increment('file_'), 'file_1');
    }

    public function testStartsWith()
    {
        $this->assertFalse(PhText::startsWith("", ""));
        $this->assertFalse(PhText::startsWith("", "hello"));
        $this->assertTrue(PhText::startsWith("Hello", "H"));
        $this->assertTrue(PhText::startsWith("Hello", "He"));
        $this->assertTrue(PhText::startsWith("Hello", "Hello"));
        $this->assertFalse(PhText::startsWith("Hello", "hel"));
        $this->assertFalse(PhText::startsWith("Hello", "hello"));
        $this->assertFalse(PhText::startsWith("Hello", "hello", true));
        $this->assertTrue(PhText::startsWith("Hello", "hello", false));
        $this->assertTrue(PhText::startsWith("Hello", "h", false));
    }

    public function testEndsWith()
    {
        $this->assertFalse(PhText::endsWith("", ""));
        $this->assertFalse(PhText::endsWith("", "hello"));
        $this->assertTrue(PhText::endsWith("Hello", "o"));
        $this->assertTrue(PhText::endsWith("Hello", "lo"));
        $this->assertTrue(PhText::endsWith("Hello", "Hello"));
        $this->assertFalse(PhText::endsWith("Hello", "LLO"));
        $this->assertFalse(PhText::endsWith("Hello", "hello"));
        $this->assertFalse(PhText::endsWith("Hello", "hello", true));
        $this->assertTrue(PhText::endsWith("Hello", "hello", false));
        $this->assertTrue(PhText::endsWith("Hello", "o", false));
    }

    public function testUpper()
    {
        $this->assertEquals(PhText::upper('hello'), 'HELLO');
        $this->assertEquals(PhText::upper('HELLO'), 'HELLO');
        $this->assertEquals(PhText::upper('1234'), '1234');
    }

    public function testLower()
    {
        $this->assertEquals(PhText::lower('hello'), 'hello');
        $this->assertEquals(PhText::lower('HELLO'), 'hello');
        $this->assertEquals(PhText::lower('1234'), '1234');
    }

    public function testRandomAlnum()
    {
        for ($i = 1; $i<10; $i++) {
            $text = PhText::random(PhText::RANDOM_ALNUM, $i);
            $this->assertEquals(preg_match('/[a-zA-Z0-9]+/', $text, $matches), 1);
            $this->assertEquals($matches[0], $text);
            $this->assertEquals(strlen($text), $i);
        }
    }

    public function testRandomAlpha()
    {
        for ($i = 1; $i<10; $i++) {
            $text = PhText::random(PhText::RANDOM_ALPHA, $i);
            $this->assertEquals(preg_match('/[a-zA-Z]+/', $text, $matches), 1);
            $this->assertEquals($matches[0], $text);
            $this->assertEquals(strlen($text), $i);
        }
    }

    public function testRandomHexDec()
    {
        for ($i = 1; $i<10; $i++) {
            $text = PhText::random(PhText::RANDOM_HEXDEC, $i);
            $this->assertEquals(preg_match('/[a-f0-9]+/', $text, $matches), 1);
            $this->assertEquals($matches[0], $text);
            $this->assertEquals(strlen($text), $i);
        }
    }

    public function testRandomNumeric()
    {
        for ($i = 1; $i<10; $i++) {
            $text = PhText::random(PhText::RANDOM_NUMERIC, $i);
            $this->assertEquals(preg_match('/[0-9]+/', $text, $matches), 1);
            $this->assertEquals($matches[0], $text);
            $this->assertEquals(strlen($text), $i);
        }
    }

    public function testRandomNonZero()
    {
        for ($i = 1; $i<10; $i++) {
            $text = PhText::random(PhText::RANDOM_NOZERO, $i);
            $this->assertEquals(preg_match('/[1-9]+/', $text, $matches), 1);
            $this->assertEquals($matches[0], $text);
            $this->assertEquals(strlen($text), $i);
        }
    }
}
