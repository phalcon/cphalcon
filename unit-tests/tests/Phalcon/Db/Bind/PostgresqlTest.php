<?php
/**
 * PostgresqlTest.php
 * \Phalcon\Db\Bind\PostgresqlTests
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

use \Phalcon\Db\RawValue as PhDbRawValue;

class Db_Bind_PostgresqlTest extends Db_Helper_Bind
{
    public function setUp()
    {
        parent::setUp();

        parent::setDb('postgresql');

        $this->_nullDefault = new PhDbRawValue('default');
    }

    public function testRawBindTestThreeOnThreeWithKeysEscapedMixed()
    {
        $connection = $this->_di->get('db');

        $expected = "column3 IN ('hello', 100, '''hahaha''')";
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

        $expected = "column3 IN ('hello', 100, '''hahaha''') AND column4 > 'le-nice'";
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
}
