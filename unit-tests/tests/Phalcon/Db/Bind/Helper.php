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

use Phalcon\Db\Column as DbColumn;

class Db_Bind_Helper extends Phalcon_Test_ModelTestCase
{
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

   	public function testBindByTypeTests()
   	{
        $connection = $this->_di->get('db');

		$success = $connection->execute(
			'INSERT INTO prueba(id, nombre, estado) VALUES ('.$connection->getDefaultIdValue().', ?, ?)',
			array("LOL 1", "A"),
			array(DbColumn::BIND_PARAM_STR, DbColumn::BIND_PARAM_STR)
		);
		$this->assertTrue($success);

		$success = $connection->execute(
			'UPDATE prueba SET nombre = ?, estado = ?',
			array("LOL 11", "R"),
			array(DbColumn::BIND_PARAM_STR, DbColumn::BIND_PARAM_STR)
		);
		$this->assertTrue($success);

		$success = $connection->execute(
			'DELETE FROM prueba WHERE estado = ?',
			array("R"),
			array(DbColumn::BIND_PARAM_STR)
		);
		$this->assertTrue($success);

		$success = $connection->insert(
			'prueba',
			array($connection->getDefaultIdValue(), "LOL 1", "A"),
			null,
			array(DbColumn::BIND_SKIP, DbColumn::BIND_PARAM_STR, DbColumn::BIND_PARAM_STR)
		);
		$this->assertTrue($success);

		$success = $connection->insert(
			'prueba',
			array("LOL 2", "E"),
			array('nombre', 'estado'),
			array(DbColumn::BIND_PARAM_STR, DbColumn::BIND_PARAM_STR)
		);
		$this->assertTrue($success);

		$success = $connection->insert(
			'prueba',
			array("LOL 3", "I"),
			array('nombre', 'estado'),
			array(DbColumn::BIND_PARAM_STR, DbColumn::BIND_PARAM_STR)
		);
		$this->assertTrue($success);

		$success = $connection->insert(
			'prueba',
			array(new Phalcon\Db\RawValue('current_date'), "A"),
			array('nombre', 'estado'),
			array(DbColumn::BIND_PARAM_STR, DbColumn::BIND_PARAM_STR)
		);
		$this->assertTrue($success);

		$success = $connection->update(
			'prueba',
			array("nombre", "estado"),
			array("LOL 1000", "X"),
			"estado='E'",
			array(DbColumn::BIND_PARAM_STR, DbColumn::BIND_PARAM_STR)
		);
		$this->assertTrue($success);

		$success = $connection->update(
			'prueba',
			array("nombre"), array("LOL 3000"),
			"estado='X'",
			array(DbColumn::BIND_PARAM_STR)
		);
		$this->assertTrue($success);

		$success = $connection->update(
			'prueba',
			array("nombre"), array(new Phalcon\Db\RawValue('current_date')),
			"estado='X'",
			array(DbColumn::BIND_PARAM_STR)
		);
		$this->assertTrue($success);

   	}

}
