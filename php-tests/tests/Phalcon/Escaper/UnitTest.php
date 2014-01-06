<?php
/**
 * UnitTest.php
 * Escaper_UnitTest
 *
 * Tests the \Phalcon\Escaper component
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

namespace Phalcon\Test\Escaper;

use \Phalcon\Test\UnitTestCase as PhTestUnitTestCase;

use \Phalcon\Escaper as PhEscaper;

class UnitTest extends PhTestUnitTestCase
{
    /**
     * Tests the escaper
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testEscapeHtml()
    {
        $escaper = new PhEscaper();

        $source = "<h1></h1>";

        $expected = '&lt;h1&gt;&lt;/h1&gt;';
        $actual   = $escaper->escapeHtml($source);

        $this->assertEquals(
            $expected,
            $actual,
            'The escaper does not escape string correctly'
        );
    }
}