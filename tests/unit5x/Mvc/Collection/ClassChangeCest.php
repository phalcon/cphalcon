<?php

namespace Phalcon\Test\Unit5x\Mvc\Collection;

use UnitTester;
use Helper\CollectionTrait;
use Phalcon\Mvc\Collection\Exception;
use Phalcon\Test\Collections\Bookshelf\Books;

/**
 * Phalcon\Test\Unit5x\Mvc\Collection\ClassChangeCest
 * Tests the Phalcon\Mvc\Collection component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit5x\Mvc\Collection
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class ClassChangeCest
{
    use CollectionTrait;

    public function change(UnitTester $I)
    {
        $I->wantTo("fetch result from collection in desired class");

        $this->setupMongo($I);

        $book = new Books();
        $book->title = 'book';
        $I->assertTrue($book->save());

        $book = Books::findFirst([
            ['_id' => $book->getId()]
        ]);
        $I->assertInstanceOf('\Phalcon\Test\Collections\Bookshelf\Books', $book);

        $magazine = Books::findFirst([
            ['_id'   => $book->getId()],
            'class' => '\Phalcon\Test\Collections\Bookshelf\Magazines'
        ]);
        $I->assertInstanceOf('\Phalcon\Test\Collections\Bookshelf\Magazines', $magazine);

        $document = Books::findFirst([
            ['_id'   => $book->getId()],
            'class' => '\Phalcon\Mvc\Collection\Document'
        ]);
        $I->assertInstanceOf('\Phalcon\Mvc\Collection\Document', $document);

        $I->assertTrue($book->delete());
    }

    public function notACollection(UnitTester $I)
    {
        $I->wantToTest("throwing exception when used not a collection class binding");

        $this->setupMongo($I);

        $book = new Books();
        $book->title = 'book';
        $I->assertTrue($book->save());

        $I->expectException(
            new Exception(
                "Object of class '\\Phalcon\\Test\\Collections\\Bookshelf\\NotACollection' " .
                "must be an implementation of Phalcon\\Mvc\\CollectionInterface or an instance of Phalcon\\Mvc\\Collection\\Document"
            ),
            function () use ($book) {
                Books::findFirst([
                    ['_id'   => $book->getId()],
                    'class' => '\Phalcon\Test\Collections\Bookshelf\NotACollection'
                ]);
            }
        );

        $I->assertTrue($book->delete());
    }
}
