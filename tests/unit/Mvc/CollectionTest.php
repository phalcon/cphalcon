<?php

namespace Phalcon\Test\Unit\Mvc;

use Helper\Collection;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Test\Collections\Songs;

/**
 * \Phalcon\Test\Unit\Mvc\CollectionTest
 * Tests the Phalcon\Mvc\Collection component
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit\Mvc
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class CollectionTest extends UnitTest
{
    use Collection;

    /**
     * executed before each test
     */
    protected function _before()
    {
        parent::_before();

        $this->setupMongo($this->tester);
    }

    /**
     * Tests triggering exception on update non existent document
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-03-03
     */
    public function testShouldCatchExceptionOnUpdateNonExistentDocument()
    {
        $this->specify(
            "Test does not catch Collection Exception on update non existent document",
            function () {
                $song = new Songs();
                $song->artist = 'Cinema Strange';
                $song->name = 'Legs and Tarpaulin';
                $song->update();
            },
            ['throws' => ['Phalcon\Mvc\Collection\Exception', "The document cannot be updated because it doesn't exist"]]
        );
    }

    /**
     * Tests Collection::save
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-03-13
     */
    public function testShouldGetTrueWhenSaveDocument()
    {
        $this->specify(
            "Collection::save does not return expected result",
            function () {
                $this->clearCollection();
                expect($this->createDocument(['artist' => 'Radiohead', 'name' => 'Lotus Flower']))->true();
            }
        );
    }

    /**
     * Tests Collection::find
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-03-03
     */
    public function testShouldGetArrayOfCollectionsByUsingFind()
    {
        $this->specify(
            "Collection::find does not return expected result",
            function () {
                $songs = Songs::find();
                expect(is_array($songs))->true();

                $this->clearCollection();

                $this->createDocument([
                    'artist' => 'Radiohead',
                    'name'   => 'Lotus Flower',
                ]);

                $songs = Songs::find();

                expect(is_array($songs))->true();
                expect($songs)->count(1);
                expect($songs[0]->_id)->isInstanceOf('MongoId');
                expect($songs[0]->artist)->equals('Radiohead');
                expect($songs[0]->name)->equals('Lotus Flower');

                $this->createDocument([
                    'artist' => 'Massive Attack',
                    'name'   => 'Teardrop',
                ]);

                $songs = Songs::find();

                expect(is_array($songs))->true();
                expect($songs)->count(2);
                expect($songs[1]->_id)->isInstanceOf('MongoId');
                expect($songs[1]->artist)->equals('Massive Attack');
                expect($songs[1]->name)->equals('Teardrop');
                expect((string) $songs[0]->_id)->notEquals((string) $songs[1]->_id);

                $this->createDocument([
                    'artist' => 'Massive Attack',
                    'name'   => 'Paradise Circus',
                ]);

                $songs = Songs::find();

                expect(is_array($songs))->true();
                expect($songs)->count(3);
                expect($songs[2]->_id)->isInstanceOf('MongoId');
                expect($songs[2]->artist)->equals('Massive Attack');
                expect($songs[2]->name)->equals('Paradise Circus');
                expect((string) $songs[0]->_id)->notEquals((string) $songs[1]->_id);
                expect((string) $songs[1]->_id)->notEquals((string) $songs[2]->_id);
                expect((string) $songs[2]->_id)->notEquals((string) $songs[0]->_id);

                $songs = Songs::find([['artist' => 'Massive Attack']]);

                expect(is_array($songs))->true();
                expect($songs)->count(2);
                expect($songs[0]->name)->equals('Teardrop');
                expect($songs[1]->name)->equals('Paradise Circus');

                $songs = Songs::find(['conditions' => ['artist' => 'Massive Attack']]);

                expect(is_array($songs))->true();
                expect($songs)->count(2);
                expect($songs[0]->name)->equals('Teardrop');
                expect($songs[1]->name)->equals('Paradise Circus');

                $songs = Songs::find([
                    'conditions' => ['artist' => 'Massive Attack'],
                    'sort'       => ['name' => 1],
                ]);

                expect($songs[0]->name)->equals('Paradise Circus');
                expect($songs[1]->name)->equals('Teardrop');


                $songs = Songs::find([
                    'conditions' => ['artist' => 'Massive Attack'],
                    'sort'       => ['name' => 1],
                    'limit'      => 1
                ]);

                expect(is_array($songs))->true();
                expect($songs)->count(1);
                expect($songs[0]->name)->equals('Paradise Circus');

                $songs = Songs::find([
                    'conditions' => ['artist' => 'Massive Attack'],
                    'limit'      => 1
                ]);

                expect(is_array($songs))->true();
                expect($songs)->count(1);
                expect($songs[0]->name)->equals('Teardrop');
            }
        );
    }

    /**
     * Tests Collection::findFirst
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-03-13
     */
    public function testShouldGetCollectionByUsingFindFirst()
    {
        $this->specify(
            "Collection::findFirst does not return expected result",
            function () {
                $song = Songs::findFirst();

                expect($song->artist)->equals('Radiohead');
                expect($song->name)->equals('Lotus Flower');

                $song = Songs::findFirst([['artist' => 'Massive Attack']]);

                expect($song->artist)->equals('Massive Attack');
                expect($song->name)->equals('Teardrop');

                $song = Songs::findFirst(['conditions' => ['name' => 'Paradise Circus']]);

                expect($song->artist)->equals('Massive Attack');
                expect($song->name)->equals('Paradise Circus');

                expect(Songs::findFirst([['artist' => 'Lana']]))->false();
                expect(Songs::findFirst(['conditions' => ['artist' => 'Lana']]))->false();
            }
        );
    }

    /**
     * Tests Collection::count
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-03-13
     */
    public function testShouldCountDocumentsInCollection()
    {
        $this->specify(
            "Collection::count does not return expected result",
            function () {
                expect(Songs::count())->equals(3);
                expect(Songs::count([['artist' => 'Massive Attack']]))->equals(2);
            }
        );
    }

    /**
     * Tests Collection::create
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-03-13
     */
    public function testShouldCreateDocument()
    {
        $this->specify(
            "Collection::create does not work correctly",
            function () {
                $song = new Songs();
                $song->artist = 'Cinema Strange';
                $song->name = 'Greensward Grey';

                expect($song->create())->true();
                expect(Songs::count())->equals(4);
            }
        );
    }

    /**
     * Tests Collection::createIfNotExist
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-03-13
     */
    public function testShouldCreateIfNotExistDocument()
    {
        $this->specify(
            "Collection::createIfNotExist does not work correctly",
            function () {
                $song = new Songs();
                $song->artist = 'Cinema Strange';
                $song->name = 'Catacomb Kittens';


                expect($song->createIfNotExist(['name', 'artist']))->true();

                $song = new Songs();
                $song->artist = 'Cinema Strange';
                $song->name = 'Catacomb Kittens';

                expect($song->createIfNotExist(['name', 'artist']))->false();

                expect(Songs::count())->equals(5);
                expect(Songs::count([['artist' => 'Cinema Strange']]))->equals(2);
            }
        );
    }

    public function testShouldUpdateDocument()
    {
        $this->specify(
            "Collection::update does not work correctly",
            function () {
                $song = new Songs();
                $song->artist = 'Cinema Strange';
                $song->name = 'Hebenon Vial';
                $song->create();

                $song->name = "Lindsey's Trachea";
                expect($song->update())->true();
                expect(Songs::count())->equals(6);
                expect(Songs::count([['name' => 'Hebenon Vial']]))->equals(0);
            }
        );
    }

    protected function createDocument(array $fields)
    {
        $song = new Songs();

        foreach ($fields as $name => $value) {
            $song->{$name} = $value;
        }

        return $song->save();
    }

    protected function clearCollection()
    {
        foreach(Songs::find() as $song) {
            $this->assertTrue($song->delete());
        }
    }
}
