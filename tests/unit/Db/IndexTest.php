<?php

namespace Phalcon\Test\Unit\Db;

use Helper\DialectTrait;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Db\IndexTest
 * Tests the \Phalcon\Db\Index component
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
class IndexTest extends UnitTest
{
    use DialectTrait;

    /** @test */
    public function shouldWorkPerfectlyWithIndexAsObject()
    {
        $indexes = $this->getIndexes();

        $index1 = $indexes['index1'];
        $this->assertEquals($index1->getName(), 'index1');
        $this->assertEquals($index1->getColumns(), ['column1']);

        $index2 = $indexes['index2'];
        $this->assertEquals($index2->getName(), 'index2');
        $this->assertEquals($index2->getColumns(), ['column1', 'column2']);

        $index3 = $indexes['PRIMARY'];
        $this->assertEquals($index3->getName(), 'PRIMARY');
        $this->assertEquals($index3->getColumns(), ['column3']);

        $index4 = $indexes['index4'];
        $this->assertEquals($index4->getName(), 'index4');
        $this->assertEquals($index4->getColumns(), ['column4']);
        $this->assertEquals($index4->getType(), 'UNIQUE');

        $index5 = $indexes['index5'];
        $this->assertEquals($index5->getName(), 'index5');
        $this->assertEquals($index5->getColumns(), ['column7']);
        $this->assertEquals($index5->getType(), 'FULLTEXT');
    }
}
