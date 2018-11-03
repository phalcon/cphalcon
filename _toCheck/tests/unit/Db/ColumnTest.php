<?php

namespace Phalcon\Test\Unit\Db;

use Phalcon\Db\Column;
use Helper\DialectTrait;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Db\ColumnTest
 * Tests the \Phalcon\Db\Column component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit\Db
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class ColumnTest extends UnitTest
{
    use DialectTrait;

    /** @test */
    public function shouldWorkPerfectlyWithCoulmnAsObject()
    {
        $columns = $this->getColumns();

        //Varchar column
        $column1 = $columns['column1'];

        $this->assertEquals($column1->getName(), 'column1');
        $this->assertEquals($column1->getType(), Column::TYPE_VARCHAR);
        $this->assertEquals($column1->getSize(), 10);
        $this->assertEquals($column1->getScale(), 0);
        $this->assertFalse($column1->isUnsigned());
        $this->assertFalse($column1->isNotNull());

        //Integer column
        $column2 = $columns['column2'];

        $this->assertEquals($column2->getName(), 'column2');
        $this->assertEquals($column2->getType(), Column::TYPE_INTEGER);
        $this->assertEquals($column2->getSize(), 18);
        $this->assertEquals($column2->getScale(), 0);
        $this->assertTrue($column2->isUnsigned());
        $this->assertFalse($column2->isNotNull());

        //Decimal column
        $column3 = $columns['column3'];

        $this->assertEquals($column3->getName(), 'column3');
        $this->assertEquals($column3->getType(), Column::TYPE_DECIMAL);
        $this->assertEquals($column3->getSize(), 10);
        $this->assertEquals($column3->getScale(), 2);
        $this->assertFalse($column3->isUnsigned());
        $this->assertTrue($column3->isNotNull());

        //Char column
        $column4 = $columns['column4'];

        $this->assertEquals($column4->getName(), 'column4');
        $this->assertEquals($column4->getType(), Column::TYPE_CHAR);
        $this->assertEquals($column4->getSize(), 100);
        $this->assertEquals($column4->getScale(), 0);
        $this->assertFalse($column4->isUnsigned());
        $this->assertTrue($column4->isNotNull());

        //Date column
        $column5 = $columns['column5'];

        $this->assertEquals($column5->getName(), 'column5');
        $this->assertEquals($column5->getType(), Column::TYPE_DATE);
        $this->assertEquals($column5->getSize(), 0);
        $this->assertEquals($column5->getScale(), 0);
        $this->assertFalse($column5->isUnsigned());
        $this->assertTrue($column5->isNotNull());

        //Datetime column
        $column6 = $columns['column6'];

        $this->assertEquals($column6->getName(), 'column6');
        $this->assertEquals($column6->getType(), Column::TYPE_DATETIME);
        $this->assertEquals($column6->getSize(), 0);
        $this->assertEquals($column6->getScale(), 0);
        $this->assertFalse($column6->isUnsigned());
        $this->assertTrue($column6->isNotNull());

        //Text column
        $column7 = $columns['column7'];

        $this->assertEquals($column7->getName(), 'column7');
        $this->assertEquals($column7->getType(), Column::TYPE_TEXT);
        $this->assertEquals($column7->getSize(), 0);
        $this->assertEquals($column7->getScale(), 0);
        $this->assertFalse($column7->isUnsigned());
        $this->assertTrue($column7->isNotNull());

        //Float column
        $column8 = $columns['column8'];

        $this->assertEquals($column8->getName(), 'column8');
        $this->assertEquals($column8->getType(), Column::TYPE_FLOAT);
        $this->assertEquals($column8->getSize(), 10);
        $this->assertEquals($column8->getScale(), 2);
        $this->assertFalse($column8->isUnsigned());
        $this->assertTrue($column8->isNotNull());

        //Varchar column + default value
        $column9 = $columns['column9'];

        $this->assertEquals($column9->getName(), 'column9');
        $this->assertEquals($column9->getType(), Column::TYPE_VARCHAR);
        $this->assertEquals($column9->getSize(), 10);
        $this->assertEquals($column9->getScale(), 0);
        $this->assertFalse($column9->isUnsigned());
        $this->assertFalse($column9->isNotNull());
        $this->assertEquals($column9->getDefault(), 'column9');

        //Integer column + default value
        $column10 = $columns['column10'];

        $this->assertEquals($column10->getName(), 'column10');
        $this->assertEquals($column10->getType(), Column::TYPE_INTEGER);
        $this->assertEquals($column10->getSize(), 18);
        $this->assertEquals($column10->getScale(), 0);
        $this->assertTrue($column10->isUnsigned());
        $this->assertFalse($column10->isNotNull());
        $this->assertEquals($column10->getDefault(), '10');

        //Bigint column
        $column11 = $columns['column11'];

        $this->assertEquals($column11->getName(), 'column11');
        $this->assertEquals($column11->getType(), 'BIGINT');
        $this->assertEquals($column11->getTypeReference(), Column::TYPE_INTEGER);
        $this->assertEquals($column11->getSize(), 20);
        $this->assertEquals($column11->getScale(), 0);
        $this->assertTrue($column11->isUnsigned());
        $this->assertFalse($column11->isNotNull());

        //Enum column
        $column12 = $columns['column12'];

        $this->assertEquals($column12->getName(), 'column12');
        $this->assertEquals($column12->getType(), 'ENUM');
        $this->assertEquals($column12->getTypeReference(), -1);
        $this->assertEquals($column12->getTypeValues(), ['A', 'B', 'C']);
        $this->assertEquals($column12->getSize(), 0);
        $this->assertEquals($column12->getScale(), 0);
        $this->assertFalse($column12->isUnsigned());
        $this->assertTrue($column12->isNotNull());

        //Timestamp column
        $column13 = $columns['column13'];
        $this->assertEquals($column13->getName(), 'column13');
        $this->assertEquals($column13->getType(), Column::TYPE_TIMESTAMP);
        $this->assertTrue($column13->isNotNull());
        $this->assertEquals($column13->getDefault(), 'CURRENT_TIMESTAMP');

        //Tinyblob column
        $column14 = $columns['column14'];
        $this->assertEquals($column14->getName(), 'column14');
        $this->assertEquals($column14->getType(), Column::TYPE_TINYBLOB);
        $this->assertTrue($column14->isNotNull());

        //Mediumblob column
        $column15 = $columns['column15'];
        $this->assertEquals($column15->getName(), 'column15');
        $this->assertEquals($column15->getType(), Column::TYPE_MEDIUMBLOB);
        $this->assertTrue($column15->isNotNull());

        //Blob column
        $column16 = $columns['column16'];
        $this->assertEquals($column16->getName(), 'column16');
        $this->assertEquals($column16->getType(), Column::TYPE_BLOB);
        $this->assertTrue($column16->isNotNull());

        //Longblob column
        $column17 = $columns['column17'];
        $this->assertEquals($column17->getName(), 'column17');
        $this->assertEquals($column17->getType(), Column::TYPE_LONGBLOB);
        $this->assertTrue($column17->isNotNull());

        //Boolean column
        $column18 = $columns['column18'];
        $this->assertEquals($column18->getName(), 'column18');
        $this->assertEquals($column18->getType(), Column::TYPE_BOOLEAN);

        //Double column
        $column19 = $columns['column19'];
        $this->assertEquals($column19->getName(), 'column19');
        $this->assertEquals($column19->getType(), Column::TYPE_DOUBLE);
        $this->assertFalse($column19->isUnsigned());

        //Unsigned double column
        $column20 = $columns['column20'];
        $this->assertEquals($column20->getName(), 'column20');
        $this->assertEquals($column20->getType(), Column::TYPE_DOUBLE);
        $this->assertTrue($column20->isUnsigned());
    }
}
