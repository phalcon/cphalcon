<?php
/**
 * FunctionalTest.php
 * \Phalcon\Tag\FunctionalTest
 *
 * Tests the \Phalcon\Tag component
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2014 Phalcon Team
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

namespace Phalcon\Test\Tag;

use \Phalcon\Test\FunctionalTestCase as PhTestFunctionalTestCase;

use \PhalconTest\Tag as PhTTag;

class FunctionalTest extends PhTestFunctionalTestCase
{
    private $message = "%s does not return proper html element";

    // -------------------------------------------------------------------------
    // form. endForm
    // -------------------------------------------------------------------------
    /**
     * Tests form with a string as a parameter
     *
     * @issue  57
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testFormBasicT57()
    {
        $params = 'about/index';

        $expected = '<form method="post" action="/about/index">';
        $actual   = PhTTag::form($params);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'form basic parameter')
        );
    }

    /**
     * Tests form with a string as a parameter
     *
     * @issue  57
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testFormBasicWithRandomStringT57()
    {
        $params = 'somestring';

        $expected = '<form method="post" action="/somestring">';
        $actual   = PhTTag::form($params);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'form with random string parameter')
        );
    }

    /**
     * Tests form with an array as parameters
     *
     * @issue  57
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testFormWithArrayParametersGetT57()
    {
        $params = array(
            'about/list',
            'method' => 'get',
        );

        $expected = '<form method="get" action="/about/list">';
        $actual   = PhTTag::form($params);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'form with array parameters get')
        );
    }

    /**
     * Tests form with an array as parameters
     *
     * @issue  57
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testFormWithArrayParametersPostT57()
    {
        $params = array(
            'about/list',
            'method' => 'post',
        );

        $expected = '<form method="post" action="/about/list">';
        $actual   = PhTTag::form($params);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'form with array parameters post')
        );
    }

    /**
     * Tests endForm with an array as parameters
     *
     * @issue  57
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-29
     */
    public function testEndForm()
    {
        $expected = '</form>';
        $actual   = PhTTag::endForm();

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'endForm')
        );
    }
}
