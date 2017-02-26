<?php

/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2017 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  |          Rack Lin <racklin@gmail.com>                                  |
  +------------------------------------------------------------------------+
*/

use Phalcon\Db\Column;
use Phalcon\Db\Index;
use Phalcon\Db\Reference;

class DbDialectTest extends PHPUnit_Framework_TestCase
{
    private function getColumns()
    {
        return array(
            'column1' => new Column("column1", array(
                'type' => Column::TYPE_VARCHAR,
                'size' => 10
            )),
            'column2' => new Column("column2", array(
                'type' => Column::TYPE_INTEGER,
                'size' => 18,
                'unsigned' => true,
                'notNull' => false
            )),
            'column3' => new Column("column3", array(
                'type' => Column::TYPE_DECIMAL,
                'size' => 10,
                'scale' => 2,
                'unsigned' => false,
                'notNull' => true
            )),
            'column4' => new Column("column4", array(
                'type' => Column::TYPE_CHAR,
                'size' => 100,
                'notNull' => true
            )),
            'column5' => new Column("column5", array(
                'type' => Column::TYPE_DATE,
                'notNull' => true
            )),
            'column6' => new Column("column6", array(
                'type' => Column::TYPE_DATETIME,
                'notNull' => true
            )),
            'column7' => new Column("column7", array(
                'type' => Column::TYPE_TEXT,
                'notNull' => true
            )),
            'column8' => new Column("column8", array(
                'type' => Column::TYPE_FLOAT,
                'size' => 10,
                'scale' => 2,
                'unsigned' => false,
                'notNull' => true
            )),
            'column9' => new Column("column9", array(
                'type' => Column::TYPE_VARCHAR,
                'size' => 10,
                'default' => 'column9'
            )),
            'column10' => new Column("column10", array(
                'type' => Column::TYPE_INTEGER,
                'size' => 18,
                'unsigned' => true,
                'notNull' => false,
                'default' => 10,
            )),
            'column11' => new Column("column11", array(
                'type' => 'BIGINT',
                'typeReference' => Column::TYPE_INTEGER,
                'size' => 20,
                'unsigned' => true,
                'notNull' => false
            )),
            'column12' => new Column("column12", array(
                'type' => 'ENUM',
                'typeValues' => array('A', 'B', 'C'),
                'notNull' => true,
                'default' => 'A',
                'after' => 'column11'
            )),
            'column13' => new Column("column13", array(
                'type' => Column::TYPE_TIMESTAMP,
                'notNull' => true,
                'default' => 'CURRENT_TIMESTAMP',
            )),
            'column14' => new Column("column14", array(
                'type' => Column::TYPE_TINYBLOB,
                'notNull' => true
            )),
            'column15' => new Column("column15", array(
                'type' => Column::TYPE_MEDIUMBLOB,
                'notNull' => true
            )),
            'column16' => new Column("column16", array(
                'type' => Column::TYPE_BLOB,
                'notNull' => true
            )),
            'column17' => new Column("column17", array(
                'type' => Column::TYPE_LONGBLOB,
                'notNull' => true
            )),
            'column18' => new Column("column18", array(
                'type' => Column::TYPE_BOOLEAN,
            )),
            'column19' => new Column("column19", array(
                'type' => Column::TYPE_DOUBLE,
            )),
            'column20' => new Column("column20", array(
                'type' => Column::TYPE_DOUBLE,
                'unsigned' => true
            ))
        );
    }

    private function getIndexes()
    {
        return array(
            'index1' => new Index("index1", array('column1')),
            'index2' => new Index("index2", array('column1', 'column2')),
            'PRIMARY' => new Index("PRIMARY", array('column3')),
            'index4' => new Index("index4", array('column4'), 'UNIQUE'),
            'index5' => new Index("index5", array('column7'), 'FULLTEXT'),
        );
    }

    private function getReferences()
    {
        return array(
            'fk1' => new Reference("fk1", array(
                'referencedTable' => 'ref_table',
                'columns' => array('column1'),
                'referencedColumns' => array('column2')
            )),
            'fk2' => new Reference("fk2", array(
                'referencedTable' => 'ref_table',
                'columns' => array('column3', 'column4'),
                'referencedColumns' => array('column5', 'column6')
            )),
            'fk3' => new Reference("fk3", array(
                'referencedTable' => 'ref_table',
                'columns' => array('column1'),
                'referencedColumns' => array('column2'),
                'onDelete' => 'CASCADE',
            )),
            'fk4' => new Reference("fk4", array(
                'referencedTable' => 'ref_table',
                'columns' => array('column1'),
                'referencedColumns' => array('column2'),
                'onUpdate' => 'SET NULL',
            )),
            'fk5' => new Reference("fk5", array(
                'referencedTable' => 'ref_table',
                'columns' => array('column1'),
                'referencedColumns' => array('column2'),
                'onDelete' => 'CASCADE',
                'onUpdate' => 'NO ACTION',
            )),
        );
    }

    public function testDbColumn()
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
        $this->assertEquals($column12->getTypeValues(), array('A', 'B', 'C'));
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

    public function testIndexes()
    {

        $indexes = $this->getIndexes();

        $index1 = $indexes['index1'];
        $this->assertEquals($index1->getName(), 'index1');
        $this->assertEquals($index1->getColumns(), array('column1'));

        $index2 = $indexes['index2'];
        $this->assertEquals($index2->getName(), 'index2');
        $this->assertEquals($index2->getColumns(), array('column1', 'column2'));

        $index3 = $indexes['PRIMARY'];
        $this->assertEquals($index3->getName(), 'PRIMARY');
        $this->assertEquals($index3->getColumns(), array('column3'));

        $index4 = $indexes['index4'];
        $this->assertEquals($index4->getName(), 'index4');
        $this->assertEquals($index4->getColumns(), array('column4'));
        $this->assertEquals($index4->getType(), 'UNIQUE');

        $index5 = $indexes['index5'];
        $this->assertEquals($index5->getName(), 'index5');
        $this->assertEquals($index5->getColumns(), array('column7'));
        $this->assertEquals($index5->getType(), 'FULLTEXT');

    }

    public function testReferences()
    {

        $references = $this->getReferences();

        $reference1 = $references['fk1'];
        $this->assertEquals($reference1->getName(), 'fk1');
        $this->assertEquals($reference1->getColumns(), array('column1'));
        $this->assertEquals($reference1->getReferencedTable(), 'ref_table');
        $this->assertEquals($reference1->getReferencedColumns(), array('column2'));
        $this->assertEquals($reference1->getOnDelete(), NULL);
        $this->assertEquals($reference1->getOnUpdate(), NULL);

        $reference2 = $references['fk2'];
        $this->assertEquals($reference2->getName(), 'fk2');
        $this->assertEquals($reference2->getColumns(), array('column3', 'column4'));
        $this->assertEquals($reference2->getReferencedTable(), 'ref_table');
        $this->assertEquals($reference2->getReferencedColumns(), array('column5', 'column6'));
        $this->assertEquals($reference1->getOnDelete(), NULL);
        $this->assertEquals($reference1->getOnUpdate(), NULL);

        $reference3 = $references['fk3'];
        $this->assertEquals($reference3->getName(), 'fk3');
        $this->assertEquals($reference3->getColumns(), array('column1'));
        $this->assertEquals($reference3->getReferencedTable(), 'ref_table');
        $this->assertEquals($reference3->getReferencedColumns(), array('column2'));
        $this->assertEquals($reference3->getOnDelete(), 'CASCADE');
        $this->assertEquals($reference3->getOnUpdate(), NULL);

        $reference4 = $references['fk4'];
        $this->assertEquals($reference4->getName(), 'fk4');
        $this->assertEquals($reference4->getColumns(), array('column1'));
        $this->assertEquals($reference4->getReferencedTable(), 'ref_table');
        $this->assertEquals($reference4->getReferencedColumns(), array('column2'));
        $this->assertEquals($reference4->getOnDelete(), NULL);
        $this->assertEquals($reference4->getOnUpdate(), 'SET NULL');

        $reference5 = $references['fk5'];
        $this->assertEquals($reference5->getName(), 'fk5');
        $this->assertEquals($reference5->getColumns(), array('column1'));
        $this->assertEquals($reference5->getReferencedTable(), 'ref_table');
        $this->assertEquals($reference5->getReferencedColumns(), array('column2'));
        $this->assertEquals($reference5->getOnDelete(), 'CASCADE');
        $this->assertEquals($reference5->getOnUpdate(), 'NO ACTION');

    }
}
