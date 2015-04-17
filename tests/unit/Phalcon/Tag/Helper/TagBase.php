<?php
/**
 * TagBase.php
 * \Phalcon\Tag
 *
 * Tests the \Phalcon\Tag component
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

namespace Phalcon\Tests\unit\Phalcon\Tag\Helper;

use Phalcon\Di\FactoryDefault as PhDI;

use \PhalconTest\Tag as PhTTag;

use \Phalcon\Tests\unit\Phalcon\_Helper\TestsBase as TBase;

class TagBase extends TBase
{
    public function _before()
    {
        parent::_before();

        PhDI::reset();
        $di = new PhDI();
        PhTTag::setDI($di);
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
        PhTTag::resetInput();

        if ($xhtml) {
            PhTTag::setDocType(PhTTag::XHTML10_STRICT);
        } else {
            PhTTag::setDocType(PhTTag::HTML5);
        }

        $expected .= ($xhtml) ? ' />' : '>';

        if ($set) {
            PhTTag::displayTo('x_name', 'x_value');
        }
        $actual   = PhTTag::$function($options);
        if ($set) {
            PhTTag::$set('x_name', '');
        }

        expect($actual)->equals($expected);
    }
}
