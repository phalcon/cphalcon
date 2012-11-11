<?php
/**
 * PostgresqlTest.php
 * Phalcon_Db_PostgresqlTest
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

class Db_PostgresqlTest extends Db_Helper_Model
{
    public function setUp()
    {
        $this->markTestSkipped('Postgres schema to be completed');
        parent::setUp();

        $this->setDb('postgresql');
    }

	public function testDbPostgresqlSchemas()
	{
        $this->markTestSkipped('Postgres schema to be completed');
        $config           = $this->_config;
        $configPostgresql = $config['db']['postgresql'];

		$configPostgresqlDefault = array_merge(array(), $configPostgresql);
		unset($configPostgresqlDefault['schema']);

		$configPostgresqlNonExists = array_merge(array(), $configPostgresql);
		$configPostgresqlNonExists['schema'] = 'nonexists';

		try {
			$connection = new Phalcon\Db\Adapter\Pdo\Postgresql($configPostgresql);
			$this->assertTrue(is_object($connection));
		} catch(Exception $e) {
			$this->assertTrue(false);
		}

		try {
			$connection = new Phalcon\Db\Adapter\Pdo\Postgresql($configPostgresqlDefault);
			$this->assertTrue(is_object($connection));
		} catch(Exception $e) {
			$this->assertTrue(false);
		}

		try {
			$connection = new Phalcon\Db\Adapter\Pdo\Postgresql($configPostgresqlNonExists);
			$this->assertFalse(is_object($connection));
		} catch(Exception $e) {
			$this->assertTrue(true);
		}

	}
}
