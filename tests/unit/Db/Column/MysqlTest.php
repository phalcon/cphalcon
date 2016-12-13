<?php

namespace Phalcon\Test\Unit\Db\Column;

use Phalcon\Db\Column;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Db\Dialect\Mysql as MysqlDialect;

/**
 * \Phalcon\Test\Unit\Db\Column\MyslTest
 * Tests the \Phalcon\Db\Column component
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      https://www.phalconphp.com
 * @package   Phalcon\Test\Unit\Db\Column
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class MysqlTest extends UnitTest
{
    public function testDetectTimeColumn()
    {
        $dialect = new MysqlDialect();
        $column = new Column("time-test", array(
            'type' => Column::TYPE_TIME
        ));
        $this->assertEquals($dialect->getColumnDefinition($column), 'TIME');
    }
}
