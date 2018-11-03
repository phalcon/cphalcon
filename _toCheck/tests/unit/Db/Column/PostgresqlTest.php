<?php

namespace Phalcon\Test\Unit\Db\Column;

use Phalcon\Db\Column;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Db\Column\PostgresqlTest
 * Tests the \Phalcon\Db\Column component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit\Db\Column
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class PostgresqlTest extends UnitTest
{
    /**
     * Tests Postgresql::hasDefault for autoincrement fields
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/853
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-09-28
     */
    public function testHasAutoIncrementDefault()
    {
        $this->specify(
            'The autoincrement column has default value',
            function () {
                $column = Column::__set_state([
                    '_columnName'    => 'id',
                    '_schemaName'    => null,
                    '_type'          => 14,
                    '_typeReference' => -1,
                    '_typeValues'    => null,
                    '_isNumeric'     => true,
                    '_size'          => 0,
                    '_scale'         => 0,
                    '_default'       => "nextval('images_id_seq'::regclass)",
                    '_unsigned'      => false,
                    '_notNull'       => true,
                    '_primary'       => false,
                    '_autoIncrement' => true,
                    '_first'         => true,
                    '_after'         => null,
                    '_bindType'      => 1,
                ]);

                expect($column->hasDefault())->false();
                expect($column->isAutoIncrement())->true();
            }
        );
    }
}
