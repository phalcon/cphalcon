<?php
/**
 * SqliteTest.php
 * Logger_Adapter_File_SqliteTest
 *
 * Tests the \Phalcon\Logger\Adapter\File component
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

class Logger_Adapter_File_SqliteTest extends Logger_Adapter_File_Helper_Model
{
    public function setUp()
    {
        $this->markTestSkipped('Sqlite schema to be completed');
        parent::setUp();

        $this->setDb('sqlite');

    }
}