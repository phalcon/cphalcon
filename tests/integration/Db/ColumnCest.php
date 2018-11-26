<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Db;

use IntegrationTester;
use Phalcon\Db\Column;
use Phalcon\Test\Fixtures\Traits\DialectTrait;

class ColumnCest
{
    use DialectTrait;

    public function shouldWorkPerfectlyWithColumnAsObject(IntegrationTester $I)
    {
        $columns = $this->getColumns();

        //Varchar column
        $column1 = $columns['column1'];

        $I->assertEquals($column1->getName(), 'column1');
        $I->assertEquals($column1->getType(), Column::TYPE_VARCHAR);
        $I->assertEquals($column1->getSize(), 10);
        $I->assertEquals($column1->getScale(), 0);
        $I->assertFalse($column1->isUnsigned());
        $I->assertFalse($column1->isNotNull());

        //Integer column
        $column2 = $columns['column2'];

        $I->assertEquals($column2->getName(), 'column2');
        $I->assertEquals($column2->getType(), Column::TYPE_INTEGER);
        $I->assertEquals($column2->getSize(), 18);
        $I->assertEquals($column2->getScale(), 0);
        $I->assertTrue($column2->isUnsigned());
        $I->assertFalse($column2->isNotNull());

        //Decimal column
        $column3 = $columns['column3'];

        $I->assertEquals($column3->getName(), 'column3');
        $I->assertEquals($column3->getType(), Column::TYPE_DECIMAL);
        $I->assertEquals($column3->getSize(), 10);
        $I->assertEquals($column3->getScale(), 2);
        $I->assertFalse($column3->isUnsigned());
        $I->assertTrue($column3->isNotNull());

        //Char column
        $column4 = $columns['column4'];

        $I->assertEquals($column4->getName(), 'column4');
        $I->assertEquals($column4->getType(), Column::TYPE_CHAR);
        $I->assertEquals($column4->getSize(), 100);
        $I->assertEquals($column4->getScale(), 0);
        $I->assertFalse($column4->isUnsigned());
        $I->assertTrue($column4->isNotNull());

        //Date column
        $column5 = $columns['column5'];

        $I->assertEquals($column5->getName(), 'column5');
        $I->assertEquals($column5->getType(), Column::TYPE_DATE);
        $I->assertEquals($column5->getSize(), 0);
        $I->assertEquals($column5->getScale(), 0);
        $I->assertFalse($column5->isUnsigned());
        $I->assertTrue($column5->isNotNull());

        //Datetime column
        $column6 = $columns['column6'];

        $I->assertEquals($column6->getName(), 'column6');
        $I->assertEquals($column6->getType(), Column::TYPE_DATETIME);
        $I->assertEquals($column6->getSize(), 0);
        $I->assertEquals($column6->getScale(), 0);
        $I->assertFalse($column6->isUnsigned());
        $I->assertTrue($column6->isNotNull());

        //Text column
        $column7 = $columns['column7'];

        $I->assertEquals($column7->getName(), 'column7');
        $I->assertEquals($column7->getType(), Column::TYPE_TEXT);
        $I->assertEquals($column7->getSize(), 0);
        $I->assertEquals($column7->getScale(), 0);
        $I->assertFalse($column7->isUnsigned());
        $I->assertTrue($column7->isNotNull());

        //Float column
        $column8 = $columns['column8'];

        $I->assertEquals($column8->getName(), 'column8');
        $I->assertEquals($column8->getType(), Column::TYPE_FLOAT);
        $I->assertEquals($column8->getSize(), 10);
        $I->assertEquals($column8->getScale(), 2);
        $I->assertFalse($column8->isUnsigned());
        $I->assertTrue($column8->isNotNull());

        //Varchar column + default value
        $column9 = $columns['column9'];

        $I->assertEquals($column9->getName(), 'column9');
        $I->assertEquals($column9->getType(), Column::TYPE_VARCHAR);
        $I->assertEquals($column9->getSize(), 10);
        $I->assertEquals($column9->getScale(), 0);
        $I->assertFalse($column9->isUnsigned());
        $I->assertFalse($column9->isNotNull());
        $I->assertEquals($column9->getDefault(), 'column9');

        //Integer column + default value
        $column10 = $columns['column10'];

        $I->assertEquals($column10->getName(), 'column10');
        $I->assertEquals($column10->getType(), Column::TYPE_INTEGER);
        $I->assertEquals($column10->getSize(), 18);
        $I->assertEquals($column10->getScale(), 0);
        $I->assertTrue($column10->isUnsigned());
        $I->assertFalse($column10->isNotNull());
        $I->assertEquals($column10->getDefault(), '10');

        //Bigint column
        $column11 = $columns['column11'];

        $I->assertEquals($column11->getName(), 'column11');
        $I->assertEquals($column11->getType(), 'BIGINT');
        $I->assertEquals($column11->getTypeReference(), Column::TYPE_INTEGER);
        $I->assertEquals($column11->getSize(), 20);
        $I->assertEquals($column11->getScale(), 0);
        $I->assertTrue($column11->isUnsigned());
        $I->assertFalse($column11->isNotNull());

        //Enum column
        $column12 = $columns['column12'];

        $I->assertEquals($column12->getName(), 'column12');
        $I->assertEquals($column12->getType(), 'ENUM');
        $I->assertEquals($column12->getTypeReference(), -1);
        $I->assertEquals($column12->getTypeValues(), ['A', 'B', 'C']);
        $I->assertEquals($column12->getSize(), 0);
        $I->assertEquals($column12->getScale(), 0);
        $I->assertFalse($column12->isUnsigned());
        $I->assertTrue($column12->isNotNull());

        //Timestamp column
        $column13 = $columns['column13'];
        $I->assertEquals($column13->getName(), 'column13');
        $I->assertEquals($column13->getType(), Column::TYPE_TIMESTAMP);
        $I->assertTrue($column13->isNotNull());
        $I->assertEquals($column13->getDefault(), 'CURRENT_TIMESTAMP');

        //Tinyblob column
        $column14 = $columns['column14'];
        $I->assertEquals($column14->getName(), 'column14');
        $I->assertEquals($column14->getType(), Column::TYPE_TINYBLOB);
        $I->assertTrue($column14->isNotNull());

        //Mediumblob column
        $column15 = $columns['column15'];
        $I->assertEquals($column15->getName(), 'column15');
        $I->assertEquals($column15->getType(), Column::TYPE_MEDIUMBLOB);
        $I->assertTrue($column15->isNotNull());

        //Blob column
        $column16 = $columns['column16'];
        $I->assertEquals($column16->getName(), 'column16');
        $I->assertEquals($column16->getType(), Column::TYPE_BLOB);
        $I->assertTrue($column16->isNotNull());

        //Longblob column
        $column17 = $columns['column17'];
        $I->assertEquals($column17->getName(), 'column17');
        $I->assertEquals($column17->getType(), Column::TYPE_LONGBLOB);
        $I->assertTrue($column17->isNotNull());

        //Boolean column
        $column18 = $columns['column18'];
        $I->assertEquals($column18->getName(), 'column18');
        $I->assertEquals($column18->getType(), Column::TYPE_BOOLEAN);

        //Double column
        $column19 = $columns['column19'];
        $I->assertEquals($column19->getName(), 'column19');
        $I->assertEquals($column19->getType(), Column::TYPE_DOUBLE);
        $I->assertFalse($column19->isUnsigned());

        //Unsigned double column
        $column20 = $columns['column20'];
        $I->assertEquals($column20->getName(), 'column20');
        $I->assertEquals($column20->getType(), Column::TYPE_DOUBLE);
        $I->assertTrue($column20->isUnsigned());
    }
}
