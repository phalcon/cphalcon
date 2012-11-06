<?php
/**
 * UnitTest.php
 * Escaper_UnitTest
 *
 * Tests the \Phalcon\Escaper component
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2012 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Eduar Carvajal <eduar@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@niden.net>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

use \Phalcon\Escaper as PhEscaper;

class Escaper_UnitTest extends Phalcon_Test_UnitTestCase
{
    /**
     * Tests the escaper
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-05
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