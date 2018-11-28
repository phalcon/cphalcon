<?php

/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file LICENSE.txt.                             |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  |          Rack Lin <racklin@gmail.com>                                  |
  +------------------------------------------------------------------------+
*/

use PHPUnit\Framework\TestCase;

class DbTest extends TestCase
{
    /**
     * @medium
     */
    public function testDbPostgresqlSchemas()
    {
        require 'unit-tests/config.db.php';
        if (empty($configPostgresql)) {
            $this->markTestSkipped("Skipped");
            return;
        }

        $configPostgresqlDefault = array_merge([], $configPostgresql);
        unset($configPostgresqlDefault['schema']);

        $configPostgresqlNonExists           = array_merge([], $configPostgresql);
        $configPostgresqlNonExists['schema'] = 'nonexists';

        try {
            $connection = new Phalcon\Db\Adapter\Pdo\Postgresql($configPostgresql);
            $this->assertInternalType('object', $connection);
        } catch (Exception $e) {
            $this->assertTrue(false);
        }

        try {
            $connection = new Phalcon\Db\Adapter\Pdo\Postgresql($configPostgresqlDefault);
            $this->assertInternalType('object', $connection);
        } catch (Exception $e) {
            $this->assertTrue(false);
        }

        try {
            $connection = new Phalcon\Db\Adapter\Pdo\Postgresql($configPostgresqlNonExists);
            $this->assertNotInternalType('object', $connection);
        } catch (Exception $e) {
            $this->assertTrue(true);
        }

    }

    /**
     * @medium
     */
    public function testDbSqlite()
    {
        require 'unit-tests/config.db.php';

        if (!empty($configSqlite)) {
            $connection = new Phalcon\Db\Adapter\Pdo\Sqlite($configSqlite);
            $this->_executeTests($connection);
        } else {
            $this->markTestSkipped("Skipped");
        }
    }
}
