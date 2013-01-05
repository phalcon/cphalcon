<?php
/**
 * FunctionalTest.php
 * \Phalcon\Tag\FunctionalTest
 *
 * Tests the \Phalcon\Tag component
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2013 Phalcon Team
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

use \Phalcon\Tag as Tg;

class Tag_FunctionalTest extends Phalcon_Test_FunctionalTestCase
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
    public function testFormBasic_T57()
    {
        $params = 'about/index';

        $expected = '<form method="post" action="/about/index">';
        $actual   = Tg::form($params);

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
    public function testFormBasicWithRandomString_T57()
    {
        $params = 'somestring';

        $expected = '<form method="post" action="/somestring">';
        $actual   = Tg::form($params);

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
    public function testFormWithArrayParametersGet_T57()
    {
        $params = array(
            'about/list',
            'method' => 'get',
        );

        $expected = '<form method="get" action="/about/list">';
        $actual   = Tg::form($params);

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
    public function testFormWithArrayParametersPost_T57()
    {
        $params = array(
            'about/list',
            'method' => 'post',
        );

        $expected = '<form method="post" action="/about/list">';
        $actual   = Tg::form($params);

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
        $actual   = Tg::endForm();

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'endForm')
        );
    }
}