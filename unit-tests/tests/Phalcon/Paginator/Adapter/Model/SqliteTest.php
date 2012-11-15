<?php
/**
 * SqliteTest.php
 * Paginator_Adapter_Model_SqliteTest
 *
 * Tests the \Phalcon\Paginator\Adapter\Model component
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

class Paginator_Adapter_Model_SqliteTest extends Paginator_Adapter_Helper_Base
{
    public function setUp()
    {
        parent::setUp();

        $this->populateTable('customers', 101);

        $fixture = Customers::find();

        $this->setClass('\Phalcon\Paginator\Adapter\Model');
        $this->setFixture($fixture);
        $this->setParameters(1, 5);

        $this->setDb('sqlite');
    }
}
