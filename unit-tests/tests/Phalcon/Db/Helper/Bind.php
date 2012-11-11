<?php
/**
 * Helper.php
 * \Phalcon\Db\Bind\Helper
 *
 * Db Bind test helper
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2012 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Eduar Carvajal <eduar@phalconphp.com>
 * @author    Rack Lin <racklin@gmail.com>
 * @author    Nikolaos Dimopoulos <nikos@niden.net>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

use \Phalcon\Db\Column as PhDbColumn;
use \Phalcon\Db\RawValue as PhDbRawValue;

class Db_Bind_Helper extends Phalcon_Test_ModelTestCase
{
    protected $_nullDefault = null;

    /**
     * Tests one on one parameter - number
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-11
     */
    public function testRawBindTestOneOnOneParameterNumber()
    {
        $connection = $this->_di->get('db');

        $expected = 'a=100';
        $actual   = $connection->bindParams(
            "a=?0",
            array(0 => 100)
        );

        $this->assertEquals(
            $expected,
            $actual,
            'Binding not correct ' . $expected
        );
    }

    /**
     * Tests one on two parameter - number
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-11
     */
    public function testRawBindTestOneOnTwoParametersNumber()
    {
        $connection = $this->_di->get('db');

        $expected = 'a=100';
        $actual   = $connection->bindParams(
            "a=?0",
            array(
                0 => 100,
                1 => 50
            )
        );

        $this->assertEquals(
            $expected,
            $actual,
            'Binding not correct ' . $expected
        );
    }

    /**
     * Tests one on two (second) parameter - number
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-11
     */
    public function testRawBindTestOneOnSecondParameterNumber()
    {
        $connection = $this->_di->get('db');

        $expected = 'a=?0';
        $actual   = $connection->bindParams(
            "a=?0",
            array(1 => 50)
        );

        $this->assertEquals(
            $expected,
            $actual,
            'Binding not correct ' . $expected
        );
    }

    /**
     * Tests two on two parameter - number
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-11
     */
    public function testRawBindTestTwoOnTwoParametersNumber()
    {
        $connection = $this->_di->get('db');

        $expected = "a=25 AND b=50";
        $actual   = $connection->bindParams(
            "a=?0 AND b=?1",
            array(
                0 => 25,
                1 => 50
            )
        );

        $this->assertEquals(
            $expected,
            $actual,
            'Binding not correct ' . $expected
        );
    }

    /**
     * Tests two on two (reverse) parameter - number
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-11
     */
    public function testRawBindTestTwoOnTwoParametersReversedNumber()
    {
        $connection = $this->_di->get('db');

        $expected = "a=50 AND b=25";
        $actual   = $connection->bindParams(
            "a=?1 AND b=?0",
            array(
                0 => 25,
                1 => 50
            )
        );

        $this->assertEquals(
            $expected,
            $actual,
            'Binding not correct ' . $expected
        );
    }

    /**
     * Tests one on one parameter - string
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-11
     */
    public function testRawBindTestOneOnOneParameterString()
    {
        $connection = $this->_di->get('db');

        $expected = 'a=100';
        $actual   = $connection->bindParams(
            "a=?0",
            array(0 => '100')
        );

        $this->assertEquals(
            $expected,
            $actual,
            'Binding not correct ' . $expected
        );
    }

    /**
     * Tests one on two parameter - string
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-11
     */
    public function testRawBindTestOneOnTwoParametersString()
    {
        $connection = $this->_di->get('db');

        $expected = 'a=100';
        $actual   = $connection->bindParams(
            "a=?0",
            array(
                0 => '100',
                1 => '50'
            )
        );

        $this->assertEquals(
            $expected,
            $actual,
            'Binding not correct ' . $expected
        );
    }

    /**
     * Tests one on two (second) parameter - string
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-11
     */
    public function testRawBindTestOneOnSecondParameterString()
    {
        $connection = $this->_di->get('db');

        $expected = 'a=?0';
        $actual   = $connection->bindParams(
            "a=?0",
            array(1 => '50')
        );

        $this->assertEquals(
            $expected,
            $actual,
            'Binding not correct ' . $expected
        );
    }

    /**
     * Tests two on two parameter - string
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-11
     */
    public function testRawBindTestTwoOnTwoParametersString()
    {
        $connection = $this->_di->get('db');

        $expected = "a=25 AND b=50";
        $actual   = $connection->bindParams(
            "a=?0 AND b=?1",
            array(
                0 => '25',
                1 => '50'
            )
        );

        $this->assertEquals(
            $expected,
            $actual,
            'Binding not correct ' . $expected
        );
    }

    /**
     * Tests two on two (reverse) parameter - string
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-11
     */
    public function testRawBindTestTwoOnTwoParametersReversedString()
    {
        $connection = $this->_di->get('db');

        $expected = "a=50 AND b=25";
        $actual   = $connection->bindParams(
            "a=?1 AND b=?0",
            array(
                0 => '25',
                1 => '50'
            )
        );

        $this->assertEquals(
            $expected,
            $actual,
            'Binding not correct ' . $expected
        );
    }

    /**
     * Tests one on one parameter - float
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-11
     */
    public function testRawBindTestOneOnOneParameterFloat()
    {
        $connection = $this->_di->get('db');

        $expected = 'a=100.5';
        $actual   = $connection->bindParams(
            "a=?0",
            array(0 => 100.50)
        );

        $this->assertEquals(
            $expected,
            $actual,
            'Binding not correct ' . $expected
        );
    }

    /**
     * Tests one on two parameter - float
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-11
     */
    public function testRawBindTestOneOnTwoParametersFloat()
    {
        $connection = $this->_di->get('db');

        $expected = 'a=100.5';
        $actual   = $connection->bindParams(
            "a=?0",
            array(
                0 => 100.50,
                1 => '100.60'
            )
        );

        $this->assertEquals(
            $expected,
            $actual,
            'Binding not correct ' . $expected
        );
    }

    /**
     * Tests one on two (second) parameter - float
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-11
     */
    public function testRawBindTestOneOnSecondParameterFloat()
    {
        $connection = $this->_di->get('db');

        $expected = 'a=?0';
        $actual   = $connection->bindParams(
            "a=?0",
            array(1 => 100.50)
        );

        $this->assertEquals(
            $expected,
            $actual,
            'Binding not correct ' . $expected
        );
    }

    /**
     * Tests two on two parameter - float
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-11
     */
    public function testRawBindTestTwoOnTwoParametersFloat()
    {
        $connection = $this->_di->get('db');

        $expected = "a=100.50 AND b=100.5";
        $actual   = $connection->bindParams(
            "a=?0 AND b=?1",
            array(
                0 => '100.50',
                1 => 100.50
            )
        );

        $this->assertEquals(
            $expected,
            $actual,
            'Binding not correct ' . $expected
        );
    }

    /**
     * Tests two on two (reverse) parameter - float
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-11
     */
    public function testRawBindTestTwoOnTwoParametersReversedFloat()
    {
        $connection = $this->_di->get('db');

        $expected = "a=100.5 AND b=100.50";
        $actual   = $connection->bindParams(
            "a=?1 AND b=?0",
            array(
                0 => '100.50',
                1 => 100.50
            )
        );

        $this->assertEquals(
            $expected,
            $actual,
            'Binding not correct ' . $expected
        );
    }

    /**
     * Tests three on three parameter - mixed
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-11
     */
    public function testRawBindTestThreeOnThreeMixed()
    {
        $connection = $this->_di->get('db');

        $expected = "a=50 AND b=25 AND c<>15";
        $actual   = $connection->bindParams(
            "a=?1 AND b=?0 AND c<>?2",
            array(
                0 => 25,
                1 => 50,
                2 => 15
            )
        );

        $this->assertEquals(
            $expected,
            $actual,
            'Binding not correct ' . $expected
        );
    }

    /**
     * Tests one on one parameter - text
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-11
     */
    public function testRawBindOneOnOneText()
    {
        $connection = $this->_di->get('db');

        $expected = "a='no-suprises'";
        $actual   = $connection->bindParams(
            "a=:a:",
            array('a' => 'no-suprises')
        );

        $this->assertEquals(
            $expected,
            $actual,
            'Binding not correct ' . $expected
        );
    }

    /**
     * Tests two on two parameter - text
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-11
     */
    public function testRawBindTwoOnTwoText()
    {
        $connection = $this->_di->get('db');

        $expected = "column1='hello' AND column2='lol'";
        $actual   = $connection->bindParams(
            "column1=:column1: AND column2=:column2:",
            array(
                'column1' => 'hello',
                'column2' => 'lol'
            )
        );

        $this->assertEquals(
            $expected,
            $actual,
            'Binding not correct ' . $expected
        );
    }

    /**
     * Test on bound parameters - insert
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-11
     */
    public function testTypeBindExecuteInsert()
    {
        $this->emptyTable('customers');

        $actual = $this->_insertRecord();

        $this->assertTrue($actual, 'Record was not inserted correctly');
    }

    /**
     * Test on bound parameters - update
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-11
     */
    public function testTypeBindExecuteUpdate()
    {
        $this->emptyTable('customers');

        $connection = $this->_di->get('db');

        $actual = $this->_insertRecord();
        $this->assertTrue($actual, 'Record was not inserted correctly');

        $sql    = "UPDATE customers SET first_name = ?, status = ?";
        $params = array('Jane', 'X');
        $bind   = array(PhDbColumn::BIND_PARAM_STR, PhDbColumn::BIND_PARAM_STR);

        $actual = $connection->execute($sql, $params, $bind);
        $this->assertTrue($actual, 'Record was not updated correctly');
    }

    /**
     * Test on bound parameters - delete
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-11
     */
    public function testTypeBindExecuteDelete()
    {
        $this->emptyTable('customers');

        $connection = $this->_di->get('db');

        $actual = $this->_insertRecord();
        $this->assertTrue($actual, 'Record was not inserted correctly');

        $sql    = "DELETE FROM customers WHERE status = ?";
        $params = array('A');
        $bind   = array(PhDbColumn::BIND_PARAM_STR);

        $actual = $connection->execute($sql, $params, $bind);
        $this->assertTrue($actual, 'Record was not deleted correctly');
    }

    /**
     * Test on bound parameters - insert with null on PK
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-11
     */
    public function testTypeBindInsertBindSkipNull()
    {
        $this->emptyTable('customers');

        $connection = $this->_di->get('db');

        $table  = 'customers';
        $params = array(
            $this->_nullDefault,
            1,
            1,
            'John',
            'Doe',
            '555-444-6666',
            'john@doe.com',
            'Some instructions',
            'A',
            '1970-10-30',
            100.00,
            '2012-10-30 00:00:30',
            4
        );
        $bind   = array(
            PhDbColumn::BIND_SKIP,
            PhDbColumn::BIND_PARAM_INT,
            PhDbColumn::BIND_PARAM_INT,
            PhDbColumn::BIND_PARAM_STR,
            PhDbColumn::BIND_PARAM_STR,
            PhDbColumn::BIND_PARAM_STR,
            PhDbColumn::BIND_PARAM_STR,
            PhDbColumn::BIND_PARAM_STR,
            PhDbColumn::BIND_PARAM_STR,
            PhDbColumn::BIND_PARAM_STR,
            PhDbColumn::BIND_PARAM_INT,
            PhDbColumn::BIND_PARAM_STR,
            PhDbColumn::BIND_PARAM_INT,
        );

        $actual = $connection->insert($table, $params, null, $bind);
        $this->assertTrue($actual, 'Record was not inserted correctly');
    }

    /**
     * Test on bound parameters - insert with DefaultIdValue PK
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-11
     */
    public function testTypeBindInsertBindSkipDefaultIdValue()
    {
        $this->emptyTable('customers');

        $connection = $this->_di->get('db');

        $table  = 'customers';
        $params = array(
            $connection->getDefaultIdValue(),
            1,
            1,
            'John',
            'Doe',
            '555-444-6666',
            'john@doe.com',
            'Some instructions',
            'A',
            '1970-10-30',
            100.00,
            '2012-10-30 00:00:30',
            4
        );
        $bind   = array(
            PhDbColumn::BIND_SKIP,
            PhDbColumn::BIND_PARAM_INT,
            PhDbColumn::BIND_PARAM_INT,
            PhDbColumn::BIND_PARAM_STR,
            PhDbColumn::BIND_PARAM_STR,
            PhDbColumn::BIND_PARAM_STR,
            PhDbColumn::BIND_PARAM_STR,
            PhDbColumn::BIND_PARAM_STR,
            PhDbColumn::BIND_PARAM_STR,
            PhDbColumn::BIND_PARAM_STR,
            PhDbColumn::BIND_PARAM_INT,
            PhDbColumn::BIND_PARAM_STR,
            PhDbColumn::BIND_PARAM_INT,
        );

        $actual = $connection->insert($table, $params, null, $bind);
        $this->assertTrue($actual, 'Record was not inserted correctly');
    }

    /**
     * Test on bound parameters - insert with RawValue
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-11
     */
    public function testTypeBindInsertWithRawValue()
    {
        $this->emptyTable('customers');

        $connection = $this->_di->get('db');

        $date   = new PhDbRawValue('current_date');
        $table  = 'customers';
        $params = array(
            $connection->getDefaultIdValue(),
            1,
            1,
            'John',
            'Doe',
            '555-444-6666',
            'john@doe.com',
            'Some instructions',
            'A',
            '1970-10-30',
            100.00,
            $date,
            4
        );
        $bind   = array(
            PhDbColumn::BIND_SKIP,
            PhDbColumn::BIND_PARAM_INT,
            PhDbColumn::BIND_PARAM_INT,
            PhDbColumn::BIND_PARAM_STR,
            PhDbColumn::BIND_PARAM_STR,
            PhDbColumn::BIND_PARAM_STR,
            PhDbColumn::BIND_PARAM_STR,
            PhDbColumn::BIND_PARAM_STR,
            PhDbColumn::BIND_PARAM_STR,
            PhDbColumn::BIND_PARAM_STR,
            PhDbColumn::BIND_PARAM_INT,
            PhDbColumn::BIND_PARAM_STR,
            PhDbColumn::BIND_PARAM_INT,
        );

        $actual = $connection->insert($table, $params, null, $bind);
        $this->assertTrue($actual, 'Record was not inserted correctly');
    }

    /**
     * Test on bound parameters - update
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-11
     */
    public function testTypeBindUpdateOneField()
    {
        $this->emptyTable('customers');

        $connection = $this->_di->get('db');

        $actual = $this->_insertRecord();
        $this->assertTrue($actual, 'Record was not inserted correctly');

        $table  = 'customers';
        $fields = array('last_name');
        $params = array('Jane');
        $where  = "status = 'A'";
        $bind   = array(PhDbColumn::BIND_PARAM_STR);

        $actual = $connection->update($table, $fields, $params, $where, $bind);
        $this->assertTrue($actual, 'Record was not updated correctly');
    }

    /**
     * Test on bound parameters - update
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-11
     */
    public function testTypeBindUpdateTwoFields()
    {
        $this->emptyTable('customers');

        $connection = $this->_di->get('db');

        $actual = $this->_insertRecord();
        $this->assertTrue($actual, 'Record was not inserted correctly');

        $table  = 'customers';
        $fields = array('last_name', 'status');
        $params = array('Jane', 'X');
        $where  = "status = 'A'";
        $bind   = array(PhDbColumn::BIND_PARAM_STR, PhDbColumn::BIND_PARAM_STR);

        $actual = $connection->update($table, $fields, $params, $where, $bind);
        $this->assertTrue($actual, 'Record was not updated correctly');
    }

    /**
     * Test on bound parameters - update
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-11
     */
    public function testTypeBindUpdateRawValue()
    {
        $this->emptyTable('customers');

        $connection = $this->_di->get('db');

        $actual = $this->_insertRecord();
        $this->assertTrue($actual, 'Record was not inserted correctly');

        $date   = new PhDbRawValue('current_date');
        $table  = 'customers';
        $fields = array('created_at');
        $params = array($date);
        $where  = "status = 'A'";
        $bind   = array(PhDbColumn::BIND_PARAM_STR);

        $actual = $connection->update($table, $fields, $params, $where, $bind);
        $this->assertTrue($actual, 'Record was not updated correctly');
    }

    /**
     * Test on bound parameters - delete
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-11
     */
    public function testTypeBindDelete()
    {
        $this->emptyTable('customers');

        $connection = $this->_di->get('db');

        $actual = $this->_insertRecord();
        $this->assertTrue($actual, 'Record was not inserted correctly');

        $table  = 'customers';
        $where  = "status = 'A'";

        $actual = $connection->delete($table, $where);
        $this->assertTrue($actual, 'Record was not deleted correctly');
    }

    /**
     * Helper function to insert a record in the database
     */
    private function _insertRecord()
    {
        $connection = $this->_di->get('db');

        $sql    = "INSERT INTO customers ("
                . "id, document_id, customer_id, first_name, last_name, "
                . "phone, email, instructions, status, birth_date, "
                . "credit_line, created_at, created_at_user_id"
                . ") VALUES ("
                . $connection->getDefaultIdValue() . ","
                . "?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
        $params = array(
                    1,
                    1,
                    'John',
                    'Doe',
                    '555-444-6666',
                    'john@doe.com',
                    'Some instructions',
                    'A',
                    '1970-10-30',
                    100.00,
                    '2012-10-30 00:00:30',
                    4
                  );
        $bind   = array(
                    PhDbColumn::BIND_PARAM_INT,
                    PhDbColumn::BIND_PARAM_INT,
                    PhDbColumn::BIND_PARAM_STR,
                    PhDbColumn::BIND_PARAM_STR,
                    PhDbColumn::BIND_PARAM_STR,
                    PhDbColumn::BIND_PARAM_STR,
                    PhDbColumn::BIND_PARAM_STR,
                    PhDbColumn::BIND_PARAM_STR,
                    PhDbColumn::BIND_PARAM_STR,
                    PhDbColumn::BIND_PARAM_INT,
                    PhDbColumn::BIND_PARAM_STR,
                    PhDbColumn::BIND_PARAM_INT,
                  );
        $actual = $connection->execute($sql, $params, $bind);

        return $actual;
    }
}