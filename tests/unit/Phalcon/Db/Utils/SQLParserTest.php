<?php

/**
 * SQLParserTest.php
 * \Phalcon\Db\Utils\SQLParser
 *
 * Tests the \Phalcon\Db\Utils\SQLParser component
 * Port to Phalcon of tests for class SQLParserUtils of Doctrine DBAL.
 *
 * Phalcon Framework
 *
 * @copyright (c) 2011-2015 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Doctrine DBAL Team, Vladimir Khramov <quant13@gmail.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * This source file is based on the file of Doctrine DBAL project, which
 * licensed under the MIT license (see below).
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 *
 *
 * Doctrine 2 License (MIT)
 *
 * Copyright (c) 2006-2012 Doctrine Project
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is furnished to do
 * so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */


namespace Phalcon\Tests\unit\Phalcon\Db\Utils;

use \Phalcon\Db\Utils\SQLParser;
use \Phalcon\Db\Column;
use \Phalcon\Tests\unit\Phalcon\_Helper\TestsBase as TBase;

class SQLParserTest extends TBase
{
    public function dataGetPlaceholderPositions()
    {
        return array(
            // none
            array('SELECT * FROM Foo', true, array()),
            array('SELECT * FROM Foo', false, array()),

            // Positionals
            array('SELECT ?', true, array(7)),
            array('SELECT * FROM Foo WHERE bar IN (?, ?, ?)', true, array(32, 35, 38)),
            array('SELECT ? FROM ?', true, array(7, 14)),
            array('SELECT "?" FROM foo', true, array()),
            array("SELECT '?' FROM foo", true, array()),
            array("SELECT `?` FROM foo", true, array()), // Ticket DBAL-552
            array("SELECT [?] FROM foo", true, array()),
            array("SELECT 'Doctrine\DBAL?' FROM foo", true, array()), // Ticket DBAL-558
            array('SELECT "Doctrine\DBAL?" FROM foo', true, array()), // Ticket DBAL-558
            array('SELECT `Doctrine\DBAL?` FROM foo', true, array()), // Ticket DBAL-558
            array('SELECT [Doctrine\DBAL?] FROM foo', true, array()), // Ticket DBAL-558
            array('SELECT "?" FROM foo WHERE bar = ?', true, array(32)),
            array("SELECT '?' FROM foo WHERE bar = ?", true, array(32)),
            array("SELECT `?` FROM foo WHERE bar = ?", true, array(32)), // Ticket DBAL-552
            array("SELECT [?] FROM foo WHERE bar = ?", true, array(32)),
            array("SELECT 'Doctrine\DBAL?' FROM foo WHERE bar = ?", true, array(45)), // Ticket DBAL-558
            array('SELECT "Doctrine\DBAL?" FROM foo WHERE bar = ?', true, array(45)), // Ticket DBAL-558
            array('SELECT `Doctrine\DBAL?` FROM foo WHERE bar = ?', true, array(45)), // Ticket DBAL-558
            array('SELECT [Doctrine\DBAL?] FROM foo WHERE bar = ?', true, array(45)), // Ticket DBAL-558
            array(
<<<'SQLDATA'
SELECT * FROM foo WHERE bar = 'it\'s a trap? \\' OR bar = ?
AND baz = "\"quote\" me on it? \\" OR baz = ?
SQLDATA
            , true, array(58, 104)
            ),
            array('SELECT * FROM foo WHERE foo = ? AND bar = ?', true, array(1 => 42, 0 => 30)), // explicit keys

            // named
            array('SELECT :foo FROM :bar', false, array(7 => 'foo', 17 => 'bar')),
            array('SELECT * FROM Foo WHERE bar IN (:name1, :name2)', false, array(32 => 'name1', 40 => 'name2')),
            array('SELECT ":foo" FROM Foo WHERE bar IN (:name1, :name2)', false, array(37 => 'name1', 45 => 'name2')),
            array("SELECT ':foo' FROM Foo WHERE bar IN (:name1, :name2)", false, array(37 => 'name1', 45 => 'name2')),
            array('SELECT :foo_id', false, array(7 => 'foo_id')), // Ticket DBAL-231
            array('SELECT @rank := 1', false, array()), // Ticket DBAL-398
            array('SELECT @rank := 1 AS rank, :foo AS foo FROM :bar', false, array(27 => 'foo', 44 => 'bar')), // Ticket DBAL-398
            array('SELECT * FROM Foo WHERE bar > :start_date AND baz > :start_date', false, array(30 => 'start_date', 52 =>  'start_date')), // Ticket GH-113
            array('SELECT foo::date as date FROM Foo WHERE bar > :start_date AND baz > :start_date', false, array(46 => 'start_date', 68 =>  'start_date')), // Ticket GH-259
            array('SELECT `d.ns:col_name` FROM my_table d WHERE `d.date` >= :param1', false, array(57 => 'param1')), // Ticket DBAL-552
            array('SELECT [d.ns:col_name] FROM my_table d WHERE [d.date] >= :param1', false, array(57 => 'param1')), // Ticket DBAL-552
        );
    }

    /**
     * @dataProvider dataGetPlaceholderPositions
     */
    public function testGetPlaceholderPositions($query, $isPositional, $expectedParamPos)
    {
        $actualParamPos = SQLParser::getPlaceholderPositions($query, $isPositional);
        $this->assertEquals($expectedParamPos, $actualParamPos);
    }

    public function dataExpandListParameters()
    {
        return array(
            // Positional: Very simple with one needle
            array(
                "SELECT * FROM Foo WHERE foo IN (?)",
                array(array(1, 2, 3)),
                array(Column::BIND_PARAM_INT_ARRAY),
                'SELECT * FROM Foo WHERE foo IN (?, ?, ?)',
                array(1, 2, 3),
                array(Column::BIND_PARAM_INT, Column::BIND_PARAM_INT, Column::BIND_PARAM_INT)
            ),
            // Positional: One non-list before d one after list-needle
            array(
                "SELECT * FROM Foo WHERE foo = ? AND bar IN (?)",
                array("string", array(1, 2, 3)),
                array(Column::BIND_PARAM_STR, Column::BIND_PARAM_INT_ARRAY),
                'SELECT * FROM Foo WHERE foo = ? AND bar IN (?, ?, ?)',
                array("string", 1, 2, 3),
                array(Column::BIND_PARAM_STR, Column::BIND_PARAM_INT, Column::BIND_PARAM_INT, Column::BIND_PARAM_INT)
            ),
            // Positional: One non-list after list-needle
            array(
                "SELECT * FROM Foo WHERE bar IN (?) AND baz = ?",
                array(array(1, 2, 3), "foo"),
                array(Column::BIND_PARAM_INT_ARRAY, Column::BIND_PARAM_STR),
                'SELECT * FROM Foo WHERE bar IN (?, ?, ?) AND baz = ?',
                array(1, 2, 3, "foo"),
                array(Column::BIND_PARAM_INT, Column::BIND_PARAM_INT, Column::BIND_PARAM_INT, Column::BIND_PARAM_STR)
            ),
            // Positional: One non-list before and one after list-needle
            array(
                "SELECT * FROM Foo WHERE foo = ? AND bar IN (?) AND baz = ?",
                array(1, array(1, 2, 3), 4),
                array(Column::BIND_PARAM_INT, Column::BIND_PARAM_INT_ARRAY, Column::BIND_PARAM_INT),
                'SELECT * FROM Foo WHERE foo = ? AND bar IN (?, ?, ?) AND baz = ?',
                array(1, 1, 2, 3, 4),
                array(Column::BIND_PARAM_INT, Column::BIND_PARAM_INT, Column::BIND_PARAM_INT, Column::BIND_PARAM_INT, Column::BIND_PARAM_INT)
            ),
            // Positional: Two lists
            array(
                "SELECT * FROM Foo WHERE foo IN (?, ?)",
                array(array(1, 2, 3), array(4, 5)),
                array(Column::BIND_PARAM_INT_ARRAY, Column::BIND_PARAM_INT_ARRAY),
                'SELECT * FROM Foo WHERE foo IN (?, ?, ?, ?, ?)',
                array(1, 2, 3, 4, 5),
                array(Column::BIND_PARAM_INT, Column::BIND_PARAM_INT, Column::BIND_PARAM_INT, Column::BIND_PARAM_INT, Column::BIND_PARAM_INT)
            ),
            // Positional: Empty "integer" array DDC-1978
            array(
                "SELECT * FROM Foo WHERE foo IN (?)",
                array(array()),
                array(Column::BIND_PARAM_INT_ARRAY),
                'SELECT * FROM Foo WHERE foo IN (NULL)',
                array(),
                array()
            ),
            // Positional: Empty "str" array DDC-1978
            array(
                "SELECT * FROM Foo WHERE foo IN (?)",
                array(array()),
                array(Column::BIND_PARAM_STR_ARRAY),
                'SELECT * FROM Foo WHERE foo IN (NULL)',
                array(),
                array()
            ),
            // Positional: explicit keys for params and types
            array(
                "SELECT * FROM Foo WHERE foo = ? AND bar = ? AND baz = ?",
                array(1 => 'bar', 2 => 'baz', 0 => 1),
                array(2 => Column::BIND_PARAM_STR, 1 => Column::BIND_PARAM_STR),
                'SELECT * FROM Foo WHERE foo = ? AND bar = ? AND baz = ?',
                array(1 => 'bar', 0 => 1, 2 => 'baz'),
                array(1 => Column::BIND_PARAM_STR, 2 => Column::BIND_PARAM_STR)
            ),
            // Positional: explicit keys for array params and array types
            array(
                "SELECT * FROM Foo WHERE foo IN (?) AND bar IN (?) AND baz = ?",
                array(1 => array('bar1', 'bar2'), 2 => true, 0 => array(1, 2, 3)),
                array(2 => Column::BIND_PARAM_BOOL, 1 => Column::BIND_PARAM_STR_ARRAY, 0 => Column::BIND_PARAM_INT_ARRAY),
                'SELECT * FROM Foo WHERE foo IN (?, ?, ?) AND bar IN (?, ?) AND baz = ?',
                array(1, 2, 3, 'bar1', 'bar2', true),
                array(Column::BIND_PARAM_INT, Column::BIND_PARAM_INT, Column::BIND_PARAM_INT, Column::BIND_PARAM_STR, Column::BIND_PARAM_STR, Column::BIND_PARAM_BOOL)
            ),
            // Positional starts from 1: One non-list before and one after list-needle
            array(
                "SELECT * FROM Foo WHERE foo = ? AND bar IN (?) AND baz = ? AND foo IN (?)",
                array(1 => 1, 2 => array(1, 2, 3), 3 => 4, 4 => array(5, 6)),
                array(1 => Column::BIND_PARAM_INT, 2 => Column::BIND_PARAM_INT_ARRAY, 3 => Column::BIND_PARAM_INT, 4 => Column::BIND_PARAM_INT_ARRAY),
                'SELECT * FROM Foo WHERE foo = ? AND bar IN (?, ?, ?) AND baz = ? AND foo IN (?, ?)',
                array(1, 1, 2, 3, 4, 5, 6),
                array(Column::BIND_PARAM_INT, Column::BIND_PARAM_INT, Column::BIND_PARAM_INT, Column::BIND_PARAM_INT, Column::BIND_PARAM_INT, Column::BIND_PARAM_INT, Column::BIND_PARAM_INT)
            ),
            //  Named parameters : Very simple with one needle
            array(
                "SELECT * FROM Foo WHERE foo IN (:foo)",
                array('foo'=>array(1, 2, 3)),
                array('foo'=>Column::BIND_PARAM_INT_ARRAY),
                'SELECT * FROM Foo WHERE foo IN (?, ?, ?)',
                array(1, 2, 3),
                array(Column::BIND_PARAM_INT, Column::BIND_PARAM_INT, Column::BIND_PARAM_INT)
            ),
            // Named parameters: One non-list before d one after list-needle
            array(
                "SELECT * FROM Foo WHERE foo = :foo AND bar IN (:bar)",
                array('foo'=>"string", 'bar'=>array(1, 2, 3)),
                array('foo'=>Column::BIND_PARAM_STR, 'bar'=>Column::BIND_PARAM_INT_ARRAY),
                'SELECT * FROM Foo WHERE foo = ? AND bar IN (?, ?, ?)',
                array("string", 1, 2, 3),
                array(Column::BIND_PARAM_STR, Column::BIND_PARAM_INT, Column::BIND_PARAM_INT, Column::BIND_PARAM_INT)
            ),
            // Named parameters: One non-list after list-needle
            array(
                "SELECT * FROM Foo WHERE bar IN (:bar) AND baz = :baz",
                array('bar'=>array(1, 2, 3), 'baz'=>"foo"),
                array('bar'=>Column::BIND_PARAM_INT_ARRAY, 'baz'=>Column::BIND_PARAM_STR),
                'SELECT * FROM Foo WHERE bar IN (?, ?, ?) AND baz = ?',
                array(1, 2, 3, "foo"),
                array(Column::BIND_PARAM_INT, Column::BIND_PARAM_INT, Column::BIND_PARAM_INT, Column::BIND_PARAM_STR)
            ),
            // Named parameters: One non-list before and one after list-needle
            array(
                "SELECT * FROM Foo WHERE foo = :foo AND bar IN (:bar) AND baz = :baz",
                array('bar'=>array(1, 2, 3),'foo'=>1, 'baz'=>4),
                array('bar'=>Column::BIND_PARAM_INT_ARRAY, 'foo'=>Column::BIND_PARAM_INT, 'baz'=>Column::BIND_PARAM_INT),
                'SELECT * FROM Foo WHERE foo = ? AND bar IN (?, ?, ?) AND baz = ?',
                array(1, 1, 2, 3, 4),
                array(Column::BIND_PARAM_INT, Column::BIND_PARAM_INT, Column::BIND_PARAM_INT, Column::BIND_PARAM_INT, Column::BIND_PARAM_INT)
            ),
            // Named parameters: Two lists
            array(
                "SELECT * FROM Foo WHERE foo IN (:a, :b)",
                array('b'=>array(4, 5),'a'=>array(1, 2, 3)),
                array('a'=>Column::BIND_PARAM_INT_ARRAY, 'b'=>Column::BIND_PARAM_INT_ARRAY),
                'SELECT * FROM Foo WHERE foo IN (?, ?, ?, ?, ?)',
                array(1, 2, 3, 4, 5),
                array(Column::BIND_PARAM_INT, Column::BIND_PARAM_INT, Column::BIND_PARAM_INT, Column::BIND_PARAM_INT, Column::BIND_PARAM_INT)
            ),
            //  Named parameters : With the same name arg
            array(
                "SELECT * FROM Foo WHERE foo IN (:arg) AND NOT bar IN (:arg)",
                array('arg'=>array(1, 2, 3)),
                array('arg'=>Column::BIND_PARAM_INT_ARRAY),
                'SELECT * FROM Foo WHERE foo IN (?, ?, ?) AND NOT bar IN (?, ?, ?)',
                array(1, 2, 3, 1, 2, 3),
                array(Column::BIND_PARAM_INT,Column::BIND_PARAM_INT, Column::BIND_PARAM_INT,Column::BIND_PARAM_INT,Column::BIND_PARAM_INT, Column::BIND_PARAM_INT)
            ),

            //  Named parameters : Empty "integer" array DDC-1978
            array(
                "SELECT * FROM Foo WHERE foo IN (:foo)",
                array('foo'=>array()),
                array('foo'=>Column::BIND_PARAM_INT_ARRAY),
                'SELECT * FROM Foo WHERE foo IN (NULL)',
                array(),
                array()
            ),
            //  Named parameters : Two empty "str" array DDC-1978
            array(
                "SELECT * FROM Foo WHERE foo IN (:foo) OR bar IN (:bar)",
                array('foo'=>array(), 'bar'=>array()),
                array('foo'=>Column::BIND_PARAM_STR_ARRAY, 'bar'=>Column::BIND_PARAM_STR_ARRAY),
                'SELECT * FROM Foo WHERE foo IN (NULL) OR bar IN (NULL)',
                array(),
                array()
            ),
            array(
                "SELECT * FROM Foo WHERE foo IN (:foo) OR bar = :bar OR baz = :baz",
                array('foo' => array(1, 2), 'bar' => 'bar', 'baz' => 'baz'),
                array('foo' => Column::BIND_PARAM_INT_ARRAY, 'baz' => 'string'),
                'SELECT * FROM Foo WHERE foo IN (?, ?) OR bar = ? OR baz = ?',
                array(1, 2, 'bar', 'baz'),
                array(Column::BIND_PARAM_INT, Column::BIND_PARAM_INT, Column::BIND_PARAM_STR, 'string')
            ),
            array(
                "SELECT * FROM Foo WHERE foo IN (:foo) OR bar = :bar",
                array('foo' => array(1, 2), 'bar' => 'bar'),
                array('foo' => Column::BIND_PARAM_INT_ARRAY),
                'SELECT * FROM Foo WHERE foo IN (?, ?) OR bar = ?',
                array(1, 2, 'bar'),
                array(Column::BIND_PARAM_INT, Column::BIND_PARAM_INT, Column::BIND_PARAM_STR)
            ),
            // Params/types with colons
            array(
                "SELECT * FROM Foo WHERE foo IN (:foo) OR bar = :bar",
                array(':foo' => array(1, 2), ':bar' => 'bar'),
                array('foo' => Column::BIND_PARAM_INT_ARRAY),
                'SELECT * FROM Foo WHERE foo IN (?, ?) OR bar = ?',
                array(1, 2, 'bar'),
                array(Column::BIND_PARAM_INT, Column::BIND_PARAM_INT, Column::BIND_PARAM_STR)
            ),
            array(
                "SELECT * FROM Foo WHERE foo IN (:foo) OR bar = :bar",
                array('foo' => array(1, 2), 'bar' => 'bar'),
                array(':foo' => Column::BIND_PARAM_INT_ARRAY),
                'SELECT * FROM Foo WHERE foo IN (?, ?) OR bar = ?',
                array(1, 2, 'bar'),
                array(Column::BIND_PARAM_INT, Column::BIND_PARAM_INT, Column::BIND_PARAM_STR)
            ),
            // DBAL-522 - null valued parameters are not considered
            array(
                'INSERT INTO Foo (foo, bar) values (?, ?)',
                array(1, null),
                array(Column::BIND_PARAM_INT, Column::BIND_PARAM_NULL),
                'INSERT INTO Foo (foo, bar) values (?, ?)',
                array(1, null),
                array(Column::BIND_PARAM_INT, Column::BIND_PARAM_NULL)
            ),
        );
    }

    /**
     * @dataProvider dataExpandListParameters
     */
    public function testExpandListParameters($q, $p, $t, $expectedQuery, $expectedParams, $expectedTypes)
    {
        list($query, $params, $types) = SQLParser::expandListParameters($q, $p, $t);

        $this->assertEquals($expectedQuery, $query, "Query was not rewritten correctly.");
        $this->assertEquals($expectedParams, $params, "Params dont match");
        $this->assertEquals($expectedTypes, $types, "Types dont match");
    }
}
