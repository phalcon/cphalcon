<?php
/**
 * Model.php
 * Logger_Adapter_File_Helper_Model
 *
 * Tests the \Phalcon\Logger\Adapter\File component
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

use Phalcon\Events\Manager as EvMgr;

class Logger_Adapter_File_Helper_Model extends Phalcon_Test_ModelTestCase
{
    /**
     * Tests the creation of the log file
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-30
     */
    public function testDbLoggerDefault()
    {
        $this->populateTable('customers', 10);

        $fileName = $this->getFileName('log', 'log');
        $evman    = new EvMgr();
        $listener = new Logger_Adapter_File_Helper_Listener(PATH_LOGS . $fileName);

        $evman->attach('db', $listener);

        $connection = $this->_di->get('db');

        $connection->setEventsManager($evman);

        $connection->query("SELECT * FROM customers LIMIT 3");
        $connection->query("SELECT * FROM customers LIMIT 10");
        $connection->query("SELECT * FROM customers LIMIT 1");

        $this->assertTrue($connection->close());

        $listener->getLogger()->close();

        $lines = file(PATH_LOGS . $fileName);
        $this->assertEquals(count($lines), 3);

        $this->assertTrue(strpos($lines[0], '[DEBUG]')!==false);
        $this->assertTrue(strpos($lines[0], 'LIMIT 3')!==false);
        $this->assertTrue(strpos($lines[1], '[DEBUG]')!==false);
        $this->assertTrue(strpos($lines[1], 'LIMIT 10')!==false);
        $this->assertTrue(strpos($lines[2], '[DEBUG]')!==false);
        $this->assertTrue(strpos($lines[2], 'LIMIT 1')!==false);



        $this->cleanFile(PATH_LOGS, $fileName);

        //$this->assertTrue($actual, 'File was not correctly created');
    }
}