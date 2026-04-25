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

namespace Phalcon\Tests\Database\Db;

use Phalcon\Db\Column;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Database\Db\Fake\DialectTrait;

final class ColumnTest extends AbstractDatabaseTestCase
{
    use DialectTrait;

    /**
     * Tests Phalcon\Db\Column :: properties - works correctly as objects
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbColumnWorksAsObject(): void
    {
        $columns = $this->getColumns();

        // Varchar column
        $column1 = $columns['column1'];
        $this->assertEquals('column1', $column1->getName());
        $this->assertEquals(Column::TYPE_VARCHAR, $column1->getType());
        $this->assertEquals(10, $column1->getSize());
        $this->assertEquals(0, $column1->getScale());
        $this->assertFalse($column1->isUnsigned());
        $this->assertTrue($column1->isNotNull());

        // Integer column
        $column2 = $columns['column2'];
        $this->assertEquals('column2', $column2->getName());
        $this->assertEquals(Column::TYPE_INTEGER, $column2->getType());
        $this->assertEquals(18, $column2->getSize());
        $this->assertEquals(0, $column2->getScale());
        $this->assertTrue($column2->isUnsigned());
        $this->assertFalse($column2->isNotNull());

        // Decimal column
        $column3 = $columns['column3'];
        $this->assertEquals('column3', $column3->getName());
        $this->assertEquals(Column::TYPE_DECIMAL, $column3->getType());
        $this->assertEquals(10, $column3->getSize());
        $this->assertEquals(2, $column3->getScale());
        $this->assertFalse($column3->isUnsigned());
        $this->assertTrue($column3->isNotNull());

        // Char column
        $column4 = $columns['column4'];
        $this->assertEquals('column4', $column4->getName());
        $this->assertEquals(Column::TYPE_CHAR, $column4->getType());
        $this->assertEquals(100, $column4->getSize());
        $this->assertEquals(0, $column4->getScale());
        $this->assertFalse($column4->isUnsigned());
        $this->assertTrue($column4->isNotNull());

        // Date column
        $column5 = $columns['column5'];
        $this->assertEquals('column5', $column5->getName());
        $this->assertEquals(Column::TYPE_DATE, $column5->getType());
        $this->assertEquals(0, $column5->getSize());
        $this->assertEquals(0, $column5->getScale());
        $this->assertFalse($column5->isUnsigned());
        $this->assertTrue($column5->isNotNull());

        // Datetime column
        $column6 = $columns['column6'];
        $this->assertEquals('column6', $column6->getName());
        $this->assertEquals(Column::TYPE_DATETIME, $column6->getType());
        $this->assertEquals(0, $column6->getSize());
        $this->assertEquals(0, $column6->getScale());
        $this->assertFalse($column6->isUnsigned());
        $this->assertTrue($column6->isNotNull());

        // Text column
        $column7 = $columns['column7'];
        $this->assertEquals('column7', $column7->getName());
        $this->assertEquals(Column::TYPE_TEXT, $column7->getType());
        $this->assertEquals(0, $column7->getSize());
        $this->assertEquals(0, $column7->getScale());
        $this->assertFalse($column7->isUnsigned());
        $this->assertTrue($column7->isNotNull());

        // Float column
        $column8 = $columns['column8'];
        $this->assertEquals('column8', $column8->getName());
        $this->assertEquals(Column::TYPE_FLOAT, $column8->getType());
        $this->assertEquals(10, $column8->getSize());
        $this->assertEquals(2, $column8->getScale());
        $this->assertFalse($column8->isUnsigned());
        $this->assertTrue($column8->isNotNull());

        // Varchar column + default value
        $column9 = $columns['column9'];
        $this->assertEquals('column9', $column9->getName());
        $this->assertEquals(Column::TYPE_VARCHAR, $column9->getType());
        $this->assertEquals(10, $column9->getSize());
        $this->assertEquals(0, $column9->getScale());
        $this->assertFalse($column9->isUnsigned());
        $this->assertTrue($column9->isNotNull());
        $this->assertEquals('column9', $column9->getDefault());

        // Integer column + default value
        $column10 = $columns['column10'];
        $this->assertEquals('column10', $column10->getName());
        $this->assertEquals(Column::TYPE_INTEGER, $column10->getType());
        $this->assertEquals(18, $column10->getSize());
        $this->assertEquals(0, $column10->getScale());
        $this->assertTrue($column10->isUnsigned());
        $this->assertFalse($column10->isNotNull());
        $this->assertEquals('10', $column10->getDefault());

        // Bigint column
        $column11 = $columns['column11'];
        $this->assertEquals('column11', $column11->getName());
        $this->assertEquals('BIGINT', $column11->getType());
        $this->assertEquals(Column::TYPE_INTEGER, $column11->getTypeReference());
        $this->assertEquals(20, $column11->getSize());
        $this->assertEquals(0, $column11->getScale());
        $this->assertTrue($column11->isUnsigned());
        $this->assertFalse($column11->isNotNull());

        // Enum column
        $column12 = $columns['column12'];
        $this->assertEquals('column12', $column12->getName());
        $this->assertEquals('ENUM', $column12->getType());
        $this->assertEquals(-1, $column12->getTypeReference());
        $this->assertEquals(['A', 'B', 'C'], $column12->getTypeValues());
        $this->assertEquals(0, $column12->getSize());
        $this->assertEquals(0, $column12->getScale());
        $this->assertFalse($column12->isUnsigned());
        $this->assertTrue($column12->isNotNull());

        // Timestamp column
        $column13 = $columns['column13'];
        $this->assertEquals('column13', $column13->getName());
        $this->assertEquals(Column::TYPE_TIMESTAMP, $column13->getType());
        $this->assertTrue($column13->isNotNull());
        $this->assertEquals('CURRENT_TIMESTAMP', $column13->getDefault());

        // Tinyblob column
        $column14 = $columns['column14'];
        $this->assertEquals('column14', $column14->getName());
        $this->assertEquals(Column::TYPE_TINYBLOB, $column14->getType());
        $this->assertTrue($column14->isNotNull());

        // Mediumblob column
        $column15 = $columns['column15'];
        $this->assertEquals('column15', $column15->getName());
        $this->assertEquals(Column::TYPE_MEDIUMBLOB, $column15->getType());
        $this->assertTrue($column15->isNotNull());

        // Blob column
        $column16 = $columns['column16'];
        $this->assertEquals('column16', $column16->getName());
        $this->assertEquals(Column::TYPE_BLOB, $column16->getType());
        $this->assertTrue($column16->isNotNull());

        // Longblob column
        $column17 = $columns['column17'];
        $this->assertEquals('column17', $column17->getName());
        $this->assertEquals(Column::TYPE_LONGBLOB, $column17->getType());
        $this->assertTrue($column17->isNotNull());

        // Boolean column
        $column18 = $columns['column18'];
        $this->assertEquals('column18', $column18->getName());
        $this->assertEquals(Column::TYPE_BOOLEAN, $column18->getType());

        // Double column
        $column19 = $columns['column19'];
        $this->assertEquals('column19', $column19->getName());
        $this->assertEquals(Column::TYPE_DOUBLE, $column19->getType());
        $this->assertFalse($column19->isUnsigned());

        // Unsigned double column
        $column20 = $columns['column20'];
        $this->assertEquals('column20', $column20->getName());
        $this->assertEquals(Column::TYPE_DOUBLE, $column20->getType());
        $this->assertTrue($column20->isUnsigned());
    }
}
