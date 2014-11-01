<?php
/**
 * MysqlTest.php
 * \Phalcon\Tag\MysqlTest
 *
 * Tests the \Phalcon\Tag component
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2014 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

namespace Phalcon\Tests\unit\Phalcon\Tag;

use PhalconTest\Models\Select;

class MysqlTest extends Helper\TagBase
{
    public function setUp()
    {
        parent::setUp();

        $this->setDb('mysql');
    }

    public function notestMe()
    {
        $select = new Select();

        $select->setName('Option');
        $select->setText('Option Text');
        $select->save();

        $actual   = $select->getName();
        $expected = 'Option';
        expect($actual)->equals($expected);

        $this->unitTester->seeInDatabase(
            'ph_select',
            [
                'sel_name' => 'Option',
                'sel_text' => 'Option Text'
            ]
        );
    }
}
