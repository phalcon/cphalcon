<?php
/**
 * MysqlTest.php
 * Phalcon_Db_Model_Validators_MysqlTest
 *
 * Tests the \Phalcon\Db Model Validators component
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

class Db_Model_Validators_MysqlTest extends Db_Helper_Model_Validators
{
    public function setUp()
    {
        parent::setUp();

        $this->setDb('mysql');
    }
}
