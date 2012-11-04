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
	public function testExecute()
	{
        $connection = $this->_di->get('db');

		$result = $connection->query("SELECT * FROM personas LIMIT 3");
		$this->assertTrue(is_object($result));
		$this->assertEquals(get_class($result), 'Phalcon\Db\Result\Pdo');

		for ($i=0; $i<3; $i++) {
			$row = $result->fetchArray();
			$this->assertEquals(count($row), 22);
		}

		$row = $result->fetchArray();
		$this->assertEquals($row, false);
		$this->assertEquals($result->numRows(), 3);

		$number = 0;
		$result = $connection->query("SELECT * FROM personas LIMIT 5");
		$this->assertTrue(is_object($result));

		while ($row = $result->fetchArray()) {
			$number++;
		}
		$this->assertEquals($number, 5);

		$result = $connection->query("SELECT * FROM personas LIMIT 5");
		$result->setFetchMode(Phalcon\Db::FETCH_NUM);
		$row = $result->fetchArray();
		$this->assertEquals(count($row), 11);

		$result = $connection->query("SELECT * FROM personas LIMIT 5");
		$result->setFetchMode(Phalcon\Db::FETCH_ASSOC);
		$row = $result->fetchArray();
		$this->assertEquals(count($row), 11);

		$result = $connection->query("SELECT * FROM personas LIMIT 5");
		$result->setFetchMode(Phalcon\Db::FETCH_BOTH);
		$result->dataSeek(4);
		$row = $result->fetchArray();
		$row = $result->fetchArray();
		$this->assertEquals($row, false);

		$result = $connection->execute("DELETE FROM prueba");
		$this->assertTrue($result);

		$success = $connection->execute('INSERT INTO prueba(id, nombre, estado) VALUES ('.$connection->getDefaultIdValue().', ?, ?)', array("LOL 1", "A"));
		$this->assertTrue($success);

		$success = $connection->execute('UPDATE prueba SET nombre = ?, estado = ?', array("LOL 11", "R"));
		$this->assertTrue($success);

		$success = $connection->execute('DELETE FROM prueba WHERE estado = ?', array("R"));
		$this->assertTrue($success);

		$success = $connection->insert('prueba', array($connection->getDefaultIdValue(), "LOL 1", "A"));
		$this->assertTrue($success);

		$success = $connection->insert('prueba', array("LOL 2", "E"), array('nombre', 'estado'));
		$this->assertTrue($success);

		$success = $connection->insert('prueba', array("LOL 3", "I"), array('nombre', 'estado'));
		$this->assertTrue($success);

		$success = $connection->insert('prueba', array(new Phalcon\Db\RawValue('current_date'), "A"), array('nombre', 'estado'));
		$this->assertTrue($success);

		for ($i=0; $i<50; $i++) {
			$success = $connection->insert('prueba', array("LOL ".$i, "F"), array('nombre', 'estado'));
			$this->assertTrue($success);
		}

		$success = $connection->update('prueba', array("nombre", "estado"), array("LOL 1000", "X"), "estado='E'");
		$this->assertTrue($success);

		$success = $connection->update('prueba', array("nombre"), array("LOL 3000"), "estado='X'");
		$this->assertTrue($success);

		$success = $connection->update('prueba', array("nombre"), array(new Phalcon\Db\RawValue('current_date')), "estado='X'");
		$this->assertTrue($success);

		$connection->delete("prueba", "estado='X'");
		$this->assertTrue($success);

		$connection->delete("prueba");
		$this->assertTrue($success);
		$this->assertEquals($connection->affectedRows(), 53);

		$row = $connection->fetchOne("SELECT * FROM personas");
		$this->assertEquals(count($row), 22);

		$row = $connection->fetchOne("SELECT * FROM personas", Phalcon\Db::FETCH_NUM);
		$this->assertEquals(count($row), 11);

		$rows = $connection->fetchAll("SELECT * FROM personas LIMIT 10");
		$this->assertEquals(count($rows), 10);

		$rows = $connection->fetchAll("SELECT * FROM personas LIMIT 10", Phalcon\Db::FETCH_NUM);
		$this->assertEquals(count($rows), 10);
		$this->assertEquals(count($rows[0]), 11);

		//Auto-Increment/Serial Columns
		$sql = 'INSERT INTO subscriptores(id, email, created_at, status) VALUES ('.$connection->getDefaultIdValue().', ?, ?, ?)';
		$success = $connection->execute($sql, array('shirley@garbage.com', "2011-01-01 12:59:13", "P"));
		$this->assertTrue($success);

		//Check for auto-increment column
		$this->assertTrue($connection->lastInsertId('subscriptores_id_seq') > 0);

	}

}
