<?php
/**
 * MysqlTest.php
 * \Phalcon\Db\Bind\MysqlTests
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

require_once 'Helper.php';

class Db_Bind_MysqlTest extends Db_Bind_Helper
{
    public function setUp()
    {
        parent::setUp();

        parent::setDb('mysql');
    }

    public function testRawBindTestThreeOnThreeWithKeysEscapedMixed()
    {
        $connection = $this->_di->get('db');

        $expected = "column3 IN ('hello', 100, '\'hahaha\'')";
        $actual   = $connection->bindParams(
            "column3 IN (:val1:, :val2:, :val3:)",
            array(
                'val1' => 'hello',
                'val2' => 100,
                'val3' => "'hahaha'"
            )
        );

        $this->assertEquals(
            $expected,
            $actual,
            'Binding not correct ' . $expected
        );
    }

    public function testRawBindTestThreeOnThreeWithMixedKeysEscapedMixed()
    {
        $connection = $this->_di->get('db');

        $expected = "column3 IN ('hello', 100, '\'hahaha\'') AND column4 > 'le-nice'";
        $actual   = $connection->bindParams(
            "column3 IN (:val1:, :val2:, :val3:) AND column4 > ?2",
            array(
                'val1' => 'hello',
                'val2' => 100,
                'val3' => "'hahaha'",
                2      => 'le-nice',
            )
        );

        $this->assertEquals(
            $expected,
            $actual,
            'Binding not correct ' . $expected
        );
    }

    public function testConvertBindTests()
    {
        $connection = $this->_di->get('db');

        $params = $connection->convertBoundParams("a=?0", array(0 => 100));
        $this->assertEquals($params, array('sql' => 'a=?', 'params' => array(0 => 100)));

        $params = $connection->convertBoundParams("a=?0", array(0 => 100, 1 => 50));
        $this->assertEquals($params, array('sql' => 'a=?', 'params' => array(0 => 100)));

        $params = $connection->convertBoundParams("a=?1 AND b = ?0", array(1 => 50, 0 => 25));
        $this->assertEquals($params, array('sql' => "a=? AND b = ?", 'params' => array(0 => 50, 1 => 25)));

        $params = $connection->convertBoundParams("a=?1 AND b = ?0", array(1 => 25.10, 0 => '25.10'));
        $this->assertEquals($params, array('sql' => "a=? AND b = ?", 'params' => array(0 => '25.10', 1 => 25.10)));

        $params = $connection->convertBoundParams("a=?1 AND b = ?0 AND c > :c: AND d = ?3", array('c' => 1000, 1 => 'some-name', 0 => 15, 3 => 400));
        $this->assertEquals($params, array('sql' => "a=? AND b = ? AND c > ? AND d = ?", 'params' => array(0 => 'some-name', 1 => 15, 2 => 1000, 3 => 400)));
    }

}
