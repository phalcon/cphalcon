<?php

namespace Phalcon\Test\Unit\Db;

use Helper\DialectTrait;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Db\ReferenceTest
 * Tests the \Phalcon\Db\Reference component
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
class ReferenceTest extends UnitTest
{
    use DialectTrait;

    /** @test */
    public function shouldWorkPerfectlyWithCReferenceAsObject()
    {
        $references = $this->getReferences();

        $reference1 = $references['fk1'];
        $this->assertEquals($reference1->getName(), 'fk1');
        $this->assertEquals($reference1->getColumns(), ['column1']);
        $this->assertEquals($reference1->getReferencedTable(), 'ref_table');
        $this->assertEquals($reference1->getReferencedColumns(), ['column2']);
        $this->assertEquals($reference1->getOnDelete(), null);
        $this->assertEquals($reference1->getOnUpdate(), null);

        $reference2 = $references['fk2'];
        $this->assertEquals($reference2->getName(), 'fk2');
        $this->assertEquals($reference2->getColumns(), ['column3', 'column4']);
        $this->assertEquals($reference2->getReferencedTable(), 'ref_table');
        $this->assertEquals($reference2->getReferencedColumns(), ['column5', 'column6']);
        $this->assertEquals($reference1->getOnDelete(), null);
        $this->assertEquals($reference1->getOnUpdate(), null);

        $reference3 = $references['fk3'];
        $this->assertEquals($reference3->getName(), 'fk3');
        $this->assertEquals($reference3->getColumns(), ['column1']);
        $this->assertEquals($reference3->getReferencedTable(), 'ref_table');
        $this->assertEquals($reference3->getReferencedColumns(), ['column2']);
        $this->assertEquals($reference3->getOnDelete(), 'CASCADE');
        $this->assertEquals($reference3->getOnUpdate(), null);

        $reference4 = $references['fk4'];
        $this->assertEquals($reference4->getName(), 'fk4');
        $this->assertEquals($reference4->getColumns(), ['column1']);
        $this->assertEquals($reference4->getReferencedTable(), 'ref_table');
        $this->assertEquals($reference4->getReferencedColumns(), ['column2']);
        $this->assertEquals($reference4->getOnDelete(), null);
        $this->assertEquals($reference4->getOnUpdate(), 'SET NULL');

        $reference5 = $references['fk5'];
        $this->assertEquals($reference5->getName(), 'fk5');
        $this->assertEquals($reference5->getColumns(), ['column1']);
        $this->assertEquals($reference5->getReferencedTable(), 'ref_table');
        $this->assertEquals($reference5->getReferencedColumns(), ['column2']);
        $this->assertEquals($reference5->getOnDelete(), 'CASCADE');
        $this->assertEquals($reference5->getOnUpdate(), 'NO ACTION');
    }
}
