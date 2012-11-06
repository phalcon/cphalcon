<?php
/**
 * MysqlTest.php
 * Paginator_Adapter_NativeArray_UnitTest
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

class Paginator_Adapter_NativeArray_UnitTest extends Paginator_Adapter_Helper_Base
{
    public function setUp()
    {
        $fixture = $this->_setupFixture();

        $this->setClass('\Phalcon\Paginator\Adapter\NativeArray');
        $this->setFixture($fixture);
        $this->setParameters(1, 10);

        parent::setUp();
    }

    private function _setupFixture()
    {
        $data = array();
        for ($i = 1; $i < 2180; $i++)
        {
            $data[$i] = array('name' => 'PETER');
        }

        return $data;
    }
}
