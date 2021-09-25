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

namespace Phalcon\Tests\Integration\Db;

use IntegrationTester;
use Phalcon\Db\Column;
use Phalcon\Tests\Fixtures\Traits\DialectTrait;

class ColumnCest
{
    use DialectTrait;

    public function shouldWorkPerfectlyWithColumnAsObject(IntegrationTester $I)
    {
        $columns = $this->getColumns();


        //Varchar column
        $column1 = $columns['column1'];

        $I->assertEquals(
            'column1',
            $column1->getName()
        );

        $I->assertEquals(
            Column::TYPE_VARCHAR,
            $column1->getType()
        );

        $I->assertEquals(
            10,
            $column1->getSize()
        );

        $I->assertEquals(
            0,
            $column1->getScale()
        );

        $I->assertFalse(
            $column1->isUnsigned()
        );

        $I->assertFalse(
            $column1->isNotNull()
        );


        //Integer column
        $column2 = $columns['column2'];

        $I->assertEquals(
            'column2',
            $column2->getName()
        );

        $I->assertEquals(
            Column::TYPE_INTEGER,
            $column2->getType()
        );

        $I->assertEquals(
            18,
            $column2->getSize()
        );

        $I->assertEquals(
            0,
            $column2->getScale()
        );

        $I->assertTrue(
            $column2->isUnsigned()
        );

        $I->assertFalse(
            $column2->isNotNull()
        );


        // Decimal column
        $column3 = $columns['column3'];

        $I->assertEquals(
            'column3',
            $column3->getName()
        );

        $I->assertEquals(
            Column::TYPE_DECIMAL,
            $column3->getType()
        );

        $I->assertEquals(
            10,
            $column3->getSize()
        );

        $I->assertEquals(
            2,
            $column3->getScale()
        );

        $I->assertFalse(
            $column3->isUnsigned()
        );

        $I->assertTrue(
            $column3->isNotNull()
        );


        // Char column
        $column4 = $columns['column4'];

        $I->assertEquals(
            'column4',
            $column4->getName()
        );

        $I->assertEquals(
            Column::TYPE_CHAR,
            $column4->getType()
        );

        $I->assertEquals(
            100,
            $column4->getSize()
        );

        $I->assertEquals(
            0,
            $column4->getScale()
        );

        $I->assertFalse(
            $column4->isUnsigned()
        );

        $I->assertTrue(
            $column4->isNotNull()
        );


        // Date column
        $column5 = $columns['column5'];

        $I->assertEquals(
            'column5',
            $column5->getName()
        );

        $I->assertEquals(
            Column::TYPE_DATE,
            $column5->getType()
        );

        $I->assertEquals(
            0,
            $column5->getSize()
        );

        $I->assertEquals(
            0,
            $column5->getScale()
        );

        $I->assertFalse(
            $column5->isUnsigned()
        );

        $I->assertTrue(
            $column5->isNotNull()
        );


        // Datetime column
        $column6 = $columns['column6'];

        $I->assertEquals(
            'column6',
            $column6->getName()
        );

        $I->assertEquals(
            Column::TYPE_DATETIME,
            $column6->getType()
        );

        $I->assertEquals(
            0,
            $column6->getSize()
        );

        $I->assertEquals(
            0,
            $column6->getScale()
        );

        $I->assertFalse(
            $column6->isUnsigned()
        );

        $I->assertTrue(
            $column6->isNotNull()
        );


        //Text column
        $column7 = $columns['column7'];

        $I->assertEquals(
            'column7',
            $column7->getName()
        );

        $I->assertEquals(
            Column::TYPE_TEXT,
            $column7->getType()
        );

        $I->assertEquals(
            0,
            $column7->getSize()
        );

        $I->assertEquals(
            0,
            $column7->getScale()
        );

        $I->assertFalse(
            $column7->isUnsigned()
        );

        $I->assertTrue(
            $column7->isNotNull()
        );


        //Float column
        $column8 = $columns['column8'];

        $I->assertEquals(
            'column8',
            $column8->getName()
        );

        $I->assertEquals(
            Column::TYPE_FLOAT,
            $column8->getType()
        );

        $I->assertEquals(
            10,
            $column8->getSize()
        );

        $I->assertEquals(
            2,
            $column8->getScale()
        );

        $I->assertFalse(
            $column8->isUnsigned()
        );

        $I->assertTrue(
            $column8->isNotNull()
        );


        //Varchar column + default value
        $column9 = $columns['column9'];

        $I->assertEquals(
            'column9',
            $column9->getName()
        );

        $I->assertEquals(
            Column::TYPE_VARCHAR,
            $column9->getType()
        );

        $I->assertEquals(
            10,
            $column9->getSize()
        );

        $I->assertEquals(
            0,
            $column9->getScale()
        );

        $I->assertFalse(
            $column9->isUnsigned()
        );

        $I->assertFalse(
            $column9->isNotNull()
        );

        $I->assertEquals(
            'column9',
            $column9->getDefault()
        );


        //Integer column + default value
        $column10 = $columns['column10'];

        $I->assertEquals(
            'column10',
            $column10->getName()
        );

        $I->assertEquals(
            Column::TYPE_INTEGER,
            $column10->getType()
        );

        $I->assertEquals(
            18,
            $column10->getSize()
        );

        $I->assertEquals(
            0,
            $column10->getScale()
        );

        $I->assertTrue(
            $column10->isUnsigned()
        );

        $I->assertFalse(
            $column10->isNotNull()
        );

        $I->assertEquals(
            '10',
            $column10->getDefault()
        );


        //Bigint column
        $column11 = $columns['column11'];

        $I->assertEquals(
            'column11',
            $column11->getName()
        );

        $I->assertEquals(
            'BIGINT',
            $column11->getType()
        );

        $I->assertEquals(
            Column::TYPE_INTEGER,
            $column11->getTypeReference()
        );

        $I->assertEquals(
            20,
            $column11->getSize()
        );

        $I->assertEquals(
            0,
            $column11->getScale()
        );

        $I->assertTrue(
            $column11->isUnsigned()
        );

        $I->assertFalse(
            $column11->isNotNull()
        );


        // Enum column
        $column12 = $columns['column12'];

        $I->assertEquals(
            'column12',
            $column12->getName()
        );

        $I->assertEquals(
            'ENUM',
            $column12->getType()
        );

        $I->assertEquals(
            -1,
            $column12->getTypeReference()
        );

        $I->assertEquals(
            ['A', 'B', 'C'],
            $column12->getTypeValues()
        );

        $I->assertEquals(
            0,
            $column12->getSize()
        );

        $I->assertEquals(
            0,
            $column12->getScale()
        );

        $I->assertFalse(
            $column12->isUnsigned()
        );

        $I->assertTrue(
            $column12->isNotNull()
        );


        // Timestamp column
        $column13 = $columns['column13'];

        $I->assertEquals(
            'column13',
            $column13->getName()
        );

        $I->assertEquals(
            Column::TYPE_TIMESTAMP,
            $column13->getType()
        );

        $I->assertTrue(
            $column13->isNotNull()
        );

        $I->assertEquals(
            'CURRENT_TIMESTAMP',
            $column13->getDefault()
        );


        // Tinyblob column
        $column14 = $columns['column14'];

        $I->assertEquals(
            'column14',
            $column14->getName()
        );

        $I->assertEquals(
            Column::TYPE_TINYBLOB,
            $column14->getType()
        );

        $I->assertTrue(
            $column14->isNotNull()
        );


        // Mediumblob column
        $column15 = $columns['column15'];

        $I->assertEquals(
            'column15',
            $column15->getName()
        );

        $I->assertEquals(
            Column::TYPE_MEDIUMBLOB,
            $column15->getType()
        );

        $I->assertTrue(
            $column15->isNotNull()
        );


        // Blob column
        $column16 = $columns['column16'];

        $I->assertEquals(
            'column16',
            $column16->getName()
        );

        $I->assertEquals(
            Column::TYPE_BLOB,
            $column16->getType()
        );

        $I->assertTrue(
            $column16->isNotNull()
        );


        // Longblob column
        $column17 = $columns['column17'];

        $I->assertEquals(
            'column17',
            $column17->getName()
        );

        $I->assertEquals(
            Column::TYPE_LONGBLOB,
            $column17->getType()
        );

        $I->assertTrue(
            $column17->isNotNull()
        );


        // Boolean column
        $column18 = $columns['column18'];

        $I->assertEquals(
            'column18',
            $column18->getName()
        );

        $I->assertEquals(
            Column::TYPE_BOOLEAN,
            $column18->getType()
        );


        // Double column
        $column19 = $columns['column19'];

        $I->assertEquals(
            'column19',
            $column19->getName()
        );

        $I->assertEquals(
            Column::TYPE_DOUBLE,
            $column19->getType()
        );

        $I->assertFalse(
            $column19->isUnsigned()
        );


        // Unsigned double column
        $column20 = $columns['column20'];

        $I->assertEquals(
            'column20',
            $column20->getName()
        );

        $I->assertEquals(
            Column::TYPE_DOUBLE,
            $column20->getType()
        );

        $I->assertTrue(
            $column20->isUnsigned()
        );
    }
}
