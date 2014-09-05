<?php
/**
 * TagDoctypeCest.php
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

use \CodeGuy;
use \Phalcon\Tag as PhTag;

class TagDoctypeCest
{
    private $message = "%s does not return proper html element";

    /**
     * Tests the setting the doctype
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     *
     * @param CodeGuy $I
     */
    public function testDoctypeSet(CodeGuy $I)
    {
        $doctype  = PhTag::HTML5;
        $expected = "<!DOCTYPE html>" . PHP_EOL;

        PhTag::setDocType($doctype);
        $actual = PhTag::getDocType();

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'Doctype (HTML5)')
        );
    }
}
