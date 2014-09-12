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

class TagSelectStaticCest extends TagBase
{
    /**
     * Tests the get
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     *
     * @param CodeGuy $I
     */
//    public function testGet(CodeGuy $I)
//    {
//        $actual = Version::get();
//
//        $I->assertTrue(
//            is_string($actual),
//            'get() does not return a string'
//        );
//    }

    // -------------------------------------------------------------------------
    // selectStatic
    // -------------------------------------------------------------------------
    /**
     * Tests selectStatic with array as parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticWithArrayBasic(CodeGuy $I)
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

        $I->assertEquals(
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
    public function testSelectStaticWithIdInParameters_T54(CodeGuy $I)
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

        $I->assertEquals(
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
    public function testSelectStaticWithNameAndNotIdInParameters_T54(CodeGuy $I)
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

        $I->assertEquals(
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
    public function testSelectStaticWithValueInParameters(CodeGuy $I)
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

        $I->assertEquals(
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
    public function testSelectStaticSetDefault(CodeGuy $I)
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

        $I->assertEquals(
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
    public function testSelectStaticDisplayTo(CodeGuy $I)
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

        $I->assertEquals(
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
    public function testSelectStaticSetDefaultElementNotPresent(CodeGuy $I)
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

        $I->assertEquals(
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
    public function testSelectStaticDisplayToElementNotPresent(CodeGuy $I)
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

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'selectStatic with setDefault')
        );
    }

    /**
     * Tests selectStatic with array as parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticWithArrayBasicXHTML(CodeGuy $I)
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

        $I->assertEquals(
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
    public function testSelectStaticWithIdInParameters_T54XHTML(CodeGuy $I)
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

        $I->assertEquals(
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
    public function testSelectStaticWithNameAndNotIdInParameters_T54XHTML(CodeGuy $I)
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

        $I->assertEquals(
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
    public function testSelectStaticWithValueInParametersXHTML(CodeGuy $I)
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

        $I->assertEquals(
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
    public function testSelectStaticSetDefaultXHTML(CodeGuy $I)
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

        $I->assertEquals(
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
    public function testSelectStaticDisplayToXHTML(CodeGuy $I)
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

        $I->assertEquals(
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
    public function testSelectStaticSetDefaultElementNotPresentXHTML(CodeGuy $I)
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

        $I->assertEquals(
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
    public function testSelectStaticDisplayToElementNotPresentXHTML(CodeGuy $I)
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

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML selectStatic with setDefault')
        );
    }


    public function testSelect(CodeGuy $I)
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

        $ret = PhTag::selectStatic($data);

        $I->assertEquals($ret, $html);

        $html = <<<HTML
<select id="status" name="status">
	<optgroup label="Active">
	<option selected="selected" value="A1">A One</option>
	<option value="A2">A Two</option>
	</optgroup>
	<option value="B">B One</option>
</select>
HTML;
        PhTag::setDefault("status", "A1");

        $ret = PhTag::selectStatic($data);

        $I->assertEquals($ret, $html);
    }


}
