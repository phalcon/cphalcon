<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Database\Db\Column;

use DatabaseTester;
use Phalcon\Db\Column;
use Phalcon\Db\ColumnInterface;

class ConstructCest
{
    /**
     * Tests Phalcon\Db\Column :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group  common
     */
    public function dbColumnConstruct(DatabaseTester $I)
    {
        $I->wantToTest('Db\Column - __construct()');

        $options = [
            'type'          => Column::TYPE_INTEGER,
            'isNumeric'     => true,
            'size'          => 11,
            'scale'         => 0,
            'default'       => null,
            'unsigned'      => false,
            'notNull'       => true,
            'autoIncrement' => true,
            'primary'       => true,
            'first'         => true,
            'after'         => null,
            'bindType'      => Column::BIND_PARAM_INT,
        ];

        $column = new Column('field_primary', $options);
        $I->assertInstanceOf(Column::class, $column);
        $I->assertInstanceOf(ColumnInterface::class, $column);
    }
}
