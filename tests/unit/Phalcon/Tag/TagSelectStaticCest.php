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

use \CodeGuy;
use \Phalcon\Tag as PhTag;

class TagCest
{
    /**
     * Tests the get
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     *
     * @param CodeGuy $I
     */
    public function testGet(CodeGuy $I)
    {
        $actual = Version::get();

        $I->assertTrue(
            is_string($actual),
            'get() does not return a string'
        );
    }

    // -------------------------------------------------------------------------
    // selectStatic
    // -------------------------------------------------------------------------
    /**
     * Tests selectStatic with string as a parameter throws exception
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticStringThrowsException()
    {
        $name    = 'some_field_name';
        $options = 'some_values';

        try {
            $actual   = PhTag::selectStatic($name, $options);
        } catch (\Phalcon\Tag\Exception $e) {
            // This is where we need to be
        }

        $this->assertInstanceOf(
            'Phalcon\Tag\Exception',
            $e,
            'selectStatic does not throw correct exception with wrong parameters'
        );
    }

    /**
     * Tests selectStatic with array as parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticWithArrayBasic()
    {
        $name    = 'some_field_name';
        $options = array(
            'A' => 'Active',
            'I' => 'Inactive',
        );
        $expected = '<select id="some_field_name" name="some_field_name">' . PHP_EOL
            . chr(9) . '<option value="A">Active</option>' . PHP_EOL
            . chr(9) . '<option value="I">Inactive</option>' . PHP_EOL
            . '</select>';
        $actual   = PhTag::selectStatic($name, $options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'selectStatic basic with array')
        );
    }

    /**
     * Tests selectStatic with id in parameters
     *
     * @issue  54
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticWithIdInParameters_T54()
    {
        $params = array(
            'some_field_name',
            'id'    => 'some_id',
            'class' => 'some_class',
        );
        $options = array(
            'A' => 'Active',
            'I' => 'Inactive',
        );
        $expected = '<select id="some_id" name="some_field_name" class="some_class">' . PHP_EOL
            . chr(9) . '<option value="A">Active</option>' . PHP_EOL
            . chr(9) . '<option value="I">Inactive</option>' . PHP_EOL
            . '</select>';
        $actual   = PhTag::selectStatic($params, $options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'selectStatic with id in parameters'
            )
        );
    }

    /**
     * Tests selectStatic with name and not id in parameters
     *
     * @issue  54
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticWithNameAndNotIdInParameters_T54()
    {
        $params = array(
            'some_field_name',
            'id'    => 'some_id',
            'class' => 'some_class',
        );
        $options = array(
            'A' => 'Active',
            'I' => 'Inactive',
        );
        $expected = '<select id="some_id" name="some_field_name" class="some_class">' . PHP_EOL
            . chr(9) . '<option value="A">Active</option>' . PHP_EOL
            . chr(9) . '<option value="I">Inactive</option>' . PHP_EOL
            . '</select>';
        $actual   = PhTag::selectStatic($params, $options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'selectStatic with name and id in parameters'
            )
        );
    }

    /**
     * Tests selectStatic with value in parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticWithValueInParameters()
    {
        $params = array(
            'some_field_name',
            'value' => 'I',
            'class' => 'some_class',
        );
        $options = array(
            'A' => 'Active',
            'I' => 'Inactive',
        );
        $expected = '<select id="some_field_name" name="some_field_name" class="some_class">' . PHP_EOL
            . chr(9) . '<option value="A">Active</option>' . PHP_EOL
            . chr(9) . '<option selected="selected" value="I">Inactive</option>' . PHP_EOL
            . '</select>';
        $actual   = PhTag::selectStatic($params, $options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'selectStatic with value in parameters'
            )
        );
    }

    /**
     * Tests selectStatic with setDefault
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticSetDefault()
    {
        $params = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        PhTag::setDefault('some_field_name', 'I');
        $options = array(
            'A' => 'Active',
            'I' => 'Inactive',
        );
        $expected = '<select id="some_field_name" name="some_field_name" class="some_class" size="10">' . PHP_EOL
            . chr(9) . '<option value="A">Active</option>' . PHP_EOL
            . chr(9) . '<option selected="selected" value="I">Inactive</option>' . PHP_EOL
            . '</select>';
        $actual   = PhTag::selectStatic($params, $options);
        PhTag::setDefault('some_field_name', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'selectStatic with setDefault')
        );
    }

    /**
     * Tests selectStatic with setDefault
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticDisplayTo()
    {
        $params = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        PhTag::displayTo('some_field_name', 'I');
        $options = array(
            'A' => 'Active',
            'I' => 'Inactive',
        );
        $expected = '<select id="some_field_name" name="some_field_name" class="some_class" size="10">' . PHP_EOL
            . chr(9) . '<option value="A">Active</option>' . PHP_EOL
            . chr(9) . '<option selected="selected" value="I">Inactive</option>' . PHP_EOL
            . '</select>';
        $actual   = PhTag::selectStatic($params, $options);
        PhTag::displayTo('some_field_name', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'selectStatic with setDefault')
        );
    }

    /**
     * Tests selectStatic with setDefault to an non existent element
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticSetDefaultElementNotPresent()
    {
        $params = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        PhTag::setDefault('some_field', 'I');
        $options = array(
            'A' => 'Active',
            'I' => 'Inactive',
        );
        $expected = '<select id="some_field_name" name="some_field_name" class="some_class" size="10">' . PHP_EOL
            . chr(9) . '<option value="A">Active</option>' . PHP_EOL
            . chr(9) . '<option value="I">Inactive</option>' . PHP_EOL
            . '</select>';
        $actual   = PhTag::selectStatic($params, $options);
        PhTag::setDefault('some_field', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'selectStatic with setDefault')
        );
    }

    /**
     * Tests selectStatic with setDefault to an non existent element
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticDisplayToElementNotPresent()
    {
        $params = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        PhTag::displayTo('some_field', 'I');
        $options = array(
            'A' => 'Active',
            'I' => 'Inactive',
        );
        $expected = '<select id="some_field_name" name="some_field_name" class="some_class" size="10">' . PHP_EOL
            . chr(9) . '<option value="A">Active</option>' . PHP_EOL
            . chr(9) . '<option value="I">Inactive</option>' . PHP_EOL
            . '</select>';
        $actual   = PhTag::selectStatic($params, $options);
        PhTag::displayTo('some_field', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'selectStatic with setDefault')
        );
    }

    /**
     * Tests selectStatic with string as a parameter throws exception
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticStringThrowsExceptionXHTML()
    {
        $name    = 'some_field_name';
        $options = 'some_values';

        try {
            $actual   = PhTag::selectStatic($name, $options);
        } catch (\Phalcon\Tag\Exception $e) {
            // This is where we need to be
        }

        $this->assertInstanceOf(
            'Phalcon\Tag\Exception',
            $e,
            'selectStatic does not throw correct exception with wrong parameters'
        );
    }

    /**
     * Tests selectStatic with array as parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticWithArrayBasicXHTML()
    {
        $name    = 'some_field_name';
        $options = array(
            'A' => 'Active',
            'I' => 'Inactive',
        );
        $expected = '<select id="some_field_name" name="some_field_name">' . PHP_EOL
            . chr(9) . '<option value="A">Active</option>' . PHP_EOL
            . chr(9) . '<option value="I">Inactive</option>' . PHP_EOL
            . '</select>';
        $actual   = PhTag::selectStatic($name, $options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML selectStatic basic with array')
        );
    }

    /**
     * Tests selectStatic with id in parameters
     *
     * @issue  54
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticWithIdInParameters_T54XHTML()
    {
        $params = array(
            'some_field_name',
            'id'    => 'some_id',
            'class' => 'some_class',
        );
        $options = array(
            'A' => 'Active',
            'I' => 'Inactive',
        );
        $expected = '<select id="some_id" name="some_field_name" class="some_class">' . PHP_EOL
            . chr(9) . '<option value="A">Active</option>' . PHP_EOL
            . chr(9) . '<option value="I">Inactive</option>' . PHP_EOL
            . '</select>';
        $actual   = PhTag::selectStatic($params, $options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'selectStatic with id in parameters'
            )
        );
    }

    /**
     * Tests selectStatic with name and not id in parameters
     *
     * @issue  54
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticWithNameAndNotIdInParameters_T54XHTML()
    {
        $params = array(
            'some_field_name',
            'id'    => 'some_id',
            'class' => 'some_class',
        );
        $options = array(
            'A' => 'Active',
            'I' => 'Inactive',
        );
        $expected = '<select id="some_id" name="some_field_name" class="some_class">' . PHP_EOL
            . chr(9) . '<option value="A">Active</option>' . PHP_EOL
            . chr(9) . '<option value="I">Inactive</option>' . PHP_EOL
            . '</select>';
        $actual   = PhTag::selectStatic($params, $options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'selectStatic with name and id in parameters'
            )
        );
    }

    /**
     * Tests selectStatic with value in parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticWithValueInParametersXHTML()
    {
        $params = array(
            'some_field_name',
            'value' => 'I',
            'class' => 'some_class',
        );
        $options = array(
            'A' => 'Active',
            'I' => 'Inactive',
        );
        $expected = '<select id="some_field_name" name="some_field_name" class="some_class">' . PHP_EOL
            . chr(9) . '<option value="A">Active</option>' . PHP_EOL
            . chr(9) . '<option selected="selected" value="I">Inactive</option>' . PHP_EOL
            . '</select>';
        $actual   = PhTag::selectStatic($params, $options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'selectStatic with value in parameters'
            )
        );
    }

    /**
     * Tests selectStatic with setDefault
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticSetDefaultXHTML()
    {
        $params = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        PhTag::setDefault('some_field_name', 'I');
        $options = array(
            'A' => 'Active',
            'I' => 'Inactive',
        );
        $expected = '<select id="some_field_name" name="some_field_name" class="some_class" size="10">' . PHP_EOL
            . chr(9) . '<option value="A">Active</option>' . PHP_EOL
            . chr(9) . '<option selected="selected" value="I">Inactive</option>' . PHP_EOL
            . '</select>';
        $actual   = PhTag::selectStatic($params, $options);
        PhTag::setDefault('some_field_name', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML selectStatic with setDefault')
        );
    }

    /**
     * Tests selectStatic with setDefault
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticDisplayToXHTML()
    {
        $params = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        PhTag::displayTo('some_field_name', 'I');
        $options = array(
            'A' => 'Active',
            'I' => 'Inactive',
        );
        $expected = '<select id="some_field_name" name="some_field_name" class="some_class" size="10">' . PHP_EOL
            . chr(9) . '<option value="A">Active</option>' . PHP_EOL
            . chr(9) . '<option selected="selected" value="I">Inactive</option>' . PHP_EOL
            . '</select>';
        $actual   = PhTag::selectStatic($params, $options);
        PhTag::displayTo('some_field_name', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML selectStatic with setDefault')
        );
    }

    /**
     * Tests selectStatic with setDefault to an non existent element
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticSetDefaultElementNotPresentXHTML()
    {
        $params = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        PhTag::setDefault('some_field', 'I');
        $options = array(
            'A' => 'Active',
            'I' => 'Inactive',
        );
        $expected = '<select id="some_field_name" name="some_field_name" class="some_class" size="10">' . PHP_EOL
            . chr(9) . '<option value="A">Active</option>' . PHP_EOL
            . chr(9) . '<option value="I">Inactive</option>' . PHP_EOL
            . '</select>';
        $actual   = PhTag::selectStatic($params, $options);
        PhTag::setDefault('some_field', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML selectStatic with setDefault')
        );
    }

    /**
     * Tests selectStatic with setDefault to an non existent element
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticDisplayToElementNotPresentXHTML()
    {
        $params = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        PhTag::displayTo('some_field', 'I');
        $options  = array(
            'A' => 'Active',
            'I' => 'Inactive',
        );
        $expected = '<select id="some_field_name" name="some_field_name" class="some_class" size="10">' . PHP_EOL
            . chr(9) . '<option value="A">Active</option>' . PHP_EOL
            . chr(9) . '<option value="I">Inactive</option>' . PHP_EOL
            . '</select>';
        $actual   = PhTag::selectStatic($params, $options);
        PhTag::displayTo('some_field', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML selectStatic with setDefault')
        );
    }


    public function testSelect()
    {
        $data = array(
            "status",
            array("Active" => array('A1' => 'A One', 'A2' => 'A Two'), "B" => "B One")
        );

        $html = <<<HTML
<select id="status" name="status">
	<optgroup label="Active">
	<option value="A1">A One</option>
	<option value="A2">A Two</option>
	</optgroup>
	<option value="B">B One</option>
</select>
HTML;

        $di = new Phalcon\DI\FactoryDefault();
        Tag::setDI($di);
        $ret = Tag::selectStatic($data);

        $this->assertEquals($ret, $html);

        $html = <<<HTML
<select id="status" name="status">
	<optgroup label="Active">
	<option selected="selected" value="A1">A One</option>
	<option value="A2">A Two</option>
	</optgroup>
	<option value="B">B One</option>
</select>
HTML;
        Tag::setDefault("status", "A1");

        $ret = Tag::selectStatic($data);

        $this->assertEquals($ret, $html);
    }


}
