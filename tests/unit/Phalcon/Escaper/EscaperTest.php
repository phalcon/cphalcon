<?php
/**
 * EscaperTest.php
 * \Phalcon\Escaper
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

namespace Phalcon\Tests\unit\Phalcon\Translate\Adapter\NativeArray;

use \Phalcon\Escaper as PhEscaper;

class EscaperTest extends \Codeception\TestCase\Test
{
    use \Codeception\Specify;

    private $config = null;

    /**
     * Tests whether a key exists in the array
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-12
     */
    public function testEscaperHtml()
    {
        $this->specify(
            "The escaper does not escape string correctly",
            function () {

                $escaper  = new PhEscaper();
                $source   = "<h1></h1>";
                $expected = '&lt;h1&gt;&lt;/h1&gt;';
                $actual   = $escaper->escapeHtml($source);

                expect($actual)->equals($actual);
            }
        );
    }
}