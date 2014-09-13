<?php
/**
 * TagBase.php
 * \Phalcon\Tag
 *
 * Tests the \Phalcon\Tag component
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

namespace Phalcon\Tests\unit\Phalcon\Tag;

use \Phalcon\Di\FactoryDefault as PhDI;
use \Phalcon\Tag as PhTag;

class TagBase extends \Codeception\TestCase\Test
{
    use \Codeception\Specify;

    public function _before()
    {
        $di = new PhDI();
        $di::reset();
        PhTag::setDI($di);
    }

    /**
     * Runs the test for a Tag:: element with parameters
     *
     * @param string    $function
     * @param mixed     $options
     * @param string    $expected
     * @param boolean   $xhtml
     * @param string    $set
     */
    public function fieldParameter($function, $options, $expected, $xhtml, $set = '')
    {
        if ($xhtml) {
            PhTag::setDocType(PhTag::XHTML10_STRICT);
        } else {
            PhTag::setDocType(PhTag::HTML5);
        }

        $expected .= ($xhtml) ? ' />' : '>';

        if ($set) {
            PhTag::$set('x_name', 'x_value');
        }
        $actual   = PhTag::$function($options);
        if ($set) {
            PhTag::$set('x_name', '');
        }

        expect($actual)->equals($expected);
    }
}
