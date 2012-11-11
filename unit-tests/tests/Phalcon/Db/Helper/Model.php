<?php
/**
 * Model.php
 * Db_Helper_Model
 *
 * Tests the \Phalcon\Db component
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2012 Phalcon Team
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

class Db_Helper_Model extends Phalcon_Test_ModelTestCase
{
    /**
     * Tests if query returns an object back
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2011-11-11
     */
    public function testQueryObject()
    {
        $this->populateTable('customers', 1);

        $connection = $this->_di->get('db');

        $sql = "SELECT * FROM customers";

        $result = $connection->query($sql);
        $this->assertTrue(is_object($result));
        $this->assertEquals(get_class($result), 'Phalcon\Db\Result\Pdo');
    }

	public function testExecute()
	{
        $this->markTestSkipped('needs work');
        $this->populateTable('customers', 100);

        $connection = $this->_di->get('db');

		$result = $connection->query("SELECT * FROM customers LIMIT 3");
		$this->assertTrue(is_object($result));
		$this->assertEquals(get_class($result), 'Phalcon\Db\Result\Pdo');

		for ($i=0; $i<3; $i++) {
			$row = $result->fetchArray();
			$this->assertEquals(count($row), 26);
		}

		$row = $result->fetchArray();
		$this->assertEquals($row, false);
		$this->assertEquals($result->numRows(), 3);

		$number = 0;
		$result = $connection->query("SELECT * FROM customers LIMIT 5");
		$this->assertTrue(is_object($result));

		while ($row = $result->fetchArray()) {
			$number++;
		}
		$this->assertEquals($number, 5);

		$result = $connection->query("SELECT * FROM customers LIMIT 5");
		$result->setFetchMode(Phalcon\Db::FETCH_NUM);
		$row = $result->fetchArray();
		$this->assertEquals(count($row), 13);

		$result = $connection->query("SELECT * FROM customers LIMIT 5");
		$result->setFetchMode(Phalcon\Db::FETCH_ASSOC);
		$row = $result->fetchArray();
		$this->assertEquals(count($row), 13);

		$result = $connection->query("SELECT * FROM customers LIMIT 5");
		$result->setFetchMode(Phalcon\Db::FETCH_BOTH);
		$result->dataSeek(4);
		$row = $result->fetchArray();
		$row = $result->fetchArray();
		$this->assertEquals($row, false);

		$result = $connection->execute("DELETE FROM prueba");
		$this->assertTrue($result);

		for ($i=0; $i<50; $i++) {
			$success = $connection->insert('prueba', array("LOL ".$i, "F"), array('nombre', 'estado'));
			$this->assertTrue($success);
		}

		$row = $connection->fetchOne("SELECT * FROM personas");
		$this->assertEquals(count($row), 22);

		$row = $connection->fetchOne("SELECT * FROM personas", Phalcon\Db::FETCH_NUM);
		$this->assertEquals(count($row), 11);

		$rows = $connection->fetchAll("SELECT * FROM personas LIMIT 10");
		$this->assertEquals(count($rows), 10);

		$rows = $connection->fetchAll("SELECT * FROM personas LIMIT 10", Phalcon\Db::FETCH_NUM);
		$this->assertEquals(count($rows), 10);
		$this->assertEquals(count($rows[0]), 11);

		//Check for auto-increment column
		$this->assertTrue($connection->lastInsertId('subscriptores_id_seq') > 0);

	}

}
