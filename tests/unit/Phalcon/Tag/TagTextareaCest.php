<?php
/**
 * TagCest.php
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

use \CodeGuy;
use \Phalcon\Tag as PhTag;

class TagCest extends TagBase
{
    /**
     * Tests textArea with string as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTextareaBasic(CodeGuy $I)
    {
        $options  = 'some_field_name';
        $expected = '<textarea id="some_field_name" '
                  . 'name="some_field_name"></textarea>';
        $actual   = PhTag::textArea($options);

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'textArea basic')
        );
    }

    /**
     * Tests textArea with array as parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTextareaWithArrayBasic(CodeGuy $I)
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
        );
        $expected = '<textarea id="some_field_name" name="some_field_name" '
                  . 'class="some_class"></textarea>';
        $actual   = PhTag::textArea($options);

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'textArea basic with array')
        );
    }

    /**
     * Tests textArea with id in parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTextareaWithIdInParameters(CodeGuy $I)
    {
        $options = array(
            'some_field_name',
            'id'    => 'some_id',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<textarea id="some_id" name="some_field_name" '
                  . 'class="some_class" size="10"></textarea>';
        $actual   = PhTag::textArea($options);

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'textArea with id in parameters')
        );
    }

    /**
     * Tests textArea with name and not id in parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTextareaWithNameAndNotIdInParameters(CodeGuy $I)
    {
        $options = array(
            'some_field_name',
            'name'  => 'some_other_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<textarea id="some_field_name" name="some_other_name" '
                  . 'class="some_class" size="10"></textarea>';
        $actual   = PhTag::textArea($options);

        $I->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'textArea with name and not id in parameters'
            )
        );
    }

    /**
     * Tests textArea with setDefault
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTextareaSetDefault(CodeGuy $I)
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        PhTag::setDefault('some_field_name', 'some_default_value');
        $expected = '<textarea id="some_field_name" name="some_field_name" '
                  . 'class="some_class" size="10">some_default_value</textarea>';
        $actual   = PhTag::textArea($options);
        PhTag::setDefault('some_field_name', '');

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'textArea with setDefault')
        );
    }

    /**
     * Tests textArea with displayTo
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTextareaDisplayTo(CodeGuy $I)
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        PhTag::displayTo('some_field_name', 'some_default_value');
        $expected = '<textarea id="some_field_name" name="some_field_name" '
                  . 'class="some_class" size="10">some_default_value</textarea>';
        $actual   = PhTag::textArea($options);
        PhTag::displayTo('some_field_name', '');

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'textArea with displayTo')
        );
    }

    /**
     * Tests textArea with setDefault to an non existent element
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTextareaSetDefaultElementNotPresent(CodeGuy $I)
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        PhTag::setDefault('some_field', 'some_default_value');
        $expected = '<textarea id="some_field_name" name="some_field_name" '
                  . 'class="some_class" size="10"></textarea>';
        $actual   = PhTag::textArea($options);
        PhTag::setDefault('some_field', '');

        $I->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'textArea with setDefault and element not present'
            )
        );
    }

    /**
     * Tests textArea with displayTo to an non existent element
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTextareaDisplayToElementNotPresent(CodeGuy $I)
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        PhTag::displayTo('some_field', 'some_default_value');
        $expected = '<textarea id="some_field_name" name="some_field_name" '
                  . 'class="some_class" size="10"></textarea>';
        $actual   = PhTag::textArea($options);
        PhTag::displayTo('some_field', '');

        $I->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'textArea with displayTo and element not present'
            )
        );
    }

}
